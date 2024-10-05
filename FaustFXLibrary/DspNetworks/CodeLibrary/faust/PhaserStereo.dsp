declare name "StereoPhaser";
declare author "Dabbu Debendra";
declare version "1.0";
declare license "HISE Standard"; 
import("stdfaust.lib");
   invert = hslider("Modes [style:knob]", 0, 0, 1, 1);
   Notches = 4;
   speed  = hslider("Speed[unit:Hz] [style:knob]", 0.5, 0, 5, 0.001);
   fb     = 0.8;
   width  = hslider("Width[unit:%] [style:knob]", 100, 50, 150, 1);
   frqmin = 50;
   frqmax = 500;
   fratio = 2.0;
   depth = hslider("Intensity[style:knob][unit:%][acc:1 0 -10 0 10]", 50,0,100,0.01)*(0.015);
   phaser2_stereo_demo = pf.phaser2_stereo(Notches,width,frqmin,fratio,frqmax,speed,depth,fb,invert);
   

process = phaser2_stereo_demo;
