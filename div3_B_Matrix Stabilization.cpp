#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    loop(i,0,n)loop(j,0,m)cin >> v[i][j];;
    loop(i,0,n)
    {
        loop(j,0,m)
        {
            int mx = 0;
            if (i > 0) mx = max(mx, v[i - 1][j]);
            if (i < n - 1) mx = max(mx, v[i + 1][j]);
            if (j > 0) mx = max(mx, v[i][j - 1]);
            if (j < m - 1) mx = max(mx, v[i][j + 1]);
            if (mx != 0 && v[i][j] > mx) v[i][j] = mx;
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while (t--)solve();
    return 0;
}
