#include <iostream>
#include <string>

using namespace std;

bool isSubString( string s1, string s2 ) {
    bool subString = false;

    if ( s1.length() < s2.length() ) {
        return subString;
    }

    int len = s1.length() - s2.length();

    for ( int i = 0; i < len ; i ++ ) {
        if ( s1.compare( i, s2.length(), s2 ) != 0 ) {
            subString = true;
        }
    }

    return subString;
}

bool isRotation( string s1, string s2 ) {
    bool rotation = false;

    if ( ( s1.length() == s2.length() ) && ( s1.length() > 0 ) ) {
        string s1s1 = s1 + s1;

        rotation = isSubString( s1s1, s2 );
    }

    return rotation;
}

int main() {
    string s1( "superman" );
    string s2( "man" );
    cout << "is " << s2 << " a substring of " << s1 << " " << isSubString( s1, s2 ) << endl;
    
    string s3( "yin" );
    string s4( "yang" );
    cout << "is " << s4 << " a substring of " << s3 << " " << isSubString( s3, s4 ) << endl;

    string s5( "waterbottle" );
    string s6( "erbottlewat" );
    cout << "is " << s5 << " a rotation of " << s6 << " " << isRotation( s5, s6 ) << endl;

    return 0;
}
