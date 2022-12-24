#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using pii = pair<int, int>;

int32_t main(){
	fastio;
	int a,b; cin >> a >> b;
	map<int, string> M;
	M[0] = "zero";
	M[1] = "one";
	M[2] = "two";
	M[3] = "three";
	M[4] = "four";
	M[5] = "five";
	M[6] = "six";
	M[7] = "seven";
	M[8] = "eight";
	M[9] = "nine";
	vector<pair<string,int>> v;
	for(int i = a; i <= b; i++){
		string s = "";
		if(i >= 10) s = M[i / 10] + " " + M[i % 10];
		else s = M[i % 10];
		v.push_back({s, i});
	}
	sort(v.begin(), v.end());
	const int sz = v.size();
	for(int i = 0; i < sz; i++){
		cout << v[i].second << ' ';
		if(i % 10 == 9) cout << "\n";
	}
	return 0;
}