#include<cstdio>
#include<cstring>
#include<malloc.h>
#include<algorithm>
#include<iostream>
#include<stack>
#include<windows.h>
#define KeyType int
#define ENDFLAG -1
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������
#define SElemType int // ����ջԪ������
#define Status int // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)
#define QElemType int

using namespace std;

typedef int ElemType;
typedef struct BST_Node
{
    ElemType data;
    struct BST_Node *lchild, *rchild;
} BSTNode, *BSTree;

typedef struct BT_Node
{
    BSTree Node;
    bool isFirst;
} BTN, *BTNode;

struct SqStack
{
    BSTree base[STACK_INIT_SIZE]; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    int top; // ջ��ָ��
    int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

typedef struct
{
   BSTree *base; // ��ʼ���Ķ�̬����洢�ռ�
   int front; // ͷָ��,�����в���,ָ�����ͷԪ�أ���ʵ�����±�
   int rear; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ�ã�ͬ�ϣ���ĩβԪ�ص��±�
 } SqQueue;

void CreateBST(BSTree &T);
void InsertBST(BSTree &T, ElemType e);
void PreOrderTraverse_1(BSTree T);
void PreOrderTraverse_2(BSTree T);
void InOrderTraverse_1(BSTree T);
void InOrderTraverse_2(BSTree T);
void PostOrderTraverse_1(BSTree T);
void PostOrderTraverse_2(BSTree T);
Status SearchBST(BSTree T, KeyType key);


Status InitStack(SqStack &S)       
{      
    // ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
    // �벹ȫ����
    S.top = 0;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}


Status Push(SqStack &S, BSTree Node)
{
    // ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
    // �벹ȫ����
	if(S.top == S.stacksize)
        return ERROR;

    S.base[S.top] = Node;
    S.top++;

    return OK;
}


Status Pop(SqStack &S, BSTree &p)   
{
    // ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
    // �벹ȫ����
	if(S.top == S.stacksize)
        return ERROR;

    p = S.base[S.top-1];
    --S.top;

    return OK;
}


Status GetTop(SqStack S,SElemType &e)   
{ 
    // ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    // �벹ȫ����
	if(S.top == S.stacksize)
        return ERROR;
    else
        e = S.base[S.top]->data;

    return OK;
}


Status StackEmpty(SqStack S)
{
    if(S.top == 0)
        return 1;
    
    return 0;
}


// ����
Status InitQueue(SqQueue &Q)   
{
    // ����һ���ն���Q���ö���Ԥ�����СΪMAXQSIZE
    // �벹ȫ����
	Q.base = new BSTree[MAXQSIZE];
    if(!Q.base)
        return ERROR;
    
    Q.front = Q.rear = 0;
    return OK;
}


Status EnQueue(SqQueue &Q, BSTree T)  
{ 
    // ����Ԫ��eΪQ���µĶ�βԪ��
    // �벹ȫ����
    if((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    
    Q.base[Q.rear] = T;
    Q.rear = (Q.rear+1) % MAXQSIZE;

    return OK;
}

Status DeQueue(SqQueue &Q, BSTree p) 
{  
    // �����в���, ��ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������OK; ���򷵻�ERROR
    // �벹ȫ����
	if(Q.rear == Q.front)
        return ERROR;
    
    p = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;

    return OK;
}

Status GetHead(SqQueue Q, BSTree p)
{	
    // �����в��գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
    // �벹ȫ����
	if(Q.rear == Q.front)
        return ERROR;

    p = Q.base[Q.front];
    return OK;
}


int QueueLength(SqQueue Q)  
{
    // ����Q��Ԫ�ظ���
    // �벹ȫ����
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}


// ��������
void InsertBST(BSTree &T, ElemType e)
{
    BSTree S;

    if(!T)
    {
        S = new BST_Node;
        S->data = e;
        S->lchild = NULL;
        S->rchild = NULL;
        T = S;    
    }

    else if(e < T->data)
        InsertBST(T->lchild, e);
    else if(e > T->data)
        InsertBST(T->rchild, e);
    else if(e == T->data)
    {
        MessageBox(NULL, TEXT("��Ԫ���Ѵ��ڣ�����ʧ�ܣ�"), TEXT("����"), MB_OK);
        return ;
    }
}


// ����������
void CreateBST(BSTree &T)
{
    T = NULL;
    ElemType e;
    cin>>e;

    while(e != ENDFLAG)
    {
        InsertBST(T, e);
        cin>>e;
    }
}


// �������
void PreOrderTraverse_1(BSTree T)
{
    if(T)
    {
        cout<<T->data<<' ';
        PreOrderTraverse_1(T->lchild);
        PreOrderTraverse_1(T->rchild);
    }
}


void PreOrderTraverse_2(BSTree T)
{
    BSTree Node, p;
    SqStack S;
    InitStack(S);
    Node = T;
    Push(S, Node);

    while (Node != NULL || !StackEmpty(S))
    {
        while(Node != NULL)
        {
            cout<<Node->data<<' ';
            Push(S, Node);
            Node = Node->lchild;
        }
        Pop(S, p);
        Node = p->rchild;
    }
}


// �������
void InOrderTraverse_1(BSTree T)
{
    if(T)
    {
        InOrderTraverse_1(T->lchild);
        cout<<T->data<<' ';
        InOrderTraverse_1(T->rchild);
    }
}


// �ǵݹ��������
void InOrderTraverse_2(BSTree T)
{
    SqStack S;
    InitStack(S);

    BSTree Node, p;
    Node = T;
    while(Node != NULL || !StackEmpty(S))
    {
        while(Node != NULL)
        {
            Push(S, Node);
            Node = Node->lchild;
        }
        if(!StackEmpty(S))
        {
            Pop(S, p);
            cout<<p->data<<' ';
            Node = p->rchild;
        }
    }
}


// �������
void PostOrderTraverse_1(BSTree T)
{
    if(T)
    {
        PostOrderTraverse_1(T->lchild);
        PostOrderTraverse_1(T->rchild);
        cout<<T->data<<' ';
    }
}


// �ǵݹ�������
void PostOrderTraverse_2(BSTree T)
{
    BSTree p;
    BTNode BT, temp;
    stack<BTNode> S;
    
    p = T;
    
    while(p != NULL || !S.empty())
    {
        while(p != NULL)
        {
            BT = new BTN;
            BT->Node = p;
            BT->isFirst = true;
            S.push(BT);
            p = p->lchild;
        }
        if(!S.empty())
        {
            temp = S.top();
            S.pop();
            if(temp->isFirst == true)
            {
                temp->isFirst == false;
                S.push(temp);
                p = temp->Node->rchild;
            }
            else
            {
                cout<<temp->Node->data<<' ';
                p = NULL;
            }
        }
    }
}


// ��α���
void LevelOrderTraverse(BSTree T)
{
    SqQueue Q;
    BSTree p;
    InitQueue(Q);
    p = new BSTNode;

    if(T != NULL)
        EnQueue(Q, T);  // ���ڵ����

    while(QueueLength(Q) != 0)
    {
        DeQueue(Q, p);
        cout<<p->data<<' ';
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}


// ����
Status SearchBST(BSTree T, KeyType key)
{
    if(!T)
        return 0;
    if(T->data == key)
        return 1;
    
    else if(key < T->data)
        SearchBST(T->lchild, key);
    else
        SearchBST(T->rchild, key);
}


// �������ڵ����������
void Change(BSTree &T)
{
    BSTree temp=NULL;
    if(T)
    {
        temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
        Change(T->lchild);
        Change(T->rchild);
    }
}


// �������
int Depth(BSTree T)
{
    int m, n;
    if(T)
    {
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        return n <= m ? (m+1):(n+1);
    }
    else
        return 0;
}


// ��Ҷ�ӽڵ�
int Leaf(BSTree T)
{
    if(T == NULL)
            return 0;

    if(T->lchild == NULL && T->rchild == NULL)
        return Leaf(T->lchild)+Leaf(T->rchild)+1;
    
    else
        return Leaf(T->lchild)+Leaf(T->rchild);
}


void DeleteBST(BSTree &T, ElemType key)
{
    BSTree p=T, f=NULL;

    // ����Ҫɾ���Ľ������λ��
    while(p)
    {
        if(p->data == key)
            break;

        f = p;
        if(p->data < key)
            p = p->rchild;
        else if(p->data > key)
            p = p->lchild;
    }
    if(!p)
        return ; // �Ҳ����ͷ���

    // ������������������������ǿ��Լ��������ջ����������յ����
    BSTree Parent, Son;
    Parent = p;
    if((p->lchild) && (p->rchild))
    {
        Son = p->lchild;
        while(Son->rchild)
        {
            Parent = Son;
            Son = Son->rchild;
        }
        p->data = Son->data;
        if(Parent != p)
            Parent->rchild = Son->lchild;
        else
            Parent->lchild = Son->lchild;
        
        delete Son;
        return ;
    }
    else if(!p->rchild)
        p = p->lchild;
    else if(!p->lchild)
        p = p->rchild;

    // ��p�����ӵ���˫�׽����ȥ
    if(!f)
        T = p;
    else if(Parent == f->lchild)
        f->lchild = p;
    else
        f->rchild = p;
    
    delete Parent;
}


int main()
{
    int n;
    BSTree T;
    cout<<"������������ĸ��ڵ㣨����"<<ENDFLAG<<"��Ϊ������-1������Ϊ�ڵ�֮һ����";
    CreateBST(T);

    while(1)
    {
        int key, key_1;
        system("cls");
        cout<<"1.����ڵ�"<<endl;
        cout<<"2.����������"<<endl;
        cout<<"3.��α���������"<<endl;
        cout<<"4.���Ҹ����ؼ��֣�int��"<<endl;
        cout<<"5.�������ڵ����������"<<endl;
        cout<<"6.�����������"<<endl;
        cout<<"7.Ҷ�ӽ����"<<endl;
        cout<<"8.ɾ���ڵ�"<<endl;
        cout<<"0.�˳�"<<endl;

        cin>>n;

        if(n == 0)
            break;

        switch(n)
        {
            case 1:
                system("cls");
                cout<<"�������������ݣ�";
                int e;
                cin>>e;
                InsertBST(T, e);
                cout<<"������ɣ��µ���Ϊ�������������"<<endl;
                PreOrderTraverse_1(T);
                cout<<endl;
                system("pause");
                break;
            
            case 2:
                system("cls");
                int n1;
                cout<<"1.����ݹ����"<<endl;
                cout<<"2.����ݹ����"<<endl;
                cout<<"3.����ݹ����"<<endl;
                cout<<"4.����ǵݹ����"<<endl;
                cout<<"5.����ǵݹ����"<<endl;
                cout<<"6.����ǵݹ����"<<endl;
                cin>>n1;
                switch(n1)
                {
                    case 1:
                        PreOrderTraverse_1(T);
                        cout<<endl;
                        system("pause");
                        break;
                    case 2:
                        InOrderTraverse_1(T);
                        cout<<endl;
                        system("pause");
                        break;
                    case 3:
                        PostOrderTraverse_1(T);
                        cout<<endl;
                        system("pause");
                        break;
                    case 4:
                        PreOrderTraverse_2(T);
                        cout<<endl;
                        system("pause");
                        break;
                    case 5:
                        InOrderTraverse_2(T);
                        cout<<endl;
                        system("pause");
                        break;
                    case 6:
                        PostOrderTraverse_2(T);
                        cout<<endl;
                        system("pause");
                        break;
                }
                break;
                
            case 3:
                system("cls");
                LevelOrderTraverse(T);
                cout<<endl;
                system("pause");
                break;

            case 4:
                system("cls");
                cout<<"��������ҵĹؼ��֣�int����";
                cin>>key;
                if(SearchBST(T, key))
                    cout<<"���ҳɹ���"<<endl;
                else
                    cout<<"����ʧ�ܣ�"<<endl;
                system("pause");
                break;
            
            case 5:
                system("cls");
                Change(T);
                break;

            case 6:
                system("cls");
                cout<<"������������ǣ�"<<Depth(T)<<endl;
                system("pause");
                break;

            case 7:
                system("cls");
                cout<<"��������Ҷ�ӽڵ����ǣ�"<<Leaf(T)<<endl;
                system("pause");
                break;
                
            case 8:
                system("cls");
                cout<<"������Ҫɾ���Ľ�㣺";
                cin>>key_1;
                DeleteBST(T, key_1);
                break;

            default:
                MessageBox(0,TEXT("�Ƿ��ַ������������룡"), TEXT("����"), MB_OK);
                break;
        }
    }


    system("pause");
    return 0;
}