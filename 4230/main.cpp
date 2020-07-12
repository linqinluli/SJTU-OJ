#include <iostream>
#include<cstring>
#include<string>
using namespace std;

template<class KEY, class OTHER>
struct SET
{
    KEY key;
    OTHER other;
};
template<class KEY, class OTHER>
class BST
{
public:
    struct node
    {
        SET<KEY, OTHER>data;
        node*left;
        node*right;
        node(const SET<KEY, OTHER>&da, node*le = NULL, node*ri = NULL) :data(da), left(le), right(ri) {}
    };
    node*root;
public:
    node* find(const KEY&x)const
    {
        return find(x, root);
    }
    node* find(const KEY&x, node*t)const
    {
        if (t == NULL || t->data.key == x)
            return t;
        if (x < t->data.key)
            return find(x, t->left);
        else
            return find(x, t->right);
    }
    void insert(const SET<KEY, OTHER>&x)
    {
        insert(x, root);
    }
    void insert(const SET<KEY, OTHER>&x, node*&t)
    {
        if (t == NULL)
            t = new node(x, NULL, NULL);
        else if (x.key <= t->data.key)
            insert(x, t->left);
        else if (t->data.key < x.key)
            insert(x, t->right);
    }
    void remove(const KEY&x)
    {
        remove(x, root);
    }
    void remove(const KEY&x, node*&t)
    {
        if (t == NULL)
            return;
        if (x < t->data.key)
            remove(x, t->left);
        else if (t->data.key < x)
            remove(x, t->right);
        else if (t->left != NULL && t->right != NULL)
        {
            node*tmp = t->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            t->data = tmp->data;
            remove(t->data.key, t->right);
        }
        else
        {
            node*oldNode = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete oldNode;
        }

    }
    BST()
    {
        root = NULL;
    }
};

BST<string,int>t;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string tmp1,tmp2,maxname="";
    SET<string, int>*s;
    SET<string, int>*m;
    int max=0;
    while(true)
    {
        cin>>tmp1;
        if(tmp1=="cite")
        {
            getline(cin,tmp2);
            if(t.find(tmp2)==NULL)
            {
                t.insert(*m);
                m->other=1;
            }
            else
            {
                s=&(t.find(tmp2)->data);
                s->other++;
                if(max<s->other||(max==s->other&&s->key>maxname))
                {
                    max=s->other;
                    maxname=s->key;
                }
            }
        }
        if(tmp1=="query")
        {
            cout<<max<<' '<<maxname<<'\n';
        }
        if(tmp1=="finish")
            break;
    }
return 0;
}
