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

int GetEval(string s){
    string tmpS, tmpNum;
    for(auto c : s)
        if(c != ' ') tmpS += c;
    vector <int> num;
    vector <char> op;
    for(auto t : tmpS){
        if(t == '-' || t == '+') {
            op.push_back(t);
            num.push_back(stoi(tmpNum));
            tmpNum = "";
            continue;
        }
        tmpNum += t;
    }
    num.push_back(stoi(tmpNum));
    int ans = num[0];
    for(int i = 1; i < num.size(); i++){
        if(op[i-1] == '+') ans += num[i];
        else ans -= num[i];
    }
    return ans;
}

void test_case(){
    int n; cin >> n;
    vector<int> v(n);
    set<string > S;
    iota(v.begin(), v.end(), 1);
    auto F = [&](int dep, string cur, auto&& F) -> void{
        if(dep == n){
            if(!GetEval(cur)){
                S.insert(cur);
                return;
            }
            return;
        }
        F(dep + 1, cur + ' ' + to_string(dep + 1), F);
        F(dep + 1, cur + '+' + to_string(dep + 1), F);
        F(dep + 1, cur + '-' + to_string(dep + 1), F);
    };
    F(1, "1", F);
    for(auto& i : S) cout << i << "\n";
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) test_case();
    return 0;
}