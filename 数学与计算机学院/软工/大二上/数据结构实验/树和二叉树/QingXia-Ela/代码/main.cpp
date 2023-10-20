#include <bits/stdc++.h>
using namespace std;

string str;

template <class T>
struct Node
{
  T data;
  Node *lchild, *rchild;
};

void create(Node<char> *&T)
{
  if (!str.length())
    return;

  auto ch = str[0];
  str = str.substr(1, str.length() - 1);

  if (ch != '#')
  {
    T = new Node<char>();
    T->data = ch;
    create(T->lchild);
    create(T->rchild);
  }
  else
    T = nullptr;
}

template <class T>
class BiTree
{
public:
  Node<T> *root;
  BiTree(string input_str)
  {
    str = input_str;
    Node<T> *n = NULL;

    create(n);
    root = n;
  }; // ���캯��������һ�ö�����
  void preOrder()
  {
    _preOrder(root);
  }; // ǰ
  void inOrder()
  {
    _inOrder(root);
  }; // ��
  void postOrder()
  {
    _postOrder(root);
  };
  void inOrderWithoutRecursion()
  {
    _inOrderWithoutRecursion(root);
  }; // �ǵݹ�
  void layerOrder()
  {
    _layerOrder(root);
  };
  void swap()
  {
    _swap(root);
  };
  void getTreeNodeNum()
  {
    int num = 0;
    _getTreeNodeNum(root, &num);
    cout << "�������Ľ�����Ϊ:" << num << endl;
  };
  void getTreeHeight()
  {
    cout << "�������ĸ߶�Ϊ:" << _getTreeHeight(root) << endl;
  };
  void getLeafCount()
  {
    int num = 0;
    _getLeafCount(root, &num);
    cout << "��������Ҷ�Ӹ���Ϊ:" << num << endl;
  };

private:
  // ǰ
  void _preOrder(Node<T> *n)
  {
    if (n)
    {
      cout << n->data;
      _preOrder(n->lchild);
      _preOrder(n->rchild);
    }
  };
  // ��
  void _inOrder(Node<T> *n)
  {
    if (n)
    {
      _inOrder(n->lchild);
      cout << n->data;
      _inOrder(n->rchild);
    }
  };
  void _postOrder(Node<T> *n)
  {
    if (n)
    {
      _postOrder(n->lchild);
      _postOrder(n->rchild);
      cout << n->data;
    } // ��
  };
  void _preOrderWithoutrecursion(Node<T> *n)
  {
    stack<Node<T> *> s;
    Node<T> *p = n;
    s.push(p);

    while (p)
    {
      p = s.top();
      s.pop();
      // ���ڵ�
      cout << p->data;

      // ��
      if (p->rchild)
      {
        p = p->rchild;
        s.push(p);
      }

      // ���ȳ�ջ
      if (p->lchild)
      {
        p = p->lchild;
        s.push(p);
      }
    }
  }
  void _inOrderWithoutRecursion(Node<T> *n)
  {
    stack<Node<T> *> s;
    Node<T> *p = n;

    while (p || !s.empty())
    {
      // ��������ڵ����
      while (p)
      {
        s.push(p);
        p = p->lchild;
      }

      // ��������ӡ���ڵ�ֵ
      p = s.top();
      cout << p->data;
      s.pop();
      // ָ���ҽڵ㣬�����ҽڵ�Ϊ����ص������������
      p = p->rchild;
    }
  }; // �ǵݹ�
  void _postOrderWithoutrecursion(Node<T> *n)
  {
    stack<Node<T> *> s;
    Node<T> *p = n;

    while (p || !s.empty())
    {
      while (p)
      {
        s.push(p);
        // ��ڵ�ȫ����ջ
        if (p->lchild)
        {
          p = p->lchild;
        }
        else
        {
          p = p->rchild;
        }
      }

      // û����Ҳû���ң�����
      p = s.top();
      s.pop();
      cout << p->data;

      // ��ǰ�ڵ����һ���ڵ�
      auto cur_p = s.top();

      // ջ��Ϊ������һ���ڵ���ڵ�Ϊ��ǰ�ڵ㣬˵����ǰ���֧�Ѿ����꣬������ת�����ҽڵ㲢�ظ�ѭ������
      if (!s.empty() && cur_p->lchild == p)
      {
        p = cur_p->rchild;
      }
    }
  }
  void _layerOrder(Node<T> *n)
  {
    queue<Node<T> *> q;
    if (n)
    {
      q.push(n);
    }
    while (!q.empty())
    {
      Node<T> *p = q.front();
      q.pop();
      cout << p->data;
      if (p->lchild)
      {
        q.push(p->lchild);
      }
      if (p->rchild)
      {
        q.push(p->rchild);
      }
    }
  }; // ���
  int _getTreeHeight(Node<T> *n)
  {
    if (n)
    {
      int leftHeight = _getTreeHeight(n->lchild);
      int rightHeight = _getTreeHeight(n->rchild);
      return max(leftHeight, rightHeight) + 1;
    }
    return 0;
  }; // ��������ĸ߶�
  void _getTreeNodeNum(Node<T> *n, int *num)
  {
    if (n)
    {
      *num = *num + 1;
      _getTreeNodeNum(n->lchild, num);
      _getTreeNodeNum(n->rchild, num);
    }
  }; // ��������Ľ�����
  void _getLeafCount(Node<T> *n, int *count)
  {
    if (n)
    {
      if (!n->lchild && !n->rchild)
      {
        *count = *count + 1;
      }
      _getLeafCount(n->lchild, count);
      _getLeafCount(n->rchild, count);
    }
  }; // �������Ҷ�Ӹ���
  void _swap(Node<T> *n)
  {
    if (n)
    {
      auto temp = n->lchild;
      n->lchild = n->rchild;
      n->rchild = temp;
      _swap(n->lchild);
      _swap(n->rchild);
    }
  }; // �����ڵ�
};

int main()
{
  string input;
  cout << "������Ҫ�����Ķ������ַ����У�";
  // input ABC##DE#G##F##
  cin >> input;
  BiTree<char> *tree = new BiTree<char>(input);
  cout << endl;
  int choose = 0;
  do
  {
    cout << "��ѡ��Ҫ���еĲ�����" << endl;
    cout << "1:ǰ�����" << endl;
    cout << "2:�������" << endl;
    cout << "3:�������" << endl;
    cout << "4:�ǵݹ����" << endl;
    cout << "5:��α���" << endl;
    cout << "6:����Ҷ�Ӹ���" << endl;
    cout << "7:���������" << endl;
    cout << "8:����������߶�" << endl;
    cout << "9:����������" << endl;
    cout << "0:�˳�" << endl;

    cin >> choose;

    switch (choose)
    {
    case 1:
      tree->preOrder();
      cout << endl;
      break;
    case 2:
      tree->inOrder();
      cout << endl;
      break;
    case 3:
      tree->postOrder();
      cout << endl;
      break;
    case 4:
      tree->inOrderWithoutRecursion();
      cout << endl;
      break;
    case 5:
      tree->layerOrder();
      cout << endl;
      break;
    case 6:
      tree->getLeafCount();
      cout << endl;
      break;
    case 7:
      tree->getTreeNodeNum();
      cout << endl;
      break;
    case 8:
      tree->getTreeHeight();
      cout << endl;
      break;
    case 9:
      tree->swap();
      cout << endl;
      break;
    }
  } while (choose != 0);

  return 0;
}
