#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
 char buf[1024];
 int n, in, out;

 in = open(argv[1], O_RDONLY);
 out = open(argv[2], O_WRONLY|O_APPEND);

 while((n = read(in, buf, sizeof(buf))) > 0){
  write(out, buf, n); }
 return 0;
}
