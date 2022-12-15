#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <map>
#include <queue>
#include <stdlib.h>
#include <cmath>

string div2 = "[[2]]";
string div6 = "[[6]]";

bool checkInt(char a)
{
    return (a - '0') >= 0 && a - '0' <= 9;
}
bool check10(string s)
{
    return (s[0] == '1' && s[1] == '0');
}

bool cmp(string left, string right)
{
    int posL = 0;
    int posR = 0;
    bool wrong = false;

    while (left[posL] != '\000' && right[posR] != '\000')
    {
        if (left[posL] == '[' && right[posR] == '[')
        {
            posL++;
            posR++;
            continue;
        }
        if (left[posL] == ',' && right[posR] == ',')
        {
            posL++;
            posR++;
            continue;
        }
        if (left[posL] == '[' && right[posR] != '[' && checkInt(right[posR]))
        {
            right.insert(posR, "[");
            if (right[posR + 2] == '0')
                right.insert(posR + 3, "]");
            else
                right.insert(posR + 2, "]");
            continue;
        }
        if (left[posL] != '[' && checkInt(left[posL]) && right[posR] == '[')
        {
            left.insert(posL, "[");
            if (left[posL + 2] == '0')
                left.insert(posL + 3, "]");
            else
                left.insert(posL + 2, "]");
            continue;
        }
        if (left[posL] == ']' && right[posR] != ']')
        {

            break;
        }
        if (left[posL] != ']' && right[posR] == ']')
        {
            wrong = true;
            break;
        }
        if (check10(left.substr(posL, posL + 1)) && check10(right.substr(posR, posR + 1)))
        {
            posL += 2;
            posR += 2;
            continue;
        }
        if (check10(left.substr(posL, 2)))
        {
            wrong = true;
            break;
        }
        if (check10(right.substr(posR, 2)))
        {
            break;
        }
        if (checkInt(left[posL]) && checkInt(right[posR]) && (left[posL] - '0') < (right[posR] - '0'))
        {
            break;
        }
        if (checkInt(left[posL]) && checkInt(right[posR]) && (left[posL] - '0') == (right[posR] - '0'))
        {
            posL++;
            posR++;
            continue;
        }
        if (checkInt(left[posL]) && checkInt(right[posR]) && (left[posL] - '0') > (right[posR] - '0'))
        {
            wrong = true;
            break;
        }
        if ((left[posL] == ']') && (right[posR] == ']'))
        {
            posL++;
            posR++;
            continue;
        }
    }
    if (wrong)
    {
        return false;
    }
    if (left[posL] != '\000' && right[posR] == '\000')
    {
        false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    vector<int> sol;

    int div2I = 0;
    int div6I = 0;

    for (int i = 0; i < 150; i++)
    {
        string left;
        string right;
        string noth;
        getline(cin, left);
        getline(cin, right);
        getline(cin, noth);

        if (cmp(left, right))
            sol.push_back(i + 1);

        // part2
        if (cmp(left, div2))
            div2I++;
        if (cmp(right, div2))
            div2I++;
        if (cmp(left, div6))
            div6I++;
        if (cmp(right, div6))
            div6I++;
    }
    int solN = 0;
    for (auto i : sol)
    {
        solN += i;
    }
    cout << solN << endl;
    cout << (div2I + 1) * (div6I + 2) << endl;
    return 0;
}