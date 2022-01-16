#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>

unsigned long count = 0;
unsigned long filelen = 0;
unsigned long cfilelen = 0;
unsigned char* compression(const char* s) {
unsigned char *buf;
unsigned long buflen;
unsigned long slen = strlen(s) +1;
buflen = compressBound(slen);
buf = (unsigned char*)malloc(sizeof(unsigned char)*buflen);
compress(buf, &buflen, (const Bytef *)s, slen);
count = buflen;
file_len = filelen + slen;
cfile_len = cfilelen + count;
return buf
}

main () {
FILE *pf;
char *p1 = "this document is distributed in the hope that it will be useful, but without any warranty;"; //without even the implied warranty of merchantability or fittness for a particular purpose;You should have received a copy of the GNU General Public License along with this document;";
/ * If the 3 strings are stored together, it can be decompressed completely. But if stored them seperately, only the first one can be decompressed
*/
char *p2 = "without even the implied warranty of merchantability or fittness for a particular purpose;";
char *p3 = "You should have received a copy of the GNU General Public License along with this document;";
pf = fopen("filess.txt", "wb+");
unsigned char* temp;
temp = compression(p1);
fwrite(temp, count, 1, pf);
free(temp);
printf("%lu\n", count);
temp = compression(p2);
fwrite(temp, count, 1, pf);
free(temp);
printf("%lu\n", count);
temp = compression(p3);
fwrite(temp, count, 1, pf);
free(temp);
printf("%lu\n", count);
printf("%lu\n", file_len); //274
printf("%lu\n", cfile_len); //251
fclose(pf);
return 0;
}
