#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr1 = NULL;
    FILE* fptr2 = NULL;
    char ch;
    errno_t err1, err2;

    // �}�� welcome.txt �HŪ���Ҧ�
    err1 = fopen_s(&fptr1, "welcome.txt", "r");
    // �}�� output.txt �H�g�J�Ҧ�
    err2 = fopen_s(&fptr2, "output.txt", "w");

    if (err1 == 0 && err2 == 0 && fptr1 != NULL && fptr2 != NULL)
    {
        while ((ch = getc(fptr1)) != EOF)
            putc(ch, fptr2);
        fclose(fptr1);
        fclose(fptr2);
        printf("�ɮ��ഫ����!!\n");
    }
    else
    {
        printf("�ɮ׶}�ҥ���!!\n");
        if (err1 != 0)
            printf("�L�k�}�� welcome.txt�A���~�X: %d\n", err1);
        if (err2 != 0)
            printf("�L�k�}�� output.txt�A���~�X: %d\n", err2);
        perror("�Բӿ��~��T");
    }

    system("pause");
    return 0;
}
