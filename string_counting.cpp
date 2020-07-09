#include<cstdlib>
#include<iostream>
#include<queue>


using namespace std;

int main()
{
	char* line = NULL;
	char* ch = NULL;
	line = new char[ 100 ];
	int i;
	int* count = new int[ 256 ];
	
	queue < int > letter;
	queue < int > number;
	
	cin.getline( line, 1024 );
	ch = &line[ 0 ];
	for( i = 0; i < 256; i++ )
		count[ i ] = 0;
	
//	cout << "----start-----" << endl;
	while( *ch != '\n' && *ch != '\0' )
	{
//		cout << *ch;
		count[ *ch ]++;
		ch++;
	}
//	cout << "\n-----end-----" << endl;
	
	for( i = 126; i >=32 ; i-- )
	{
		*ch = i;
		if( count[ i ] > 0 )
		{
			letter.push( i );
			number.push( count[ i ] );
		}
	}
	
	int tmp_letter;
	int tmp_number;
	
	while( letter.empty() != 1 )
	{
		tmp_letter = letter.front();
		tmp_number = number.front();
		
		letter.pop();
		number.pop();
		
		cout << tmp_letter << " " << tmp_number << endl;
	//	if( letter.empty() != 1 )
		//cout << endl;
	}
	delete [] line;
	return 0;
}
