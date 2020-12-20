# YCbCr2RGB_dsp

### Author: Ouwzhong, TOM-tym.

#### Abstract

This is a implementation of YCbCr to RGB color space conversion, coding for TMS320C6000 series DSPs from Texas Instruments.

Linear assembly language is used.

This implementation is one part of homework of course `Principles and Applications of DSP Devices` , SEIT, SYSU.

#### Useage:

1. Define your YCbCr data in `main.c`, modify variables `YCbCr`.
2. RUN THE PROGRAM!
3. (optional) Since we've only got integer that is  32-bit long in C64xx DSPs, for fix-point numbers, we actually define the length of decimal part is 20 (variable `pos`). You can enlarge it if you want more precise numbers. Note that pixel values are ranked form 0 to 255 (8-bits), please make sure that integer part is longer than 8+1 bits (1 for sign flag), i.e.  $pos<=(32-1-8)=21$.

#### Update log:

- 2020.19.20 Program is functional, but we just calling c-style sub-function at the moment (_multipy32), may cause performance loss.

- 2020.12.19 Add a framework.