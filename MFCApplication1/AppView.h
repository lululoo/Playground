#pragma once
#include "IShowable.h"

/// <summary>
/// An application's view
/// </summary>
class AppView : public IShowable
{
public:
	void Show() override { };

protected:
	const char* GetAppName() { return "mfc test app"; }
};