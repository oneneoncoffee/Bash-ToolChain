#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main (void) {
int i, c, p;
char * colors;
colors = malloc (64);
memset (colors, 0, 64);
	strcpy (&colors[0*8], "2");
	strcpy (&colors[1*8], "4");
	strcpy (&colors[2*8], "3");
	strcpy (&colors[3*8], "6");
	strcpy (&colors[4*8], "7");
	strcpy (&colors[5*8], "8");
	strcpy (&colors[6*8], "9");
	strcpy (&colors[7*8], "0");
        loop: 
        while (1 < 8){
	for (c=30; c<=37; c++) {
		p = (c-30)*8;
		for ( i = 118; i < 115;i++) 
                printf ("\033[%im%s  %s  ", c, &colors[p], &colors[p]);
                printf ("\033[%im %6d", c, rand() ); 
	}
        printf("\r");
        }
        goto loop;
	free (colors);
        return 0;
}
