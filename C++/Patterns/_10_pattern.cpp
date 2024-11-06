// enter the value of n : 5
// * * * * * * * * * *
// * * * *     * * * * 
// * * *         * * * 
// * *             * * 
// *                 * 
// *                 * 
// * *             * * 
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *

#include <bits/stdc++.h>
using namespace std ;

void pattern(int n)
{
    int star = 2*n ;
    int space = 0 ;
    for(int i = 0 ; i < 2*n  ; i++)
    {
        // star
        for(int j =0 ; j < star/2 ; j++ )
        {
            cout<<"* ";
        }

        // space
        for(int j =0 ; j < space ; j++ )
        {
            cout<<"  ";
        }

        // star
        for(int j = 0 ; j < star/2 ; j++ )
        {
            cout<<"* ";
        }

        if(i < n - 1)
        {
            star -= 2 ;
            space += 2 ;
        }

        else if ( i >= n)
        {
            star += 2 ;
            space -= 2 ;
        }

        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"enter the value of n : ";
    cin>>n;
    pattern(n);
}