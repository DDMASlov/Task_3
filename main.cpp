#include "class.h"
int main()
{
	if (autotest() != 0)
	{
		return 1;
	}
	setlocale(LC_ALL, "rus");
	int cntrl = 1;
	int f = 0, allcntrl = 0;
	ParSet allSet,a;
	string filenm;
	cout << "0 - quit" << endl;
	cout << "1 - get parameters" << endl;
	cout << "2 - to get content of file with diagnostic" << endl;
	cout << "3 - to get value of parameter from Set of parameters" << endl;
	cout << "4 - to get all parameters and values from file" << endl;
	cout << "5 - to add parameters from file to set of parameters" << endl;
	cout << "6 - to get all parameters and values from set" << endl;
	while (cntrl != 0)
	{
		cin >> cntrl;
		if ((cntrl >= 0) && (cntrl <= 6))
		{
			if (cntrl == 1)
			{
				string filename;
				cout << "Enter filename:";
				cin >> filename;
				ifstream fin(filename);
				if (!fin.is_open())
				{
					cout << "Can't open the file!\n";
				}
				else
				{
					ParSet b(fin);
					a = b;
					f = 1;
					filenm = filename;
				}
				fin.close();
			}
			if (cntrl == 2)
			{
				if (f == 1)
				{
					ifstream fin(filenm);
					if (!fin.is_open())
					{
						cout << "Can't open the file!" << endl;
					}
					else
					{
						string slov;
						string stroka;
						size_t sz, k;
						int cntrl;
						int rub = -1;
						while (!fin.eof())
						{
							getline(fin, stroka);
							cout << a.ChangePar(stroka);
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
							if (cntrl == 0)
								rub = 0;
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
											cout << " // vse horosho" << endl;
										}
										else
										{
											cout << " // est otstyp v imeni" << endl;
											slov.clear();
										}
									}
									else
									{
										cout << " // net otstypa mezdy = i znacheniem" << endl;
									}
								}
								else
								{
									if (cntrl == 0)
									{
										if (rub == 0)
											cout << " // rubbish" << endl;
										else
											cout << " // comments with rubbish" << endl;
									}
									else
										cout << " //parameter has =" << endl;
								}
							}
							else
								cout << " // comments only" << endl;
						}
					}
				}
				else
				{
					cout << "You haven't taken parameters from file" << endl;
				}

			}
			if (cntrl == 3)
			{
				if (allSet.EmptySet())
				{
					cout << "Set of all parameters is empty!!" << endl;
				}
				else
				{
					string parname;
					cout << "Enter parameter:";
					cin >> parname;
					cout << parname << " = " << allSet.ZnachP(parname) << endl;
				}
			}
			if (cntrl == 4)
			{
				if (f == 1)
				{
					cout << a;
				}
				else
				{
					cout << "You haven't get the info from file!" << endl;
				}
			}
			if (cntrl == 5)
			{
				if (f == 1)
				{
					allSet.AddPar(a);
					allcntrl = 1;
				}
			}
			if (cntrl == 6)
			{
				if (allcntrl == 1)
					cout << allSet;
				else
					cout << "Set of all parameters is empty" << endl;
			}
		}
		else
		{
			cout << "Wrong command!!!" << endl;
		}
	}
	return 0;

}