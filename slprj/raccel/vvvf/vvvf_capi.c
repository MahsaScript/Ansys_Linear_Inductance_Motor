#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "vvvf_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 22
#endif
#ifndef SS_INT64
#define SS_INT64 23
#endif
#else
#include "builtin_typeid_types.h"
#include "vvvf.h"
#include "vvvf_capi.h"
#include "vvvf_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"vvvf/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "vvvf/Speed Reference1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 1 } , { 2 , 0 , TARGET_STRING ( "vvvf/Subsystem/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"vvvf/Subsystem/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0
, TARGET_STRING ( "vvvf/Voltage Measurement/do not delete this gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/unit conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/1_2H" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/1_Tb2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/Gain" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/web_psb" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"vvvf/I1/Model/Data Type Conversion" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 12 , 0 , TARGET_STRING ( "vvvf/I2/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"vvvf/I3/Model/Data Type Conversion" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 14 , 0 , TARGET_STRING ( "vvvf/I4/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"vvvf/I5/Model/Data Type Conversion" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 1 } , { 16 , 0 , TARGET_STRING ( "vvvf/I6/Model/Data Type Conversion" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"vvvf/Subsystem/Repeating Sequence/Look-Up Table1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING ( "vvvf/V/Model/DC" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 19 , 0 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 0 , 0
, 1 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "" ) , 1 , 0
, 4 , 0 , 0 } , { 21 , 2 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 22 , 2 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation"
) , TARGET_STRING ( "" ) , 1 , 0 , 5 , 0 , 0 } , { 23 , 2 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation"
) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 24 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 27 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 28 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 31 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 32 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 35 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 36 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 39 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 40 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 42 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 43 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 44 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 47 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 48 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 49 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 51 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 52 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)"
) , TARGET_STRING ( "" ) , 1 , 0 , 5 , 0 , 0 } , { 53 , 10 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 54 , 10 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)"
) , TARGET_STRING ( "" ) , 1 , 0 , 5 , 0 , 0 } , { 55 , 11 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 56 , 11 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1"
) , TARGET_STRING ( "" ) , 1 , 0 , 5 , 0 , 0 } , { 57 , 2 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/1-D Lookup Table"
) , TARGET_STRING ( "Isat" ) , 0 , 0 , 0 , 0 , 0 } , { 58 , 1 , TARGET_STRING
(
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Product"
) , TARGET_STRING ( "Lm" ) , 0 , 0 , 0 , 0 , 0 } , { 59 , 2 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Product1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 5 , 0 , 0 } , { 60 , 2 ,
TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/inversion"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 5 , 0 , 0 } , { 61 , 2 , TARGET_STRING
(
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Switch"
) , TARGET_STRING ( "Lm" ) , 0 , 0 , 0 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/wbase"
) , TARGET_STRING ( "" ) , 0 , 0 , 6 , 0 , 0 } , { 63 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vdr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 64 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vds"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 65 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 66 , 3 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 67 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vdr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 68 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vds"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 69 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 70 , 4 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vdr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 72 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vds"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 73 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqr"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 74 , 5 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqs"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/ira"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 76 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/irb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/isa"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 78 , 6 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/isb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/ira"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 80 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/irb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 81 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/isa"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 82 , 7 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/isb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 83 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/ira"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 84 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/irb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 85 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/isa"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 86 , 8 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/isb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 87 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/W(4,3)=wr-1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 88 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 89 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 90 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 91 , 9 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Trigonometric Function1"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 92 , 10 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/W(2,1)=-wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 93 , 11 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/W(4,3)=wr"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 94 , 0 , TARGET_STRING (
"vvvf/Subsystem/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 95 , 0 , TARGET_STRING (
"vvvf/Subsystem/PID Controller/N Gain/Internal Parameters/Filter Coefficient"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 96 , 0 , TARGET_STRING (
"vvvf/Subsystem/PID Controller/Sum/Sum_PID/Sum" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 97 , 2 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 98 , TARGET_STRING ( "vvvf/V" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING ( "vvvf/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 100 , TARGET_STRING (
"vvvf/Speed Reference1" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 101 ,
TARGET_STRING ( "vvvf/Speed Reference1" ) , TARGET_STRING ( "Before" ) , 0 ,
0 , 0 } , { 102 , TARGET_STRING ( "vvvf/Speed Reference1" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 103 , TARGET_STRING ( "vvvf/Step" ) ,
TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 104 , TARGET_STRING ( "vvvf/Step"
) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 105 , TARGET_STRING (
"vvvf/Step" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 106 ,
TARGET_STRING ( "vvvf/Subsystem/PID Controller" ) , TARGET_STRING ( "P" ) , 0
, 0 , 0 } , { 107 , TARGET_STRING ( "vvvf/Subsystem/PID Controller" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 108 , TARGET_STRING (
"vvvf/Subsystem/PID Controller" ) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , {
109 , TARGET_STRING ( "vvvf/Subsystem/PID Controller" ) , TARGET_STRING ( "N"
) , 0 , 0 , 0 } , { 110 , TARGET_STRING ( "vvvf/Subsystem/PID Controller" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 111 ,
TARGET_STRING ( "vvvf/Subsystem/PID Controller" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 112 , TARGET_STRING (
"vvvf/Subsystem/Repeating Sequence" ) , TARGET_STRING ( "rep_seq_y" ) , 0 , 7
, 0 } , { 113 , TARGET_STRING ( "vvvf/Subsystem/Constant6" ) , TARGET_STRING
( "Value" ) , 0 , 7 , 0 } , { 114 , TARGET_STRING ( "vvvf/Subsystem/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"vvvf/Subsystem/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0
, 0 } , { 116 , TARGET_STRING (
"vvvf/Voltage Measurement/do not delete this gain" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs" ) ,
TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 118 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/Gain Vr_Vs1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 119 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/unit conversion" ) ,
TARGET_STRING ( "Gain" ) , 0 , 3 , 0 } , { 120 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/1\\p" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/1_2H" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/1_Tb2" ) , TARGET_STRING
( "Gain" ) , 0 , 0 , 0 } , { 123 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/F" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/Gain" ) , TARGET_STRING
( "Gain" ) , 0 , 1 , 0 } , { 125 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/web_psb" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/Rotor angle thetam" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 127 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Mechanical model/Rotor speed (wm)" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"vvvf/Subsystem/Repeating Sequence/Constant" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 129 , TARGET_STRING (
"vvvf/Subsystem/Repeating Sequence/Look-Up Table1" ) , TARGET_STRING (
"BreakpointsForDimension1" ) , 0 , 7 , 0 } , { 130 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P1" ) , 0 ,
9 , 0 } , { 131 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P2" ) , 0 ,
10 , 0 } , { 132 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P4" ) , 0 ,
11 , 0 } , { 133 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P5" ) , 0 ,
12 , 0 } , { 134 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P6" ) , 0 ,
13 , 0 } , { 135 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P7" ) , 0 ,
14 , 0 } , { 136 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P8" ) , 0 ,
13 , 0 } , { 137 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P9" ) , 0 ,
0 , 0 } , { 138 , TARGET_STRING (
"vvvf/powergui/EquivalentModel1/State-Space" ) , TARGET_STRING ( "P10" ) , 0
, 0 , 0 } , { 139 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 140 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 142 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 144 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Lm_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 150 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 151 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 152 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/1_Vb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 156 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 157 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 158 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/ib"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 162 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant1" ) ,
TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 163 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant3" ) ,
TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 165 , TARGET_STRING (
"vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"vvvf/Subsystem/Sine/Sine/Look-Up Table" ) , TARGET_STRING ( "Table" ) , 2 ,
15 , 1 } , { 167 , TARGET_STRING ( "vvvf/Subsystem/Sine/Sine/Look-Up Table" )
, TARGET_STRING ( "BreakpointsForDimension1" ) , 3 , 15 , 2 } , { 168 ,
TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 169 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/R*Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Lm"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/u1"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 174 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 8 , 0 } , { 175 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 8 , 0 } , { 176 ,
TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/wbase"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 177 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/phi/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 6 , 0 } , { 178 ,
TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqr,vdr"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 179 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Rotor reference frame/vqs,vds"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqr,vdr"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Stationary reference frame/vqs,vds"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqr,vdr"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/Synchronous reference frame/vqs,vds"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/abc to dq  transformation/transit/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 185 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/ira,irb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Rotor reference frame/isa,isb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/ira,irb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Stationary reference frame/isa,isb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/ira,irb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/dq to abc transformation/Synchronous reference frame/isa,isb"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/sin(beta),cos(beta), sin(th),cos(th)"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 192 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/W"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/u3"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 194 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/we"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 195 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(beta),cos(beta),sin(th),cos(th)/web_psb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 197 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/sin(thr),cos(thr)"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/W"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 199 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 200 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/u1"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 201 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 202 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/sin(thr),cos(thr)"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 203 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/W"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 204 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 205 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/u4"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 206 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/sin,cos/sin(thr),cos(thr)1/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING (
"vvvf/Subsystem/Sine/Sine/Handle Quarter Symmetry Sine/Point25" ) ,
TARGET_STRING ( "Value" ) , 3 , 0 , 2 } , { 208 , TARGET_STRING (
"vvvf/Subsystem/Sine/Sine/Handle Quarter Symmetry Sine/Point50" ) ,
TARGET_STRING ( "Value" ) , 3 , 0 , 2 } , { 209 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Laq=Lad/u2"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 210 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/u1"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 211 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Matrix L/u5"
) , TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 212 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 213 , TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 214 ,
TARGET_STRING (
 "vvvf/Asynchronous Machine SI Units/Electrical model/Asynchronous Machine State-space model/Saturation/phimqd/u1"
) , TARGET_STRING ( "Value" ) , 0 , 8 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 215 , 0
, TARGET_STRING ( "vvvf/Out1" ) , TARGET_STRING ( "" ) , 1 , 0 , 1 , 0 , 0 }
, { 216 , 0 , TARGET_STRING ( "vvvf/Out2" ) , TARGET_STRING (
"<Rotor speed (wm)>" ) , 2 , 0 , 0 , 0 , 0 } , { 217 , 0 , TARGET_STRING (
"vvvf/Out3" ) , TARGET_STRING ( "<Electromagnetic torque Te (N*m)>" ) , 3 , 0
, 0 , 0 , 0 } , { 218 , 0 , TARGET_STRING ( "vvvf/Out4" ) , TARGET_STRING (
"" ) , 4 , 0 , 0 , 0 , 1 } , { 219 , 0 , TARGET_STRING ( "vvvf/Out5" ) ,
TARGET_STRING ( "" ) , 5 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . kyzuz0c2ou , & rtB . lma3pjjclw ,
& rtB . cnowixuruv [ 0 ] , & rtB . mhhevg4vlf , & rtB . e0zg34sjrt , & rtB .
eypf5fvuhy [ 0 ] , & rtB . et02ll3jko [ 0 ] , & rtB . gywezhjjbo , & rtB .
mmslrcwj5x , & rtB . f2b5yhh4sl [ 0 ] , & rtB . ofe2tbnzp1 , & rtB .
hl3zkut0tq , & rtB . krwau33jsm , & rtB . jwsiric30g , & rtB . cl5eiuyk0x , &
rtB . dduwtifztf , & rtB . oj010qekf1 , & rtB . n0nxhg3cgb , & rtB .
mvr5juzn0d , & rtB . o4mv0apu4p [ 0 ] , & rtB . ij320zmpr0 [ 0 ] , & rtB .
o4k3lywywo [ 0 ] , & rtB . nfx3ygt3dv [ 0 ] , & rtB . n0dnv4pnlf , & rtB .
p2yqvbxfbg , & rtB . ellcd02d0a , & rtB . gnhazeo2uj , & rtB . eplxs5lwue , &
rtB . bh3kicabjx , & rtB . dreas41q31 , & rtB . gd120fhzkj , & rtB .
jdn3shvlxc , & rtB . g4hfa4uke0 , & rtB . euxnpqq3bj , & rtB . mqv5agdv5x , &
rtB . pfwp1k1o3k , & rtB . pbhbu5syo3 , & rtB . iby2pb1cme , & rtB .
cqwuo1xw0b , & rtB . lgiwwylx0p , & rtB . b1hqruu3lc , & rtB . jrl11asq0k , &
rtB . lu3zfkpimu , & rtB . psnaawa4gb , & rtB . aiph1d1ozm , & rtB .
fxgts2qscc , & rtB . mx24leduor , & rtB . kovx3slok1 , & rtB . f3fd2pxxgz , &
rtB . closv3m451 , & rtB . hvinyhszko , & rtB . iw1cd0lav2 , & rtB .
pia0she3o4 [ 0 ] , & rtB . otwdcoetlk [ 0 ] , & rtB . pqf1n3c5zd [ 0 ] , &
rtB . fiyra3eut5 [ 0 ] , & rtB . gb4m1upgms [ 0 ] , & rtB . hd4k5zuzfl , &
rtB . hkxto43bbu , & rtB . nfx3ygt3dv [ 0 ] , & rtB . o4k3lywywo [ 0 ] , &
rtB . n0dnv4pnlf , & rtB . kgnko1zzwd [ 0 ] , & rtB . ellcd02d0a , & rtB .
eplxs5lwue , & rtB . p2yqvbxfbg , & rtB . gnhazeo2uj , & rtB . dreas41q31 , &
rtB . jdn3shvlxc , & rtB . bh3kicabjx , & rtB . gd120fhzkj , & rtB .
euxnpqq3bj , & rtB . pfwp1k1o3k , & rtB . g4hfa4uke0 , & rtB . mqv5agdv5x , &
rtB . pbhbu5syo3 , & rtB . iby2pb1cme , & rtB . cqwuo1xw0b , & rtB .
lgiwwylx0p , & rtB . b1hqruu3lc , & rtB . jrl11asq0k , & rtB . lu3zfkpimu , &
rtB . psnaawa4gb , & rtB . aiph1d1ozm , & rtB . fxgts2qscc , & rtB .
mx24leduor , & rtB . kovx3slok1 , & rtB . pia0she3o4 [ 0 ] , & rtB .
hvinyhszko , & rtB . iw1cd0lav2 , & rtB . f3fd2pxxgz , & rtB . closv3m451 , &
rtB . pqf1n3c5zd [ 0 ] , & rtB . gb4m1upgms [ 0 ] , & rtB . l4bi3vcc2y , &
rtB . p2q5eo3ncp , & rtB . bb3bcb2evb , & rtB . g2cszcmclk , & rtP .
V_Amplitude , & rtP . Gain1_Gain_jt2wimow1f , & rtP . SpeedReference1_Time ,
& rtP . SpeedReference1_Y0 , & rtP . SpeedReference1_YFinal , & rtP .
Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal , & rtP . PIDController_P ,
& rtP . PIDController_I , & rtP . PIDController_D , & rtP . PIDController_N ,
& rtP . PIDController_InitialConditionForIntegrator , & rtP .
PIDController_InitialConditionForFilter , & rtP . RepeatingSequence_rep_seq_y
[ 0 ] , & rtP . Constant6_Value_knfpzjs1ar [ 0 ] , & rtP .
Gain1_Gain_ejiryrm5j4 , & rtP . Integrator_IC_i2vfa00yuw , & rtP .
donotdeletethisgain_Gain , & rtP . GainVr_Vs_Gain [ 0 ] , & rtP .
GainVr_Vs1_Gain [ 0 ] , & rtP . unitconversion_Gain [ 0 ] , & rtP . up_Gain ,
& rtP . u_2H_Gain , & rtP . u_Tb2_Gain , & rtP . F_Gain , & rtP . Gain_Gain [
0 ] , & rtP . web_psb_Gain_kuk5g3cab0 , & rtP . Rotoranglethetam_IC , & rtP .
Rotorspeedwm_IC , & rtP . Constant_Value_mko5x2kkfl , & rtP .
LookUpTable1_bp01Data [ 0 ] , & rtP . StateSpace_P1 [ 0 ] , & rtP .
StateSpace_P2 [ 0 ] , & rtP . StateSpace_P4 [ 0 ] , & rtP . StateSpace_P5 [ 0
] , & rtP . StateSpace_P6 [ 0 ] , & rtP . StateSpace_P7 [ 0 ] , & rtP .
StateSpace_P8 [ 0 ] , & rtP . StateSpace_P9 , & rtP . StateSpace_P10 , & rtP
. Constant_Value_cphior1m01 , & rtP . Constant1_Value_mra2gbpsfd , & rtP .
Constant2_Value [ 0 ] , & rtP . Constant3_Value , & rtP . Constant4_Value [ 0
] , & rtP . Constant5_Value , & rtP . Lm_nosat_Value , & rtP .
Switch_Threshold , & rtP . Switch1_Threshold , & rtP . Switch2_Threshold , &
rtP . Constant_Value_gtcefg4zzv , & rtP . Constant1_Value_faydk34tyo , & rtP
. Constant2_Value_k5k5bfeqo3 , & rtP . Constant3_Value_arz4qri3yc , & rtP .
Constant4_Value_imbo4fbnsv , & rtP . u_Vb_Gain , & rtP .
Constant_Value_kly1hwzxtv , & rtP . Constant1_Value_odujgzr1je , & rtP .
Constant2_Value_aig4mgmkah , & rtP . Constant3_Value_g55vewersr , & rtP .
Constant4_Value_euqv3crn5c , & rtP . ib_Gain , & rtP .
Constant_Value_oc5ovlg3x4 , & rtP . Constant1_Value_n30gxh2450 , & rtP .
Constant2_Value_l1jbfmoris , & rtP . Constant3_Value_kyknctkiab , & rtP .
Constant4_Value_n0est4yi5w , & rtP . LookUpTable_tableData [ 0 ] , & rtP .
LookUpTable_bp01Data [ 0 ] , & rtP . u1_Gain [ 0 ] , & rtP . Linv_Y0 , & rtP
. RLinv_Y0 , & rtP . Lm_Y0 , & rtP . Constant1_Value , & rtP .
u1_Value_d5egqcm1pc [ 0 ] , & rtP . uDLookupTable_tableData [ 0 ] , & rtP .
uDLookupTable_bp01Data [ 0 ] , & rtP . wbase_Gain , & rtP .
Integrator_IC_ae2mgg5baa [ 0 ] , & rtP . vqrvdr_Y0 , & rtP . vqsvds_Y0 , &
rtP . vqrvdr_Y0_pi4orirh4m , & rtP . vqsvds_Y0_lyow20grr3 , & rtP .
vqrvdr_Y0_jimj400mu5 , & rtP . vqsvds_Y0_pwfnlr1s2b , & rtP . Constant6_Value
[ 0 ] , & rtP . irairb_Y0 , & rtP . isaisb_Y0 , & rtP . irairb_Y0_ivyhy1p3ly
, & rtP . isaisb_Y0_gpqqvmdlbh , & rtP . irairb_Y0_p0eabwehg2 , & rtP .
isaisb_Y0_bpi2zml5at , & rtP . sinbetacosbetasinthcosth_Y0 , & rtP . W_Y0 , &
rtP . u3_Value [ 0 ] , & rtP . we_Value , & rtP . Gain2_Gain , & rtP .
web_psb_Gain , & rtP . sinthrcosthr_Y0 , & rtP . W_Y0_e3wtsdenx4 , & rtP .
Constant_Value [ 0 ] , & rtP . u1_Value_kogsxs4z2y [ 0 ] , & rtP . Gain1_Gain
, & rtP . sinthrcosthr_Y0_o3efkyf0oi , & rtP . W_Y0_bl1gxt3wnj , & rtP .
Constant_Value_m5od03unxi [ 0 ] , & rtP . u4_Value [ 0 ] , & rtP . Gain3_Gain
, & rtP . Point25_Value , & rtP . Point50_Value , & rtP . u2_Value [ 0 ] , &
rtP . u1_Value [ 0 ] , & rtP . u5_Value [ 0 ] , & rtP . uTT1e6s_Gain , & rtP
. Integrator_IC , & rtP . u1_Value_ko0zivs4jv [ 0 ] , & rtY . npec32cc2u [ 0
] , & rtY . g3gy4f2qnt , & rtY . iirxjsi1ck , & rtY . ff3fiqzzpo , & rtY .
eim4mc5rzx , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } , { "short" , "int16_T" , 0 , 0 , sizeof ( int16_T )
, ( uint8_T ) SS_INT16 , 0 , 0 , 0 } , { "unsigned short" , "uint16_T" , 0 ,
0 , sizeof ( uint16_T ) , ( uint8_T ) SS_UINT16 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , {
rtwCAPI_VECTOR , 20 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 22 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 24 , 2 , 0 } , { rtwCAPI_VECTOR , 26 , 2 , 0 } , {
rtwCAPI_VECTOR , 28 , 2 , 0 } , { rtwCAPI_VECTOR , 30 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 3 , 1 , 2 , 1 , 19 , 1 , 12 , 1
, 4 , 4 , 4 , 1 , 1 , 3 , 1 , 2 , 18 , 9 , 1 , 4 , 18 , 44 , 2 , 6 , 1 , 6 ,
6 , 1 , 1 , 33 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 }
; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
rtwCAPI_FIX_UNIFORM_SCALING , 16 , - 14 , ( boolean_T ) 1 } , { ( const void
* ) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ]
, rtwCAPI_FIX_UNIFORM_SCALING , 16 , - 16 , ( boolean_T ) 0 } } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0
} , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 98 , rtRootInputs , 0 , rtRootOutputs , 5 }
, { rtBlockParameters , 117 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 1547433344U , 230169129U , 1701565233U ,
1522444939U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * vvvf_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void vvvf_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void vvvf_host_InitializeDataMapInfo ( vvvf_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
