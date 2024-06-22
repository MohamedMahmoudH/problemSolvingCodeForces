#include <string>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define MOD 1000000007
using namespace std;

void solve()
{
    short n , m;
    string str , need;
    cin >> n >> m >> str;
    while(m--)need += "ABCDEFG";

    size_t pos = 0; n = 0;
    for(char x : need)
    {
        pos = str.find(x);
        if(pos != string::npos)str.erase(pos , 1);
        else n++;
    }
    cout << n << '\n';
}

short t;
int main()
{
    cin >> t;
    while(t--)solve();
    return 0;
}
