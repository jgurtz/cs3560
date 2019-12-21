#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MsgSize 32

char *pMsg1 = "Parent #1";
char *pMsg2 = "Parent #2";
char *pMsg3 = "Parent #3";
char *cMsg1 = "Child #1";
char *cMsg2 = "Child #2";
char *cMsg3 = "Child #3";

int main() {
    char inbuf[MsgSize];
    int p2c[2], c2p[2];
    int pid, status;

    pipe(p2c); // Parent -> child
    pipe(c2p); // Child -> parent

    pid = fork();
    
    if (pid == 0) {     // The child
        close(p2c[1]);    // unneeded
        close(c2p[0]);    // unneeded

        for ( int j=0; j<3; j++) {
            read(p2c[0], inbuf, MsgSize);

            printf("The child is printing: %s\n", inbuf);
        }
        write(c2p[1], cMsg1, MsgSize);
        write(c2p[1], cMsg2, MsgSize);
        write(c2p[1], cMsg3, MsgSize);
    }

    if ( pid > 0) {     // The parent
        close(p2c[0]);    // unneeded
        close(c2p[1]);    // unneeded

        write(p2c[1], pMsg1, MsgSize);
        write(p2c[1], pMsg2, MsgSize);
        write(p2c[1], pMsg3, MsgSize);

        wait(&status);      // wait for child to die

        for ( int j=0; j<3; j++) {
            read(c2p[0], inbuf, MsgSize);

            printf("The parent is printing: %s\n", inbuf);
        }
    }
    return 0;
}
