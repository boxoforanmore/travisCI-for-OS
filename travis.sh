#/bin/bash
echo
echo
echo "Running: gcc -o main main.cpp -Wall"  `gcc -o main main.cpp -Wall`
echo "Running: gcc -o child child.cpp -Wall"  `gcc -o child child.cpp -Wall`
echo
echo
./main
