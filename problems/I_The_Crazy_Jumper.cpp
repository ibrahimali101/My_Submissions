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
int n;
vector<int>v,inc;

void solve()
{
    cin >> n;
    v = vector<int>(n);
    inc = vector<int>(n,-1);
    for (auto &i : v)cin >>i;
    vector<int>fr(2e5+6,-1);
    for (int i=0;i<n;++i){
        if (fr[v[i]] == -1)
            inc[i] = -1; 
        else 
            inc[fr[v[i]]] = i;
        fr[v[i]] = i;
    }
    vector<int>dp(n+1,inf);
    dp[0] = 0;
    for (int i=0;i<n;++i)
    {
        dp[i+1] = min (dp[i+1] , 1 + dp[i]);
        if (inc[i]!=-1) dp[inc[i]] = min(dp[inc[i]], 1+ dp[i]);
    }
    cout << dp[n-1];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}