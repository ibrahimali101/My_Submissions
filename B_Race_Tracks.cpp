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
#define clr(v,d) memset(v,d,sizeof(v))
#define cceil(a,b) (a+b-1)/b
#define fix(a,b) (a%b+b)%b
#define ishowspeed ios_base::sync_with_stdio(false);    cin.tie();    cout.tie();
using int64 = ll;
using namespace std;
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
const int N = 3e1 + 6;
int n,m,p;
pair<int,int> st,en;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int spx[] = {1,0,-1};
int spy[] = {1,0,-1};
array<int,4> Obst[N];
bool vis[N][N][7][7];
int Dis[N][N][7][7];
bool valid(int i,int j)
{
    return (i>=0&&j>=0&&i<n&&j<m);
}

bool exist(int x,int y) {
    for (int i=0;i<p;++i) {
        if (Obst[i][2] <= y && Obst[i][3] >= y && Obst[i][0] <= x && Obst[i][1] >= x) {
            return true;
        }
    }
    return false;
}
bool valids(int i,int j) {
    return (i>=-3&&j>=-3&&i<=3&&j<=3);
}

int bfs() {
    queue<array<int,4>>q; 
    array<int,4> start = {st.fi,st.se,0,0};
    q.push(start);
    vis[start[0]][start[1]][3][3] = true;
    if (st.fi == en.fi && st.se == en.se) return 0;
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int x=0;x<3;++x) {
            for(int y=0;y<3;++y) {
                if (!valids(node[2]+spx[x],node[3]+spy[y])) continue;
                int nX = node[0]+(node[2]+spx[x]);
                int nY = node[1]+(node[3]+spy[y]);
                if (valid(nX,nY) && !vis[nX][nY][node[2]+spx[x]+3][node[3]+spy[y]+3] && !exist(nX,nY)) {
                    vis[nX][nY][node[2]+spx[x]+3][node[3]+spy[y]+3] = true;
                    Dis[nX][nY][node[2]+spx[x]+3][node[3]+spy[y]+3] = Dis[node[0]][node[1]][node[2]+3][node[3]+3] + 1;
                    if (nX == en.fi && nY == en.se) return Dis[nX][nY][node[2]+spx[x]+3][node[3]+spy[y]+3]; // remember to test make_pair and make_pair too!
                    q.push({nX,nY,node[2]+spx[x],node[3]+spy[y]});
                }
            }
        }
    }
    return -1;
}

void solve()
{
    clr(vis,false);
    clr(Dis,0);
    cin >> n >> m;
    cin >> st.fi >> st.se >> en.fi >> en.se;
    cin >> p;
    for (int i=0;i<p;++i) {
        int p1,p2,p3,p4;
        cin >> p1 >> p2 >> p3 >> p4;
        Obst[i] = {p1,p2,p3,p4};
    }
    int ans = bfs();
    if (ans == -1) cout << "No solution.";
    else cout << "Optimal solution takes " << ans << " hops.";
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
