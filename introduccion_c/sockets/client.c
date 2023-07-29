#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc > 2)
	{
		const char *ip;
		int client_socket, numbytes, puerto;
		char buff[100];

		puerto = atoi(argv[2]);
		ip = argv[1];

		struct sockaddr_in server;

		// inet_pton convierte a una dirección ip y la almacena en la estructura, en este caso server
		if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0)
		{
			printf("La ip %s no es válida\n", ip);

			return -1;
		}

		printf("Abriendo el socker\n");

		if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("No pude abrir el socket\n");

			return -2;
		}

		server.sin_family = AF_INET;	 // familia de protocolos de internet
		server.sin_port = htons(puerto); // convierte el puerto a la estructura
		bzero(&(server.sin_zero), 8);	 // llenar con zeros

		printf("Conectando a %s:%s\n", argv[1], argv[2]);

		if (connect(client_socket, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
		{
			perror("No pude conectarme al servidor\n");

			return -3;
		}

		printf("Recibiendo...\n");

		if ((numbytes = recv(client_socket, buff, 100, 0)) == -1)
		{
			perror("Error en la lectura\n");

			return -4;
		}

		buff[numbytes] = '\0';

		printf("El servidor envió el mensaje %s\n", buff);

		// se llama a shutdown con parámetro 2 para cerrar y que no se pueda hacer nada mas con el socket
		shutdown(client_socket, 2);
	}
	else
	{
		printf("Por favor indique ip del servidor y el puerto\n");

		return -5;
	}

	return 0;
}
