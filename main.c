
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int n = 0;
	int s = 0;
	int i = 0;
	int b = 0;
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
   }

}
