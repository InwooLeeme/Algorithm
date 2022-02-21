// 1629번 : 곱셈

#include <stdio.h>
#define ll long long

ll divide(ll a, ll b, ll c)
{
    if (b > 1)
    {
        ll result = divide(a, b / 2, c);
        if (b % 2 == 0)
        {
            // b가 짝수
            return result * result % c;
        }
        else
        {
            // b가 홀수
            return ((result * result) % c * a) % c;
        }
    }
    else
    {
        return a;
    }
}

int main()
{
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld", divide(a, b, c) % c);
    return 0;
}