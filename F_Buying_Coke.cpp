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
int dp[809][409][80];
int n,n1,n2,n3;
int rc(int cola,int x,int y,int z) // 1 5 10
{
    if (cola == n) return 0;
    int&ret = dp[x][y][z];
    if (~ret) return ret;
    ret = 2e17;
    if (z > 0) ret = min(ret, 1 + rc(cola+1,x+2,y,z-1));
    if (z > 0 && x > 2)  ret = min(ret, 4 + rc(cola+1,x-3,y+1,z-1));
    if (y > 1) ret = min(ret, 2 + rc(cola+1,x+2,y-2,z));
    if (y > 0 && x > 2) ret = min(ret, 4 + rc(cola+1,x-3,y-1,z));
    if (x > 7) ret = min(ret, 8 + rc(cola+1,x-8,y,z));
    return ret;
}

void solve()
{
    clr(dp,-1);
	cin >> n >> n1 >> n2 >> n3;
    int ans = rc(0,n1,n2,n3);
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}