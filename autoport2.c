/*
Program: Autoport2 TCP/UDP networkz Port Scanner Tool. 
         THE REALLY BAD HACKER EXAMPLE ! Version 2 of 2 
*/ 

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <rpc/rpc.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#define ATF_PROGRAM ((u_long)100099)
#define ATF_VERSION ((u_long)1)

int net_mode=0;
void finderz(char *host);
unsigned long calculate_sleep(char *host);

int main(int argc,char *argv[])
{
        char host[1000];
        char net[1000];
        int i;
	int sleep=0;

        if(argc < 2)
        {
                printf("Autoport ]2[ ToolBox\n");
                printf("Usage: %s <wifi connection ip>\n",argv[0]);
                exit(0);
        }

        strncpy(host,argv[1],999);
        if(host[strlen(host)-1] == '-')
        {
                net_mode=1;
                host[strlen(host)-1]=0x0;
        }

        if(net_mode==0)
	{
		sleep=calculate_sleep(host);
		if(sleep < 500000 )
                	finderz(host);
	}
        else
                for(i=1;i<256;i++)
                {
                        sprintf(net,"%s%d",host,i);
			sleep=calculate_sleep(net);
			if(sleep < 500000)
                        	finderz(net);
			else
				printf("Skipping (%s) appear to be down..\n",net);
                }
}

void finderz(char *host)
{
  struct sockaddr_in saddr;
  struct hostent *h0zt;
  struct timeval tv;
  CLIENT *cl;
  int flag=0;
  int sd, portz=0;

        h0zt = gethostbyname(host);
        saddr.sin_family = AF_INET;
        if(!h0zt)
        {
                if((saddr.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE)
                {
                        printf ( "Error: Host not found!\n");
                        exit(0);
                }
        }

        bcopy(h0zt->h_addr,(struct in_addr *)&saddr.sin_addr,h0zt->h_length);
        saddr.sin_port = htons(portz);
        sd = RPC_ANYSOCK;
        tv.tv_sec = 0;
        tv.tv_usec = 100;

        if((cl = clnttcp_create(&saddr,ATF_PROGRAM,ATF_VERSION,&sd, 0, 0)) == NULL)
                printf("Atfs not found at (%s) on TCP MODE\n",host);
        else
                flag=1;
        if(flag==0)
        if((cl = clntudp_create(&saddr, ATF_PROGRAM, ATF_VERSION, tv, &sd)) == NULL)
                printf("Atfs not found at (%s) on UDP MODE\n",host);
	else
		flag=1;
	
	if(flag==1)
        {
                printf ("Atfs Running found at (%s) on %d port.\n",host,ntohs(saddr.sin_port));
		clnt_destroy(cl);
        }
}


unsigned long calculate_sleep(char *host) {
struct timeval begin, end;
int sd;
struct sockaddr_in sock;
int res;

if ((sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
  {perror("Socket troubles"); exit(1);}

sock.sin_family = AF_INET;
sock.sin_addr.s_addr = inet_addr(host);
sock.sin_port = htons((random()%65535));

gettimeofday(&begin, NULL);
if ((res = connect(sd, (struct sockaddr *) &sock,
                   sizeof(struct sockaddr_in))) != -1)
  fprintf(stderr, "Error-out\n");
close(sd);
gettimeofday(&end, NULL);
if (end.tv_sec - begin.tv_sec > 5 ) 
  return 0;
return (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
}

