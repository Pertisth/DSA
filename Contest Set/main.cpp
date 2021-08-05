#include <iostream>

using namespace std;

int main()
{

    int m1,m2,r1;
    cin >> m1 >> m2 >> r1;
    int m1m2,m1r1,m2r1;
    cin >> m1m2 >> m1r1 >> m2r1;
    int m1m2r1;
    cin >> m1m2r1;
    int onlyR1 = r1 - ((m1r1-m1m2r1)+(m2r1-m1m2r1)+(m1m2r1));
    int m1m2butNotR1 = m1m2 - m1m2r1;
    cout << onlyR1 << " "  << m1m2butNotR1;

    return 0;
}

