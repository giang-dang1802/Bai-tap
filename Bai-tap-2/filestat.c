#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat info;
    if (lstat(argv[1], &info) == -1) {
        perror("lstat");
        return 1;
    }

    printf("File Path: %s\n", argv[1]);

    if (S_ISREG(info.st_mode))
        printf("File Type: Regular File\n");
    else if (S_ISDIR(info.st_mode))
        printf("File Type: Directory\n");
    else if (S_ISLNK(info.st_mode))
        printf("File Type: Symbolic Link\n");
    else
        printf("File Type: Other\n");

    printf("Size: %ld bytes\n", info.st_size);

    // Hiển thị thời gian sửa đổi cuối
    printf("Last Modified: %s", ctime(&info.st_mtime));

    return 0;
}
