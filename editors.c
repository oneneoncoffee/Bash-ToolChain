/***************************************
 * Editors.c text source editor Ver1.6 *
 ***************************************/
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>

#define MAX 50000
#define LEN 256
#define NR_ARGS 3
#define FILE_ARG_INDEX 1
char text[MAX][LEN];
char option = 0;
/*******************************************
        DO EXIT SUBFUNCTIONS HERE 
 ********************************************/
long CountCharacters(FILE*fp2)
{
    long counter = 0L;
    char c = 0x01;
    while(c!=EOF)
    {
        c = fgetc(fp2);
        counter++;
    }
    return counter;
}
long CountLines(FILE*fp2)
{
    long counter = 1L;
    char c = 0x01;
    while(c!=EOF)
    {
        c = fgetc(fp2);
        if(c=='\n')
        {
            counter++;
        }
    }
    return counter;
}
long CountWords(FILE*fp2)
{
    long counter = 0L;
    char c = 0x01;
    bool isInsideWord = true;
    while(c!=EOF)
    {
        c = fgetc(fp2);
        if(isInsideWord==true)
        {
         counter++;
         isInsideWord = false;
        }
        else if(isspace(c))
        {
         isInsideWord = true;
        }
    }
    return counter;
}
int main(int argc, char **argv[]) {
register int t,x,j;
struct timeval v1, v2;
gettimeofday(&v1, NULL);
FILE *outfile;
if(argc !=3) {
printf("Error: No write mode slected \n\n USAGE: ./editor [file name to open] [file options: new/append]\n\n");
exit(1);
}

if(!strcmp(argv[2], "append")) outfile = fopen(argv[1], "a");
if(!strcmp(argv[2], "new")) outfile = fopen(argv[1], "w+");

if (outfile == NULL) {
perror ("The following error occurred");
} if (argc <= 1) { printf("USAGE: ./editor [file name to open] [New/Append]\n\n"); exit(0); }

system("clear");
printf("OPEN FILE: %s Write Mode: %s \n Enter an empty line to quit. \n", argv[1], argv[2]);
for(t = 0; t < MAX; t++) {
printf("%d: ", t);
gets(text[t]);
fprintf(outfile, "%s\n",text[t]);
if(!*text[t]) break;
}
system("clear");
printf("Output Saved to file %s \n Lines for review by editor: \n", argv[1]);
  for(x = 0; x < t; x++) {  for(j = 0; text[ x ][ j ]; j++) putchar(text[ x ][ j ]); putchar('\n'); }
fclose(outfile);
FILE*fp2;
 long characters = 0UL, lines = 0UL, words = 0UL;
 if(argc==NR_ARGS)
 {
     fp2 = fopen(argv[FILE_ARG_INDEX],"rt");
     if(argv[1]!=NULL)
     {
         characters = CountCharacters(fp2);
         rewind(fp2);
         lines = CountLines(fp2);
         rewind(fp2);
         words = CountWords(fp2);
         rewind(fp2);
         printf("Characters: %ld Lines: %ld Words: %ld \n", characters,lines,words);
         fclose(fp2);
     }
     else
     {
         perror("Error: Could not open file");
     }
 }
 else
 {
     perror("Error: Incorrect number of arguments");
 }
 gettimeofday(&v2, NULL);
 printf("Run time: %f seconds \n", (double) (v2.tv_usec -v1.tv_usec) / 1000000 + (double) (v2.tv_sec - v1.tv_sec));
 return 0;
}
