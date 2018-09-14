#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> num(3);
	cin>>num[0]>>num[1]>>num[2];
	int menor=1000;
	do{
		menor = min(menor,num[0] - num[1] - num[2]);
		menor = min(menor,num[0] - num[1] + num[2]);
		menor = min(menor,num[0] - num[1] * num[2]);
		menor = min(menor,num[0] + num[1] - num[2]);
		menor = min(menor,num[0] + num[1] + num[2]);
		menor = min(menor,num[0] + num[1] * num[2]);
		menor = min(menor,num[0] * num[1] - num[2]);
		menor = min(menor,num[0] * num[1] + num[2]);
		menor = min(menor,num[0] * num[1] * num[2]);
	}while(next_permutation(num.begin(),num.end()));
	cout<<menor;




	return 0;
}
