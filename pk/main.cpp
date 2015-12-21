#include <iostream>
#include "Deck.h"
#include "Ryad.h"

using namespace std;

ostream & operator<<(ostream &output, Ryad *_rya) 
{
	while(true)
	{
		for (unsigned int i = 0; i != 7; ++i)
		{
			cout << (_rya+ i)->getstr()<<"  ";
		}
	}

}



int main()
{
	//cout << "Hello world\n";
	Deck k;
	Ryad ryads[7];
	for (unsigned int i = 1; i < 8;++i)
	{
		for (unsigned int j = i; j > 0;--j)
		{
			ryads[i-1].add(k.get_up_card());
		}
	}
	cout << endl << k.size() << endl;
	cin.get();

}