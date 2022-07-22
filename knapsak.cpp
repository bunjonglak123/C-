int max(int a, int b) { if(a > b){ return a;} else{ return b;}}
int weight[] = {1,3,4,5}; 
int value[] = {1, 4, 5, 7};
int row = 4 ;
int col = 7;
int array[5][8];

int main() {
	for(int i=0; i <= row; i++)
	{
		for(int j=0; j <= col; j++)
		{
			if (i == 0 || j == 0) {array[i][j] = 0; }
			
			else if (weight[i-1] <=j)
		{

			array[i][j]=max( value[i-1]+
							array[i-1][j-weight[i-1]],
							array[i-1][j]);
		}
		
		else { array[i][j] = array[i - 1][i]; }
		
		}
	}
}
