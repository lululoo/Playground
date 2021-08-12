#pragma once
#include <memory>

class AppShim
{
public:
	AppShim();
	~AppShim();
	AppShim(const AppShim& other);

	void SomeAppFunc();

private:
	class Impl;

	std::unique_ptr<Impl> pimpl;
};