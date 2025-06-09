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
    string ss;
    cin >> ss;
    string s = "#" + ss;
    vector<int>v(n+1);
    int cnt=0;
	for (int i=1;i<=n;++i)
    {
        if (s[i] == '1' && v[i] == 0) continue;
        for (int j=i;j<=n;j+=i)
        {
            if (s[j] == '0') s[j]='1',v[j]=i;
            else if (s[j] == '1' && v[j] == 0) break;
        }
    }
    for (auto i : v) cnt+=i;
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