//	find the sum of a sequence of cubic numbers
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int input;
	int sum = 0;
	
	while( cin >> input )
	{
		sum = sum + input*input*input;
	}
	cout << sum << endl;
	
	return 0;
}
