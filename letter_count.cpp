#include<cstdlib>
#include<iostream>

//count the amount of letters

using namespace std;

int main()
{
	int* count = new int[ 26 ];
	char* line = new char[ 1024 ];
	int i = 0;
	
	cin.getline( line, 1024 );
	
	char* ch = &line[ 0 ];
	
	for( i = 0; i < 26; i++ )
		count[ i ] = 0;
	
	i = 0;
	while( line[ i ] != '\n' && line[ i ] != '\0' )
	{
		if( line[ i ] >= 65 && line[ i ] <= 90 )
			count[ line[ i ] - 65 ]++;
		else if( line[ i ] >= 97 && line[ i ] <= 122 )
			count[ line[ i ] - 97 ]++;
		
//		cout << "line[ " << i << " ]: " << line[ i ] << endl;
		i++;
	}
	
	for( i = 0; i < 25; i++ )
		cout << count[ i ] << " " ;
	cout << count[ i ] << endl;
	
	delete [] line;
	delete [] count;
	return 0;
}
