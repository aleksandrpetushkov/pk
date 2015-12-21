#include <vector>
//#include "card.h"


class Ryad
{
public:
	Ryad()
	{
		
	}
	unsigned size_out = 0;
	void calc_size_out()
	{
		size_out = visible.size() + invisible.size();
	}
	void add(Card _in_card)
	{
		invisible.push_back(_in_card);
	}
	void show()
	{
		if(visible.size()==0&&invisible.size()!=0)
		{
			
		}
	}
	char * getstr()
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
				return  visible[size_out - 1].get_string();
			}
		}
		
	}

protected:
	std::vector<Card> visible;
	std::vector<Card> invisible;
	unsigned int vis=0;
	unsigned int invis=0;

};
