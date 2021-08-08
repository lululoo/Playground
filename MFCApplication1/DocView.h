#pragma once
#include "AppView.h"
#include "ICloseable.h"

/// <summary>
/// The base class for the views of all documents in this app
/// </summary>
class DocView : public AppView, public ICloseable
{
public:
	void Show() override { GetAppName(); };
};