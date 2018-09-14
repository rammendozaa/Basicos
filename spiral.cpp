#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <vector<long long> > llenarMatriz(long long n, long long cuadrado, long long number)
{
	vector <vector<long long> > matriz(n,vector<long long>(n));
	vector <long long> resultados;
	long iniY, iniX,iterador = 0, contador; // contador = 1;
	vector <long> mov(2);
	mov[0] = -1;
	mov[1] = 2;
	iniY = iniX = (n/2);
	long long auxAr, auxAb, auxIz, auxDe;
		contador = 1;
		while(iterador < n/2)
	{
		auxAr = abs(mov[0]);
		auxAb = mov[1];
		auxIz = abs(mov[0]);
		auxDe = mov[1];
		while(auxAr > 0)
		{
			//iniY -= 1;
			matriz[iniY--][iniX] = contador;
			contador++;
			auxAr--;
		}
		while(auxIz > 0)
		{
			//iniX -= 1;
			matriz[iniY][iniX--] = contador;
			contador++;
			auxIz--;
		}
		while(auxAb > 0)
		{
			//iniY += 1;
			matriz[iniY++][iniX] = contador;
			contador++;
			auxAb--;
		}
		while(auxDe > 0)
		{
			//iniX += 1;
			matriz[iniY][iniX++] = contador;
			contador++;
			auxDe--;
		}
		iterador++;
		mov[0] = mov[0] - 2;
		mov[1] = mov[1] + 2;
		}
	for(int i = 0 ; i<n; i++)
	{
		matriz[iniY--][iniX] = contador;
		contador++;
	}
	return matriz;
}
	//first, push back y, then x.
//	return matriz;

int main(void)
{
	long long N,N2,number;
	while(cin>>N>>number && N != 0 && number != 0)
	{
		if(N == 1)
		{
			cout<<"Line = 1, column = 1."<<'\n';
		}
		else
		{
			vector <vector<long long>> cuadrado;//, vector<long>(N));
			N2 = N*N;
			cuadrado = llenarMatriz(N,N2,number);
			//cout<<N-cuadrado[0]<<"\t"<<cuadrado[1]+1<<'\n';
			//0 is the line. 1 is the column
		for(auto a: cuadrado)
			{
				for(auto b: a)
					cout<<b<<"\t";
				cout<<endl;
			}

/*
			for(int i = 0 ; i<N ; i++)
			{
				for(int j = 0 ; j<N ; j++)
				{
					if(cuadrado[i][j] == number)
					{
						cout<<"Line = "<<N - i<<", column = "<<j + 1<<"."<<endl;
					}
				}
			}
			*/
		}
	}
	return 0;
}
/*


SOLO HACCER QUE SE MUEVAN LAS POSCIONES SIN CREAR EL ARREGLO, LUEGO AL FINAL CUANDO YA LLEGUES AL NUMERO QUE QUIERES
LO REGRESAS, NUNCA CREAS EL ARREGLO
*/