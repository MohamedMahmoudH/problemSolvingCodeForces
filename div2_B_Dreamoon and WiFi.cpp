/*it's not the optimal soln but it's a soln!!*/
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;


short pascal[11][11]= { {1},
                        {1, 1},
                        {1, 2, 1},
                        {1, 3, 3, 1},
                        {1, 4, 6, 4, 1},
                        {1, 5, 10, 10, 5, 1},
                        {1, 6, 15, 20, 15, 6, 1},
                        {1, 7, 21, 35, 35, 21, 7, 1},
                        {1, 8, 28, 56, 70, 56, 28, 8, 1},
                        {1, 9, 36, 84, 126, 126, 84, 36, 9, 1},
                        {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}};
void solve()
{
    short sentPos = 0 , receivedPos = 0 , error = 0;
    string sent , received ;
    cin >> sent >> received;

    for(short i = 0 ; i < sent.size() ; ++i)
    {
        switch(sent[i])
        {
            case '+':
                sentPos++;
                break;
            case '-':
                sentPos--;
        }

        switch(received[i])
        {
            case '+':
                receivedPos++;
                break;
            case '-':
                receivedPos--;
                break;
            case '?':
                error++;
        }
    }

    short diff = sentPos - receivedPos , rep = 0;
    if(diff > error) cout << (long double)0;
    else
    {
        for(rep = 0;error != diff ; diff += 2)rep++;
        long double result = (long double)pascal[error][rep] / pow(2 , error);
        cout << result;
    }
}

int main()
{
    ByMohamedMahmoud
    cout << fixed << setprecision(9);
    solve();
    return 0;
}
