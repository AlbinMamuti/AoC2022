#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <map>
#include <queue>
#include <stdlib.h>
#include <cmath>

int l = 10000;
int r = 0;
int h = 10000;
int d = 0;

bool move(int x, int y, vector<vector<char>> &grid)
{
    if (x < l || x > r || y > d)
        return false;
    if (grid[x][y + 1] == '.')
        return move(x, y + 1, grid);
    if (grid[x - 1][y + 1] == '.')
        return move(x - 1, y + 1, grid);
    if (grid[x + 1][y + 1] == '.')
        return move(x + 1, y + 1, grid);

    grid[x][y] = 'o';
    if (x == 500 && y == 0)
        return false;
    return true;
}
bool move2(int x, int y, vector<vector<char>> &grid)
{
    if (grid[x][y + 1] == '.')
        return move(x, y + 1, grid);
    if (grid[x - 1][y + 1] == '.')
        return move(x - 1, y + 1, grid);
    if (grid[x + 1][y + 1] == '.')
        return move(x + 1, y + 1, grid);

    grid[x][y] = 'o';
    if (x == 500 && y == 0)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    vector<vector<char>> grid(900, vector<char>(200, '.'));
    vector<vector<char>> grid2(900, vector<char>(200, '.'));

    for (int i = 0; i < 144; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string parts;

        int x, y, prex, prey;
        prex = 0;
        prey = 0;

        int j = 0;
        while (getline(ss, parts, ' '))
        {
            if (parts == "->")
                continue;
            stringstream kk(parts);
            string temp;
            getline(kk, temp, ',');
            x = stoi(temp);
            getline(kk, temp, ',');
            y = stoi(temp);

            l = min(l, x);
            r = max(r, x);
            h = min(h, y);
            d = max(d, y);

            if (prex == 0 && prey == 0)
            {
                prex = x;
                prey = y;
                continue;
            }
            for (int i = min(x, prex); i <= max(x, prex); i++)
            {
                grid[i][y] = '#';
                grid2[i][y] = '#';
            }
            for (int j = min(y, prey); j <= max(y, prey); j++)
            {
                grid[x][j] = '#';
                grid2[x][j] = '#';
            }
            prex = x;
            prey = y;
        }
    }

    for (int i = 0; i < 900; i++)
    {
        grid2[i][d + 2] = '#';
    }

    int sol = 0;

    bool part1 = false;

    while (1)
    {
        if (part1 && !move(500, 0, grid))
        {
            cout << sol << endl;
            return 0;
        }
        if (!part1 && !move2(500, 0, grid2))
        {
            cout << sol << endl;
            return 0;
        }
        sol++;
    }

    return 0;
}
