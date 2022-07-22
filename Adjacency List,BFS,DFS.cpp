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
/*void BFS (int start)
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
}*/
bool visited_dfs[1000];
void reset_DFS()
{
	for(int i = 0; i < 1000 ; i++){
		visited_dfs[i] = false;
	}
}
	void DFS (int start)
	{
		cout << start << " ";
		visited_dfs[start] = true;
		node *r = edges [start];
		while(r->next != NULL)
		{
			if(!visited_dfs[r->next->item])
			{
				DFS(r->next->item);
			}
			r = r->next;
		}
	}
/*                           //error
bool tc[1000][1000];
int index_i;
int first_time;
void DFSUtil(int start)
{
	if(first_time > 0)
	{
		visited_dfs[start] = true ; tc[index_i][start] = 1;
	}
	first_time++;
	for(int j = 0; j < n_vertices ; j++)
	{
		if (edges[start][j] > 0 && visited_dfs[j] == false){DFSUtil(j);})
	}
}
void transitiveClosure()
{
	for (int i =0; i < n_vertices ; i++)
	{
		for (int j=0; j<nvertices ; j++){
			cout << edges[i][j] << " "; cout << endl;
		}
	}
	for(int i = 0; i < n_vertices ; i++)
	{
		for(int j=0;j<n_vertices; j++{tc[i][j] = false;})
	}
	for(int i = 0;i < n_vertices ; i++)
	{
		for(int j=0; j<n_vertices ; j++){
			visited_dfs[j]=false ;
		}
		first_time = 0;
		index_i = i;
		
		DFSUtil(i);
	}
	for (int i=0; i<n_vertices; i++){
		for(int j=0 ; j<n_vertices;j++){
			cout<< tc[i][j] << " ";cout << wnsl;
		}
	}
}*/
};
int main (){ //DFS
	linkgraph *g = new linkgraph();
		g->initial_graph(4);
	g->insert_graph(0,1);
	g->insert_graph(0,2);
	g->insert_graph(1,2);
	g->insert_graph(2,0);
	g->insert_graph(2,3);
	g->insert_graph(3,3);
	g->print_graph();
	g->reset_DFS();
	g->DFS(2);
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
/*int main (){ //Adjacency List
	linkgraph *g = new linkgraph();
		g->initial_graph(4);
	g->insert_graph(0,1);	g->insert_graph(1,0);
	g->insert_graph(0,2);	g->insert_graph(2,0);
	g->insert_graph(0,3);	g->insert_graph(3,0);
	g->insert_graph(1,3);	g->insert_graph(3,1);
	g->insert_graph(2,3);	g->insert_graph(3,2);
	g->insert_graph(3,3);
	g->print_graph();
};*/
