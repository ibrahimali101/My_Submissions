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

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<ll>v(n),p(n,-1);
    ll sum = 0;
    for (auto &i : v) cin >> i,sum+=i;
    ll vv = -1;
    ll var = 0;
    ll y,z;
    for (int i=0;i<q;++i) {
        ll x;
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            y--;
            if (p[y] < vv) sum-=var;
            else sum-=v[y];
            sum+=z;
            v[y] = z;
            p[y] = i;
        }
        else {
            cin >> var;
            sum = var*n;
            vv = i;
        }
        cout << sum << '\n';
    }
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
