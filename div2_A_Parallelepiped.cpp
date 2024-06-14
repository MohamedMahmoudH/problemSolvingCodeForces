#include <cmath>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

unsigned short xy , yz , zx;
int main()
{
    ByMohamedMahmoud
    cin >> xy >> yz >> zx;
    cout << 4*(sqrt(xy*zx/yz) + sqrt(yz*xy/zx) + sqrt(zx*yz/xy));
    return 0;
}
