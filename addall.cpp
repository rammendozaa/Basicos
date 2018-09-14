#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main(void)
{
	long int numbers, minCost, sumCost, auxN, auxUno, auxDos, sumAux;
	while(cin >> numbers && numbers != 0)
	{
		//priority_queue <long int> nums;
		vector <long int> numeros(numbers);
		sumCost = 0;
		sumAux = 0;
		for(int i = 0 ; i < numbers ; i++)
		{
			cin >> auxN;
			numeros[i] = auxN;
		}
		priority_queue<int, vector<int>, greater<int> > nums (numeros.begin(),numeros.end());
	/*	while(!nums.empty())
		{
			cout << nums.top() << " ";
			nums.pop();
		}
cout << "\n";
*/
		sumAux = 0;
		if(numbers == 1)
		{
			cout << "0" << "\n";
			continue;
		}
		while(nums.size() > 1)
		{
			auxUno = nums.top();
			nums.pop();
			auxDos = nums.top();
			nums.pop();
			sumCost = auxUno + auxDos;
			sumAux += sumCost;
			nums.push(sumCost);
		}
			cout << sumAux<< "\n";
		
	}
	return 0;
}