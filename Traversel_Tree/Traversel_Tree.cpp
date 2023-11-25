#include<iostream>
using namespace std;
#define MAX 8
int size[MAX];
struct bstnode
{
	bstnode* lchild;
	int data;
	bstnode* rchild;
};
bstnode* root = 0;

void insert(int x);
void insert(int x)
{
	bstnode* p, * t;
	int done;
	p = new bstnode;
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	if (root == NULL)
	{
		root = p;
	}
	else
	{
		t = root;
		done = 0;
		while (done == 0)
		{
			if (x < t->data)
			{
				if (t->lchild == NULL)
				{
					t->lchild = p;
					done = 1;
				}
				else
					t = t->lchild;
			}
			else
			{
				if (t->rchild == NULL)
				{
					t->rchild = p;
					done = 1;
				}
				else
					t = t->rchild;
			}
		}
	}
}

void inorder(bstnode* t)
{
	if (t != NULL)
	{
		inorder(t->lchild);
		cout << t->data << endl;
		inorder(t->rchild);
	}
}

void preorder(bstnode* t)
{
	if (t != NULL)
	{
		cout << t->data << endl;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void postorder(bstnode* t)
{
	if (t != NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout << t->data << endl;
	}
}

int main()
{
	int ch, data;
	do
	{
		cout << "1.Insert\n2.Inorder\n3.PreOrder\n4.PostOrder\n5.Exit" << endl;
		cout << "Enter the Choice : ";   cin >> ch;
		switch (ch)
		{
		case 1:cout << "Enter the values to insert : " << endl;
			cin >> data;     insert(data);   break;
		case 2:cout << "The tree in Inorder is  : " << endl;
			inorder(root);    break;
		case 3:cout << "The Tree in Preorder is : " << endl;
			preorder(root);  break;
		case 4:cout << "The Tree in PostOrder is : " << endl;
			postorder(root);   break;
		default:cout << "Exiting" << endl;
		ch = 5;
		}
	} while (ch != 5);
}