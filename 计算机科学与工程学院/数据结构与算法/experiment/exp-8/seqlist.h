#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>
#define MAXL 100

typedef int KeyType; // ����ؼ�������Ϊint

typedef struct {
    KeyType key; // �ؼ�����
    char data;   // �������������Ϊchar
} RecType;       // ����Ԫ�ص�����

void CreateList(RecType R[], KeyType keys[], int n);
void DispList(RecType R[], int n);
void BinInsertSort(RecType R[], int n);

#endif
