/* Socket - Serveur - Mode Datagramme */

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define UDP_port_S 8000
#define IP_addr_S "127.0.0.1"

int main()
{
	int sock_bouche;
	
	struct sockaddr_in sa_oreille;
	
	unsigned int taille_sa_oreille;
	
	char message[10];
	
	/* creation socket Client */
	sock_bouche = socket(PF_INET, SOCK_DGRAM, 0);
	perror("socket");
	
	/* @IP et n° port Serveur */
	bzero((char*) &sa_oreille, sizeof(sa_oreille));
	sa_oreille.sin_family      = AF_INET;
	sa_oreille.sin_addr.s_addr = inet_addr( IP_addr_S );
	sa_oreille.sin_port        = htons( UDP_port_S );

	/* emission vers le serveur (a partir du client) */
	taille_sa_oreille = sizeof( struct sockaddr );

	sendto(sock_bouche, "ptn de ste", 10 * sizeof(char), 0, (struct sockaddr*) &sa_oreille, taille_sa_oreille);
	
	while(1)
	{
		/* reception datagramme du client*/
		recvfrom(sock_bouche, message, 10 * sizeof(char), 0, (struct sockaddr *) &sa_oreille, &taille_sa_oreille);
		
		/* affichage */
		printf("%s \n", message);
		
		/* re-emission datagramme vers client */
		sendto(sock_bouche, message, 10 * sizeof(char), 0, (struct sockaddr*) &sa_oreille, taille_sa_oreille);
	}

	/* fin */
    	close(sock_bouche);
	exit(EXIT_SUCCESS);
	
}

