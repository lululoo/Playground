#pragma once

/// <summary>
/// Interface for any class that can show itself in some shape or form
/// </summary>
class IShowable
{
public:
	virtual void Show() = 0;
};