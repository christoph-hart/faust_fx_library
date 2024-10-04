/** Autogenerated Main.cpp. */

// ==============================| Include only the DSP files  |==============================

#include <AppConfig.h>
#include <hi_dsp_library/hi_dsp_library.h>
#include <hi_faust/hi_faust.h>
#include "includes.h"
// ========================| Now we can add the rest of the codebase |========================

#include <JuceHeader.h>

#if !JUCE_WINDOWS
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif

// ====================================| Project Factory |====================================

namespace project
{

struct Factory: public scriptnode::dll::StaticLibraryHostFactory
{
	Factory()
	{
		TempoSyncer::initTempoData();
		// Node registrations ---------------------------------------------------------------
		
		registerPolyNode<project::DjFlanger<1>, wrap::illegal_poly<project::DjFlanger<1>>>();
		registerPolyNode<project::Flanger<1>, wrap::illegal_poly<project::Flanger<1>>>();
	}
};
}

project::Factory f;

// ================================| Exported DLL functions |================================

DLL_EXPORT int getNumNodes()
{
	return f.getNumNodes();
}

DLL_EXPORT size_t getNodeId(int index, char* t)
{
	return HelperFunctions::writeString(t, f.getId(index).getCharPointer());
}

DLL_EXPORT bool isThirdPartyNode(int index)
{
	return index < 1;
}

DLL_EXPORT int getNumDataObjects(int nodeIndex, int dataTypeAsInt)
{
	return f.getNumDataObjects(nodeIndex, dataTypeAsInt);
}

DLL_EXPORT void deInitOpaqueNode(scriptnode::OpaqueNode* n)
{
	n->callDestructor();
}

DLL_EXPORT void initOpaqueNode(scriptnode::OpaqueNode* n, int index, bool polyIfPossible)
{
	f.initOpaqueNode(n, index, polyIfPossible);
}
DLL_EXPORT int getHash(int index)
{
	static const int thirdPartyOffset = 1;
	static const int hashIndexes[1] =
	{
		-290080190
	};
	return (index >= thirdPartyOffset) ? hashIndexes[index - thirdPartyOffset] : 0;
}
DLL_EXPORT int getWrapperType(int index)
{
	return f.getWrapperType(index);
}
DLL_EXPORT ErrorC getError()
{
	return f.getError();
}
DLL_EXPORT void clearError()
{
	f.clearError();
}
DLL_EXPORT int getDllVersionCounter()
{
	return scriptnode::dll::ProjectDll::DllUpdateCounter;
}

#if !JUCE_WINDOWS
#pragma clang diagnostic pop
#endif


