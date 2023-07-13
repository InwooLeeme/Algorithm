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
    int n; cin >> n;
    multiset<int> MS;
    int cnt = 0;
    for(int i = 0,t; i < n; i++){
        string s; cin >> s >> t;
        if(s == "insert"){
            if(!MS.count(t)) cnt++;
            MS.insert(t);
        }
        else if(s == "delete"){
            if(MS.count(t) > 0){
                MS.erase(MS.find(t));
                if(MS.count(t) == 0) cnt--;
            }
        }        
        if(MS.size() >= 2 and MS.size() > cnt and cnt >= 2) cout << "both" << '\n';
        else if(MS.size() >= 2 and cnt == 1) cout << "homo" << "\n";
        else if(MS.size() >= 2 and MS.size() == cnt) cout << "hetero" << "\n";
        else if(MS.size() < 2) cout << "neither" << "\n";
    }
    return 0;
}