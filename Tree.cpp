#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		node *right;
		node *left;
		int value = 0;
		node(int v)
		{
			value = v;
			left = NULL;
			right = NULL;
		}
};
class tree
{
	public:
		node *rootnode;
		tree(int value)
		{
			rootnode = new node(value);
		}
		bool search(int value)
{
	node *i = rootnode;
	while(true)
	{
		if( i->value > value && i->left != NULL) 		{i=i->left;}
		else if( i->value < value && i->right != NULL)	{i=i->right;}
		else if(i->value == value)						{return true;}
		else											{return false;}						
	}
}
void add_node(int value)
{
	node *i = rootnode;
	while(true)
	{
		if( i->value > value && i->left != NULL)		{ i = i->left;}
		else if( i->value < value && i->right != NULL)	{ i = i->right;}
		else if( i->value > value && i->left ==NULL)	{ i->left = new node(value); break;}
		else if( i->value < value && i->right ==NULL)	{ i->right = new node(value); break;}
		else											{ break;}
	}
}
void DFS_Pre_order (node *rootnode){
	if( rootnode != NULL)
	{
		cout<<rootnode->value<<",";
		DFS_Pre_order(rootnode->left);
		DFS_Pre_order(rootnode->right);
	}
}
void DFS_In_order (node *rootnode){

	if( rootnode != NULL){
		DFS_In_order(rootnode->left);
		cout<<rootnode->value<<",";
		DFS_In_order(rootnode->right);
	}
}
void DFS_Post_order (node *rootnode){

	if( rootnode != NULL){
		DFS_In_order(rootnode->left);
		DFS_In_order(rootnode->right);
		cout<<rootnode->value<<",";
	}
}
int max_height = 0;
int temp_height = 0;
void height(node *rootnode)
{
	if( rootnode != NULL)
	{
		temp_height++;
		height(rootnode->left);
		if(temp_height > max_height )
		{
			max_height = temp_height;
		}
		height(rootnode->right);
		temp_height --;
	}
}
void BFS_help (node *rootnode,int level)
{
	if(level == 0){	cout<<rootnode->value<<",";}
	else
	{
		if( rootnode->left != NULL){BFS_help(rootnode->left,level-1);}
		if( rootnode->left != NULL){BFS_help(rootnode->right,level-1);}
	}
}
void BFS()
{
	max_height = 0;
	height(rootnode);
	for(int i=0; i<max_height;i++)
	{
		BFS_help(rootnode,i);
		cout<<"|";
	}
}
void height_node(int value)
{
	max_height = -1;
	temp_height = -1;
	node *i = rootnode;
	while(true)
	{
		if( i->value > value && i->left != NULL)
		{
			i = i->left;
		}
		else if( i->value && i->right != NULL)
		{
			i = i->right;
		}
		else if( i->value == value)
		{
			height(i);
			cout<<max_height<<endl;
			return;
		}
		else
		{
			cout<<-1<<endl;
			return;
		}
	}
}
void Depth_node(int value)
{
	int num_Depth = 0;
	node *i = rootnode;
	while(true)
	{
		if(i->value > value && i->left != NULL)
		{
			num_Depth++;
			i = i->left;
		}
		else if(i->value <value && i->right != NULL)
		{
			num_Depth++;
			i = i->right;
		}
		else if(i->value == value)
		{
			cout<<num_Depth<<endl;
			return;
		}
		else
		{
			cout<<"-1"<<endl;
			return;
		}
	}
}
void delete_node(int v)
{
	node *parent = rootnode;
	node *children = rootnode;
	while(true)
	{
		parent = children;
		if(children->value == v)
		{
			if(children->left == NULL && children->right == NULL)
			{
				return;
			}
			else if(children->right != NULL)
			{
				SwitchValueR(children);
			}
			else if(children->left != NULL)
			{
				SwitchValueL(children);
			}
			return;
		}
		else if(children->value>v)
		{
			if(children->left != NULL) { children = children->left; }
			else					   { return;					}
			if(children->value == v)
			{
				if(children->left == NULL && children->right == NULL)
				{
					parent->left - NULL;
				}
				else if(children->left == NULL && children->right != NULL)
				{
					parent->left =children->right;
				}
				else if(children->left != NULL && children->right == NULL)
				{
					parent->left = children->left;
				}
				else if(children->left != NULL && children->right != NULL)
				{
					SwitchValueR(children);
				}
				return;
			}
			else if(children->value<v)
			{
				if(children->right != NULL) { children = children->right; }
				else						{ return;					  }
				if( children->value == v)
				{
					if(children->left == NULL && children->right == NULL)
					{
						parent->right = NULL;
					}
					else if( children->left == NULL &&children->right != NULL)
					{
						parent->right = children->right;
					}
					else if(children->left !=NULL &&children->right == NULL)
					{
						parent->right = children->left;
					}
					else if( children->left != NULL && children->right != NULL)
					{
						SwitchValueR(children);
					}
					return;
				}
			}
		}
	}
}
void SwitchValueR(node *children)
{
	node *Pmin =children->right; node *min = children->right;
	if( min->left == NULL)
	{
		children->value = min->value; children->right = min->right; return;
	}
	while(true)
	{
		min = min->left;
		if(min->left == NULL && min->right == NULL)
		{
			children->value = min->value; Pmin->left = NULL; return;
		}
		if(min->left == NULL && min->right != NULL)
		{
			children->value = min->value; Pmin->left = min->right; return;
		}
		Pmin = min;
	}
}
void SwitchValueL(node *children)
{
	node *Pmin = children->left;
	node *min = children->left;
	if(min->right == NULL)
	{
		children->value = min->value; children->left; return;
	}
	while(true)
	{
		min = min->right;
		if(min->right == NULL && min->left == NULL)
		{
			children->value = min->value; Pmin->right = NULL; return;
		}
		if(min->right == NULL && min->left != NULL)
		{
			children->value = min->value; Pmin->right = min->left; return;
		}
		Pmin = min;
	}
}
void search_array(int num)
{
	int arr[] = {11,8,10,4,8,9,3,2,17,25,26,20,27};
	int size = sizeof(arr) / sizeof(arr[0]);
	int counter = 0;
	for(int i = 0;  i < size ; i++)
	{
		counter++;
		if(arr[i]==num)
		{
			break;
		}
	}
	cout<<counter<<endl;
}
void search_counter(int value)
{
	int counter = 0;
	node *i = rootnode;
	while(true)
	{
		if(i->value>value && i->left != NULL)
		{
			counter++; i = i->left;
		}
		else if(i->value < value && i->right != NULL)
		{
			counter++; i = i->right;
		}
		else if(i->value == value)
		{
			counter++; cout<<counter<<endl;
		}
		else
		{
			counter++; cout<<counter<<endl;
		}
	}
}
};

