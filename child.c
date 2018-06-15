#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include <signal.h>
#include <sys/types.h>

#define assertsyscall(x, y) if((x) y){int err = errno; {perror(#x); exit(err);}}

int main(int argc, char *argv[]) {
    pid_t parent = getppid();
    
    assertsyscall(printf("Signals were sent in the following order:\n"), <= 0);
    assertsyscall(printf("1) SIGUSR1\n2) SIGUSR2\n3) SIGHUP\n"), <= 0);
    assertsyscall(printf("4) SIGUSR1\n5) SIGUSR1\n6) SIGUSR1\n\n"), <= 0);

    // Multiple SIGUSR1 signals will likely collapse into just one or two  on runtime
    assert(kill(parent, SIGUSR1) == 0);
    assert(kill(parent, SIGUSR2) == 0);
    assert(kill(parent, SIGHUP) == 0);
    assert(kill(parent, SIGUSR1) == 0);
    assert(kill(parent, SIGUSR1) == 0);
    assert(kill(parent, SIGUSR1) == 0);

}
