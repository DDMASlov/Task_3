#include "autotest.h"
int autotest()
{
	if (autotest1() && autotest2() && autotest3() == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int autotest1()
{
	string filename = "test1.txt";
	ifstream fin(filename);
	ParSet a(fin);
	ParSet cha;
	string nm1 = "par1";
	string nm2 = "par2";
	string zn1 = "kot1";
	string zn2 = "kkot12";
	fin.close();
	cha.pushback(zn1, nm1);
	cha.pushback(zn2, nm2);
	if (cha == a)
	{
		cout << "Autotest1 passed!" << endl;
		return 1;
	}
	else
	{
		cout << "Autotest1 failed!!" << endl;
		return 0;
	}
}
int autotest2()
{
	string filename = "test1.txt";
	ifstream fin(filename);
	ParSet a(fin);
	string nm1 = "par1";
	string zn1 = "kot1";
	fin.close();
	string chzn = a.ZnachP(nm1);
	if (zn1 == chzn)
	{
		cout << "Autotest2 passed!" << endl;
		return 1;
	}
	else
	{
		cout << "Autotest2 failed!!" << endl;
		return 0;
	}
}
int autotest3()
{
	string filename1 = "test1.txt";
	string filename2 = "test2.txt";
	ifstream fin1(filename1);
	ifstream fin2(filename2);
	ParSet a(fin1);
	ParSet b(fin2);
	ParSet cha, allSet;
	allSet.AddPar(a);
	allSet.AddPar(b);
	string nm1 = "par1";
	string nm2 = "par2";
	string nm3 = "23";
	string nm4 = "nov";
	string zn1 = "kot1";
	string zn2 = "kkot12";
	string zn3 = "chislo";
	string zn4 = "znach";
	fin1.close();
	fin2.close();
	cha.pushback(zn1, nm1);
	cha.pushback(zn2, nm2);
	cha.pushback(zn3, nm3);
	cha.pushback(zn4, nm4);
	if (cha == allSet)
	{
		cout << "Autotest3 passed!" << endl;
		return 1;
	}
	else
	{
		cout << "Autotest3 failed!!" << endl;
		return 0;
	}
}