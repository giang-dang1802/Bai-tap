#include <stdio.h>
#include <string.h>
#include "strutils.h"

// Hàm đảo ngược chuỗi
void str_reverse(char *s) {
    int len = strlen(s);
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// Hàm xóa khoảng trắng ở đầu và cuối chuỗi
void str_trim(char *s) {
    int start = 0;
    int end = strlen(s) - 1;

    // Bỏ khoảng trắng ở đầu
    while (s[start] == ' ' || s[start] == '\t') {
        start++;
    }

    // Bỏ khoảng trắng ở cuối
    while (end > start && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')) {
        end--;
    }

    // Cắt chuỗi lại
    s[end + 1] = '\0';

    // Dịch phần còn lại về đầu chuỗi
    int i = 0;
    while (s[start] != '\0') {
        s[i++] = s[start++];
    }
    s[i] = '\0';
}

// Hàm chuyển chuỗi thành số nguyên
int str_to_int(const char *s) {
    int num = 0;
    int i = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] != '\0') {
        printf("Cảnh báo: '%s' không phải số nguyên hợp lệ!\n", s);
    }

    return num;
}
