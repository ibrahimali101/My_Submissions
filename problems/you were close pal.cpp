#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;


void solve()
{
	int n;
	cin >> n;
	vector<int>v1(n),v2(n);
	map<int,pair<int,int>>mp;
	map<int,int>m;
	multiset<int>v;
	// v2.resize(n);
	// v1.resize(n);
	// number and its indexes in both perms;
	for (int i=0;i<n;++i) cin >> v1[i],mp[v1[i]].fi = i;
	for (int i=0;i<n;++i) cin >> v2[i],mp[v2[i]].se = i;	
	int ans = 0;	
	// int cnt1 = 0,cnt2 =0;
	for (int i=0;i<n;++i)
	{
		if (mp[v1[i]].fi > mp[v1[i]].se) m[mp[v1[i]].fi - mp[v1[i]].se]++;
		else if (mp[v1[i]].se > mp[v1[i]].fi) m[n- mp[v1[i]].se + mp[v1[i]].fi]++;
		else m[0]++;
	}
	
	for (auto i : m)
	{
		ans = max(ans,i.se);
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