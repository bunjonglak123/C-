#include <bits/stdc++.h>


using namespace std;


int meet_value = 0;

void binary_search(int num[],int value,int left,int right)
{
    int mid = (right+left)/2;
    if(right<left)
	{
        return;
    }
    cout<<left<<","<<mid<<","<<right<<" ";
    if(num[mid]==value)
	{
        meet_value = 1;
        return;
    }
    if(right == left)
	{
        return;
    }
    if(num[mid]<value)
	{
        binary_search(num,value,mid+1,right);
    }
    else if(num[mid]>value)
	{
        binary_search(num,value,left,mid-1);
    }
}

void bs(int num[],int value,int s_min,int s_max)
{
    meet_value = 0;
    binary_search(num,value,s_min,s_max-1);
    if(meet_value == 1)
	{
    	cout<<"Yes"<<endl;
	}
	else if(meet_value == 0)
	{
    	cout<<"No"<<endl;
	}
}


int main()
{
	string key;
	int x;
	int num[100];
	int k = 0;
	int size = 0;
	int s_min = 0;
	int s_max;
	int sort[100];


	while(1)
	{
		cin>>key;
		int X;
		
		stringstream ss;  
  		ss << key;  
  		ss >> X;
  		
		if(key[size] != 'p' && key[size] !='s' && key[size] !='o')
		{
			num[k] = X;
			k++;
			
		}
		else if(key[size] == 'p')
		{
			for(int i =0 ; i<k ; i++)
			{
				cout<<num[i]<<" ";
			}
			cout<<endl;
		}
		else if(key[size] == 's')
		{
			cin>>x;
			
			for(int i=0; i<k; i++)
			{
				sort[i] = num[i];
			}
			
			for(int i=0; i<k; i++)
			{
        		for (int j=i+1; j<k; j++)
				{
            		if (sort[i] > sort[j])
					{
                		int t = sort[i];
                		sort[i] = sort[j];
               			sort[j] = t;
            		}
        		}
    		}
				
			bs(sort,x,s_min,k);
		}
		else if(key[size] == 'o')
		{
			break;
		}
	}
	
}
