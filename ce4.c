#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_FORMULA  (int) Byte + 125
#define DECRYPTION_FORMULA  (int) Byte - 125
#define MAX_SIZE 256 

void strip_newline(char* to_strip);
void encrypt_data(FILE* input_file, FILE* output_file, char *key);

int Encrypt(char * FILENAME, char * NEW_FILENAME)
{
		 FILE *inFile, *outFile;
		 char Byte;
		 char newByte;
		 int n;

		 int i=0;

		 inFile = fopen(FILENAME,"rb");
		 outFile = fopen(NEW_FILENAME, "wb");

		 if(inFile==NULL)
		 		 printf("Error: Can't Open inFile");

		 if(outFile==NULL)
		 {
		 		 printf("Error: Can't open outFile.");
		 return 1;
		 }
		 else
		 {

		 		 printf(" File Opened, Encrypting");
		 		 while(1)
		 		 {
		 		 		 printf(".");


		 		 		 if(Byte!=EOF)
		 		 		 {
		 		 		 		 Byte=fgetc(inFile);
		 		 		 		 newByte=Byte+125;

		 		 		 		 fputc(newByte,outFile);

		 		 		 }

		 		 		 else
		 		 		 {
		 		 		 		 printf("Done.\n\n");
		 		 		 		 break;
		 		 		 }
		 		 }
		 fclose(inFile);
		 fclose(outFile);

		 }
}

int Decrypt (char *FILENAME, char *NEW_FILENAME)
{
		 FILE *inFile, *outFile;

		 char Byte;
		 char newByte;
		 int i=0;

		 inFile = fopen(FILENAME,"rb");
		 outFile = fopen(NEW_FILENAME, "wb");

		 if(inFile==NULL)
		 		 printf("Error: Can't Open inFile");

		 if(outFile==NULL)
		 {
		 		 printf("Error: Can't open outFile.");
		 return 1;
		 }
		 else
		 {

		 		 printf(" File Opened, Decrypting");
		 		 while(1)
		 		 {
		 		 		 printf(".");


		 		 		 if(Byte!=EOF)
		 		 		 {
		 		 		 		 Byte=fgetc(inFile);
		 		 		 		 newByte=Byte-125;

		 		 		 		 fputc(newByte,outFile);

		 		 		 }

		 		 		 else
		 		 		 {
		 		 		 		 printf("Done. \n\n");
		 		 		 		 break;
		 		 		 }
		 		 }
		 fclose(inFile);
		 fclose(outFile);

		 }
}


void encrypt_data(FILE *input_file, FILE *output_file, char *key)
{
	int key_count = 0; //Used to restart key if strlen(key) < strlen(encrypt)
	int encrypt_byte;

	while( (encrypt_byte = fgetc(input_file)) != EOF) //Loop through each byte 
	{
		//XOR the data and write it to a file
		fputc(encrypt_byte ^ key[key_count], output_file); 
		//Increment key_count and start over if necessary
		key_count++;
		if(key_count == strlen(key))
			key_count = 0;
	}
}

void strip_newline(char* to_strip)
{
	//remove newlines
	if (to_strip[strlen(to_strip) - 1] == '\n') {
		to_strip[strlen(to_strip) - 1] = '\0';
	}
}

int main()
{
		 char *encFile[200], *newencFile[200], *decFile[200], *newdecFile[200], *dataw[200];

		 int choice, x;
                 system("clear");
for ( x = 0; x < 10; x++ ) {
		 printf("\n >>>>>>>>>>>>>>>>>>>> ENCRYPTION PROGRAM MAIN MENU <<<<<<<<<<<<<<<< \n");
		 printf("\n 1. Encrypt A text document. \n 2. Decrypt A text document. \n 3. Encrypt and delete A text document.\n");
                 printf(" 4. Exit Program. \n 5. encrypt xor and decoy document. \n");
                 printf(" \n\n Command:");
		 scanf("%d",&choice);

		 switch(choice)
		 {
		 case 1:
		 		 		 printf("Enter source document filename:  ");
		 		 		 scanf("%s",&encFile);
		 		 		 printf("Enter new destination filename:  ");
		 		 		 scanf("%s",&newencFile);
		 		 		 Encrypt(encFile, newencFile);
                                                 printf("\n Removeing old files.");
                                                 Encrypt(encFile, encFile); 
                                                 remove(encFile);
                                                 printf("\n"); 
		 		 break;
		 case 2:
		 		 		 printf("Enter encrypted source filename:   ");
		 		 		 scanf("%s",&decFile);
		 		 		 printf("Enter new destination filename for decryption:   ");
		 		 		 scanf("%s",&newdecFile);
		 		 		 Decrypt(decFile, newdecFile);
                                                 printf("Removeing old files.");
                                                 Encrypt(decFile, decFile);
						 remove(decFile); 
		 		 break;
                case 3:
                                                 printf("Enter filename to be deleted:  ");
                                                 scanf("%s",&encFile); 
                                                 Encrypt(encFile, encFile); 
                                                 remove(encFile); 
                                                 printf("Done file trashed and removed. \n\n");
				 break;
                case 4:
                                                 printf("\7 Exiting program now! \n\n\n");
                                                 return 0;
                                                 break;
                case 5:
                                                printf("\nThis action will add one level of xor decoy encryption to the, \n");
                                                printf("text document then delete all files.  \n");
                                                printf("This is only A anti-cracking deployable decoy method to make your file,\n");
                                                printf("computationally harder to reconstruct. \n");
	FILE *input;
	FILE *output;

        printf("\n Enter source document filename:  ");
        scanf("%s",&encFile);
        printf(" Enter new destination filename:  ");
        scanf("%s",&newencFile);
	input = fopen(encFile, "r");
	output = fopen(newencFile, "w");      
	char *key = malloc(MAX_SIZE), str[]="A@@@@DA@@@DA@@@@D^@^@^@@addad@@@@@@@@^^^^adada^^@@@^^^A@@DADA@@@Dad@@@ada@@@da@@d";        
        fgets(key, MAX_SIZE, input);
        fwrite(str, 1, sizeof(str), output);
        fwrite(str, 1, sizeof(str), output); 
	printf("\n Xor Encrypting trashing and adding decoy data to RAM FILENAME: %s \n", encFile);
	strip_newline(key);
	encrypt_data(input, output, key);       
	printf("Decoy data written to %s\n", newencFile);
	free(key);
	fclose(input);
	fclose(output);
        Encrypt(encFile, encFile); 
        FILE *writeit;
        printf("\n\n Write more junk to open file ? Enter Filename:   ");
        scanf("%s",&dataw);
        writeit = fopen(dataw, "w+");
        fprintf(writeit,"yummylulzlulzlulzlololololohappyhappyhapyyho!happyhappyhappyHO!whatthefoxsay?");
        fprintf(writeit,"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        fprintf(writeit,"%%%%%%%%%%##_)()#(**********@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
        fprintf(writeit,"AAAAADDDDDDDDDDDDDAAAAAAAAAAAAAAADDDDDDDDDDDDDDDDDDDDAAAAAAAAAAAADDDDDDDD");
        fclose(writeit);
        printf("\n\n Deleteing [ALL] open files.. \n");
        remove(encFile);
        remove(newencFile);
        system("clear");
        break;

	 }

    }
    printf("\n\n Default Error: Exiting Program now! \n");
    return 0;
}
