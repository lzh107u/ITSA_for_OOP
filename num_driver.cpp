#include<iostream>
#include<cstdlib>


using namespace std;

int main()
{
	int diagram[ 24 ];
	int i, j, k;
	for( i = 0; i < 24; i++ )
	{
		diagram[ i ] = 0;
	}
	int num_work, start, end;
	
	cin >> num_work;
	
	for( i = 0; i < num_work; i++ )
	{
		
		cin >> start >> end;
		for( k = start; k < end; k++ )
		{
			diagram[ k ] = diagram[ k ] + 1;	
		}
	}
	
	int num_driver = 0;
	
	for( i = 0; i < 24; i++ )
	{
		if( diagram[ i ] > num_driver )
			num_driver = diagram[ i ];
	}
	
	cout << num_driver << endl;	
	return 0;
} 
