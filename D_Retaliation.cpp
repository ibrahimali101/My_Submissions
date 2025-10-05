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

void solve()
{
    int n;
    cin >> n;
    vector<ll>v(n);
    for (auto &i : v) cin >> i;
    int diff = v[1]-v[0];
    set<int>s;
    for (int i=1;i<=n;++i) {
        v[i-1] -= abs(diff)*(diff < 0 ? n-i+1 : i);
        if (v[i-1] < 0 || v[i-1]%(n+1)) return void (cout << "NO");
        s.insert(v[i-1]);
    }
    if (s.size() == 1) cout << "YES";
    else cout << "NO";
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
