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
#define fix(a,b) (a%b+b)%b
#define ishowspeed ios_base::sync_with_stdio(false);    cin.tie();    cout.tie();
using int64 = ll;
using namespace std;
const ll mod = 1e9+7,MAX = 1e5+9, OO = 0x3f3f3f3f3f3f3f;
string s;
int n;
int dp[MAX][10];
int rc(int i,int sum) {
    if (i == n) return sum == 0;
    int &ret = dp[i][sum];
    if (~ret) return ret;
    ret = 0;
    int x = s[i]-'0';
    if (x == 3) ret = rc(i+1,fix(sum+3,9)) || rc(i+1,fix(sum+9,9));
    else if (x == 2) ret = rc(i+1,fix(sum+2,9)) || rc(i+1,fix(sum+4,9));
    else ret = rc(i+1,fix(sum+x,9));
    return ret;
}
void solve()
{
    cin >> s;
    n = s.size();
    dp[0][(s[0]-'0')%9] = 1;
    for (int i=1;i<n;++i){
        int x = s[i]-'0';
        if (x == 3) dp[i+1][3]=1;
        else if (x==2) dp[i+1]
    }
    if (rc(0,0)) cout << "YES";
    else cout << "NO";
}

int main()
{
    ishowspeed
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
