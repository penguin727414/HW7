#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ENTER 13
#define MAX 80

int main(void) {
    FILE* fptr;
    char str[MAX], ch; // �ŧi�r�Ű}�Cstr�A�Ψ��x�s��J���r��
    int i = 0;

    if (fopen_s(&fptr, "output.txt", "a") != 0) { // �T�{�ɮ׬O�_���T�}��
        printf("�L�k�}���ɮסI\n");
        return 1;
    }

    printf("�п�J�r��A��ENTER�䵲����J�G\n");
    while ((ch = _getche()) != ENTER && i < MAX - 1) { // �ϥ� _getche�A�T�O�r�Ű}�C���W�X�d��
        str[i++] = ch;
    }
    str[i] = '\0'; // �[�J�r�굲���Ÿ�

    putc('\n', fptr); // �g�J�浲����
    fwrite(str, sizeof(char), i, fptr); // �g�J�r����ɮ�
    fclose(fptr);

    printf("\n�ɮת��[�����I�I\n");
    system("pause");
    return 0;
}
