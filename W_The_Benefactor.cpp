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
const int N = 5e4+6;
int dis[N];
bool vis[N];
vector<vector<int>>adj;
map<pair<int,int>,int>mp;

void init(int n) {
    adj.resize(n+1);
    for (int i=1;i<=n;++i) {
        adj[i].clear();
    }
    clr(vis,false);
    clr(dis,0);
}

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
                dis[j] = dis[node]+mp[{node,j}];
                q.push(j);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    init(n);
    for (int i=0;i<n-1;++i) {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[{u,v}] = c;
        mp[{v,u}] = c;
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
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
