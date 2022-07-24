#!/bin/bash 
# Felipe Pegoraro, 22/07/2022

CFLAGS='-Wall -Werror -Wextra'
echo -ne "[${CFLAGS}] 
\tEnables all the warnings about weird constructions\n\n"

echo -ne "[-Wduplicated-branches] [-Wduplicated-cond]
\tWarn when an [if-else]/[if-else-if] has identical branches.\n\n"

echo -ne "[-Wlogical-op]
\tWarn about suspicious uses of logical operators in expressions.\n"

# echo "CFLAGS=${CFLAGS}" >> ~/.bashrc
# echo "alias gcc='gcc \${CFLAGS}'" >> ~/.bashrc
