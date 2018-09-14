#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	int coordini[2];
	cin>>num;
	//vector <vector<int>> coord(num, vector<int>(2));
	//vector<vector<int> > coord(num, vector<int>(2));
	int coord[num][2];
	int i,j,k;
	while(num != 0)
	{
		//coord(num, vector<int>(2));
		int coord[num][2];
		cin>>coordini[0]>>coordini[1];
		for(i=0;i<num;i++)
		{
				cin>>coord[i][0]>>coord[i][1];
				if(coord[i][0]==coordini[0] || coord[i][1]==coordini[1])
					cout<<"divisa"<<'\n';
				else if(coord[i][0]>coordini[0] && coord[i][1]>coordini[1])
					cout<<"NE"<<'\n';
				else if(coord[i][0]>coordini[0] && coord[i][1]<coordini[1])
					cout<<"SE"<<'\n';
				else if(coord[i][0]<coordini[0] && coord[i][1]<coordini[1])
					cout<<"SO"<<'\n';
				else if(coord[i][0]<coordini[0] && coord[i][1]>coordini[1])
					cout<<"NO"<<'\n';
		}
		cin>>num;
	}
	return 0;
}
