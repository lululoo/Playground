#pragma once
#include "DocView.h"

/// <summary>
/// Displays the news
/// </summary>
class NewsView : public DocView
{
public:
	void Show() override { GetAppName(); }
	void Close() override {}
};