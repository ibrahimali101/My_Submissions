// Good. That's one less loose end.
#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define clr(v,d) memset(v,d,sizeof(v));
#define cceil(a,b) (a+b-1)/b
#define inf (1<<31)-1
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;
vector<pair<int,int>>cop;
void sieve_prime()
{
    for (int i=1;i<=1000;++i)
    {
        for (int j=1;j<=1000;++j)
        {
            if (__gcd(i,j) == 1) cop.pb({i,j});
        }
    }
}

void solve()
{
    map<int,int>mp;
    mp[4] = 4;
    for (auto i : mp) cout << i.fi << ':' << i.se << el;
    mp[4]=0;
    for (auto i : mp) cout << i.fi << ':' << i.se << el;
}

signed main()
{
    sieve_prime();
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}