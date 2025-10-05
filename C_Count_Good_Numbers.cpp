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

ll l,r;
ll calc(ll x) {
    return r/x - (l-1)/x;
}

void solve()
{
    cin >> l >> r;
    ll ans=r-l+1;
    int arr[] = {2, 3, 5, 7};
    for (int i=1;i<(1<<4);++i) {
        int cc = __builtin_popcount(i);
        ll m = 1, ie;
        for (int j=0;j<4;++j) {
            if (1&(i>>j)) m*=arr[j];
        }
        ie = calc(m);
        if (cc&1) ans-=ie;
        else ans+=ie;
    }
    cout << ans;
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
