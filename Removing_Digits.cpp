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
const int mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
const int MAX = 1e6;
int dp[MAX+9];

int rc(int i) {
    if (i == 0) return 0;
    if (i <= 9 && i >= 1) return 1;
    int var = i;
    if (~dp[i]) return dp[i];
    dp[i] = OO;
    while(var>0) {
        int x = var%10;
        var/=10;
        dp[i] = min(dp[i], 1 + rc(i-x));
    }
    return dp[i];
}

void solve()
{
    clr(dp,-1);
	int n;
    cin >> n;
    cout << rc(n);
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