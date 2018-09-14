#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
	long int cdJack, cdJill, auxJack, auxJill;
	while(cin >> cdJack >> cdJill && (cdJack != 0 || cdJill != 0))
	{
		set <long int> cds;
		queue <long int> auxCDJack;
		queue <long int> auxCDJill;
		for(int i = 0 ; i < cdJack ; i++)
		{
			cin >> auxJack;
			auxCDJack.push(auxJack);
		}
		for(int i = 0 ; i < cdJill ; i++)
		{
			cin >> auxJill;
			auxCDJill.push(auxJill);
		}
		while(!auxCDJack.empty() && !auxCDJill.empty())
		{
			if(auxCDJack.front() == auxCDJill.front())
			{
				cds.insert(auxCDJack.front());
				auxCDJack.pop();
				auxCDJill.pop();
			}	
			else if(auxCDJack.front() < auxCDJill.front())// && !auxCDJack.empty())
				auxCDJack.pop();
			else if(auxCDJack.front() > auxCDJill.front())// && !auxCDJill.empty())
				auxCDJill.pop();
		}
		cout << cds.size() << "\n";
	}
	return 0;
}