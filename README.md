# ROOTGradientSpectra

An OpenGL-enhanced ROOT macro for **multi-gradient histogram overlays**, ideal for **energy-spectra visualization** and **data presentation** in experimental and nuclear physics.

This project was **inspired by** the original ROOT OpenGL gradient tutorial by **Timur Pocheptsov**, and extends it by supporting **multiple gradient palettes** on a single canvas — suitable for comparing spectral distributions or highlighting overlapping datasets.

---

## Features

- Multiple independent linear gradients using ROOT’s OpenGL engine  
- Overlay and blending of histograms with semi-transparent fills  
- Customizable color stops and gradient directions  
- Ideal for energy-spectrum, particle-detection, or general scientific visualization  

---

## Example

<img src="multidraw/demo.png" width="600">

Run:
```bash
root -l multidrawgrad.C
