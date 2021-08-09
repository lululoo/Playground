#pragma once
#using "NETStandardLibrary.dll"

using namespace NETStandardLibrary;
using namespace System;

/// C++/CLI implementation of ILegacyApplication 
/// responsible for marshalling between ProSeries MFC Application & .NET projects
public ref class LegacyApplicationInterop : public ILegacyApplication
{
public:

	// Inherited via ILegacyApplication
	virtual property String^ CommonDirectory
	{
		String^ get() 
		{ 
			return gcnew String("hello world!");
		}
	}

	virtual String^ GetAuthToken()
	{
		return gcnew String("token");
		//throw gcnew NotImplementedException();
		// TODO: insert return statement here
	}
};

struct MyLegacyApp
{
	LegacyApplicationInterop^& legacyApp;
};