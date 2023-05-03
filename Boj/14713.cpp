#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n; cin.ignore();
    vector<deque<string>> I(n);
    string s;
    for(int i = 0; i < n; i++){
        string s,temp; getline(cin, s);
        stringstream in(s);
        while(in >> temp) I[i].push_back(temp);
    }
    getline(cin, s);
    stringstream in(s);
    string temp;
    vector<string> ss;
    while(in >> temp) ss.push_back(temp);
    auto Sol = [&]() -> string {
        for(auto& cur : ss){
            bool flag = 0;
            for(int i = 0; i < n; i++){
                if(cur == I[i].front() and !I[i].empty()) {
                    flag = 1;
                    I[i].pop_front();
                    break;
                }
            }
            if(!flag) return "Impossible";
        }
        for(int i = 0; i < n; i++) if(!I[i].empty()) return "Impossible";
        return "Possible";
    };
    cout << Sol() << "\n";
    return 0;
}