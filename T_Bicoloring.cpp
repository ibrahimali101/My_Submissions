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
const int N = 2e2 + 5;
int n,m;
vector<vector<int>>adj;
int Color[N];
void init(int n)
{
    adj.resize(n);
    for (int i=0;i<n;++i) {
        adj[i].clear();
    }
    clr(Color,-1);
}

bool dfs(int i) {
    for (int j : adj[i]) {
        if (Color[j] == -1) {
            Color[j] = (Color[i] == 1? 2 : 1);
            if (!dfs(j)) return false;
        }
        else if (Color[j] == Color[i])
            return false;
    }
    return true;
}

int main()
{
    ishowspeed
    while(cin >> n)
    {
        if (n == 0) break;
        init(n);
        cin >> m;
        for (int i=0;i<m;++i) {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool bicolor = 1;
        for (int i=0;i<n;++i) {
            if (Color[i] == -1) {
                Color[i] = 1;
                bicolor&= dfs(i);
            }
        }
        if (bicolor) {
            cout << "BICOLORABLE.\n";
        } else cout << "NOT BICOLORABLE.\n";
    }
}
