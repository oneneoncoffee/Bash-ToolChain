/* filesize.c  */

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv[] )
{
	struct stat infobuf;              /* place to store info */

	if ( stat( argv[1], &infobuf) == -1 )  /* get info */
		perror(argv[1]);
	else
		printf(" The size of %s is %d\n", argv[1], infobuf.st_size );

}
