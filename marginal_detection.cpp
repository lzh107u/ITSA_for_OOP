#include<cstdlib>
#include<iostream>

//https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1703

using namespace std;

class graph
{
private:
	int width;
	int length;
	char** array;
	char** answer;
public:
	graph( int, int );
	~graph();
	void print();
	void generate_answer();
	void set_array( int, char* );
	void print_array();
	void print_answer();
};
graph :: graph( int _length, int _width ): length( _length ), width( _width )
{
	int i;
	array = new char*[ width ];
	answer = new char*[ width ];
	for( i = 0; i < width; i++ )
	{
		array[ i ] = new char[ length ];
		answer[ i ] = new char[ length ];
	}
}
graph :: ~graph()
{
	int i;
	for( i = 0; i < width; i++ )
	{
		delete [] array[ i ];
		delete [] answer[ i ];
	}
	delete [] array;
	delete [] answer;
}
void graph :: set_array( int count, char* line )
{
	int i;
	for( i = 0; i < length; i++ )
	{
		array[ count ][ i ] = line[ i ];
	}
	return ;
}
void graph :: print_array()
{
	int i, j;
	for( i = 0; i < width; i++ )
	{
//		cout << "line" << i << ": " ;
		for( j = 0; j < length; j++ )
		{
			cout << array[ i ][ j ] << " " ;
		}
		cout << endl;
	}
	return ;
}
void graph :: print_answer()
{
	int i, j;
	for( i = 0; i < width - 1; i++ )
	{
//		cout << "line" << i << ": ";
		for( j = 0; j < length - 1; j++ )
		{
			cout << answer[ i ][ j ] << " ";
		}
		cout << answer[ i ][ j ] << endl;
//		cout << endl;
	}
	for( j = 0; j < length - 1; j++ )
		cout << answer[ i ][ j ] << " ";
	cout << answer[ i ][ j ] ; 
	
	return ;
}
void graph :: generate_answer()
{
	int i, j;
	int flag;
	for( i = 0; i < width; i++ )
	{
		for( j = 0; j < length; j++ )
		{
			flag = 0;
			if( i > 0 && array[ i - 1 ][ j ] == '0' && array[ i ][ j ] == '1' )
			{
				flag = 1;
			}
			if( i < width - 1 && array[ i + 1 ][ j ] == '0' && array[ i ][ j ] == '1' )
			{
				flag = 1;
			}
			if( j > 0 && array[ i ][ j - 1 ] == '0' && array[ i ][ j ] == '1' )
			{
				flag = 1;
			}
			if( j < length - 1 && array[ i ][ j + 1 ] == '0' && array[ i ][ j ] == '1' )
			{
				flag = 1;
			}
			if( ( i == 0 || i == width - 1 ) && array[ i ][ j ] == '1' )
				flag = 1;
			if( ( j == 0 || j == length - 1 ) && array[ i ][ j ] == '1' )
				flag = 1;
			
			if( flag == 0 )
				answer[ i ][ j ] = '_';
			else if( flag == 1 )
				answer[ i ][ j ] = '0';
		}
	}
	return ;
}

int main()
{
	int num_graph;
	cin >> num_graph;
	
	int width, length, count, cur_graph, cur_row;
	char* line;
	char ch;
	
	for( cur_graph = 0; cur_graph < num_graph; cur_graph++ )
	{
		cin >> width >> length;
//		length = 2*length + 1;
		line = new char[ length + 1 ];
		graph obj( length, width );
		for( cur_row = 0; cur_row < width; cur_row++ )
		{
//			cin >> line;
			for( count = 0; count < length; count++ )
			{
				cin >> ch;
				line[ count ] = ch;
			}
//			cout << "line: " << line << endl;
			obj.set_array( cur_row, line );
		}
		obj.generate_answer();
		obj.print_answer();
	}
	return 0;
}
