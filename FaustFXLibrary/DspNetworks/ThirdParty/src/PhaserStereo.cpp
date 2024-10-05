/* ------------------------------------------------------------
author: "Dabbu Debendra"
license: "HISE Standard"
name: "StereoPhaser"
version: "1.0"
Code generated with Faust 2.75.7 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _PhaserStereo -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___PhaserStereo_H__
#define  ___PhaserStereo_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _PhaserStereo
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

static float _PhaserStereo_faustpower2_f(float value) {
	return value * value;
}

struct _PhaserStereo final : public ::faust::dsp {
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec1[2];
	float fRec2[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	float fConst4;
	float fConst5;
	float fRec6[3];
	float fConst6;
	float fRec5[3];
	float fRec4[3];
	float fRec3[3];
	float fRec0[2];
	float fRec11[3];
	float fRec10[3];
	float fRec9[3];
	float fRec8[3];
	float fRec7[2];
	
	_PhaserStereo() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Dabbu Debendra");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _PhaserStereo -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("filename", "PhaserStereo.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("license", "HISE Standard");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "StereoPhaser");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("version", "1.0");
	}

	static constexpr int getStaticNumInputs() {
		return 2;
	}
	static constexpr int getStaticNumOutputs() {
		return 2;
	}
	int getNumInputs() {
		return 2;
	}
	int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 6.2831855f / fConst0;
		fConst2 = 16.0f / fConst0;
		fConst3 = 8.0f / fConst0;
		fConst4 = 3.1415927f / fConst0;
		fConst5 = 2.0f / fConst0;
		fConst6 = 4.0f / fConst0;
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(5e+01f);
		fHslider2 = FAUSTFLOAT(0.5f);
		fHslider3 = FAUSTFLOAT(1e+02f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 3; l3 = l3 + 1) {
			fRec6[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 3; l4 = l4 + 1) {
			fRec5[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 3; l5 = l5 + 1) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 3; l6 = l6 + 1) {
			fRec3[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fRec0[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 3; l8 = l8 + 1) {
			fRec11[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec10[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 3; l10 = l10 + 1) {
			fRec9[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 3; l11 = l11 + 1) {
			fRec8[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec7[l12] = 0.0f;
		}
	}
	
	void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	_PhaserStereo* clone() {
		return new _PhaserStereo();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("StereoPhaser");
		ui_interface->declare(&fHslider1, "acc", "1 0 -10 0 10");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->declare(&fHslider1, "unit", "%");
		ui_interface->addHorizontalSlider("Intensity", &fHslider1, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Modes", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider2, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(5.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "unit", "%");
		ui_interface->addHorizontalSlider("Width", &fHslider3, FAUSTFLOAT(1e+02f), FAUSTFLOAT(5e+01f), FAUSTFLOAT(1.5e+02f), FAUSTFLOAT(1.0f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1e+02f, float(fHslider1)));
		float fSlow1 = 0.0075f * fSlow0;
		float fSlow2 = ((int(std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0))))) ? -0.0075f * fSlow0 : fSlow1);
		float fSlow3 = fConst1 * std::max<float>(0.0f, std::min<float>(5.0f, float(fHslider2)));
		float fSlow4 = std::cos(fSlow3);
		float fSlow5 = std::sin(fSlow3);
		float fSlow6 = std::exp(-(fConst4 * std::max<float>(5e+01f, std::min<float>(1.5e+02f, float(fHslider3)))));
		float fSlow7 = _PhaserStereo_faustpower2_f(fSlow6);
		float fSlow8 = 2.0f * fSlow6;
		float fSlow9 = 1.0f - fSlow1;
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			fRec1[0] = fSlow5 * fRec2[1] + fSlow4 * fRec1[1];
			fRec2[0] = float(1 - iVec0[1]) + fSlow4 * fRec2[1] - fSlow5 * fRec1[1];
			float fTemp0 = 1413.7167f * (1.0f - fRec1[0]) + 314.15927f;
			float fTemp1 = fRec4[1] * std::cos(fConst3 * fTemp0);
			float fTemp2 = std::cos(fConst5 * fTemp0) * fRec6[1];
			float fTemp3 = float(input0[i0]);
			fRec6[0] = fTemp3 + 0.8f * fRec0[1] + fSlow8 * fTemp2 - fSlow7 * fRec6[2];
			float fTemp4 = std::cos(fConst6 * fTemp0) * fRec5[1];
			fRec5[0] = fRec6[2] - (fSlow8 * (fTemp2 - fTemp4) + fSlow7 * (fRec5[2] - fRec6[0]));
			fRec4[0] = fRec5[2] + fSlow7 * (fRec5[0] - fRec4[2]) - fSlow8 * (fTemp4 - fTemp1);
			float fTemp5 = fRec3[1] * std::cos(fConst2 * fTemp0);
			fRec3[0] = fRec4[2] + fSlow8 * (fTemp5 - fTemp1) + fSlow7 * (fRec4[0] - fRec3[2]);
			fRec0[0] = fRec3[2] + fSlow7 * fRec3[0] - fSlow8 * fTemp5;
			output0[i0] = FAUSTFLOAT(fSlow9 * fTemp3 + fRec0[0] * fSlow2);
			float fTemp6 = 1413.7167f * (1.0f - fRec2[0]) + 314.15927f;
			float fTemp7 = std::cos(fConst6 * fTemp6) * fRec10[1];
			float fTemp8 = fRec11[1] * std::cos(fConst5 * fTemp6);
			float fTemp9 = float(input1[i0]);
			fRec11[0] = fTemp9 + 0.8f * fRec7[1] + fSlow8 * fTemp8 - fSlow7 * fRec11[2];
			fRec10[0] = fRec11[2] + fSlow7 * (fRec11[0] - fRec10[2]) - fSlow8 * (fTemp8 - fTemp7);
			float fTemp10 = std::cos(fConst3 * fTemp6) * fRec9[1];
			fRec9[0] = fRec10[2] + fSlow8 * (fTemp10 - fTemp7) + fSlow7 * (fRec10[0] - fRec9[2]);
			float fTemp11 = std::cos(fConst2 * fTemp6) * fRec8[1];
			fRec8[0] = fRec9[2] - (fSlow8 * (fTemp10 - fTemp11) + fSlow7 * (fRec8[2] - fRec9[0]));
			fRec7[0] = fSlow7 * fRec8[0] + fRec8[2] - fSlow8 * fTemp11;
			output1[i0] = FAUSTFLOAT(fSlow9 * fTemp9 + fRec7[0] * fSlow2);
			iVec0[1] = iVec0[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "PhaserStereo.dsp"
	#define FAUST_CLASS_NAME "_PhaserStereo"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _PhaserStereo -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 4
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Intensity", fHslider1, 5e+01f, 0.0f, 1e+02f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("Modes", fHslider0, 0.0f, 0.0f, 1.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Speed", fHslider2, 0.5f, 0.0f, 5.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("Width", fHslider3, 1e+02f, 5e+01f, 1.5e+02f, 1.0f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Intensity, "Intensity", fHslider1, 5e+01f, 0.0f, 1e+02f, 0.01f) \
		p(HORIZONTALSLIDER, Modes, "Modes", fHslider0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(HORIZONTALSLIDER, Speed, "Speed", fHslider2, 0.5f, 0.0f, 5.0f, 0.001f) \
		p(HORIZONTALSLIDER, Width, "Width", fHslider3, 1e+02f, 5e+01f, 1.5e+02f, 1.0f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
