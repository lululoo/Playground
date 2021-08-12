/*
#include "pch.h"
#include "AppShim.h"
#include "AppActivity.h"

class AppShim::Impl 
{
public:
	Impl() {}
	~Impl() {}

	void SomeImplFunc();

};

AppShim::AppShim()
	: pimpl(new Impl())
{

}

AppShim::~AppShim()
{	
}

AppShim::AppShim(const AppShim& other)
	: pimpl(new Impl(*other.pimpl))
{

}

void AppShim::SomeAppFunc()
{
	AppActivity a;
	a.DoActivity();
}
*/