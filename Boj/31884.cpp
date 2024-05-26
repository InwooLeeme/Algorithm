#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main(){
    fastio;
    map<int, int> M;
    int q; cin >> q; while(q--){
        int t,i; cin >> t >> i;
        if(t == 1){
            int mx = 0;
            for(int j = i; j < i + 4; j++) mx = max<int>(mx, M[j]);
            for(int j = i; j < i + 4; j++) M[j] = mx + 1;
        }
        else if(t == 2){
            M[i] += 4;
        }
        else if(t == 3){
            if(!M.count(i)) cout << 0 << "\n";
            else cout << M[i] << "\n";
        }
    }
    return 0;
}
