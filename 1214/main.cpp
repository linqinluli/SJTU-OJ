#include <iostream>
using namespace std;
class Tree
{
public:
    struct  node
    {
        int left, right,val;
        node() :left(0), right(0) {}
    };
    node**base;
    Tree(int N)
    {
        base = new node*[N + 1];
        for (int i = 1; i <= N; i++)
        {
            base[i] = new node;
        }
    }
    struct queue
    {
        struct qNode
        {
            qNode*next;
            node*data;
            qNode(node*k) :data(k), next(NULL) {}
        };
        qNode*head, *rear;
        queue() :head(NULL), rear(NULL) {}
        node*de_queue()
        {
            node*tmp;
            qNode*k;
            tmp = head->data;
            k = head;
            head = head->next;
            delete k;
            return tmp;
        }
        void en_queue(node*k)
        {
            if (head == NULL)
            {
                head = new qNode(k);
                rear = head;
            }
            else
            {
                rear->next = new qNode(k);
                rear = rear->next;
            }
        }
        void head_en_queue(node*k)
        {
            if (head == NULL)
                en_queue(k);
            else
            {
                qNode*tmp = new qNode(k);
                tmp->next = head;
                head = tmp;
            }
        }
        bool is_empty()
        {
            return head == NULL;
        }
    };
    void pre_order(node*n)
    {
        if (n == NULL)
            return;
        cout << n->val << ' ';
        if (n->left)
            pre_order(base[n->left]);
        if (n->right)
            pre_order(base[n->right]);
    }
    void post_order(node*n)
    {
        if (n == NULL)
            return;
        if (n->left)
            post_order(base[n->left]);
        cout << n->val<<' ';
        if (n->right)
            post_order(base[n->right]);
    }
    void level_order(node*n)
    {
        if (n == NULL)
            return;
        queue q;
        node*tmp;
        q.en_queue(n);
        while (!q.is_empty())
        {
            tmp = q.de_queue();
            cout << tmp->val << ' ';
            if (tmp->left != 0)
                q.en_queue(base[tmp->left]);
            if (tmp->right != 0)
                q.head_en_queue(base[tmp->right]);
        }
    }
};

int main()
{
    int N, a, b,c;
    cin >> N;
    Tree tree(N);
    int i=1;
    while(i<=N)
    {
        cin >> a >> b>>c;
        tree.base[i]->left = a;
        tree.base[i]->right = b;
        tree.base[i]->val = c;
        i++;
    }
    Tree::node*tmp;
    int *root = new int[N + 1];
    for (int i = 0; i <= N; i++)
        root[i] = 0;
    for (int i = 1; i <= N; i++)
    {
        root[tree.base[i]->left] = 1;
        root[tree.base[i]->right] = 1;
    }
    for (int a = 1; a <= N; a++)
    {
        if (root[a] == 0)
        {
            b = a;
            break;
        }
    }
    tree.pre_order(tree.base[b]);
    cout << endl;
    tree.post_order(tree.base[b]);
    cout << endl;
    tree.level_order(tree.base[b]);
    cout << endl;
    return 0;
}
