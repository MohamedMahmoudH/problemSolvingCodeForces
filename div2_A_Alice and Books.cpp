#include <vector>
#include <iostream>
using namespace std;

void solve()
{
    short n;
    cin >> n;
    int bigger = 0;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> a.at(i);
        if(bigger <= a.at(i) && i != n-1)bigger = a.at(i);
    }
    cout << bigger + a.at(n - 1) << '\n';
}

short t;
int main()
{
    cin >> t;
    while(t--)solve();
    return 0;
}
