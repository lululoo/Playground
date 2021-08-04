#pragma once

class MyClass
{
public:
	MyClass();

	int& GetMemberNum();
	int& GetNamespaceNum();

private:
	int number;

};