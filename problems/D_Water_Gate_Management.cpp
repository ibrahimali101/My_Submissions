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
#define inf (1<<31)-1
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;
int n,m;
int tar,t;
vector<pair<int,int>>v;
vector<bool>vis;
int ans = 2e17;
void rc(int i)
{
    if (i == n) 
    {
        int sum = 0;
        int cs = 0;
        for (int i=0;i<n;++i)
        {
            if (vis[i]) cs+=v[i].se,sum+=(v[i].fi*t);
            if (sum >= tar) {
                ans = min(ans,cs);
            }
        }
        return ;
    }
    vis[i] = true;
    rc(i+1);
    vis[i]=false;
    rc(i+1);
}

void solve()
{
	cin >> n;
    vis.resize(n);
    v.resize(n);
    for (auto &i : v) cin >> i.fi >> i.se;
    cin >> m;
    for (int i=1;i<=m;++i)
    {
        cin >> tar >> t;
        ans=2e17;
        rc(0);
        cout << "Case " << i << ": ";
        if (ans!=2e17) cout << ans;
        else cout << "IMPOSSIBLE";
        if (i!=m) cout << el;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}