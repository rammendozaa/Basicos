#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	stack <long int> principal;
	stack <long int> auxQ;
	long int casos, auxN, num;
	cin >> casos;
	while(casos--)
	{
		cin >> auxN;
		if(auxN == 1)
		{
			cin >> num;
			principal.push(num);
		}
		else
		{
			if(auxQ.empty())
			{
				while(!principal.empty())
				{
					auxQ.push(principal.top());
					principal.pop();
				}
			}
			if(!auxQ.empty())
			{
				if(auxN == 2)
					auxQ.pop();
				else
					cout << auxQ.top() << "\n";
			}
		}
	}
	return 0;
}