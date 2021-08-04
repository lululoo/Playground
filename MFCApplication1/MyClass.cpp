#include "pch.h"
#include "MyClass.h"

namespace
{
	int namespaceNum = 7;
}

MyClass::MyClass()
{
	number = 4;
}

int& MyClass::GetMemberNum()
{
	return number;
}

int& MyClass::GetNamespaceNum()
{
	return namespaceNum;
}