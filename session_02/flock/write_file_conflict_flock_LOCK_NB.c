#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/file.h> // Required for flock

int main() {
    // Open the file with write-only, create if not exists, and append mode
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Try to acquire an exclusive lock on the file
    
    if (flock(fd, LOCK_EX | LOCK_NB) < 0) { // do not waiting for key, return error immediately
        perror("flock");
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
        usleep(1000000);
    }

    // Release the lock
    flock(fd, LOCK_UN);
    // Close the file descriptor
    close(fd);

    return 0;
}
