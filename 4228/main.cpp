#include <iostream>
#include<cstring>
#include<string>
using namespace std;

template<class KEY, class OTHER>
struct SET {
	KEY key;
	OTHER other;
};

template<class KEY, class OTHER>
class BST {
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
	node* find(const KEY&x)const {
		return find(x, root);
	}
	node* find(const KEY&x, node*t)const
	{
		if (t == NULL || t->data.key == x)
			return t;
		if (x < t->data.key)
			return find(x, t->left);
		else return find(x, t->right);
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
		if (t == NULL)return;
		if (x < t->data.key)remove(x, t->left);
		else if (t->data.key < x)remove(x, t->right);
		else if (t->left != NULL && t->right != NULL)
		{
			node*tmp = t->right;
			while (tmp->left != NULL)tmp = tmp->left;
			t->data = tmp->data;
			remove(t->data.key, t->right);
		}
		else {
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










struct nodex
{
	nodex*next;
	string name;
	nodex() :next(NULL) {}
	nodex(string tmp) :next(NULL)
	{
		name = tmp;
	}
};


BST<string,nodex*>t;
SET<string, nodex*>*order[1000000];
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	string tmp1, tmp2;
	SET<string, nodex*>*s;
	nodex*nam;
	int count=0, k=0,key;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> tmp1 >> tmp2;
		s = &(t.find(tmp2)->data);
		if (s == NULL)
		{
			s = new SET<string, nodex*>;
			s->key = tmp2;
			s->other = new nodex(tmp1);
			t.insert(*s);
			order[k] = s;
			k++;
		}
		else {
			nodex*p = s->other;
			while (p->next != NULL)
				p = p->next;
			p->next = new nodex(tmp1);
		}
	}




	for (int i = 0; i < k; i++)
	{
		s = order[i];
		nam = s->other;
		while (nam != NULL)
		{
			cout << nam->name<<' ';
			nam = nam->next;
		}
		cout << '\n';

	}
}
