#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
int main(void)
{
	long long int cases, totalArboles;
	string arbol, linea;
	cout << fixed;
	cout << setprecision(4);
	cin >> cases;
	cin.ignore();
	cin.ignore();
	while(cases--)
	{
		totalArboles = 0;
		map <string, long long int> arboles;
		//cin >> linea;
		/*cin.ignore();
		cin.ignore();*/
		//getline(cin, linea);
		while(getline(cin, arbol) && arbol.length() > 0)
		{
			arboles[arbol] = arboles[arbol] + 1;
			totalArboles++;
		}
		for(auto a : arboles)
		{
			cout << a.first << " " << ((float)a.second/totalArboles)* 100 << "\n";
		}
		if(cases >= 1)
			cout << "\n";
	}
	return 0;
}