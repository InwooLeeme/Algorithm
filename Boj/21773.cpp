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

struct Info{
    int id, T, pri;
    bool operator< (const Info& p) const{
        return pri == p.pri ? id > p.id : pri < p.pri;
    };
};

void Main(){
    priority_queue<Info> PQ;
    int t,n; cin >> t >> n;
    vector<int> ret;
    for(int i = 0; i < n; i++){
        int a,b,c; cin >> a >> b >> c;
        PQ.push({a, b, c});
    }
    int cnt = 0;
    while(!PQ.empty() and cnt < t){
        auto cur = PQ.top(); PQ.pop();
        ret.push_back(cur.id);
        if(cur.T - 1 > 0) PQ.push({cur.id, cur.T - 1, cur.pri - 1});
        cnt++;
    }
    for(auto& i : ret) cout << i << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}