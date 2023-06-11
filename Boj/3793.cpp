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

// Get LCS length
int LCS(string& a,string& b,const int sz = 1000){
	const int aSz = a.size();
	const int bSz = b.size();
	vector<vector<int>> d(sz + 1,vector<int>(sz + 1, 0));
	for(int i = 1; i <= aSz; i++) for(int j = 1; j <= bSz; j++){
		if(a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
		else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
	}
	return d[aSz][bSz];
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 	string a,b;
	while(cin >> a >> b){
		cout << LCS(a, b) << "\n";
	}   
    return 0; 
}
