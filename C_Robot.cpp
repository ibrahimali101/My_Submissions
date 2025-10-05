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
#define pa pair<int,int>
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;
const int N = 5e1+5;
int n,m;
int grid[N][N];
int Dis[N][N][4];
int dx[] = {0,1,0,-1}; // east, south, west, north
int dy[] = {1,0,-1,0};
int dir=-1;
pa st,en;

bool valid(int i,int j,int k=0) {
    if (k==2) return true;
    return(i>=0&&j>=0&&i<n&&j<m&&(grid[i][j] != 1)&&valid(i-1,j,k+1)&&valid(i,j-1,k+1)&&valid(i-1,j-1,k+1));
}

int bfs() {
    queue<array<int,3>>q; // x,y,dir
    q.push({st.fi,st.se,dir});
    Dis[st.fi][st.se][dir] = 0;
    while(!q.empty()) {
        auto node = q.front();
        if (node[0] == en.fi && node[1] == en.se) return Dis[node[0]][node[1]][node[2]];
        q.pop();
        for (int k=0;k<4;++k) {
            if (node[2] != k) continue;
            for (int i=1;i<=3;++i) {
                int nX = node[0] + (dx[k]*i);
                int nY = node[1] + (dy[k]*i);
                if (!valid(nX,nY)) break;
                if (valid(nX,nY) && Dis[nX][nY][node[2]] == -1) {
                    Dis[nX][nY][node[2]] = Dis[node[0]][node[1]][node[2]]+1;
                    q.push({nX,nY,node[2]});
                }
            }
        }
        if (Dis[node[0]][node[1]][(node[2]+1)%4] == -1) {
            Dis[node[0]][node[1]][(node[2]+1)%4] = Dis[node[0]][node[1]][node[2]]+1;
            q.push({node[0],node[1],(node[2]+1)%4});
        }
        if (Dis[node[0]][node[1]][fix(node[2]-1,4)] == -1) {
            Dis[node[0]][node[1]][fix(node[2]-1,4)] = Dis[node[0]][node[1]][node[2]]+1;
            q.push({node[0],node[1],fix(node[2]-1,4)});
        }
    }
    return -1;
}   

int main()
{
    ishowspeed
    while(cin >> n >> m && (n || m))
    {
        clr(Dis,-1);
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) {
                cin >> grid[i][j];
            }
        }
        string di;
        cin >> st.fi >> st.se >> en.fi >> en.se >> di;
        if (di == "south") dir = 1;
        else if (di == "north") dir = 3;
        else if (di == "east") dir = 0;
        else dir = 2;
        cout << bfs() << el;
    }
}
