#include "class.h"
ParSet::ParSet()
{
	num = 0;
}
ParSet::ParSet(ifstream& fin)
{
	string slov;
	string stroka;
	size_t sz,k;
	num = 0;
	int cntrl;
	while (!fin.eof())
	{
		getline(fin,stroka);
		sz = stroka.size();
		cntrl = 0;
		k = 0;
		for (size_t i = 0; i < sz && cntrl == 0; i++)
		{
			if ((stroka[i] == '#') && (cntrl == 0))
			{
				cntrl = 1;
				k = i;
			}
		}
		if (cntrl == 1)
		{
			stroka.resize(k);
			sz = k;

		}
		cntrl = 0;
		if (stroka.size() != 0)
		{
			for (size_t i = 0; i < sz && cntrl == 0; i++)
			{
				if ((stroka[i] == '=') && (cntrl == 0))
				{
					if (stroka[i - 1] == ' ')
					{
						k = i;
						cntrl = 1;
					}
					else
						cntrl = 2;
				}
			}
			if (cntrl == 1)
			{
				if (stroka[k + 1] == ' ')
				{
					slov.assign(stroka, 0, k - 1);
					int shet = 0;
					for (size_t i = 0; i < k - 1; i++)
					{
						if (slov[i] == ' ')
							shet++;
					}
					if (shet == 0)
					{
						znach.resize(num + 1);
						name.resize(num + 1);
						name[num] = slov;
						slov.clear();
						slov.assign(stroka, k + 2, sz - (k - 1));
						size_t znak1 = 0, znak2 = 0;
						size_t nm1, nm2,szvr = slov.size();
						for (size_t i = 0; i < szvr; i++)
						{
							if (znak1 == 0)
							{
								if (slov[i] == '$')
								{
									nm1 = i;
									znak1++;
								}
							}
							else
							{

								if ((slov[i] == '$') && (znak1 == 1) && (znak2 == 0))
								{
									nm2 = i;
									znak2++;
								}
							}
						}
						if ((znak1 == 1) && (znak2 == 1))
						{
							string vrem;
							znak1 = 0;
							vrem.assign(slov, nm1 + 1, nm2 - nm1 - 1);
							for (size_t i = 0; i < num; i++)
							{
								if ((vrem == name[i]) && (znak1 == 0))
								{
									znak1++;
									znak2 = i;
								}
							}
							if (znak1 != 0)
							{
								if (nm2 == szvr - 1)
								{
									slov.resize(nm1);
									slov += znach[znak2];
								}
								else
								{
									string ost;
									ost.assign(slov, nm2 + 1, szvr - (nm2));
									slov.resize(nm1);
									slov += znach[znak2];
									slov += ost;
									ost.clear();
								}
							}
						}
						znach[num] = slov;
						slov.clear();
						num++;
					}
					else
						slov.clear();
				}
			}
		}
	}
}
ParSet::ParSet(const ParSet& other)
{
	num = other.num;
	name.resize(num);
	znach.resize(num);
	for (size_t i = 0; i < num; i++)
	{
		name[i] = other.name[i];
		znach[i] = other.znach[i];
	}
}
ParSet::~ParSet()
{
	name.~vector();
	znach.~vector();
}
ParSet& ParSet::operator=(const ParSet& other)
{
	if (this != &other)
	{
		name.clear();
		znach.clear();
		num = other.num;
		name.resize(num);
		znach.resize(num);
		for (size_t i = 0; i < num; i++)
		{
			name[i] = other.name[i];
			znach[i] = other.znach[i];
		}
	}
	return *this;
}
ostream& operator<<(ostream& cout, ParSet& x)
{
	cout << endl;
	for (size_t i = 0; i < x.num; i++)
	{
		cout << x.name[i] << " = " << x.znach[i] << endl;
	}
	return cout;
}
int ParSet::operator==(const ParSet& other)
{
	if (num == other.num)
	{
		size_t sh = 0;
		for (size_t i = 0; i < num; i++)
		{
			if ((name[i] == other.name[i]) && (znach[i] == other.znach[i]))
				sh++;
		}
		if (sh == num)
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}
string ParSet::ChangePar(string stroka)
{
	size_t cntrl1 = 0, cntrl2 = 0,nm1,nm2;
	for (size_t i = 0; i < stroka.size(); i++)
	{
		if  (cntrl1 == 0)
		{
			if (stroka[i] == '$')
			{
				nm1 = i;
				cntrl1++;
			}
		}
		else
		{
			if ((cntrl1 == 1) && (cntrl2 == 0) && (stroka[i] == '$'))
			{
				nm2 = i;
				cntrl2++;
			}
		}
	}
	if ((cntrl1 == 1) && (cntrl2 == 1))
	{
		string vrem;
		cntrl1 = 0;
		vrem.assign(stroka, nm1 + 1, nm2 - nm1 - 1);
		for (size_t i = 0; i < num; i++)
		{
			if ((vrem == name[i]) && (cntrl1 == 0))
			{
				cntrl1++;
				cntrl2 = i;
			}
		}
		if (cntrl1 != 0)
		{
			if (nm2 == stroka.size() - 1)
			{
				stroka.resize(nm1);
				stroka += znach[cntrl2];
			}
			else
			{
				string ost;
				ost.assign(stroka, nm2 + 1, stroka.size() - (nm2));
				stroka.resize(nm1);
				stroka += znach[cntrl2];
				stroka += ost;
				ost.clear();
			}
		}
		return stroka;
	}
	else
		return stroka;
}
void ParSet::pushback(string pushz, string pushn)
{
	num += 1;
	name.resize(num);
	znach.resize(num);
	znach[num - 1] = pushz;
	name[num - 1] = pushn;
}
int ParSet::EmptySet()
{
	if (num == 0)
		return 1;
	else
		return 0;
}
string ParSet::ZnachP(string nm)
{	
	int k = 0;
	size_t h;
	for (size_t i = 0; i < num; i++)
	{
		if (nm == name[i])
		{
			h = i;
			k++;
		}
	}
	if (k != 0)
	{
		return znach[h];
	}
	else
	{
		string otvet = "Net parametra s takim nazvaniem!";
		return otvet;
	}
}
void ParSet::AddPar(const ParSet& other)
{
	name.resize(num + other.num);
	znach.resize(num + other.num);
	for (size_t i = 0; i < other.num; i++)
	{
		name[num + i] = other.name[i];
		znach[num + i] = other.znach[i];
	}
	num += other.num;
}