#include <map>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int main(void)
{
	long int casos, fields, blue, green, auxBlue, auxGreen;
	cin >> casos;
	while(casos--)
	{
		priority_queue <long int> bBlue;
		priority_queue <long int> bGreen;
		cin >> fields >> green >> blue;
		for(int i = 0 ; i < green ; i++)
		{
			cin >> auxGreen;
			bGreen.push(auxGreen);
		}
		for(int i = 0 ; i < blue ; i++)
		{
			cin >> auxBlue;
			bBlue.push(auxBlue);
		}
		/*
		while(!bBlue.empty() && !bGreen.empty())
		{
			cout << bBlue.top() << " " << bGreen.top() << "\n";
			bBlue.pop();
			bGreen.pop();
		}
		*/

		while(!bBlue.empty() && !bGreen.empty())
		{
			vector <long int> ganadorB;
			vector <long int> ganadorG;
			for(int i = 0 ; i < fields ; i++)
			{
				if(!bGreen.empty() && !bBlue.empty())
				{
					auxBlue = bBlue.top();
					auxGreen = bGreen.top();
					if(auxBlue > auxGreen)
					{
						auxBlue = auxBlue - auxGreen;
						bBlue.pop();
						bGreen.pop();
						ganadorB.push_back(auxBlue);
						//bBlue.push(auxBlue);
					}
					else if(auxBlue < auxGreen)
					{
						auxGreen = auxGreen - auxBlue;
						bBlue.pop();
						bGreen.pop();
						ganadorG.push_back(auxGreen);
						//bGreen.push(auxGreen);
					}
					else
					{
						bBlue.pop();
						bGreen.pop();
					}
				}
			
			}
			for(auto a : ganadorB)
				bBlue.push(a);
			for(auto a : ganadorG)
				bGreen.push(a);
		}
		if(bBlue.empty() && !bGreen.empty())
		{
			cout << "green wins\n";
			while(!bGreen.empty())
			{
				cout << bGreen.top() << "\n";
				bGreen.pop();
			}
		}
		else if(!bBlue.empty() && bGreen.empty())
		{
			cout << "blue wins\n";
			while(!bBlue.empty())
			{
				cout << bBlue.top() << "\n";
				bBlue.pop();
			}
		}		
		else if(bBlue.empty() && bGreen.empty())
			cout << "green and blue died\n";
	
		if(casos >= 1)
			cout << "\n";

	}
	return 0;
}