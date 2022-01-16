#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
 uid_t uid;
 gid_t gid;
 struct passwd *pw;

 uid = getuid();
 gid = getgid();
 
 printf("\n\n I am user: %s  ", getlogin());
 printf(" uid: %d  ", uid); 
 printf(" gid: %d  \n", gid);
 pw = getpwuid(uid);
 printf(" home: %s  ", pw->pw_dir);
 printf(" shell: %s\n", pw->pw_shell);

 printf("\n");

 printf("Root Info:\n");
 pw = getpwnam("root");
 printf(" name : %s\n", pw->pw_name);
 printf(" uid  : %d\n", pw->pw_uid);
 printf(" gid  : %d\n", pw->pw_gid);
 printf(" home : %s\n", pw->pw_dir);
 printf(" shell: %s\n\n\n", pw->pw_shell);

 return 0;
}

