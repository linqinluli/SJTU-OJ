#include <iostream>

using namespace std;
struct node
{
    int data;
    node*left;
    node*right;

    node(const int&data,node*lt=NULL,node*rt=NULL):data(data),left(lt),right(rt) {}
};
class tree
{
public:
    node *root;
    tree()
    {
        root=NULL;
    }
    void makeempty(node *t)
    {
        if(t==NULL)
            return;
        makeempty(t->left);
        makeempty(t->right);
        delete t;
    }
    ~tree()
    {
        makeempty(root);
    }
    node *find(int&x)
    {
        return find(x,root);
    }
    void clear(node *t)
    {
        if (t == NULL)
            return;
        clear(t->left);
        clear(t->right);
        delete t;
    }
    node *find(int &x,node *t)
    {
        if(t==NULL||t->data==x)
            return t;
        if(x<t->data)
            return find(x,t->left);
        else
            return find(x,t->right);
    }
    void insert(const int&x)
    {
        insert(x,root);
    }
    void insert (const int&x,node *&t)
    {
        if(t==NULL)
            t= new node(x,NULL,NULL);
        else if(x==t->data)
            insert (x,t->left);
        else if(x<t->data)
            insert (x,t->left);
        else if(t->data<x)
            insert(x,t->right);
    }
    void remove(const int&x)
    {
        remove(x,root);
    }
    void remove(const int&x,node *&t)
    {
        if(t==NULL)
            return;
        if(x<t->data)
            remove(x,t->left);
        else if(x>t->data)
            remove(x,t->right);
        else if(t->left!=NULL&&t->right!=NULL)
        {
            node *tmp=t->right;
            while(tmp->left!=NULL)
                tmp=tmp->left;
            t->data=tmp->data;
            remove(t->data,t->right);
        }
        else
        {
            node *oldnode=t;
            t=(t->left!=NULL)?t->left:t->right;
            delete oldnode;
        }

    }
    void deleteless(int x)
    {
        deleteless(x,root);
    }
    void deleteless(int x,node *&t)
    {
        if(t==NULL)
            return;
        if(t->data==x)
            t->left=NULL;
        else if(t->data<x)
        {
            node *tmp=t;
            node *left=t->left;
            t=t->right;
            clear(left);
            delete tmp;
            deleteless(x,t);
        }
        else
        {
            deleteless(x,t->left);
        }
    }
    void deletegreat(int x)
    {
        deletegreat(x,root);
    }
    void deletegreat(int x,node *&t)
    {
        if(t==NULL)
            return;
        if(t->data==x)
            t->left=NULL;
        else if(t->data>x)
        {
            node *tmp=t;
            node *right=t->right;
            t=t->left;
            clear(right);
            delete tmp;
            deletegreat(x,t);
        }
        else
        {
            deletegreat(x,t->right);
        }
    }
    void deleteft(int a,int b)
    {
        for(int i=1; i<b-a; i++)
            remove(a+i);
    }
    void findith(int n)
    {
        int *num = new int[n] {0};
        int k = 0;
        search(root, n, num,k);
        if(k==n)
            cout << num[n - 1] << '\n';
        else
            cout << 'N' << '\n';
        delete num;
    }
    void search(node *&t, int n, int *num,int &k)
    {
        if (k > n-1 )
            return;
        if (t == NULL)
            return;
        search(t->left, n, num, k);
        if (k > n-1 )
            return;
        num[k++] = t->data;
        if (k > n-1 )
            return;
        search(t->right, n, num, k);
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    tree atree;
    string a;
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(a=="insert")
        {
            cin>>x;
            atree.insert(x);
        }
        if(a=="delete")
        {
            cin>>x;
            atree.remove(x);
        }
        if(a=="delete_less_than")
        {
            cin>>x;
            atree.deleteless(x);
        }
        if(a=="delete_greater_than")
        {
            cin>>x;
            atree.deletegreat(x);
        }
        if(a=="delete_interval")
        {
            cin>>x>>y;
            atree.deleteft(x,y);
        }
        if(a=="find")
        {
            cin>>x;
            if(atree.find(x)==NULL||x!=atree.find(x)->data)
                cout<<'N'<<'\n';
            else if(x==atree.find(x)->data)
                cout<<'Y'<<'\n';
        }
        if(a=="find_ith")
        {
            cin>>x;
            atree.findith(x);
        }

    }

    return 0;
}

