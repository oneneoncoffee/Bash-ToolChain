/* Tested on: 
   Ubuntu 9.10 - the Karmic Koala 
   Slackware linux with kernel 2.0.35 
   Kubuntu/Eubuntu linux with Kernel 9.10 
                                                Version 2.7 Bata  
   Tested on: Ubuntu 14.04 LTS / Server  
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <ctype.h>
#include <arpa/nameser.h>
#include <sys/stat.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

void main(int argc, char *argv[])
{
 int sock,debugm=0;
 struct in_addr addr;
 struct sockaddr_in sin;
 struct hostent *he;
 unsigned long start;
 unsigned long end;
 unsigned long counter;
 char foundmsg[] = "200";
 char *cgistr, buffer[1024];
 int count=0;
 int numin;
 char cgibuff[1024];
 char *buff[150], *cginame[150];

 buff[1] = "GET /cgi-bin/phf HTTP/1.0\n\n";
 buff[2] = "GET /cgi-bin/Count.cgi HTTP/1.0\n\n";
 buff[3] = "GET /cgi-bin/test-cgi HTTP/1.0\n\n";
 buff[4] = "GET /cgi-bin/php.cgi HTTP/1.0\n\n";
 buff[5] = "GET /cgi-bin/handler HTTP/1.0\n\n";
 buff[6] = "GET /cgi-bin/webgais HTTP/1.0\n\n";
 buff[7] = "GET /cgi-bin/websendmail HTTP/1.0\n\n";
 buff[8] = "GET /cgi-bin/webdist.cgi HTTP/1.0\n\n";
 buff[9] = "GET /cgi-bin/faxsurvey HTTP/1.0\n\n";
 buff[10] = "GET /cgi-bin/htmlscript HTTP/1.0\n\n";
 buff[11] = "GET /cgi-bin/pfdispaly.cgi HTTP/1.0\n\n";
 buff[12] = "GET /cgi-bin/perl.exe HTTP/1.0\n\n";
 buff[13] = "GET /cgi-bin/wwwboard.pl HTTP/1.0\n\n";
 buff[14] = "GET /index.html XHTML/1.0\n\n";
 buff[15] = "GET /admin/index.php XHTML/1.0\n\n";
 buff[16] = "GET /index.htm HTTP/1.0\n\n";
 buff[17] = "GET /mail.html HTTP/1.0 \n\n";
 buff[18] = "GET /mail.htm  HTTP/1.0 \n\n";
 buff[19] = "GET /mail/mail.html HTTP/1.0 \n\n";

 cginame[1] = "phf";
 cginame[2] = "Count.cgi";
 cginame[3] = "test-cgi";
 cginame[4] = "php.cgi";
 cginame[5] = "handler";
 cginame[6] = "webgais";
 cginame[7] = "websendmail";
 cginame[8] = "webdist.cgi";
 cginame[9] = "faxsurvey";
 cginame[10] = "htmlscript";
 cginame[11] = "pfdisplay";
 cginame[12] = "perl.exe";
 cginame[13] = "wwwboard.pl";
 cginame[14] = "index.html";
 cginame[15] = "index.php";
 cginame[16] = "index.htm";
 cginame[17] = "mail.html";
 cginame[18] = "mail.htm";
 cginame[19] = "mail.html";

 if (argc<2)
   {
   printf("\n Project file Name: %s \n",argv[0]);  
   printf("This server robot will accumulate server intelligence printed as terminal output.\n"); 
   printf("It is a handy tool if your testing a server or just trying to look-up information about a website.");
   printf("\n More so over this program will look for CGI/HTML/XHTML files listed on a server."); 
   printf("\n ----------------------------------------------------\n"); 
   printf("\nusage : %s host ",argv[0]);
   printf("\n   Or : %s host -d (debug mode)\n\n",argv[0]); 
   exit(0);
   }

 if (argc>2)
   {
   if(strstr("-d",argv[2]))
     {
     debugm=1;
     }
   }

 if ((he=gethostbyname(argv[1])) == NULL)
   {
   herror("gethostbyname");
   exit(0);
   }

 printf("\n\n\t\t Robot Looking for CGI/XHTML/HTML files on %s\n\n\n", argv[1]);
 start=inet_addr(argv[1]);
 counter=ntohl(start);

   sock=socket(AF_INET, SOCK_STREAM, 0);
   bcopy(he->h_addr, (char *)&sin.sin_addr, he->h_length);
   sin.sin_family=AF_INET;
   sin.sin_port=htons(80);

  if (connect(sock, (struct sockaddr*)&sin, sizeof(sin))!=0)
     {
     perror("connect");
     }
 
   send(sock, "HEAD / HTTP/1.0\n\n",17,0);
   recv(sock, buffer, sizeof(buffer),0);
   printf("%s",buffer);
   close(sock); 
   
while(count++ < 19)   
   {
   sock=socket(AF_INET, SOCK_STREAM, 0);
   bcopy(he->h_addr, (char *)&sin.sin_addr, he->h_length);
   sin.sin_family=AF_INET;
   sin.sin_port=htons(80);
   if (connect(sock, (struct sockaddr*)&sin, sizeof(sin))!=0)
     {
     perror("connect");
     }
   printf("Robot searching for %s : ",cginame[count]);
  
   for(numin=0;numin < 1024;numin++)
      {
      cgibuff[numin] = '\0';
      } 
  
   send(sock, buff[count],strlen(buff[count]),0);
   recv(sock, cgibuff, sizeof(cgibuff),0);
   cgistr = strstr(cgibuff,foundmsg);
   if( cgistr != NULL)
       printf("Found ! ;)\n");
   else
       printf("Not Found.. \n");
      
  if(debugm==1)
    { 
    printf("\n %s \n",cgibuff);
    printf("\n\n NETSTATUS: \n");
    system("ifconfig"); 
    printf("Press any key to continue....\n");
    getchar();
    }
   close(sock);
   }
 }
