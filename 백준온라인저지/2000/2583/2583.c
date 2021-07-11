// 2583번 : 영역 구하기

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#include <stdio.h>
#define SZ 101

int map[SZ][SZ] = {0};
int M, N, K;
int i, j;
int zero_area_cnt = 0;
int zero_area[SZ * (SZ / 2) + 1] = {0};

int vectX[4] = {0, 0, 1, -1};
int vectY[4] = {1, -1, 0, 0};

void make_square(int from_x, int from_y, int to_x, int to_y)
{
    for (int i = from_y; i < to_y; i++)
    {
        for (int j = from_x; j < to_x; j++)
        {
            map[j][i] = 1;
        }
    }
}

void do_dfs(int i, int j, int value)
{
    map[i][j] = value;
    zero_area[value - 2]++;
    int nextX, nextY;
    for (int k = 0; k < 4; k++)
    {
        nextX = i + vectX[k];
        nextY = j + vectY[k];

        if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M)
        {
            if (map[nextX][nextY] == 0)
            {
                do_dfs(nextX, nextY, value);
            }
        }
    }
}

void bubble_sort()
{
    for (i = 0; i < zero_area_cnt; i++)
    {
        for (j = 0; j < zero_area_cnt - 1; j++)
        {
            if (zero_area[j] > zero_area[j + 1])
            {
                int temp = zero_area[j];
                zero_area[j] = zero_area[j + 1];
                zero_area[j + 1] = temp;
            }
        }
    }
}

void solution()
{
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                zero_area_cnt++;
                do_dfs(i, j, zero_area_cnt + 1);
            }
        }
    }
    bubble_sort();
    printf("%d\n", zero_area_cnt);
    for (i = 0; i < zero_area_cnt; i++)
    {
        printf("%d ", zero_area[i]);
    }
}

int main()
{
    scanf("%d %d %d", &M, &N, &K);
    int from_x, from_y, to_x, to_y;
    for (i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        make_square(from_x, from_y, to_x, to_y);
    }
    solution();
}