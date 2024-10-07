// Faust Source File: KorgLowPass
// Created with HISE on 2024-10-07
import("stdfaust.lib");
// Filter Frequency - Faust expects a normalised value =- so normalised here
Freq = hslider("Freq.", 3000, 20, 20000, 1)/20000;
Res = hslider("Res.", 1, 0.3, 9.0, 0.1);
// The filter is a mono effect, so duplicated here for stereo usage
process = _,_:ve.korg35LPF(Freq,Res),ve.korg35LPF(Freq,Res);
