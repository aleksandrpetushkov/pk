#include <ctime>

static class Card
{
public:
	Card(char t, char v)
	{
		type = t;
		val = v;
	}
	Card()
	{
		srand(time(NULL));
		t = rand() % 3 + 1;
		v = rand() % 12 + 1;
		generate_card();
	}
	bool sequence(const Card& _two)const
	{
		if(type==_two.get_type())
		{
			for (unsigned int i = 0; i < 12; ++i)
			{
				if(val==vals[i])
				{
					if(vals[i+1]==_two.get_val())
					{
						return true;
					}
					break;
				}
			}
		}
		return false;
	}
	char get_type()const
	{
		return type;
	}
	char get_val()const
	{
		return val;
	}
	bool operator==(const Card& _right) const
	{
		if(type==_right.get_type()&&val==_right.get_val())
		{
			return true;
		}
		return false;
	}
	void generate_card()
	{
		type = gen_t();
		val = gen_v();
	}

	std::string get_string()
	{
		std::string result;
		result += type;
		result += '|';
		result += val;
		return result;
	}
protected:

	static char gen_t()
	{
		if(t>=3)
		{
			t = 0;
			return types[3];
		}
		else
		{
			++t;
			return types[t - 1];
		}
	}

	static char gen_v()
	{
		if (v >= 12)
		{
			v = 0;
			return vals[12];
		}
		else
		{
			++v;
			return vals[v - 1];
		}
	}
	static char t;
	static char v;
	static char types[4];
	static char vals[13];
	char type; //�����
	char val;	
};
char Card::vals[13] = { ' A', 'K', 'Q', 'J', 'T','9','8','7','6','5','4','3','2' };
char Card::types[4] = { 3,4,5,6 };
char Card::t = 0;
char Card::v = 0;