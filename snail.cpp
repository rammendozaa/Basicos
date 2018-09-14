#include <iostream>
using namespace std;
int main()
{	
	int dias;
	float altura, sube, baja, fatiga,dist,distfat;
	dias = 0;
	dist = 0;
	float inicio = 0;
	cin>>altura>>sube>>baja>>fatiga;
	while(altura != 0)
	{
		dias = 0;
		dist = 0;
		fatiga = fatiga/100;
		distfat = fatiga * sube;
		while(dist<altura)
		{
			dias++;
			if(sube < 0)
				sube = 0;
			dist = dist + sube;
			if(dist>altura)
			{
				cout<<"success on day "<<dias<<'\n';
				break;
			}
			dist = dist - baja;
			sube = sube - distfat;
			if(dist < 0.0)
			{
				cout<<"failure on day "<<dias<<'\n';
				break;
			}
		}
		cin>>altura>>sube>>baja>>fatiga;
	}





/*
int alt,sub,baj,dist,dias;
	cin>>alt;
	cin>>sub;
	cin>>baj;
	dias=0;
	dist=0;
	while(dist<alt)
	{
		dias++;
		dist=dist+sub;
		if(dist>=alt)
		{
			cout<<dias;
			break;
		}	
		dist=dist-baj;
	}
*/	return 0;
}
