#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
    FILE* fptr;
    char str[MAX];
    int bytes; // 存放 fread() 成功讀取的字元數

    // 修正 fopen_s 的使用方式
    if (fopen_s(&fptr, "output.txt", "r") != 0) {
        printf("無法開啟檔案！\n");
        return 1;
    }

    printf("檔案內容如下：\n");

    // 修正讀取檔案的迴圈
    while ((bytes = fread(str, sizeof(char), MAX - 1, fptr)) > 0) {
        str[bytes] = '\0'; // 加入字串結束符號
        printf("%s", str); // 印出檔案內容
    }

    fclose(fptr); // 關閉檔案
    system("pause");
    return 0;
}
