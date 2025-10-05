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
#define fix(a,b) (a%b+b)%b
#define ishowspeed ios_base::sync_with_stdio(false);    cin.tie();    cout.tie();
using int64 = ll;
using namespace std;
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
const int N = 3e5+6;
int Color[N];
vector<vector<int>>adj;
int n,R,B;
pair<int,int>dp[N];
int ans = 0;
bool vis[N];
void dfs(int i,int par) {
    vis[i] = true;
    dp[i] = {Color[i] == 1, Color[i] == 2};
    for (auto j : adj[i]) {
        if (par == i) continue;
        if (vis[j]) continue;
        dfs(j,i);
        dp[i].fi += dp[j].fi;
        dp[i].se += dp[j].se;
    }
}

int main()
{
    ishowspeed
    cin >> n;
    adj.resize(n+1);
    for (int i=1;i<=n;++i) {
        int x;
        cin >> x;
        if (x == 1) R++;
        else if (x==2) B++;
        Color[i] = x;
    }
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    int ans = 0;
    for (int i=1;i<=n;++i) {
        if (dp[i].fi == R && dp[i].se == 0) ans++;
        if (dp[i].se == B && dp[i].fi == 0) ans++;
    }
    cout << ans;
}
