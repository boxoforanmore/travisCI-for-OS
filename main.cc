#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>

#define assertsyscall(x, y) if((x) y){int err = errno; {perror(#x); exit(err);}}

void handler(int sigNum) {
    if(sigNum == SIGUSR1){
        assertsyscall(printf("Received signal SIGUSR1\n"), <= 0); 
        fflush(stdout);
    }   

    else if(sigNum == SIGUSR2) {
        assertsyscall(printf("Received signal SIGUSR2\n"), <= 0); 
        fflush(stdout);
    }   

    else if(sigNum == SIGHUP) {
        assertsyscall(printf("Received signal SIGHUP\n"), <= 0); 
        fflush(stdout);
    } 
    else {
        assertsyscall(printf("Unexpected signal received\n"), <= 0);
    }  
    //assertsyscall(printf("Sending a signal"), <= 0); 
    //fflush(stdout);
} 


int main() {
    pid_t myPID = getpid();

    struct sigaction action1;
    struct sigaction action2;
    struct sigaction action3;

    action1.sa_handler = handler;
    action2.sa_handler = handler;
    action3.sa_handler = handler;

    assertsyscall(sigemptyset(&action1.sa_mask), != 0); 
    assertsyscall(sigemptyset(&action2.sa_mask), != 0); 
    assertsyscall(sigemptyset(&action3.sa_mask), != 0);

    action1.sa_flags = SA_RESTART;
    action2.sa_flags = SA_RESTART;
    action3.sa_flags = SA_RESTART;

    assert(sigaction(SIGUSR1, &action1, NULL) == 0); 
    assert(sigaction(SIGUSR2, &action2, NULL) == 0); 
    assert(sigaction(SIGHUP, &action3, NULL) == 0);


    pid_t childPID = fork();

//add handler to child and have three sig calls from child
//add pause in parent on else below
//structs should also be in action

    if (childPID < 0) {
        perror("Fork failed");
    }
    else if (childPID ==  0) { 
        // You are the "Luke"
        assertsyscall(execl("./child", "child", NULL), < 0);
        _exit(EXIT_FAILURE);
    }
    else {
        // You are the "Vader" (Familias)

        assertsyscall(printf("Parent PID: %d\n", myPID), <= 0);
        assertsyscall(printf("Child PID: %d\n\n", childPID), <= 0);
        fflush(stdout);

        int status;
	assertsyscall(wait(&status), < 0);
        //assertsyscall(wait(&action1), != 0);
        //assert(sigsuspend(action1) == -1);
        //assertsyscall(wait(action2), != 0);
        //sleep(1);
        //assert(sigaction(SIGUSR2, &action2, NULL) == 0);
        //assertsyscall(sigsuspend(action2), == -1);
        //assertsyscall(wait(action3), != 0);
        //sleep(1);
        //assert(sigaction(SIGHUP, &action3, NULL) == 0);
        //assertsyscall(sigsuspend(action3), == -1);
        //assertsyscall(wait(action1), != 0);
        //sleep(1);
        //assert(sigaction(SIGUSR1, &action1, NULL) == 0);
        //assertsyscall(sigsuspend(action1), == -1);
        //assertsyscall(pause(), == -1);
        //assertsyscall(pause(), == -1);
        //assertsyscall(pause(), == -1);
        //assertsyscall(pause(), == -1);


        if(WIFEXITED(status)){
            assertsyscall(printf("Process %d exited with status: %d\n", childPID, WEXITSTATUS(status)), <= 0);						
        }
    }
}
