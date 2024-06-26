/*
ID: 06jajun
TASK: template
LANG: C++17
*/

//

#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int dp[201][201];
int actual[201][201];
int topDP[201];
int leftDP[201];
int rightDP[201];
int bottomDP[201];
ifstream fin ("paintbarn.in");
ofstream fout ("paintbarn.out");

int rectangleSum(int a, int b, int x, int y) {
    return actual[a+x][b+y] - actual[a][b+y] - actual[a+x][b] + actual[a][b];
}

int main() {
    int n, k;
    fin >> n >> k;
    while(n--) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        dp[a][b]++;
        dp[a][d]--;
        dp[c][b]--;
        dp[c][d]++;
    }
    int currAmt = 0;
    int ret = 0;

    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            if(i) dp[i][j] += dp[i-1][j];
            if(j) dp[i][j] += dp[i][j-1];
            if(i && j) dp[i][j] -= dp[i-1][j-1];
            if(dp[i][j] == k-1) actual[i+1][j+1] = 1;
            if(dp[i][j] == k) {
                currAmt++;
                actual[i+1][j+1] = -1;
            }
        }
    }
    for (int i=0; i<9; i++) {
        for (int j=0; j<8; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } cout << endl;
    for (int i=0; i<9; i++) {
        for (int j=0; j<8; j++) {
            cout << actual[i][j] << ' ';
        }
        cout << endl;
    } cout << endl;
    for(int i = 1; i <= 200; i++) {
        for(int j = 1; j <= 200; j++) {
            actual[i][j] += actual[i-1][j];
            actual[i][j] += actual[i][j-1];
            actual[i][j] -= actual[i-1][j-1];
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<9; j++) {
            cout << actual[i][j] << ' ';
        }
        cout << endl;
    } cout << endl;
    for(int lhs = 0; lhs <= 200; lhs++) {
        for(int len = 1; lhs + len <= 200; len++) {
            int topSum = 0;
            int leftSum = 0;
            int rightSum = 0;
            int bottomSum = 0;
            for(int i = 1; i <= 200; i++) {
                ret = max(ret, topDP[i] = max(topDP[i], topSum = max(0, topSum + rectangleSum(i-1, lhs, 1, len))));
                ret = max(ret, leftDP[i] = max(leftDP[i], leftSum = max(0, leftSum + rectangleSum(lhs, i-1, len, 1))));
                ret = max(ret, rightDP[i] = max(rightDP[i], rightSum = max(0, rightSum + rectangleSum(lhs, 200-i, len, 1))));
                ret = max(ret, bottomDP[i] = max(bottomDP[i], bottomSum = max(0, bottomSum + rectangleSum(200-i, lhs, 1, len))));
            }
        }
    }
    for(int i = 2; i <= 200; i++) {
        topDP[i] = max(topDP[i], topDP[i-1]);
        leftDP[i] = max(leftDP[i], leftDP[i-1]);
        rightDP[i] = max(rightDP[i], rightDP[i-1]);
        bottomDP[i] = max(bottomDP[i], bottomDP[i-1]);
    }
    for(int i = 1; i <= 199; i++) {
        ret = max(ret, topDP[i] + bottomDP[200-i]);
        ret = max(ret, leftDP[i] + rightDP[200-i]);
    }
    fout << ret + currAmt << "\n";
}
