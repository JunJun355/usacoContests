/*
ID: 06jajun
TASK: cowmbat
LANG: C++17
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

#define MXN 100001
#define MXM 26
#define INF 1000000000

int n, m, k;
int s[MXN];
int adj[MXM][MXM];
int prefix[MXM][MXN];
int dp[MXM][MXN];
int min_dp[MXN];

ifstream fin ("cowmbat.in");
ofstream fout ("cowmbat.out");

int main() {
    //inputs
    fin >> n >> m >> k;
    string temp; fin >> temp;
    for (int i=0; i<n; i++) s[i] = (int)(temp[i] - 'a');
    for (int i=0; i<m; i++) for (int j=0; j<m; j++) fin >> adj[i][j];

    //Floyd-Warshall
    for (int b=0; b<m; b++) for (int a=0; a<m; a++) for (int c=0; c<m; c++) 
        adj[a][c] = min(adj[a][c], adj[a][b] + adj[b][c]);
    
    for (int i=0; i<MXM; i++) for (int j=0; j<MXN; j++) dp[i][j] = INF;
    for (int i=0; i<MXN; i++) min_dp[i] = INF;

    for (int i=0; i<m; i++) {
        for (int j=1; j<=n; j++) {
            prefix[i][j] = prefix[i][j - 1] + adj[s[j - 1]][i];
        }
    }
    min_dp[0] = 0;
    // for (int i=1; i<=n; i++) {
    //     for (int j=0; j<m; j++) {
    //         dp[j][i] = min(dp[j][i], dp[j][i - 1] + adj[s[i]][j]);
    //         if (i >= k) dp[j][i] = min(dp[j][i], min_dp[i-k] + prefix[s[i]][j] - prefix[s[i]][j]);
    //         min_dp[0] = min(min_dp[i], dp[j][i]); 
    //     }
    // }
    // for (int i=0; i<m; i++) {
    //     for (int j=k; j<=n; j++) {
    //         dp[i][j] = min(dp[i][j], min(dp[i][j - 1] + adj[s[j - 1]][i], min_dp[j - k] + prefix[i][j] - prefix[i][j - k]));
    //         min_dp[j] = min(min_dp[j], dp[i][j]);
    //         // cout << (char)(i + 'a') << ' ' << (char)(s[j] + 'a') << dp[i][j] << endl;
    //     }
    // }
    for (int j=k; j<=n; j++) {
        for (int i=0; i<m; i++) {
            dp[i][j] = min(dp[i][j], dp[i][j-1]+adj[s[j - 1]][i]);
            dp[i][j] = min(dp[i][j], prefix[i][j]-prefix[i][j-k]+min_dp[j-k]);
            //cout << "dp " << i << " " << j << " " << dp[i][j] << "\n";
            min_dp[j] = min(min_dp[j], dp[i][j]);
        }
    }
    fout << min_dp[n] << endl;
}
