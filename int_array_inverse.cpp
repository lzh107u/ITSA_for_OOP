#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;

int* reverse( int* input, int* output )
{
	int i = 0;
	
	while( i < 10 )
	{
		output[ 9 - i ] = input[ i ];
		i++;
	}
	
	return output;
}
void display( int* output )
{
	int i = 0;
	
	while( i < 9 )
	{
		cout << output[ i ] << " " ;
		i++;
	}
	cout << output[ i ] << endl;
	return ;
}

int main()
{
	stack < int > output;
	int* array_input = new int[ 10 ];
	int* array_output = new int[ 10 ];
	
	int i = 0, input;
	
	while( i < 10 )
	{
		cin >> input;
		output.push( input );
		array_input[ i ] = input;
		i++;
	}
	
	array_output = reverse( array_input, array_output );
	display( array_output );
	
	while( output.empty() != 1 )
	{
//		cout << output.top() << " ";
		output.pop();
	}
	
	return 0;
}
