#include <stdio.h>
#include <fcntl.h>      // For open()
#include <unistd.h>     // For read(), write(), lseek(), close()
#include <string.h>     // For strlen()
#include <stdlib.h>     // For exit()

int main() {
    int fd;
    char buffer[100];
    ssize_t bytes_read, bytes_written;

    // 1. Open the file "test.txt" with read/write access.
    // If it doesn't exist, create it with permission 0644 (rw-r--r--).
    fd = open("test.txt", O_RDWR | O_CREAT, 0644); //Read and Write, Create file if file does not exist
    if (fd < 0) {
        perror("open"); // Print error if opening fails
        exit(1);
    }

    // 2. Write a string to the file
    const char *text = "Hello, this is a test.\n";
    bytes_written = write(fd, text, strlen(text));
    if (bytes_written < 0) {
        perror("write"); // Print error if writing fails
        close(fd);
        exit(1);
    }


    // 3. Move the file pointer back to the beginning of the file
    if (lseek(fd, 5, SEEK_SET) < 0) {
        perror("lseek"); // Print error if seeking fails
        close(fd);
        exit(1);
    }

    // 4. Read the content from the file into the buffer
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("read"); // Print error if reading fails
        close(fd);
        exit(1);
    }

    buffer[bytes_read] = '\0'; // Null-terminate the string
    printf("Content read from file:\n%s", buffer);

    // 5. Close the file
    close(fd);

    return 0;
}
