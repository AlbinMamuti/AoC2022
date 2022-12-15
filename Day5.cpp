#include <bits/stdc++.h>
using namespace std;
#include <stack>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    stack<char> c1{{'W', 'B', 'D', 'N', 'C', 'F', 'J'}};
    stack<char> c2{{'P', 'Z', 'V', 'Q', 'L', 'S', 'T'}};
    stack<char> c3{{'P', 'Z', 'B', 'G', 'J', 'T'}};
    stack<char> c4{{'D', 'T', 'L', 'J', 'Z', 'B', 'H', 'C'}};
    stack<char> c5{{'G', 'V', 'B', 'J', 'S'}};
    stack<char> c6{{'P', 'S', 'Q'}};
    stack<char> c7{{'B', 'V', 'D', 'F', 'L', 'M', 'P', 'N'}};
    stack<char> c8{{'P', 'S', 'M', 'F', 'B', 'D', 'L', 'R'}};
    stack<char> c9{{'V', 'D', 'T', 'R'}};
    vector<stack<char>> stacks{{}, c1, c2, c3, c4, c5, c6, c7, c8, c9};

    int partOne = 0;
    int partTwo = 0;
    for (int i = 0; i < 501; i++)
    {
        int a, b, c;
        string a1, b1, c1;

        scanf("%s %d %s %d %s %d", &a1[0], &a, &b1[0], &b, &c1[0], &c);

        /*
        //part 1
        for(int j = 0; j < a; j++){
            char toMove= stacks[b].top();
            stacks[b].pop();
            stacks[c].push(toMove);
        }

        */

        stack<char> temp;
        for (int j = 0; j < a; j++)
        {
            temp.push(stacks[b].top());
            stacks[b].pop();
        }
        for (int j = 0; j < a; j++)
        {
            stacks[c].push(temp.top());
            temp.pop();
        }
    }
    for (int i = 1; i < 10; i++)
    {
        cout << stacks[i].top();
    }
    cout << endl;
    return 0;
}