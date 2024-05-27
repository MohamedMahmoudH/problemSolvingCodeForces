/*
https://codeforces.com/contest/1957/problem/A
A. Stickogon
*/

#include <stdio.h>
#include <stdlib.h>

int rev(const void *a , const void *b)
{
    return(*(short *)b - *(short *)a);
}

void solve(void)
{
    short n , polygons = 0;
    short index1 = 0;
    scanf("%hi",&n);

    short *arr  = (short *)calloc(n+1 , sizeof(short));
    short *freq = (short *)calloc(101 , sizeof(short));
    for(index1 = 0 ; index1 < n ; ++index1)
    {
        scanf("%hi",&arr[index1]);
        freq[arr[index1]]++;
    }

    if(n <= 2)
    {
        printf("0\n");
    }
    else
    {
        qsort(freq , 101 , sizeof(short) , rev);
        for(index1 = 0 ; (freq[index1] != 0) ; ++index1)
        {
            polygons += (freq[index1] / 3);
        }
        printf("%hi\n",polygons);
    }

    free(freq);
    free(arr);
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
