# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
    deque<char> ret;
    stack<int> S;
    for(int i = 0,t; i < n; i++){
        cin >> t;
        if(t == 1){
            char c; cin >> c;
            ret.push_back(c);
            S.push(t);
        }
        else if(t == 2){
            char c; cin >> c;
            ret.push_front(c);
            S.push(t);
        }
        else if(t == 3){
            if(S.empty() or ret.empty()) continue;
            if(S.top() == 1){
                ret.pop_back();
                S.pop();
            }
            else{
                ret.pop_front();S.pop();
            }
        }
    }
    if(ret.empty()) cout << 0 << "\n";
    else for(auto& i : ret) cout << i;
    return 0; 
}
