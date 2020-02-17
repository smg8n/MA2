MASTER		= oss
WORKER		= prime
MASTER_OBJ	= oss.o
WORKER_OBJ	= prime.o
TARGETS		= $(MASTER) $(WORKER)

.SUFFIXES: .c .o

all: $(TARGETS)

$(MASTER): $(MASTER_OBJ)
	gcc -Wall -g -o $@ $(MASTER_OBJ)

$(WORKER): $(WORKER_OBJ)
	gcc -Wall -g -o $@ $(WORKER_OBJ)

.c.o:
	gcc -Wall -g -c $<

.PHONY: clean
clean:
	/bin/rm -f $(TARGETS) *.o

