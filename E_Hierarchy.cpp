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
#define ishowspeed ios_base::sync_with_stdio(false);
using int64 = ll;
using namespace std;
const int mod = 1e9+7, OO = 0x3f3f3f3f;
const int N = 1e5 + 8;
vector<vector<int>>adj;
bool vis[N];
vector<int>top_so;
void dfs(int node) {
    vis[node] = true;
    for (int i : adj[node]) {
        if (!vis[i]) dfs(i);
    }
    top_so.pb(node);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i=1;i<=m;++i) {
        int wishes;
        cin >> wishes;
        while(wishes--) {
            int v;
            cin >> v;
            adj[i].pb(v);
        }
    }
    for (int i=1;i<=n;++i) {
        if (!vis[i]) dfs(i);
    }
    reverse(all(top_so));
    int Par[N] {0};
    for (int i=1;i<top_so.size();++i) {
        Par[top_so[i]] = top_so[i-1]; 
    }
    int boss = top_so[0];
    for (int i=1;i<=n;++i) {
        cout <<Par[i] << '\n';
    }
}

int main()
{
    ishowspeed
    int tc = 1;
    // cin >> tc;
    for (int i=0;i<tc;++i)
    {
        solve();
        cout << el;
    }
}
