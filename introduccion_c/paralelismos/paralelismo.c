#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	int pid = fork();

	if (pid)
	{
		printf("Luke, soy tu padre. Mi PID es %d y tu PID es %d\n", getpid(), pid);
		wait(NULL);
		printf("Soy tu padre again %d \n", getpid());
	}
	else
	{
		printf("Soy luke. Mi PID es %d\n", getpid());
		sleep(1);
	}

	return 0;
}
