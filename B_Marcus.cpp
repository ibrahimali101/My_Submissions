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
int n,m;
char grid[9][9];
bool vis[9][9];
bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<n&&j<m);
}
int dir[9][9];
string word = "IEHOVA";
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

pair<int,int> ex,Indiana;
void dfs(int i,int j,int bit) {
    vis[i][j] = true;
    for (int k=0;k<4;++k) {
        int nX = i + dx[k];
        int nY = j + dy[k];
        bool exist = false;
        if (!valid(nX,nY)) continue;
        for (int h = 0;h < 6; ++ h) {
            if (grid[nX][nY] == word[h])
            {
                exist = true;
                bit|=(1<<h);
                break;
            }
        }
        if (grid[nX][nY] == '#' && bit == 63) {
            dir[nX][nY] = k;
            return;
        }
        if (!vis[nX][nY] && exist) {
            dir[nX][nY] = k;
            dfs(nX,nY,bit);
        }
    }
}

void solve()
{
    cin >> n >> m;
    clr(vis,false);
    clr(dir,-1);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') ex = {i,j};
            if (grid[i][j] == '@') Indiana = {i,j};
        }
    }
    dfs(Indiana.fi,Indiana.se,0);
    int x = ex.fi,y = ex.se;
    string path;
    while(dir[x][y] != -1) {
        if (dir[x][y] == 1) path+="L",x += dx[2], y += dy[2];
        else if (dir[x][y] == 2) path+= "R", x+= dx[1], y+= dy[1];
        else path+= "F", x+= dx[0], y+= dy[0];
    }
    reverse(all(path));
    for (int i=0;i<path.size();++i) {
        if (path[i] == 'L') cout << "left";
        else if (path[i] == 'R') cout << "right";
        else cout << "forth";
        if (i != path.size()-1) cout << ' ';
    }
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
