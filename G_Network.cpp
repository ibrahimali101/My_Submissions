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
const int N = 1e2+3;
int lowlink[N],dfn[N];
set<int> art;
vector<int>adj[N];
int ndfn = 1;

void init(int n) {
    for (int i=1;i<=n;++i) {
        adj[i].clear();
    }
    clr(lowlink,0);
    clr(dfn,-1);
    ndfn = 1;
    art.clear();
}

void tarjan(int node,int par) {
    lowlink[node] = dfn[node] = ndfn++;
    int child = 0;
    for (auto j : adj[node]) {
        if (dfn[j] == -1) {
            tarjan(j,node);
            child++;
            lowlink[node] = min(lowlink[node], lowlink[j]);
            if (par != -1 && lowlink[j] >= dfn[node]) {
                art.insert(node);
            }
        }
        else if (node != j){
            lowlink[node] = min(lowlink[node], dfn[j]);
        }
    }
    if (par == -1 && child > 1) art.insert(node);
}

int main()
{
    ishowspeed
    bool fg = 0;
    int n;
    while(cin >> n)
    {
        if (n == 0) {
            break;
        }
        string st;
        init(n);
        while(getline(cin,st) && st != "0") {
            stringstream ss(st);
            int x;
            int node = -1;
            while(ss >> x) {
                if (node == -1) {
                    node = x;
                    continue;
                }
                adj[node].pb(x);
                adj[x].pb(node);
            }
        }
        for (int i=1;i<=n;++i) {
            if (dfn[i] == -1) tarjan(i,-1);
        }
        cout << art.size() << el;
    }
}
