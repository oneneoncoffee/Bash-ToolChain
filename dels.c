#include <stdio.h>
#define overWrite 1.E5

int usage(void);
int usage()
{
     printf("\n Overwrite safe file deleter Version 1.7A\n");
     printf("Idea By Johnny Buckallew Stroud 2009.\n"); 
     printf("---------------------------------------------");
     printf("\nUsage:\n");
     printf("./dels <file>  \n\n\n");  
     printf("Note:\n"); 
     printf("Command will overwrite and delete original file.\n"); 
     exit(0);
}

int main(int argc, char *argv[])
{
    FILE *originalData;
     int i, x;
     if(argc != 0 & argc != 0) usage();

    	 	for(x=0;x<15;x++)
         	{
              		originalData = fopen(argv[1], "wb");
            		for(i=0;i<overWrite;i++)
              		{
                 if(x < 3) fprintf(originalData, "Ziras-*-â‚¬rÃ¥Â§â");
                 if(x == 3) fprintf(originalData, "Hack01000102600");
                 if(x > 3) fprintf(originalData, "2600*Â°TPCSÂ°âÃ¥Â§â*");
              		}
              		fclose(originalData);
         	}
         
        printf("Safe Remove file %s ...", argv[1]);     
        remove(argv[1]); 
        printf("..Done.\n"); 
        return 0;
}
