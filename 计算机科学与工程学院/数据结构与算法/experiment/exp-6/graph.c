#include "graph.h"

void CreateMat(MatGraph* g, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    g->n = n; g->e = e;
    for (i = 0; i < g->n; i++)
        for (j = 0; j < g->n; j++)
            g->edges[i][j] = A[i][j];
}

void DispMat(MatGraph g) {
    int i, j;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] != INF)
                printf("%4d", g.edges[i][j]);
            else
                printf("%4s", "��");
        printf("\n");
    }
}

void CreateAdj(AdjGraph** G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode* p, * tail = NULL;
    *G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) {
        (*G)->adjlist[i].info = '\0'; // ��ʼ��������Ϣ
        (*G)->adjlist[i].count = 0;   // ��ʼ�����
        (*G)->adjlist[i].firstarc = NULL; // ��ʼ���ڽ�����ͷָ��
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = NULL; // �½��Ľڵ�ָ��NULL
                if ((*G)->adjlist[i].firstarc == NULL) {
                    (*G)->adjlist[i].firstarc = p; // �������Ϊ�գ��½ڵ㼴Ϊͷ�ڵ�
                }
                else {
                    // �ҵ������β��������½ڵ�
                    tail = (*G)->adjlist[i].firstarc;
                    while (tail->nextarc != NULL) {
                        tail = tail->nextarc;
                    }
                    tail->nextarc = p;
                }
            }
        }
    }
    (*G)->n = n; (*G)->e = e;
}

void DispAdj(AdjGraph* G) {
    ArcNode* p;
    for (int i = 0; i < G->n; i++) {
        printf("%d: ", i);
        int isFirst = 1; // ���ڱ���Ƿ��ǵ�һ���ڽӵ�
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            if (!isFirst) {
                printf("��"); // ������ǵ�һ���ڽӵ㣬��ӡ��ͷ
            }
            printf("%d[%d]", p->adjvex, p->weight);
            isFirst = 0; // ���±�ǣ���ʾ�Ѿ���ӡ��һ���ڽӵ�
            p = p->nextarc;
        }
        if (!isFirst) {
            printf("^\n"); // ������ڽӵ㣬��ӡ��������
        }
        else {
            printf("^\n"); // ���û���ڽӵ㣬Ҳ��ӡ��������
        }
    }
}

void DestroyAdj(AdjGraph** G) {
    ArcNode* pre, * p;
    for (int i = 0; i < (*G)->n; i++) {
        pre = (*G)->adjlist[i].firstarc;
        if (pre != NULL) {
            p = pre->nextarc;
            while (p != NULL) {
                free(pre);
                pre = p; p = p->nextarc;
            }
            free(pre);
        }
    }
    free(*G);
    *G = NULL;
}