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
    vector<int>a(n),b(n);
    int lanon1 = -1;
    int lanon2 = -1;
    int al=0,bob=0;
    for (int i=0;i<n;++i) {
        char ch;
        cin >> ch;
        if (ch == 'A') 
        {
            a[i]++;
            al++;
            if (i != n-1) lanon1 = i;
        }
        else 
        {
            b[i] ++ ;
            bob++;
            if (i != n-1) lanon2= i;
        }
    }
    if ( n!= 2 && (al==1 || bob == 1)) {
        if (al == 1) cout << "Bob";
        else cout << "Alice";
        return;
    }
    if (n == 2) {
        if (a[0]) cout << "Alice";
        else cout << "Bob";
        return;
    }
    if (a[0]&& a[n-1]) return void(cout << "Alice");
    else if (b[0]&& b[n-1]) return void(cout << "Bob");
    if (a[n-1]) {
        if (lanon1 < lanon2) {
            cout << "Bob";
        }
        else cout << "Alice";
    }
    else if (b[n-1]){
        cout<< "Bob";
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