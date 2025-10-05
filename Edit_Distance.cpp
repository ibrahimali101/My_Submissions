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
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f, MAX = 5009, OOI = 0x3f3f3f3f;
int n,m;
string a,b;
int dp[MAX][MAX];
int rc(int i, int j) {
    if (i == n && j == m) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = OOI;
    if (a[i] != b[j]) {
        ret = min(ret, 1 + rc(i+1,j+1));
        ret = min(ret, 1 + rc(i,j+1));
        ret = min(ret, 1 + rc(i+1,j));
    }
    else ret = rc(i+1,j+1);
    return ret;
}
 
void solve()
{
    // clr(dp,-1);
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = '#' + a;
    b = '#' + b;
    for (int i=0;i<=n;++i)  {
        for (int j=0;j<=m;++j) {
            if ((i == 0 || j == 0) && i < n && j < m) dp[i][j] = i+j;
            else dp[i][j] = OOI;
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            int& ret = dp[i][j];
            ret = min(ret, (a[i] != b[j]) + dp[(i-1)][j-1]);
            ret = min(ret, 1 + dp[i][j-1]);
            ret = min(ret, 1 + dp[(i-1)][j]);
        }
    }
    for (int i=0;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            cout << dp[i][j] << ' ';
        }
        cout << el;
    }
    // cout << dp[n][m];
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