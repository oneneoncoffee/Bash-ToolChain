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
   char *cgistr;
   char buffer[1024];
   int count=0;
   int numin,suxes=0;
   char cgibuff[1024];
   char *buff[100];    
   char *cginame[100];

 		buff[1] = "GET /cgi-bin/unlg1.1 HTTP/1.0\n\n";
 		buff[2] = "GET /cgi-bin/rwwwshell.pl HTTP/1.0\n\n";
 		buff[3] = "GET /cgi-bin/phf HTTP/1.0\n\n";    
 		buff[4] = "GET /cgi-bin/Count.cgi HTTP/1.0\n\n";
 		buff[5] = "GET /cgi-bin/test-cgi HTTP/1.0\n\n";
 		buff[6] = "GET /cgi-bin/nph-test-cgi HTTP/1.0\n\n";
 		buff[7] = "GET /cgi-bin/nph-publish HTTP/1.0\n\n";
 		buff[8] = "GET /cgi-bin/php.cgi HTTP/1.0\n\n";
 		buff[9] = "GET /cgi-bin/handler HTTP/1.0\n\n";
 		buff[10] = "GET /cgi-bin/webgais HTTP/1.0\n\n";
 		buff[11] = "GET /cgi-bin/websendmail HTTP/1.0\n\n";
 		buff[12] = "GET /cgi-bin/webdist.cgi HTTP/1.0\n\n";
 		buff[13] = "GET /cgi-bin/faxsurvey HTTP/1.0\n\n";
 		buff[14] = "GET /cgi-bin/htmlscript HTTP/1.0\n\n";
 		buff[15] = "GET /cgi-bin/pfdispaly.cgi HTTP/1.0\n\n";
 		buff[16] = "GET /cgi-bin/perl.exe HTTP/1.0\n\n";
 		buff[17] = "GET /cgi-bin/wwwboard.pl HTTP/1.0\n\n";
 		buff[18] = "GET /cgi-bin/www-sql HTTP/1.0\n\n";
 		buff[19] = "GET /cgi-bin/view-source HTTP/1.0\n\n";
 		buff[20] = "GET /cgi-bin/campas HTTP/1.0\n\n";
 		buff[21] = "GET /cgi-bin/aglimpse HTTP/1.0\n\n";
 		buff[22] = "GET /cgi-bin/glimpse HTTP/1.0\n\n";
 		buff[23] = "GET /cgi-bin/man.sh HTTP/1.0\n\n";
 		buff[24] = "GET /cgi-bin/AT-admin.cgi HTTP/1.0\n\n";
 		buff[25] = "GET /cgi-bin/filemail.pl HTTP/1.0\n\n";
 		buff[26] = "GET /cgi-bin/maillist.pl HTTP/1.0\n\n";
 		buff[27] = "GET /cgi-bin/jj HTTP/1.0\n\n";
 		buff[28] = "GET /cgi-bin/info2www HTTP/1.0\n\n";
 		buff[29] = "GET /cgi-bin/files.pl HTTP/1.0\n\n"; 
 		buff[30] = "GET /cgi-bin/finger HTTP/1.0\n\n";
 		buff[31] = "GET /cgi-bin/bnbform.cgi HTTP/1.0\n\n";
 		buff[32] = "GET /cgi-bin/survey.cgi HTTP/1.0\n\n";
 		buff[33] = "GET /cgi-bin/AnyForm2 HTTP/1.0\n\n";
 		buff[34] = "GET /cgi-bin/textcounter.pl HTTP/1.0\n\n";
 		buff[35] = "GET /cgi-bin/classifieds.cgi HTTP/1.0\n\n";
 		buff[36] = "GET /cgi-bin/environ.cgi HTTP/1.0\n\n";
 		buff[37] = "GET /cgi-bin/wrap HTTP/1.0\n\n";
 		buff[38] = "GET /cgi-bin/cgiwrap HTTP/1.0\n\n";
 		buff[39] = "GET /cgi-bin/guestbook.cgi HTTP/1.0\n\n";
 		buff[40] = "GET /cgi-bin/edit.pl HTTP/1.0\n\n";
 		buff[41] = "GET /cgi-bin/perlshop.cgi HTTP/1.0\n\n";
 		buff[42] = "GET /_vti_inf.html HTTP/1.0\n\n";
 		buff[43] = "GET /_vti_pvt/service.pwd HTTP/1.0\n\n";
 		buff[44] = "GET /_vti_pvt/users.pwd HTTP/1.0\n\n";
 		buff[45] = "GET /_vti_pvt/authors.pwd HTTP/1.0\n\n";
 		buff[46] = "GET /_vti_pvt/administrators.pwd HTTP/1.0\n\n";
 		buff[47] = "GET /_vti_bin/shtml.dll HTTP/1.0\n\n";
 		buff[48] = "GET /_vti_bin/shtml.exe HTTP/1.0\n\n";
 		buff[49] = "GET /cgi-dos/args.bat HTTP/1.0\n\n";
 		buff[50] = "GET /cgi-win/uploader.exe HTTP/1.0\n\n";
 		buff[51] = "GET /cgi-bin/rguest.exe HTTP/1.0\n\n";
 		buff[52] = "GET /cgi-bin/wguest.exe HTTP/1.0\n\n";
 		buff[53] = "GET /scripts/issadmin/bdir.htr HTTP/1.0\n\n";
 		buff[54] = "GET /scripts/CGImail.exe HTTP/1.0\n\n";
 		buff[55] = "GET /scripts/tools/newdsn.exe HTTP/1.0\n\n";
 		buff[56] = "GET /scripts/fpcount.exe HTTP/1.0\n\n";
 		buff[57] = "GET /cfdocs/expelval/openfile.cfm HTTP/1.0\n\n";
 		buff[58] = "GET /cfdocs/expelval/exprcalc.cfm HTTP/1.0\n\n";
 		buff[59] = "GET /cfdocs/expelval/displayopenedfile.cfm HTTP/1.0\n\n";
 		buff[60] = "GET /cfdocs/expelval/sendmail.cfm HTTP/1.0\n\n";
 		buff[61] = "GET /iissamples/exair/howitworks/codebrws.asp HTTP/1.0\n\n"; 
 		buff[62] = "GET /iissamples/sdk/asp/docs/codebrws.asp HTTP/1.0\n\n";
 		buff[63] = "GET /msads/Samples/SELECTOR/showcode.asp HTTP/1.0\n\n";
 		buff[64] = "GET /search97.vts HTTP/1.0\n\n";
 		buff[65] = "GET /carbo.dll HTTP/1.0\n\n"; 
 		buff[66] = "GET /cgi-bin/ax-admin.cgi HTTP/1.0\n\n";       
 		buff[67] = "GET /scripts/convert.bas HTTP/1.0\n\n";        
 		buff[68] = "GET /cgi-bin/excite HTTP/1.0\n\n";               
 		buff[69] = "GET /cgi-bin/whois_raw.cgi HTTP/1.0\n\n";
                buff[70] = "GET /cgi-bin/axs.cgi HTTP/1.0\n\n";
                buff[71] = "GET /scripts/counter.exe HTTP/1.0\n\n";
                buff[72] = "GET /adsamples/config/site.csc HTTP/1.0\n\n";
                buff[73] = "GET /cgi-bin/responder.cgi HTTP/1.0\n\n";
                buff[74] = "GET /bb-dnbd/bb-hist.sh HTTP/1.0\n\n";
                buff[75] = "GET /scripts/iisadmin/ism.dll HTTP/1.0\n\n";
                buff[76] = "GET /cgi-bin/environ.cgi HTTP/1.0\n\n";
                buff[77] = "GET /scripts/tools/getdrvrs.exe HTTP/1.0\n\n";
                buff[78] = "GET /scripts/tools/dsnform.exe HTTP/1.0\n\n";
                buff[79] = "GET /scripts/samples/search/webhits.exe HTTP/1.0\n\n";
                buff[80] = "GET /_vti_pvt/author.log HTTP/1.0\n\n";
                buff[81] = "GET /_vti_pvt/service.grp HTTP/1.0\n\n";
                buff[82] = "GET /samples/search/queryhit.htm HTTP/1.0\n\n";
                buff[83] = "GET /domcfg.nsf HTTP/1.0\n\n";
                buff[84] = "GET /today.nsf HTTP/1.0\n\n";
                buff[85] = "GET /names.nsf HTTP/1.0\n\n";
                buff[86] = "GET /catalog.nsf HTTP/1.0\n\n";
                buff[87] = "GET /log.nsf HTTP/1.0\n\n";
                buff[88] = "GET /domlog.nsf HTTP/1.0\n\n";
                buff[89] = "GET /cgi-bin/AT-generate.cgi HTTP/1.0\n\n";
                buff[90] = "GET /secure/.htaccess HTTP/1.0\n\n";
                buff[91] = "GET /secure/.wwwacl HTTP/1.0\n\n";
                buff[92] = "GET /cgi-bin/day5datacopier.cgi HTTP/1.0\n\n";
                buff[93] = "GET /cgi-bin/day5notifier HTTP/1.0\n\n";
                buff[94] = "GET /cgi-bin/dumpenv.pl HTTP/1.0\n\n";
                buff[95] = "GET /scripts/../../cmd.exe HTTP/1.0\n\n";
                buff[96] = "GET /WebSTAR HTTP/1.0\n\n";
                buff[97] = "GET /~root HTTP/1.0\n\n";




 cginame[1] = "UnlG - backd00r ";
 cginame[2] = "THC - backd00r  ";
 cginame[3] = "phf..classic :) ";
 cginame[4] = "Count.cgi       ";
 cginame[5] = "test-cgi        ";
 cginame[6] = "nph-test-cgi    ";
 cginame[7] = "nph-publish     ";
 cginame[8] = "php.cgi         ";
 cginame[9] = "handler         ";
 cginame[10] = "webgais         ";
 cginame[11] = "websendmail     ";
 cginame[12] = "webdist.cgi     ";
 cginame[13] = "faxsurvey       ";
 cginame[14] = "htmlscript      ";
 cginame[15] = "pfdisplay       ";
 cginame[16] = "perl.exe        ";
 cginame[17] = "wwwboard.pl     ";
 cginame[18] = "www-sql         ";
 cginame[19] = "view-source     ";
 cginame[20] = "campas          ";
 cginame[21] = "aglimpse        ";
 cginame[22] = "glimpse         ";
 cginame[23] = "man.sh          ";
 cginame[24] = "AT-admin.cgi    ";
 cginame[25] = "filemail.pl     ";
 cginame[26] = "maillist.pl     ";
 cginame[27] = "jj              ";
 cginame[28] = "info2www        ";
 cginame[29] = "files.pl        ";
 cginame[30] = "finger          ";
 cginame[31] = "bnbform.cgi     ";
 cginame[32] = "survey.cgi      ";
 cginame[33] = "AnyForm2        ";
 cginame[34] = "textcounter.pl  ";
 cginame[35] = "classifields.cgi";
 cginame[36] = "environ.cgi     ";
 cginame[37] = "wrap            ";
 cginame[38] = "cgiwrap         ";
 cginame[39] = "guestbook.cgi   ";
 cginame[40] = "edit.pl         ";
 cginame[41] = "perlshop.cgi    ";
 cginame[42] = "_vti_inf.html   ";
 cginame[43] = "service.pwd     ";
 cginame[44] = "users.pwd       ";
 cginame[45] = "authors.pwd     ";
 cginame[46] = "administrators  ";
 cginame[47] = "shtml.dll       ";
 cginame[48] = "shtml.exe       ";
 cginame[49] = "args.bat        ";
 cginame[50] = "uploader.exe    ";
 cginame[51] = "rguest.exe      ";
 cginame[52] = "wguest.exe      ";
 cginame[53] = "bdir - samples  ";
 cginame[54] = "CGImail.exe     ";
 cginame[55] = "newdsn.exe      ";
 cginame[56] = "fpcount.exe     ";
 cginame[57] = "openfile.cfm    ";
 cginame[58] = "exprcalc.cfm    ";
 cginame[59] = "dispopenedfile  ";
 cginame[60] = "sendmail.cfm    ";
 cginame[61] = "codebrws.asp    ";
 cginame[62] = "codebrws.asp 2  ";
 cginame[63] = "showcode.asp    ";
 cginame[64] = "search97.vts    ";
 cginame[65] = "carbo.dll       ";
 cginame[66] = "ax-admin.cgi    ";
 cginame[67] = "convert.bas     ";
 cginame[68] = "excite          ";
 cginame[69] = "whois_raw.cgi   ";
 cginame[70] = "axs.cgi         ";
 cginame[71] = "counter.exe     ";
 cginame[72] = "site.csc        ";
 cginame[73] = "responder.cgi   ";
 cginame[74] = "bb-hist.sh      ";
 cginame[75] = "ism.dll         ";
 cginame[76] = "environ.cgi     ";
 cginame[77] = "getdrvrs.exe    ";
 cginame[78] = "dsnform.exe     ";
 cginame[79] = "webhits.exe     ";
 cginame[80] = "author.log      ";
 cginame[81] = "service.grp     ";
 cginame[82] = "queryhit.htm    ";
 cginame[83] = "domcfg.nsf      ";
 cginame[84] = "today.nsf       ";
 cginame[85] = "names.nsf       ";
 cginame[86] = "catalog.nsf     ";
 cginame[87] = "log.nsf         ";
 cginame[88] = "domlog.nsf      ";
 cginame[89] = "AT-generate.cgi ";
 cginame[90] = ".htaccess       ";
 cginame[91] = ".wwwacl         ";
 cginame[92] = "day5datacopier  ";
 cginame[93] = "day5notifier    ";
 cginame[94] = "dumpenv.pl      ";
 cginame[95] = "cmd.exe         ";
 cginame[96] = "WebSTAR         ";
 cginame[97] = "~root           ";



 if (argc<2)

   {
   printf("\n SaferBot ]2[ The network buster,");
   printf("\n Vulnerability scanner......... ");
   printf("\nusage : %s host ",argv[0]);
   printf("\n   Or : %s host -t [for test mode]\n\n",argv[0]); 
   exit(0);
   }

 if (argc>2)
   {
   if(strstr("-t",argv[2]))
     {
     debugm=1;
     }
   }

 if ((he=gethostbyname(argv[1])) == NULL)
   {
   herror("gethostbyname");
   exit(0);
   }
 printf("\n SaferBot ]2[ The network buster,\n");
 printf("\n Vulnerability database scanner. \n");
 printf("\n Searching database scanning... \n\t  Socket Open Connecting...\n");
 start=inet_addr(argv[1]);
 counter=ntohl(start);

   sock=socket(AF_INET, SOCK_STREAM, 0);
   bcopy(he->h_addr, (char *)&sin.sin_addr, he->h_length);
   sin.sin_family=AF_INET;
   sin.sin_port=htons(80);    /* port number 80 default */

  if (connect(sock, (struct sockaddr*)&sin, sizeof(sin))!=0)
     {
     perror("connect");
     }
   printf("\n\n\t Checking WebServer Version... \n");  
   send(sock, "HEAD / HTTP/1.0\n\n",17,0);
   recv(sock, buffer, sizeof(buffer),0);
   printf("%s",buffer);
   close(sock); 
  
   printf("\n\t  Vulnerability Scanning... \n");
   
while(count++ < 97)    
   {
   sock=socket(AF_INET, SOCK_STREAM, 0);
   bcopy(he->h_addr, (char *)&sin.sin_addr, he->h_length);
   sin.sin_family=AF_INET;
   sin.sin_port=htons(80);
   if (connect(sock, (struct sockaddr*)&sin, sizeof(sin))!=0)
     {
     perror("connect");
     }
   printf(">>> %s : ",cginame[count]);
  
   for(numin=0;numin < 1024;numin++)
      {
      cgibuff[numin] = '\0';
      } 
  
   send(sock, buff[count],strlen(buff[count]),0);
   recv(sock, cgibuff, sizeof(cgibuff),0);
   cgistr = strstr(cgibuff,foundmsg);
   if( cgistr != NULL)   {
       printf("Found !! \n");++suxes;     }
   else
       printf("Not Found safe..\n");
      
  if(debugm==1)
    { 
    printf("\n\n >>>>>>\n %s \n <<<<<<\n",cgibuff); 
    printf("Press any key to continue....\n");         
    }  
   close(sock);
   }
   if (suxes){   printf("              Network is not safe!\n");}
   else {        printf ("             Network is safe.... \n");} 
 }

