/*
https://codeforces.com/contest/1973/problem/A
A. Chess For Three
*/

#include <stdio.h>

void solve(void)
{
    short p1 = 0 ;
    short p2 = 0 ;
    short p3 = 0 ;

    scanf("%hi %hi %hi",&p1,&p2,&p3);
    getchar();

    if((p1 + p2 + p3) % 2)
    {
        printf("-1\n");
    }
    else if((p1 + p2) <= p3)
    {
        printf("%hi\n",(p1 + p2));
    }
    else
    {
        printf("%hi\n",(p3 + ((p1 + p2 - p3)/2)));
    }
}

short t;//test cases
int main()
{
    scanf("%hi",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
