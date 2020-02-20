
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define SHM_KEY 0x1971

int isNumeric(const char *str)
{
	if (*str == '-') str++; // check if negative
	while (*str != '\0') // until null terminator
	{
		if (*str < '0' || *str > '9') return 0; // check if non-digit and return isn't numeric
		str++;
	}
	return 1; // return is numeric
}

int main(int argc, char *argv[])
{
	int opt;
	int n = 4;
	int s = 2;
	int i = 10000;
	int b = 100;
	char *o = NULL;
	int c;	
	while((c=getopt(argc, argv, "n:s:b:i:o:h"))!= EOF)
  	{
		switch(c)
    		{
	case 'h':
               	printf("\nInvocation: oss [-h] [-n x | -s x | -b B | -i I ] [-o (filename)]\n");
               	printf("-------------------------------------------------Program Options--------------------------------------------------\n");
               	printf("       -h             Describe how the project should be run and then, terminate\n");
               	printf("       -n x           Indicate the maximum total of child processes oss will ever create. (Default 4)\n");
               	printf("       -s x           Indicate the number of children allowed to exist in the system at the same time. (Default 2)\n");
               	printf("       -b B           Start of the sequence of numbers to be tested for primality\n");
               	printf("       -i I           Increment between numbers that we test\n");
               	printf("       -o filename    Output file\n");
               	return EXIT_SUCCESS;
      	case 'n':
      		n = atoi(optarg);
		//printf("%d\n", n);
      		break;
      
      	case 's':
      		s = atoi(optarg);
		printf("%d\n", s);
     		break;
      
      	case 'b':
      		b = atoi(optarg);
		printf("%d\n", b);
      		break;
      
     	case 'i':
      		i = atoi(optarg);
		printf("%d\n", i);
      		break;
      
	case 'o':
      		o = optarg;
		printf("%s\n", o);
      		break;
	default:
		fprintf(stderr, "%s: Error: Unknown option -%c\n",argv[0],optopt);
		return -1;
	
	}
  	if (optind != argc)
	{
		fprintf(stderr, "Found an unknown argument!\n");
		return EXIT_FAILURE;
	}
	
	printf("[oss] number of processes are %d\n", n);
	
	printf("[oss] getting shared memory\n");
	int shmid = shmget(SHM_KEY, sizeof(int), 0666 | IPC_CREAT); // get shared memory id
	if (shmid < 0) // check if shared memory get error
	{
		perror("[oss] shmget\n");
		return EXIT_FAILURE;
	}
	
	int *shm = (int *) shmat(shmid, NULL, 0); // attach to shared memory
	if (shm == (int *) -1) // check if shared memory attachment error
	{
		perror("[oss] shmat\n");
		return EXIT_FAILURE;
	}
	
	*shm = 0; // set shared memory integer to zero
	printf("[oss] shared memory set to zero\n");
	
	printf("[oss] forking...\n");
	int pid = fork(); // duplicate process
	if (pid < 0) // check if fork error
	{
		perror("[oss] fork\n");
		return EXIT_FAILURE;
	}
	else if (pid == 0) // check if is child
	{
		// CHILD
		
		printf("[oss] child is executing worker\n");
		
		// convert integer to string
		char number[256];
		sprintf(number, "%d", n);
		
		execl("./worker", "./worker", number, NULL); // execute worker with parameter from -n argument
	}
	
	// PARENT
	
	// wait until shared memory memory is not zero
	printf("[oss] parent is waiting for shared memory not to be zero\n");
	while (*shm == 0)
		sleep(1);
	
	if (*shm < 2) // check if shared memory isn't a possible prime
	{
		printf("[oss] no  prime found\n");
		
		// kill child because it's waiting on parent which won't change shared memory for it to terminate
		kill(pid, SIGTERM);
		sleep(1);
		int status;
		waitpid(pid, &status, WNOHANG);
		if (status)
		{
			kill(pid, SIGKILL);
			waitpid(pid, &status, 0);
		}
		
		// stop everything
		return EXIT_FAILURE;
	}
	
	printf("[oss]  prime is %d\n", *shm); // we found a prime!
	
	*shm = 0; // reset shared memory integer to zero
	printf("[oss] shared memory set to zero\n");
	
	printf("[oss] waiting for child to terminate\n");
	wait(NULL); // wait until child terminates
	printf("[oss] child terminated\n");
	
	shmdt(shm); // reattach to shared memory just in case
	shmctl(shmid, IPC_RMID, NULL); // remove shared memory integer
	printf("[oss] shared memory freed\n");
	
	printf("[oss] terminating\n");
	
	// all right, we're done now
	return EXIT_SUCCESS;
}
}
