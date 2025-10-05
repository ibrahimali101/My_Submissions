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
const int N = 2e6+9;
vector<int>par,sz;
void init() {
    par.resize(N);
    sz.resize(N);
    for (int i=1;i<=N;++i)
    {
        par[i] = i;
        sz[i]=1;
    }
}

int FindPar(int u) {
    if (u == par[u]) return u;
    return par[u] = FindPar(par[u]);
}

bool F(int u,int v) {
    return FindPar(u) == FindPar(v);
}

void UnBySz(int u,int v) {
    u = FindPar(u);
    v = FindPar(v);
    if (u == v) return;
    par[u] = v;
    sz[v] += sz[u];
}

int getSize(int i) {
    int rep = FindPar(i);
    return sz[rep];
}

void solve()
{
    int n;
    cin >> n;
    init();
    int Given_ID = 1;
    map<string,int>ID;
    for (int i=0;i<n;++i) {
        string u,v;
        cin >> u >> v;
        if (ID[u] == 0) ID[u] = Given_ID++;
        if (ID[v] == 0) ID[v] = Given_ID++;
        UnBySz(ID[u],ID[v]);
        cout << getSize(ID[v]) << el;
    }
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
