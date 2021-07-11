// 9317번 : Monitor DPI(브론즈 3)

#include <iostream>
#include <algorithm>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    fastio;
    while (1)
    {
        float d;
        int HorDPI, VertDPI;
        cin >> d >> HorDPI >> VertDPI;
        if (d == 0 && HorDPI == 0 & VertDPI == 0)
        {
            break;
        }
        float W = (16 * d) / sqrt(337);
        float h = (9 * W) / 16;
        float ans1 = HorDPI / W;
        float ans2 = VertDPI / h;
        printf("Horizontal DPI: %.2f\nVertical DPI: %.2f\n", ans1, ans2);
    }
    return 0;
}