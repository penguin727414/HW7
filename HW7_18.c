#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
    FILE* in = NULL, * out = NULL;
    int cnt;
    char str[100];

    // �ץ� fopen_s ���Ϊk
    if (fopen_s(&in, "welcome.txt", "r") != 0) {
        printf("�L�k�}�� welcome.txt�I\n");
        return 1;
    }

    if (fopen_s(&out, "output.txt", "w") != 0) {
        printf("�L�k�}�� output.txt�I\n");
        fclose(in); // �p�G��J�ɮפw�g���}�A��������
        return 1;
    }

    // Ū���ɮרüg�J
    while (fscanf_s(in, "%s", str, (unsigned)_countof(str)) != EOF) {
        fprintf(out, "%s\n", str);
    }

    fclose(in); // �����ɮ�
    fclose(out); // �����ɮ�
    system("pause");
    return 0;
}
