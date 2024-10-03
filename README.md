# faust_fx_library

A community collection of Faust powered FX for usage in HISE.

This repository hosts a collection of effect algorithms made in Faust. You can use this library:

- to extend the effect selection in HISE for your project
- use the effects in a Rhapsody Player library (at some point in the future)

## Guidelines

This repository is a joint effort to find the gems from the [Faust Library](https://faustlibraries.grame.fr) or share custom algorithms. In order for this to be useful, we should follow a few guidelines to make this a good curated set of effects. 

### One .dsp file per effect

The Faust algorithm that you want to share should be supplied with a single .dsp file per FX that should be loadable directly into HISE. We assume stereo operation mode for all effects, so if you drop this is in a hardcoded FX module, it's supposed to work right out of the box.

### Sensible parameter range & naming

Every parameter that is published as scriptnode parameter should have a reasonable range & named with CamelCase without whitespace (for compatibility reasons)

### Only the things that HISE is missing

There are a lot of things in the Faust library, from basic operators to complex effect algorithms. In order for this collection to fulfil its goal, we should limit the collection to effects that are missing in HISE or have a subpar quality that you would like to improve. So eg. [this](https://faustlibraries.grame.fr/libs/filters/#parametric-equalizers-shelf-peaking) would not be a suitable candidate (not because it sounds bad but because there are already enough generic biquad filters in HISE).

## Contributing

If you want to contribute to this repository, just let me know (in the HISE forum), then I'll add you as collaborateur. Ideally the discussion about effects should be in a dedicated issue for every dsp node, then we can follow the history of the development.