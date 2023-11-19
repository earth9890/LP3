#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define setpr(x) cout << setprecision(x) << fixed
const ll mod = 1e9 + 7;
const ll N = 1e6 + 1;
int dp[101][N];
class Harish
{
public:
    int dpp(int i, vector<int> &weight, vector<int> &value, int n, int k)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i][k])
        {
            return dp[i][k];
        }
        int ans = 0;
        if ((k - weight[i]) >= 0)
            ans = max(ans, dpp(i + 1, weight, value, n, k - weight[i])) + value[i];
        ans = max(ans, dpp(i + 1, weight, value, n, k));

        dp[i][k] = ans;
        return ans;
    }
    void hari()
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> wieght(n);
        vector<int> value(n);

        for (int i = 0; i < n; i++)
        {
            cin >> wieght[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        cout << dpp(0, wieght, value, n, k);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    Harish h;
    int t = 1;
    while (t--)
    {
        h.hari();
    }
}

// 3 8 3 4 5 30 50 60 = 90

// 6 15 6 5 5 6 6 4 6 6 3 5 7 2 = 17 (cin>>wt>>val);
