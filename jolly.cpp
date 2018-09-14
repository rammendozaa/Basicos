#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool esta(int res,vector <int> num)
{
	for(int i = 0; i < num.size();i++)
	{
		if(res == num[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	vector <int> restas;
	int n, resta;
	int aux;
	bool jolly = true;
	vector <int> valores;
	while(cin>>n)
	{
		jolly = true;
		valores.clear();
		restas.clear();
		for(int i = 0; i < n; i++)
		{
			cin >> aux;
			valores.push_back(aux);
		}
		for(int i = 0; i<valores.size()-1;i++)
		{
			resta = abs(valores[i] - valores[i+1]);
			restas.push_back(resta);
		}
		for(int i = 1; i<n; i++)
		{
			bool si = esta(i,restas);
			if(!si)
			{
				jolly = false;
				cout<<"Not jolly"<<'\n';
				break;
			}
		}
		if(jolly == true)
			cout<<"Jolly"<<'\n';
	}
	return 0;
}
