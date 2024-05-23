#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char code;
    int  indexx;
}mapping;

int compare(const void *a , const void *b)
{
    const mapping *v1 = (const mapping *)a;
    const mapping *v2 = (const mapping *)b;

    if((v1 -> code) != (v2 -> code)){
        return ((v1 -> code) - (v2 -> code));
    }else{
        return ((v1 -> indexx) - (v2 -> indexx));
    }
}

void remainder(int big , int i_big , int counter , char *op , mapping *mars)// counter = big - small
{
    while(counter--) // counter must be even
    {
        op[mars[i_big].indexx] = ((counter % 2) ? 'R' : 'H');
        ++i_big;
    }
}


void solve()
{
    int n;
    int N = 0, S = 0, E = 0, W = 0;
    int index1 = 0 , index2 = 0;
    scanf("%d",&n);

    mapping *mars = (mapping *)calloc(n , sizeof(mapping));

    char *str = (char *)calloc(n ,sizeof(char));
    char *op  = (char *)calloc(n+1 ,sizeof(char));//output
    memset(op , '1' , n);

    for(index1 = 0 ; index1 < n ; index1++)
    {
        scanf(" %c",&str[index1]);
        //getchar();

        mars[index1].code   = str[index1];
        mars[index1].indexx = index1;

        if(str[index1] == 'N') N++;
        else if(str[index1] == 'S') S++;
        else if(str[index1] == 'E') E++;
        else if(str[index1] == 'W') W++;
    }

    qsort(mars , (n) , sizeof(mapping) , compare);

    /**************************************************************************************************************
    printf("code\tindex\n");
    for(int index5 = 0 ; index5 < n ; ++index5)
    {
        printf("  %c  \t  %d  \n",mars[index5].code , mars[index5].indexx);
    }
    /**************************************************************************************************************/

    int x = N - S ;
    int y = W - E ;

    if((n % 2) || (x % 2) || (y % 2) || ((!x && !y) && (2 == n)))
    {
        printf("NO\n");
    }
    else
    {
        if(N >= S)x = S;
        else x = N;

        if(W >= E)y = E;
        else y = W;

        index1 = E; //beginning of N
        index2 = 0;
        while(x--)
        {
            op[mars[index1    ].indexx] = ((index2 % 2)? 'H' : 'R');
            op[mars[index1 + N].indexx] = ((index2 % 2)? 'H' : 'R');
            ++index1;
            ++index2;
        }

        index1 = index2 = 0;
        while(y--)
        {
            op[mars[index1      ].indexx] = ((index2 % 2)? 'R' : 'H');
            op[mars[index1+E+N+S].indexx] = ((index2 % 2)? 'R' : 'H');
            ++index1;
            ++index2;
        }

        if(N != S)
        {
            if(N > S)
            {
                remainder(N , (E + S) , (N - S) , op , mars);
            }
            else
            {
                remainder(S , (E +2*N) , (S - N) , op , mars);
            }
        }
        if(E != W)
        {
            if(E > W)
            {
                remainder(E , W , (E - W) , op , mars);
            }
            else
            {
                remainder(W , (2*E + N + S) , (W - E), op , mars);
            }
        }
        op[n] = '\0';
        printf("%s\n",op);
    }

    free(mars);
    free(str );
    free(op  );
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
