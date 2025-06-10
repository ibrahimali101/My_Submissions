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
	int n,o;
    cin >> n >> o;
    string s;
    cin >> s;
    vector<pair<int,int>>fr(26);
    for (int i=0;i<n;++i) {
        if (s[i] < 'a') {
            fr[s[i]-'A'].fi++;
        }
        else {
            fr[s[i]-'a'].se++;
        }
    }
    int p = 0;
    for (int i=0;i<26;++i) {
        if (fr[i].fi | fr[i].se) {
            if (fr[i].fi == fr[i].se || o==0) {
                p+= min(fr[i].fi,fr[i].se);
                continue;
            }
            int j = min(o,(fr[i].fi+fr[i].se)/2 - min(fr[i].fi,fr[i].se));
            o-= j; // my ops vs op to make it GOOD!
            p+= (j+min(fr[i].fi,fr[i].se));
        }
    }
    cout << p;
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