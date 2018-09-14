#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
	bool encontrado = false;
	long long n, auxN, cuadrado, cuadradoN, iniX, iniY, contador, posible, iz, der, ar,ab, number,N;
	while(cin>>n>>number && n != 0 && number != 0)
	{
		if(n == 1)
			cout<<"Line = 1, column = 1."<<'\n';
		else
		{
			encontrado = false;
			contador = 1;
			posible = 1;
			auxN = n - 2;
			cuadrado = n * n;
			cuadradoN = auxN * auxN;
			iniX = iniY = n - 1;
			N = n;
			while(!encontrado)
			{
				if(number >= cuadradoN && number <= cuadrado)
				{
					encontrado = true;
					break;
				}
				else
				{
					auxN-=2;
					n-=2;
					cuadrado = n * n;
					cuadradoN = auxN * auxN;
					iniX--;
					iniY--;
					contador++;
				} 
			}
			if(number == 1)
				cout<<"Line = "<<(N/2)+1<<", column = "<<(N/2)+1<<"."<<endl;
			else if(number == n * n)
				cout<<"Line = "<<n<<", column = "<<n<<"."<<endl;
			else if(number == ((n - 2) * (n - 2)))
				cout<<"Line = "<<n-1<<", column = "<<n-1<<"."<<endl;
			else
			{
				ar = ab = der = n - 1;
				iz = n - 2;
				//iniX = iniY = n - contador;
				posible = cuadradoN;
				encontrado = false;
				if(posible + 1 == number)
				{
					cout<<"Line = "<<iniY + 1<<", column = "<<iniX<<"."<<endl;
					encontrado = true;
				}
				else
				{
					iniY++;
					posible++;	
				}
				// ar -> iz -> der -> ar
				if(!encontrado)
				{	
					for(int i = 0 ; i < iz ; i++)
					{
						if(posible == number)
						{
							cout<<"Line = "<<iniY<<", column = "<<iniX<<"."<<endl;
							encontrado = true;
							break;
						}
						iniX--;
						posible++;
					}
				}
				if(!encontrado)
				{	
					for(int i = 0 ; i < ab ; i++)
					{
						if(posible == number)
						{
							cout<<"Line = "<<iniY<<", column = "<<iniX<<"."<<endl;
							encontrado = true;
							break;
						}
						iniY--;
						posible++;
					}
				}
				if(!encontrado)
				{	
					for(int i = 0 ; i < der ; i++)
					{
						if(posible == number)
						{
							cout<<"Line = "<<iniY<<", column = "<<iniX<<"."<<endl;
							encontrado = true;
							break;
						}
						iniX++;
						posible++;
					}
				}
				if(!encontrado)
				{	
					for(int i = 0 ; i < ar ; i++)
					{
						if(posible == number)
						{
							cout<<"Line = "<<iniY<<", column = "<<iniX<<"."<<endl;
							encontrado = true;
							break;
						}
						iniY++;
						posible++;
					}
				}
			}
		}
	}
	return 0;
}
/*


SOLO HACCER QUE SE MUEVAN LAS POSCIONES SIN CREAR EL ARREGLO, LUEGO AL FINAL CUANDO YA LLEGUES AL NUMERO QUE QUIERES
LO REGRESAS, NUNCA CREAS EL ARREGLO
*/