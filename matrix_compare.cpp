#include<cstdlib>
#include<iostream>
#include<algorithm>

//find the maximum sum of a small sub-matrix in a big matrix

using namespace std;

int main()
{
	int** matrix = NULL;
	int num_matrix, width, length, sub_matrix, maximum, tmp;
	
	int i, j, k, l, m;
	
	cin >> num_matrix;
	
	for( i = 0; i < num_matrix; i++ )
	{
		cin >> width >> length >> sub_matrix;
		matrix = new int*[ width ];
		for( j = 0; j < width; j++ )
		{
			matrix[ j ] = new int[ length ];
			for( k = 0; k < length; k++ )
			{
				cin >> matrix[ j ][ k ];
			}
		}
		
		for( j = 0; j < width; j++ )
		{
//			for( k = 0; k < length; k++ )
//				cout << matrix[ j ][ k ] << " ";
//			cout << endl;
		}
		maximum = 0;
		for( j = 0; j < sub_matrix; j++ )
		{
			for( k = 0; k < sub_matrix; k++ )
				maximum = maximum + matrix[ j ][ k ];
		}
		for( j = 0; j < width - sub_matrix + 1; j++ )
		{
			for( k = 0; k < length - sub_matrix + 1; k++ )
			{
				tmp = 0;
				for( l = 0; l < sub_matrix; l++ )
				{
					for( m = 0; m < sub_matrix; m++ )
					{
						tmp = tmp + matrix[ j + l ][ k + m ];
					}
				}
				if( tmp > maximum )
					maximum = tmp;
			}
		}
		
//		cout << "maximum: " << maximum << endl;
		cout << maximum << endl;
		for( j = 0; j < width; j++ )
			delete [] matrix[ j ];
		delete [] matrix;
	}
	
	return 0;
}
