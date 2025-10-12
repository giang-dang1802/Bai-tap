// lock_first_5.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("testfile.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;      // Write Lock
    lock.l_whence = SEEK_SET;   // Start from the beginning of the file
    lock.l_start = 0;           // Start form byte 0
    lock.l_len = 5;             // Lock 5 byte
    lock.l_pid = getpid();

    printf("Locking first 5 bytes...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Locked. Press Enter to unlock...\n");
    getchar();  // Keep lock util pres Enter

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
    }

    close(fd);
    return 0;
}
