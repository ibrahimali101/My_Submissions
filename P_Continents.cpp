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
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
const int N = 2e1 + 3;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int vis[N][N];
char grid[N][N];
int n,m;
pair<int,int> majid;
char land;

void init() {
    clr(vis,false);
}

bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<n&&j<m);
}
int n_lands = 0;
void dfs(int x,int y) {
    vis[x][y] = true;
    n_lands++;
    for (int i=0;i<4;++i) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if (nY == m) nY = 0;
        if (nY == -1) nY = m-1;
        if (nX == n) nY = 0;
        if (nX == -1) nY = n-1;
        if (valid(nX,nY) && !vis[nX][nY] && grid[nX][nY] == land) {
            dfs(nX,nY);
        }
    }
}

int main()
{
    ishowspeed
    while(cin >> n >> m)
    {
        init();
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                cin >> grid[i][j];
            }
        }
        cin >> majid.fi >> majid.se;
        land = grid[majid.fi][majid.se];
        int ans = 0;
        dfs(majid.fi,majid.se);
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                n_lands = 0;
                if (!vis[i][j] && grid[i][j] == land)  dfs(i,j);
                ans = max(ans, n_lands);
            }
        }
        cout << ans << el;
    }
}