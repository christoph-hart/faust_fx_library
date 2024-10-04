// Faust Source File: ChaosFlanger
// Created with HISE on 2024-10-04
// Developed by DabDab
declare name "DJFlanger";
declare author "Dabbu Debendra";
declare copyright "(c) Dabdab";
declare version "1.00";
import("stdfaust.lib");
lfol = os.oscrs;
lfor = os.oscrc;
dflange = 0.001 * ma.SR * 10;
odflange = 0.001 * ma.SR * 1;
dmax = 1048;
x = odflange+dflange*(1 + lfol(freq))/2;
y = odflange+dflange*(1 + lfor(freq))/2;
freq  = hslider("[1] Speed [acc:0 1 -10 0 15][unit:Hz] [style:knob]", 3, 0, 10, 0.01);
curdel1=hslider("FlangeLeft",50,0.0,350,0.01);
curdel2=hslider("FlangeRight",50,0.0,350,0.01);
depth=hslider("Strength[style:knob][unit:%]",0.5,0,1,0.01);
fb= hslider("Feedback[style:knob][unit:db]",0.75,0,1,0.001);
invert=hslider("Invert[style:knob]",0,0,1,1.0);
process = pf.flanger_stereo(dmax,curdel1+x,curdel2+y,depth,fb,invert);
