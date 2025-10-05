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
const int N = 4e4+9;
int b,e,p,n,m;
vector<vector<int>>adj;
int DisB[N],DisE[N],DisBarn[N];
void bfs(int i, int Dis[]) {
    queue<int>q;
    q.push(i);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto j : adj[node]) {
            if (Dis[j] == -1) Dis[j] = Dis[node]+1, q.push(j);
        }
    }
}
void solve()
{
    clr(DisB,-1);clr(DisE,-1);clr(DisBarn,-1);
    cin >> b >> e >> p >> n >> m;
    adj.resize(n+1);
    DisB[1] = 0;
    DisE[2] = 0;
    DisBarn[n] = 0;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1,DisB),bfs(2,DisE),bfs(n,DisBarn);
    int mn = OO;
    for (int i=1;i<=n;++i) {
        int sum = 0;
        sum += DisB[i]*b;
        sum += DisE[i]*e;
        sum += DisBarn[i]*p;
        mn = min(sum,mn);
    }
    cout << mn;
}

int main()
{
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    ishowspeed
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
