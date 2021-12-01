#include <iostream>
#include <math.h>
using namespace std;
bool isprime(int n)
{
    int m = sqrt(n);
    for (int k = 2; k <= m; k++)
    {
        if (m % k == 0)
        {
            return false;
            cout<<n<<endl;
            
        }
        else
        {
            return true;
        }
    }

    
}

int main()
{
    int i, j = 0, max[30];
    for (i = 1; i <= 100; i++)
    {

        if (isprime(i) == true)
        {
			cout<<"here";
            max[j] = i;
            j++;
            
        }
    }
    cout << "The Second Largest Prime will be: " << max[j - 1];

    return 0;
}
