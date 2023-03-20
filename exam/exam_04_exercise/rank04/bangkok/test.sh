#!/bin/bash
# basic complining and testing

#src=microshell.c
src=myself.c
gcc -Wextra -Werror -Wall ${src} -o microshell

./microshell cd a b c d e
./microshell cd x
./microshell cd ..
./microshell x
./microshell /bin/echo x
./microshell /bin/echo y ; /bin/ls | /usr/bin/wc -l
./microshell /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3
