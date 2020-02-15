# merugu.2

INTRODUCTION
------------

Problem: In  this  project  you  will  have  two  executable  files.   The  first  executable  file,oss,  
will  be  in  charge  of launching a specific number of child processes at various times using afork followed by an exec. 
oss should then keep  track  of  how  many  children  have  finished  executing  and  terminate  itself  only  when  
all  of  its  children  have finished.When you runoss, it should take in several command line options.  
First, -h, to describe how it should be run.  Thena -n x option to indicate the maximum total of child processes it will ever create.  Another option, -s, will indicatehow many children should be allowed to exist in the system at the same time.  
I suggest the default being of a -n of 4and a -s of 2.  
Additional options are -b to indicate the start of the sequence of numbers we are to test for primality,a -i option for the increment between numbers that we test and finally a -o option specifying an output file.  
Notethat all of these arguments should have some sensible default values, which should be described if -h is given

 * For a full description of the module, visit th
   e project page of CS4760: Operating Systems at:
   http://www.cs.umsl.edu/~sanjiv/classes/cs4760/

 * To submit bug reports and feature suggestions o
   r track changes visit:
   https://github.com/smg8n


REQUIREMENTS
------------

This module requires the following:

 * Hoare Linux (http://www.umsl.edu/technology/tsc/)
 * UMSL ID (https://www.umsl.edu/degrees/index.html)


INSTALLATION
------------

 * Install as you would normally install a distrib
   uted C module. To compile and execute, you must
   have the build-essential packages properly inst
   alled on your system. 


COMPILATION
-----------

To compile, open a new CLI window, change the the
directory nesting your module. Type:

 * make


EXECUTION
---------
																								 
Find the executable named bt, located inside that
directory in which you compiled the module. After
you have found bt, invoke the program with:

 * oss [-h] [n:s:b:i:o:h] 
 
 * The options are to be interpreted as follows:
 
 -h             Describe how the project should be run and then, terminate
 -n x           Indicate the maximum total of child processes oss will ever create. (Default 4)
 -s x           Indicate the number of children allowed to exist in the system at the same time. (Default 2)
-b B           Start of the sequence of numbers to be tested for primality
 -i I           Increment between numbers that we test
 -o filename    Output file

MAINTAINERS
-----------

Current maintainers: https://github.com/smg8n
