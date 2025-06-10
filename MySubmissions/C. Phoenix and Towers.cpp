#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
 
void solve()
{
	int n,m,x;
	cin >> n >> m >> x;
	set<pair<ll,int>>s;
	cout << "YES" << el;
	for (int i=0;i<m;++i)	s.insert({0,i});
	for (int i=0;i<n;++i)
	{
		int var; cin >> var;
		ll x=s.begin()->fi,y=s.begin()->se;
		s.erase(s.begin());
		cout << y+1 << ' ';
		s.insert({x+var,y});
	}
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