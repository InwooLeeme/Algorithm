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


const int PRECISION = 0;

int N;
int D[5001][5001], v[5001];

int Sol(int i, int j){
    if(i == j) return (N & 1) ? v[i] : 0;
    int& ret = D[i][j];
    if(ret != -1) return ret;
    if((N - (j - i)) & 1) ret = max<int>(Sol(i + 1, j) + v[i], Sol(i, j - 1) + v[j]);
    else ret = min<int>(Sol(i + 1, j), Sol(i, j - 1));
    return ret;
};

void Main(){
    memset(D, -1, sizeof(D));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    cout << Sol(0, N - 1) << "\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
