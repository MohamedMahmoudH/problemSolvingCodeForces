#include <cmath>
#include <iostream>
#include <algorithm>
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    short x1 , x2 ,x3;
    short a = 0, b = 0 , c = 0;
    cin >> x1 >> x2 >> x3;

    a = abs(x1 - x1) + abs(x2 - x1) + abs(x3 - x1);
    b = abs(x1 - x2) + abs(x2 - x2) + abs(x3 - x2);
    c = abs(x1 - x3) + abs(x2 - x3) + abs(x3 - x3);
    cout << min(min(a , b) , c) << '\n';
}

int main()
{
    ///ByMohamedMahmoud///
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
