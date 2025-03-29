#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define INF 32767
#define MAXV 100
typedef char InfoType;

// ��������
typedef struct {
    int no;
    InfoType info;
} VertexType;

// �ڽӾ�������
typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MatGraph;

// �߽ڵ�����
typedef struct ANode {
    int adjvex;
    struct ANode* nextarc;
    int weight;
} ArcNode;

// �ڽӱ�ͷ�ڵ�����
typedef struct VNode {
    InfoType info;
    int count;
    ArcNode* firstarc;
} VNode;

// �ڽӱ�����
typedef struct {
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;

// ��������
void CreateMat(MatGraph* g, int A[MAXV][MAXV], int n, int e);
void DispMat(MatGraph g);
void CreateAdj(AdjGraph** G, int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph* G);
void DestroyAdj(AdjGraph** G);

#endif