// Problem: Increasing Array
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1094
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	vector<ll>v(n);
	for (auto &i : v) cin >> i;
	ll cnt = 0 ;
	for (int i=1;i<n;++i)
	{
		if (v[i-1] > v[i]){
			cnt+=(v[i-1]-v[i]);
			v[i]+= (v[i-1] - v[i]);
		}
	}
	// for (auto i : v) cout << i << ' ';
	cout << cnt;
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
