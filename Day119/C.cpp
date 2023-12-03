// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>

// using namespace std;

// #define ll long long
// #define vli vector<ll>
// #define rep(i, n) for (int i = 0; i < n; i++)
// #define dsort(v) sort(v.begin(), v.end(), greater<ll>())

// ll __gcd(ll a, ll b)
// {
//     return b == 0 ? a : __gcd(b, a % b);
// }

// void solve()
// {
//     ll n;
//     cin >> n;
//     vli v(n);
//     map<ll, ll> mp;
//     rep(i, n)
//     {
//         cin >> v[i];
//         mp[v[i]]++;
//     }

//     dsort(v);

//     if (n == 1)
//     {
//         cout << 1;
//         return;
//     }

//     ll gcd = v[n - 1] - v[n - 2];

//     for (int i = n - 3; i >= 0; i--)
//     {
//         gcd = __gcd(gcd, (v[n - 1] - v[i]));
//     }

//     ll ans = 0;

//     for (int i = 0; i < n; i++)
//     {
//         ans += (v[n - 1] - v[i]) / gcd;
//     }

//     ll curr = v[n - 1];
//     while (mp.find(curr) != mp.end())
//     {
//         curr -= gcd;
//     }

//     cout << ans + ((v[n - 1] - curr) / gcd);
// }

// int main()
// {
//     int t;
//     cin>>t;
//     for(int i = 0; i<t; i++){
//         solve();
//         cout << endl;
//     }
    
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
#define pb push_back
#define pf push_front
#define nl '\n'
ll fx[]= {1,0,-1,0,1,-1,1,-1};
ll fy[]= {0,1,0,-1,1,-1,-1,1};
void func()
{
    cout<<" Na otari chapara beltow "<<nl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll tc=1;
    cin>>tc;
    for(ll tt=1; tt<=tc; tt++)
    {
        ll n;
        cin>>n;
        ll a[n];
         map<ll,ll>ache;
        for(ll i=0;i<n;i++)cin>>a[i],ache[a[i]]=1;
        if(n==1){
            cout<<1<<nl;
            continue;
        }
        sort(a,a+n);
       // cout<<"ache"<<nl;
        ll mx=a[n-1];
        ll dif[n];
        for(ll i=0;i<n;i++){
            dif[i]=mx-a[i];
        }
        ll gc=dif[0];
        for(ll i=0;i<n;i++){
                //cout<<dif[i]<<nl;
            gc=__gcd(dif[i],gc);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans+=(dif[i]/gc);
        }
        ll ekhon=mx;
        ll koita=n+5;
        for(ll i=0;i<n;i++){
                ekhon-=gc;
            if(ache[ekhon]==0){
                koita=i+1;
                break;
            }
        }
         cout<<min(ans+n,ans+koita)<<nl;
        //cout<<gc<<nl;

    }
    return 0;
}