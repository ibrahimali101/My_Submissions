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

int grid[3][4] = {1,1,0,1,
                  1,1,1,1,
                  1,1,0,1};
bool vis[3][4];
int mark[3][4];
bool valid(int i,int j)
{
    return (i>=0&&j>=0&&i<3&&j<4&&!vis[i][j]&&grid[i][j] != 0);
}
int cnt = 0;
int dp[3][4]; 
int c_path(int i,int j)
{
    if (!valid(i,j)) return 0;
    if (i == 2 && j == 3) {
        mark[i][j] ++;
        return 1;
    }
    int& ret = dp[i][j];
    if (~ret ) return ret;
    ret =0;
    mark[i][j] ++;
    ret = max(ret,c_path(i+1,j) +c_path(i,j+1) );
    return ret;
}

void solve()
{
    clr(dp,-1);
    
    cout << c_path(0,0);
    for (int i=0;i<3;++i)
    {
        for (int j=0;j<4;++j) cout << mark[i][j] << ' ';
        cout << el;
    }
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