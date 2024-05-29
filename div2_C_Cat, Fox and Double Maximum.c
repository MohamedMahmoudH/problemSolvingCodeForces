#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int indexx ;
    int value  ;
}mapping;

int compare(const void *a, const void *b)
{
    mapping *mapA = (mapping *)a;
    mapping *mapB = (mapping *)b;
    return ((mapA -> value) - (mapB -> value));
}

void Reverse(mapping *arr , int Begin , int end)
{
    mapping temp ;
    while(Begin < end)
    {
        temp       = arr[Begin];
        arr[Begin] = arr[end];
        arr[end]   = temp;

        --end;
        ++Begin;
    }
}

void localMax(mapping *localMax , mapping *localMin , int n)
{
    Reverse(localMin , 0 , (n/2) - 1);

    int *add = (int *)calloc(n , sizeof(int));
    int start = 1 ;
    int end   = n ;
    for(int ii = 0 ; ii < n/2 ; ++ii)
    {
        add[localMin[ii].indexx] = start;
        add[localMax[ii].indexx] = end  ;

        ++start;
        --end;
    }

    for(int ii = 0 ; ii < n ; ++ii)
    {
        printf("%d ",add[ii]);
    }
    printf("\n");

    free(add);
}

int n;
void solve(void)
{
    int indexOfBig = 0;
    scanf("%d",&n);
    int *arr = (int *)calloc(n , sizeof(int));
    mapping *theMapOdd  = (mapping *)calloc(n/2 , sizeof(mapping));
    mapping *theMapEven = (mapping *)calloc(n/2 , sizeof(mapping));

    for(int ii = 0 ; ii < n ; ++ii)
    {
        scanf("%d",&arr[ii]);
        if(ii % 2)
        {
            theMapOdd[ii / 2].value  = arr[ii];
            theMapOdd[ii / 2].indexx = ii;
        }
        else
        {
            theMapEven[ii / 2].value  = arr[ii];
            theMapEven[ii / 2].indexx = ii;
        }

        if(arr[ii] == n)
        {
            indexOfBig = ii;
        }
    }

    qsort(theMapEven , n/2 , sizeof(mapping) , compare);
    qsort(theMapOdd  , n/2 , sizeof(mapping) , compare);

    if(indexOfBig % 2) // then "n" with odd indexes ---> odd is the local max
    {
        localMax(theMapOdd , theMapEven , n);
    }
    else
    {
        localMax(theMapEven , theMapOdd , n);
    }

    free(arr);
    free(theMapEven);
    free(theMapOdd );
}

short t ;
int main()
{
    scanf("%hi",&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
