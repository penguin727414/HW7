#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ENTER 13
#define MAX 80

int main(void) {
    FILE* fptr;
    char str[MAX], ch; // 宣告字符陣列str，用來儲存輸入的字符
    int i = 0;

    if (fopen_s(&fptr, "output.txt", "a") != 0) { // 確認檔案是否正確開啟
        printf("無法開啟檔案！\n");
        return 1;
    }

    printf("請輸入字串，按ENTER鍵結束輸入：\n");
    while ((ch = _getche()) != ENTER && i < MAX - 1) { // 使用 _getche，確保字符陣列不超出範圍
        str[i++] = ch;
    }
    str[i] = '\0'; // 加入字串結束符號

    putc('\n', fptr); // 寫入行結束符
    fwrite(str, sizeof(char), i, fptr); // 寫入字串到檔案
    fclose(fptr);

    printf("\n檔案附加完成！！\n");
    system("pause");
    return 0;
}
