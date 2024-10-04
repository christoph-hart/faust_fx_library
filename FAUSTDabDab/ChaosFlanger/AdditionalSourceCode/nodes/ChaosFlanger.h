#pragma once

// These will improve the readability of the connection definition

#define getT(Idx) template get<Idx>()
#define connectT(Idx, target) template connect<Idx>(target)
#define getParameterT(Idx) template getParameter<Idx>()
#define setParameterT(Idx, value) template setParameter<Idx>(value)
#define setParameterWT(Idx, value) template setWrapParameter<Idx>(value)
using namespace scriptnode;
using namespace snex;
using namespace snex::Types;

namespace ChaosFlanger_impl
{
// =====================| Node & Parameter type declarations |=====================

template <int NV>
using ChaosFlanger_t_ = container::chain<parameter::empty, 
                                         wrap::fix<2, project::ChaosFlanger<NV>>>;

// ========================| Root node initialiser class |========================

template <int NV> struct instance: public ChaosFlanger_impl::ChaosFlanger_t_<NV>
{
	
	struct metadata
	{
		static const int NumTables = 0;
		static const int NumSliderPacks = 0;
		static const int NumAudioFiles = 0;
		static const int NumFilters = 0;
		static const int NumDisplayBuffers = 0;
		
		SNEX_METADATA_ID(ChaosFlanger);
		SNEX_METADATA_NUM_CHANNELS(2);
		SNEX_METADATA_ENCODED_PARAMETERS(2)
		{
			0x0000, 0x0000
		};
	};
	
	instance()
	{
		// Node References -------------------------------------------------------
		
		auto& faust = this->getT(0); // project::ChaosFlanger<NV>
		
		// Default Values --------------------------------------------------------
		
		faust.setParameterT(0, 0.75); // core::faust::Feedback
		faust.setParameterT(1, 50.);  // core::faust::FlangeLeft
		faust.setParameterT(2, 50.);  // core::faust::FlangeRight
		faust.setParameterT(3, 0.);   // core::faust::Invert
		faust.setParameterT(4, 0.5);  // core::faust::Strength
		faust.setParameterT(5, 3.);   // core::faust::Speed
		
	}
	
	static constexpr bool isPolyphonic() { return NV > 1; };
	
	static constexpr bool hasTail() { return true; };
	
	static constexpr bool isSuspendedOnSilence() { return false; };
};
}

#undef getT
#undef connectT
#undef setParameterT
#undef setParameterWT
#undef getParameterT
// =============================| Public Definition |=============================

namespace project
{
// polyphonic template declaration

template <int NV>
using ChaosFlanger = wrap::node<ChaosFlanger_impl::instance<NV>>;
}


