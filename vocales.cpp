#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string cad;
	char dot = '.';
	vector <char> consonantes;
	cin>>cad;
	for(int i = 0; i<cad.length();i++)
		cad[i] = tolower(cad[i]);
	for(char a:cad)
		if(a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u' && a != 'y')
		{
			consonantes.push_back(dot);
			consonantes.push_back(a);
		}
	for(char a: consonantes)
		cout<<a;
	cout<<'\n';
	return 0;
}
