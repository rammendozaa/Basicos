#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;

int main(void)
{
	long long int req, difC, auxCumplidos, auxReq, cases = 1;
	string auxNombre, auxEntrada, auxReqString;
	double auxPrecio;
	//tuple - string indicates name of product, float indicates price and int indicates number of met requirements
	tuple<string, double, long long int> mejorO;
	while (cin >> req >> difC && (req != 0 || difC != 0))
	{
		if(cases != 1)
		{
			cout<<"\n";
		}
		get<0>(mejorO) = ""; // name
		get<1>(mejorO) = 10000000000000; // price
		get<2>(mejorO) = -100000000000; // met
		//vector <string> require(req);
		cin.ignore();
		// requirements are declared and saved in vector
		for(int i = 0 ; i < req ; i++)
		{
		
			getline(cin, auxEntrada);
		/*
			require[i] = auxEntrada;
		*/
		}
		//number of different requests are processed
		for(int i = 0 ; i < difC ; i++)
		{
			getline(cin, auxNombre);
			cin>>auxPrecio;
			cin>>auxReq;
			cin.ignore();
			//auxCumplidos = 0;
			for(int j = 0 ; j < auxReq ; j++)
			{
				getline(cin, auxReqString);
			/*
				auxCumplidos += count(require.begin(), require.end(), auxReqString);
			*/
			}
			if(get<2>(mejorO) < auxReq || (get<2>(mejorO) == auxReq && get<1>(mejorO) > auxPrecio))
			{
				get<0>(mejorO) = auxNombre;
				get<1>(mejorO) = auxPrecio;
				get<2>(mejorO) = auxReq;
			}
		}
		cout<<"RFP #"<<cases<<"\n"<<get<0>(mejorO)<<"\n";
		cases++;
	}
	return 0;
}