#define  _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"

void CreateList(RecType R[], KeyType keys[], int n) {
    for (int i = 0; i < n; i++) {
        R[i].key = keys[i];
        R[i].data = ' '; // ��ʼ������������
    }
}

void DispList(RecType R[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", R[i].key);
    }
    printf("\n");
}

void InsertSort(RecType R[], int n) {
    int i, j;
    RecType tmp;
    for (i = 1; i < n; i++) {
        printf("  i=%d������%d��������: ", i, R[i].key);
        if (R[i].key < R[i - 1].key) { // ����ʱ
            tmp = R[i];
            j = i - 1;
            do { // ��R[i]�Ĳ���λ��
                R[j + 1] = R[j]; // ���ؼ��ִ���R[i].key�ļ�¼����
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            R[j + 1] = tmp; // ��j+1������R[i]
        }
        DispList(R, n);
    }
}