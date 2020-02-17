void help(){

	printf("\nInvocation: oss [-h] [-n x | -s x | -b B | -i I ] [-o (filename)]\n");
               	printf("       -h             Describe how the project should be run and then, terminate\n");
               	printf("       -n x           Indicate the maximum total of child processes oss will ever create. (Default 4)\n");
               	printf("       -s x           Indicate the number of children allowed to exist in the system at the same time. (Default 2)\n");
               	printf("       -b B           Start of the sequence of numbers to be tested for primality\n");
               	printf("       -i I           Increment between numbers that we test\n");
               	printf("       -o filename    Output file\n");
                return;
}
