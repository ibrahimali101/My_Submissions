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
const int N = 1000;
int dp[N+9][N+9];
void solve()
{
	int n;
    cin >> n;
    vector<vector<char>>grid(n,vector<char>(n));
    for (auto &i : grid) for (auto &j : i) cin >> j;
    dp[0][0]=1;
    if (grid[0][0] == '*') return void(cout << 0);
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (grid[i][j] == '*' ||( i==0 && j==0)) continue;
            int op1 = i-1 > -1 ? dp[i-1][j] : 0;
            int op2 = j-1 > -1 ? dp[i][j-1] : 0;
            dp[i][j] = (op1+op2)%mod;
        }
    }
    cout << dp[n-1][n-1];
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