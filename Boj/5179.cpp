#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    auto Sol = [&]() -> void{
        using vi = vector<int>; 
        int n,m,p; cin >> n >> m >> p;
        vector<map<int,int>> wrong(p + 1),already(p + 1);
        map<int, int> M,S;
        for(int i = 0; i < m; i++){
            int x,t,j; char c; cin >> x >> c >> t >> j;
            if(!j) wrong[x][c - 'A']++;
            else{
                if(already[x].count(c - 'A')) continue;
                already[x][c - 'A']++;
                M[x]++;
                S[x] += (t + 20 * wrong[x][c - 'A']);
            }
        }
        vector<array<int, 3>> ret;
        for(int i = 1; i <= p; i++){
            ret.push_back({i, M[i], S[i]});
        }
        sort(ret.begin(), ret.end(), [&](array<int, 3>& a, array<int,3>& b){
            return a[1] == b[1] ? a[2] < b[2] : a[1] > b[1];
        });
        for(const auto& [a, b, c] : ret) cout << a << " " << b << " " << c << "\n";
    };
    int t; cin >> t; for(int tc = 1; tc <= t; tc++){
        cout << "Data Set " << tc << ": \n";
        Sol();
        cout << "\n";
    }
    return 0;
}
