#include <iostream>
#include <utility>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

string sequenceIO(string original, string final,char car, int veces)
{
	string so = "", auxString = "";
	stack <char> manip;
	int i , j , vecesO;
	vecesO = 0;
	i = 1; 
	j = 0;
	//cout << original << " " << final << " " << car << " " << veces << " ";
	manip.push(original[0]);
	so += "i";
	if(original[0] == car)
		vecesO++;
	while(j < final.length() || i < original.length())
	{
		if(manip.empty())
		{
			if(original[i] == car)
				vecesO++;
			manip.push(original[i]);
			so += "i";
			i++;
		}
		if(manip.top() == final[j])
		{
			if(manip.top() == car && vecesO < veces)
			{
				vecesO++;
				manip.push(original[i]);
				so += "i";
				i++;
			}
			else
			{
				auxString += manip.top();
				manip.pop();
				so += "o";
				j++;
			}
		}
		else if(manip.top() != final[j])// && i < original.length())
		{
			if(original[i] == car)
				vecesO++;
			manip.push(original[i]);
			so += "i";
			i++;
		}
	//cout << "\t" << vecesO << " "; 	
			
	}
	//cout << so << " " << auxString << "\n";
	if(auxString == final && so.length() == 2 * final.length())
		return so;
	else
		return "";
}

int main(void)
{
	string original, auxOriginal, final, auxFinal, auxString, palabra, so;
	char auxChar;
	int contador, i, j, k, l, tamCad;
	bool empezar;
	while(cin >> original >> final)
	{
		set <string> in_n_out;
		empezar = false;
		auxOriginal = original;
		auxFinal = final;
		map <char, int> ori;
		map <char, int> fin;
		map <char, int> orifound;
		map <char, int> finfound;
		map <char, int> pivote;
		stack <char> manip;
		auxString = "";
		contador = 0;
		for(char a : original)
		{
			ori[a] = ori[a] + 1;
			orifound[a] = 1;
		}
		for(char a : final)
		{
			fin[a] = fin[a] + 1;
			finfound[a] = 1;
		}
		//aqui se hace toda la manipulacion
		for(char a : original)
		{
			if(ori[a] != fin[a] || original.length() != final.length())
			{
				cout << "[\n]\n";
				empezar = true;
				break;			
			}
		}
		//para empezar el while desde el inicio
		if(empezar)
			continue;
		else
		{
			tamCad = original.length();
			so = "";
		}
		if(ori.size() == tamCad && fin.size() == tamCad)
		{
			i = 1; 
			j = 0;
			manip.push(original[0]);
			so += "i";
			while(j < final.length())// && i < original.length())
			{
				// este if tiene que ver con la iteracion que sea
				if(manip.empty() && i < original.length())
				{
						manip.push(original[i]);
						so += "i";
						i++;
				}
				if(manip.top() == final[j])
				{
					auxString += manip.top();
					manip.pop();
					so += "o";
					j++;
				}
				else if(manip.top() != final[j])// && i < original.length())
				{
						manip.push(original[i]);
						so += "i";
						i++;
				}
			}
			in_n_out.insert(so);
		}
		else
		{
			for(auto a : original)
			{

				for(i = 1 ; i <= fin[a]; i++)
				{
					cout << fin[a] << i << " ";
					auxString = sequenceIO(original, final, a, i);
					in_n_out.insert(auxString);
				}
			}
		}
		cout << "[\n";
		for(auto a : in_n_out)
		{
			if(a.size() > 0)
			{
				i = 0; 
				while(i < a.length() - 1)
				{
					cout << a[i] << " ";
					i++;
				}
				cout << a[i];
				cout << "\n";
			}
		}
		cout << "]\n";
	}
	return 0;
}	