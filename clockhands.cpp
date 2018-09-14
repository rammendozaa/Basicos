#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	float horas, minutos, anguloH, anguloM;
	while(scanf("%f:%f",&horas, &minutos))
	{
		if(horas == 0 && minutos == 0)
			break;
		anguloH = horas * 30 + ((minutos / 60) * 30);
		anguloM = minutos * 6;
		if(abs(anguloH - anguloM) > 180)
			printf("%.3f\n", abs(360 - abs(anguloH - anguloM)));
		else
			printf("%.3f\n", abs(anguloH - anguloM));
	}

	return 0;
}