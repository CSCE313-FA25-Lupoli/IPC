//c stuff
#include <cstdlib>
#include <cstdio>
#include <cstring>

//linux stuff
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {

    printf("[CLIENT] opening read pipe...\n");
    int fd_read = open("pipe_server2client", O_RDONLY);
    printf("[CLIENT] opening write pipe...\n");
    int fd_write = open("pipe_client2server", O_WRONLY);
    printf("[CLIENT] opened both pipes\n");

    int limit = 10;
    if(argc > 1) {
        limit = atoi(argv[1]);
    }
    printf("[CLIENT] looping to: %d\n", limit);
    for(int i = 1; i <= limit; i++) {
        printf("[CLIENT] sending value: %d\n", i);
        write(fd_write, &i, sizeof(i));
        int j;
        read(fd_read, &j, sizeof(j));
        printf("[CLIENT] received value: %d\n", j);
    }
    //tell server to stop
    int value = 0;
    write(fd_write, &value, sizeof(value));

    return 0;
}

