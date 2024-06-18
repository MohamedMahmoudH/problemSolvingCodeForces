#include <string>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main()
{
    ByMohamedMahmoud
    short counter = 0;
    string num;
    cin >> num;
    for(short i = 0 ; i < num.size() ; ++i)
    {
        if((num[i] == '4') || (num[i] == '7'))counter++;
    }
    cout << ((counter == 4 || counter == 7) ? "YES" : "NO");
    return 0;
}


