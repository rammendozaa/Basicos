#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

struct comparar {
    constexpr bool operator()(pair<long int, long int> const & a,
                              pair<long int, long int> const & b) const noexcept
    { return a.first > b.first || (a.first == b.first && a.second > b.second); }
};

vector <long int> factores (long int n, long int K)
{
	vector <long int> fact;
	for(int i = 1 ; i <= K ; i++)
		fact.push_back(i * n);
	return fact;
}

int main(void)
{
	string auxS;
	long int id, period, K;
	map <long int, long int> query;
	vector <long int> aux;
	priority_queue <pair<long int, long int>, vector<pair<long int, long int> >, comparar> ordenados;
	while(cin >> auxS && auxS != "#")
	{
		cin >> id >> period;
		query[id] = period;
	}
	cin >> K;
	for(auto a : query)
	{
		aux = factores(a.second, K);
		for(auto b : aux)
		{
			ordenados.push(make_pair(b, a.first));
		}
	}
	for(int i = 0 ; i < K ; i++)
	{
		cout << ordenados.top().second << "\n";
		ordenados.pop();
	}
	return 0;
}