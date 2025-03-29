#include "betree.h"

int main() {
    BTNode* b = NULL;
    CreateBTree(&b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("������b:"); DispBTree(b); printf("\n");

    printf("��α�������: ");
    TravLevel(b);
    printf("\n");

    printf("�����������:\n");
    printf("    �ݹ��㷨: ");
    PreOrder(b);
    printf("\n");
    printf("  �ǵݹ��㷨: ");
    PreOrder1(b);
    printf("\n");

    printf("�����������:\n");
    printf("    �ݹ��㷨: ");
    InOrder(b);
    printf("\n");
    printf("  �ǵݹ��㷨: ");
    InOrder1(b);
    printf("\n");

    printf("�����������:\n");
    printf("    �ݹ��㷨: ");
    PostOrder(b);
    printf("\n");
    printf("  �ǵݹ��㷨: ");
    PostOrder1(b);
    printf("\n");

    DestroyBTree(b);
    return 0;
}