#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <map>
#include <stdlib.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);
    long long strength = 1;
    int cycle = 1;
    long long sol = 0;
    for (int i = 0; i < 140; i++)
    {
        string instr;
        int addx;
        cin >> instr;

        if (((cycle - 1) % 40) >= strength - 1 && ((cycle - 1) % 40) <= strength + 1)
            cout << "#";
        else
            cout << ".";
        if (cycle % 40 == 0)
            cout << endl;
        cycle++;
        if (cycle >= 20 && cycle % 40 == 20)
        {
            sol += cycle * strength;
        }
        if (instr == "noop")
        {
            continue;
        }
        cin >> addx;
        if (((cycle - 1) % 40) >= strength - 1 && ((cycle - 1) % 40) <= strength + 1)
            cout << "#";
        else
            cout << ".";
        if (cycle % 40 == 0)
            cout << endl;
        cycle++;
        strength += addx;
        if (cycle >= 20 && cycle % 40 == 20)
        {
            sol += cycle * strength;
        }
    }
    cout << sol << endl;
    return 0;
}