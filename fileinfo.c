
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char *argv[]) {
 
 char  cmpname[256];
 struct utsname uts;
 struct stat file_stats;

 if(argc != 2)
  fprintf(stderr, "Usage: fileinfo FILE\n"), exit(EXIT_FAILURE);

 if((stat(argv[1], &file_stats)) == -1) {
  perror("fstat"); 
  return 1;
 }

 printf("\n filename: %s\n", argv[1]);
 printf(" total size, in bytes: %ld \n",           file_stats.st_size);
 printf(" last access: %s ",               ctime(&file_stats.st_atime));
 printf("last modification: %s ",         ctime(&file_stats.st_mtime));
 printf("last change: %s ",               ctime(&file_stats.st_ctime));
 printf("device: %lld ",                       file_stats.st_dev);
 printf("** inode: %ld **",                         file_stats.st_ino);
 printf(" protection: %o \n",                     file_stats.st_mode);
 printf(" number of hard links: %d\n",           file_stats.st_nlink);
 printf(" user ID of owner: %d --",               file_stats.st_uid);
 printf(" group ID of owner: %d\n",              file_stats.st_gid);
 printf(" device type (if inode device): %lld\n",file_stats.st_rdev);
 printf(" blocksize for filesystem I/O: %ld\n",  file_stats.st_blksize);
 printf(" number of blocks allocated: %ld\n",    file_stats.st_blocks);
 printf("System Info:\n");

 if(gethostname(cmpname, 255) == 0)
  printf("Host    Name : %s\n", cmpname);
 if(uname(&uts) == 0) {
  printf("System  Name : %s\n", uts.sysname);
  printf("Machine Name : %s\n", uts.machine);
  printf("Node    Name : %s\n", uts.nodename);
  printf("Release Name : %s\n", uts.release);
  printf("Version Name : %s\n", uts.version);
 }
 printf("\n"); 
 return 0;
}

