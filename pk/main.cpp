#include <iostream>
#include "Deck.h"
#include "Ryad.h"
#include <string>

using namespace std;

ostream & operator<<(ostream &output, Ryad (&_rya)[7]) 
{

	for (bool b = true; b;)
	{
		b = false;
		for (unsigned int i = 0; i != 7; ++i)
		{
			if (_rya[i].size_out > 0)
			{
				cout << _rya[i].getstr() << "  ";
				b = true;
			}
			cout << endl;
		}
	}
	cin.get();
	return output;

}



int main()
{
	//cout << "Hello world\n";
	Deck k;
	/*
	for (unsigned int i = 0; i < 52; ++i)
	{
		cout << k[i].get_type() << "|" << k[i].get_val() << endl;
	}
	//*/
	Ryad ryads[7];
	for (unsigned int i = 1; i < 8;++i)
	{
		for (unsigned int j = i; j > 0;--j)
		{
			ryads[i-1].add(k.get_up_card());
		}
	}


	ryads[0].show();
	ryads[0].calc_size_out();
	/*
	cout << ryads[0].getstr();
	cout << endl << k.size() << endl << endl;
	//*/
	cout << ryads << endl;
	cin.get();

}