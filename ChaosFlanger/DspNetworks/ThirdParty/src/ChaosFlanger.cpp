/* ------------------------------------------------------------
author: "Dabbu Debendra"
copyright: "(c) Dabdab"
name: "DJFlanger"
version: "1.00"
Code generated with Faust 2.74.6 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _ChaosFlanger -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___ChaosFlanger_H__
#define  ___ChaosFlanger_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _ChaosFlanger
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


class _ChaosFlanger final : public ::faust::dsp {
	
 public:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fVec1[2048];
	FAUSTFLOAT fHslider3;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec1[2];
	float fRec2[2];
	FAUSTFLOAT fHslider4;
	float fRec0[2];
	float fVec2[2048];
	FAUSTFLOAT fHslider5;
	float fRec3[2];
	
 public:
	_ChaosFlanger() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Dabbu Debendra");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _ChaosFlanger -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("copyright", "(c) Dabdab");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("filename", "ChaosFlanger.dsp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "DJFlanger");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("version", "1.00");
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
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.75f);
		fHslider3 = FAUSTFLOAT(3.0f);
		fHslider4 = FAUSTFLOAT(5e+01f);
		fHslider5 = FAUSTFLOAT(5e+01f);
	}
	
	void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		IOTA0 = 0;
		for (int l1 = 0; l1 < 2048; l1 = l1 + 1) {
			fVec1[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec0[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2048; l5 = l5 + 1) {
			fVec2[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec3[l6] = 0.0f;
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
	
	_ChaosFlanger* clone() {
		return new _ChaosFlanger();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("DJFlanger");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "unit", "db");
		ui_interface->addHorizontalSlider("Feedback", &fHslider2, FAUSTFLOAT(0.75f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("FlangeLeft", &fHslider4, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.5e+02f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("FlangeRight", &fHslider5, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(3.5e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Invert", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->declare(&fHslider1, "unit", "%");
		ui_interface->addHorizontalSlider("Strength", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->declare(&fHslider3, "acc", "0 1 -10 0 15");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("Speed", &fHslider3, FAUSTFLOAT(3.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1e+01f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider1)));
		float fSlow1 = ((int(std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0))))) ? -fSlow0 : fSlow0);
		float fSlow2 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider2)));
		float fSlow3 = fConst1 * std::max<float>(0.0f, std::min<float>(1e+01f, float(fHslider3)));
		float fSlow4 = std::cos(fSlow3);
		float fSlow5 = std::sin(fSlow3);
		float fSlow6 = std::max<float>(0.0f, std::min<float>(3.5e+02f, float(fHslider4)));
		float fSlow7 = std::max<float>(0.0f, std::min<float>(3.5e+02f, float(fHslider5)));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			iVec0[0] = 1;
			float fTemp1 = fSlow2 * fRec0[1] - fTemp0;
			fVec1[IOTA0 & 2047] = fTemp1;
			fRec1[0] = fSlow5 * fRec2[1] + fSlow4 * fRec1[1];
			fRec2[0] = float(1 - iVec0[1]) + fSlow4 * fRec2[1] - fSlow5 * fRec1[1];
			float fTemp2 = fConst0 * (0.005f * (fRec1[0] + 1.0f) + 0.001f);
			float fTemp3 = fSlow6 + fTemp2;
			int iTemp4 = int(fTemp3);
			float fTemp5 = std::floor(fTemp3);
			fRec0[0] = fVec1[(IOTA0 - std::min<int>(1049, std::max<int>(0, iTemp4))) & 2047] * (fTemp5 + (1.0f - fTemp2) - fSlow6) + (fSlow6 + (fTemp2 - fTemp5)) * fVec1[(IOTA0 - std::min<int>(1049, std::max<int>(0, iTemp4 + 1))) & 2047];
			output0[i0] = FAUSTFLOAT(0.5f * (fTemp0 + fRec0[0] * fSlow1));
			float fTemp6 = float(input1[i0]);
			float fTemp7 = fSlow2 * fRec3[1] - fTemp6;
			fVec2[IOTA0 & 2047] = fTemp7;
			float fTemp8 = fConst0 * (0.005f * (fRec2[0] + 1.0f) + 0.001f);
			float fTemp9 = fSlow7 + fTemp8;
			int iTemp10 = int(fTemp9);
			float fTemp11 = std::floor(fTemp9);
			fRec3[0] = fVec2[(IOTA0 - std::min<int>(1049, std::max<int>(0, iTemp10))) & 2047] * (fTemp11 + (1.0f - fTemp8) - fSlow7) + (fSlow7 + (fTemp8 - fTemp11)) * fVec2[(IOTA0 - std::min<int>(1049, std::max<int>(0, iTemp10 + 1))) & 2047];
			output1[i0] = FAUSTFLOAT(0.5f * (fTemp6 + fRec3[0] * fSlow1));
			iVec0[1] = iVec0[0];
			IOTA0 = IOTA0 + 1;
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "ChaosFlanger.dsp"
	#define FAUST_CLASS_NAME "_ChaosFlanger"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _ChaosFlanger -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 6
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Feedback", fHslider2, 0.75f, 0.0f, 1.0f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("FlangeLeft", fHslider4, 5e+01f, 0.0f, 3.5e+02f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("FlangeRight", fHslider5, 5e+01f, 0.0f, 3.5e+02f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("Invert", fHslider0, 0.0f, 0.0f, 1.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Strength", fHslider1, 0.5f, 0.0f, 1.0f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("Speed", fHslider3, 3.0f, 0.0f, 1e+01f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Feedback, "Feedback", fHslider2, 0.75f, 0.0f, 1.0f, 0.001f) \
		p(HORIZONTALSLIDER, FlangeLeft, "FlangeLeft", fHslider4, 5e+01f, 0.0f, 3.5e+02f, 0.01f) \
		p(HORIZONTALSLIDER, FlangeRight, "FlangeRight", fHslider5, 5e+01f, 0.0f, 3.5e+02f, 0.01f) \
		p(HORIZONTALSLIDER, Invert, "Invert", fHslider0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(HORIZONTALSLIDER, Strength, "Strength", fHslider1, 0.5f, 0.0f, 1.0f, 0.01f) \
		p(HORIZONTALSLIDER, Speed, "Speed", fHslider3, 3.0f, 0.0f, 1e+01f, 0.01f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
