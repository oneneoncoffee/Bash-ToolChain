/*
Tested on Ubuntu 9.10
            - the Karmic Koala 
NOTE: 
TO COMPILE ON OLDER VERSIONS [ gcc -Wall autoport.c -o autoport ] AND/OR
[ gcc autoport.c -o autoport ] like all OK port checkers this one is not so buggy. 
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define DEF_STR_PORT 1
#define DEF_STP_PORT 1024
#define OXO 1

struct sockaddr_in addr;
struct hostent *rh;
struct servent *rp;

int sock,i;
int str_ptr, stp_ptr;
int Usage(char *ARG);
int CONNECTION(int port);
                        
int main(int argc, char *argv[])
{

	if (argc != 4)
		Usage(argv[0]);
	
		str_ptr = atoi(argv[2]);
		stp_ptr = atoi(argv[3]);
	if (strcmp(argv[2],"-")==0 && strcmp(argv[3],"-")==0){
		str_ptr = DEF_STR_PORT;
		stp_ptr = DEF_STP_PORT;
	}

	if ( str_ptr > stp_ptr){
		fprintf(stderr,"DetecT ErroR !!! On PortS, <Start-Port> Can't Be Greater Than <Stop-Port>.-\n");
		Usage(argv[0]);
		exit(OXO);
	}

	if ((rh=gethostbyname(argv[1])) == NULL){		
		fprintf(stderr,"Can't Resolve Host %s .-\n",argv[1]);
		Usage(argv[0]);
		exit(OXO);
	}

	printf("Scanning Host %s From %d TCP Port To %d ......\n",argv[1],str_ptr,stp_ptr);
	for (i=str_ptr; i <= stp_ptr; i++)
	{
		if (CONNECTION(i)==0)
		{
			rp=getservbyport(htons(i),"tcp");
			printf("Port %d Is Open !!!  Service: %s \n",i,(rp == NULL)?"UknowN":rp->s_name);
		}
	close(sock);
	}

return 0;
}

int CONNECTION(int port)
{

	if ((sock=socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("SockeT");
		exit(OXO);
	}
	        
        addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr = *((struct in_addr *)rh->h_addr);

	if ((connect(sock,(struct sockaddr *) &addr, sizeof(addr))) == 0)
	        return 0;
	else
		return 1;
}

int Usage(char *ARG)
{
	fprintf(stderr,"Auto-Port Scanner Tool\n");
	fprintf(stderr,"Usage: %s <Remote-Host> <Start-Port> <Stop-Port>.-\n",ARG);
	exit(OXO);
}
