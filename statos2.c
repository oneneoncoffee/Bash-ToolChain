#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <arpa/inet.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
  struct sysinfo sys_info;
  struct group* grp;
  struct ifreq ifr;

    gid_t gid;
    char** users;
    char iface[] = "eth0", iface00[] = "eth0:0", iface2[] = "eth1", *cvalue = NULL;

  int c, index, fd, days, hours, mins, x = 1;


 while ((c = getopt (argc, argv, "abdc:")) != -1)
 switch(c) {
 	case 'a':  
  if(sysinfo(&sys_info) != 0)
    perror("sysinfo");

  days = sys_info.uptime / 86400;
  hours = (sys_info.uptime / 3600) - (days * 24);
  mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);

  printf("\033[1;33m Ubuntu Uptime: \033[0;31m %ddays, %dhours, %dminutes, %ldseconds \033[0;m \n",
                      days, hours, mins, sys_info.uptime % 60);

  printf("\033[1;33m Load Avgs: \033[0;m 1min(%ld) 5min(%ld) 15min(%ld) \n",
          sys_info.loads[0], sys_info.loads[1], sys_info.loads[2]);

  printf("  Total Ram: %ldk\tFree: %ldk\n", sys_info.totalram / 1024,
                                        sys_info.freeram / 1024);

  printf("\033[1;33m Shared Ram: \033[0;m %ldk -- ", sys_info.sharedram / 1024);
  printf(" Buffered Ram: %ldk\n", sys_info.bufferram / 1024);
  printf("\033[1;33m Total Swap: \033[0;m %ldk\tFree: %ldk\n", sys_info.totalswap / 1024,
                                           sys_info.freeswap / 1024);

  printf("\033[031;m  Total Number of processes: %d\n", sys_info.procs);
  printf("\033[0;m \n\n");
    
  gid = getgid();
    printf("  Group ID: \033[031m %d\n", gid);

    if((grp = getgrgid(gid)) == NULL )
      return 1;
    
      printf("\033[0;m  Group %s\n", grp->gr_name );
      printf(" Users in your group:");
    for( users = grp->gr_mem; *users != NULL; users++,++x )
      printf( "%d.  %s | \n", x, *users );

    if(strcmp(grp->gr_passwd,"x") == 0)
      printf("Password is protected by shadow file.\n");
    else
      printf("Password: %s\n", grp->gr_passwd);

  break;
  case 'b':

  printf("\n \033[4;34m Checking server for wired aliases:  \033[0;m \n");
  fd = socket(AF_INET, SOCK_DGRAM, 0); 
  ifr.ifr_addr.sa_family = AF_INET;

  strncpy(ifr.ifr_name , iface , IFNAMSIZ-1); 
ioctl(fd, SIOCGIFADDR, &ifr);
      printf("   IP ADDRESS OF %s - %s / ", iface, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
ioctl(fd, SIOCGIFNETMASK, &ifr); 
      printf("NETMASK OF %s - %s \n", iface, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );

  strncpy(ifr.ifr_name, iface2, IFNAMSIZ-1);
ioctl(fd, SIOCGIFADDR, &ifr);
      printf("   IP ADDRESS OF %s - %s / ", iface2, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
ioctl(fd, SIOCGIFNETMASK, &ifr); 
      printf("NETMASK OF %s - %s \n", iface2, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) ); 

  strncpy(ifr.ifr_name, iface00, IFNAMSIZ-1); 
ioctl(fd, SIOCGIFADDR, &ifr);
      printf("   ALIASES OF %s IP ADDRESS: %s \n", iface00, inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) ); 
  close(fd);
 break; 
case 'c': 
	cvalue = optarg;
	break;
case 'd': 
        system("ifconfig | more");
        system("ip addr | more"); 
        system("ufw status | more");
        break;
case '?': 
  if (optopt == 'c') 
      fprintf(stderr, "\n\n Usage: statos2 a|b|d|c \n -a (system information) \n -b (checking for wired aliases) \n -d (system check network) Note: statos2 -d >>network.log at the comamnd line to make a new document with network information. \n - Option -%c argument will print program usage.\n\n\n", optopt);
  else if (isprint (optopt)) fprintf(stderr, "Unknown Option %c. \n", optopt);
  else fprintf(stderr, "Unknown character '\\x%x'.\n", optopt);
  return 1;
  default:
 abort ();
}
 for(index = optind; index < argc; index++) printf("Non-Option argument %s ...\n", argv[index]);
 return 0;
}
