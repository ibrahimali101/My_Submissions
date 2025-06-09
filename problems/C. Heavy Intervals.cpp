#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
 
void solve()
{
	int n;
	cin >> n;
	vector<int>v,c(n);
	vector<pair<int,char>>inter;
	ll ans = LONG_LONG_MAX;
	int x;
	for (int i=0;i<n;++i)
	{
		cin >>x;
		inter.pb({x,'l'});
	}
	for (int i=0;i<n;++i)
	{
		cin >>x;
		inter.pb({x,'r'});
	}
	input(c);
	stack<pair<int,char>>st;
	sort(all(inter));
	for (int i=0;i<2*n;++i)
	{
		if (!st.empty() && inter[i].se == 'r' && st.top().se == 'l')
		{
			v.pb(inter[i].fi - st.top().fi);
			st.pop();
			continue;
		}
		if (inter[i].se == 'l')
		{
			st.push(inter[i]);
		}
	}
	sort(all(c));
	sort(rall(v));
	ll tow = 0;
	for (int i=0;i<n;++i)
	{
		tow+= (c[i]*v[i]);
	}
	cout << tow;
}
 
int main()
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