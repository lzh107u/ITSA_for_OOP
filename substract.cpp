#include<cstdlib>
#include<iostream>
#include<algorithm>


using namespace std;

bool compare1( int a, int b )
{
	return a > b;	
}
bool compare2( int a, int b )
{
	return b > a;
}
int main()
{
	char* line = new char[ 20 ];
	int* list = new int[ 8 ];
	int count_char = 1, count_int = 1;
	int i, j, maximum, minimum;
	
	for( i = 0; i < 8; i++ )
		list[ i ] = -1;
	
	cin >> line ;
	
	list[ 0 ] = line[ 0 ] - 48;
	
	while( line[ count_char ] == ',' )
	{
		count_char++;
		
		list[ count_int ] = line[ count_char ] - 48;
		count_int++;
		count_char++;
	}
	
	sort( list, list+8, compare1 );
	
//	cout << "result1: ";
	for( i = 0; i < 8; i++ )
	{
		if( list[ i ] == -1 )
			break;
//		else
//			cout << list[ i ] ;
	}
//	cout << endl;
	int tmp;
	maximum = 0;
	for( i = 0; i < count_int; i++ )
	{
		tmp = 1;
		for( j = 0; j < count_int - 1 - i; j++ )
		{
			tmp = tmp * 10;
		}
		maximum = maximum + ( list[ i ] * tmp );
	}
//	cout << "maximum: " << maximum << endl;
	sort( list, list+8, compare2 );
	
//	cout << "result2: ";
	for( i = 0; i < 8; i++ )
	{
//		if( list[ i ] != -1 )
//			cout << list[ i ];
	}
//	cout << endl;
	
	minimum = 0;
	int fix = 0;
	for( i = 0; i < 8; i++ )
	{
		while( list[ i ] == -1 )
		{
			i++;
//			fix++;
		}
		tmp = 1;
		for( j = i; j < 7; j++ )
		{
			tmp = tmp * 10;
		}
		minimum = minimum + ( list[ i ] * tmp );
//		cout << "list[ " << i << " ]: " << list[ i ] << ", tmp: " << tmp << endl;
	}
//	cout << "minimum: " << minimum << endl;
	
//	cout << "digits: " << count_int << endl;
	
	cout << maximum - minimum << endl;
	delete [] line;
	return 0;
}
