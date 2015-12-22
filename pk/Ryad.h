#include <vector>
//#include "card.h"


class Ryad
{
public:
	Ryad()
	{
		
	}
	void calc_size_out()
	{
		size_out = visible.size() + invisible.size();
	}
	void add(Card _in_card)
	{
		invisible.push_back(_in_card);
	}
	void show()//ѕереворачивает карту если всерхн€€ карта лежит рубашкой ввех
	{
		if(visible.size()==0&&invisible.size()!=0)
		{
			visible.push_back(invisible[invisible.size()-1]);
			invisible.pop_back();
		}
	}

	std::string  getstr()
	{
		if(size_out>0)
		{
			if (size_out-visible.size()>0) 
			{
				--size_out;
				return "--";
			}
			else
			{
				std::string tmp = visible[size_out - 1].get_string();
				--size_out;
				return  tmp;
			}
		}
	}
	unsigned int size_outm()
	{
		return size_out;
	}
	unsigned int get_size()
	{
		return visible.size() + invisible.size();
	}
protected:
	unsigned int size_out = 0;

	std::vector<Card> visible;
	std::vector<Card> invisible;
	unsigned int vis=0;
	unsigned int invis=0;

};
