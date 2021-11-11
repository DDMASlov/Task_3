#include "main.h"
class ParSet
{
private:
	vector <string> name;
	vector <string> znach;
	size_t num;
public:
	ParSet();
	ParSet(ifstream& fin);
	ParSet(const ParSet& other);
	~ParSet();
	ParSet& operator=(const ParSet& other);
	int operator==(const ParSet& other);
	friend ostream& operator<<(ostream& cout, ParSet& x);
	int EmptySet();
	void pushback(string pushz, string pushn);
	string ChangePar(string stroka);
	string ZnachP(string nm);
	void AddPar(const ParSet& other);
};