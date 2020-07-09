//find maximum prime number in a number

#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

int check_prime( int number )
{
	int square_root = 1;
	if( number == 2 )
	{
		return 0;
	}
	else if( number == 3 )
	{
		return 0;
	}
	
	while( square_root*square_root < number )
	{
		square_root++;
	}
	
	while( square_root > 1 && number%square_root != 0 )
	{
		square_root--;
	}
	
	if( square_root == 1 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int* parse_process( int number, int digits, int* list )
{
	int tmp = number;
	int num_sample = 0;
	int quotient = 1, remain;
	int i, j, count;
	
	while( tmp > 0 )
	{
		tmp = tmp / 10;
		num_sample++;
	}
	num_sample = num_sample - digits + 1;
	count = 0;
	while( list[ count ] != -1 && count < 20 )
	{
		count++;
	}
	for( i = 0; i < num_sample; i++ )
	{
		tmp = 1;
		for( j = 0; j < ( digits + num_sample - i - 1 ); j++ )
		{
			tmp = tmp * 10;
		}
		
		list[ count + i ] = number % tmp;
		
		for( j = 0; j < num_sample - i - 1; j++ )
		{
			list[ count + i ] = list[ count + i ] / 10;
		}
	}
	
	return list;
}
int* parse_number( int number, int* list, int digits )
{
	while( digits > 0 )
	{
		list = parse_process( number, digits, list );
		digits--;
	}
	return list;
}
bool compare( int a, int b )
{
	return a > b;
}
int main()
{
	int* list = new int[ 20 ];
	int number, digits = 1;
	int i;
	
	cin >> number;
	
	//initiate
	for( i = 0; i < 20; i++ )
	{
		list[ i ] = -1;
	}
	
	//digits 
	i = number;
	while( i / 10 > 0 )
	{
		i = i / 10;
		digits++;
	}

	list = parse_number( number, list, digits );

	sort( list, list + 20, compare );
	
	int ret;
	int flag_prime = 0;
	for( i = 0; i < 20; i++ )
	{
		if( list[ i ] == -1 )	//	no data
			break;
		ret = check_prime( list[ i ] );	
		if( ret == 0 )	//	find maximum prime
		{
			flag_prime = 1;
			cout << list[ i ] << endl;
			break;
		}
	}
	
	if( flag_prime == 0 )
		cout << "No prime found" << endl;
	
	delete [] list;
	return 0;
}
