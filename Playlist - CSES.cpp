// Problem: Playlist
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1141
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
 
void solve()
{
	int n,w;
	cin >> n >> w;
	vector<int>v(n);
	input(v);
	sort(rall(v));
	ll g=0,s=0,c=0;
	// vector<int>v;
	for (int i=0;i<n;++i)
	{
		if (s+v[i] > w || c+1 > 2) g++,s=0,c=0;
		s+=v[i];
		c++;
	}
	if (s > 0) g++;
	cout << g;
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
