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
    const int N = 1e6+4;
    vector<int>adj[N];
    int lowlink[N],dfn[N];
    int ndfn = 1;
    set<pair<int,int>>bridges;
    void init(int n) {
        clr(lowlink,0);
        clr(dfn,-1);
        for(int i=0;i<n;++i) {
            adj[i].clear();
        }
        bridges.clear();
        ndfn = 1;
    }
    void tarjan(int node, int par) {
        lowlink[node] = dfn[node] = ndfn++;
        for (int ch : adj[node]) {
            if (dfn[ch] == -1) {
                tarjan(ch,node);
                lowlink[node] = min(lowlink[node], lowlink[ch]);
            }
            else if (ch != par) {
                lowlink[node] = min(lowlink[node], dfn[ch]);
            }
        }
        if (par != -1 && lowlink[node] == dfn[node]) {
            int x = min(par,node);
            int y = max(par,node);
            bridges.insert({x,y});
        }
    }


    int main()
    {
        ishowspeed
        int n;
        while(cin >> n)
        {
            init(n);
            for (int i=0;i<n;++i) {
                int node,m,x;
                cin >> node;
                char temp;
                cin >> temp >> m >> temp;
                for (int j=0;j<m;++j) {
                    cin >> x;
                    adj[node].pb(x);
                    adj[x].pb(node);
                }
            }
            for (int i=0;i<n;++i) {
                if (dfn[i] == -1) tarjan(i,-1);
            }
            cout << bridges.size() << " critical links\n";
            for (auto [x,y] : bridges) {
                cout << x << " - " << y << el; 
            }
            cout << el;
        }
    }
