/*
                    وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ (39) وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ (40)
                     ثُمَّ يُجْزَاهُ الْجَزَاءَ الْأَوْفَىٰ (41) وَأَنَّ إِلَىٰ رَبِّكَ الْمُنتَهَىٰ (42) 
                       وَأَنَّهُ هُوَ أَضْحَكَ وَأَبْكَىٰ (43) وَأَنَّهُ هُوَ أَمَاتَ وَأَحْيَا (44)
*/


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
#define cceil(a,b) (a+b-1)/b
using namespace std;
 
void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int>v(n+1);
	for (int i=1;i<=n;++i) cin >> v[i];
	vector<int>v2 = v;
	sort(all(v2));
	multiset<int>s;
	ll sum = 0;
	for (int i=n-k+1;i<=n;++i) s.insert(v2[i]),sum+=v2[i];
	int left = 0;
	vector<int>pro;
	for (int i=1;i<=n && s.size() > 1;++i)
	{
		auto it = s.find(v[i]);
		if (it != s.end())
		{
			// if (i == n-1) pro.pb(i-left+(n-i)+1);
			pro.pb(i-left);
			s.erase(it);
			left = i;
		}
	}
	cout << sum << el;
	// pro.pb()
	for (auto i : pro) cout << i << ' ';
	cout << n-left;
	
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int tc = 1;
    // cin >> tc;R
    while(tc--)
    {
        solve();
        cout << el;
    }
}