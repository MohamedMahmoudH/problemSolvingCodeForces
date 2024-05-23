/*
https://codeforces.com/contest/1506/problem/D
D. Epic Transformation

NOTE : TAKE A LOOK ON HASH TABLES IN C
       to calculate freq of elements :)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int freq ;
    int value;
}mapping;

int compare(const void *a , const void *b)
{
    return(*(int *)a - *(int *)b);
}
int compareMap(const void *a , const void *b) /// sorting in decreasing order with freq field
{
    const mapping *v1 = (const mapping *)a;
    const mapping *v2 = (const mapping *)b;

    return((v2 ->freq) - (v1 ->freq));
}

void solve(void)
{
    int  n;
    scanf("%d",&n);

    int *arr = (int *)calloc(n , sizeof(int));

    for(int index1 = 0 ; index1 < n ; ++index1)
    {
        scanf("%d",&arr[index1]);
    }

    qsort(arr , n , sizeof(int) , compare);
    mapping *counter = (mapping *)calloc(n , sizeof(mapping));

    int index2 = 0; /// declare outside the loop to use it after that
    counter[0].value = arr[0] ;
    counter[0].freq = 1;

    for(int index1 = 1 ; index1 < n ; ++index1)
    {
        if(counter[index2].value == arr[index1])
        {
            counter[index2].freq++;
        }
        else
        {
            ++index2;
            counter[index2].value = arr[index1];
            counter[index2].freq  = 1;
        }
    }

    qsort(counter , index2 + 1 , sizeof(mapping) , compareMap);/// use index 2 to sort only exist elements

    int x = counter[0].freq;
    if(((2 * x) <= n) && !(n % 2))
    {
        printf("0\n");
    }
    else if(((2 * x) <= n) && (n % 2))
    {
        printf("1\n");
    }
    else
    {
        printf("%d\n",((2 * x) - n));
    }

    free(arr);
    free(counter);
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


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int freq ;
    int value;
}mapping;

int compare(const void *a , const void *b)
{
    return(*(int *)a - *(int *)b);
}

int compareMap(const void *a , const void *b) /// sort in decreasing order
{
    const mapping *v1 = (const mapping *)a;
    const mapping *v2 = (const mapping *)b;

    return((v2 -> freq) - (v1 -> freq));
}

void solve(void)
{
    int n = 0 ;
    scanf("%d",&n);

    mapping *theMap = (mapping *)calloc(n , sizeof(mapping));

    int *arr = (int *)calloc(n+1 , sizeof(int));
    arr[n] = '\0';

    for(int index1 = 0 ; index1 < n ; ++index1)
    {
        scanf("%d",&arr[index1]);
        theMap[arr[index1]].freq++;
    }

    qsort(theMap , n , sizeof(mapping) , compareMap);

    int x = theMap[0].freq;
    if((2 * x) <= n)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",((2 * x) - n));
    }

    free(arr);
    free(theMap);
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
*/
