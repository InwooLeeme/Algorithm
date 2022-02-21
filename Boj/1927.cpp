// 1927번 : 최소 힙

#include <iostream>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    int n;
    fastio;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 구성
    //priority_queue<int> pq; // 요건 최대 힙!
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            // x가 0이면
            if (pq.empty())
            {
                // x가 0이고 최소 힙에 아무것도 없으면
                cout << "0\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            // x가 0이 아닐 때
            pq.push(x);
        }
    }
    return 0;
}