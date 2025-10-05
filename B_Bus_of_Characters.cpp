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
const ll mod = 1e9+7, OO = 0x3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        pq.push({x,i});
    }
    stack<int>s;
    string str;
    cin >> str;
    for (int i=0;i<2*n;++i) {
        if (str[i] == '0') { // introvert
            cout << pq.top().se+1 << ' ';
            s.push(pq.top().se);
            pq.pop();
        }
        else {
            cout << s.top()+1 << ' ';
            s.pop();
        }
    }
}

int main()
{
    ishowspeed
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        solve();
        cout << el;
    }
}
