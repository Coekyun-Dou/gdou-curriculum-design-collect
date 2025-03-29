#include "linklist.h"
#include <stdio.h>

int main() {
    LinkNode* h;
    ElemType e;
    printf("������Ļ�����������:\n");
    printf("  (1)��ʼ��������h\n");
    InitList(&h);
    printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
    ElemType elements[] = { 'a', 'b', 'c', 'd', 'e' };
    CreateListR(&h, elements, sizeof(elements) / sizeof(elements[0]));
    printf("  (3)���������h:\n");
    DispList(h);
    printf("  (4)������h����:%d\n", ListLength(h));
    printf("  (5)������hΪ%s\n", (ListEmpty(h) ? "��" : "�ǿ�"));
    if (GetElem(h, 3, &e)) {
        printf("  (6)������h�ĵ�3��Ԫ��:%c\n", e);
    }
    printf("  (7)Ԫ��a��λ��:%d\n", LocateElem(h, 'a'));
    printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(&h, 4, 'f');
    printf("  (9)���������h:\n");
    DispList(h);
    printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
    if (ListDelete(&h, 3, &e)) { 
        printf("  (11)���������h:\n");
        DispList(h);
    }
    printf("  (12)�ͷŵ�����h\n");
    DestroyList(&h);
    return 0;
}