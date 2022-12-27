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

#define int int_fast64_t

int32_t main(){
    fastio;
    int N;
    while(cin >> N and N){
        cin.ignore();
        map<string, int> M;
        vector<string> v(N);
        for(auto& i : v) cin >> i;
        for(int i = 0; i < N; i++){
            int cnt = 0;
            auto a = v[i];
            sort(a.begin(), a.end());
            for(int j = i + 1; j < N; j++){
                auto b = v[j]; 
                sort(b.begin(), b.end());
                if(a == b) cnt++;
            }
            M[v[i]] = cnt;
        }
        string ret = "";
        int mx = 0;
        for(auto& [a, b] : M){
            if(mx < b){
                mx = max<int>(mx, b);
                ret = a;
            }
        }
        cout << ret << ' ' << mx << "\n";
    }
    return 0;
}