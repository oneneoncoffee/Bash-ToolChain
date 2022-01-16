#!/bin/bash
# heading index with div line
printf "\n      "; # indent

for x in {0..15}; do printf "%-3x" $x; done;
printf "\n%46s\n" | sed 's/ /-/g;s/^/      /';

# two lines with dots to represent control chars
c=$(echo "fa" | xxd -p -r | iconv -f 'CP437//' -t 'UTF-8')
printf "%32s" | sed 's/../'"$c"'  /g;s/^/  0   /;s/$/\n\n/'
printf "%32s" | sed 's/../'"$c"'  /g;s/^/  1   /'

# convert dec to codepage 437 in a table
for x in {32..255};
do

  # newline every 16 translated code values
  (( x % 16 == 0 )) && printf "\n\n"

  # left index numbers
  let "n = x % 15"
  (( (x % 16) == 0 )) && printf "%-4x" $n | sed 's/0/f/;s/^/  /'

  # conversion of x integer value to symbol
  printf "%02x" $x | xxd -p -r | iconv -f 'CP437//' -t 'UTF-8' | sed 's/.*/&  /'

  # div line
  (( x == 127 )) && printf "%46s" | sed 's/ /-/g;s/^/      /;i\ '

done
printf "%46s" | sed 's/ /-/g;s/^/\n      /;s/$/\n      /'; # div line
for x in {0..15}; do printf "%-3x" $x; done;
echo
