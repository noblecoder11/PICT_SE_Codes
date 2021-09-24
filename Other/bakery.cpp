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
cin>>n;
bool flag=0;

for (int i = 0; i <= 25; i++)
{
    for (int j = 0; j <= 15; j++)
    {
        if(i*4 +j*7==n){cout<<"yes"<<endl; flag=1; break;}
    }
    if(flag==1){break;}
}
if (flag==0)
{
    cout<<"no"<<endl;
}

    

return 0;
}