#/bin/bash
echo "Installing clang-tidy" `sudo apt-get install clang-tidy`
echo
echo
echo "Running clang-tidy main.c" `clang-tidy main.c`
echo "Running clang-tidy child.c" `clang-tidy child.c`
echo
echo "Running: gcc -o child child.c -Wall"  `gcc -o child child.c -Wall`
echo "Running: gcc -o main main.c -Wall"  `gcc -o main main.c -Wall`
echo
echo
./main
