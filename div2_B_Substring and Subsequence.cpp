#include <string>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    string str1 , str2;
    cin >> str1 >> str2;

    short size1 = str1.size() , size2 = str2.size();
    loop(i,0,size2)
    {
        auto it = str1.find(str2[i]);
        if(it != string::npos)str1.erase(it , 1);
        else size1++;
    }
    cout << size1 << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
