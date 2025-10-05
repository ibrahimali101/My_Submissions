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
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;

void solve()
{
	int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for (auto &i : v) cin >> i;
    vector<int>v2 = v;
    for (int i=1;i<n;++i) v[i]+=v[i-1];
    for (int i=n-2;i>=0;--i) v2[i]+=v2[i+1];
    auto it = upper_bound(all(v),k) - v.begin();
    reverse(all(v2));
    auto it2 = upper_bound(all(v2),k) - v2.begin();
    if (it2 < it) cout << "Yan";
    else if(it2 == it) cout << "Empate";
    else cout << "Nathan";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}