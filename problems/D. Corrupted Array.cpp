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
	vector<ll>v(n+2);
	ll sum = 0;
	for (auto &i : v) cin >> i,sum+=i;
	sort(v.begin(),v.end());
	int arr[2] = {v[n],v[n+1]};
	sum-=arr[0],sum-=arr[1];
	vector<int>ans;
	bool fg1=false,fg2=false;
	fg1 = (sum == arr[0]);
	fg2 = (sum == arr[1]);
	if (fg1 || fg2)
	{
		for (int i=0;i<n;++i)	cout << v[i] << ' ';
		return;
	}
	for (int i=0;i<n;++i)
	{
		if (sum-v[i]+arr[0] == arr[1] && !fg2)
		{
			fg2 = true;
			continue;
		}
		ans.pb(v[i]);
	}
	// if (!fg2)	fg2 |= (sum+arr[0] == arr[1]);
	if (fg2)
	{
		for (auto i : ans) cout << i << ' ';
		cout << arr[0];
	}
	else cout << -1;
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