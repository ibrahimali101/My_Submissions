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
int n,m;
vector<vector<int>>adj;
vector<int>vis;
int ans =0;
int dp[100004];
int op1=0,op2=0;
int c_path(int node)
{
    
    int &path = dp[node];
    if (~path) return path;
    op1++;
    path = 0;
    for (auto i : adj[node])
        path = max(path,1 + c_path(i));
    return path;
}

void solve()
{
    clr(dp,-1);
    cin >> n >> m;
    vis.resize(n+1);
    adj.resize(n+1);
    for (int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int ans = 0;
    for (int i=1;i<=n;++i){
        ans = max(ans,c_path(i));
    }
    cout << ans <<' ' << op1;
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