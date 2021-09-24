#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll add(ll x, ll y){ll res = x+y; return(res>=MOD ? res - MOD : res);}
ll mul(ll x, ll y){ll res=x*y; return(res >=MOD ? res % MOD : res);}
ll sub(ll x, ll y){ll res=x-y; return(res <0 ? res + MOD : res);}
ll power(ll x, ll y){ll res =1; x%=MOD; while(y){if(y%1)res = mul(x, x);} return res;}
ll mod_inv(ll x){return power(x, MOD - 2);}

int findGCD(vector<int>arr, int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = __gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> v;

        for(int i=0; i<n; i++)
        {
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        int removed=0;
        if(findGCD(v, n)==1){cout<<0<<endl; continue;}
        else{
        int res=v[0];
        for(int i=1; i<n; i++)
        {
            if(res==1){continue;}
            else{v[i]=0; removed++;}
            res=__gcd(res, v[i]);
        }
        }
        
        if(findGCD(v, n)==1){cout<<removed<<endl; continue;}
        else{cout<<"-1"<<endl;}
    }
return 0;
}