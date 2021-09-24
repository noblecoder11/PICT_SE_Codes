#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll add(ll x, ll y){ll res = x+y; return(res>=MOD ? res - MOD : res);}
ll mul(ll x, ll y){ll res=x*y; return(res >=MOD ? res % MOD : res);}
ll sub(ll x, ll y){ll res=x-y; return(res <0 ? res + MOD : res);}
ll power(ll x, ll y){ll res =1; x%=MOD; while(y){if(y%1)res = mul(x, x);} return res;}
ll mod_inv(ll x){return power(x, MOD - 2);}

struct trip{
    double x; ll y; ll z;
};
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll n, w;
    cin>>n>>w;
    
    vector <ll> val;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin>>x;
        val.push_back(x);
    }

    vector <ll> wt;
    for (ll j = 0; j < n; j++)
    {
        ll x;
        cin>>x;
        wt.push_back(x);        
    }

    vector <pair<[]> vp;
    for (ll i = 0; i < n; i++)
    {
        vp.push_back({val[i]/(1.0*wt[i]), wt[i], val[i]});        
    }
    sort(vp.begin(), vp.end(), 1);

    ll fwt=0;
    double fval=0;
    
    // for (ll i = 0; i < n; i++)
    // {
    //     ll a=0;
    //     while(a<wt[i] and fwt<w)
    //     {
    //         fval+=val[i]/(1.0*wt[i]);
    //         fwt+=1;
    //         a+=1;
    //     }
    // }
    
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (fwt + vp[i].y <= w) {
            fwt += vp[i].y;
            fval += vp[i].z;
        }
 
        // If we can't add current Item, add fractional part
        // of it
        else {
            int remain = w - fwt;
            fval += vp[i].z
                          * ((double)remain
                             / (double)vp[i].y);
            break;
        }
    }
    cout<<fixed<<setprecision(6)<<fval<<endl;

return 0;
}