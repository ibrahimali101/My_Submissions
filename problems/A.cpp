#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define clr(v,d) memset(v,d,sizeof(v));
using namespace std;
 ll n,s;
void solve()
{
	// cin >> n >> m;
	// vector<ll>a(n);
	cin >> n >> s;
	vector<ll>v(n);
	for (auto &i : v) cin >> i;
	ll sum = 0,ans=0,l=0;
	for (int r=0;r<n;++r)
	{
		sum+= v[r];
		while(sum >= s) sum-=v[l],l++;
		ans += l;
	}
	cout << ans;
}
 
int main()
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