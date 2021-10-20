//programule este facut in limbajul de programare C
#include <stdio.h>

int main()
{
	 unsigned long long int numar_par, prim1 = 0, prim2 = 0, i,k=1, contor = 0;
	printf("Introduceti un numar par: "); //Vom citi un numar par de la tastatura
	scanf("%llu", &numar_par);
	//Vom folosi un for loop pentru a gasi cel mai mare numar prim 
	//apropiat de numarul nostur par	
	for (i = numar_par-1; i > 1; i-=2) 
	{
		//Vom imparti numarul i la toate numerele naturale > 0 
		//pana la acesta inclusiv pentru a verifica daca este prim
		while (k <= i) 
		{
			if (i % k == 0)
				contor++; //Daca numarul se imparte la alt numar contorul ca vreste cu 1
			k++;
		}
		//In cazul in care contorul nostru este = 2, 
		//inseamna ca numarul s-a impartit doar la 1 si la el insusi
		if (contor == 2 ) 
		{
			prim1 = i;
			break; //Daca a m gasit un numar prim atunci vom iesi din acest loop
		}
		k = 1; contor = 0;
	}
	k = 1; contor = 0;
	for (i = 1; i <= numar_par - prim1; i++) 
	//In acest for loop vom cauta un alt numar prim
	//care adunat cu cel precedent va fi egal cu numarul par citit de la tastatura
	{
		while (k <= i)
		{
			if (i % k == 0)
				contor++;
			k++;
		}
		//In cazul in care contorul este 1 atunci numarul prim este 1
		if (contor == 2 || contor == 1) 
			prim2 = i;
		//Daca suma dintre cele doua numere este egala cu numarul par vom iesi din loop
		if (prim1 + prim2 == numar_par) 
			break;
		else {
			k = 1;  contor = 0;
		}
	}
	printf("%llu + %llu = %llu \n", prim1, prim2, prim1+prim2);
	return 0;
}