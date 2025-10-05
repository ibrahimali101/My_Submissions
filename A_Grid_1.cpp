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
int dp[1001][1001];
vector<vector<char>>grid;
vector<vector<bool>>vis;

bool valid(int i,int j)
{
    return (i>=0&&j>=0&&i<n&&j<m&&!vis[i][j]&&grid[i][j]=='.');
}

int c_path(int i,int j)
{
    if (i == n-1 && j == m-1) return 1;
    vis[i][j] = true;
    int &path = dp[i][j];
    if (~path) return path;
    path = 0;
    path = ((valid(i+1,j) ? c_path(i+1,j): 0)%mod + (valid(i,j+1)? c_path(i,j+1) : 0)%mod)%mod;
    vis[i][j] = false;
    return path;
}

void solve()
{
    clr(dp,-1);
	cin >> n >> m;
    grid = vector<vector<char>>(n,vector<char>(m));
    vis = vector<vector<bool>>(n,vector<bool>(m));
    for (auto &i : grid) {
        for (auto &j : i) cin >> j;
    }
    cout << c_path(0,0);
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