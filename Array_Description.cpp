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
int n,u;
const int MAX = 1e5;
ll dp[102][MAX+9];
// ll rc(int i,int prv) {
//     if (i == n) return 1;
//     ll &ret = dp[prv][i];
//     if (~ret) return ret;
//     ret = 0;
//     if (!v[i]) {
//         if (prv > 1) ret+= rc(i+1,prv-1);
//         if (prv < u) ret = (ret%mod + rc(i+1,prv+1)%mod)%mod;
//         ret = (ret%mod + rc(i+1,prv)%mod)%mod ;
//     }
//     else {
//         if (abs(v[i]-prv) <= 1) ret = rc(i+1,v[i]);
//     }
//     return ret;
// }

void solve()
{
    // clr(dp,-1);
    cin >> n >> u;
    vector<int>v(n+2);
    for (int i=1;i<=n;++i) cin >> v[i];
    if (v[1]) dp[v[1]][1] = 1;
    else {
        for (int i=1;i<=u;++i) dp[i][1] = 1;
    }
    for (int i=2;i<=n;++i) {
        if (v[i]) {
            dp[v[i]][i] = (dp[v[i]][i]%mod +  dp[v[i]][i-1]%mod)%mod;
            if (v[i] > 1)
                dp[v[i]][i] = (dp[v[i]][i]%mod + dp[v[i]-1][i-1]%mod)%mod;
            if (v[i] < u)
                dp[v[i]][i] = (dp[v[i]][i]%mod + dp[v[i]+1][i-1]%mod)%mod;
        }
        else{
            for (int j=1;j<=u;++j) {
                dp[j][i] = (dp[j][i]%mod +  dp[j][i-1]%mod)%mod;
                if (j > 1)
                dp[j][i] = (dp[j][i]%mod + dp[j-1][i-1]%mod)%mod;
                if (j < u)
                dp[j][i] = (dp[j][i]%mod + dp[j+1][i-1]%mod)%mod;
            }
        }
    }
    ll ans = 0;
    for (int j=1;j<=u;++j)
        ans =( ans%mod + dp[j][n]%mod)%mod;
    cout << ans;
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
