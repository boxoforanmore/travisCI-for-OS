#/bin/bash
echo
echo
echo "Running: gcc -o main main.cc -Wall"  `gcc -o main main.cc -Wall`
echo "Running: gcc -o child child.cc -Wall"  `gcc -o child child.cc -Wall`
echo
echo
./main
