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
const ll mod = 1e9+7, OO = 0x3f3f3f3f;
int n,m;

vector<vector<char>> grid;
vector<vector<int>> dp;

bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<n&&j<m);
}

int rc(int i,int j, bool p)
{
    if (i == n-1 && j == m-1) return 0;
    int &ret = dp[i][j];
    if (~ret) return ret;
    ret = OO;
    if (valid(i,j+1)) {
        if (p)
            ret = min(ret, (grid[i][j+1] == '#') + rc(i,j+1,1));
        else
            if (grid[i][j+1] == '.') ret = min(ret, rc(i,j+1,1));
    }
    if (valid(i+1,j)) {
        if (!p)
            ret = min(ret, (grid[i+1][j] == '#') + rc(i+1,j,0));
        else
            if (grid[i+1][j] == '.') ret = min(ret, rc(i+1,j,0));
    }
    return ret;
}

void solve()
{
    cin >> n >> m;
    grid.clear();
    dp.clear();
    grid.resize(n,vector<char>(m));
    dp.resize(n+9,vector<int>(m+9));
    for (auto &i : grid) {
        for (char &j : i) cin >> j;
    }
    int st1 = rc(0,0,0);
    int st2 = rc(0,0,1);
    if (valid(1,0) && grid[1][0] == '#') st1 = OO;
    if (valid(0,1) && grid[0][1] == '#') st2 = OO;
    cout << (st1==OO&&st2==OO? -1 : min(st1,st2));
}

int main()
{
    ishowspeed
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
