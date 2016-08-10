// AsymTitling.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

unsigned int CountAllCases(unsigned int);
unsigned int Symtiling(unsigned int);

const int MaxLength = 100;
unsigned int cache[MaxLength];

int _tmain(int argc, _TCHAR* argv[])
{
	//Initailize cache for Memoization
	for(int i=0;i<MaxLength;i++)
			cache[i] = -1;

	unsigned int length;
	unsigned int allPossibleCases;
	while(1)
	{
		length = 0;
		allPossibleCases = 0;

		cout<<"Input Length (0~100):";
		cin>>length;

		allPossibleCases = CountAllCases(length) - Symtiling(length);
		cout<<"All possible case of asymtiling:" <<allPossibleCases %1000000007 <<endl;
	}

	return 0;
}



unsigned int CountAllCases(unsigned int length)
{
	if(length== 0)
		return 0;

	if(length == 1)
		return 1;

	if(length == 2)
		return 2;

	if(cache[length] == -1)
	 cache[length] = (CountAllCases(length-1) + CountAllCases(length-2))  ;
		
	return cache[length];
}

unsigned int Symtiling(unsigned int length)
{
	if(length ==0)
		return 0;
	if(length == 1)
		return 1;
	if(length ==2)
		return 2;

	if(length %4 == 0)
		return CountAllCases((length/2)) + CountAllCases((length-2)/2);   // no center, 2 in the center
	else if(length%2 ==0)
		return 2*CountAllCases((length-2)/2); //2 or 1,1 in the center
	else
		return CountAllCases((length-1)/2); //1 in the center
}