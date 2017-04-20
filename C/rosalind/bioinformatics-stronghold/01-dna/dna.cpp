/*

    A Rapid Introduction to Molecular Biologyclick to expand

    Problem

    A string is simply an ordered collection of symbols selected from some alphabet and formed into a word; the length of a string is the number of symbols that it contains.

    An example of a length 21 DNA string (whose alphabet contains the symbols 'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."

    Given: A DNA string s

    of length at most 1000 nt.

    Return: Four integers (separated by spaces) counting the respective number of times that the symbols 'A', 'C', 'G', and 'T' occur in s

    .
    Sample Dataset

    AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC

    Sample Output

    20 12 17 21

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
    auto Acount = 0;
    auto Ccount = 0;
    auto Gcount = 0;
    auto Tcount = 0; 

    for ( string::iterator it = dna.begin(); it != dna.end(); it++ ) {
        switch ( *it ) {
            case 'A':
                Acount++;
                break;
            case 'C':
                Ccount++;
                break;
            case 'G':
                Gcount++;
                break;
            case 'T':
                Tcount++;
                break;
            default:
                cout << "ERROR: Unexepcted alphabet value." << endl;
                exit( 1 );
        }
    }

    cout << Acount << " " << Ccount << " " << Gcount << " " << Tcount << " " << endl;

    return 0;
}   

