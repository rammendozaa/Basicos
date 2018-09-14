#include<bits/stdc++.h>
using namespace std ;
//-------------------------------
typedef long long ll ;
#define rep(i,a,b) for(int i=(a) ; (i)<(b) ; ++i)
#define inf 2000000000
#define endl "\n"
//------------------------------
int ri() { char c = getchar(); while(c<'0' || c>'9') c=getchar(); int ret = 0; while(c>='0' && c<='9') { ret=10*ret+c-48; c=getchar(); } return ret; }
ll n,m,k ;
int main() {
//freopen("input.txt","r",stdin);
scanf("%lld%lld%lld",&n,&m,&k) ;
ll R=n*m ;
ll L=1 ;
while(L<=R){ ll mid = (L+R) >> 1 ;
ll cnt = 0 ;
rep(i,1,m+1){
cnt += ( n < (mid/i)) ? n : (mid/i) ;
}
if(cnt<k)
L=mid+1 ;
else
R=mid-1 ;
}
printf("%lld\n",L);
}