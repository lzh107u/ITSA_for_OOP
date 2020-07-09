#include<cstdlib>
#include<iostream>
#include<map>
using namespace std;
void check( map < int, int >&list, int number )
{
	if( list.count( number ) == 0 )
		list.insert( { number, 1 } );
	else
		list[ number ]++;
	
	return ;
}
void _find( const map < int, int >&list, const int num )
{
	int max_num, max_amt = 0;
	
	map< int, int > :: iterator it;
	
	for( auto i:list )
	{
//		cout << i.first << " " << i.second << endl;
		if( i.second > max_amt )
		{
			max_amt = i.second;
			max_num = i.first;
		}
	}
	
	if( ( num%2 != 0 && max_amt >= ( num + 1 )/2 ) || ( num%2 == 0 && max_amt >= num/2 ) )
	{
		cout << max_num << endl;
//		cout << "max_num: " << max_num <<", max_amt: " << max_amt << endl;
	}
	else
		cout << "NO" << endl;
	
	return ;
}
int main()
{
	map < int, int > list;
	char* line = new char[ 1024 ];
	int digit;
	
	int tmp, number, i, j, k, num = 0;
	
	while( cin.getline( line, 1024 ) )
	{
		i = 0;
		digit = 0;
		num = 0;
		while( line[ i ] != '\0' && line[ i ] != '\n' )
		{
//			cout << "line[ " << i << " ]: " << line[ i ] << endl;
			if( ( line[ i ] >= 48 && line[ i ] <= 57 ) || line[ i ] == '-' )
			{
				digit++;
			}
			else
			{
				//process
				number = 0;
				for( j = 0; j < digit; j++ )
				{
					if( line[ i - j - 1 ] == '-' )
					{
						number = -number;
					}
					else
					{
						tmp = line[ i - j - 1 ] - 48;
//						cout << "line[ " << i - j - 1 << " ]: " << line[ i - j - 1 ] << ", tmp( before ): " << tmp << endl;
						for( k = 0; k < j; k++ )
						{
							tmp = tmp * 10;
						}
//						cout << "tmp( after ): " << tmp << endl;
						number = tmp + number;
					}
				}
//				cout << "number: " << number << endl;
				check( list, number );
				num++;
				digit = 0;
			}
			i++;
		}
		number = 0;
		for( j = 0; j < digit; j++ )
		{
			tmp = line[ i - j - 1 ] - 48;
			for( k = 0; k < j; k++ )
			{
				tmp = tmp * 10;
			}

				number = tmp + number;
		}
//		cout << "number: " << number << endl;
		check( list, number );
		num++;
		
		_find( list, num );
		
		list.clear();
		
	}
	
	delete [] line;

	return 0;
}
