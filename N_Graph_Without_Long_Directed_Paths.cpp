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
const int N = 2e5+9;
int color[N]; // -1 no color, 1 blue , 2 red
vector<vector<int>> adj;
bool yes = 1;
void can_color(int i)
{
    for (auto j : adj[i]) {
        if (color[j] == -1) {
            color[j] = (3^color[i]);
            can_color(j);
        }
        else if (color[j] == color[i]) {
            yes = 0;
        }
    }
}

void solve()
{
    int n,m;
    cin >> n >> m;
    clr(color,-1);
    adj.resize(n+1);
    pair<int,int> edgeList[m];
    for (int i=0;i<m;++i) {
        int u,v;
        cin >> u >> v;
        edgeList[i] = {u,v};
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool flag = 1;
    int c = 1;
    for (int i=1;i<=n;++i) {
        if (color[i] == -1) {
            color[i] = c;
            c^=3;
            yes = 1;
            can_color(i);
            flag &= yes;
        }
    }
    
    if (flag) {
        cout << "YES\n";
        for (int i=0;i<m;++i) {
            if (color[edgeList[i].fi] == 1) cout << 0;
            else cout << 1;
        }
    }else cout << "NO";
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
