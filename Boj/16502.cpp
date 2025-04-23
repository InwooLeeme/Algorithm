#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<double, int>> g[5];
vector<double> res(4);

void dfs(int cur, double cost, int dep = 0){
    if(dep == n){
        res[cur] += cost * 100;
        return;
    }
    for(const auto& [c, nxt] : g[cur]){
        dfs(nxt, cost * c, dep + 1);
    }
}

void Main(){
    cin >> n >> m;
    while(m--){
        char a,b; double c; cin >> a >> b >> c;
        g[a - 'A'].push_back({c, b - 'A'});
    }
    for(int i = 0; i < 4; i++) dfs(i, 0.25, 0);
    for(int i = 0; i < 4; i++) cout << fixed << setprecision(3) << res[i] << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    Main();
    return 0;
}
