/* ------------------------------------------------------------
author: "Dabbu Debendra"
copyright: "(c) Dabdab"
name: "Mono-Flanger"
version: "1.00"
Code generated with Faust 2.74.6 (https://faust.grame.fr)
Compilation options: -lang cpp -rui -nvi -ct 1 -cn _MonoFlanger -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0
------------------------------------------------------------ */

#ifndef  ___MonoFlanger_H__
#define  ___MonoFlanger_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>

#ifndef FAUSTCLASS 
#define FAUSTCLASS _MonoFlanger
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


class _MonoFlanger final : public ::faust::dsp {
	
 public:
	
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fVec0[256];
	FAUSTFLOAT fHslider3;
	float fRec0[2];
	float fVec1[256];
	float fRec1[2];
	int fSampleRate;
	
 public:
	_MonoFlanger() {
	}
	
	void metadata(Meta* m) { 
		m->declare("author", "Dabbu Debendra");
		m->declare("compile_options", "-lang cpp -rui -nvi -ct 1 -cn _MonoFlanger -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0");
		m->declare("copyright", "(c) Dabdab");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.1.0");
		m->declare("filename", "MonoFlanger.dsp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.0");
		m->declare("name", "Mono-Flanger");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "1.1.0");
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
	}
	
	void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.0f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(0.75f);
		fHslider3 = FAUSTFLOAT(5e+01f);
	}
	
	void instanceClear() {
		IOTA0 = 0;
		for (int l0 = 0; l0 < 256; l0 = l0 + 1) {
			fVec0[l0] = 0.0f;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec0[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 256; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec1[l3] = 0.0f;
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
	
	_MonoFlanger* clone() {
		return new _MonoFlanger();
	}
	
	int getSampleRate() {
		return fSampleRate;
	}
	
	void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Mono-Flanger");
		ui_interface->addHorizontalSlider("Delay", &fHslider3, FAUSTFLOAT(5e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(2.5e+02f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->declare(&fHslider2, "unit", "db");
		ui_interface->addHorizontalSlider("Feedback", &fHslider2, FAUSTFLOAT(0.75f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.98f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Invert", &fHslider0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->declare(&fHslider1, "unit", "%");
		ui_interface->addHorizontalSlider("Strength", &fHslider1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider1)));
		float fSlow1 = ((int(std::max<float>(0.0f, std::min<float>(1.0f, float(fHslider0))))) ? -fSlow0 : fSlow0);
		float fSlow2 = std::max<float>(0.0f, std::min<float>(0.98f, float(fHslider2)));
		float fSlow3 = std::max<float>(0.0f, std::min<float>(2.5e+02f, float(fHslider3)));
		int iSlow4 = int(fSlow3);
		int iSlow5 = std::min<int>(513, std::max<int>(0, iSlow4 + 1));
		float fSlow6 = std::floor(fSlow3);
		float fSlow7 = fSlow3 - fSlow6;
		int iSlow8 = std::min<int>(513, std::max<int>(0, iSlow4));
		float fSlow9 = fSlow6 + (1.0f - fSlow3);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = float(input0[i0]);
			float fTemp1 = fSlow2 * fRec0[1] - fTemp0;
			fVec0[IOTA0 & 255] = fTemp1;
			fRec0[0] = fSlow9 * fVec0[(IOTA0 - iSlow8) & 255] + fSlow7 * fVec0[(IOTA0 - iSlow5) & 255];
			output0[i0] = FAUSTFLOAT(0.5f * (fTemp0 + fRec0[0] * fSlow1));
			float fTemp2 = float(input1[i0]);
			float fTemp3 = fSlow2 * fRec1[1] - fTemp2;
			fVec1[IOTA0 & 255] = fTemp3;
			fRec1[0] = fSlow9 * fVec1[(IOTA0 - iSlow8) & 255] + fSlow7 * fVec1[(IOTA0 - iSlow5) & 255];
			output1[i0] = FAUSTFLOAT(0.5f * (fTemp2 + fRec1[0] * fSlow1));
			IOTA0 = IOTA0 + 1;
			fRec0[1] = fRec0[0];
			fRec1[1] = fRec1[0];
		}
	}

};

#ifdef FAUST_UIMACROS
	
	#define FAUST_FILE_NAME "MonoFlanger.dsp"
	#define FAUST_CLASS_NAME "_MonoFlanger"
	#define FAUST_COMPILATION_OPIONS "-lang cpp -rui -nvi -ct 1 -cn _MonoFlanger -scn ::faust::dsp -es 1 -mcd 16 -mdd 1024 -mdy 33 -uim -single -ftz 0"
	#define FAUST_INPUTS 2
	#define FAUST_OUTPUTS 2
	#define FAUST_ACTIVES 4
	#define FAUST_PASSIVES 0

	FAUST_ADDHORIZONTALSLIDER("Delay", fHslider3, 5e+01f, 0.0f, 2.5e+02f, 0.01f);
	FAUST_ADDHORIZONTALSLIDER("Feedback", fHslider2, 0.75f, 0.0f, 0.98f, 0.001f);
	FAUST_ADDHORIZONTALSLIDER("Invert", fHslider0, 0.0f, 0.0f, 1.0f, 1.0f);
	FAUST_ADDHORIZONTALSLIDER("Strength", fHslider1, 0.5f, 0.0f, 1.0f, 0.01f);

	#define FAUST_LIST_ACTIVES(p) \
		p(HORIZONTALSLIDER, Delay, "Delay", fHslider3, 5e+01f, 0.0f, 2.5e+02f, 0.01f) \
		p(HORIZONTALSLIDER, Feedback, "Feedback", fHslider2, 0.75f, 0.0f, 0.98f, 0.001f) \
		p(HORIZONTALSLIDER, Invert, "Invert", fHslider0, 0.0f, 0.0f, 1.0f, 1.0f) \
		p(HORIZONTALSLIDER, Strength, "Strength", fHslider1, 0.5f, 0.0f, 1.0f, 0.01f) \

	#define FAUST_LIST_PASSIVES(p) \

#endif

#endif
