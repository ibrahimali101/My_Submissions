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
const int N = 3e5+5;
int lead[N];
int sz[N];
ll ans = 0;

void init(int n) {
    for (int i=1;i<=n;++i) {
        lead[i] = i;
        sz[i] = 1;
    }
}

int findpar(int u) {
    if (u == lead[u]) return u;
    return lead[u] = findpar(lead[u]);
}
int getsz(int u) {
    u = findpar(u);
    return sz[u];
}

void attack(int u,int v) {
    u = findpar(u);
    v = findpar(v);
    if (u == v) return;
    if (sz[u] < sz[v]) { swap(u, v); }
    ans+= (getsz(v)*getsz(u));
    sz[u] += sz[v];
    lead[v] = u;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    init(n);
    vector<pair<int,pair<int,int>>> edgeList(n-1);
    for (int i=0;i<n-1;++i) {
        int u,v,w;
        cin >> u >> v >> w;
        edgeList[i] = {w,{u,v}};
    }
    sort(all(edgeList));
    int queries[N] {0};
    for (int i=0;i<n-1;++i) {
        attack(edgeList[i].se.fi,edgeList[i].se.se);
        queries[edgeList[i].fi] = ans;
    }
    for (int i=1;i<N;++i) {
        if (!queries[i]) queries[i] = queries[i-1];
        // cout << queries[i] << ' ';
    }
    while (q--) {
        int x;
        cin >> x;
        cout << queries[x] << ' ';
    }
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
