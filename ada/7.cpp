#include <iostream>
#include <conio.h>
using namespace std;
class node
{
	public:
	int info;
	node *left;
	node *right;
}*root;
class BST
{
	public:
	void insert(node*,node*);
	void inorder(node*);
	void display(node*,int);
	int maxDepth(node*);
	bool search(node*,int);
};
void BST::insert(node *tree,node *newnode)
{
	if (root==NULL)
	{
		root=new node;
		root->info=newnode->info;
		root->left=NULL;
		root->right=NULL;
		cout<<"\nRoot node is Added!";
		return;
	}
	if (tree->info>newnode->info)
	{
		if (tree->left!=NULL)
		{
			insert(tree->left,newnode);
		}
		else 
		{
		tree->left=newnode;
		(tree->left)->left=NULL;
		(tree->left)->right=NULL;
		cout<<"\nNode Added to Left";
		return;
		}
	}
	else 
	{
		if (tree->right!=NULL)
		{
			insert(tree->right,newnode);
		}
		else 
		{
			tree->right=newnode;
			(tree->right)->left=NULL;
			(tree->right)->right=NULL;
			cout<<"\nNode Added to Right";
			return;
		}
		
	}
}
void BST::inorder(node *ptr)
{
	if (root==NULL)
	{
		cout<<"Tree is Empty!"<<endl;
		return;
	}
	if (ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->info<<" ";
		inorder(ptr->right);
	}
}
void BST::display(node *ptr,int level)
{
	int i;
	if (ptr!=NULL)
	{
		display(ptr->right,level+1);
		cout<<endl;
		if (ptr==root)
			cout<<"Root->:";
		else 
		{
			for (i=0;i<level;i++)
				cout<<" ";
		}
		cout<<ptr->info;
		display(ptr->left,level+1);
	}
}
int BST::maxDepth(node* node)
{
	if (node==NULL)
		return 0;
	else 
	{
		int lDepth=maxDepth(node->left);
		int rDepth=maxDepth(node->right);
		if (lDepth>rDepth)
			return (lDepth+1);
		else 
			return (rDepth+1);
	}
}
bool BST::search(node* ptr,int value)
{
	if (ptr==NULL)
	{
		return false;
	}
	if (ptr->info==value)
	{
		return true;
	}
	else if(value<ptr->info)
	{
		return search(ptr->left,value);
	}
	else 
	{
		return search(ptr->right,value);
	}
}
int main()
{
	int choice,num,h;
	char ch;
	BST bst;
	node *temp;
	while(1)
	{
		cout<<"\n-----MENU------";
		cout<<"\n1.INSERT";
		cout<<"\n2.INORDER";
		cout<<"\n3.DISPLAY";
		cout<<"\n4.HEIGHT";
		cout<<"\n5.SEARCH";
		cout<<"\n6.EXIT";
		cout<<"\nENTER CHOICE:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				temp=new node;
				cout<<"\nEnter the number to be inserted:";
				cin>>temp->info;
				bst.insert(root,temp);
				break;
			case 2:
				cout<<"\nInorder Traversal:"<<endl;
				bst.inorder(root);
				cout<<endl;
				break;
			case 3:
				cout<<"\nDisplay BST:"<<endl;
				bst.display(root,1);
				cout<<endl;
				break;
			case 4:
				h=bst.maxDepth(root);
				cout<<"\nHeight=:"<<h<<endl;
				break;
			case 5:
				cout<<"\nEnter the number to search:";
				cin>>num;
				if (bst.search(root,num))
				{
					cout<<num<<" is present in the tree."<<endl;
				}
				else 
				{
					cout<<num<<" is not present in the tree."<<endl;
				}
				break;
			case 6:
				exit(1);
			default:
				cout<<"\nWrong choice entered"<<endl;
		}
	}
	return 0;
}
				
			

