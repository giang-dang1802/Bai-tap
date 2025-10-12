#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // Open the file in write-only, create if not exists, and append mode
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;       // Request a write (exclusive) lock
    lock.l_whence = SEEK_SET;    // Lock from the beginning of the file
    lock.l_start = 0;            // Start offset
    lock.l_len = 0;              // 0 means lock to EOF (entire file)

    // Try to acquire the lock (blocking)
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        close(fd);
        return 1;
    }

    char buffer[100];
    for (int i = 0; i < 1000; i++) {
        // Format the number into the buffer
        sprintf(buffer, "%d\n", i);
        // Write the buffer to the file
        ssize_t bytes_written = write(fd, buffer, strlen(buffer));
        if (bytes_written < 0) {
          perror("write");
        }
        // Sleep for 1 millisecond to simulate potential conflict
        usleep(1000);
    }

    // Unlock the file after writing
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
    }

    close(fd);
    return 0;
}
