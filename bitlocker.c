#include <stdio.h>
#define PROG_NAME "bitlocker"

void usage()
{
 printf("------------------------------------------------\n");
 printf("Usage:\n\t%s infile outfile key\n", PROG_NAME);
 printf("------------------------------------------------\n");
 printf("\nAbout This Program:\n");
 printf("This encryption method is really simple and I do not recommend it for stand alone \n encryption use.");  
 printf("You can run this encryption tool over an already encrypted file. \n"); 
}


int main(int argc, char *argv[])
{
   int count,bytes,count2; 

   FILE *in,*out;
   FILE *in2,*out2;    

    if(argc < 4) { 
     usage();       
      return 0;     
      }

    if (( in = fopen(argv[1], "rb")) == NULL) 
     {
       printf("Error opening %s.\n", argv[1]);
     }
    if (( out = fopen(argv[2], "wb")) == NULL)
     {
       printf("Error opening %s.\n", argv[2]);
     }

      
       while(( count = getc(in)) != EOF )  {  
           count = count ^ *argv[3] +  *argv[0]; 
           bytes++;            			
           putc(count, out);		
        }
       while(( count = getc(out)) != EOF )  { 
           bytes++; 
           putc(count, out); 
        } 

         fclose(in);
         fclose(out);
         
         printf("1st Pass Encryption Success:\n");
         printf("\tEncrypted %s and stored data in %s.\n", argv[1],argv[2]);
         printf("\tWrote %d bytes to %s.\n", bytes,argv[2]);
     

         in2 = fopen(argv[1], "rb"); 
         out2 = fopen(argv[2], "wb"); 
         while(( count2 = getc(in2)) != EOF) {
         count2 = count2 ^ *argv[0]; 
         bytes++; 
         putc(count2, out2);
         }   
         fclose(in2); 
         fclose(out2); 
         printf("2st Pass Encryption Success:\n");
         printf("\tEncrypted %s and stored data in %s.\n", argv[1],argv[2]);
  
         printf("\tWrote total %d bytes to %s.\n", bytes,argv[2]);
     

   return 0;
}
