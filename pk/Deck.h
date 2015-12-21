#include <vector>;
#include "card.h"

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
		result = _cards[_cards.size() - 1];
		_cards.pop_back();
		return result;
	}
	unsigned int size()
	{
		return _cards.size();
	}
protected:
	unsigned int _number_of=52;
	std::vector<Card> _cards;
};
