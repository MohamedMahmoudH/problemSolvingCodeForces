#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

short t;
int main()
{
    cin >> t;
    while(t--)
    {
        int x , y ;
        cin >> x >> y;
        x = x ^ y;
        y = floor(log2(x));
        while(x)
        {
            x -= pow(2 , y);
            if(x)y = floor(log2(x));
        }
        cout << (unsigned long long)pow(2 , y) << '\n';
    }
    return 0;
}

