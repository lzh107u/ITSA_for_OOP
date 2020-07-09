#include<string>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>

using namespace std;

int main( int argc, char** argv )
{
	int count = 0;
	int input;
	char* line = new char[ 1024 ];
	stack <int> array;
	
	while( cin >> input )
	{
		count++;
		array.push( input );
	}
	
	while( array.empty() != 1 )
	{
		cout << array.top();
		array.pop();
		count--;
		if( count > 0 )
			cout << " ";
	}
	
	cout << endl;
	
	return 0;
}
