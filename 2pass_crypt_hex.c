//Project: XOR Encryption, 2 Password System Example. 
//Program: Version 1.2 / Lines of code: 227                              
//Programmer Name: Johnny B Stroud (Ubuntu GCC tested)
//To Make program: gcc 2pass_crypt_hex.c -o 2passhex
//To Run program:  ./2passhex input output (Basic file Usage)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
 
#define MIN_SIZE      128
#define MAX_SIZE      256
#define SIZE          256
#define HEX_OFFSET    1
#define ASCII_OFFSET  51
#define NUM_CHARS     16

void strip_newline(char* to_strip);
void encrypt_data(FILE* input_file, FILE* output_file, char *key);
void encrypt_data2(FILE* input_file, FILE* output_file, char *key2);
void hexdump(char* prog_name, char * filename);
void clear_line(char *line, int size);

char * hex   (char *position, int c);
char * ascii (char *position, int c);

void usage_null();

int main(int argc, char* argv[])
{       char *prog_name=argv[0];
	//Check for valid number of arguments
	if (argc != 3) { usage_null(); }
	
	FILE* input;
	FILE* output;

	//Open input and output files
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
		

	//Check input file
	if (input == NULL)
	{
		printf("Input file cannot be read.\n");
		exit(0);
	}
		
	//Check output file
	if (output == NULL)
	{
		printf("Output file cannot be written to.\n");
		exit(0);
	}

	//Key strings
	char *key = malloc(MIN_SIZE);
  
	//Prompt for key
	printf("Passphrase: ");

	//Read in key
	fgets(key, MIN_SIZE, stdin);

	printf("Encrypting %s\n", argv[1]);

	//strip newlines
	strip_newline(key);

	//XOR data and write it to file
	encrypt_data(input, output, key);
	
	printf("Data written to %s\n", argv[2]);

	//Release memory
	free(key);         
        hexdump(argv[0], argv[1]);

        char *key2 = malloc(MAX_SIZE);
        printf("Password:");
        fgets(key2, MAX_SIZE, stdin);
        printf("Encrypting %s\n", argv[1]);
        strip_newline(key2);
        encrypt_data2(input, output, key2);
        printf("Encrypted data written to %s\n", argv[2]);
        free(key2);
 
	//Close files
	fclose(input);
	fclose(output);    
        hexdump(argv[0], argv[2]); 

	return 0;

}


void encrypt_data(FILE* input_file, FILE* output_file, char* key)
{
	int key_count = 0; //Used to restart key if strlen(key) < strlen(encrypt)
	int encrypt_byte;
	
	while( (encrypt_byte = fgetc(input_file)) != EOF) //Loop through each byte of file until EOF
	{
		//XOR the data and write it to a file
		fputc(encrypt_byte ^ key[key_count], output_file);

		//Increment key_count and start over if necessary
		key_count++;
		if(key_count == strlen(key))
			key_count = 0;
	}
}

void encrypt_data2(FILE* input_file, FILE* output_file, char* key2)
{
	int key_count = 0; //Used to restart key if strlen(key) < strlen(encrypt)
	int encrypt_byte;
	
	while( (encrypt_byte = fgetc(input_file)) != EOF) //Loop through each byte of file until EOF
	{	
		fputc(encrypt_byte ^ key2[key_count], output_file);
		key_count++;
		if(key_count == strlen(key2))
			key_count = 0;
	}
}

void strip_newline(char* to_strip)
{
	//remove newlines
	if (to_strip[strlen(to_strip) - 1] == '\n')
	{
		to_strip[strlen(to_strip) - 1] = '\0';
	}
}



void hexdump(char* prog_name, char * filename)
{
    int c=' ';                // Character read from the file.
    char * hex_offset;        // Position of the next character * in Hex     
    char * ascii_offset;      // Position of the next character in ASCII.         
    char buffer[SIZE];
    time_t curtime;
    struct tm *loctime;
    curtime = time (NULL);
    loctime = localtime (&curtime);

    FILE *ptr;                       /* Pointer to the file.   */
    FILE *log;                       /* Pointer to logfile.log for Appending */

    char line[81];        /* O/P line.      */
    /* Open the files    */
    ptr = fopen(filename,"r");
    log = fopen("logfile.log","a+");
    if ( ferror(ptr) )
    {
        printf("\n\t%s: Unable to open %s\n\n", prog_name, filename);
        exit(0);
    }

    printf("\n\t Appending data of %s to Log file. \n", filename);
       
       fputs (asctime (loctime), stdout);  // Print out the date and time in the standard format.
       fprintf(log, buffer, SIZE, "Log Date: %A, %B %d \n", loctime); //  write Log Date to file. 
       strftime (buffer, SIZE, "New Log Date: %A, %B %d.\n", loctime); //  Print Date 
       fputs (buffer, stdout);                                               
       fprintf(log, buffer, SIZE, "Log Time: %I:%M %p.\n", loctime); // write Log Time to file. 
       strftime (buffer, SIZE, "New Log Time: %I:%M %p.\n", loctime); // Print Time
       fputs(buffer, stdout);
      
    fprintf(log,"Log hex file: %s \n ------------------------------------------ \n", filename);

    while (c != EOF )
    {
        clear_line(line, sizeof line);
        hex_offset   = line+HEX_OFFSET;
        ascii_offset = line+ASCII_OFFSET;

        while ( ascii_offset < line+ASCII_OFFSET+NUM_CHARS
                &&(c = fgetc(ptr)) != EOF  )
        {
            hex_offset = hex(hex_offset, c); 
            ascii_offset = ascii(ascii_offset, c);

        }     //   printf("%s\n", line);
           fprintf(log,"%s\n", line);
    }
    fprintf(log,"------------------------------------------------\n ( END OF FILE ) \n\n"); 
    fclose(ptr);
    fclose(log);
}

void clear_line(char *line, int size)
{
    int count;

    for  (count=0; count < size; line[count]=' ', count++);
}

char * ascii(char *position, int c)
{    
    if (!isprint(c)) c='.';        //If the character is NOT printable replace it with a '.'  
    sprintf(position, "%c", c);    //Put the character to the line so it can be displayed later    
    return(++position);            // Return the position of the next ASCII character.  
}

char * hex(char *position, int c)
{
    int offset=3;

    sprintf(position, "%02X ", (unsigned char) c);

    *(position+offset)=' ';   // Remove the '/0' created by 'sprint'  

    return (position+offset);
}

void usage_null() 
{
		printf("ERROR: Invalid number of arguments.\n");
		printf("Usage: program_name inputfile outputfile\n"); 
		exit(0);
}
