#include <vector>;
#include "card.h"
//#include "Home.h"

class Deck
{
public:
	Deck()
	{
		Card ncard;
		for (unsigned int i=0; i != 52;++i)
		{
			for (auto b=true;b;)
			{
				b = false;
				for(const auto& _card:_cards)
				{
					if(ncard==_card)
					{
						ncard.generate_card();
						b = true;
						break;
					}
				}
			}
			_cards.push_back(ncard);
			ncard.generate_card();
		}
	}
	Card get_up_card()
	{
		Card result;
		result = _cards[0];
		_cards.erase(_cards.begin());
		return result;
	}
	Card get_up_card_copy()
	{
		return _cards[0];
	}
	unsigned int size()
	{
		return _cards.size();
	}
	Card operator[](unsigned int _i)const
	{
		if(!(_i>_cards.size()-1))
		{
			return _cards[_i];
		}
	}
	std::string get_str_up_card()
	{
		if (_cards.size() > 0)
		{
			return _cards[0].get_string();
		}

		return "=====";
	}
	void next()
	{
		_cards.push_back(_cards[0]);
		_cards.erase(_cards.begin());
	}
	

protected:
	unsigned int _number_of=52;
	std::vector<Card> _cards;
};
