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
    int s[32]{0};
    for (int i=0;i<31;++i) {
        if (n & (1<<i)) s[i] = 1;
    }
    int f=-1,l=-1;
    int arr[32]{0};
    for (int i=0;i<30;++i) {
        if (s[i] == 1){
            if (f==-1) f=i;
            l = i;
        }else {
            if (f != l) {
                arr[i] = 1;
                arr[f] = -1;
                s[i] = 1;
                i--;
            }
            else if (f == l && s[f] == 1) {
                arr[f] =1; 
            }
            f=-1,l=-1;
        }
    }
    // arr[f] = 1;
    // arr[l] = -1;
    cout << 31 << '\n';
    for (int i=0;i<31;++i) 
        cout << arr[i] << ' ';
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