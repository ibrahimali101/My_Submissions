#include <bits/stdc++.h> 
int grid[11][11];
using namespace std;
int n,m;

vector<vector<int>>vec;

bool valid(int r,int c) {
    return (r>=0&&c>=0&&r<n&&c<m);
}

void rec(int r,int c,vector<int>&vv) {
    if (r==n && c == m) {
        vec.push_back(vv);
        return;
    }
    vv.push_back(grid[r][c]);
    if (valid(r+1,c)) rec(r+1,c,vv);
    if (valid(r,c+1)) rec(r,c+1,vv);
    vv.pop_back();
}

int main() {
    cin >> n >> m;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) cin >> grid[i][j];
    }
    vector<int>v;
    rec(0,0,v);
    sort(vec.begin(),vec.end());
    for (auto i : vec) {
        for (auto j : i) cout << j << ' ';
        cout << endl;
    }
}