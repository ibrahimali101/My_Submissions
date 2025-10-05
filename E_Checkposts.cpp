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
const int N = 1e5+6;
int ndfn = 1;
int dfn[N], lowlink[N], comp[N], up[N];
int Cost[N];
bool inStack[N];
stack<int>stk;
vector<vector<int>>adj(N),comps;
void tarjan(int node) {
    dfn[node] = lowlink[node] = ndfn++; inStack[node] = 1;
    stk.push(node);
    for (int ch : adj[node]) {
        if (dfn[ch] == -1) {
            tarjan(ch);
            lowlink[node] = min(lowlink[node], lowlink[ch]);
        }
        else if (inStack[ch]) {
            lowlink[node] = min(lowlink[node], lowlink[ch]);
        }
    }
    if (lowlink[node] == dfn[node]) {
        comps.pb(vector<int>());
        int x = - 1;
        while(x!=node) {
            x = stk.top(); stk.pop(); inStack[x] = 0;
            comps.back().pb(Cost[x]);
            // comp[x] = comps.size() - 1;
        }
        sort(all(comps.back()));
    }
}
void solve()
{
    int n,m;
    cin >> n;
    clr(dfn,-1);
    for (int i=1;i<=n;++i)
        cin >> Cost[i];
    cin >> m;
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i=1;i<=n;++i) {
        if (dfn[i] == -1) 
            tarjan(i);
    }
    ll mn = 0;
    for (int i=0;i<comps.size();++i) {
        int k = *comps[i].begin();
        mn += k;
        up[i] = upper_bound(all(comps[i]), k) - comps[i].begin();
    }
    ll nW = 1;
    for (int i=0;i<comps.size();++i) {
        nW = (nW * up[i])%mod;
    }
    cout << mn << " " << nW;
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
