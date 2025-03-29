// exp7-1.c
#include "betree.h"
#include <stdio.h>

int main() {
    BTNode* b = NULL;
    printf("�������Ļ�����������:\n");
    printf("  (1)����������\n");
    CreateBTree(&b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("  (2)���������:"); DispBTree(b); printf("\n");
    printf("  (3)H���:");
    BTNode* p = FindNode(b, 'H');
    if (p != NULL) {
        BTNode* lp = LchildNode(p);
        if (lp != NULL)
            printf("����Ϊ%c ", lp->data);
        else
            printf("������ ");
        BTNode* rp = RchildNode(p);
        if (rp != NULL)
            printf("�Һ���Ϊ%c", rp->data);
        else
            printf("���Һ��� ");
    }
    printf("\n");
    printf("  (4)������b�ĸ߶�:%d\n", BTHeight(b));
    printf("  (5)�ͷŶ�����b\n");
    DestroyBTree(b);
    return 0;
}