#include <bits/stdc++.h>
using namespace std;
#include <stack>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    int partOne = 0;
    int partTwo = 0;

    string seq;
    cin >> seq;

    int tester = 0;
    vector<bool> test(52, false);

    for (int i = 14; i < seq.length(); i += 1)
    {
        bool temp = false;
        for (int j = i - 14; j < i; j++)
        {
            int ind = seq[j] - 'a';
            // cout << ind << ", ";
            temp |= test[ind];
            // cout << temp << " ;";
            test[ind] = true;
        }
        if (!temp)
        {
            cout << "Part2: " << i << endl;
            return 0;
        }
        // cout << "clear" << endl;
        test.clear();
        vector<bool> test2(52, false);
        test = test2;
    }
    for (int i = 3; i < seq.length(); i++)
    {
        char a, b, c, d;
        a = seq[i - 3];
        b = seq[i - 2];
        c = seq[i - 1];
        d = seq[i];
        if (a != b && a != c && a != d && b != c && b != d && c != d)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "error" << endl;
    return 0;
}