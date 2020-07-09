#include<cstdlib>
#include<iostream>
#include<iomanip>

using namespace std;

int** create( int** matrix, int size )
{
	int l1, l2;
	matrix = new int*[ size ];
	
	for( l1 = 0; l1 < size; l1++ )
	{
		matrix[ l1 ] = new int[ size ];
		for( l2 = 0; l2 < size; l2++ )
		{
			matrix[ l1 ][ l2 ] = l1*size + l2 + 1;
		}
	}
	
	return matrix;
}
int** remove( int** matrix, int size )
{
	int l1;
	
	for( l1 = 0; l1 < size; l1++ )
		delete [] matrix[ l1 ];
	
	delete [] matrix;
	return matrix;
}
void show( int** matrix, int size )
{
	int l1, l2;
	for( l1 = 0; l1 < size; l1++ )
	{
		for( l2 = 0; l2 < size; l2++ )
			cout << setw( 5 ) << matrix[ l1 ][ l2 ] ;
		
		cout << endl;
	}
	return ;
}
int** func_R( int** matrix, int size )
{
	int l1, l2;
	int** answer = create( answer, size );
	
	for( l1 = 0; l1 < size; l1++ )
	{
		for( l2 = 0; l2 < size; l2++ )
		{
			answer[ l1 ][ l2 ] = matrix[ size - l2 - 1 ][ l1 ];
		}
	}
	return answer;
}
int** func_L( int** matrix, int size )
{
	int l1, l2;
	int** answer = create( answer, size );
	for( l1 = 0; l1 < size; l1++ )
	{
		for( l2 = 0; l2 < size; l2++ )
		{
			answer[ l1 ][ l2 ] = matrix[ l2 ][ size - l1 - 1 ];
		}
	}
	return answer;
}
int** func_N( int** matrix, int size )
{
	int l1, l2;
	int** answer = create( answer, size );
	for( l1 = 0; l1 < size; l1++ )
	{
		for( l2 = 0; l2 < size; l2++ )
		{
			answer[ l1 ][ l2 ] = matrix[ size - l1 - 1 ][ l2 ];
		}
	}
	return answer;
}
void transpose( int** matrix, int size, char* line )
{
	char* ch = &line[ 0 ];
	while( *ch != '\n' && *ch != '\0' )
	{
		if( *ch == 'R' )
		{
			matrix = func_R( matrix, size );
//			show( matrix, size );
		}
		else if( *ch == 'L' )
		{
			matrix = func_L( matrix, size );
//			show( matrix, size );
		}
		else if( *ch == 'N' )
		{
			matrix = func_N( matrix, size );
//			show( matrix, size );
		}
		else
		{
//			cout << "something wrong, ch: " << *ch << endl;
		}
		
		ch++;
	}
	show( matrix, size );
	return ;
}

int main()
{
	char* line = NULL;
	int** matrix = NULL;
	int l1, l2, l3;
	int size, num_matrix;
	cin >> num_matrix;
	
	for( l1 = 0; l1 < num_matrix; l1++ )
	{
		cin >> size;
		matrix = create( matrix, size );
//		show( matrix, size );
		line = new char[ 90 ];
		cin >> line ;
		
		transpose( matrix, size, line );
		
		matrix = remove( matrix, size );
		delete [] line;
	}
	
	return 0;
}
