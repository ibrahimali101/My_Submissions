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
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f, K = 1e6;
int n,k;
int dp[101][K+2];


void solve()
{
    cin >> n >> k;
	vector<int>v(n+1);
    for (int i=1;i<=n;++i) cin >> v[i];
    for (int i=0;i<=n;++i) dp[i][0] = 1;
    for (int i=1;i<=k;++i) {
        for (int j=1;j<=n;++j) {
            int op1 = i-v[j] >= 0 ? dp[j][i - v[j]] : 0;
            int op2 = dp[j - 1][i]; 
            dp[j][i] = (op1+op2)%mod;
        }
    }
    cout << dp[n][k];
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