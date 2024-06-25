#include <iostream>
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    int x1 , y1 ,x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 > y1 && x2 > y2)cout << "YES\n";
    else if(y1 > x1 && y2 > x2)cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ///ByMohamedMahmoud///
    short t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
