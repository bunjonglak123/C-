#include <bits/stdc++.h>
using namespace std;
class graph
{
	public :
		int edges[1000][1000];
		int n_vertices;
		int n_edges;
		void print_graph()
		{
			for (int i=0; i < n_vertices ; i++)
			{
				cout << i <<" : ";
				for(int j=0 ; j<=n_vertices ; j++){
					if (edges[i][j]>0)
					{
						cout << j <<" ";
					}
				}
			}
		}
		void initial_graph(int n)
		{
			n_vertices = n;
			n_edges = 0;
			for (int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					edges[i][j] = 0;
				}
			}
		}
		void insert_graph(int x,int y) //Undirected Graph
		{
			edges[x][y] = 1;
			edges[y][x] = 1;
			n_edges++;
		}
/*		void insert_graph(int x,int y){ //Directed Graph
			edges[x][y]=1;
			n_edges++;
		}*/
/*		void insert_graph(int x,int y,int v) //Undirected +weight 
		{
			edges[x][y] = v;
			edges[y][x] = v;
			n_edges++;
		}*/
/*		void insert_graph(int x,int y,int v) //Directed Graph +weight
		{
			edges[x][y] v;
			n_edges++;
		}*/

int reach[1000][1000];
void Warshall()
{
	for(int i = 0; i < n_vertices;i++)
	{
		for(int j=0; j<n_vertices; j++)
		{
			reach[i][j] = edges [i][j];
		}
	}
	for(int k = 0; k<n_vertices; k++)
	{
		for(int ii=0; ii <n_vertices;ii++)
		{
			for(int jj=0; jj<n_vertices;jj++)
			{
				cout<<(reach[k][jj]&&reach[ii][k])<<" ";
			}
			cout<<endl;
		}
		for(int i = 0; i<n_vertices;i++) // X
		{
			for(int j=0; j<n_vertices;j++) // Y
			{
				reach[i][j] = reach[i][j] || (reach[i][k]&&reach[k][j]);
			}
		}
	}
	for(int ii= 0; ii<n_vertices;ii++)
	{
		for(int jj=0; jj<n_vertices;jj++)
		{
			cout<<reach[ii][jj]<<" ";
		}
		cout<<endl;
	}
}
};
int main(){ // Warshall
	graph *g = new graph();
	g->initial_graph(4);
	g->insert_graph(0,1);
	g->insert_graph(0,2);
	g->insert_graph(1,2);
	g->insert_graph(2,0);
	g->insert_graph(2,3);
	g->print_graph();
	g->Warshall();
};
/*int main(){ //Adjacency Matrix
		graph *g = new graph();
	g->initial_graph(4);
	g->insert_graph(0,1);
	g->insert_graph(0,2);
	g->insert_graph(0,3);
	g->insert_graph(1,3);
	g->insert_graph(2,3);
	g->insert_graph(3,3);
	g->print_graph();
}*/
