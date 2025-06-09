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
int n,m,k;
vector<int>v;
vector<vector<int>>co;
int dp[109][109][109];
int rec(int i,int lc,int cnt)
{
    if (cnt < 0) return 1e18;
    if (i == n) return !cnt? 0 : 1e18;
    int &ret = dp[i][lc][cnt];
    if (~ret) return ret;
    if (v[i]) return ret = rec(i+1,v[i],cnt-(v[i]!=lc));
    else{
        ret = 1e18;
        for (int j=1;j<=m;++j)
        ret = min(ret, co[i][j-1] + rec(i+1,j,cnt-(j!=lc)));
    }
    return ret;
}

void solve()
{
    clr(dp,-1);
    cin >> n >> m >> k;
    v.resize(n);
    co.resize(n,vector<int>(m));
    for (auto &i : v) cin >> i;
    for (auto &i : co)
    {
        for (auto &j : i) cin >> j;
    }
    int ans = rec(0,m+1,k);
    cout << (ans==1e18? -1 : ans);
}

signed main()
{
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