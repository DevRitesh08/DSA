#include<iostream>
using namespace std;

void printnum(int n)
{
    for(int i = 1; i <= n; i++)
    {
        // Print numbers from 1 to (n - i + 1)
        for(int num = 1; num <= n - i + 1; num++)
        {
            cout << num << " ";
        }

        // Print (i - 1) stars
        for(int star = 1; star < i; star++)
        {
            cout << "* ";
        }
        for(int star = 1; star < i; star++)
        {
            cout  << "* ";
        }
        for(int num1 = n - i + 1; num1 >= 1; num1--)
        {
            cout << num1 << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printnum(n);
    return 0;
}