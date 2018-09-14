#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string cadena;
	bool yaabrio = false;
	while(getline(cin, cadena))
	{
		for(int i = 0 ; i < cadena.length() ; i++)
		{
			if(cadena[i] == '"' && !yaabrio)
			{
				yaabrio = true;
				cadena.replace(i, 1, "``");
			}
			else if(cadena[i] == '"' && yaabrio)
			{
				yaabrio = false;
				cadena.replace(i, 1, "''");
			}
		}
		cout << cadena << "\n";
	}
	return 0;
}