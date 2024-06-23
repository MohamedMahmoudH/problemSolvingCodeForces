#include <vector>
#include <iostream>
#include <algorithm>
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;


void solve()
{
    int n , c , d , minNum = 0 , x = 0 ;
    cin >> n >> c >> d;

    vector<int> input(n*n);
    loop(i,0,n*n) cin >> input[i];

    sort(all(input));
    minNum = input[0];

    vector<int> square;
    loop(i,0,n)
    {
        x = minNum + c*i;
        loop(j,0,n)
        {
            square.push_back(x);
            x += d;
        }
    }
    sort(all(square));
    if(input == square)cout << "YES\n";
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
