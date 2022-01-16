#include <time.h>

#include <grp.h>

#include <sys/stat.h>

#include <sys/types.h>

#include <unistd.h>

#include <sys/utsname.h>

#include <sys/sysinfo.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <dirent.h>

#define SIZE 256

#define clrscr() printf("\e[1;1H\e[2J")

void printFileAsHex(FILE* file);
char toVisibleCharacter(int byteVal);
void writeLine(char* lineBuffer, int buflen);
char upperToHex(int byteVal);
char lowerToHex(int byteVal);
char nibbleToHex(int nibble);

#define LINELEN     16



void help_function() {
printf("\n Index of commands for coreline 2.5Beta \n");
printf("----------------------------------------\n");
printf("1.  uptime    - total systems up time.\n");
printf("2.  cls       - clear the screen.\n");
printf("3.  helpme    - This help screen.\n");
printf("    Sub commands: help & cmdlist.\n");
printf("4.  fileinfo  - Basic File info. \n");
printf("5.  filesize  - [input1] file size. \n");
printf("6.  time      - The Date & Time. \n");
printf("7.  typefile  - [input1] dump text file contents.\n");
printf("8.  remove    - [input1] Remove a file. \n");
printf("    Sub commands: del & remove.\n");
printf("9.  rename    - [input1] [input2] Rename a file. \n");
printf("10. hexdump   - [input1] hex dump of file. \n");
printf("    Sub commands: hex and/or hexdump. \n");
printf("11. shell     - Open a new bash shell, \n");
printf("                type exit to return to coreline prompt.\n");
printf("12. fortune   - A random fortune just for you.\n");
printf("13. listhome  - list home directory.\n"); 
printf("14. reboot    - reboot computer.\n");
printf("15. subcmd    - list more commands \n");
printf("\n Bash Command line Usage: \n");
printf("coreline [input1] [input2] \n\n");
return 1;
}

void function_sub_command() {
printf("\n Coreline sub-command menu:");
printf("\n 16. wifinfo - list WIFI chipset information.");
printf("\n 17. wispeed - Wireless network speed, Signal Strength.");
printf("\n 18. nano    - Text Editor");
printf("\n 19. ltr     - Order Files Based on Last Modified Time (In Reverse Order) "); 
printf("\n 20. dir     - list all files. \n"); 
return 1; 
}

