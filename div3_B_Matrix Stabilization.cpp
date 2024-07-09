/* HACKED */
#include <vector>
#include <iostream>
#include <algorithm>
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

short n , m;
int x = 1;
void who(int **arr)
{
    x = 0;
    loop(i,1,n+1)
    {
        loop(j,1,m+1)
        {
            x = arr[i][j];
            if(x > arr[i-1][j] && x > arr[i+1][j] && x > arr[i][j-1] && x > arr[i][j+1])
            {
                arr[i][j] = max(max(arr[i-1][j] ,  arr[i+1][j]) , max(arr[i][j-1] , arr[i][j+1]));
                who(arr);
            }
        }
    }
    x = 0;
}

void solve()
{
    cin >> n >> m;

    int** arr = new int*[n+2];
    loop(i, 0, n+2)
    {
        arr[i] = new int[m+2]();
    }

    loop(i,1,n+1)
    {
        loop(j,1,m+1)
        {
            cin >> arr[i][j];
        }
    }
    who(arr);
    loop(i,1,n+1)
    {
        loop(j,1,m+1)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    loop(i, 0, n+2)
    {
        delete[] arr[i];
    }
    delete[] arr;

}

int main()
{
    ///ByMohamedMahmoud///
    short t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
