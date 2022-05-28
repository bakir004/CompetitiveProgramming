#include <cstdio>

int main()
{
    int n, d, b0, b, moves(0);
    scanf("%d%d%d", &n, &d, &b0);
    while (--n)
    {
        scanf("%d", &b);
        if (b <= b0)
        {
            int x = (b0 - b) / d + 1;
            moves += x;
            b0 = b + x * d;
        }
        else
        {
            b0 = b;
        }
    }
    printf("%d\n", moves);
    return 0;
}