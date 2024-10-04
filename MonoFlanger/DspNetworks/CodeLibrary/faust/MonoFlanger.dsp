// Faust Source File: ChaosFlanger
// Created with HISE on 2024-10-04
// Developed by DabDab
declare name "Mono-Flanger";
declare author "Dabbu Debendra";
declare copyright "(c) Dabdab";
declare version "1.00";
import("stdfaust.lib");
dmax = 512;
curdel1=hslider("Delay",50,0.0,250,0.01);
depth=hslider("Strength[style:knob][unit:%]",0.5,0,1,0.01);
fb= hslider("Feedback[style:knob][unit:db]",0.75,0,0.98,0.001);
invert=hslider("Invert[style:knob]",0,0,1,1.0);
process = pf.flanger_mono(dmax,curdel1,depth,fb,invert),pf.flanger_mono(dmax,curdel1,depth,fb,invert);