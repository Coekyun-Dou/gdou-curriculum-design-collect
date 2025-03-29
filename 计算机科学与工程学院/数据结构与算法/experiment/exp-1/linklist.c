// linklist.c
#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

// ͷ�巨����������
void CreateListF(LinkNode** L, ElemType a[], int n) {
    LinkNode* s;
    *L = (LinkNode*)malloc(sizeof(LinkNode));  // ����ͷ���
    (*L)->next = NULL;
    for (int i = 0; i < n; i++) {
        s = (LinkNode*)malloc(sizeof(LinkNode)); // �����½��s
        s->data = a[i];
        s->next = (*L)->next;
        (*L)->next = s;
    }
}

// β�巨����������
void CreateListR(LinkNode** L, ElemType a[], int n) {
    LinkNode* s, * r;
    *L = (LinkNode*)malloc(sizeof(LinkNode));   // ����ͷ���
    (*L)->next = NULL;
    r = *L;                                     // rʼ��ָ��β���,��ʼʱָ��ͷ���
    for (int i = 0; i < n; i++) {
        s = (LinkNode*)malloc(sizeof(LinkNode)); // �����½��s
        s->data = a[i];
        r->next = s;                             // �����s����r���֮��
        r = s;
    }
    r->next = NULL;                             // β���next����ΪNULL
}

// ��ʼ�����Ա�
void InitList(LinkNode** L) {
    *L = (LinkNode*)malloc(sizeof(LinkNode));   // ����ͷ���
    (*L)->next = NULL;                          // ��������Ϊ�ձ�
}

// �������Ա�
void DestroyList(LinkNode** L) {
    LinkNode* pre, * p;
    p = *L;
    while (p != NULL) {
        pre = p;
        p = p->next;
        free(pre);
    }
    *L = NULL;
}

// �����Ա��Ƿ�Ϊ�ձ�
int ListEmpty(LinkNode* L) {
    return L->next == NULL;
}

// �����Ա�ĳ���
int ListLength(LinkNode* L) {
    int i = 0;
    LinkNode* p = L->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

// ������Ա�
void DispList(LinkNode* L) {
    LinkNode* p = L->next;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// �����Ա��е�i��Ԫ��ֵ
int GetElem(LinkNode* L, int i, ElemType* e) {
    int j = 0;
    LinkNode* p = L;
    while (j < i && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) return 0;
    *e = p->data;
    return 1;
}

// ���ҵ�һ��ֵ��Ϊe��Ԫ�����
int LocateElem(LinkNode* L, ElemType e) {
    int i = 1;
    LinkNode* p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL) return 0;
    return i;
}

// �����i��Ԫ��
int ListInsert(LinkNode** L, int i, ElemType e) {
    int j = 0;
    LinkNode* p = *L, * s;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL || (i != 1 && p->next == NULL)) return 0;
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

// ɾ����i��Ԫ��
int ListDelete(LinkNode** L, int i, ElemType* e) {
    int j = 0;
    LinkNode* p = *L, * q;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL || p->next == NULL) return 0;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}