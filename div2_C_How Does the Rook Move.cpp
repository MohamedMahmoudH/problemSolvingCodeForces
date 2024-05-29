///first problem in dynamic programming : 170 min
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define MOD 1000000007
#define MAX 300005
using namespace std;

void solve(int *dp)
{
    int n , k;
    cin >> n >> k;
    for(int index1 = 0 ; index1 < k ; ++index1)
    {
        int r , c;
        cin >> r >> c;
        if(r == c)--n;
        else   n -= 2;
    }
    if(n <= 0) cout << 1 << endl;
    else   cout << dp[n] << endl;
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    int *dp = new int [MAX]();
    dp[0] = dp[1] = 1 ; // as a base case
    for(int index1 = 2 ; index1 <= (MAX - 5) ; ++index1) // memoization
    {
          dp[index1] = (dp[index1 - 1] + ((2LL * (index1 - 1) % MOD) * dp[index1 - 2]) % MOD) % MOD;
    }
    while(t--)
    {
        solve(dp);
    }
    delete[] dp; dp = nullptr;
    return 0;
}
