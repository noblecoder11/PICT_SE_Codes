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
    int k, s, count=0;
    cin>>k>>s;
    int x, y, z;
    for (int x = 0; x <= k; x++)
    {
        for (int y = 0; y <= k; y++)
        {
                if (x+y>=0 && s-x-y>=0) 
                {
                    count++;
                }
                 
            
        }
        
    }
    cout<<count<<endl;
return 0;
}