#include <bits/stdc++.h>
using namespace std;
class node
{
	public:
		int item;
		node *next;
		node(int i) {
			item = 0; next =NULL;
		}
		node() {
			item = 0; next = NULL;
		}
};
class linkgraph
{
	public :
		int n_vertices;
		int n_edges;
		node *edges[100];
		void print_graph()
		{
			node *r;
			for (int i=0 ; i < n_vertices ; i++)
			{
				r = edges[i];
				cout << i << " : ";
				while( r->next != NULL)
				{
					cout << r->next->item <<" "; r = r->next;
				}
				cout<<endl;
			}
		}
		void initial_graph(int n)
		{
			n_vertices = n;
			n_edges = 0;
			for(int i=0 ; i<n ; i++)
			{edges[i] = new node();
			}
		}
		void insert_graph(int x,int y)
		{
			node *p, *r;
			p = new node(y);
			r = edges[x];
			while(r->next != NULL ){
				r = r->next;
			}
			r->next = p;
		}
	/*	void insert_graph (int x, int y ,int z) //input weight
		{
			node *p,*r;
			p = node(y,z);
			r = edges[x];
			while(r->next != NULL){
				r = r->next;
			}
			r->next = p;
		}*/
void BFS (int start)
{
	vector<int> queue ;
	bool *visited = new bool [1000];
	for(int i=0; i< 1000; i++){
		visited[i]= false ;
	}
	visited[start] = true;
	queue.push_back(start);
	
	while(queue.empty()==false)
	{
		start = queue.front();
		cout << start << " ";
		queue.erase(queue.begin());
		node *r = edges[start];
		while(r->next != NULL)
		{
			if(!visited[r->next->item])
			{
				visited[r->next->item] = true;
				queue.push_back(r->next->item);
			}
			r = r->next;
		}
	}
}
};
/*int main (){ //BFS
	linkgraph *g = new linkgraph();
		g->initial_graph(4);
	g->insert_graph(0,1);
	g->insert_graph(0,2);
	g->insert_graph(1,2);
	g->insert_graph(2,0);
	g->insert_graph(2,3);
	g->insert_graph(3,3);
	g->print_graph();
	g->BFS(0);
};*/
int main (){ //Adjacency List
	linkgraph *g = new linkgraph();
		g->initial_graph(4);
	g->insert_graph(0,1);	g->insert_graph(1,0);
	g->insert_graph(0,2);	g->insert_graph(2,0);
	g->insert_graph(0,3);	g->insert_graph(3,0);
	g->insert_graph(1,3);	g->insert_graph(3,1);
	g->insert_graph(2,3);	g->insert_graph(3,2);
	g->insert_graph(3,3);
	g->print_graph();
};
