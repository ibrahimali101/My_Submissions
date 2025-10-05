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

string done(deque<int>dq, char dir) {
    string res;
    vector<int>seq;
    while(!dq.empty()) {
        if (seq.empty() && dir == 'L') {
            seq.push_back(dq.front());
            dq.pop_front();
            res+='L';
        }
        else if (seq.empty() && dir == 'R'){
            seq.push_back(dq.back());
            dq.pop_back();
            res+='R';
        }
        if (dq.empty()) break;
        if (seq.back() < dq.back() && seq.back() < dq.front()) {
            if (dq.front() > dq.back()) {
                seq.push_back(dq.back());
                dq.pop_back();
                res+='R';
            }
            else {
                seq.push_back(dq.front());
                dq.pop_front();
                res+='L';
            }
        }
        else if (seq.back() > dq.back() && seq.back() > dq.front()) {
            break;
        }
        else {
            if (dq.front() > seq.back()) {
                seq.push_back(dq.front());
                dq.pop_front();
                res+='L';
            }
            else {
                seq.push_back(dq.back());
                dq.pop_back();
                res+='R';
            }
        }
    }
    return res;
}


void solve()
{
    int n;
    cin >> n;
    deque<int>dq(n),dq2(n);
    for (auto&i : dq) {
        cin >> i;
    }
    string x,y;
    x = done(dq,'L');
    y = done(dq,'R');
    cout << max(x.size(),y.size()) << el;
    if (x.size() > y.size())
        cout << x;
    else cout << y;
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
