#include <stdio.h>

int main(void) {
FILE *file_in;
char filename[20]; 
char ch;

printf("\n What other file do you want to open?: ");
gets(filename);
file_in=fopen(filename, "r");

if(file_in==NULL) printf("Error: File did not open.\n");

printf("Open file name: %s \n\n", filename);
while((ch=fgetc(file_in)) != EOF) putchar(ch);
printf("\n\n ** END OF FILE ** \n"); 
return 0; 
}
