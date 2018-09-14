#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int howMany(bool sta, bool que, bool pque)
{
	if(sta && que && pque)
		return 3;
	if(sta && que)
		return 2;
	if(sta && pque)
		return 2;
	if(pque && que)
		return 2;
}
int main(void)
{
	int casos; 
	while(cin >> casos)
	{
		int n, entrada;
		bool isStack, isQueue, isPrior;
		isStack = true;
		isQueue = true;
		isPrior = true;
		stack <int> sta;
		queue <int> que;
		priority_queue <int> pque;
		while(casos--)
		{
			cin >> entrada >> n;
			if(entrada == 1)
			{
				sta.push(n);
				que.push(n);
				pque.push(n);
			}
			else if(entrada == 2)
			{
				if(isStack)
				{
					if(sta.empty() || sta.top() != n)
						isStack = false;
					else
						sta.pop();
				}
				if(isQueue)
				{
					if(que.empty() || que.front() != n)
						isQueue = false;
					else
						que.pop();
				}
				if(isPrior)
				{
					if(pque.empty() || pque.top() != n)
						isPrior = false;
					else
						pque.pop();
				}
			}
		}
		if(!isPrior && !isQueue && isStack)
			cout << "stack\n";
		else if(!isPrior && isQueue && !isStack)
				cout << "queue\n";
		else if(isPrior && !isQueue && !isStack)
				cout << "priority queue\n";
		else if(!isStack && !isQueue && !isPrior)
			cout << "impossible\n";
		else
			cout << "not sure\n";
	}
	return 0;
}