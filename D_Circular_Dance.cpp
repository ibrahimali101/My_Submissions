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
int n;
int edge[N][2];
bool try_(int prev,int cur)  {
    vector<int>v;
    for (int i=0;i<n;++i){
        int nxt = -1;
        if (edge[prev][0] == cur) nxt = edge[prev][1];
        else if (edge[prev][1] == cur) nxt = edge[prev][0];
        else return false;
        prev = cur;
        cur = nxt;
        v.pb(nxt);
    }
    for (int i=0;i<n;++i) cout << v[i] << ' ';
    return true;
}

void solve()
{
    cin >> n;
    for (int i=1;i<=n;++i) {
        int u,v;
        cin >> u >> v;
        edge[i][0] = u;
        edge[i][1] = v;
    }
    bool ping = try_(1, edge[1][0]);
    if (!ping)
        try_(1, edge[1][1]);
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
