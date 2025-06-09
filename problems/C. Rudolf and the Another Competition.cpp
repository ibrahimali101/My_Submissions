#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
using namespace std;
 
void solve()
{
	int n,m,h;
	cin >> n >> m >> h;
	vector<vector<int>>v(n,vector<int>(m));
	for (auto &i : v)
	{
		for (auto &j : i) cin >> j;
	}
	vector<pair<int,pair<int,int>>>s;
	for (int i=0;i<n;++i)
	{
		sort(all(v[i]));
		int pena = 0;
		int p = 0;
		int time = 0;
		int j;
		for (j=0;j<m;++j)
		{
			if (v[i][j] + time <= h) time+=v[i][j],v[i][j]+=(j? v[i][j-1]:0),p++;
			else break;
		}
		for (int k=0;k<j;++k) pena+=v[i][k];
		s.pb({p,{pena,i+1}});
	}
	sort(s.begin(),s.end(),[](auto &left,auto &right)
	{
		if (left.fi == right.fi)
		{
			if (left.se.fi == right.se.fi) 
			{
				return left.se.se < right.se.se;
			}
			return left.se.fi <= right.se.fi;
		}		
		return left.fi > right.fi;
	});
	int x = 0;
	for (auto i : s)
	{
		if (i.se.se == 1) break;
		x++;
	}
	cout << x+1;
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