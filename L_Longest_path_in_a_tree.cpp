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
const int N = 1e4+9;
int dis[N];
bool vis[N];
vector<vector<int>>adj;
void bfs(int i) {
    vis[i] = true;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int node = q.front();
        vis[node] = true;
        q.pop();
        for (auto j : adj[node]) {
            if (!vis[j]) {
                dis[j] = dis[node]+1;
                q.push(j);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1);
    int mx = 0;
    int max_dis = 0;
    for (int i=1;i<=n;++i) {
        if (mx <= dis[i]) {
            mx = dis[i];
            max_dis = i;
        }
    }
    mx = 0;
    clr(dis,0);
    clr(vis,false);
    bfs(max_dis);
    for (int i=1;i<=n;++i) {
        mx = max(mx,dis[i]);
    }
    cout << mx;
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
