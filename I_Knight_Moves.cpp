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
const int N = 1e1;
bool vis[N][N];
typedef pair<int,int> pa;

int k_dx[] = {1,-1,2,2,-2,-2,1,-1};
int k_dy[] = {2,2,1,-1,1,-1,-2,-2};
int level_[N][N] {0};
bool valid(int i,int j) {
    return (i>=0&&j>=0&&i<8&&j<8);
}
pa convert(string x)
{
    int a,b;
    a = 'h' - x[0];
    b = '8' - x[1];
    return {b,a};
}

pa loc,dest;
int bfs(int i,int j)
{
    int level = 1;
    queue<pa>q;
    q.push({i,j});
    vis[i][j] = true;
    level_[i][j] = 0;
    while(!q.empty()) {
        pa node = q.front();
        q.pop();
        for (int k=0;k<8;++k) {
            int nX = node.fi + k_dx[k];
            int nY = node.se + k_dy[k];
            if (valid(nX,nY) && !vis[nX][nY]) {
                // cerr << nX << ' ' << nY << el;
                vis[nX][nY] = true;
                level_[nX][nY] = level_[node.fi][node.se] + 1;
                if (dest == make_pair(nX,nY)) return level_[nX][nY];
                q.push({nX,nY});
            }
        }
    }
}

void solve()
{

}

int main()
{
    ishowspeed
    string a,b;
    while(cin >> a >> b)
    {
        clr(vis,false);
        clr(level_,0);
        loc = convert(a);
        dest = convert(b);
        if (a != b) bfs(loc.fi,loc.se);
        cout << "To get from " << a << " to "<<b <<" takes " << level_[dest.fi][dest.se]  << " knight moves." << el;
    }
}
