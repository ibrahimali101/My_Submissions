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
// #define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;
const int MAX = 1e6;
int dp[109][100];
int n;
vector<int>v;
int kk(int i,int sum)
{
    if (sum == 0) return 0;
    if (i == n || sum < 0) return inf;
    int& x = dp[i][sum];
    if (~x) return x;
    x = 1 + min({kk(i,sum-v[i]),kk(i+1,sum-v[i]),kk(i+1,sum)});
    return x;
}


void solve()
{
    clr(dp,-1);
    int c;
	cin >> n >> c;
    v.resize(n);
    for (auto &i : v) cin >> i;
    cout << kk(0,c);
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