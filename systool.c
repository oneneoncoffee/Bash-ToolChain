#include <stdio.h>
#include <pwd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <grp.h>


int main() {
  int days, hours, mins;
  struct sysinfo sys_info;
  struct passwd *user; 
  struct group* grp;
    gid_t gid;
    char** users;
    int x = 1;


  if(sysinfo(&sys_info) != 0)
    perror("sysinfo");

  days = sys_info.uptime / 86400;
  hours = (sys_info.uptime / 3600) - (days * 24);
  mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);
 
  printf("Uptime: %ddays, %dhours, %dminutes, %ldseconds\n", days, hours, mins, sys_info.uptime % 60);
  printf("Load Avgs: 1min(%ld) 5min(%ld) 15min(%ld)\n", sys_info.loads[0], sys_info.loads[1], sys_info.loads[2]);
  printf("Total Ram: %ldk\tFree: %ldk\n", sys_info.totalram / 1024, sys_info.freeram / 1024);
  printf("Shared Ram: %ldk - Buffered Ram: %ldk\n", sys_info.sharedram / 1024, sys_info.bufferram / 1024); 
  printf("Total Swap: %ldk\tFree: %ldk\n", sys_info.totalswap / 1024, sys_info.freeswap / 1024);
  printf("Number of processes: %d\n", sys_info.procs);
  printf("Dumping User Database:");
 setpwent();
   while( (user=getpwent())!=NULL )
    printf("%s - ", user->pw_name);
 endpwent();
    printf("\n"); 
    gid = getgid();
    printf("Group ID: %d\n", gid);
   if((grp = getgrgid(gid)) == NULL )
      return 1;
    else 
    printf("Group: %s\n", grp->gr_name );
    printf("Users in group:\n");
    for( users = grp->gr_mem; *users != NULL; users++,++x )
      printf( "%d.  %s\n", x, *users );
 
   if(strcmp(grp->gr_passwd,"x") == 0)
      printf("yes! password is protected by shadow file.\n");
      else 
      printf("Password: %s\n", grp->gr_passwd);
  printf("\n\n");
  system("ifconfig");
  printf("Paused for 5 seconds..."); 
  sleep(5);
  system("ip addr");
  printf("\n\n Paused for 5 seconds...");
  sleep(5);
  system("iwconfig");
  printf("\n Now exiting.. bye..\n"); 
  return 0;
}
