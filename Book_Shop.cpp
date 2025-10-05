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
const int N = 1009, X = 1e5 + 9;
int dp[X];
void solve()
{
	int n,x;
    cin >> n >> x;
    vector<int>p(n+1),pa(n+1);
    for(int i=1;i<=n;++i) cin >> p[i];
    for(int i=1;i<=n;++i) cin >> pa[i];
    for (int j=1;j<=n;++j) {
        for (int i=x;i>=0;--i) {
            int op1 = dp[i];
            int op2 = i-p[j] > -1 ? dp[i-p[j]] + pa[j] : 0;
            dp[i] = max(op1,op2);
        }
    }
    cout << dp[x];
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