#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
void solve()
{
	ll n,k;
	cin >> n >> k;
	vector<ll>v(n);
	deque<int>dq(n);
	iota(dq.begin(),dq.end(),1);
	int l=0,r=k;
	while(r<n)
	{
		v[l] = dq.front();
		dq.pop_front();
		v[r] = dq.front();
		dq.pop_front();
		r+=2;l+=2;
	}
	l=n-1-k,r=n-1;
	if (v[n-1]) l--;
	// while(l>=0)
	// {
		// if (!v[l] && !v[r])
		// v[r] = dq.front();
		// dq.pop_front();
		// v[l] = dq.front();
		// dq.pop_front();
		// r-=
	// }
	for (auto i : v) cout << i << ' ';
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