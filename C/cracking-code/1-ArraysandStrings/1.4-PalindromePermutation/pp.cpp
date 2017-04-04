#include <iostream>
#include <unordered_map>

using namespace std;

bool isPalindromePermutation( string letters )
{
    unordered_map< char, int > hashtable;
    bool isPP = true;
    bool odd = false;

    // create a hash table of the input characters and frequencies
    for ( string::iterator it = letters.begin(); it != letters.end(); it++ ) {
        char c = tolower( *it );

        if ( !isspace( c ) ) {
            unordered_map< char, int >::iterator seen = hashtable.find( c );
            if ( seen == hashtable.end() ) {
                hashtable.insert( make_pair( c, 1 ) );
            } else {
                seen->second += 1;
            }
        }
    }

    // search the hash table for character frequency, if all the letters
    // have an even frequency with up to 1 odd frequency then the input
    // is a palidrome permutation
    for ( auto itr = hashtable.begin(); itr != hashtable.end(); itr++ ) {
        cout << itr->first << " " << itr->second << endl;

        // check for odd frequency
        if ( ( itr->second % 2 ) == 1 ) {
            // is there another odd frequency? if so we are done
            if ( !odd ) {
                odd = true;
            } else {
                isPP = false;
                break;
            }
        }
    }

    return isPP;
}

int main()
{
    string letters( "Tact Coa" );

    bool pp = isPalindromePermutation( letters );

    cout << pp << " " << letters << endl;
}
