#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
	fastio;
    int n,m; cin >> n >> m;
    map<string, string> M;
    for(int i = 0; i < n; i++){
        string a,b; cin >> a >> b;
        M[a] = b;
    }
    for(int i = 0; i < m; i++){
        string ret = "";
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            for(const auto& [a, b] : M){
                if(j + a.size() > s.size()) continue;
                if(s.substr(j, a.size()) == a) ret += b;
            }
        }
        if(ret == "") cout << -1 << "\n";
        else cout << ret << "\n";
    }
    return 0;
}
