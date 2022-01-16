#include <stdio.h>

void printFileAsHex(FILE* file);
char toVisibleCharacter(int byteVal);
void writeLine(char* lineBuffer, int buflen);
char upperToHex(int byteVal);
char lowerToHex(int byteVal);
char nibbleToHex(int nibble);

#ifdef WIN32
    #define CRLF    "\r\n"
#else
    #define CRLF    "\n"
#endif

//number of bytes per line
//default 16 bytes 
#define LINELEN     17



int main(int argc, const char* argv[])
{
    FILE* file;
    
    if(argc != 2)
    {
printf("\33[1;34m Usage: \33[1;37m \n \33[1;39m \n %s [file] >dumpfile.doc\n\n", argv[0]);
printf("\33[1;38m _________________________________________________________________________ \n");
printf("\33[1;32m About:\n"); 
printf("\n Text book example of common hex dumping shell tool made for Ubuntu. \n No copyright this file is open public source. \n Made for use with the Linux encryption system.\n"); 
printf("\33[1;35m -Programming by Johnny B. \33[1;39m \33[0m \n");    
        printf(CRLF);
        return 1;
    }
    
    file = fopen(argv[1], "rb");
    if(NULL == file)
    {
        printf("ERROR: Cannot open %s", argv[1]);
        printf(CRLF);
        return 2;
    }

    printf("__________S_T_A_R_T__D_U_M_P______________________\n");
    printFileAsHex(file);
    fclose(file);
    printf("___________E_N_D__D_U_M_P_________________________\33[1;39m \n");
    printf("\7 \33[0m \n");
    return 0;
}

void printFileAsHex(FILE* file)
{
    int count = 0;
    char buffer[LINELEN];
    
    while(1)
    {
        int byteVal = fgetc(file);
        
        if(EOF == byteVal)
        {
            break;
        }

        buffer[count] = byteVal;
        count++;
        if(count >= LINELEN)
        {
            writeLine(buffer, LINELEN);
            count = 0;
        }
    }

    if(count > 0)
    {
        writeLine(buffer, count);
    }
}

char toVisibleCharacter(int byteVal)
{
    if(byteVal >= 32 && byteVal <= 126)
    {
        return (char) byteVal;
    }
    
    return '_';
}

void writeLine(char* lineBuffer, int buflen)
{
    int i;

    for(i=0; i<buflen; i++)
    {
        char chu = upperToHex(lineBuffer[i]);
        char chl = lowerToHex(lineBuffer[i]);
        printf("\33[1;32m %c%c \33[0m", chu, chl);
    }
    
    if(buflen < LINELEN)
    {
        for(i = LINELEN - buflen; i>0; i--)
        {
            printf("\33[2;31m *** \33[0m");
        }
    }

    printf("\t");
    
    for(i=0; i<buflen; i++)
    {
        char ch = toVisibleCharacter(lineBuffer[i]);
        printf("\33[3;44m %c \33[0m", ch);
    }

    printf(CRLF);
}

char upperToHex(int byteVal)
{
    int i = (byteVal & 0xF0) >> 4;
    return nibbleToHex(i);
}

char lowerToHex(int byteVal)
{
    int i = (byteVal & 0x0F);
    return nibbleToHex(i);
}

char nibbleToHex(int nibble)
{
    const int ascii_zero = 48;
    const int ascii_a = 65;
    
    if((nibble >= 0) && (nibble <= 9))
    {
        return (char) (nibble + ascii_zero);
    }
    if((nibble >= 10) && (nibble <= 15))
    {
        return (char) (nibble - 10 + ascii_a);
    }
    return '?';
}

