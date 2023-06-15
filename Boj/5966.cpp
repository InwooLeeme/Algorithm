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
	int t; cin >> t; 
	for(int i = 0; i < t; i++){
		int n; string x; cin >> n >> x;
		int ret = 0;
		[&](){
				for(auto& c : x){
				if(c == '>') ret++;
				else ret--;
				if(ret < 0){
					cout << "illegal" << '\n';
					return;
				}
			}
			cout << (ret ? "illegal" : "legal") << "\n";
		}();
	}
    return 0; 
}
