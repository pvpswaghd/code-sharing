#include <iostream>
using namespace std;
int main()
{
    char ch=0;
    cout << "Press Q to quit\n";
    do
    {
        ch = getch();

        switch(ch)
        {
            case 'W':
            case 'w':
                cout << "W was pressed \n";
                break;
            case 'A':
            case 'a':
                cout << "A was pressed \n";
                break;
            case 's':
            case 'S':
                cout << "S was pressed \n";
                break;
            case 'D':
            case 'd':
                cout << "D was pressed \n";
                break;

        }

    }while (ch != 'Q' && ch!='q');
}
