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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<bool>vis(n+1,1);
    if (n == m) return void(cout << 0);
    for (int i=1;i<=n&&m;i+=2) {
        int j = i%(n+1);
        vis[i] = 0;
        m--;
        if (!vis[(i+2)%(n)]) {
            i++;
        }
    }
    bool ok = false;
    int ans = 0;
    for (int i=1;i<=n;++i) {
        if (!vis[i] && ok == true) ans++,ok=false;
        if (vis[i]) ok=true;
    }
    if (ok) ans++;
    for (int i=1;i<=n;++i) cout << vis[i] << ' ';
    // cout << ans;
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
