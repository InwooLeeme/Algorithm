// 2075번 : N번째 큰수

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        int x;
        cin >> x;
        if (pq.size() < n)
        {
            pq.push(x);
        }
        else
        {
            if (pq.top() < x)
            {
                pq.push(x);
                pq.pop();
            }
        }
    }
    cout << pq.top();
    return 0;
}