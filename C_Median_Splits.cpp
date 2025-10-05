// Good. That's one less loose end.
#include <bits/stdc++.h>
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define watch(x) cerr << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << "\n"
#define ll long long
#define input(v) for(auto&i : v) cin >> i;
#define output(v) for(auto i : v) cout << i << ' ';
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define clr(v,d) memset(v,d,sizeof(v));
#define cceil(a,b) (a+b-1)/b
#define inf (1<<31)-1
#define int ll
#define fix(a,b) (a%b+b)%b
using namespace std;
const int mod = 1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
	vector<int>a(n),b(n);
    for (auto &i : a) cin >> i;
    for (int i=0;i<n;++i) {
        if (a[i] <= k) b[i]=1;
        else b[i]=-1;
    }
    bool ans = 0;
    vector<int>s = b;
    int x=-1,z=-1;
    for (int i=1;i<n;++i) {
        b[i] += b[i-1];
    } // cheking on prefixes
        
    for (int i=n-2;i>=0;--i) {
        s[i] += s[i+1];
    } // suffixes
    set<int,greater<>>ss;
	for (int i=n-1;i>=0;--i) {
		if (s[i] >= 0) ss.insert(i);
        if (z == -1 && s[i] > -1) z = i; 
    }
    set<int>p;
    for (int i=0;i<n;++i) {
    	if (b[i] >=0) p.insert(i);
        if (x == -1 && b[i] > -1) x = i; 
    }
    int mn = inf;
    for (auto i : p)
    {
    	// if (i == n-1) continue;
    	if (b[i] >= mn) {
    		ans = 1;
    		break;
    	}
    	mn = min(mn,b[i]); 
    }
    mn = inf;
    for (auto i : ss)
    {
    	// if (i == 0) continue;
    	if (s[i] >= mn){
    		ans = 1;
    		break;
    	}
    	mn = min(mn,s[i]);
    }
    if (~x && ~z && x < z) ans = 1;
    cout << (ans? "YES" : "NO");
    
}

signed main()
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