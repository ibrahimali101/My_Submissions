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
const int N = 1e6+6;
int n,m;
vector<vector<int>>adj;
int vis[N];
vector<int>sorv;
void init(int n) {
    adj.resize(n+1);
    for (int i=1;i<=n;++i) {
        adj[i].clear();
    }
    clr(vis,0);
    sorv.clear();
}
int dfs(int i) {
    vis[i] = 1;
    for (auto j : adj[i]) {
        if (vis[j] == 0) {
            if (dfs(j)) return true;
        }
        else if (vis[j] == 1) {
            return true;
        }
    }
    vis[i] = 2;
    sorv.pb(i);
    return false;
}
int main()
{
    ishowspeed
    while(cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        init(n);
        for (int i=0;i<m;++i) {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        bool x = 0;
        for (int i=1;i<=n;++i) {
            if (!vis[i]) {
                x|=dfs(i);
            }
        }
        if (x) cout << "IMPOSSIBLE\n";
        else {
            reverse(all(sorv));
            for (auto i : sorv) cout << i << '\n';
        }
    }
}
