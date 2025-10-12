#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buffer[100];
    for (int i = 0; i < 1000; i++) {
        sprintf(buffer, "%d\n", i);
        ssize_t bytes_written = write(fd, buffer, strlen(buffer));
        if (bytes_written < 0) {
          perror("write");
        }
        usleep(1000); // sleep 1ms, easy to conflict
    }

    close(fd);
    return 0;
}