int main(int argc, char *argv[])
{

int i, j = 20;

for( i = 0; i <= j; i ++ ) {

if( i == 15) { continue; }

 /*  Start inside the header of the loop  */

 char name[12];

 printf("coreline#");
 scanf("%s", &name);
if (strcmp ("dir", name) ==0 ) {
system("dir -a *.*"); 
}
if (strcmp ("ltr", name) ==0 ) {
system("ls -ltr"); 
} else 
if (strcmp ("subcmd", name) ==0 ) {
function_sub_command();
} else 
if (strcmp ("wifinfo", name) ==0 ) {
printf("Searching Basic system information: \n");
system("lspci"); 
system("lspci | grep -i wireless"); 
system("lspci | egrep -i --color 'wifi|wlan|wireless'"); 
system("lspci -vv -s 0c:00.0");
printf("\n Search [OK!] exiting back to coreshell prompt.\n"); 
} else 
if (strcmp ("nano", name) ==0 ) {
system("nano");
} else 
if (strcmp ("wispeed", name) ==0 ) {
system("watch -n 1 cat /proc/net/wireless");
} else 

 if (strcmp ("fileinfo", name) ==0 ) {

 char cmpname[256];

 struct utsname uts;

 struct stat file_stats;



if ( stat( argv[1], &file_stats) == -1 )  /* get info */

        perror(argv[1]);

    else

    printf("filename: %s total size, in bytes: %ld \n", argv[1] ,file_stats.st_size);

    printf(" %s last access: %s ", argv[1] ,ctime(&file_stats.st_atime));

    printf("%s last modification: %s ", argv[1] ,ctime(&file_stats.st_mtime));

    printf("last change: %s ", ctime(&file_stats.st_ctime));

    printf("device: %lld ",file_stats.st_dev);

    printf("** inode: %ld **",file_stats.st_ino);

    printf(" protection: %o \n",file_stats.st_mode);

    printf(" number of hard links: %d\n",file_stats.st_nlink);

    printf(" user ID of owner: %d --",file_stats.st_uid);

    printf(" group ID of owner: %d\n",file_stats.st_gid);

    printf(" device type (if inode device): %lld\n",file_stats.st_rdev);

    printf(" blocksize for filesystem I/O: %ld\n",file_stats.st_blksize);

    printf(" number of blocks allocated: %ld\n\n",file_stats.st_blocks);



 if(gethostname(cmpname, 255) == 0)

   printf(" Host    Name : %s\n", cmpname);

 if(uname(&uts) == 0) {

   printf(" System  Name : %s\n", uts.sysname);

   printf(" Machine Name : %s\n", uts.machine);

   printf(" Node    Name : %s\n", uts.nodename);

   printf(" Release Name : %s\n", uts.release);

   printf(" Version Name : %s\n", uts.version);

 }
} else

 if (strcmp ("filesize", name) ==0 ) {

   struct stat infobuf;

    if ( stat( argv[1], &infobuf) == -1 )

        perror(argv[1]);

    else

    printf(" The size of %s is %d\n", argv[1], infobuf.st_size );

 }

 else

 if (strcmp ("uptime", name) ==0 ) {



  struct sysinfo sys_info;

  struct group* grp;



    gid_t gid;


  int days, hours, mins;



  if(sysinfo(&sys_info) != 0)

    perror("sysinfo");



  days = sys_info.uptime / 86400;

  hours = (sys_info.uptime / 3600) - (days * 24);

  mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);



  printf("Ubuntu Uptime: %ddays, %dhours, %dminutes, %ldseconds \n", days, hours, mins, sys_info.uptime % 60);

  printf("Load Avgs: 1min(%ld) 5min(%ld) 15min(%ld) \n", sys_info.loads[0], sys_info.loads[1], sys_info.loads[2]);

  printf("Total Ram: %ldk \n", sys_info.totalram / 1024);

  printf("Total Free Ram: %ldk \n", sys_info.freeram / 1024);

  printf("Total memory units: %ld \n", sys_info.mem_unit);

  printf("Shared Ram: %ldk \n", sys_info.sharedram / 1024);

  printf("Buffered Ram: %ldk \n", sys_info.bufferram / 1024);

  printf("Total Swap: %ldk - Free Swap: %ldk \n", sys_info.totalswap / 1024, sys_info.freeswap / 1024);

  printf("Total Number of open processes: %d\n", sys_info.procs);

  gid = getgid();

  printf("Group ID: %d ", gid);



    if((grp = getgrgid(gid)) == NULL )

      return 1;



    printf("Group %s \n", grp->gr_name );



    if(strcmp(grp->gr_passwd,"x") == 0)

      printf("Password is protected by shadow file.\n");

    else

      printf("Password: %s\n", grp->gr_passwd);

 } else

 if (strcmp ("time", name) ==0 ) {

       char buffer[SIZE];

       time_t curtime;

       struct tm *loctime;

       curtime = time (NULL);

       loctime = localtime (&curtime);

       fputs (asctime (loctime), stdout);

       strftime (buffer, SIZE, "Today is %A, %B %d.\n", loctime);

       fputs (buffer, stdout);

       strftime (buffer, SIZE, "The time is %I:%M %p.\n", loctime);

       fputs (buffer, stdout);



 } else if (strcmp ("clear", name) ==0 ) {

    clrscr();

 } else if (strcmp ("cls", name) ==0 ) {

    clrscr();

 } else if (strcmp ("typefile", name) ==0 ) {

   char  str[SIZE];

   FILE * file;

   file = fopen( argv[1] , "r");

    if (file) {

       while (fscanf(file, "%s", str)!=EOF)

        printf("%s", str);

        fclose(file);

        }

 } else if (strcmp ("help", name) ==0 ) {
   help_function();
 } else if (strcmp ("helpme", name) ==0) {
   help_function();
 } else if (strcmp ("cmdlist", name) ==0) {
   help_function();
 } else if (strcmp ("remove", name) ==0) {
 if(remove(argv[1])) printf("Error: File %s not removed.\n", argv[1]);
 else
 printf("File %s removed. \n", argv[1]);
 } else if (strcmp ("del", name) ==0) {
 if(remove(argv[1])) printf("Error: file %s not removed.\n", argv[1]);
 else
 printf("File %s removed. \n", argv[1]);
 } else if (strcmp ("rename", name) ==0) {
 if(rename(argv[1], argv[2]) != 0) {
 printf("Error: Renameing file %s to %s rename fail!", argv[1], argv[2]); }
 } else if (strcmp ("hexdump", name) ==0) {
   FILE *dumpit;
   dumpit = fopen(argv[1], "rb");
   printFileAsHex(dumpit);
   fclose(dumpit);
 } else if (strcmp ("hex", name) ==0) {
   FILE *dumpit;
   dumpit = fopen(argv[1], "rb");
   printFileAsHex(dumpit);
   fclose(dumpit);
 } else if (strcmp ("shell", name) ==0) {
   printf("Droping to new bash shell.");
   printf("\n\n Note: you have not exited coreline, \n");
   printf("type exit to close this bash shell & return to coreline prompt. \n\n");
   system("/bin/bash");
 } else if (strcmp("fortune", name) ==0) {
   system("fortune");
 } else if (strcmp("exit", name) ==0) {
   printf("Exiting Program Good bye! \n");
   return 0;
 } else if (strcmp("quit", name) ==0) {
   printf("Exiting Program Good bye! \n");
   return 0;
 } else if (strcmp("listhome", name) ==0) {
     DIR *dp;
      struct dirent *ep;
      dp = opendir ("./");

  if (dp != NULL)
  {
    while (ep = readdir (dp))
      puts (ep->d_name);

    (void) closedir (dp);
  }  else
    perror ("Couldn't open the directory");
} else if (strcmp("reboot", name) ==0) {
system("sudo shutdown -P now");
}

}
   return 0;
 }


