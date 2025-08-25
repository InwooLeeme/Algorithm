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

const int PRECISION = 0;

void Main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        stack<int> s;
        for(int i = 0; i < n; i++){
            char c; cin >> c;
            if(c == 'A'){
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(a & b);
            }
            else if(c == 'R'){
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(a | b);
            }
            else if(c == 'X'){
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(a ^ b);
            }
            else if(c == 'N'){
                auto a = s.top(); s.pop();
                s.push(!a);
            }
            else if(c == '1'){
                s.push(1);
            }
            else if(c == '0'){
                s.push(0);
            }
        }
        cout << s.top() << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
