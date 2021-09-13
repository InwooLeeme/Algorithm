// 1990번 : 소수인팰린드롬(수학, 골드 5)

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#define lli long long int
#define MAX 10000001
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int a, b;
bool seive[MAX] = {
    false,
};

bool ispalindrome(int n)
{
    string s1 = to_string(n);
    string s2 = s1;
    reverse(s1.begin(), s1.end());
    if (s1 == s2)
        return true;
    else
        return false;
}

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    fastio;
    cin >> a >> b;
    if (b > MAX - 1)
    {
        b = MAX - 1;
    }
    for (int i = 2; i < MAX; i++)
    {
        if (ispalindrome(i))
        {
            seive[i] = true;
        }
    }
    for (int i = a; i <= b; i++)
    {
        if (seive[i])
        {
            if (isPrime(i))
            {
                printf("%d\n", i);
            }
        }
    }
    printf("-1");
    return 0;
}