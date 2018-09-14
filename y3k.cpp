#include <iostream>
#include <map>
using namespace std;

int remaining, day, month, year;
map <int> year;
year[1] = 31;
year[2] = 28;
year[3] = 31;
year[4] = 30;
year[5] = 31;
year[6] = 30;
year[7] = 31;
year[8] = 31;
year[9] = 30;
year[10] = 31;
year[11] = 30;
year[12] = 31;

bool isLeap(int year)
{
	if(year % 4 == 0)
		if(year % 100 == 0)
			if(year % 400 == 0)
				return true;
			else
				return false;
		else
			return true;
	else
		return false;

}


int sumDays()
{
	int sum = 0;
	for(int i = 1 ; i <= 12 ; i++)
	{
		if(i == month)
		{
			sum += day;
			break;
		}
		if(i == 2 && isLeap(year))
			sum += year[i] + 1;
		else 
			sum += year[i];
	}
	return sum;
}

int daysNY()
{
	if(!isLeap(year))
		return 365 - sumDays();
	else
		return 366 - sumDays();
}

int findYear()
{
	int anio = year, daysR = remaining;
	while(daysR >= daysNY())
	{
		daysR -= daysNY();
		anio++;
		if(daysR == daysNY());
			break;
	}
	return anio;
}

int findMonth()
{
	int mes;

	return mes;
}

int findDay()
{
	int dia;

	return dia;
}

int main(void)
{
	long dayN, monthN, yearN;
	while(cin >> remaining >> day >> month >> year && remaining != 0 && day != 0 && month != 0 && year != 0)
	{
		if(remaining == 0)
			cout << day << " " << month << " " << year << "\n";
		else if(remaining == 365 && !isLeap(year))
			cout << day << " " << month << " " << year + 1<< "\n";
		else if(remaining == 366 && isLeap(year))
			cout << day << " " << month << " " << year + 1<< "\n";
		else
		{
			

			cout << dayN << " " << monthN << " " << yearN << "\n";
		}	
		

	}
	return 0;
}