/***
 *
 *
 *
 *
 * 시간 제한	메모리 제한
    3.0 초	512 MB
    문제
    M * N 격자로 이루어진 도시가 있다. 이 도시 군데군데에는 폐지가 버려져 있다.

    범수는 가장 왼쪽 위 격자 (1, 1)에서 출발하여 가장 오른쪽 아래 격자 (M, N)까지 이동하며 폐지를 줍는데, 최단 경로를 따라가야만 한다. 즉, 인접한 오른쪽 칸 또는 아래쪽 칸으로만 이동할 수 있다.

    여기에 더해, (M, N)에서 다시 (1, 1)으로 이동하면서 폐지를 더 줍는다. 역시 최단 경로를 따라가야 한다. 즉, 인접한 왼쪽 칸 또는 위쪽 칸으로만 이동할 수 있다.

    폐지를 한번 주우면 없어진다는 것에 유의하자.

    이 때, 범수가 수집할 수 있는 폐지의 최대값을 출력하시오.

    입력
    첫 줄에는 테스트 케이스의 수를 나타내는 T(1 ≤ T ≤ 20)가 주어진다.

    각 테스트 케이스의 첫 줄에는 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 M줄에 N개의 문자가 주어진다.

    '*'는 갈 수 있으며 폐지가 있는 곳을 나타낸다.

    '.'는 갈 수 있지만 폐지가 없는 곳을 나타낸다.

    '#'는 갈 수 없는 곳을 나타낸다.

    (1, 1)과 (M, N)은 갈 수 있는 곳임이 보장된다.

    또, 이 두 점 사이에 경로가 있음도 보장된다.

    출력
    각 테스트 케이스에 대해, 범수가 주울 수 있는 최대 폐지 수를 한 줄에 하나씩 출력한다.

    힌트
    예제 입력

    2
    9 7
 *........
    .....**#.
    ..**...#*
    ..####*#.
    .*.#*.*#.
    ...#**...
 *........
    5 5
    .*.*.
 *###.
 *.*.*
    .###*
    .*.*.
    예제 출력

    7
    8
    예제 보충

    첫 번째 테스트 케이스에서, 범수가 (M, N)까지 가면 도시는 다음과 같이 변한다.

    xxxxx....
    ....xxx#.
    ..**..x#*
    ..####x#.
    .*.#*.x#.
    ...#**xxx
 *.......x
    x는 범수의 이동 경로를 나타낸다. 지금까지 수집한 폐지는 5개이다. 다시 (1, 1)로 가면 도시는 다음과 같이 변한다.

    yxxxx....
    y...xxx#.
    yyyyyyy#*
    ..####y#.
    .*.#*.y#.
    ...#**yxx
 *.....yyy
    y는 범수의 이동 경로를 나타낸다. 범수가 모은 총 폐지 양은 7개이므로 7를 출력한다.

    두 번째 테스트 케이스의 경우, 해는 다음과 같다.

    yxxxx
    y###x
    y.*.x
    y###x
    yyyyy
 *
 *
 *
 *
 *
 */

// 1. Exhaustive search

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int N, M;
//     cin >> N >> M;

//     // Grid to store waste paper information
//     vector<vector<int>> A(N + 1, vector<int>(M + 1, 0));

//     // Reading the grid input
//     for (int i = 1; i <= N; ++i)
//     {
//         string line;
//         cin >> line;
//         for (int j = 1; j <= M; ++j)
//         {
//             if (line[j - 1] == '*')
//             {
//                 A[i][j] = 1; // Waste paper
//             }
//             else if (line[j - 1] == '#')
//             {
//                 A[i][j] = -1; // Blocked cell
//             }
//         }
//     }

//     // Initialize a 4D DP table with dimensions for two paths
//     vector<vector<vector<vector<int>>>> D(N + 1, vector<vector<vector<int>>>(M + 1, vector<vector<int>>(N + 1, vector<int>(M + 1, -1))));

//     // Base case: both paths start at (1, 1)
//     D[1][1][1][1] = A[1][1]; // If there's waste paper at (1, 1), we start with it

//     // Process all possible states
//     for (int i1 = 1; i1 <= N; ++i1)
//     {
//         for (int j1 = 1; j1 <= M; ++j1)
//         {
//             for (int i2 = 1; i2 <= N; ++i2)
//             {
//                 for (int j2 = 1; j2 <= M; ++j2)
//                 {
//                     // Skip invalid positions or blocked cells
//                     if (A[i1][j1] == -1 || A[i2][j2] == -1)
//                         continue;
//                     // you can assume the column of A is always left or equal to the column of B
//                     if (j1 > j2)
//                         continue;

//                     // Maximize from four previous states
//                     int value = -1;
//                     if (i1 > 1 && i2 > 1)
//                         value = max(value, D[i1 - 1][j1][i2 - 1][j2]);
//                     if (i1 > 1 && j2 > 1)
//                         value = max(value, D[i1 - 1][j1][i2][j2 - 1]);
//                     if (j1 > 1 && i2 > 1)
//                         value = max(value, D[i1][j1 - 1][i2 - 1][j2]);
//                     if (j1 > 1 && j2 > 1)
//                         value = max(value, D[i1][j1 - 1][i2][j2 - 1]);

//                     if (value == -1)
//                         continue; // If no valid previous state, skip

//                     D[i1][j1][i2][j2] = value + A[i1][j1]; // Add waste paper at i1,j1

//                     // If the two paths are on different cells, add waste paper from the second path
//                     if (i1 != i2 || j1 != j2)
//                     {
//                         D[i1][j1][i2][j2] += A[i2][j2];
//                     }
//                 }
//             }
//         }
//     }

//     // The final result will be the maximum waste collected when both paths finish at (N, M)
//     cout << D[N][M][N][M] << endl;

//     return 0;
// }

// 2. Using the number of move

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(M + 1, vector<int>(N + 1, 0));
    vector<vector<vector<int>>> dp(M + N - 1, vector<vector<int>>(M + 1, vector<int>(M + 1, -1)));

    for (int i = 1; i <= M; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j <= N; j++)
        {
            if (line[j - 1] == '*')
            {
                grid[i][j] = 1;
            }
            else if (line[j - 1] == '#')
            {
                grid[i][j] = -1; // Blocked cell
            }
        }
    }

    dp[0][1][1] = (grid[1][1] == 1) ? 1 : 0;
    // M+N-2 is the number of moves
    for (int i = 1; i <= M + N - 2; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 1; k <= M; k++)
            {

                int y1 = i - j + 2;
                int y2 = i - k + 2;

                if (j > i + 1 || k > i + 1)
                    continue;

                // Ensure positions are valid and within bounds
                if (y1 < 1 || y1 > N || y2 < 1 || y2 > N || grid[j][y1] == -1 || grid[k][y2] == -1)
                {
                    continue; // Skip blocked cells or out-of-bounds positions
                }

                int max_prev = -1;
                if (j > 1 && k > 1)
                    max_prev = max(max_prev, dp[i - 1][j - 1][k - 1]);
                if (j > 1)
                    max_prev = max(max_prev, dp[i - 1][j - 1][k]);
                if (k > 1)
                    max_prev = max(max_prev, dp[i - 1][j][k - 1]);
                max_prev = max(max_prev, dp[i - 1][j][k]);

                if (max_prev == -1)
                    continue;

                dp[i][j][k] = max_prev + grid[j][y1];
                if (j != k)
                {
                    dp[i][j][k] += grid[k][y2];
                }
            }
        }
    }

    cout << dp[M + N - 2][M][M] << endl;

    return 0;
}
