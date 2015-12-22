#include <iostream>
#include "Deck.h"
#include "Ryad.h"
#include <string>
#include "Home.h"
#include "gtest/gtest.h"

using namespace std;


TEST(Card, sequence) // Проверка метода проверки очередности карт
{
	Card one(3, 'A');
	Card two(3, 'K');
	Card three(0, 'T');
	ASSERT_TRUE(one.sequence(two));
	ASSERT_FALSE(one.sequence(three));
}

TEST(Home, add) // проверка добавление карты 
{
	Home h1;
	Card c1(0, 'T');
	Card c2(0, 'A');
	Card c3(0, 'K');
	ASSERT_FALSE(h1.test_add(c1));
	ASSERT_TRUE(h1.test_add(c2));
	ASSERT_TRUE(h1.add(c2));
	ASSERT_TRUE(h1.test_add(c3));

}


TEST(Ryad, add) // проверка добавление карты 
{
	Card c1(3, 'K');
	Ryad ryad;
	ryad.add(c1);
	ryad.get_size();
	EXPECT_EQ(ryad.get_size(), 1);
}


ostream & operator<<(ostream &output, Ryad (&_rya)[7]) 
{
	for (unsigned int i = 0; i < 7; ++i)
	{
		_rya[i].show();
		_rya[i].calc_size_out();
	}

	for (bool b = true; b;)
	{
		b = false;
		for (unsigned int i = 0; i != 7; ++i)
		{
			if (_rya[i].size_outm() > 0)
			{
				output << _rya[i].getstr() << "  ";
				b = true;
			}
			else
			{
				output << "    ";
			}
		}
		output << endl;
	}
	return output;
}


ostream & operator<<(ostream &output, Home(&home)[4])
{
	for (unsigned int i = 0; i < 4;++i)
	{
		home[i].calc_size_out();
	}
	for (bool b = true; b;)
	{
		b = false;
		for (unsigned int i = 0; i < 4;++i)
		{
			if(home[i].size_outm()>0)
			{
				output << home[i].show()<<"  ";
				b = true;
			}
			else
			{
				output << "     ";
			}
		}
		output << endl;
	}
	return output;
}


int main(int argc, char ** argv)
{
	//cout << "Hello world\n";


	Deck k;
	Home home[4];

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

	cout << ryads << endl;
	cout << k.get_str_up_card()<<endl;
	
	//cin.get();


	for (bool b = true; b;)
	{
		unsigned int menu, men2;
		cout << ryads << endl << endl << endl;

		cout << home<<"\n------------------------------------------------------\n";
		cout << k.get_str_up_card() << "  Size: " << k.size() << endl;
		
		cout << "1. Move card desk to home.\n2. Net card deck.\n3. Exit.\n";
		cin >> menu;
		switch(menu)
		{
		case 1:
			cout << "Enter numvber dec: ";
			while (true)
			{
				cin >> men2;
				if (cin.fail() || men2 < 1 || men2>4)
				{
					cin.sync();
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cerr << "Error: incorrect enter, reenter: ";
				}
				else
				{
					break;
				}
			}
			if(home[men2-1].test_add(k.get_up_card_copy()))
			{
				home[men2-1].add(k.get_up_card());
			}
			break;
		case 2:
			k.next();
			break;
		case 3:
			b = false;
		}
		cout << "-------------------------------------------------------------------" << endl;
	}

	cin.ignore(cin.rdbuf()->in_avail()); //Сброс буфера потока ввода.

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	
	
	cin.get();
	
}
