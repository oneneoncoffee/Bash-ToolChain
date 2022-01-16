/*
        GCC ELF compiler only not supported by QT but works with none the less. 
        
        How to compile this source code from the bash shell usage: 
        
        gcc isnetworksafe.c -o isnetworksafe 
        
        Program may return warnings because this is A very ugly port of the Java based, 
        zero-day. 
        

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
    #include <stdarg.h>
    #include <netinet/tcp.h>
    #include <netinet/in.h>

int socket_connect(char *host, in_port_t port){
	struct hostent *hp;
	struct sockaddr_in addr;
	int on = 1, sock;     

	if((hp = gethostbyname(host)) == NULL){
		herror("gethostbyname");
		exit(1);
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

	if(sock == -1){
		perror("setsockopt");
		exit(1);
	}
	
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("connect");
		exit(1);

	}
	return sock;
}
 
    #define BUFFER_SIZE 1024
    #define protocol "80"
    #define maxdatasize 100*100
    #define PROTOCOL "80"
    #define MAXDATASIZE  100*100 /* This will slooow down our test 1024*1024 */
    
    #ifndef   NI_MAXHOST
    #define   NI_MAXHOST 1025
    #endif
    
  static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
} 
 void errorout(int status, const char *format, ...);
 void *get_in_addr(struct sockaddr *sa);
  
  int main(int argc, char *argv[])
{
int error, status;
struct addrinfo *infos;
struct addrinfo hints;
struct addrinfo * _addrinfo;
struct addrinfo * _res;
struct addrinfo *result;
struct addrinfo *res;

memset(&hints, 0, sizeof(hints));
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE;
hints.ai_family = AF_UNSPEC;

if(argc <2) {
    printf("Error: Not enough arguments to continue");
    exit(1);
    } else 
    
status = getaddrinfo(argv[1],
                     protocol,
                     &hints,
                     &infos);
 if(status != 0)
        errorOut(-1, "Couldn't get addres information: %s\n", gai_strerror(status));
int sockfd;
struct addrinfo *p;

    for(p = infos; p != NULL; p = p->ai_next) {
        // CREATE SOCKET
        sockfd = socket(p->ai_family, 
                        p->ai_socktype, 
                        p->ai_protocol);
        if(sockfd == -1)
            continue;

        // TRY TO CONNECT
        status = connect(sockfd, 
                         p->ai_addr, 
                         p->ai_addrlen);
        if(status == -1) {
            close(sockfd);
            continue;
        }

        break;
    
    }
    
    if(p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return 1;
    }
    
    char printableIP[INET6_ADDRSTRLEN];
    inet_ntop(p->ai_family,
              get_in_addr((struct sockaddr *)p->ai_addr),
              printableIP,
              sizeof(printableIP));
 printf("Connection to %s\n", printableIP);
 printf("INET6 IP lookup: \n");   
 char _address[INET6_ADDRSTRLEN];
  int errcode = 0;

  if(argc < 2) {
    return EXIT_FAILURE;
  }

  errcode = getaddrinfo(argv[1], NULL, NULL, &_addrinfo);
  if(errcode != 0) {
    printf("getaddrinfo: %s\n", gai_strerror(errcode));
    return EXIT_FAILURE;
  }

  for(_res = _addrinfo; _res != NULL; _res = _res->ai_next) {

    if(_res->ai_family == AF_INET) {

      if( NULL == inet_ntop( AF_INET,
        &((struct sockaddr_in *)_res->ai_addr)->sin_addr,
        _address,
        sizeof(_address) )
      ) {
        perror("inet_ntop");
        return EXIT_FAILURE;
      }

      printf("%s\n", _address);
    }
}
   


    error = getaddrinfo(argv[1], NULL, NULL, &result);
    if (error != 0)
    {   
        fprintf(stderr, "error in getaddrinfo: %s\n", gai_strerror(error));
        return EXIT_FAILURE;
    }   

    printf("\n Looping over all returned results and do inverse lookup. \n");
    for (res = result; res != NULL; res = res->ai_next)
    {   
        char hostname[NI_MAXHOST] = "";

        error = getnameinfo(res->ai_addr, res->ai_addrlen, hostname, NI_MAXHOST, NULL, 0, 0); 
        if (error != 0)
        {
            fprintf(stderr, "error in getnameinfo: %s\n", gai_strerror(error));
            continue;
        }
        if (*hostname != '\0')
            printf("Hostname: %s\n", hostname);
    }   

    freeaddrinfo(result);
    freeaddrinfo(infos);
    
    printf("Searching server with GET request... \n");
    int fd;
	char buffer[BUFFER_SIZE];


	fd = socket_connect(argv[1], atoi(protocol)); 
	write(fd, "GET /\r\n", strlen("GET /\r\n")); // write(fd, char[]*, len);  
	bzero(buffer, BUFFER_SIZE);
	
	while(read(fd, buffer, BUFFER_SIZE - 1) != 0){
		fprintf(stderr, "%s", buffer);
		bzero(buffer, BUFFER_SIZE);
	}

	shutdown(fd, SHUT_RDWR); 
	close(fd); 
    printf("Looking for index file.. \n");
    fd = socket_connect(argv[1], atoi(protocol)); 
	write(fd, "GET /index.html\r\n", strlen("GET /index.html\r\n")); // write(fd, char[]*, len);  
	bzero(buffer, BUFFER_SIZE);
	
	while(read(fd, buffer, BUFFER_SIZE - 1) != 0){
		fprintf(stderr, "%s", buffer);
		bzero(buffer, BUFFER_SIZE);
	}
    shutdown(fd, SHUT_RDWR); 
	close(fd);
    printf("\n Other index alias (index.htm)  \n");
   fd = socket_connect(argv[1], atoi(protocol)); 
	write(fd, "GET /index.htm\r\n", strlen("GET /index.htm\r\n"));   
	bzero(buffer, BUFFER_SIZE);
	
	while(read(fd, buffer, BUFFER_SIZE - 1) != 0){
		fprintf(stderr, "%s", buffer);
		bzero(buffer, BUFFER_SIZE);
	}
    shutdown(fd, SHUT_RDWR); 
	close(fd); 
    printf("\n  Looking for PHP server alias (index.php) \n");
      fd = socket_connect(argv[1], atoi(protocol)); 
	write(fd, "GET /index.php\r\n", strlen("GET /index.php\r\n"));   
	bzero(buffer, BUFFER_SIZE);
	
	while(read(fd, buffer, BUFFER_SIZE - 1) != 0){
		fprintf(stderr, "%s", buffer);
		bzero(buffer, BUFFER_SIZE);
	}
    shutdown(fd, SHUT_RDWR); 
	close(fd); 
     
    
  return EXIT_SUCCESS;
  return 0;
}


void *get_in_addr(struct sockaddr *sa) {
    // IP4
    if(sa->sa_family == AF_INET)
        return &(((struct sockaddr_in *) sa)->sin_addr);

    return &(((struct sockaddr_in6 *) sa)->sin6_addr);
}



void errorOut(int status, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(status);
}
