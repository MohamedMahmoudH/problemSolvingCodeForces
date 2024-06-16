#include <string>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int solve()
{
    bool flag = false;
    short n , m , x ;
    cin >> n >> m >> x;
    string keyboard[n] , sentence;
    for(short i = 0 ; i < n ; ++i)
    {
        cin >> keyboard[i];
        if(keyboard[i].find('S') != string::npos)
        {
            flag = true;
            ///---------------------------
        }
    }
    int q , result = 0;
    char ch = 0;
    cin >> q >> sentence;
    sort(sentence.begin() , sentence.end());
    for(int i = 0 ; i < q ; ++i)
    {
        if(ch == sentence[i])continue;
        if(sentence[i] <= 'Z')
        {
            if(flag)ch = sentence[i] + 32; else return -1;
            for(short j = 0 ; j < n ; ++j)
            {
                if(keyboard[j].find(ch) == string::npos)return -1;
            }
        }
        else
        {
            for(short j = 0 ; j < n ; ++j)
            {
                if(keyboard[j].find(sentence[i]) == string::npos)return -1;
            }
        }
        ch = sentence[i];
    }

}

int main()
{
    ByMohamedMahmoud
    cout << solve();
    return 0;
}
