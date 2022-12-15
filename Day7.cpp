#include <bits/stdc++.h>
using namespace std;
#include <stack>

struct tree_node
{
    string name;
    long long size;
    std::vector<tree_node *> children;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);
    tree_node rootFIX =
        {
            "/",
            0,
            {}};
    tree_node *root = &rootFIX;
    stack<tree_node *> myStack;
    vector<tree_node *> listAllNodes;
    vector<long long> solList;
    listAllNodes.push_back(root);
    for (int i = 0; i < 1031; i++)
    {
        string line;
        getline(cin, line);
        // command
        if (line[0] == '$')
        {
            // cd
            if (line[2] == 'c')
            {
                if (line[5] == '.')
                {
                    tree_node *temp = myStack.top();
                    temp->size += root->size;
                    myStack.pop();
                    root = temp;
                    continue;
                }
                else if (line[5] == '/')
                {
                    root = &rootFIX;
                    myStack = stack<tree_node *>();
                    // myStack.emplace(root);
                    continue;
                }
                tree_node *child = new tree_node();
                child->name = line.substr(5);
                child->size = 0;
                child->children = {};
                listAllNodes.push_back(child);
                myStack.push(root);
                root->children.push_back(child);
                root = child;
            }
            // ls
            else
            {
                continue;
            }
        }
        //
        else
        {
            if (line[0] == 'd')
            {
                continue;
            }
            stringstream stream(line);
            string temp;
            getline(stream, temp, ' ');
            long long size = stoll(temp);
            root->size += size;
        }
    }
    while (!myStack.empty())
    {
        tree_node *temp = myStack.top();
        temp->size += root->size;
        myStack.pop();
        root = temp;
    }

    long long part1 = 0;
    for (int i = 0; i < listAllNodes.size(); i++)
    {
        part1 += listAllNodes[i]->size < 100000 ? listAllNodes[i]->size : 0;
        solList.push_back(listAllNodes[i]->size);
    }

    // part2
    long long need = 30000000;
    long long have = 70000000 - rootFIX.size;
    long long want = need - have;
    vector<long long> pos;
    copy_if(solList.begin(), solList.end(), back_inserter(pos), [want](long long i)
            { return i >= want; });
    sort(pos.begin(), pos.end());

    cout << part1 << endl;
    cout << pos[0] << endl;
    return 0;
}