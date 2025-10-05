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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll x=0,y=0;
    ll cnta=0,cntb=0;
    pair<ll,ll> b = {0,n},a = {0,n};
    for (int i=0;i<n;++i) {
        if (s[i] == 'b') {
            if (b.fi == 0 && s[0] != 'b') b.fi = i;
            b.se = i;
            cntb++;
        }
        else {
            if (a.fi == 0 && s[0] != 'a') a.fi = i;
            a.se = i;
            cnta++;
        }
    }
    ll ans1 = 0;
    ll cnt_ = 0;
    for (int i=b.fi;i<=b.se;++i) {
        if (s[i] == 'a') {
            ans1+= min(cnt_,cntb - cnt_);
        }
        else cnt_++;
    }
    cnt_ = 0;
    ll ans2=0;
    for (int i=a.fi;i<=a.se;++i) {
        if (s[i] == 'b') {
            ans2+= min(cnt_,cnta - cnt_);
        }
        else cnt_++;
    }
    cout << min(ans2,ans1);
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
