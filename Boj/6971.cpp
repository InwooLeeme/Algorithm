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

void Sol(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            v.push_back(i);
            v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    bool flag = 0;
    for(int i = 0; i < v.size(); i++){
        int lft = v[v.size() - i - 1] - v[i];
        for(int j = 0; j < v.size(); j++){
            if(v[j] + v[v.size() - j - 1] == lft){
                flag = 1;
                break;
            }
        }
    }
    cout << n << " is " << (flag ? "nasty" : "not nasty") << "\n";
} 

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--) Sol();
    return 0;
}