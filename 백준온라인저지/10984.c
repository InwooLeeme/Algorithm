//  10984번 : 내 학점을 구해줘

#include <stdio.h>

int main()
{
    int test;
    int dayScore, sum;
    float gradeScore = 0, gradeResult;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int num;
        sum = 0, gradeResult = 0.0;
        scanf("%d", &num);
        for (int i = 0; i < num; i++)
        {
            scanf("%d %f", &dayScore, &gradeScore);
            sum += dayScore;
            gradeResult += (float)dayScore * gradeScore;
        }
        gradeResult = gradeResult / (float)sum;
        printf("%d %.1f\n", sum, gradeResult);
    }
    return 0;
}