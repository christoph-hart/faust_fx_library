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

scriptnode::dll::FactoryBase* scriptnode::DspNetwork::createStaticFactory()
{
	return new project::Factory();
}

#if !JUCE_WINDOWS
#pragma clang diagnostic pop
#endif


