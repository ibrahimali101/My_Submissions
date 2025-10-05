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
    string s;
    cin >> s;
    string temp=s;
    sort(all(temp));
    if (k%2==0) {
        cout << temp;
        return;
    } 
    string s1,s2;
    for (int i=0;i<n;++i) {
        if (i%2==0) s1+=s[i];
        else s2+=s[i];
    }
    sort(all(s1));
    sort(all(s2));
    for(int i=0,j=0;i<s1.size()||j<s2.size();) {
        if (i < s1.size()) cout << s1[i],i++;
        if (j < s2.size()) cout << s2[j],j++;
    }
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