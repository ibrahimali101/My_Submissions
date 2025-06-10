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
    string s;
    cin >> s;
    int n = s.size();
    int f0=-1, f1=-1; 
	for (int j=n-1,i=0;j>=0,i<n;++i,--j)
    {
        if (s[i] == '1' && f1 == -1) f1 = i;
        if (s[j] == '0' && f0 == -1) f0 = j;
    }
    if (f1 == -1 || f0 == -1) return void(cout << 0);
    int cnt=0;
    int ans = 0;
    for (int i=f1;i<=f0;++i) {
        if (s[i] == '1') cnt++;
        else ans+= (cnt+1);
    }
    cout << ans;
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