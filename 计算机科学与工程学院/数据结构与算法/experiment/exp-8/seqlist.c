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

void BinInsertSort(RecType R[], int n) {
    int i, j, low, high, mid;
    RecType tmp;
    for (i = 1; i < n; i++) {
        if (R[i].key < R[i - 1].key) { // ����ʱ
            printf("  i=%d������%d��������: ", i, R[i].key);
            tmp = R[i]; // ��R[i]���浽tmp��
            low = 0; high = i - 1;
            while (low <= high) { // ��R[low..high]�в��Ҳ����λ��
                mid = (low + high) / 2; // ȡ�м�λ��
                if (tmp.key < R[mid].key)
                    high = mid - 1; // ������������
                else
                    low = mid + 1; // ��������Ұ���
            }
            for (j = i - 1; j >= high + 1; j--) // ���н���Ԫ�غ���
                R[j + 1] = R[j];
            R[high + 1] = tmp; // ����tmp
        }
        DispList(R, n);
    }
}