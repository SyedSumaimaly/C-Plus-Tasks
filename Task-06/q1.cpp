#include <iostream>
using namespace std;

int main()
{

    int start = 1, end = 5, i, j;

    for (int i = start; i <= end; ++i)
    {
        cout << "   " << i;
    }
    cout << endl;

    for (int i = start; i <= end; i++)
    {
        for (int j = start; j <= end; j++)
        {

            if (i * j < 10)
            {
                cout << "   " << i * j;
            }
            else
            {
                cout << "  " << i * j;
            }
        }
        cout << endl;
    }

    return 0;
}
