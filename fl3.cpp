#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <utility>
using namespace std;
string currentSide;
int ferry;
int currentTime;
int timeCross;

int main(void)
{
	int cases, carsTotal, arrivalTime , carsWaiting;
	string side;
	cin >> cases;
	while(cases--)
	{
		cin >> carsTotal >> timeCross >> carsWaiting;
		//int currentTime = 0;
		//deque <int> ferry;
		int ferry;
		queue <int> rightSide;
		queue <int> leftSide;

		//1
		for(int i = 0 ; i < carsWaiting ; i++)
		{
			cin >> arrivalTime >> side;
			if(side == "right")
				rightSide.push(arrivalTime);
			else
				leftSide.push(arrivalTime);
		}
		ferry = 0;
		currentTime = 0;
		currentSide = "left";
		while(!leftSide.empty() || !rightSide.empty())
		{
			if(leftSide.front() > rightSide.front() && !rightSide.empty() && !leftSide.empty())
			{
				if(currentSide == "right")
				{
					while(ferry < carsTotal)
					{
						if(rightSide.front() <= currentTime  && !rightSide.empty() && !leftSide.empty())
						{
							ferry++;
							rightSide.pop();
						}
						else if(rightSide.front() > currentTime && !rightSide.empty() && !leftSide.empty() && ferry == 0)
						{
							currentTime = rightSide.front();
							ferry++;
							rightSide.pop();
						}
						else
							break;
					}
					currentSide = "left";
					currentTime += timeCross;
						while(ferry--)
					cout << currentTime <<"\n";
				ferry = 0;
			
				}
				else if(currentSide == "left")
				{
					currentSide = "right";
					if(rightSide.front() > currentTime && !rightSide.empty() && ferry == 0)
						currentTime = rightSide.front();
					currentTime += timeCross;
				}
			}
			else if(leftSide.front() < rightSide.front() && !rightSide.empty() && !leftSide.empty())
			{
				if(currentSide == "left")
				{
					while(ferry < carsTotal)
					{
						if(leftSide.front() <= currentTime  && !rightSide.empty() && !leftSide.empty())
						{
							ferry++;
							leftSide.pop();
						}
						else if(leftSide.front() > currentTime && !rightSide.empty() && !leftSide.empty() && ferry == 0)
						{
							currentTime = leftSide.front();
							ferry++;
							leftSide.pop();
						}
						else
							break;
					}
					currentSide = "right";
					currentTime += timeCross;
						while(ferry--)
					cout << currentTime <<"\n";
				ferry = 0;
			
				}
				else if(currentSide == "right")
				{
					currentSide = "left";
					if(leftSide.front() > currentTime && !leftSide.empty() && ferry == 0)
						currentTime = leftSide.front();
					currentTime += timeCross;
				}
			}
			else if(rightSide.empty())
			{
				if(currentSide == "left")
				{
					while(ferry < carsTotal)
					{
						if(leftSide.front() <= currentTime && !leftSide.empty())
						{
							ferry++;
							leftSide.pop();
						}
						else if(leftSide.front() > currentTime && !leftSide.empty() && ferry == 0)
						{
							ferry++;
							currentTime = leftSide.front();
							leftSide.pop();
						}
						else
							break;
					}
					currentSide = "right";
					currentTime += timeCross;
					while(ferry--)
						cout << currentTime << "\n";
					ferry = 0;
				}
				else if(currentSide == "right")
				{
					currentSide = "left";
					if(leftSide.front() > currentTime && !leftSide.empty() && ferry == 0)
						currentTime = leftSide.front();
					currentTime += timeCross;
				}
			}
			else if(leftSide.empty())
			{
				if(currentSide == "right")
				{
					while(ferry < carsTotal)
					{
						if(rightSide.front() <= currentTime  && !rightSide.empty())
						{
							ferry++;
							rightSide.pop();
						}
						else if(rightSide.front() > currentTime && !rightSide.empty() && ferry == 0)
						{
							ferry++;
							currentTime = rightSide.front();
							rightSide.pop();
						}
						else
							break;
					}
					currentSide = "left";
					currentTime += timeCross;
					while(ferry--)
						cout << currentTime << "\n";
					ferry = 0;
				}
				else if(currentSide == "left")
				{
					currentSide = "right";
					if(rightSide.front() > currentTime && !rightSide.empty() && ferry == 0)
						currentTime = rightSide.front();
					currentTime += timeCross;
				}
			}
		}


		if(cases >= 1)
			cout << "\n";
	}
	return 0;
}




//could do with two queues for each side and start popping -- 1
// or at the moment they come into each side, as the program is reading -- 2