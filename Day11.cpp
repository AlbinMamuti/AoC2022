#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <map>
#include <queue>
#include <stdlib.h>
#include <cmath>
struct monkey
{
    queue<long long> items;
    int operation;
    string op;
    int test;
    int ifTrue;
    int ifFalse;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);
    vector<monkey *> monkeys;
    monkey mk0 = {
        queue<long long>({66, 79}),
        11,
        "*",
        7,
        6,
        7,
    };
    monkey mk1 = {
        queue<long long>({84, 94, 94, 81, 98, 75}),
        17,
        "*",
        13,
        5,
        2,
    };
    monkey mk2 = {
        queue<long long>({85, 79, 59, 64, 79, 95, 67}),
        8,
        "+",
        5,
        4,
        5,
    };
    monkey mk3 = {
        queue<long long>({70}),
        3,
        "+",
        19,
        6,
        0,
    };
    monkey mk4 = {
        queue<long long>({57, 69, 78, 78}),
        4,
        "+",
        2,
        0,
        3,
    };
    monkey mk5 = {
        queue<long long>({65, 92, 60, 74, 72}),
        7,
        "+",
        11,
        3,
        4,
    };
    monkey mk6 = {
        queue<long long>({77, 91, 91}),
        -1,
        "*",
        17,
        1,
        7,
    };
    monkey mk7 = {
        queue<long long>({76, 58, 57, 55, 67, 77, 54, 99}),
        6,
        "+",
        3,
        2,
        1,
    };
    monkeys.push_back(&mk0);
    monkeys.push_back(&mk1);
    monkeys.push_back(&mk2);
    monkeys.push_back(&mk3);
    monkeys.push_back(&mk4);
    monkeys.push_back(&mk5);
    monkeys.push_back(&mk6);
    monkeys.push_back(&mk7);

    long long mod = 7 * 13 * 5 * 19 * 2 * 11 * 17 * 3;

    vector<long long> sol = vector<long long>(8, 0);

    for (int rond = 0; rond < 10000; rond++)
    {
        for (int i = 0; i < 8; i++)
        {
            while (!monkeys[i]->items.empty())
            {
                long long currLevel = monkeys[i]->items.front();
                monkeys[i]->items.pop();
                sol[i]++;
                if (monkeys[i]->op == "+")
                {
                    currLevel += monkeys[i]->operation;
                }
                else
                {
                    if (monkeys[i]->operation == -1)
                    {
                        currLevel *= currLevel;
                    }
                    else
                    {
                        currLevel *= monkeys[i]->operation;
                    }
                }
                // currLevel = floor(currLevel / 3);
                currLevel %= mod;
                if (currLevel % monkeys[i]->test == 0)
                    monkeys[monkeys[i]->ifTrue]->items.push(currLevel);
                else
                    monkeys[monkeys[i]->ifFalse]->items.push(currLevel);
            }
        }
    }

    sort(sol.begin(), sol.end());

    cout
        << sol[7] << ", " << sol[6] << endl;
    cout << sol[7] * sol[6] << endl;
    return 0;
}