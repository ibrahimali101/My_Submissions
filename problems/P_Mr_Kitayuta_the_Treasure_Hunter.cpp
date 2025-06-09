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
int gem[30001] {};
int dp[30001][250*2];
int n,d;
int rc(int i,int jp)
{
    int prv = jp-(d-250);
    if (i >= 30001) return 0;
    int &ret = dp[i][prv];
    if (~ret) return ret;
    ret = 0;
    if (jp == 1) {
        ret = gem[i] + max(rc(i+jp, jp), rc(i+jp+1, jp+1));
    } else {
        ret = gem[i] + max(max(rc(i+jp-1, jp-1), rc(i+jp, jp)), rc(i+jp+1, jp+1));
    }
    return ret;
}
void solve()
{
	clr(dp,-1);
    cin >> n >> d;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        gem[x]++;
    }
    int ans = 0;
    ans += rc(d,d);
    cout << ans;
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