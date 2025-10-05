#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
 
void solve()
{
	int n,k;
	cin >> n >> k;
	vector<pair<int,bool>>v(n);
	set<int>s;
	int ts=0;
	vector<int>ans;
	for (auto &i : v){
		cin >> i.fi;
		if (s.count(i.fi))
			ts++;
		else ans.pb(i.fi);
		s.insert(i.fi);
	}
	// for (auto i : ans) cout << i << ' ';
	if (s.size() > k) return void(cout << -1);
	else
	{
		while (ans.size() < k)
		{
			ans.pb(20);
		}
		cout << n*k << el;
		for (int i=0;i<n;++i)
		{
			for (auto i : ans) cout << i << ' ';
		}
		// for (auto i : ans) cout << i << ' ';
	/*
	6 4
	5 6 5 3 4 6
	s = 5 6 3 4
	5 6 5 3 4 6
	t t f t t f
	true = available
	false = unavailable
	*/
		// for (auto i : v) cout << i.fi << ' ';
		// cout << el;
		// for (auto i : v ) cout << i.se << ' ';
		// int e = 0;
		// while(ts!=0)
		// {
			// bool fg=true;
			// for (int i=0;i<n;++i)
			// {
				// if (!v[i].se) continue;
				// if (v[i].fi == v[e%k].fi)
				// {
					// v[i].se = false;
					// ts--;
				// }
				// ans.pb(v[e%k].fi);
				// break;
			// }
			// e++;
		// }
		
	}
	// cout << el;
	// cout << "RES:" << el;
	// for (auto i : ans) cout << i << ' ';
	// cout << "EXP" << el;
	// cout << "1 2 1 2 1";
	
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