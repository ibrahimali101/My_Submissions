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
const int N = 1e5+4;
vector<int>adj[N];
int Color[N];
void dfs(int i) {
    for (int j : adj[i]) {
        if (Color[j] == -1) {
            Color[j] = Color[i] == 1? 2 : 1;
            dfs(j);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    clr(Color,-1);
    for (int i=0;i<n-1;++i) {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool c = 1;
    Color[1] = 1;
    dfs(1);
    int R = 0, B = 0;
    for (int i=1;i<=n;++i) {
        R+= Color[i] == 1;
        B+= Color[i] == 2;
    }
    ll ans = 0;
    for (int i=1;i<=n;++i) {
        if (Color[i] == 1) { // if red
            ans+= (B - adj[i].size());
        }else {
            ans+= (R - adj[i].size());
        }
    }
    cout << ans/2;
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
