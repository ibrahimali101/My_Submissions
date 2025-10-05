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
using pa = pair<string,string>;

vector<set<pa>> ans(300);
void init() {
    for (int i=0;i<300;++i) {
        ans[i].clear();
    }
}

void print(int n) {
    vector<string>v;
    for (int i=0;i<=n;++i) {
        if (ans[i].empty()) return void(cout << "not complete\n");
        for (auto k : ans[i]) {
            v.pb(k.se);
            v.pb(" ");
        }
    }
    v.pop_back();
    for (auto i : v) cout << i;
    cout << '\n';
}


pa parse(string str) {
    string num, lvl;
    int n = str.size();
    for (int i=0;i<n;++i) {
        if (!(str[i] == '(' || str[i] == ')' || str[i] == ',')) {
            if (isdigit(str[i])) num.pb(str[i]);
            else lvl.pb(str[i]);
        }
        
    }
    return {lvl,num};
}

int main()
{
    ishowspeed
    string str;
    unordered_set<string>cmds;
    int lvl = -1;
    bool complete = true;
    while(cin >> str) {
        if (str == "()") {
            if (complete) {
                print(lvl);
            }
            else cout << "not complete\n";
            complete = true;
            cmds.clear();
            init();
            lvl = -1;
        }
        else {
            pa p = parse(str);
            if (cmds.count(p.fi)) complete = false;
            else {
                cmds.insert(p.fi);
                ans[(int)p.fi.size()].insert(p);
                lvl = max(lvl, (int)p.fi.size());
            }
        }
    }
}
