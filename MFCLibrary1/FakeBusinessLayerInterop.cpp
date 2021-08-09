#include "pch.h"
#include "FakeBusinessLayerInterop.h"

using namespace SomeBusinessLayer;
using namespace System;

FakeBusinessLayerInterop::FakeBusinessLayerInterop(ILegacyApplication^ app)
{
	mLegacyApp = &app;
}

void FakeBusinessLayerInterop::DoStuffRequiringAuth()
{
	FakeBusinessLayer fakeBiz (*mLegacyApp);
	fakeBiz.DoStuffRequiringAuthAsync();
}
