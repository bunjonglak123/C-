#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *next;
    int value;
    Node(int value)
    {
        this -> value = value;
    }
};

class Link_List
{
    public:
    Node* head;
    int size = 0;
    Link_List(int value)
    {
        head = new Node(value);
        head -> next = NULL;
        size = 1;
    }
    void addNode(int value)
    {
        for(Node *h = head; h!= NULL; h = h->next)
        {
            if(h->next == NULL)
        	{
				h-> next = new Node(value);
	            h-> next-> next = NULL;
	            break;
            }
        }
    size++;
	}

    void InsertNode(int index,int value)
    {
        if(index <= size && index > -1)
        {
            bool complete_insert = 0;
            int my_index = 1;
            for(Node* h = head; h!= NULL;h = h-> next)
            {
                if(index == 0)
                {
                    Node*h = new Node(value);
                    h-> next = head;
                    complete_insert = 1;
                    break;
                }
                else if(my_index == size && index == size)
                {
                    h-> next = new Node(value);
                    h-> next -> next = NULL;
                    complete_insert = 1;
                }
                else if(my_index == index)
                {
                    Node* n = new Node(value);
                    n -> next = h->next;
                    h->next = n;
                    complete_insert = 1;
                    break;
                }
                my_index++;
            }
            if(complete_insert == 1)
            {
                size++;
            }
        }
    }
    
        void InsertNode_after(int index,int value)
    {
        if(index <= size && index > -1)
        {
            bool complete_insert = 0;
            int my_index = 0;
            for(Node* h = head; h!= NULL;h = h-> next)
            {
                
                if(my_index == size && index == size)
                {
                    h-> next = new Node(value);
                    h-> next -> next = NULL;
                    complete_insert = 1;
                }
                else if(my_index == index)
                {
                    Node* n = new Node(value);
                    n -> next = h->next;
                    h->next = n;
                    complete_insert = 1;
                    break;
                }
                my_index++;
            }
            if(complete_insert == 1)
            {
                size++;
            }
        }
    }
   void RemoveNode (int index){
            int my_index = 1 ;
            if (index<=size && index > -1){
            for (Node *h=head; h!=NULL ; h=h->next){
              if(index==0){
                head = head->next ;
                break ;
             } 
             else if (my_index==index){
                 h->next = h->next->next ;
                 break ;
             }
             my_index++;
            }
            }
        }
   
	int search(int value){
            int i = 0 ;
            for (Node *h=head; h!=NULL ; h=h->next){
                if (value==h->value){
                    return i ;
                }
                i++;
            }
            return -1 ;
        }


    void PrintList()
    {
        for(Node* h = head; h!= NULL; h = h -> next)
        {
            cout << h-> value << " ";
        }
    }
};


int main()
{
    /*Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(5);
    Node *d = new Node(7);
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = NULL;
    for(Node *h = a; h != NULL; h = h-> next)
    {
        cout << h -> value << " ";
    }
    */
  /* Link_List *ben10 = new Link_List(10);
   ben10 ->addNode(5);
   ben10 ->addNode(10);
   ben10 ->addNode(17);
   ben10 ->addNode(19);
   ben10 ->addNode(20);
   ben10 ->addNode(112);
   ben10 ->addNode(44);

   
   ben10 ->InsertNode(0,55); ben10 ->PrintList(); cout << endl;
   
	ben10 ->InsertNode(9,77); ben10 ->PrintList();	cout << endl;
   
    ben10 ->InsertNode(5,1010);	ben10 ->PrintList();	cout << endl;*/
    //2
/*    Link_List *l = new Link_List(1);
	l ->addNode(9);
	l ->addNode(5);
	l ->addNode(2);
	
	l->PrintList(); cout<<endl;
	
	int t_index = l->search(5);
		if(t_index != -1){
			l->InsertNode_after(t_index, 3);
		}
		l->PrintList(); cout<<endl;

	t_index =	l->search(3);
		if(t_index != -1){
			l->RemoveNode(t_index);
		}
		l->PrintList(); cout<<endl;*/
		//5
		char character;
		int x;
		int y;
		cin>>character;
	Link_List *l = new Link_List(12);
	l ->addNode(34)	;
	l ->addNode(58)	;
	l ->addNode(102);
	if (character=='I'){
		cin>>x;
		cin>>y;
		if(enable == 0)
		{
			l = new Link_list(x);
			enable = 1;
			l->PrintList(); cout<<endl;
		}
		if(l->search(x)== -1){
			int t_index = l->search(t_index);
			if(t_index == -1){
			l->AddNode(x); 
			l->PrintList(); cout<<endl;
			}
			else{
				l->InsertNode(t_index,x);
				l->PrintList(); cout<<endl; 
			}
		}
	}
	else if (character=='D'){
		cin>>t_index;
		int t_index = l->search(t_index);
		if(t_index != -1 && 1->size>1){
			l->RemoveNode(t_index); 
			l->PrintList(); cout<<endl;
		}
	}
	else if(character=='E')
	{
		
	}

   return 0;
}
