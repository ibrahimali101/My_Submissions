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
#define inf (1LL<<31)-1
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;

void solve()
{
    int n,c;
    cin >> n >> c;
    vector<pair<int,int>>vp;
    for(int i=1;i<=n;++i)
    {
        int x = 0;
        cin >> x;
        vp.pb({x,i});
    }
    sort(all(vp),[](auto &left,auto &right)
    {
        return left.fi+left.se < right.fi+right.se;
    });
    int sum = 0,cnt=0;
    for(auto i : vp)
    {
        if (sum+i.fi+i.se <= c) sum = sum + i.fi + i.se , cnt++;
        else break;
    }
    cout << cnt;
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