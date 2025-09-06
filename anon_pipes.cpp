//c stuff
#include <cstdlib>
#include <cstdio>
#include <cstring>

//linux stuff
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {

    //make a pipe
    int fds[2];
    pipe(fds);

    //fork
    printf("[MAIN] Before fork\n");
    pid_t p = fork();

    if(p == 0) {
        //child
        printf("[CHILD] After fork: my id is %d, my parent is %d\n", getpid(), getppid());

        //send a message over the pipe
        char msg[16] = "test";
        printf("[CHILD] sending message: \"%s\"\n", msg);
        write(fds[1], msg, 15);

    } else {
        //parent
        printf("[PARENT] After fork: my id is %d, my child is %d\n", getpid(), p);

        //receive a message over the pipe
        char buf[16];
        memset(buf, 0, 16);
        read(fds[0], buf, 15); //leave one byte for null-terminator
        printf("[PARENT] received message: \"%s\"\n", buf);
    }

    return 0;
}

