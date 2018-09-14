#include <iostream>
#include <algorithm>
#include <vector>
long int arr[100000];
using namespace std;

long int MaxSubCruzado(long int p, long int q, long int r){
	long int maxDer = -10000;
	long int maxIzq = -10000;
	long int aux = q + 1, suma = 0;
	while(q >= p){
		suma += arr[q];
		q--;
		maxIzq = max(maxIzq, suma);
	}
	suma = 0;
	while(aux <= r){
		suma += arr[aux];
		aux++;
		maxDer = max(maxDer, suma);
	}
	return maxIzq + maxDer;
}

long int MaxSubArr(long int p, long int q){
	if(p == q)
		return arr[p];
	long int mid = (p + q) / 2;
	return max({
		MaxSubArr(p,mid),MaxSubArr(mid+1,q),MaxSubCruzado(p,mid,q)
	});
}

int main(void)
{
	//cin.tie(0);
	//ios::sync_with_stdio(0);
	long int T, N;
	cin >> T;
	while(T--){
		cin>>N;
		for(long int i = 0 ; i < N ; i++)
			cin >> arr[i];
		long int res = MaxSubArr(0,N-1);
		sort(arr, arr + N);
		long int sub = arr[N - 1];
		for(long int i = N - 2 ; i >= 0 && arr[i] > 0 ; i--){
			sub += arr[i];
		}
		cout<<res<<" "<<sub<<'\n';
	}	
}