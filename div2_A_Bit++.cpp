#include <string>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve()
{
    short n , x = 0;
    cin >> n;
    string str;
    while(n--)
    {
        cin >> str;
        (str[1] == '+')?x++:x--;
    }
    cout << x;
}

int main()
{
    ByMohamedMahmoud
    solve();
    return 0;
}


