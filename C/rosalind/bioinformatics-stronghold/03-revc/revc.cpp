/*

       The Secondary and Tertiary Structures of DNAclick to expand

       Problem

       In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.

       The reverse complement of a DNA string s
       is the string sc formed by reversing the symbols of s

       , then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").

Given: A DNA string s

of length at most 1000 bp.

Return: The reverse complement sc
of s

.
Sample Dataset

AAAACCCGGT

Sample Output

ACCGGGTTTT
*/

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main( int argc, char **argv ) {

    if ( argc != 2 ) {
        cout << argv[ 0 ] << " DNA string" << endl;
    }

    auto dna = string( argv[ 1 ] );
    auto revc = dna;

    string::reverse_iterator rt = dna.rbegin(); 
    string::iterator it = revc.begin(); 
    for ( ; rt != dna.rend(); rt++, it++ ) {
        switch ( *rt ) {
            case 'A':
                *it = 'T';
                break;
            case 'C':
                *it = 'G';
                break;
            case 'G':
                *it = 'C';
                break;
            case 'T':
                *it = 'A';
                break;
            default:
                cout << "ERROR: Unexpected alphabet value." << endl;
                exit( 1 );
        }
    }

    cout << revc << endl;

    return 0;
}   

