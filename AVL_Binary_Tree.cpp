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
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
#define SElemType int // 定义栈元素类型
#define Status int // Status是函数的类型,其值是函数结果状态代码，如OK等
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)
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
    BSTree base[STACK_INIT_SIZE]; // 在栈构造之前和销毁之后，base的值为NULL
    int top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

typedef struct
{
   BSTree *base; // 初始化的动态分配存储空间
   int front; // 头指针,若队列不空,指向队列头元素，其实就是下标
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置，同上，是末尾元素的下标
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
    // 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    // 请补全代码
    S.top = 0;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}


Status Push(SqStack &S, BSTree Node)
{
    // 在栈S中插入元素e为新的栈顶元素
    // 请补全代码
	if(S.top == S.stacksize)
        return ERROR;

    S.base[S.top] = Node;
    S.top++;

    return OK;
}


Status Pop(SqStack &S, BSTree &p)   
{
    // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    // 请补全代码
	if(S.top == S.stacksize)
        return ERROR;

    p = S.base[S.top-1];
    --S.top;

    return OK;
}


Status GetTop(SqStack S,SElemType &e)   
{ 
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    // 请补全代码
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


// 队列
Status InitQueue(SqQueue &Q)   
{
    // 构造一个空队列Q，该队列预定义大小为MAXQSIZE
    // 请补全代码
	Q.base = new BSTree[MAXQSIZE];
    if(!Q.base)
        return ERROR;
    
    Q.front = Q.rear = 0;
    return OK;
}


Status EnQueue(SqQueue &Q, BSTree T)  
{ 
    // 插入元素e为Q的新的队尾元素
    // 请补全代码
    if((Q.rear + 1) % MAXQSIZE == Q.front)
        return ERROR;
    
    Q.base[Q.rear] = T;
    Q.rear = (Q.rear+1) % MAXQSIZE;

    return OK;
}

Status DeQueue(SqQueue &Q, BSTree p) 
{  
    // 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
    // 请补全代码
	if(Q.rear == Q.front)
        return ERROR;
    
    p = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;

    return OK;
}

Status GetHead(SqQueue Q, BSTree p)
{	
    // 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
    // 请补全代码
	if(Q.rear == Q.front)
        return ERROR;

    p = Q.base[Q.front];
    return OK;
}


int QueueLength(SqQueue Q)  
{
    // 返回Q的元素个数
    // 请补全代码
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}


// 插入数据
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
        MessageBox(NULL, TEXT("该元素已存在，插入失败！"), TEXT("警告"), MB_OK);
        return ;
    }
}


// 创建二叉树
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


// 先序遍历
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


// 中序遍历
void InOrderTraverse_1(BSTree T)
{
    if(T)
    {
        InOrderTraverse_1(T->lchild);
        cout<<T->data<<' ';
        InOrderTraverse_1(T->rchild);
    }
}


// 非递归中序遍历
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


// 后序遍历
void PostOrderTraverse_1(BSTree T)
{
    if(T)
    {
        PostOrderTraverse_1(T->lchild);
        PostOrderTraverse_1(T->rchild);
        cout<<T->data<<' ';
    }
}


// 非递归后序遍历
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


// 层次遍历
void LevelOrderTraverse(BSTree T)
{
    SqQueue Q;
    BSTree p;
    InitQueue(Q);
    p = new BSTNode;

    if(T != NULL)
        EnQueue(Q, T);  // 根节点入队

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


// 查找
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


// 交换各节点的左右子树
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


// 树的深度
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


// 求叶子节点
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

    // 查找要删除的结点所在位置
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
        return ; // 找不到就返回

    // 考虑三种情况，左右子树均非空以及左子树空或者右子树空的情况
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

    // 将p子树接到其双亲结点上去
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
    cout<<"请输入二叉树的各节点（输入"<<ENDFLAG<<"即为结束，-1不会作为节点之一）：";
    CreateBST(T);

    while(1)
    {
        int key, key_1;
        system("cls");
        cout<<"1.插入节点"<<endl;
        cout<<"2.遍历二叉树"<<endl;
        cout<<"3.层次遍历二叉树"<<endl;
        cout<<"4.查找给定关键字（int）"<<endl;
        cout<<"5.交换各节点的左右子树"<<endl;
        cout<<"6.二叉树的深度"<<endl;
        cout<<"7.叶子结点数"<<endl;
        cout<<"8.删除节点"<<endl;
        cout<<"0.退出"<<endl;

        cin>>n;

        if(n == 0)
            break;

        switch(n)
        {
            case 1:
                system("cls");
                cout<<"请输入插入的数据：";
                int e;
                cin>>e;
                InsertBST(T, e);
                cout<<"操作完成，新的树为（先序遍历）："<<endl;
                PreOrderTraverse_1(T);
                cout<<endl;
                system("pause");
                break;
            
            case 2:
                system("cls");
                int n1;
                cout<<"1.先序递归遍历"<<endl;
                cout<<"2.中序递归遍历"<<endl;
                cout<<"3.后序递归遍历"<<endl;
                cout<<"4.先序非递归遍历"<<endl;
                cout<<"5.中序非递归遍历"<<endl;
                cout<<"6.后序非递归遍历"<<endl;
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
                cout<<"请输入查找的关键字（int）：";
                cin>>key;
                if(SearchBST(T, key))
                    cout<<"查找成功！"<<endl;
                else
                    cout<<"查找失败！"<<endl;
                system("pause");
                break;
            
            case 5:
                system("cls");
                Change(T);
                break;

            case 6:
                system("cls");
                cout<<"二叉树的深度是："<<Depth(T)<<endl;
                system("pause");
                break;

            case 7:
                system("cls");
                cout<<"二叉树的叶子节点数是："<<Leaf(T)<<endl;
                system("pause");
                break;
                
            case 8:
                system("cls");
                cout<<"请输入要删除的结点：";
                cin>>key_1;
                DeleteBST(T, key_1);
                break;

            default:
                MessageBox(0,TEXT("非法字符，请重新输入！"), TEXT("警告"), MB_OK);
                break;
        }
    }


    system("pause");
    return 0;
}