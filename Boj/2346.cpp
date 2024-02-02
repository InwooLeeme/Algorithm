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

int main(){
    int n; cin >> n;
	deque<int> DQ;
	vector<int> IDX(n + 1);
	for(int i = 1; i <= n; i++){
	    cin >> IDX[i];
		DQ.push_back(i); 
	}
	while(!DQ.empty()){
		auto move = IDX[DQ.front()];
		cout << DQ.front() << " ";
		DQ.pop_front();
		int cnt = abs(move);
		if(move > 0){
			for(int i = 1; i < cnt; i++){
			    DQ.push_back(DQ.front());
				DQ.pop_front();
			}
		}
		else{
			for(int i = 0; i < cnt; i++){
			    DQ.push_front(DQ.back());
				DQ.pop_back(); 
			}
		}
	}
    return 0;
}
