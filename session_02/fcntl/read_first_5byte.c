// read_first_5.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the file for reading
    int fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Try to acquire a read lock on the first 5 bytes
    struct flock lock;
    lock.l_type = F_RDLCK;      // Read lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 5;

    printf("Trying to acquire read lock on first 5 bytes...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Read the first 5 bytes
    char buffer[6] = {0};
    if (read(fd, buffer, 5) != 5) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Read first 5 bytes: %s\n", buffer);

    // Unlock the region
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}
