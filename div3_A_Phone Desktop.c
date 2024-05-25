/*
https://codeforces.com/contest/1974/problem/A
A. Phone Desktop
*/

#include <stdio.h>

void solve(void)
{
    short x , y , sc = 0 , flag = 0;
    scanf("%hi %hi",&x ,&y);

    if(y % 2)
    {
        y--;
        sc++;
        flag = 1;
    }

    sc += y / 2;

    if(flag)
    {
        if(x > ((7 * (sc - 1)) + 11))
        {
            x -= ((7 * (sc - 1)) + 11);
            sc += x /15 ;
            sc += (x %15 != 0);
        }
    }
    else
    {
        if(x > (7 * sc))
        {
            x -= (7 * sc);
            sc += x /15;
            sc += (x %15 != 0);
        }
    }
    printf("%hi\n" , sc);
}

short t;
int main()
{
    scanf("%hi",&t);
    while(t--)
    {
        solve();
    }

}