void printFileAsHex(FILE* file)
{
    int count = 0;
    char buffer[LINELEN];

    while(1)
    {
        int byteVal = fgetc(file);

        if(EOF == byteVal)
        {
            break;
        }

        buffer[count] = byteVal;
        count++;
        if(count >= LINELEN)
        {
            writeLine(buffer, LINELEN);
            count = 0;
        }
    }

    if(count > 0)
    {
        writeLine(buffer, count);
    }
}

char toVisibleCharacter(int byteVal)
{
    if(byteVal >= 32 && byteVal <= 126)
    {
        return (char) byteVal;
    }

    return '_';
}

void writeLine(char* lineBuffer, int buflen)
{
    int i;

    for(i=0; i<buflen; i++)
    {
        char chu = upperToHex(lineBuffer[i]);
        char chl = lowerToHex(lineBuffer[i]);
        printf("%c%c", chu, chl);
    }

    if(buflen < LINELEN)
    {
        for(i = LINELEN - buflen; i>0; i--)
        {
            printf("0");
        }
    }

    printf("\t");

    for(i=0; i<buflen; i++)
    {
        char ch = toVisibleCharacter(lineBuffer[i]);
        printf("%c", ch);
    }
    printf("\r\n");
}

char upperToHex(int byteVal)
{
    int i = (byteVal & 0xF0) >> 4;
    return nibbleToHex(i);
}

char lowerToHex(int byteVal)
{
    int i = (byteVal & 0x0F);
    return nibbleToHex(i);
}

char nibbleToHex(int nibble)
{
    const int ascii_zero = 48;
    const int ascii_a = 65;

    if((nibble >= 0) && (nibble <= 9))
    {
        return (char) (nibble + ascii_zero);
    }
    if((nibble >= 10) && (nibble <= 15))
    {
        return (char) (nibble - 10 + ascii_a);
    }
    return '?';
}
