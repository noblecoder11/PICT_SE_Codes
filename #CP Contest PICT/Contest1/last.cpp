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
int t;
cin>>t;
while(t--){
    int64_t n;
    cin>>n;
    
    // int count=0;
    // for(int i=2; i<=sqrtl(n); i++)
    // {
    //     if(n%i==0){count++;}

    // }
    // if(count==1){cout<<"YES"<<endl;}
    // else{cout<<"NO"<<endl;}
    if(n==4){cout<<"YES"<<endl;}
    else if(n%2==0){cout<<"NO"<<endl;}
    else
    {
         int count=0;
    for(int64_t i=2; i<n/2; i++)
    {
        if(n%i==0){count++;}

    }
    if(count==1){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
    }
}
return 0;
}