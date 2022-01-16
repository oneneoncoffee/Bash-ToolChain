/*
      * Basic Color Table *
1m     -     Change text to hicolour (bold) mode
4m     -        "    "   "  Underline (doesn't seem to work)
5m     -        "    "   "  BLINK!!
8m     -        "    "   "  Hidden (same colour as bg)
30m    -        "    "   "  Black
31m    -        "    "   "  Red
32m    -        "    "   "  Green
33m    -        "    "   "  Yellow
34m    -        "    "   "  Blue
35m    -        "    "   "  Magenta
36m    -        "    "   "  Cyan
37m    -        "    "   "  White
40m    -     Change Background to Black
41m    -        "       "      "  Red
42m    -        "       "      "  Green
43m    -        "       "      "  Yellow
44m    -        "       "      "  Blue
45m    -        "       "      "  Magenta
46m    -        "       "      "  Cyan
47m    -        "       "      "  White
7m     -     Change to Black text on a White bg
0m     -     Turn off all attributes.
*/ 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
      char string1[100], string2[100], string3[100];
      int choice = 0;
      system("clear");
      printf("\n\33[1;37m MAIN MENU ");
      printf("\n\33[1;32m  1 - Search my encryption Library. \n");
      printf("\n\33[1;32m  2 - dump all to log files \n");
      printf("\n\33[1;32m  3 - Drop to root shell only \n");
      printf("\n\n\33[1;37m Options");
      printf("\n\33[1;32m 4 - Total operating system uptime status.\n");
      printf("\33[1;32m 5 - Show Time 12 & 24 hour format.  \n");
      printf("\33[1;32m 6 - Exit Program");
      printf("\33[1;31m Please enter option 1 to 6:");
      scanf("%d",&choice);


      switch (choice)
        {
      case 1:
      {
             printf("\33[1;30m Executing programs: \n");
             system("encrypt");
             system("encrypt2");
             system("encrypt3");
             system("bitlocker");
             system("2pass_crypt");
             system("2pass_crypt_hex");
             printf("\33[1;37m \n");
            exit(0);
      }
      case 2:
      {
   printf("\33[1;34m file names sergo00.doc and sergo01.doc.....\n");
            system("sudo find / >>sergo00.doc");
            printf("....");
            system(" sudo vdir / >>sergo01.doc");
      	    printf("....Done...\33[1;37m \n");
            exit(0);
      }
      case 3:
      {
           system("sudo su");
           exit(0);
      }
      case 4:
      {    system("statos");
           system("sergo");
           exit(0);
      }
      case 5:
      { system("time2");
        system("sergo");
      }
      case 6:
      {   printf("\33[1;37m \n");
          exit(0);
      }
      default:
      {      printf("\33[1;28m illegal selection \n \33[1;37m \n");
                exit(0);
                }
      }

        printf("\33[1;37m \n");
        return 0;
}
