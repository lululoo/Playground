#pragma once

/// <summary>
/// Interface for any class that can be closed
/// </summary>
class ICloseable
{
public:
	virtual void Close() = 0;
};