#include <iostream>
#include <fstream>

using namespace std;

void Skaityti(char Duom[], int& k)
{
	ifstream fd("Tekstas.txt");
	while (!fd.eof())
	{
		fd.get(Duom[k]);
		k++;
	}

}

void Rasti(char Duom[], char S[], int Skaiciai[], int k, char Sym[])
{
	int sk = 0;
	char s;
	char sim;
	for (int i = 0; i < 10; i++)
	{
		sim = S[i];
		for (int b = 0; b < k; b++)
		{
			s = Duom[b];
			Sym[i] = sim;
			if (s == sim)
			{
				sk++;
				Skaiciai[i] = sk;
			}
		}
		if (sk == 0)
		{
			Skaiciai[i] = 0;
		}
		sk = 0;
	}
}

void Max(char Sym[], int Skaiciai[], char& max, int &maxk)
{
	for (int i = 0; i < 10; i++)
	{

		if (Skaiciai[i] > maxk)
		{
			maxk = Skaiciai[i];
			max = Sym[i];
		}
	}
	cout << max << endl;
	cout << maxk;
}

void Spausdinti(char Sym[], int Skaiciai[], char max, int maxk)
{
	ofstream fr("Rezultatai.txt");
	for (int i = 0; i < 10; i++)
	{
		fr << Sym[i] << " " << Skaiciai[i] << endl;
	}
	fr << "Skaitmuo " << max << " buvo daugiausiai kartu tekste: " << maxk << "kartus(u).";
	fr.close();
}

int main()
{
	int k = 0;
	char S[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char Duom[500];
	int Skaiciai[10];
	char Sym[10];
	char max = '0';
	int maxk = 0;
	Skaityti(Duom, k);
	Rasti(Duom, S, Skaiciai, k, Sym);
	Max(Sym, Skaiciai, max, maxk);
	Spausdinti(Sym, Skaiciai, max, maxk);
	system("pause");
	return 0;
}