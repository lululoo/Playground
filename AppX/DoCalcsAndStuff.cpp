#include "pch.h"

#include "DoCalcsAndStuff.h"

DoCalcsAndStuff::DoCalcsAndStuff(AppShim* app)
	: pApp(app)
{

}

void DoCalcsAndStuff::DoSomeCalcs()
{
	// unresolved external symbol
	//pApp->SomeAppFunc();
}
	
void DoCalcsAndStuff::DoStuff()
{
}