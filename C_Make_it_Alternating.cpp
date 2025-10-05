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
const ll mod = 998244353, OO = 0x3f3f3f3f3f3f3f;
int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1LL)
            res = res * a%mod;
        a = a * a%mod;
        b >>= 1LL;
    }
    return res;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans1 = 0, ans2 = 1;
    char x = '?';
    int len = 1;
    int k=n;
    for (int i=0;i<n;++i) {
        if (x != s[i]) {
            k--;
            ans2 = (ans2%mod * len%mod)%mod;
            len=1;
            x = s[i];
        }
        else {
            len ++;
        }
    }
    ans2 = (ans2%mod * len%mod)%mod;
    for (int i=1;i<=k;++i)
        ans2 = (ans2%mod * i%mod)%mod;
    cout << k << ' ' << ans2;
    
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
