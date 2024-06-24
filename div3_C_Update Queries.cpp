#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    int n , m;
    cin >> n >> m;
    vector<int> arr(m);
    string str1 , str2 ;
    cin >> str1;
    loop(i,0,m)cin >> arr[i];
    cin >> str2;

    sort(all(str2));
    sort(all(arr));

    int x = 0 , y = 0;
    loop(i,0,m)
    {
        if(x == arr[i])continue;
        x = arr[i];
        str1[x-1] = str2[y++];
    }
    cout << str1 <<'\n';

}

int main()
{
    ///ByMohamedMahmoud///
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
