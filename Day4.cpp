#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    int partOne = 0;
    int partTwo = 0;
    for (int i = 0; i < 1000; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <= c && b >= d)
            partOne++;
        else if (a >= c && b <= d)
            partOne++;

        if (b < c)
            partTwo++;
        else if (d < a)
            partTwo++;
    }
    cout << partOne << endl;
    cout << (1000 - partTwo) << endl;
}