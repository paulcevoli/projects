#include <iostream>

using namespace std;

int multiplesOf3and5() {
    int sum = 0;

    for ( int i = 0; i < 1000; i++ ) {
        if ( ( i % 3 == 0 ) || ( i % 5 == 0 ) ) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << "The sum of the multiples of 3 and 5 up to 1000 is " << multiplesOf3and5() << endl;

    return 0;
}