int main(){
	tree t(10);
	t.add_node(11);
	t.add_node(3);
	t.add_node(6);
	t.add_node(5);
	t.add_node(7);
	t.add_node(17);
	t.add_node(22);
/*	search_array(24);
	search_array(10);
	search_array(8);
	search_array(3);
	search_array(9);
	search_array(50);
	cout<<"-------------------------"<<endl;
	t.search_counter(24);
	t.search_counter(10);
	t.search_counter(8);
	t.search_counter(3);
	t.search_counter(9);
	t.search_counter(50);*/
	t.BFS();cout<<endl;
	t.DFS_In_order(t.rootnode);cout<<endl;
	t.DFS_Post_order(t.rootnode);cout<<endl;
	t.DFS_Pre_order(t.rootnode);cout<<endl;
	
	cout<< t.search(19) <<endl;
	cout<< t.search(199) <<endl;
	
	t.Depth_node(3);
	t.height_node(11);
	
	
/*	t.BFS();cout<<endl;
	t.delete_node(9);
	t.BFS();cout<<endl;
	t.delete_node(7);
	t.BFS();cout<<endl;
	t.delete_node(5);
	t.BFS();cout<<endl;
	t.delete_node(20);
	t.BFS();cout<<endl;
	t.delete_node(10);
	t.BFS();cout<<endl;
	t.delete_node(19);
	t.BFS();cout<<endl;
	t.delete_node(30);
	t.BFS();cout<<endl;
	t.delete_node(4);
	t.BFS();cout<<endl;*/

}
