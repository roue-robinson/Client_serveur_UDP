CC=gcc

all: client serveur bouche clean

client: client.o
	$(CC) -Wall -o $@ $^

serveur: serveur.o
	$(CC) -Wall -o $@ $^

bouche: bouche.o
	$(CC) -Wall -o $@ $^

client.o: 
	$(CC) -Wall -c client.c

serveur.o: 
	$(CC) -Wall -c serveur.c	

bouche.o: 
	$(CC) -Wall -c bouche.c	


clean:
	rm *.o



