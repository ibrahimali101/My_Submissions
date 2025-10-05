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
int n,m;
vector<vector<int>>adj;
vector<int>vis;
// course schedule
vector<int>v;

// bool cycle(int i)
// {
//     vis2[i] = 1;
//     for (auto j : adj[i]) {
//         if (vis2[j] == 0) {
//             if (cycle(j)) return true;
//         }
//         else if (vis2[j] == 1) {
//             return true;
//         }
//     }
//     vis2[i] = 2;
//     return false;
// }


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
    v.pb(i);
    return false;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vis.resize(n+1);
    adj.resize(n+1);
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        adj[v].pb(u);
    }
    bool x = 0;
    for (int i=1;i<=n;++i) {
        if (!vis[i]) {
            x|=dfs(i);
        }
    }
    if (x) cout << "IMPOSSIBLE";
    else 
    for (auto i : v) cout << i << ' ';
}

int main()
{
    ishowspeed
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
