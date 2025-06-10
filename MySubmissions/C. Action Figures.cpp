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
	int n,k,q;
	cin >> n >> k >> q;
	vector<vector<int>>v(n,vector<int>(k));
	for (auto &i : v)
	{
		for (auto &j : i) cin >> j;
	}
	for (int i=0;i<k;++i)
	{
		for (int j=1;j<n;++j)
			v[j][i]|= v[j-1][i];
	}
	vector<vector<int>>v2(k,vector<int>(n));
	for (int i=0;i<k;++i)
	{
		for (int j=0;j<n;++j)
		{
			v2[i][j] = v[j][i];
		}
	}
	vector<pair<int,int>>int_;
	while(q--)
	{
		int m;
		cin >> m;
		int lp=0,rp=n-1;
		for (int i=0;i<m;++i)
		{
			int r,c;
			char o;
			// int it = 0;
			cin >> r >> o >> c;
			if (o == '<')
			{
				int le=-1,ri=n,md;
				while(le+1!=ri)
				{
					md = le + (ri-le)/2;
					if (v2[r-1][md] < c) le = md;
					else ri = md;
				}
				rp = min(rp,le);
			}
			else
			{
				int le=-1,ri=n,md;
				while(le+1!=ri)
				{
					md = le + (ri-le)/2;
					if (v2[r-1][md] <= c) le = md;
					else ri = md;
				}
				lp = max(ri,lp);
			}
		}
		if (lp<=rp) cout << lp+1 << el;
		else cout << -1 << el;
	}
	
	
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