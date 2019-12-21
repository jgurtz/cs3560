#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // defines all the signals
#include <unistd.h> // for sleep


void catchInt(int);

int main() {
    signal(SIGINT, catchInt); //SIGINT == ctrl+c == 2; should be at top of main

    printf("Sleep call #1\n");
    sleep(5);
    printf("Sleep call #2\n");
    sleep(2);
    printf("Sleep call #3\n");
    sleep(2);
    printf("ExitingNow\n");

    exit(0);
}

void catchInt(int signo) {
    printf("\nCatchingSignal %d, ☺☻☺☻☺  haha\n", signo);
}
