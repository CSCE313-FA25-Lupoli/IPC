//c stuff
#include <cstdlib>
#include <cstdio>
#include <cstring>

//linux stuff
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

    mkfifo("pipe_server2client", 0777);
    mkfifo("pipe_client2server", 0777);

    printf("[SERVER] opening write pipe...\n");
    int fd_write = open("pipe_server2client", O_WRONLY);
    printf("[SERVER] opening read pipe...\n");
    int fd_read = open("pipe_client2server", O_RDONLY);
    printf("[SERVER] opened both pipes\n");

    while(true) {
        //read until we get 0
        int value;
        read(fd_read, &value, sizeof(value));

        if(value == 0) break;

        //respond with the square of the number
        value = value * value;
        write(fd_write, &value, sizeof(value));
    }
    printf("[SERVER] bye!\n");

    return 0;
}

