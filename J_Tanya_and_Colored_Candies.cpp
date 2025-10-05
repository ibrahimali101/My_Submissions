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
string str;
vector<int>v;
int dp[60][2009];
int n,s,k;

int dd(int i,int myk)
{
    if (myk >= k)
        return 0;
    if (i == n) return inf;
    int &ret = dp[i][myk];
    if (~ret) return ret;
    ret = 100002;
    for (int j=0;j<n;++j)
    {
        if (i!=j && v[j] > v[i] && str[j] != str[i])
            ret = min(ret, abs(i-j) + dd(j,myk+v[j]));
    }
    return ret;
}


void solve()
{
    clr(dp,-1);
    cin >> n >> s >>k;
    s--;
    v.resize(n);
    for (auto &i : v) cin >> i;
    cin >> str;
    int ans = 100002;
    for (int i=0;i<n;++i)
    {
        ans = min(ans, abs(s-i) + dd(i, v[i]) );
    }
    cout << (ans == 100002? -1 : ans);
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