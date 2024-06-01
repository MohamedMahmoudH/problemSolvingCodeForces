/*
https://codeforces.com/contest/1981/problem/A
A. Turtle and Piggy Are Playing a Game
15 MIN
*/

#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(void)
{
    int l , r;
    cin >> l >> r;

    int limit = 1 , counter = 1;
    for(counter = 1 ; ((limit << 1) <= r) ; ++counter)
    {
        limit <<= 1;
    }
    cout << (counter - 1) << endl;
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
