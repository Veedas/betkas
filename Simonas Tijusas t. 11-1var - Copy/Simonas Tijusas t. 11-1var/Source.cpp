#include <iostream>
#include <fstream>

using namespace std;

void Skaityti(char A[], int& k)
{
	ifstream fd("Tekstas.txt");
	while (!fd.eof())
	{
		fd.get(A[k]);
		k++;
	}
		
}
void Rasti(char A[], char S[], int C[],int k, char Sym[])
{
	int sk = 0;
	char s;
	char sim;
	for (int i = 0; i < 10; i++)
	{
		sim = S[i];
		for (int b = 0; b < k; b++)
		{
			s = A[b];
			Sym[i] = sim;
			if (s == sim)
			{
				sk++;
				C[i]=sk;
			}
		}
		if (sk == 0)
		{
			C[i] = 0;
		}
		sk = 0;
	}
}
void Max(char Sym[],int C[], char& max, int &maxk)
{
	for (int i = 0; i < 10; i++)
	{
		
		if (C[i] > maxk)
		{
			maxk = C[i];
			max = Sym[i];
		}
	}
	cout << max<<endl;
	cout << maxk;
}
void Spauzdinti(char Sym[],int C[], char max, int maxk)
{
	ofstream fr("Rezultatai.txt");
	for (int i = 0; i < 10; i++)
	{
		fr << Sym[i] << " " << C[i]<< endl;
	}
	fr << "Skaitmuo " << max << " buvo daugiausiai kartu tekste: " << maxk << "kartus(u).";
	fr.close();
}
int main()
{
	int k=0;
	char S[10] = { '0','1','2','3','4','5','6','7','8','9' };
	char A[500];
	int C[10];
	char Sym[10];
	char max='0';
	int maxk=0;
	Skaityti(A, k);
	Rasti(A, S, C, k, Sym);
	Max(Sym, C, max, maxk);
	Spauzdinti(Sym, C, max, maxk);
	system("pause");
	return 0;
}