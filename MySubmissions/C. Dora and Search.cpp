#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) (v.begin(),v.end())
using namespace std;
 
void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	input(v);
	multiset<int>s;
	for (auto i : v) s.insert(i);
	int l=0,r=n-1;
	while(l!=r)
	{
		if (v[l] != *s.begin() && v[r]!= *s.rbegin() && v[l] != *s.rbegin() && v[r] != *s.begin())
		{
			return void(cout << l+1 << ' ' << r+1);
		}
		else if (v[l] == *s.begin())
		{
			s.erase(*s.begin());
			l++;
		}
		else if (v[r] == *s.begin())
		{
			r--;
			s.erase(*s.begin());
		}
		else if (v[r] == *s.rbegin())
		{
			r--;
			s.erase(*s.rbegin());
		}
		else if (v[l] == *s.rbegin())
		{
			l++;
			s.erase(*s.rbegin());
		}
	}
	cout << -1;
	// output(v);
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