#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
    FILE* fptr;
    char str[MAX];
    int bytes; // �s�� fread() ���\Ū�����r����

    // �ץ� fopen_s ���ϥΤ覡
    if (fopen_s(&fptr, "output.txt", "r") != 0) {
        printf("�L�k�}���ɮסI\n");
        return 1;
    }

    printf("�ɮפ��e�p�U�G\n");

    // �ץ�Ū���ɮת��j��
    while ((bytes = fread(str, sizeof(char), MAX - 1, fptr)) > 0) {
        str[bytes] = '\0'; // �[�J�r�굲���Ÿ�
        printf("%s", str); // �L�X�ɮפ��e
    }

    fclose(fptr); // �����ɮ�
    system("pause");
    return 0;
}
