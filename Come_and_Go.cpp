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
const ll mod = 1e9+7, OO = 0x3f3f3f3f;
int n,m;
const int N = 2e3+4;
vector<int>adj[N],adj2[N];
bool vis[N];
stack<int>st;
void dfs(int node) {
    vis[node] = true;
    for (auto j : adj[node]) {
        if (!vis[j]) dfs(j);
    }
    st.push(node);
}
void dfs1(int node) {
    vis[node] = true;
    for (auto j : adj2[node]) {
        if (!vis[j]) dfs1(j);
    }
}
int main()
{
    ishowspeed
    while(cin >> n >> m)
    {
        if (!(n|m)) break;
        st = stack<int>();
        for (int i=0;i<m;++i) {
            int u,v,p;
            cin >> u >> v >> p;
            adj[u].pb(v);
            adj2[v].pb(u);
            if (p == 2) adj[v].pb(u),adj2[u].pb(v);
        }
        dfs(1);
        bool ans = 1;
        for (int i=1;i<=n;++i) {
            if (!vis[i]) ans = 0;
        }
        clr(vis,0);
        dfs1(st.top());
        for (int i=1;i<=n;++i) {
            if (!vis[i]) ans = 0;
        }
        cout << ans << el;
        clr(vis,0);
        for (int i=1;i<=n;++i) {
            adj[i].clear();
            adj2[i].clear();
        }
    }
}
