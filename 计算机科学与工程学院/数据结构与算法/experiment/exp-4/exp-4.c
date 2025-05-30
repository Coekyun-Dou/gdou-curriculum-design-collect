﻿// exp7-1.c
#include "betree.h"
#include <stdio.h>

int main() {
    BTNode* b = NULL;
    printf("二叉树的基本运算如下:\n");
    printf("  (1)创建二叉树\n");
    CreateBTree(&b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("  (2)输出二叉树:"); DispBTree(b); printf("\n");
    printf("  (3)H结点:");
    BTNode* p = FindNode(b, 'H');
    if (p != NULL) {
        BTNode* lp = LchildNode(p);
        if (lp != NULL)
            printf("左孩子为%c ", lp->data);
        else
            printf("无左孩子 ");
        BTNode* rp = RchildNode(p);
        if (rp != NULL)
            printf("右孩子为%c", rp->data);
        else
            printf("无右孩子 ");
    }
    printf("\n");
    printf("  (4)二叉树b的高度:%d\n", BTHeight(b));
    printf("  (5)释放二叉树b\n");
    DestroyBTree(b);
    return 0;
}