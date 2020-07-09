#include<cstdlib>
#include<iostream>

//check the correctness of sudoku

using namespace std;

class matrix
{
private:
	int** array;
	int correctness;
	int range;
public:
	matrix();
	~matrix();
	
	void check_row();
	void check_column();
	void check_block();
	void check_correctness();
	char* initiate_check( char* );
		
	void set_array( int, int* );
	void print_array();
	void current_check( char* );
};
void matrix :: current_check( char* list )
{
	cout << list << endl;
	return ;
}
matrix :: matrix()
{
	int i;
	correctness = 1;
	range = 10;
	array = new int*[ 9 ];
	for( i = 0; i < 9; i++ )
		array[ i ] = new int[ 9 ];
	
}
matrix :: ~matrix()
{
	int i;
	for( i = 0; i < 9; i++ )
		delete [] array[ i ];
	
	delete [] array;
}
void matrix :: set_array( int row, int* _array )
{
	int i, j;
	for( i = 0; i < range; i++ )
		array[ row ][ i ] = _array[ i ];
	return ;
}
char* matrix :: initiate_check( char* list )
{
	int i;
	for( i = 0; i < range; i++ )
		list[ i ] = '0';
	return list;
}
void matrix :: check_row()
{
	int i, j;
	char* check = new char[ 10 ];
	for( i = 0; i < 9; i++ )
	{
		check = matrix :: initiate_check( check );
//		current_check( check );
		for( j = 0; j < 9; j++ )
		{
			if( check[ array[ i ][ j ] ] == '0' )
				check[ array[ i ][ j ] ] = '1';
			else if( check[ array[ i ][ j ] ] == '1' && array[ i ][ j ] != 0 )
			{
				correctness = 0;
				cout << "row" << i + 1 << " #" << array[ i ][ j ] << endl;
				j = 9;
			}
//			current_check( check );
		}
	}
	delete [] check;
	return ;
}
void matrix :: check_column()
{
	int i, j;
	char* check = new char[ 10 ];
	
	for( i = 0; i < 9; i++ )
	{
		check = matrix :: initiate_check( check );
//		current_check( check );
		for( j = 0; j < 9; j++ )
		{
			if( check[ array[ j ][ i ] ] == '0' )
				check[ array[ j ][ i ] ] = '1';
			else if( check[ array[ j ][ i ] ] == '1' && array[ j ][ i ] != 0 )
			{
				correctness = 0;
				cout << "column" << i + 1 << " #" << array[ j ][ i ] << endl;
				j = 9;
			}
//			current_check( check );
		}
	}
	delete [] check;
	return ;
}
void matrix :: check_block()
{
	int i, j, k, l;
	char* check = new char[ 10 ];
	
	for( i = 0; i < 3; i++ )
	{
		for( j = 0; j < 3; j++ )
		{
			check = matrix :: initiate_check( check );
//			current_check( check );
			for( k = 0; k < 3; k++ )
			{
				for( l = 0; l < 3; l++ )
				{
					if( check[ array[ i*3 + k ][ j*3 + l ] ] == '0' )
						check[ array[ i*3 + k ][ j*3 + l ] ] = '1';
					else if( check[ array[ i*3 + k ][ j*3 + l ] ] == '1' && array[ i*3 + k ][ j*3 + l ] != 0 )
					{
						cout << "block" << i*3 + j + 1 << " #" << array[ i*3 + k ][ j*3 + l ] << endl;
						correctness = 0;
						k = 3;
						l = 3;
					}
//					current_check( check );
				}
			}
		}
	}
	delete [] check;
	return ;
}
void matrix :: check_correctness()
{
	if( correctness == 1 )
	{
		cout << "true" << endl;
	}
	return ;
}
void matrix :: print_array()
{
	int i, j;
	for( i = 0; i < 9; i++ )
	{
		for( j = 0; j < 9; j++ )
		{
			cout << array[ i ][ j ];
		}
		cout << endl;
	}
	return ;
}
int main()
{
	matrix* ptr = new matrix;
	char* line = new char[ 12 ];
	int* _input = new int[ 9 ];
	
	int i, j;
	for( i = 0; i < 9; i++ )
	{
		cin >> line;
		for( j = 0; j < 9; j++ )
		{
			_input[ j ] = line[ j ] - 48;
		}
		ptr->set_array( i, _input );
	}
	
	ptr->check_row();
	ptr->check_column();
	ptr->check_block();
	
	
	ptr->check_correctness();
	
	delete ptr;
	delete line;
	delete _input;
	
	return 0;
}
