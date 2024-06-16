#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

string solve()
{
    int n;
    cin >> n;
    vector<unsigned int> segments(n);
    for(int i = 0 ; i < n ; ++i) cin >> segments.at(i);
    sort(segments.begin() , segments.end());
    for(int i = 2 ; i < n ; ++i)
    {
        if(segments.at(i) < (segments.at(i - 1) + segments.at(i - 2)))
            return "YES";
    }
    return "NO";
}

int main()
{
    ByMohamedMahmoud
    cout << solve();
    return 0;
}
