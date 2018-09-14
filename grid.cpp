#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector <int> > suma(vector<vector <int> > matriz)
{
	vector <vector <int> > aux(3,vector <int>(3));
	aux[0][0] = (matriz[0][1] + matriz[1][0])%2;
	aux[0][1] = (matriz[0][0] + matriz[1][1] + matriz[0][2])%2;
	aux[0][2] = (matriz[0][1] + matriz[1][2])%2;
	aux[1][0] = (matriz[0][0] + matriz[1][1] + matriz[2][0])%2;
	aux[1][1] = (matriz[1][0] + matriz[0][1] + matriz[1][2] + matriz[2][1])%2;
	aux[1][2] = (matriz[0][2] + matriz[1][1] + matriz[2][2])%2;
	aux[2][0] = (matriz[1][0] + matriz[2][1])%2;
	aux[2][1] = (matriz[1][1] + matriz[2][0] + matriz[2][2])%2;
	aux[2][2] = (matriz[2][1] + matriz[1][2])%2;
	return aux;
}

int main()
{
	vector <vector <int> > grid(3, vector <int>(3));
	vector <vector <char> > chars(3, vector <char>(3));
	int n, contador, aux;
	char auxc;
	bool fin = false;
	cin>>n;
	while(n--)
	{
		fin = true;
		contador = 0;
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				cin>>auxc;
				chars[i][j] = auxc;
			}
		}
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				grid[i][j] = chars[i][j] - '0';
			}
		}
		
		if(grid[0][0] == 0 && grid[0][1] == 0 && grid[0][2] == 0 && grid[1][0] == 0 && grid[1][1] == 0 && grid[1][2] == 0 && grid[2][0] == 0 && grid[2][1] == 0 && grid[2][2] == 0)
			cout<<"-1"<<'\n';
		else
		{
			while(fin)
			{
				if(grid[0][0] == 0 && grid[0][1] == 0 && grid[0][2] == 0 && grid[1][0] == 0 && grid[1][1] == 0 && grid[1][2] == 0 && grid[2][0] == 0 && grid[2][1] == 0 && grid[2][2] == 0)
				{
					fin = false;
					break;
				}
				else
				{
					grid = suma(grid);
					contador++;
				}
			}	
			cout<<contador-1<<'\n';				
		}
	}
	return 0;
}
