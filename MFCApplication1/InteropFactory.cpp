#include "IFakeBusinessLayerInterop.h"
#include "FakeBusinessLayerInterop.h"
#include "LegacyApplicationInterop.cpp"

class InteropFactory
{
public:
	IFakeBusinessLayerInterop* GetFakeInterop();

};

IFakeBusinessLayerInterop* InteropFactory::GetFakeInterop()
{
	LegacyApplicationInterop legacyApp;
	//FakeBusinessLayerInterop interop(&legacyApp);
}