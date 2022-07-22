#include <bits/stdc++.h>
using namespace std;
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
		start = queue.form();
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
int main (){
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
