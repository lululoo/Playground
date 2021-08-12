#pragma once

#include "AppShim.h"

class DoCalcsAndStuff
{
public:
	DoCalcsAndStuff(AppShim* app);
	
	void DoSomeCalcs();
	void DoStuff();

private:
	AppShim* pApp;
};