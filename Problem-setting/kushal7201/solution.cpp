#include <bits/stdc++.h>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

int maxCaloriesBurnt(int A[][MAX_COLS], int n, int m)
{
    // Arrays to store the calories burnt from various directions
    int boyStart[MAX_ROWS + 1][MAX_COLS + 1], boyEnd[MAX_ROWS + 1][MAX_COLS + 1];
    int girlStart[MAX_ROWS + 1][MAX_COLS + 1], girlEnd[MAX_ROWS + 1][MAX_COLS + 1];

    memset(boyStart, 0, sizeof(boyStart));
    memset(boyEnd, 0, sizeof(boyEnd));
    memset(girlStart, 0, sizeof(girlStart));
    memset(girlEnd, 0, sizeof(girlEnd));

    // Calculate calories burnt when moving right and down for the boy
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            boyStart[i][j] = max(boyStart[i - 1][j], boyStart[i][j - 1]) + A[i - 1][j - 1];

    // Calculate calories burnt when moving left and up for the girl
    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            girlStart[i][j] = max(girlStart[i + 1][j], girlStart[i][j - 1]) + A[i - 1][j - 1];

    for (int i = 1; i <=n ; i++)
        for (int j = m; j >= 1; j--)
            girlEnd[i][j] = max(girlEnd[i - 1][j], girlEnd[i][j + 1]) + A[i - 1][j - 1];

    for (int i = n; i >=1 ; i--)
        for (int j = m; j >= 1; j--)
            boyEnd[i][j] = max(boyEnd[i + 1][j], boyEnd[i][j + 1]) + A[i - 1][j - 1];

    int maxCalories = 0;

    // Iterate through the cells and find the maximum sum of calories
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            int option1 = boyStart[i][j - 1] + boyEnd[i][j + 1] + girlStart[i + 1][j] + girlEnd[i - 1][j];
            int option2 = boyStart[i - 1][j] + boyEnd[i + 1][j] + girlStart[i][j - 1] + girlEnd[i][j + 1];
            maxCalories = max(maxCalories, max(option1, option2));
        }
    }

    return maxCalories;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int A[MAX_ROWS][MAX_COLS];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>A[i][j];
            }
        }
        cout<<maxCaloriesBurnt(A,n,m)<<endl;
    }

    return 0;
}
