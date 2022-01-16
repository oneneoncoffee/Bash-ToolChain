#include <stdio.h>
#define overWrite 3.E5

int usage(void);
int usage()
{
     printf("\nOverwriteing XOR encryption  \n");
     printf("\nUsage:\n");
     printf("./encrypt3 <inFile> <outFile> <key> [-d]  \n\n");  
     printf("Optional -d switch will overwrite and delete original file.\n"); 
     exit(0);
}

int main(int argc, char *argv[])
{
     FILE *originalData, *encryptedData;
     int byte, character, x, i, argComp;
     char delSwitch[] = "-d";
    
     if(argc != 4 && argc != 5) usage();
     if((originalData = fopen(argv[1], "rb")) == NULL)
     {
          printf("\nError opening %s\n\n", argv[1]);
          exit(0);
     }
     if((encryptedData = fopen(argv[2], "wb")) == NULL)
     {
          printf("\nError opening %s\n\n", argv[2]);
          exit(0);
     }

     while((character = getc(originalData)) != EOF)
     {
          character = character ^ *argv[3];
          byte++; putc(character, encryptedData);
     }
     fclose(originalData); fclose(encryptedData);

     if(argc == 5) 
     {
    	argComp = strcmp(delSwitch,argv[4]);
   	if(argComp==0)
     	{
         	for(x=0;x<15;x++)
         	{
              		originalData = fopen(argv[1], "wb");
            		for(i=0;i<overWrite;i++)
              		{
                 if(x < 3) 
fprintf(originalData, "Ziras-*-â‚¬rÃ¥Â§â");
                if(x == 3) 
fprintf(originalData, "Hack01000102600");
               if(x > 3) 
fprintf(originalData, "2600*Â°TPCSÂ°âÃ¥Â§â*");
              		}
              		fclose(originalData);
         	}
        printf("Safe Remove of %s ...", argv[1]);     
       remove(argv[1]); 
        printf("..Done.\n"); 
        return 0;
    	 }
   }
}

