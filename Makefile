OBJS = maxletters.o
CFLAGS = -std=c11
DEBUGFLAGS = -g

all: maxletters

debug: $(OBJS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(LFLAGS) -o maxletters $(OBJS)

maxletters: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o maxletters $(OBJS)

clean:
	rm -rf *.o maxletters *~
