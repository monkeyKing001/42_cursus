#!/bin/bash
# basic complining and testing

<<<<<<< HEAD
#src=microshell.c
src=myself.c
gcc -Wextra -Werror -Wall ${src} -o microshell
=======
gcc -Wextra -Werror -Wall microshell_full.c -o minishell
>>>>>>> d6bf1afcf169b3454ca22d6a15b097d6feedfe2f

./microshell cd a b c d e
./microshell cd x
./microshell cd ..
./microshell x
./microshell /bin/echo x
./microshell /bin/echo y ; /bin/ls | /usr/bin/wc -l
./microshell /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3 | /bin/sleep 3
