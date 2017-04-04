#include <iostream>
#include <cmath>

using namespace std;

bool isOneAway( string str1, string str2 )
{
    bool oneAway = true;

    // check length of strings <= 1 otherwise the string are implicting more than one away
    //
    if ( abs( str1.length() - str2.length() ) > 1 ) {
        return false;
    }
    string::iterator it1 = str1.begin();
    string::iterator it2 = str2.begin();

    bool done = false;
    int diffs = 0;
    while ( !done ) {
        if ( *it1 == *it2 ) {
            // chars match, move to next chars for each string
            it1++;
            it2++;
        } else {
            // chars done not match,
            //  increase diff count if greater than compare is complete
            //  otherwise determine which pointer to increase and continue
            diffs++;
            if ( diffs > 1 ) {
                oneAway = false;
                done = true;
            } else {
                if ( *( it1 + 1 ) == *it2 ) {
                    it1++;
                } else if ( *it1 == *( it2 + 1 ) ) {
                    *it2++;
                } else {
                    *it1++;
                    *it2++;
                }
            }
        }

        // end when pointers are exhausted, strings are one away!
        if ( ( it1 == str1.end() ) || ( it2 == str2.end() ) ) {
            done = true;
        }
    }

    return oneAway;
}

int main() 
{
    bool oneAway;

    string str1( "pale" );
    string str2( "ple" );
    oneAway = isOneAway( str1, str2 );
    cout << str1 << ", " << str2 << " -> " << oneAway << endl;

    str1 = "pales";
    str2 = "pale";
    oneAway = isOneAway( str1, str2 );
    cout << str1 << ", " << str2 << " -> " << oneAway << endl;

    str1 = "pale";
    str2 = "bale";
    oneAway = isOneAway( str1, str2 );
    cout << str1 << ", " << str2 << " -> " << oneAway << endl;

    str1 = "pale";
    str2 = "bake";
    oneAway = isOneAway( str1, str2 );
    cout << str1 << ", " << str2 << " -> " << oneAway << endl;

    return 0;
}
