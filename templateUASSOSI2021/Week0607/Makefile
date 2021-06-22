
CC=gcc
CCOPT=-std=gnu99
CCLNK=-pthread -lrt
 
P00=w0607a-processesandthreads
P01=w0607b-producerconsumer


P99=99-myutils
 

EXECS= \
	$(P00) \
	$(P01) \



OBJ= \
	$(P00).o \
	$(P01).o \


all:	$(EXECS)

$(P00): $(P00).o $(P99).o
	$(CC) $(CCOPT) $(P00).o $(P99).o $(CCLNK) -o $(P00)

$(P00).o: $(P00).c $(P99).h
	$(CC) -c $(CCOPT) $(P00).c

$(P01): $(P01).o $(P99).o
	$(CC) $(CCOPT) $(P01).o $(P99).o $(CCLNK) -o $(P01)

$(P01).o: $(P01).c $(P99).h
	$(CC) -c $(CCOPT) $(P01).c


$(P99).o: $(P99).c $(P99).h
	$(CC) -c $(CCOPT) $(P99).c

clean:
	rm -f $(EXECS)
	rm -f $(OBJ)

