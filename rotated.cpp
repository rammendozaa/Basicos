#include <iostream>
#include <vector>
using namespace std;

vector <vector <char> > rotar(vector <vector <char> > matriz, int tam)
{
	vector <vector <char> > rotada(tam,vector<char> (tam));
	int i,j,k;
	int x,y;
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	x = tam - 1;
	for(i = 0; i < tam; i++)
	{
		x = tam - 1;
		for(j = 0; j < tam; j++)
		{
			rotada[y][x] = matriz[j][i];
			x--;			
		}
		y++;
	
	}
	return rotada;
}



int main()
{
	int g, p,i,j,x,y;
	char aux;
	int cero,nov, och, dos;
	int aux1, aux2,operaciones;
	bool flag;
	cin>>g>>p;
	while(g != 0)
	{
		operaciones = 0;
		flag = true;
		aux1 = 0;
		aux2 = 0;
		cero = 0;
		nov = 0;
		och = 0;
		dos = 0;
		vector <vector <char> > grande(g);
		vector <vector <char> > peque(p);
		for(int i = 0;i<g;i++)
		{
			for(int j = 0; j<g; j++)
			{
				cin>>aux;
				grande[i].push_back(aux);
			}
		}
		for(int i = 0;i<p;i++)
		{
			for(int j = 0; j< p;j++)
			{
				cin>>aux;
				peque[i].push_back(aux);
			}
		}
		//se reciben bien
		//rotar funciona bien
//		while(operaciones < 4)
//		{
		//cero rotacion
			while(aux2+p <= g) //filas
			{
				aux1 = 0;
				while(aux1+p <= g) //columnas
				{
					i = 0;
					flag = true;
					y = aux2;
					while(i < p)
					{
						x = aux1;
						j = 0;
						while(j < p)
						{
							if(grande[y][x] != peque[i][j])
							{
								flag = false;
								break;
							}	
							x++;
							j++;
						}
						if(flag == false)
						{
							break;
						}
						i++;
						y++;
					}
					if(flag == true)
						cero++;
					aux1++;
				}
				aux2++;
			}
		//una rotacion
		peque = rotar(peque,p);
			aux1 = 0;
			aux2 = 0;
			while(aux2+p <= g) //filas
			{
				aux1 = 0;
				while(aux1+p <= g) //columnas
				{
					i = 0;
					flag = true;
					y = aux2;
					while(i < p)
					{
						x = aux1;
						j = 0;
						while(j < p)
						{
							if(grande[y][x] != peque[i][j])
							{
								flag = false;
								break;
							}	
							x++;
							j++;
						}
						if(flag == false)
						{
							break;
						}
						i++;
						y++;
					}
					if(flag == true)
						nov++;
					aux1++;
				}
				aux2++;
			}
		//dos rotacion
		peque = rotar(peque, p);
			aux1 = 0;
			aux2 = 0;
			while(aux2+p <= g) //filas
			{
				aux1 = 0;
				while(aux1+p <= g) //columnas
				{
					i = 0;
					flag = true;
					y = aux2;
					while(i < p)
					{
						x = aux1;
						j = 0;
						while(j < p)
						{
							if(grande[y][x] != peque[i][j])
							{
								flag = false;
								break;
							}	
							x++;
							j++;
						}
						if(flag == false)
						{
							break;
						}
						i++;
						y++;
					}
					if(flag == true)
						och++;
					aux1++;
				}
				aux2++;
			}
		//tres rotacion
		peque = rotar(peque,p);
			aux1 = 0;
			aux2 = 0;
			while(aux2+p <= g) //filas
			{
				aux1 = 0;
				while(aux1+p <= g) //columnas
				{
					i = 0;
					flag = true;
					y = aux2;
					while(i < p)
					{
						x = aux1;
						j = 0;
						while(j < p)
						{
							if(grande[y][x] != peque[i][j])
							{
								flag = false;
								break;
							}	
							x++;
							j++;
						}
						if(flag == false)
						{
							break;
						}
						i++;
						y++;
					}
					if(flag == true)
						dos++;
					aux1++;
				}
				aux2++;
			}

		cout<<cero<<" "<<nov<<" "<<och<<" "<<dos<<'\n';
		cin>>g>>p;
	}
	return 0;
}
