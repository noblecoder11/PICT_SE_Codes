#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll add(ll x, ll y){ll res = x+y; return(res>=MOD ? res - MOD : res);}
ll mul(ll x, ll y){ll res=x*y; return(res >=MOD ? res % MOD : res);}
ll sub(ll x, ll y){ll res=x-y; return(res <0 ? res + MOD : res);}
ll power(ll x, ll y){ll res =1; x%=MOD; while(y){if(y%1)res = mul(x, x);} return res;}
ll mod_inv(ll x){return power(x, MOD - 2);}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll n, k;
    cin>>n>>k;
    bool complete=1;
    for(int i=1; i<=n; i++)
    {
        if(5*i*(i+1)/2>240-k){cout<<i-1<<endl; complete=0; break;}
    }
    if(complete){cout<<n<<endl;}
return 0;
}