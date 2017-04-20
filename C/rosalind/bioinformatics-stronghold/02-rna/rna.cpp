/*

       The Second Nucleic Acidclick to expand

       Problem

       An RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.

       Given a DNA string t
       corresponding to a coding strand, its transcribed RNA string u is formed by replacing all occurrences of 'T' in t with 'U' in u

       .

Given: A DNA string t

having length at most 1000 nt.

Return: The transcribed RNA string of t

.
Sample Dataset

GATGGAACTTGACTACGTAAATT

Sample Output

GAUGGAACUUGACUACGUAAAUU

*/

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main( int argc, char **argv ) {

    if ( argc != 2 ) {
        cout << argv[0] << " DNA string" << endl;
    }

    auto dna = string( argv[ 1 ] );
    auto rna = dna;

    for ( string::iterator it = rna.begin(); it != rna.end(); it++ ) {
        switch ( *it ) {
            case 'A':
            case 'C':
            case 'G':
                break;
            case 'T':
                *it = 'U';
                break;
            default:
                cout << "ERROR: Unexepcted alphabet value." << endl;
                exit( 1 );
        }
    }

    cout << rna << endl;

    return 0;
}   

