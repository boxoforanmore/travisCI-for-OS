#/bin/bash
echo
echo
echo "Running: gcc -o child child.c -Wall"  `gcc -o child child.c -Wall`
echo "Running: gcc -o main main.c -Wall"  `gcc -o main main.c -Wall`
echo
echo
./main
