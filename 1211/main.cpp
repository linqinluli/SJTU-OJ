#include<iostream>
using namespace std;
struct node
{
    node*left;
    node*right;
    int ccc;
    node()
    {
        left=NULL;
        right=NULL;
        ccc=0;
    }
};
struct elem
{
    node *p;
    int num;
};
class queue
{
    elem *e;
    int maxsize;
    int front,rear;
public:
    void doublespace()
    {
        elem *tmp=e;
        e=new elem[2*maxsize];
        for(int i=1; i<=maxsize; ++i)
            e[i]=tmp[(front+i)%maxsize];
        front=0;
        rear=maxsize;
        maxsize*=2;
        delete tmp;
    }
    queue(int size=100000)
    {
        e=new elem[size];
        maxsize=size;
        front=rear=0;
    }
    ~queue()
    {
        delete []e;
    }
    bool isempty()
    {
        return front==rear;
    }
    elem dequeue()
    {
        front=(front+1)%maxsize;
        return e[front];
    }
    void enqueue(elem x)
    {
        if((rear+1)%maxsize==front)
            doublespace();
        rear=(rear+1)%maxsize;
        e[rear]=x;
    }
};
void isctree(node *root)
{
    queue que;
    elem cur,child;
    int count=1;
    int last=1;
    cur.p=root;
    cur.num=1;
    que.enqueue(cur);
    while(!que.isempty())
    {
        cur=que.dequeue();
        if(cur.p->left!=NULL)
        {
            ++count;
            child.p=cur.p->left;
            last=child.num=cur.num*2;
            que.enqueue(child);
        }
        if(cur.p->right!=NULL)
        {
            ++count;
            child.p=cur.p->right;
            last=child.num=cur.num*2+1;
            que.enqueue(child);
        }
    }
    if(count==last)
        cout<<'Y';
    else
        cout<<'N';
}
const int N=100000;
node tree[N];
int main()
{
    int n;
    int l,r;
    node *root=NULL;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>l>>r;
        if(l!=0)
            tree[i].left=&tree[l-1];
        if(r!=0)
            tree[i].right=&tree[r-1];
    }
    for(int i=0; i<n; i++)
    {
        if(tree[i].left!=NULL)
            tree[i].left->ccc=1;
        if(tree[i].right!=NULL)
            tree[i].right->ccc=1;
    }
    for(int i=0; i<n; i++)
    {
        if(tree[i].ccc==0)
        {
            root=&tree[i];
            break;
        }
    }
    isctree(root);
    return 0;
}
