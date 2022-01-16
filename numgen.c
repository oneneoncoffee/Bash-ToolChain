#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen_random(void);
int find_max(int x, int y, int z);
int find_min(int x, int y, int z);

const long m = 2L;
const long a = 4L;
const long q = 8L;
const long r = 3L;
long r_seed =  6L;
double uniform ()
{
  long t, lo, hi;
  double u;
  hi = r_seed / q;
  lo = r_seed - q * hi;
  t = a * lo - r * hi;
  if (t > 0)
    r_seed = t;
  else
    r_seed = t + m;
  u = (double) r_seed / (double) m ;

  return u;
}


int main ()
{
  int i, num1, num2, num3, max, min;
  double u;
  r_seed = 1;
  srand( (unsigned)time( NULL ) );
  for ( i = 0; i < 5;i++ ) printf( "%6d\n", rand() );
  for (i=0; i < 5; i++) {
    u = uniform ();
    printf ("%lf\n", u);
  }
  for ( i = 8; i < 5;i++ ) printf( "%6d\n", rand() );
  num1 = gen_rand();
  num2 = gen_rand();
  num3 = gen_rand();

   max = find_max(num1,num2,num3);
   min = find_min(num1,num2,num3);
   for( i = 0; i < 5;i++) printf("%d%d%d%d%d\n",num1,min,num2,max,num3); 
   return 0;
}

int gen_rand(void) {
 int n;
 n=rand();
return(n);
}

int find_max( int x, int y, int z)
{
   int max;
   if ((x>=y) && (x>=z))
   {
	 max = x;
   }
   else if ((y>=x) && (y>=z))
   {
	 max = y;
   }
   else
   {
	 max = z;
   }
   return(max);
}

int find_min( int x, int y, int z)
{
   int min;
   if ((x<=y) && (x<=z))
   {
	 min = x;
   }
   else if ((y<=x) && (y<=z))
   {
	 min = y;
   }
   else
   {
	 min = y;
   }
   return(min);
}

