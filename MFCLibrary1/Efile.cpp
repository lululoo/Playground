#include "efile.h"

#using "SomeBusinessLayer.dll"
using namespace SomeBusinessLayer;

#include <iostream>
using namespace std;

void Efile::Submit()
{
	cout << "Submit!" << endl;
	cout << "zzzSubmit!" << endl;
}

int Efile::GetAcks()
{	
	EfileBiz^ biz = gcnew EfileBiz();
	biz->Submit();
	biz->Submit();
	return biz->GetAcks();
}

