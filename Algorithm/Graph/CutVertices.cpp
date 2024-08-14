#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adl;
vector<bool> visited;
vector<int> orderList;
vector<bool> result;
int order = 1;

int dfs(int v, bool isStart)
{

    visited[v] = true;
    orderList[v] = order++;
    int childNum = 0;

    int returnV = orderList[v];

    for (int i = 0; i < adl[v].size(); i++)
    {
        int child = adl[v][i];

        if (!visited[child])
        {
            childNum++;
            int low = dfs(child, false);
            returnV = min(returnV, low);

            if ((low >= orderList[v]) && !isStart)
            {
                result[v] = true;
            }
        }
        else
        {
            // visited
            returnV = min(returnV, orderList[child]);
        }
    }

    if (isStart && childNum > 1)
    {

        result[v] = true;
    }

    return returnV;
}

int main()
{
    // make temp adl
    adl = vector<vector<int>>(5);
    adl[0].push_back(1);
    adl[1].push_back(0);
    adl[1].push_back(2);
    adl[2].push_back(1);
    adl[2].push_back(3);
    adl[3].push_back(2);
    adl[3].push_back(4);
    adl[4].push_back(3);

    visited = vector<bool>(5, false);
    orderList = vector<int>(5, 0);
    result = vector<bool>(5, false);

    dfs(0, true);

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}
