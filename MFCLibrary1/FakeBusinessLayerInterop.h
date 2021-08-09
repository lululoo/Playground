#pragma once
#include "IFakeBusinessLayerInterop.h"

#using "NETStandardLibrary.dll"
using namespace NETStandardLibrary;

class FakeBusinessLayerInterop : public IFakeBusinessLayerInterop
{
public:
	FakeBusinessLayerInterop(ILegacyApplication^ app);

	// Inherited via IFakeBusinessLayerInterop
	virtual void DoStuffRequiringAuth() override;

protected:
	ILegacyApplication^* mLegacyApp;
};

