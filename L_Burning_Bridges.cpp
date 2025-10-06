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
const int N = 1e4+6;
int dfn[N],lowlink[N];
int ndfn = 1;
vector<int>adj[N];
set<int>bridge;
map<pair<int,int>,int>mp,frq;
void tarjan(int node,int par) {
    lowlink[node] = dfn[node] = ndfn++;
    for (int ch : adj[node]) {
        if (dfn[ch] == -1) {
            tarjan(ch,node);
            lowlink[node] = min(lowlink[node], lowlink[ch]);
            if (frq[{min(ch,node),max(ch,node)}] == 1 && lowlink[ch] > dfn[node]) {
                bridge.insert(mp[{node, ch}]);
            }
        } else if(ch != par) {
            lowlink[node] = min(lowlink[node], dfn[ch]);
        }
    }
}

void solve()
{
    clr(dfn,-1);
    int n,m;
    cin >> n >> m;
    int ID = 1;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        mp[{u,v}] = ID;
        mp[{v,u}] = ID++;
        frq[{min(u,v), max(u,v)}]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i=1;i<=n;++i) {
        if (dfn[i] == -1) tarjan(i,-1);
    }
    cout << bridge.size() << el;
    for (auto i : bridge) cout << i << ' ';
}

int main()
{
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
    ishowspeed
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
