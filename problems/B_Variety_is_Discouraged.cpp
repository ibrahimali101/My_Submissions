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
	int n;
    cin >> n;
    vector<int>v(n);
    map<int,int>frq;
    int d = 0;
    for (auto &i : v)
    {
        cin >> i;
        if (!frq[i]) d++;
        frq[i]++;
    }
    int mxs = n-d;
    int mnl = n;
    int l=0,r=0,lx=-1,rx=-1;
    int k=d;
    while(r < n){
        while(r < n && frq[v[r]] == 1)
        {
            k--;
            r++;
            int s = (n-(r-l))-k;
            if (mxs <= s) {
                if (mnl > (n-(r-l))) {
                    lx = l;
                    rx = r-1;
                    mnl = (n-(r-l));
                    mxs = s;
                }
            }
        }
        l = r;
        l++;
        r++;
        k = d;
    }
    if (lx == -1 && rx == -1) {
        cout << 0;
    }else 
    cout << lx+1 << ' ' << rx+1;
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