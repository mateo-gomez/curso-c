#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	int shared = 0;
	int pid = fork();

	if (pid)
	{
		shared = 1;
		printf("Luke, soy tu padre. Mi PID es %d y tu PID es %d. Shared = %d \n", getpid(), pid, shared);
		wait(NULL);
		printf("Soy tu padre again %d. Shared = %d \n", getpid(), shared);
	}
	else
	{
		shared = 2;
		printf("Soy luke. Mi PID es %d. Shared = %d \n", getpid(), shared);
		sleep(1);
	}

	return 0;
}
