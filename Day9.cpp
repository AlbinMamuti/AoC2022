#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <map>
#include <stdlib.h>
int H = 1000, W = 1000;

pair<int, int> distant(int hx, int hy, int tx, int ty)
{
    return {abs(hx - tx), abs(hy - ty)};
};

bool adjacient(int hx, int hy, int tx, int ty)
{
    int distX = abs(hy - tx);
    int distY = abs(hy - ty);

    return (distX >= 2) || (distY >= 2);
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    vector<vector<bool>> grid(H, vector<bool>(W));
    vector<vector<bool>> grid2(H, vector<bool>(W));

    map<char, pair<int, int>> directions;

    directions['L'] = {0, -1};
    directions['R'] = {0, 1};
    directions['U'] = {-1, 0};
    directions['D'] = {1, 0};

    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    vector<pair<int, int>> pos(10, {H / 2, W / 2});

    // head
    int hx = H / 2, hy = W / 2;

    // tail
    int tx = H / 2, ty = W / 2;

    grid[tx][ty] = true;
    grid2[tx][ty] = true;

    for (int i = 0; i < 2000; i++)
    {
        char dir;
        int dist;
        cin >> dir >> dist;
        pair<int, int> heading = directions[dir];
        for (int j = 0; j < dist; j++)
        {
            grid2[pos[9].first][pos[9].second] = true;
            pos[0].first += heading.first;
            pos[0].second += heading.second;

            for (int k = 0; k < 9; k++)
            {
                pair<int, int> distance = distant(pos[k].first, pos[k].second, pos[k + 1].first, pos[k + 1].second);
                if (distance.first <= 1 && distance.second <= 1)
                {
                    break;
                }
                else if ((distance.first == 2 && distance.second == 0))
                {
                    if (pos[k].first - pos[k + 1].first == 2)
                    {
                        pos[k + 1].first++;
                    }
                    else
                    {
                        pos[k + 1].first--;
                    }
                }
                else if ((distance.first == 0 && distance.second == 2))
                {
                    if (pos[k].second - pos[k + 1].second == 2)
                    {
                        pos[k + 1].second++;
                    }
                    else
                    {
                        pos[k + 1].second--;
                    }
                }

                else if (distance.first + distance.second == 3)
                {
                    // diagonal
                    if (pos[k].first > pos[k + 1].first)
                        pos[k + 1].first++;
                    else
                        pos[k + 1].first--;
                    if (pos[k].second > pos[k + 1].second)
                        pos[k + 1].second++;
                    else
                        pos[k + 1].second--;
                }
                else if (distance.first + distance.second == 4)
                {
                    if (pos[k].first > pos[k + 1].first)
                        pos[k + 1].first++;
                    else
                        pos[k + 1].first--;
                    if (pos[k].second > pos[k + 1].second)
                        pos[k + 1].second++;
                    else
                        pos[k + 1].second--;
                }
            }

            /* for (int k = 1; k < 10; k++)
            {
                if (adjacient(pos[k - 1].first, pos[k - 1].second, pos[k].first, pos[k].second))
                {
                    int tempX = pos[k].first + theMove.first;
                    int tempY = pos[k].second + theMove.second;
                    if (!adjacient(pos[k - 1].first, pos[k - 1].second, tempX, tempY))
                    {
                        pos[k].first = tempX;
                        pos[k].second = tempY;
                        continue;
                    }
                    tempX = pos[k - 1].first - heading.first;
                    tempY = pos[k - 1].second - heading.second;
                    if (!adjacient(pos[k - 1].first, pos[k - 1].second, tempX, tempY))
                    {
                        pos[k].first = tempX;
                        pos[k].second = tempY;
                        continue;
                    }
                    for (int m = 0; m < 8; m++)
                    {
                        int newTx = pos[k].first + dirs[m].first;
                        int newTy = pos[k].second + dirs[m].second;
                        if (!adjacient(pos[k - 1].first, pos[k - 1].second, newTx, newTy))
                        {
                            pos[k].first = newTx;
                            pos[k].second = newTy;
                            break;
                        }
                    }
                } */
        }
        /*        for (int xi = 0; xi < H; xi++)
               {
                   for (int yj = 0; yj < W; yj++)
                   {
                       bool num = false;
                       for (int k = 0; k < 10; k++)
                       {
                           if (pos[k].first == xi && pos[k].second == yj)
                           {
                               num = true;
                               if (k == 0)
                               {
                                   cout << 'H' << " ";
                               }
                               else
                               {
                                   cout << k << " ";
                               }
                               break;
                           }
                       }
                       if (!num)
                       {
                           cout << ". ";
                       }
                   }
                   cout << endl;
               }
               cout << i << endl; */
        grid2[pos[9].first][pos[9].second] = true;

        /*             hx += heading.first;
                    hy += heading.second;
                    if (adjacient(hx, hy, tx, ty))
                    {
                        tx = hx - heading.first;
                        ty = hy - heading.second;
                    }
                    if (tx < 0 || tx >= H || ty < 0 || ty >= W)
                    {
                        cout << "smoll y" << endl;
                        return 0;
                    }
                    grid[tx][ty] = true; */
    }

    int sol = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            sol += grid[i][j] ? 1 : 0;
        }
    }
    int sol2 = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            sol2 += grid2[i][j] ? 1 : 0;
        }
    }
    cout << sol << endl;
    cout << sol2 << endl;
    return 0;
}