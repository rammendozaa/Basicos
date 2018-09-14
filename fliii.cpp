#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
int main(void)
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		string side, currSide;
		int currTime, auxTime, ferry, count;
		cin >> cars >> time >> lines;
		queue <int> left, right;
		map <int, int> final;
		vector <int> auxR, auxL;
		for(int i = 0 ; i < lines ; i++)
		{
			cin >> auxTime >> side;
			if(side == "right")
				right.push(auxTime);
			else
				left.push(auxTime);
		}
		currTime = 0;
		ferry = 0;
		count = 0;
		currSide = "left";
		while(!left.empty() || !right.empty())
		{
			if(currSide == "left")
			{
				if(left.front() > right.front() && !left.empty() && !right.empty())
				{
					currTime += time;
					currSide = "right";
				}
				else
				{
					currTime = left.front();
					while(ferry < cars && !left.empty())
					{
						if(left.front() <= currTime)
						{
							ferry++;
							left.pop();
						}
						else
							break;
					}
				}

			}
			else if(currSide == "right")
			{

			}
		}
		if(cases >= 1)
			cout << "\n";
	}
	return 0;
}