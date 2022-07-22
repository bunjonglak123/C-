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
/*		void insert_graph(int x,int y) 
		{
			node *p, *r;
			p = new node(y);
			r = edges[x];
			while(r->next != NULL ){
				r = r->next;
			}
			r->next = p;
		}*/
		void insert_graph (int x, int y ,int z) //input weight
		{
			node *p,*r;
			p = new node(y,z);
			r = edges[x];
			while(r->next != NULL){
				r = r->next;
			}
			r->next = p;
		}
void Dijkstra(int point)
{
	int ListNode[100][100];
	double DistNode[100];
	int ContNode[100];
	bool Compnode[100];
	int NumCity = n_vertices;
	int DistN[100][100];
	int fix_point = point ;
	for(int i=0 ; i< NumCity ; i++)
	{
		for(int j=0 ;j<NumCity;j++)
		{
			DistN[i][j] = edges[i][j];
			if(i==j || DistN[i][j] == 0)
			{
				DistN[i][j] = 99999;
			}
		}
	}
	for(int i = 0; i<NumCity;i++)
	{
		DistNode[i] = 99999;
	}
	for(int i = 0; i<NumCity;i++)
	{
		ListNode[i][0] = point;
	}
	for(int i = 0; i<NumCity;i++)
	{
		ContNode[i] = 1;
	}
	for(int i = 0; i<NumCity;i++)
	{
		Compnode[i] = false;
	}
	for(int i = 0; i<NumCity;i++)
	{
		for(int j = 0;j<NumCity;j++)
		{
			cout<<DistN[i][j]<<" ";
		}
		cout<<endl;
	}
double Max = 99999;
int select = point;

for(int i = 0; i<NumCity ;i++)
{
	if(99999>DistN[point][i])
	{
		DistNode[i] = DistN[point][i];
		ListNode[i][ContNode[i]] = i;
		ContNode[i] = ContNode[i]+1;
	}
	if(Compnode[i]==false&&Max>DistNode[i])
	{
		Max=DistNode[i];select = i;
	}
}
Compnode[select] = true;
point = select;
cout<<"["<<select<<"]\n";
for(int i = 0; i<NumCity;i++)
{
	for(int j=0;j<ContNode[i];j++)
	{
		cout<<"|"<<ListNode[i][j];
	}
	cout<<"| = "<<DistNode[i]<<"\n";
}
cout<<"-------\n";
while(true)
{
	Max = 99999;
	for(int i=0;i<NumCity;i++)
	{
		if(99999>DistN[point][i]&&i != fix_point)
		{
			double TDistNode = DistNode[point] + DistN[point][i];
			if(DistNode[i]>TDistNode)
			{
				for(int j=0;j<ContNode[point]; j++)
				{
					ListNode[i][j] = ListNode[point][j];
				}
				DistNode[i] = TDistNode;
				ContNode[i] = ContNode[point];
				ListNode[i]ContNode[i] = i;
				ContNode[i] = ContNode[i]+1;
			}
		}
		if(Compnode[i]==false &&Max>DistNode[i])
		{
			Max = DistNode[i];
			select = i;
		}
	}
	Compnode[select] = true ;
	point = select;
	cout<<"["<<select<<"]\n"
	for(int i = 0;i<NumCity;i++)
	{
		for(int j=0;j<ContNode[i];j++)
		{
			cout<<"|"<<ListNode[i][j];
		}
		cout<<"| = "<<DistNode[i]<<"\n";
	}
	cout<<"-------\n";
	bool BreakProgram = true ;
	for(int i = 0;i<NumCity;i++)
	{
		if(Compnode[i] == false && DistNode[i] < 99999)
		{
			BreakProgram = false; break;
		}
	}
	if(BreakProgram)
	{
		break;
	}
}
}
/*int my_path[100][3];
int New_edge[100][100];
int size_my_path;
bool visited_k[1000];
int pointA;
int pointB;
void check_connect(int start)
{
	visited_k[start] = true;
	for (int j=0;j<n_vertices ; j++)
	{
		if(New_edge[start][j] > 0 && visited_k[j] == false )
		{
			if(j==pointB){
				connect = true;
				check_connect(j);
			}
		}
	}
}
void Kruskal()
{
	size_my_path = 0;
	for(int i=0;i<n_vertices ; i++)
	{
		for(int j=0;j<n_vertices;j++)
		{
			if(edges[i][j]>0)
			{
				my_path[size_my_path][0] = edges[i][j];
				my_path[size_my_path][1] = i;
				my_path[size_my_path][2] = j;
				size_my_path++;
			}
		}
	}
	for (int i=0; i< size_my_path;i++)
	{
		for(int j=0;j<size_my_path;j++)
		{
			if(my_path[i][0]<my_path[j][0])
			{
				int T1 = my_path[i][0];
				int T2 = my_path[i][1];
				int T3 = my_path[i][2];
				my_path[i][0] = my_path[j][0];
				my_path[i][1] = my_path[j][1];
				my_path[i][2] = my_path[j][2];
				my_path[j][0] = T1;
				my_path[j][1] = T2;
				my_path[j][2] = T3;
			}
		}
	}
	for(int i=0; i<size_my_path ; i++)
	{
		connect = false;
		for(int i=0; i<n_vertices; i++)
		{
			visited_k[i] = false;
		}
		pointA = my_path[i][1];
		pointB = my_path[i][2];
		check_connect(pointA);
		if(!connect)
		{
			New_edge[ my_path[i][1]][my_path[i][2]] = my_path[i][0];
			New_edge[ my_path[i][2]][my_path[i][1]] = my_path[i][0];
		}
	}
	for(int i = 0; i<n_vertices ; i++)
	{
		for(int j=0; j<n_vertices;j++)
		{
			cout<<New_edge[i][j]<<" ";
			cout<<endl;
		}
	}
}*/
};

int main(){
	graph *g = new graph();
	g->initial_graph(9);
	g->insert_graph(0,1,4);
	g->insert_graph(0,7,8);
	g->insert_graph(1,0,4);
	g->insert_graph(1,2,8);
	g->insert_graph(1,7,11);
	g->insert_graph(2,1,8);
	g->insert_graph(2,3,7);
	g->insert_graph(2,5,4);
	g->insert_graph(2,8,2);
	g->insert_graph(3,2,7);
	g->insert_graph(3,4,9);
	g->insert_graph(3,5,14);
	g->insert_graph(4,3,9);
	g->insert_graph(4,5,10);
	g->insert_graph(5,2,4);
	g->insert_graph(5,3,14);
	g->insert_graph(5,4,10);
	g->insert_graph(5,6,2);
	g->insert_graph(6,5,2);
	g->insert_graph(6,7,1);
	g->insert_graph(6,8,6);
	g->insert_graph(7,0,8);
	g->insert_graph(7,1,11);
	g->insert_graph(7,6,1);
	g->insert_graph(7,8,7);
	g->insert_graph(8,2,2);
	g->insert_graph(8,6,6);
	g->insert_graph(8,7,7);
	g->Dijkstra(0);
//	g->print_graph();
//	g->Kruskal();
	
};
