/*
https://codeforces.com/contest/1957/problem/B
B. A BIT of a Construction
*/

#include <stdio.h>

void solve(void)
{
    int n , k;
    int counter = 0 ;
    scanf("%d %d",&n,&k);

    if(n == 1)
    {
        printf("%d\n",k);
    }
    else
    {
        int limit = 1;
        for(counter = 0 ; ((limit << 1) <= k) ; ++counter)
        {
            limit <<= 1 ;
        }

        --limit;
        printf("%d %d",limit, k - limit);
        for(counter = 2 ; counter < (n) ; ++counter)
        {
            printf(" 0");
        }
        printf("\n");
    }
}

short t;
int main()
{
    scanf("%hi",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
