
#include "PmergeMe.hpp"

void mergeVector(std::vector<int>	&tab, int indL, int indM, int indR)
{
	int i, j, k;
	int nl = indM - indL + 1;
	int nr = indR - indM;

	std::vector<int> L(nl);
    std::vector<int> R(nr);
	for (i = 0; i < nl; i++)
		L[i] = tab[indL + i];
	for (j = 0; j < nr; j++)
		R[j] = tab[indM + 1 + j];
	i = 0;
	j = 0;
	k = indL;
	while (i < nl && j < nr)
	{
		if (L[i] <= R[j])
		{
			tab[k] = L[i];
			i++;
		}
		else
		{
			tab[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < nl)
	{
		tab[k] = L[i];
		i++;
		k++;
	}
	while (j < nr)
	{
		tab[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortVector(std::vector<int> &tab, int indL, int indR)
{
	if (indL < indR)
	{
		int indM = (indR + indL) / 2;
        // ici on subdivise les vector 
		mergeSortVector(tab, indL, indM);
		mergeSortVector(tab, indM + 1, indR);
        // a partir de la on a que des petit vector trié
        // et la on les fusine un part un
		mergeVector(tab, indL, indM, indR);
	}
}

void mergeList(std::list<int> &tab, std::list<int> &left, std::list<int> &right)
{
	std::list<int>::iterator it1 = left.begin();
	std::list<int>::iterator it2 = right.begin();

	while (it1 != left.end() && it2 != right.end())
	{
		if (*it1 < *it2)
		{
			tab.push_back(*it1);
			it1++;
		}
		else
		{
			tab.push_back(*it2);
			it2++;
		}
	}
	while (it1 != left.end())
	{
		tab.push_back(*it1);
		it1++;
	}
	while (it2 != right.end())
	{
		tab.push_back(*it2);
		it2++;
	}
}

void mergeSortList(std::list<int> &tab)
{
	if (tab.size() > 1)
	{
	    std::list<int> left;
        std::list<int> right;
        std::list<int>::iterator it = tab.begin();
	    int count = 0;
	    while (it != tab.end())
        {
	    	if (count < tab.size() / 2)
	    		left.push_back(*it);
	    	else
	    		right.push_back(*it);
	    	count++;
	    	it++;
	    }
	    mergeSortList(left);
    	mergeSortList(right);
    	tab.clear();
	    mergeList(tab, left, right);
	}
}