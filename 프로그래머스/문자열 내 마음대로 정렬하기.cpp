#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;
    sort(strings.begin(), strings.end(), [&](const string &a, const string &b)
         {
        if(a[n] == b[n]) return a < b;
        return a[n] < b[n]; });
    answer = strings;
    return answer;
}