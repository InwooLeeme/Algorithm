#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int64_t

bool Check(int x){
    string s = to_string(x);
    for(auto& i : s) if(string("58").find(i) == -1) return 0;
    return 1;
}

void Sol(){
    int A,B,C; cin >> A;
    vector<int> v1(A);
    for(auto& i : v1) cin >> i;
    cin >> B;
    vector<int> v2(B);
    for(auto& i : v2) cin >> i;
    cin >> C;
    vector<int> v3(C);
    for(auto& i : v3) cin >> i;
    set<int> S;
    v1.erase(unique(v1.begin(), v1.end()), v1.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    v3.erase(unique(v3.begin(), v3.end()), v3.end());
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            for(int k = 0; k < v3.size(); k++){
                auto chk = v1[i] + v2[j] + v3[k];
                if(Check(chk)) S.insert(chk);
            }
        }
    }
    cout << S.size() << "\n";
}

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--) Sol();
    return 0;
}