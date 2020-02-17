
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "help.h"
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
               	help();
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
