#include <bits/stdc++.h>

using namespace std;

int calcPower(int n, int a)
{
    int cifre = 0;
    while (n > 0)
    {
        n /= a;
        cifre++;
    }
    return cifre - 1;
}

int main()
{
    int n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << 1 << endl;
        return 0;
    }

    int maxBroj = 1;
    for (int a = 2; a <= sqrt(n); a++)
    {
        int power = calcPower(n, a);

        int broj = pow(a, power);
        if (broj % a != 0) broj++;

        if (maxBroj < broj)
            maxBroj = broj;
    }

    cout << maxBroj << endl;

    return 0;
}
