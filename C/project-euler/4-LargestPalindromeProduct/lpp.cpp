#include <iostream>
#include <cstdint>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool isPalindrome( int32_t product ) {
    bool palindrome = false;

    // convert int to string
    stringstream ss;
    ss << product;
    string product_str = ss.str();

    if ( product_str.empty() ) {
        return palindrome;
    }

    // compare front and back of string
    palindrome = true;
    int i = 0;
    int j = product_str.length() - 1;

    while ( ( i < j ) && ( palindrome ) ) {
        if ( product_str[ i ] != product_str[ j ] ) {
            palindrome = false;
        }
        i++;
        j--;
    }

    return palindrome;
}

int main() {
    int32_t num1 = 100;
    int32_t num2 = 100;
    int32_t product;
    int32_t largestPalindromeProduct = 0;

    for ( num1 = 100 ; num1 < 1000 ; num1++ ) {
        for ( num2 = 100 ; num2 < 1000; num2++ ) {
            product = num1 * num2;
            //cout << product << endl;
            if ( isPalindrome( product ) ) {
                if ( product > largestPalindromeProduct ) {
                    largestPalindromeProduct = product;
                }
            }
        }
    }

    cout << "The largest palidrome product of 2 three digit integers is " << largestPalindromeProduct << endl;
    
    return 0;
}
