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
    int n;
    string s;
    cin>>n;
    cin>>s;
    string ns;
    int p=0;
    for(int i=0; i<n; i=p*(p+1)/2)
    {
        ns+=s[i];
        p++;
    }
    cout<<ns;
return 0;
}