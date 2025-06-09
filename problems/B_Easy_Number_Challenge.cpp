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
const int mod = 1073741824;
int a,b,c;
int n_prime(int N)
{
    int cnt=0,x=0;
    if (N==1) return 1;
    if (N%2==0) x++;
    while(N%2==0) N/=2, cnt++; 
    for (int i=3;i<=N/i;i+=2)
    {
        if (N%i==0) x++;
        while (N % i == 0)
        {
            cnt++;
            N /= i;
        }
    }
    if (N > 2) x++;
    return cnt+x;
}


void solve()
{
    cin >> a >> b >> c;
    int cnt = 0;
    cout << n_prime(3424) << el;
    for (int i=1;i<=a;++i)
    {
        for (int j=1;j<=b;j++)
        {
            for (int k=1;k<=c;++k)
            {
                cnt = (cnt%mod + n_prime(i*j*k)%mod)%mod;
            }
        }
    }
    cout << cnt;
}

signed main()
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