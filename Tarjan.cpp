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
const int N = 2e3+4;
int dfnn = 1;
int lowlink[N], dfn[N];
vector<int>adj[N];
int comp[N];
bool inStack[N];
int scc=0;
int n,m;
stack<int>stk;
void Tarjan(int node) {
    lowlink[node] = dfn[node] = dfnn++, inStack[node] = 1;
    stk.push(node);
    for (int ch : adj[node]) {
        if (dfn[ch] == -1) {
            Tarjan(ch);
            lowlink[node] = min(lowlink[ch],lowlink[node]);
        }else if (inStack[ch]){
            lowlink[node] = min(lowlink[ch],lowlink[node]);
        }
    }
    if (lowlink[node] == dfn[node]) {
        scc++;
        int x = -1;
        while(x!=node) {
            x = stk.top();
            stk.pop();
            inStack[x] = 0;
        }
    }
}

int main()
{
    ishowspeed
    while(cin >> n >> m)
    {
        scc = 0;
        clr(dfn,-1);
        clr(lowlink,0);
        for (int i=1;i<=n;++i) {
            adj[i].clear();
        }
        if (!(n|m)) break;
        for (int i=0;i<m;++i) {
            int u,v,p;
            cin >> u >> v >> p;
            adj[u].pb(v);
            if (p == 2) adj[v].pb(u);
        }
        for (int i = 1; i <= n; i++) {
            if (dfn[i] == -1) Tarjan(i);
        }
        cout << (scc == 1) << el;
    }
}