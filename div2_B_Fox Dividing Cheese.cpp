#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()

const int OO = 0x3f3f3f3f;
using namespace std;

unordered_map<int , unordered_map<int , int>> dp;
int recursion(int a, int b)
{
    if (a == b) return 0;
    if (b > a) swap(a, b);
    if (dp[a].count(b)) return dp[a][b];

    int result = min((a % 5) ? OO : 1 + recursion(a / 5, b),
                 min((a % 3) ? OO : 1 + recursion(a / 3, b),
                     (a % 2) ? OO : 1 + recursion(a / 2, b)));

    return dp[a][b] = result;
}

void solve()
{
    int a , b;
    cin >> a >> b;
    int x = recursion(a,b);
    if(x == OO)x = -1;
    printf("%d",x);
}

int main()
{
    ByMohamedMahmoud
    solve();
    return 0;
}

/*
NOTE :: you can't use this solution because dp[a] changing with respect to b

unordered_map<int, int> dp;
int recursion(int a , int b)
{
    if(a == b) return 0;
    if(b > a)swap(a ,b);
    //if(dp.find(a) != dp.end()) return dp[a];
    if(dp.count(a)) return dp[a];

    return dp[a] = min((a % 5)? OO : 1 + recursion(a / 5 , b) , min((a % 3)? OO : 1 + recursion(a / 3 , b) , (a % 2)? OO : 1 + recursion(a / 2 , b)));
}
*/
