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

int n;
string s;
int pos[3][1111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B') pos[0][i] = 1;
        else if(s[i] == 'O') pos[1][i] = 1;
        else if(s[i] == 'J') pos[2][i] = 1;
    }
    vector<int> d(n + 1, int(2e9)); // d[i] : i번 위치에 가기 위해 필요한 에너지의 최소값
    d[0] = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B'){
            for(int j = i + 1; j < n; j++) if(pos[1][j]){
                d[j] = min<int>(d[j], d[i] + (j - i) * (j - i));
            }
        }
        else if(s[i] == 'O'){
            for(int j = i + 1; j < n; j++) if(pos[2][j]){
                d[j] = min<int>(d[j], d[i] + (j - i) * (j - i));
            }
        }
        else if(s[i] == 'J'){
            for(int j = i + 1; j < n; j++) if(pos[0][j]){
                d[j] = min<int>(d[j], d[i] + (j - i) * (j - i));
            }
        }
    }
    cout << (d[n - 1] == int(2e9) ? -1 : d[n - 1]) << '\n';
    return 0;
}