#include <stdio.h>
#include <stdlib.h>
#define KEY_LENGTH 66

unsigned char Random_Byte(void)
{
   double result;
   
   result = (double) rand() / (double) RAND_MAX;
   result = result * 255.0;
   return (unsigned char) result;
}



void Crypt(FILE *input, FILE *output)
{
   unsigned char key[KEY_LENGTH];
   int key_index, in_value;
   unsigned char out_value, random_value;
   int done;

   /* create random key */
   for (key_index = 0; key_index < KEY_LENGTH; key_index++)
      key[key_index] = Random_Byte();

   /* write key to start of output file */
   fwrite(key, sizeof(unsigned char), KEY_LENGTH, output);

   done = 0;
   while (!done)
   {
       in_value = fgetc(input);
       if (in_value >= 0)
       {
          out_value = (unsigned char) in_value;
          random_value = Random_Byte();

          for (key_index = 0; key_index < KEY_LENGTH; key_index++)
            out_value = out_value ^ key[key_index];

          out_value = out_value ^ random_value;
          fputc(random_value, output);
          fputc(out_value, output); 
       }
       else
         done = 1;

   }  /* end of while */ 
}  /* end of Crypt() */

void Decrypt(FILE *input, FILE *output)
{
   unsigned char key[KEY_LENGTH];
   int key_index, in_value;
   unsigned char random_value, out_value;
   int done;

   /* read encryption key from file */
   fread(key, sizeof(unsigned char), KEY_LENGTH, input);

   done = 0;
   while (!done)
   {
      /* read in random value */
      in_value = fgetc(input);
      if (in_value >= 0)
      {
         random_value = (unsigned char) in_value;
         in_value = fgetc(input);
         if (in_value >= 0)
         {
             out_value = (unsigned char) in_value;
             out_value = out_value ^ random_value;
             for (key_index = (KEY_LENGTH - 1); key_index >= 0; key_index--)
                out_value = out_value ^ key[key_index];

             fputc(out_value, output);
         }
         else 
           done = 1;
       }
       else
         done = 1;
      
   }   /* end of while */

}  /* end of Decrypt() */  



int main(int argc, char *argv[])
{
   FILE *input, *output;
  
   if (argc < 4)
   {
       printf("\n\33[1;37m .. \33[1;31m 1st Pass Encryption \33[1;37m ..\n");
       printf("usage: \33[1;31m Encrypt \33[1;37m e|d  \33[1;31m <in_file> <out_file>\n");
       printf("Use the `e' option to encrypt in_file, producing out_file.\n");
       printf("Use the `d' option to decrypt out_file giving in_file.\n\n");
       printf("\33[1;37m ------------------------------------------------------\n");
       printf("Example: \33[2;33m \n"); 
       printf("Encrypt c plain.txt coded.txt\n");
       printf("Encrypt d coded.txt newplain.txt \33[1;37m \n");
       printf("\n Last update:  Sat Aug 8/9/2008 5:35AM \n");
       return 0;
   }

   if ( (argv[1][0] != 'e') && (argv[1][0] != 'd') )
   {
       printf("First agument must be `e' or `d'.\n");
       return 1;
   }

   input = fopen(argv[2], "r");
   if (!input)
   {
      printf("Cannot open %s for reading.\n", argv[2]);
      return 1;
   }

   output = fopen(argv[3], "w");
   if (!output)
   {
      printf("Cannot open %s for writting.\n", argv[3]);
      fclose(input);
      return 1;
   }

   printf("Working......");
   srand( time(NULL) );
   if (argv[1][0] == 'e')
      Crypt(input, output);
   else
      Decrypt(input, output);

   printf("....Done.\n");
   fclose(input);
   fclose(output);
   return 0;

}   /* end of main() */
