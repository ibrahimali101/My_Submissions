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
const ll mod = 1e9+7, OO = 0x3f3f3f3f, N = 1e3+5;
int n,m;
bool vis[N][N];
char grid[N][N];
pair<int,int> Human;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int Mon_dis[N][N];
int A_dis[N][N];

bool valid(int r,int c) {
    return (r>=0&&c>=0&&r<n&&c<m&&grid[r][c]!='#');
}

void BFS_Mon() {
    queue<pair<int,int>>q;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (grid[i][j] == 'M') {
                Mon_dis[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for (int i=0;i<4;++i) {
            int nR = node.fi+dx[i];
            int nC = node.se+dy[i];
            if (valid(nR,nC) && Mon_dis[nR][nC] == OO) {
                Mon_dis[nR][nC] = Mon_dis[node.fi][node.se]+1;
                q.push({nR,nC});
            }
        }
    }
}

pair<int,int> path[N][N];
pair<int,int>ex;
bool ok (int nR,int nC) {
if (nR == 0 || nC == 0 || nR == n-1 || nC == m-1) {
            ex = {nR,nC};
            return true;
        }
        return false;
}
bool BFS_A()
{
    queue<pair<int,int>>q;
    A_dis[Human.fi][Human.se] = 0;
    q.push({Human.fi,Human.se});
    if (ok(Human.fi,Human.se)) return true;
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for (int i=0;i<4;++i) {
            int nR = node.fi+dx[i];
            int nC = node.se+dy[i];
            if (valid(nR,nC) && A_dis[nR][nC] == OO && A_dis[node.fi][node.se]+1 < Mon_dis[nR][nC]) {
                path[nR][nC] = {node.fi,node.se};
                if (nR == 0 || nC == 0 || nR == n-1 || nC == m-1) {
                    ex = {nR,nC};
                    return true;
                }
                A_dis[nR][nC] = A_dis[node.fi][node.se]+1;
                q.push({nR,nC});
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') Human.fi = i,Human.se = j;
            A_dis[i][j] = OO;
            Mon_dis[i][j] = OO;
        }
    }
    BFS_Mon();
    int ddx[] = {0,0,-1,1};
    int ddy[] = {1,-1,0,0};
    char kk[] = {'L','R','D','U'};
    if(BFS_A()) {
        cout << "YES\n";
        pair<int,int> u;
        u = ex;
        int p = 0;
        string pa;
        while(u.fi || u.se) {
            p++;
            for (int i=0;i<4;++i) {
                int x = path[u.fi][u.se].fi - u.fi;
                int y = path[u.fi][u.se].se - u.se;
                if (x == ddx[i] && y == ddy[i]) pa+=kk[i];
            }
            u = {path[u.fi][u.se].fi,path[u.fi][u.se].se};
        }
        cout << max(0,p-1) << '\n';
        reverse(all(pa));
        cout << pa;
    }else cout << "NO";
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
