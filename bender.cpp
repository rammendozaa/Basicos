#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n,r;
	string aux;
	char pos,dir;
	vector <string> rota;
	cin>>n;
	string direccion;
	string posact;// = "+x";
	while(n!=0)
	{
		posact = "+x";
		r = n;	
		rota.clear();
		for(int i=0;i<r-1;i++)
		{
			cin>>aux;
			rota.push_back(aux);
		}
		for(string a: rota)
		{
			if(a == "No")
			{
				posact = posact;
			}
			else if(a == "+y")
			{
				if(posact == "+x")
					posact = "+y";
				else if(posact == "+z")
					posact = "+z";
				else if(posact == "-x")
					posact = "-y";
				else if(posact == "-z")
					posact = "-z";
				else if(posact == "+y")
					posact = "-x";
				else if(posact == "-y")
					posact = "+x";
			}
			else if(a == "-y")
			{
				if(posact == "+x")
					posact = "-y";
				else if(posact == "-x")
					posact = "+y";
				else if(posact == "+y")
					posact = "+x";
				else if(posact == "-y")
					posact = "-x";
				else if(posact == "+z")
					posact = "+z";
				else if(posact == "-z")
					posact = "-z";
			}	
			else if(a == "+z")
			{
				if(posact == "+x")
					posact = "+z";
				else if(posact == "-x")
					posact = "-z";
				else if(posact == "+y")
					posact = "+y";
				else if(posact == "-y")
					posact = "-y";
				else if(posact == "+z")
					posact = "-x";
				else if(posact == "-z")
					posact = "+x";
			}	
			else if(a == "-z")
			{
				if(posact == "+x")
					posact = "-z";
				else if(posact == "-x")
					posact = "+z";
				else if(posact == "+y")
					posact = "+y";
				else if(posact == "-y")
					posact = "-y";
				else if(posact == "+z")
					posact = "+x";
				else if(posact == "-z")
					posact = "-x";
			}
		}
		cout<<posact<<'\n';
		cin.ignore();
		cin>>n;
	}
	return 0;
}
