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
protected:
	std::vector<Card> _home_deck;
	char _type;
};
