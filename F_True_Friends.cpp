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
const int N = 1e2+4;
char grid[N][N];
vector<int> adj[N];
stack<int>stk;
int dfn[N],lowlink[N];
int cnt = 0;
bool inStack[N];
int ndfn = 1;
void tarjan(int node) {
    dfn[node] = lowlink[node] = ndfn++;
    stk.push(node);
    inStack[node] = 1;
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
        cnt++;
        int x = -1;
        while(x!=node) {
            x = stk.top(), stk.pop(), inStack[x] = 0;
        }
    }
}

void init(int n) {
    for (int i=1;i<=n;++i) {
        adj[i].clear();
    }
    stk = stack<int>();
    clr(dfn,-1);
    clr(lowlink,0);
    ndfn = 1;
    clr(inStack,false);
    cnt = 0;
}


void solve()
{
    int n;
    cin >> n;
    init(n);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'Y') {
                adj[i].pb(j);
            }
        }
    }
    for (int i=1;i<=n;++i) {
        if (dfn[i] == -1) tarjan(i);
    }
    cout << cnt;
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
