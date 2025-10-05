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
const int N = 1e3+5;
int n,m;
vector<int>adj[N];
int vis[N];
int IN[N];
int BFS() {
    queue<int>q;
    for (int i=1;i<=n;++i) {
        if (!IN[i]) q.push(i),vis[i]=true;
    }
    bool many = false;
    while(!q.empty())
    {
        int node = q.front();
        if (q.size() > 1) many = true;
        q.pop();
        int op = 0;
        for (int j : adj[node]) {
            if (!vis[j]) op++,vis[j]=true,q.push(j);
        }
    }
    for (int i=1;i<=n;++i) {
        if (!vis[i]) return 0;
    }
    return many? 2 : 1;
}

void solve()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    while(true){
        cin >> n >> m;
        if (n ==0 && m==0) break;
        for (int i=1;i<=n;++i) adj[i].clear();
        clr(vis,false);
        clr(IN,0);

        for (int i=0;i<m;++i) {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            IN[v]++;
        }
        cout << BFS() << el;
    }
    
    // int tc = 1;
    // cin >> tc;
    // while(tc--)
    // {
    //     solve();
    //     cout << el;
    // }
}