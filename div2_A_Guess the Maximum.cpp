#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int minNum = INT_MAX;
    unsigned short n = 0;
    cin >> n;
    vector<int> arr(n);

    cin >> arr[0];
    for(unsigned short i = 1 ; i < n ; ++i)
    {
        cin >> arr[i];
        if(max(arr[i] , arr[i - 1]) < minNum)minNum = max(arr[i] , arr[i - 1]);
    }
    cout << minNum - 1 << '\n';
}

short t;
int main()
{
    cin >> t;
    while(t--)solve();
    return 0;
}

