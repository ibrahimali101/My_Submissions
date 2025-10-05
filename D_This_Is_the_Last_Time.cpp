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
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f3f;
ll memo[5009][5009][2];
int n;
vector<int>v;
ll rec(int l,int r,int p)
{
	if (l > r) return 0;
	ll &ret = memo[l][r][p];
	if (ret != -1e10) return ret;
	ll p1 = (p)*v[l] + rec(l+1,r,p^1);
	ll p2 = (p)*v[r] + rec(l,r-1,p^1);
	return ret = (p? max(p1,p2):min(p1,p2));
}
void solve()
{
	for (int i=0;i<5009;i++) {
        for (int j=0;j<5009;j++) {
            for (int k=0;k<2;++k)
                memo[i][j][k] = -1e10; 
        }
    }
	cin >> n;
	v.resize(n);
	for(auto &i : v) cin>>i;
	cout << rec(0,n-1,1);
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