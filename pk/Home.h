//#include "card.h"
#include  <vector>

class Home
{
public:
	Home()
	{
		
	}
	bool add(Card _in_card)
	{
		
		if(_home_deck.size()>0)
		{
			if (_home_deck[_home_deck.size() - 1].sequence(_in_card))
			{
				_home_deck.push_back(_in_card);
				return true;
			}
		}
		else if(_in_card.get_val()=='A')
		{
			_home_deck.push_back(_in_card);
			return true;
		}
		else
		{
			return false;
		}
	}
	bool test_add(Card &_in_card)
	{
		if (_home_deck.size()>0)
		{
			if (_home_deck[_home_deck.size() - 1].sequence(_in_card))
			{
				return true;
			}
		}
		else if (_in_card.get_val() == 'A')
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	unsigned int size()
	{
		return _home_deck.size();
	}
	unsigned int size_outm()
	{
		return _size_out;
	}
	void calc_size_out()
	{
		_size_out = _home_deck.size();
	}
	std::string show()
	{
		--_size_out;
		return _home_deck[_size_out].get_string();
	}
protected:
	unsigned int _size_out=0;
	std::vector<Card> _home_deck;
	char _type;
};
