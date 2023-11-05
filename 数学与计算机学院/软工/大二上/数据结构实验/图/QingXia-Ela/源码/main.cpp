#include <bits/stdc++.h>
using namespace std;

/**
 * ��������ͼ�ڽӾ���
 *
 * @param edges a vector of pairs representing the edges in the graph
 * @param size the size of the matrix
 *
 * @return a 2D vector representing the matrix graph
 *
 * @throws None
 */
vector<vector<int>> CreateMatGraph(vector<pair<int, int>> edges, int size)
{
  vector<vector<int>> matrix(size, vector<int>(size, 0));

  for (auto p : edges)
    matrix[p.first][p.second] = 1;

  // print matrix
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return matrix;
}

struct ArcNode
{
  int adjvex;
  ArcNode *next_arc = nullptr;
};

/**
 * ͨ���ڽӱ�������ͼ
 *
 * @param edges a vector of pairs representing the edges of the graph
 * @param edge_count the total number of edges in the graph
 *
 * @return a vector of ArcNode pointers representing the adjacency list graph
 *
 * @throws None
 */
vector<ArcNode> CreateAdjGraph()
{
  int edge_count;
  cout << "������ͼ�Ľڵ����:";
  cin >> edge_count;
  vector<ArcNode> res(edge_count);

  while (true)
  {
    string head;
    cout << "��������Ҫ���õĽڵ�:";
    cin >> head;
    cout << endl;

    if (head != ".exit")
    {
      int val = stoi(head);
      ArcNode head_node;
      head_node.adjvex = val;

      ArcNode *cur = &head_node;

      while (true)
      {
        string next_head;
        cout << "������ýڵ���ڽӽڵ�:";
        cin >> next_head;
        if (next_head != ".exit")
        {
          int valNext = stoi(next_head);
          ArcNode *next = new ArcNode();
          next->adjvex = valNext;
          cur->next_arc = next;
          cur = cur->next_arc;
        }
        else
          break;
      }
      res[val] = head_node;
      cout << endl;
    }
    else
      break;
  }

  return res;
}

void PrintAdjGraph(vector<ArcNode> &graph)
{
  cout << "ͼ���ڽӱ�����:" << endl;
  for (int i = 0; i < graph.size(); i++)
  {
    cout << i << ": ";
    ArcNode *cur = &graph[i];
    while (cur != nullptr)
    {
      cout << cur->adjvex << "->";
      cur = cur->next_arc;
    }
    cout << endl;
  }
}

/**
 * ����ͼ���ڽӱ�ʵ�֣�
 */
vector<ArcNode *> UndirectGraph = {
    new ArcNode{0, new ArcNode{1, new ArcNode{3, new ArcNode{4, nullptr}}}},
    new ArcNode{1, new ArcNode{0, new ArcNode{2, new ArcNode{3, nullptr}}}},
    new ArcNode{2, new ArcNode{1, new ArcNode{3, new ArcNode{4, nullptr}}}},
    new ArcNode{3, new ArcNode{0, new ArcNode{1, new ArcNode{2, new ArcNode{4, nullptr}}}}},
    new ArcNode{4, new ArcNode{0, new ArcNode{2, new ArcNode{3, nullptr}}}},
};

/**
 * �ǵݹ������������
 *
 * @param graph �ڽӱ�
 * @param v ��ʼ�ڵ�
 *
 * @throws None
 */
void dfsNonRecursive(vector<ArcNode *> &graph, int v)
{
  vector<int> visited(graph.size(), 0);
  stack<int> s;
  s.push(v);
  visited[v] = 1;

  while (!s.empty())
  {
    int t = s.top();
    s.pop();
    cout << t << " ";
    ArcNode *cur = graph[t];
    while (cur != nullptr)
    {
      if (!visited[cur->adjvex])
      {
        s.push(cur->adjvex);
        visited[cur->adjvex] = 1;
      }
      cur = cur->next_arc;
    }
  }
}

void bfs(vector<ArcNode *> &graph)
{
  queue<int> q;
  vector<int> visited(graph.size(), 0);
  q.push(0);
  visited[0] = 1;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    cout << v << " ";
    ArcNode *cur = graph[v];
    while (cur != nullptr)
    {
      if (!visited[cur->adjvex])
      {
        q.push(cur->adjvex);
        visited[cur->adjvex] = 1;
      }
      cur = cur->next_arc;
    }
  }
}

int main()
{
  vector<ArcNode> Graph;
  while (true)
  {
    string choose;
    int final_choose = 7;
    cout << endl;
    cout << "1. ���ڽӾ���������ͼ" << endl
         << "2. ���ڽӱ�������ͼ" << endl
         << "3. �������ͼ�ڽӱ�" << endl
         << "4. �ǵݹ��������������������ͼ" << endl
         << "5. �������������������ͼ" << endl
         << "6. �˳�" << endl;

    cout << "��ѡ��:";
    cin >> choose;
    try
    {
      final_choose = stoi(choose);
    }
    catch (const std::exception &e)
    {
    }

    switch (final_choose)
    {
    case 1:
      CreateMatGraph(
          {
              {0, 1},
              {0, 3},
              {0, 4},
              {1, 0},
              {1, 2},
              {1, 3},
              {2, 1},
              {2, 3},
              {2, 4},
              {3, 0},
              {3, 1},
              {3, 2},
              {3, 4},
              {4, 0},
              {4, 2},
              {4, 3},
          },
          5);
      cout << "�������" << endl;
      break;
    case 2:
    {
      vector<ArcNode> res = CreateAdjGraph();
      Graph = res;
      break;
    }
    case 3:
      if (&Graph == nullptr)
        cout << "���ȹ���ͼ" << endl;
      else
        PrintAdjGraph(Graph);
      break;
    case 4:
      dfsNonRecursive(UndirectGraph, 0);
      break;
    case 5:
      bfs(UndirectGraph);
      break;
    case 6:
      return 0;
    default:
      cout << "�������" << endl;
    }
  }

  return 0;
}
