#include <bits/stdc++.h>
using namespace std;
#include <stack>

int H = 99;
int L = 99;

bool check(vector<vector<int>> grid, int x, int y, int dx, int dy)
{
    int myHeight = grid[x][y];
    while (x >= 0 && y >= 0 && x < H && y < L)
    {
        x += dx;
        y += dy;
        if (x >= 0 && y >= 0 && x < H && y < L)
        {
            if (myHeight <= grid[x][y])
            {
                return false;
            }
        }
    }
    return true;
}
int check2(vector<vector<int>> grid, int x, int y, int dx, int dy)
{
    int myHeight = grid[x][y];
    int dist = 0;
    while (x >= 0 && y >= 0 && x < H && y < L)
    {
        x += dx;
        y += dy;
        if (x >= 0 && y >= 0 && x < H && y < L)
        {
            if (myHeight <= grid[x][y])
            {
                return dist + 1;
            }
            dist++;
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    vector<vector<int>> grid;

    for (int i = 0; i < H; i++)
    {
        string line;
        getline(cin, line);
        vector<int> row;
        for (int j = 0; j < L; j++)
        {
            row.push_back(line[j] - '0');
        }
        grid.push_back(row);
    }
    vector<pair<int, int>> dir{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int sol = 0;
    int sol2 = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < L; j++)
        {
            bool vis = false;
            int dist = 1;
            for (int k = 0; k < 4; k++)
            {
                vis |= check(grid, i, j, dir[k].first, dir[k].second);
                dist *= check2(grid, i, j, dir[k].first, dir[k].second);
            }
            if (vis)
            {
                sol++;
            }
            sol2 = dist > sol2 ? dist : sol2;
        }
    }
    cout << sol << endl;
    cout << sol2 << endl;
    return 0;
}