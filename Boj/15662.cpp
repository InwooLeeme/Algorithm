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
int N;

struct Gear{
    string s;
    bool isRotate;
    int dir; // 1 : 시계방향, -1 : 반시계
    Gear():isRotate(0),dir(0){}
    void SetDir(int d){ dir = d; }
    void Rotate(){
        if(dir == 1) rotate(s.begin(), s.begin() + 7, s.end());
        else rotate(s.begin(), s.begin() + 1, s.end());
    };  
    void Reset(){
        SetDir(0); isRotate = 0;
    };
    void Print(){
        cout << s << "\n";
    };
};

int opdir(int d){
    if(d == 1) return -1;
    return 1;
}

bool Bound(int x){ return x < 0 or x >= N; }

void SetDirs(int s, int d, vector<Gear>& G){
    using p = pair<int, int>;
    queue<p> Q; Q.push({s, d});
    vector<int> vist(N);
    vist[s] = 1;
    while(Q.size()){
        auto [cur, dir] = Q.front(); Q.pop();
        G[cur].isRotate = 1; G[cur].SetDir(dir);
        if(!Bound(cur - 1) and !vist[cur - 1] and G[cur - 1].s[2] != G[cur].s[6]){
            vist[cur - 1] = 1;
            Q.push({cur - 1, opdir(dir)});
        }
        if(!Bound(cur + 1) and !vist[cur + 1] and G[cur + 1].s[6] != G[cur].s[2]){
            vist[cur + 1] = 1;
            Q.push({cur + 1, opdir(dir)});
        }
    }
}

void Main(){
    // input
    cin >> N;
    vector<Gear> G(N); for(auto& i : G) cin >> i.s;
    auto Rotate = [&]() -> void{
        for(int i = 0; i < N; i++) if(G[i].isRotate){
            G[i].Rotate();
            G[i].Reset();
        }
    };
    int k; cin >> k;
    while(k--){
        int s,d; cin >> s >> d; --s; // 0-indexed
        SetDirs(s, d, G);
        Rotate(); 
    }    
    int ret = 0;
    for(int i = 0; i < N; i++) ret += (G[i].s[0] == '1');
    cout << ret << "\n";

}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}