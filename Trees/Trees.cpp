// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;

};

node* createNode(int data)
{
	node* n1 = new node();
	n1->data = data;
	n1->left = NULL;
	n1->right = NULL;
	
	return n1;
}


void insertNode(node* root,int data)
{
	queue <node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* n_ptr = q.front();
		q.pop();
		if (n_ptr->left == NULL)
		{
			node*new_node = createNode(data);
			n_ptr->left = new_node;
			cout << "Node inserted L\n";
			break;
		}
		else
		{
			q.push(n_ptr->left);
		}
		if (n_ptr->right == NULL)
		{
			node*new_node = createNode(data);
			n_ptr->right = new_node;
			cout << "Node inserted R\n";
			break;
		}
		else
		{
			q.push(n_ptr->right);
		}
	}
	
}

void inorder (node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << " \t";
	inorder(temp->right);
}


int main()
{
	node* root = createNode(5);
	insertNode(root, 10);
	insertNode(root, 210);
	insertNode(root, 450);
	insertNode(root, 300);
	insertNode(root, 15);
	insertNode(root, 21);
	insertNode(root, 48);
	insertNode(root, 301);

	inorder(root);


}

