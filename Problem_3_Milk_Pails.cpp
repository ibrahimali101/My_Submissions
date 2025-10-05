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
int X,Y,K,M;
const int N = 1e2+5;
int dp[N][N][N];
int try_(int p1,int p2,int k) {
    if (k==0) return abs(M - (p1+p2));
    int &ret = dp[p1][p2][k];
    if (~ret) return ret;
    ret = 103;
    ret = min(ret, try_(X,p2,k-1));
    ret = min(ret, try_(p1,Y,k-1));
    ret = min(ret, try_(0,p2,k-1));
    ret = min(ret, try_(p1,0,k-1));
    ret = min(ret, try_(p1 - min(p1, Y-p2), p2 + min(p1, Y-p2), k-1));
    ret = min(ret, try_(p1 + min(p2, X-p1), p2 - min(p2, X-p1), k-1));
    return ret;
}
void solve()
{
    clr(dp,-1);
    // freopen("pails.in", "r", stdin);
    // freopen("pails.out", "w", stdout);
    cin >> X >> Y >> K >> M;
    cout << try_(0,0,K);
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
