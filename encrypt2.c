#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include</usr/include/sys/stat.h>  

void makekey(long int,char *);


int main(int argc,char **argv)
{
struct stat statbuf;

time_t  t;
int key;
int data;
int output;
int count=0;
int FLAG=0;
FILE * mykeyfile;
FILE * sourcefile;
FILE * destfile;

if(argc<3)
	{
   printf("\n\33[1;37m .. \33[1;31m 2nd Pass Encryption \33[1;37m ..\n");
   printf("USAGE: \33[1;31m program \33[1;37m  \33[1;34m input_file output_file keyfile\n \33[1;37m");
   printf(" input_file  - your text file. \n");
   printf(" output_file - encrypted/decrypted file. \n");
   printf(" keyfile     - text file with password in it. \n\n\n"); 
   return(0);
   }

if(argc>4){printf("Too many arguments.");return(1);}


 srand((unsigned) time(&t));

   if ((sourcefile = fopen(argv[1], "rb"))== NULL)
   {
   printf("Can't open source file.\n");
   return(4);
   }
   fflush(sourcefile);
   fstat(fileno(sourcefile), &statbuf);
   fclose(sourcefile);

if(argv[3]==NULL){argv[3]="newkey";}

if ((mykeyfile = fopen(argv[3], "r"))== NULL)
   {
   FLAG=1;
   printf("Can't open key file.\n");
   printf("...................................\n");
   makekey(statbuf.st_size,"newkey");
   }else{fclose(mykeyfile);}

   mykeyfile=fopen(argv[3],"rb");
   sourcefile=fopen(argv[1],"rb");
   destfile=fopen(argv[2],"wb");

while (count < (statbuf.st_size))
   {
   key=fgetc(mykeyfile);
   data=fgetc(sourcefile);

   output=(key^data);

   fputc(output,destfile);
   count++;
   }

   fclose(mykeyfile);
   fclose(sourcefile);
   fclose(destfile);

   if(FLAG==0)
   {
   printf("\33[2;38m Cypher output Done.... \33[1;37m \n\n");
   }
   return(0);
}

void makekey(long int size,char *name)
{
 int byte;
 int count=0;
 FILE * filein;
 filein=fopen(name,"wb");
   byte=rand() % 256;
   fprintf(filein,"%c",byte);
fclose(filein);
}




