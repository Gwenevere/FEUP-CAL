/*
 * StringAlgorithms.cpp
 *
 *  Created on: 19 May 2018
 *      Author: Jo�o �lvaro Ferreira
 */

#include "StringAlgorithms.h"



StringAlgorithms::StringAlgorithms(){};

void ExactStringMatchingNaive(string pattern, string text){
	int j;
	int l = pattern.length() - text.length();

	for (int i = 0; i <= l; i++)
	{
	        for (j = 0; j < pattern.length(); j++){
	            if (text[i + j] != pattern[j])
	                break;

	        if (j == pattern.length())
	            cout << "Padrao encontrado em" << i << ".";
	    }
	}

}

void ExactStringMatchingFiniteAutomaton(string pattern, string text){

	//TO DO se acharem necess�rio
}


void auxKMP(string pattern,  int *afixo_mais_longo)
{
	        int len = 0;
	        int i = 1;
	        afixo_mais_longo[0] = 0;

	        while (i < pattern.length())
	        {
	            if (pattern.at(i) == pattern.at(len))
	            {
	                len++;
	                afixo_mais_longo[i] = len;
	                i++;
	            }
	            else{
	                if (len != 0)
	                  len = afixo_mais_longo[len-1];

	                else
	                {
	                    afixo_mais_longo[i] = len;
	                    i++;
	                }
	            }
	        }
}



void ExactStringMatchingKMP(string pattern, string text){

	        int afixo_mais_longo[pattern.length()];
	        auxKMP(pattern,afixo_mais_longo);

	        int i = 0;
	        int j = 0;

	        while (i < text.length())
	        {
	            if (pattern.at(j) == text.at(i))
	            {
	                j++;
	                i++;
	            }
	            if (j == pattern.length())
	            {
	                cout << "Padrao encontrado em" << (i-j);
	                j = afixo_mais_longo[j-1];
	            }


	            else if (i < text.length() && pattern.at(j) != text.at(i))
	            {
	                if (j != 0)
	                    j = afixo_mais_longo[j-1];
	                else
	                    i = i+1;
	            }
	        }
}



int ApproximateStringMatchingEditDistance(string string1, string string2){

	vector<vector<int>> matrizDinamica;
	int velho, novo;

	for(int j = 0; j < string2.length(); j++)
	{
		matrizDinamica[0][j] = j;
	}

	for(int i = 1; i < string1.length(); i++)
	{
		velho = matrizDinamica[i-1][0];
		matrizDinamica[i][0] = i;

		for(int j = 1; j < string2.length(); j++)
		{
			if(string1.at(i) == string2.at(j))
				velho = novo;
			else
				novo = 1 + min(min(velho,matrizDinamica[i][j-1]), matrizDinamica[i-1][j]);

			velho = matrizDinamica[i-1][j];
		}
	}

	return matrizDinamica[string1.length()][string2.length()];
}

