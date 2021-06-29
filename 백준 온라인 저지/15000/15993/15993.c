// 15993번 : 1,2,3 더하기 8
#include <stdio.h>
#define ll long long
#define MAX 100001
#define mod 1000000009

ll odd[MAX] = {0, 1, 1, 2};
ll even[MAX] = {0, 0, 1, 2};

void getSum(int n)
{
    for (int i = 4; i <= n; i++)
    {
        odd[i] = (even[i - 1] + even[i - 2] + even[i - 3]) % mod;
        even[i] = (odd[i - 1] + odd[i - 2] + odd[i - 3]) % mod;
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        getSum(n);
        printf("%lld %lld\n", odd[n], even[n]);
    }
    return 0;
}