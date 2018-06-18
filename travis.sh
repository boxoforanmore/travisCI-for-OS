#/bin/bash
echo "Installing clang-tidy" `sudo apt-get install clang-tidy`
echo
echo
echo "Running: gcc -o child child.c -Wall"  `gcc -o child child.c -Wall`
echo "Running: gcc -o main main.c -Wall"  `gcc -o main main.c -Wall`
echo
echo "Running clang-tidy on main.c" `clang-tidy main.c -- -Imy_project/include -DMY_DEFINES ...`
echo "Running clang-tidy on child.c" `clang-tidy child.c -- -Imy_project/include -DMY_DEFINES ...`
echo
echo 
echo "Running valgrind on ./main" `valgrind --leak-check=yes ./main`
echo
echo
./main
