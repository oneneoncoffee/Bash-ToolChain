#include<stdio.h> 
#include<pwd.h> 
#include<sys/types.h> 

main() {
struct passwd *user; 
setpwent(); 
	while((user=getpwent())!=NULL) {
	printf("%s ",user->pw_name);
}
       printf("\n");        

endpwent(); 

}
