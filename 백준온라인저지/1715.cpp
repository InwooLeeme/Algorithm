// 1715번 : 카드 정렬하기

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    fastio;
    int test;
    long long result = 0;
    cin >> test;
    while (test--)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        result += (a + b);
        pq.push(a + b);
    }
    cout << result << "\n";
    return 0;
}