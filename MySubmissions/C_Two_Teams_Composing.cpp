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

void solve()
{
	int n;
    cin >> n;
    map<int,int>mp;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    if (n==1) {
        cout << 0;
        return;
    }
    int mxe = 1;
    int dis=mp.size();
    for (auto i : mp) {
        if (i.se == 1) {
        }
        else mxe = max(mxe,i.se);
    }
    cout << max(min(dis,mxe-1),min(dis-1,mxe));
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