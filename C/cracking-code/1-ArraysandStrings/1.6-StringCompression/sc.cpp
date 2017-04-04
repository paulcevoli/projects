#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string compressString( string uncompressed )
{
    stringstream ss;
    string compressed;
    char curr = uncompressed[ 0 ];
    int count = 1;

    for ( string::iterator it = uncompressed.begin(); it <= uncompressed.end(); it++ ) {
        if ( curr != *it ) {
            ss << curr << count;
            curr = *it;
            count = 1;
        } else {
            count++;
        }
    }

    compressed = ss.str();
    if ( compressed.length() >= uncompressed.length() ) {
        return uncompressed;
    } else {
        return compressed;
    }
}

int main()
{
    string str1( "aabcccccaaa" );
    cout << compressString( str1 ) << endl;

    string str2( "abcd" );
    cout << compressString( str2 ) << endl;

    string str3( "abccccccccaaaizdf" );
    cout << compressString( str3 ) << endl;

    string str4( "abcdefggghhhiiiii" );
    cout << compressString( str4 ) << endl;

    string str5( "iiiiib" );
    cout << compressString( str5 ) << endl;

    return 0;
}
