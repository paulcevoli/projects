#include <stdio.h>


int makeChange( int n, int denom )
{
    int next_denom = 0;

    switch ( denom )
    {
        case 100:
            next_denom = 50;
            break;

        case 50:
            next_denom = 25;
            break;

        case 25:
            next_denom = 10;
            break;

        case 10:
            next_denom = 5;
            break;

        case 5:
            next_denom = 1;
            break;

        case 1:
            return 1;
    }


    int ways = 0;
    int i;

    for ( i = 0; i * denom <= n; i++ )
    {
        if ( ( i * denom ) == n )
        {
            printf( " n = %d, i = %d, denom = %d, next denom = %d\n", n, i, denom, next_denom );
        }
        ways += makeChange( n - i * denom, next_denom ); 
    }

    return ways;
}

int main()
{
    printf( "ways(100) = %d\n", makeChange( 100,  100 ) );
}
