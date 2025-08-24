#include "vvvf.h"
#include "rtwtypes.h"
#include <string.h>
#include "mwmathutil.h"
#include <emmintrin.h>
#include "vvvf_private.h"
#include "rt_logging_mmi.h"
#include "vvvf_capi.h"
#include "vvvf_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , &
stopRequested ) ; } rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_engine_exec.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "24.1 (R2024a) 19-Nov-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const
char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_engine_exec.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; ExtY rtY ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; real_T look1_binlxpw ( real_T u0 , const real_T bp0 [
] , const real_T table [ ] , uint32_T maxIndex ) { real_T frac ; real_T
yL_0d0 ; uint32_T bpIdx ; uint32_T iLeft ; uint32_T iRght ; if ( u0 <= bp0 [
0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ]
) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U
; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] )
{ iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U
; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ;
} else { iLeft = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / (
bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } yL_0d0 = table [ iLeft ] ;
return ( table [ iLeft + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } real_T
look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ;
uint32_T bpIdx ; uint32_T found ; uint32_T iLeft ; uint32_T iRght ; if ( u0
<= bp0 [ 0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] -
bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = prevIndex [ 0U ]
; iLeft = 0U ; iRght = maxIndex ; found = 0U ; while ( found == 0U ) { if (
u0 < bp0 [ bpIdx ] ) { iRght = bpIdx - 1U ; bpIdx = ( ( bpIdx + iLeft ) - 1U
) >> 1U ; } else if ( u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ; } else { iLeft
= bpIdx + 1U ; bpIdx = ( ( bpIdx + iRght ) + 1U ) >> 1U ; } } frac = ( u0 -
bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx =
maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] -
bp0 [ maxIndex - 1U ] ) ; } prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [ bpIdx
] ; return ( table [ bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } uint32_T
plook_u32u16u32n16_evenc_f ( uint16_T u , uint16_T bp0 , uint16_T bpSpace ,
uint32_T maxIndex , uint32_T * fraction ) { uint32_T bpIndex ; uint16_T
fbpIndex ; uint16_T uAdjust ; if ( u <= bp0 ) { bpIndex = 0U ; * fraction =
0U ; } else { uAdjust = ( uint16_T ) ( ( uint32_T ) u - bp0 ) ; fbpIndex = (
uint16_T ) ( ( uint32_T ) uAdjust / bpSpace ) ; if ( fbpIndex < maxIndex ) {
bpIndex = fbpIndex ; * fraction = ( ( ( uint32_T ) uAdjust - ( uint16_T ) ( (
uint32_T ) fbpIndex * bpSpace ) ) << 16 ) / bpSpace ; } else { bpIndex =
maxIndex - 1U ; * fraction = 65536U ; } } return bpIndex ; } int16_T
intrp1d_s16s32s32u32u32n16l_f ( uint32_T bpIndex , uint32_T frac , const
int16_T table [ ] ) { int16_T yL_0d0 ; yL_0d0 = table [ bpIndex ] ; return (
int16_T ) ( ( int16_T ) ( ( ( table [ bpIndex + 1U ] - yL_0d0 ) * ( int32_T )
frac ) >> 16 ) + yL_0d0 ) ; } void rt_invd4x4_snf ( const real_T u [ 16 ] ,
real_T y [ 16 ] ) { real_T x [ 16 ] ; real_T s ; real_T smax ; int32_T c ;
int32_T ijA ; int32_T ix ; int32_T iy ; int32_T jA ; int32_T jBcol ; int32_T
jj ; int32_T jp1j ; int32_T pipk ; int8_T ipiv [ 4 ] ; int8_T p [ 4 ] ;
int8_T p_p ; for ( ix = 0 ; ix < 16 ; ix ++ ) { y [ ix ] = 0.0 ; x [ ix ] = u
[ ix ] ; } ipiv [ 0 ] = 1 ; ipiv [ 1 ] = 2 ; ipiv [ 2 ] = 3 ; for ( pipk = 0
; pipk < 3 ; pipk ++ ) { jBcol = pipk * 5 + 2 ; jj = pipk * 5 ; c = 4 - pipk
; iy = 1 ; smax = muDoubleScalarAbs ( x [ jj ] ) ; for ( jA = 2 ; jA <= c ;
jA ++ ) { s = muDoubleScalarAbs ( x [ ( jBcol + jA ) - 3 ] ) ; if ( s > smax
) { iy = jA ; smax = s ; } } if ( x [ ( jBcol + iy ) - 3 ] != 0.0 ) { if ( iy
- 1 != 0 ) { ipiv [ pipk ] = ( int8_T ) ( pipk + iy ) ; iy = ( pipk + iy ) -
1 ; smax = x [ pipk ] ; x [ pipk ] = x [ iy ] ; x [ iy ] = smax ; smax = x [
pipk + 4 ] ; x [ pipk + 4 ] = x [ iy + 4 ] ; x [ iy + 4 ] = smax ; smax = x [
pipk + 8 ] ; x [ pipk + 8 ] = x [ iy + 8 ] ; x [ iy + 8 ] = smax ; smax = x [
pipk + 12 ] ; x [ pipk + 12 ] = x [ iy + 12 ] ; x [ iy + 12 ] = smax ; } iy =
jBcol - pipk ; for ( ix = jBcol ; ix <= iy + 2 ; ix ++ ) { x [ ix - 1 ] /= x
[ jj ] ; } } c = 2 - pipk ; jA = jj ; jj += 4 ; for ( jp1j = 0 ; jp1j <= c ;
jp1j ++ ) { if ( x [ ( jp1j << 2 ) + jj ] != 0.0 ) { smax = - x [ ( jp1j << 2
) + jj ] ; iy = jA + 6 ; ix = ( jA - pipk ) + 8 ; for ( ijA = iy ; ijA <= ix
; ijA ++ ) { x [ ijA - 1 ] += x [ ( ( jBcol + ijA ) - jA ) - 7 ] * smax ; } }
jA += 4 ; } } p [ 0 ] = 1 ; p [ 1 ] = 2 ; p [ 2 ] = 3 ; p [ 3 ] = 4 ; if (
ipiv [ 0 ] > 1 ) { pipk = p [ ipiv [ 0 ] - 1 ] ; p [ ipiv [ 0 ] - 1 ] = 1 ; p
[ 0 ] = ( int8_T ) pipk ; } if ( ipiv [ 1 ] > 2 ) { pipk = p [ ipiv [ 1 ] - 1
] ; p [ ipiv [ 1 ] - 1 ] = p [ 1 ] ; p [ 1 ] = ( int8_T ) pipk ; } if ( ipiv
[ 2 ] > 3 ) { pipk = p [ ipiv [ 2 ] - 1 ] ; p [ ipiv [ 2 ] - 1 ] = p [ 2 ] ;
p [ 2 ] = ( int8_T ) pipk ; } for ( jA = 0 ; jA < 4 ; jA ++ ) { p_p = p [ jA
] ; y [ jA + ( ( p_p - 1 ) << 2 ) ] = 1.0 ; for ( pipk = jA + 1 ; pipk < 5 ;
pipk ++ ) { if ( y [ ( ( ( p_p - 1 ) << 2 ) + pipk ) - 1 ] != 0.0 ) { for (
ix = pipk + 1 ; ix < 5 ; ix ++ ) { y [ ( ix + ( ( p_p - 1 ) << 2 ) ) - 1 ] -=
x [ ( ( ( pipk - 1 ) << 2 ) + ix ) - 1 ] * y [ ( ( ( p_p - 1 ) << 2 ) + pipk
) - 1 ] ; } } } } for ( pipk = 0 ; pipk < 4 ; pipk ++ ) { jBcol = pipk << 2 ;
for ( jA = 3 ; jA >= 0 ; jA -- ) { jj = jA << 2 ; if ( y [ jA + jBcol ] !=
0.0 ) { y [ jA + jBcol ] /= x [ jA + jj ] ; iy = jA - 1 ; for ( ix = 0 ; ix
<= iy ; ix ++ ) { y [ ix + jBcol ] -= y [ jA + jBcol ] * x [ ix + jj ] ; } }
} } } void MdlInitialize ( void ) { int32_T i ; rtX . e5c3t34yfe [ 0 ] = rtP
. Integrator_IC_ae2mgg5baa [ 0 ] ; rtX . e5c3t34yfe [ 1 ] = rtP .
Integrator_IC_ae2mgg5baa [ 1 ] ; rtX . e5c3t34yfe [ 2 ] = rtP .
Integrator_IC_ae2mgg5baa [ 2 ] ; rtX . e5c3t34yfe [ 3 ] = rtP .
Integrator_IC_ae2mgg5baa [ 3 ] ; rtX . jk5zeqvmsz = rtP . Rotoranglethetam_IC
; rtX . ejnpqfalas = rtP . Rotorspeedwm_IC ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } rtX . ow5vjxae2l = rtP .
Integrator_IC_i2vfa00yuw ; rtX . ofid0lihsi = rtP .
PIDController_InitialConditionForIntegrator ; rtX . k1hk1sh0lu = rtP .
PIDController_InitialConditionForFilter ; rtX . iaj1ubzk1n = rtP .
Integrator_IC ; rtB . n0dnv4pnlf = rtP . Lm_Y0 ; rtB . otwdcoetlk [ 0 ] = rtP
. sinthrcosthr_Y0 ; rtB . otwdcoetlk [ 1 ] = rtP . sinthrcosthr_Y0 ; rtB .
otwdcoetlk [ 2 ] = rtP . sinthrcosthr_Y0 ; rtB . otwdcoetlk [ 3 ] = rtP .
sinthrcosthr_Y0 ; rtB . fiyra3eut5 [ 0 ] = rtP . sinthrcosthr_Y0_o3efkyf0oi ;
rtB . fiyra3eut5 [ 1 ] = rtP . sinthrcosthr_Y0_o3efkyf0oi ; rtB . fiyra3eut5
[ 2 ] = rtP . sinthrcosthr_Y0_o3efkyf0oi ; rtB . fiyra3eut5 [ 3 ] = rtP .
sinthrcosthr_Y0_o3efkyf0oi ; rtB . f3fd2pxxgz = rtP .
sinbetacosbetasinthcosth_Y0 ; rtB . closv3m451 = rtP .
sinbetacosbetasinthcosth_Y0 ; rtB . hvinyhszko = rtP .
sinbetacosbetasinthcosth_Y0 ; rtB . iw1cd0lav2 = rtP .
sinbetacosbetasinthcosth_Y0 ; for ( i = 0 ; i < 16 ; i ++ ) { rtB .
o4k3lywywo [ i ] = rtP . Linv_Y0 ; rtB . nfx3ygt3dv [ i ] = rtP . RLinv_Y0 ;
rtB . pqf1n3c5zd [ i ] = rtP . W_Y0_e3wtsdenx4 ; rtB . gb4m1upgms [ i ] = rtP
. W_Y0_bl1gxt3wnj ; rtB . pia0she3o4 [ i ] = rtP . W_Y0 ; } rtB . pbhbu5syo3
= rtP . irairb_Y0 ; rtB . iby2pb1cme = rtP . irairb_Y0 ; rtB . cqwuo1xw0b =
rtP . isaisb_Y0 ; rtB . lgiwwylx0p = rtP . isaisb_Y0 ; rtB . b1hqruu3lc = rtP
. irairb_Y0_ivyhy1p3ly ; rtB . jrl11asq0k = rtP . irairb_Y0_ivyhy1p3ly ; rtB
. lu3zfkpimu = rtP . isaisb_Y0_gpqqvmdlbh ; rtB . psnaawa4gb = rtP .
isaisb_Y0_gpqqvmdlbh ; rtB . aiph1d1ozm = rtP . irairb_Y0_p0eabwehg2 ; rtB .
fxgts2qscc = rtP . irairb_Y0_p0eabwehg2 ; rtB . mx24leduor = rtP .
isaisb_Y0_bpi2zml5at ; rtB . kovx3slok1 = rtP . isaisb_Y0_bpi2zml5at ; rtB .
p2yqvbxfbg = rtP . vqrvdr_Y0 ; rtB . ellcd02d0a = rtP . vqrvdr_Y0 ; rtB .
gnhazeo2uj = rtP . vqsvds_Y0 ; rtB . eplxs5lwue = rtP . vqsvds_Y0 ; rtB .
bh3kicabjx = rtP . vqrvdr_Y0_pi4orirh4m ; rtB . dreas41q31 = rtP .
vqrvdr_Y0_pi4orirh4m ; rtB . gd120fhzkj = rtP . vqsvds_Y0_lyow20grr3 ; rtB .
jdn3shvlxc = rtP . vqsvds_Y0_lyow20grr3 ; rtB . g4hfa4uke0 = rtP .
vqrvdr_Y0_jimj400mu5 ; rtB . euxnpqq3bj = rtP . vqrvdr_Y0_jimj400mu5 ; rtB .
mqv5agdv5x = rtP . vqsvds_Y0_pwfnlr1s2b ; rtB . pfwp1k1o3k = rtP .
vqsvds_Y0_pwfnlr1s2b ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "<Rotor speed (wm)>"
) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "<Rotor speed (wm)>" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "vvvf/Out2" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"<Rotor speed (wm)>" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. ftpuxa04zl . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"ae3cc725-fbd3-446f-82f6-523126820c81" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . ftpuxa04zl . AQHandles , hDT , & srcInfo ) ; if ( rtDW . ftpuxa04zl .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ftpuxa04zl . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
ftpuxa04zl . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ftpuxa04zl .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . ftpuxa04zl . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . ftpuxa04zl . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . ftpuxa04zl . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . ftpuxa04zl . AQHandles , 2 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars (
"<Electromagnetic torque Te (N*m)>" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "<Electromagnetic torque Te (N*m)>" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "vvvf/Out3" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"<Electromagnetic torque Te (N*m)>" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. hp52lf4igt . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"82e733e4-1eb1-401b-b8b3-6ae4b152abcc" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . hp52lf4igt . AQHandles , hDT , & srcInfo ) ; if ( rtDW . hp52lf4igt .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . hp52lf4igt . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
hp52lf4igt . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . hp52lf4igt .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . hp52lf4igt . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . hp52lf4igt . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . hp52lf4igt . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . hp52lf4igt . AQHandles , 3 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "vvvf/Out1" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 3 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. lrinayj5c5 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"d3be627f-4c34-49c6-a9c4-7f193a7b20a0" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . lrinayj5c5 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . lrinayj5c5 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . lrinayj5c5 . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
lrinayj5c5 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . lrinayj5c5 .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . lrinayj5c5 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . lrinayj5c5 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . lrinayj5c5 . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . lrinayj5c5 . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "vvvf/Out5" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. fve5j2hzkb . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"0f6d29ac-12aa-414b-afff-982656c24969" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . fve5j2hzkb . AQHandles , hDT , & srcInfo ) ; if ( rtDW . fve5j2hzkb .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . fve5j2hzkb . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
fve5j2hzkb . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . fve5j2hzkb .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . fve5j2hzkb . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . fve5j2hzkb . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . fve5j2hzkb . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . fve5j2hzkb . AQHandles , 5 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "vvvf/Out4" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. alxpzb4n5e . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"aa886594-fd6f-4c95-a9f5-d73c37b26ef9" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . alxpzb4n5e . AQHandles , hDT , & srcInfo ) ; if ( rtDW . alxpzb4n5e .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . alxpzb4n5e . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
alxpzb4n5e . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . alxpzb4n5e .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . alxpzb4n5e . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . alxpzb4n5e . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . alxpzb4n5e . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . alxpzb4n5e . AQHandles , 4 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } rtDW . ndmq3nqsdc = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void ) memset ( & ( (
( XDis * ) ssGetContStateDisabled ( rtS ) ) -> iaj1ubzk1n ) , 1 , 1 * sizeof
( boolean_T ) ) ; rtDW . h3ttfsops4 = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . a2epbhif3c =
false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW .
k2ymqellzk = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtDW . dyer3jszh3 = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . hgcaqe1nht = false ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; rtDW . h0wbstq2sb = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } rtDW . oxl5j3231b = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . mnzaoheyk3 =
false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW .
pmmn32whzd = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { __m128d tmp_e ; __m128d
tmp_g ; __m128d tmp_i ; __m128d tmp_m ; real_T o4f5cfmrf5 [ 16 ] ; real_T
ocnqsuc5g5 [ 16 ] ; real_T fhlb2qstqs [ 4 ] ; real_T bkadzvdrv5_idx_0 ;
real_T bkadzvdrv5_idx_1 ; real_T bkadzvdrv5_idx_2 ; real_T bkadzvdrv5_idx_3 ;
real_T cx35bjw00t_idx_0 ; real_T cx35bjw00t_idx_1 ; real_T cx35bjw00t_idx_2 ;
real_T cx35bjw00t_idx_3 ; real_T dgdmzzjogn ; real_T dl332u4kll_idx_0 ;
real_T dl332u4kll_idx_1 ; real_T e1mfc3nbgg ; real_T fil2tnzl4q ; real_T
jajzcpktoa ; real_T jqo2opizyd_idx_0 ; real_T nezq2aumsv_idx_0 ; real_T
nezq2aumsv_idx_1 ; real_T tmp ; real_T tmp_p ; int32_T i ; int32_T i_p ;
uint32_T bpIdx ; uint32_T frac ; int16_T khm24hkcsa_idx_0 ; int16_T
khm24hkcsa_idx_1 ; uint16_T ol2nnbdqnc_idx_0 ; uint16_T ol2nnbdqnc_idx_1 ;
uint16_T ol2nnbdqnc_p ; boolean_T jgiay0altu_idx_0 ; boolean_T
jgiay0altu_idx_1 ; boolean_T jgiay0altu_p ; srClearBC ( rtDW . gkp3taud2d ) ;
srClearBC ( rtDW . icsha3sasz ) ; srClearBC ( rtDW . pjxukapuyo ) ; srClearBC
( rtDW . ht1xjimgz4 ) ; srClearBC ( rtDW . otcudvwncc ) ; srClearBC ( rtDW .
ezrryhvozp ) ; srClearBC ( rtDW . cymarl3f1g ) ; srClearBC ( rtDW .
hfxle4xmpy ) ; srClearBC ( rtDW . k3sfgznul3 ) ; srClearBC ( rtDW .
czlc3ljrvw ) ; bkadzvdrv5_idx_0 = rtX . e5c3t34yfe [ 0 ] ; bkadzvdrv5_idx_1 =
rtX . e5c3t34yfe [ 1 ] ; bkadzvdrv5_idx_2 = rtX . e5c3t34yfe [ 2 ] ;
bkadzvdrv5_idx_3 = rtX . e5c3t34yfe [ 3 ] ; if ( ssIsSampleHit ( rtS , 1 , 0
) && ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtP . Constant_Value_cphior1m01
> 0.0 ) { if ( ! rtDW . ndmq3nqsdc ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} ( void ) memset ( & ( ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ->
iaj1ubzk1n ) , 0 , 1 * sizeof ( boolean_T ) ) ; rtDW . ndmq3nqsdc = true ; }
} else { if ( ssGetTaskTime ( rtS , 1 ) == ssGetTStart ( rtS ) ) { ( void )
memset ( & ( ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> iaj1ubzk1n ) ,
1 , 1 * sizeof ( boolean_T ) ) ; } if ( rtDW . ndmq3nqsdc ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void ) memset ( & ( (
( XDis * ) ssGetContStateDisabled ( rtS ) ) -> iaj1ubzk1n ) , 1 , 1 * sizeof
( boolean_T ) ) ; rtDW . ndmq3nqsdc = false ; } } } if ( rtDW . ndmq3nqsdc )
{ dgdmzzjogn = 1.0 / ( ( 1.0 / rtP . u2_Value [ 0 ] + 1.0 / rtP . u2_Value [
1 ] ) + 1.0 / rtX . iaj1ubzk1n ) ; jqo2opizyd_idx_0 = rtP .
u1_Value_ko0zivs4jv [ 0 ] * dgdmzzjogn ; dgdmzzjogn *= rtP .
u1_Value_ko0zivs4jv [ 1 ] ; jajzcpktoa = muDoubleScalarHypot (
bkadzvdrv5_idx_0 * jqo2opizyd_idx_0 + dgdmzzjogn * bkadzvdrv5_idx_2 ,
jqo2opizyd_idx_0 * bkadzvdrv5_idx_1 + dgdmzzjogn * bkadzvdrv5_idx_3 ) ; rtB .
hd4k5zuzfl = look1_pbinlxpw ( jajzcpktoa , rtP . uDLookupTable_bp01Data , rtP
. uDLookupTable_tableData , & rtDW . mxsrormvrm , 1U ) ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . bdjs2rcjwz = ( rtB . hd4k5zuzfl !=
0.0 ) ; } if ( rtDW . bdjs2rcjwz ) { rtB . hkxto43bbu = jajzcpktoa / rtB .
hd4k5zuzfl ; rtB . n0dnv4pnlf = rtB . hkxto43bbu ; } else { rtB . n0dnv4pnlf
= rtP . Constant1_Value ; } memcpy ( & o4f5cfmrf5 [ 0 ] , & rtP . u1_Value [
0 ] , sizeof ( real_T ) << 4U ) ; o4f5cfmrf5 [ 0 ] = rtB . n0dnv4pnlf ;
o4f5cfmrf5 [ 5 ] = rtB . n0dnv4pnlf ; o4f5cfmrf5 [ 2 ] = rtB . n0dnv4pnlf ;
o4f5cfmrf5 [ 7 ] = rtB . n0dnv4pnlf ; o4f5cfmrf5 [ 8 ] = rtB . n0dnv4pnlf ;
o4f5cfmrf5 [ 13 ] = rtB . n0dnv4pnlf ; o4f5cfmrf5 [ 10 ] = rtB . n0dnv4pnlf ;
o4f5cfmrf5 [ 15 ] = rtB . n0dnv4pnlf ; for ( i = 0 ; i <= 14 ; i += 2 ) {
tmp_g = _mm_loadu_pd ( & o4f5cfmrf5 [ i ] ) ; _mm_storeu_pd ( & ocnqsuc5g5 [
i ] , _mm_add_pd ( tmp_g , _mm_loadu_pd ( & rtP . u5_Value [ i ] ) ) ) ; }
rt_invd4x4_snf ( ocnqsuc5g5 , rtB . o4k3lywywo ) ; for ( i = 0 ; i < 4 ; i ++
) { jajzcpktoa = rtB . o4k3lywywo [ ( i << 2 ) + 1 ] ; fil2tnzl4q = rtB .
o4k3lywywo [ i << 2 ] ; jqo2opizyd_idx_0 = rtB . o4k3lywywo [ ( i << 2 ) + 2
] ; dgdmzzjogn = rtB . o4k3lywywo [ ( i << 2 ) + 3 ] ; for ( i_p = 0 ; i_p <=
2 ; i_p += 2 ) { _mm_storeu_pd ( & rtB . nfx3ygt3dv [ i_p + ( i << 2 ) ] ,
_mm_add_pd ( _mm_add_pd ( _mm_add_pd ( _mm_mul_pd ( _mm_set1_pd ( jajzcpktoa
) , _mm_loadu_pd ( & rtP . u1_Value_d5egqcm1pc [ i_p + 4 ] ) ) , _mm_mul_pd (
_mm_set1_pd ( fil2tnzl4q ) , _mm_loadu_pd ( & rtP . u1_Value_d5egqcm1pc [ i_p
] ) ) ) , _mm_mul_pd ( _mm_set1_pd ( jqo2opizyd_idx_0 ) , _mm_loadu_pd ( &
rtP . u1_Value_d5egqcm1pc [ i_p + 8 ] ) ) ) , _mm_mul_pd ( _mm_set1_pd (
dgdmzzjogn ) , _mm_loadu_pd ( & rtP . u1_Value_d5egqcm1pc [ i_p + 12 ] ) ) )
) ; } } rtB . g2cszcmclk = ( rtB . n0dnv4pnlf - rtX . iaj1ubzk1n ) * rtP .
uTT1e6s_Gain ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
gkp3taud2d ) ; } } jgiay0altu_p = ( rtP . Constant1_Value_mra2gbpsfd >= rtP .
Switch_Threshold ) ; if ( jgiay0altu_p ) { memcpy ( & ocnqsuc5g5 [ 0 ] , &
rtB . o4k3lywywo [ 0 ] , sizeof ( real_T ) << 4U ) ; } else { memcpy ( &
ocnqsuc5g5 [ 0 ] , & rtP . Constant2_Value [ 0 ] , sizeof ( real_T ) << 4U )
; } for ( i = 0 ; i <= 2 ; i += 2 ) { tmp_g = _mm_loadu_pd ( & ocnqsuc5g5 [ i
+ 4 ] ) ; tmp_e = _mm_loadu_pd ( & ocnqsuc5g5 [ i ] ) ; tmp_i = _mm_loadu_pd
( & ocnqsuc5g5 [ i + 8 ] ) ; tmp_m = _mm_loadu_pd ( & ocnqsuc5g5 [ i + 12 ] )
; _mm_storeu_pd ( & fhlb2qstqs [ i ] , _mm_add_pd ( _mm_add_pd ( _mm_add_pd (
_mm_mul_pd ( tmp_g , _mm_set1_pd ( bkadzvdrv5_idx_1 ) ) , _mm_mul_pd ( tmp_e
, _mm_set1_pd ( bkadzvdrv5_idx_0 ) ) ) , _mm_mul_pd ( tmp_i , _mm_set1_pd (
bkadzvdrv5_idx_2 ) ) ) , _mm_mul_pd ( tmp_m , _mm_set1_pd ( bkadzvdrv5_idx_3
) ) ) ) ; } fil2tnzl4q = rtX . jk5zeqvmsz ; jajzcpktoa = rtX . ejnpqfalas ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) { if (
rtP . Constant_Value_oc5ovlg3x4 ) { if ( ! rtDW . a2epbhif3c ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . a2epbhif3c =
true ; } } else if ( rtDW . a2epbhif3c ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . otwdcoetlk [ 0 ] =
rtP . sinthrcosthr_Y0 ; rtB . otwdcoetlk [ 1 ] = rtP . sinthrcosthr_Y0 ; rtB
. otwdcoetlk [ 2 ] = rtP . sinthrcosthr_Y0 ; rtB . otwdcoetlk [ 3 ] = rtP .
sinthrcosthr_Y0 ; for ( i = 0 ; i < 16 ; i ++ ) { rtB . pqf1n3c5zd [ i ] =
rtP . W_Y0_e3wtsdenx4 ; } rtDW . a2epbhif3c = false ; } } if ( rtDW .
a2epbhif3c ) { muDoubleScalarSinCos ( fil2tnzl4q , & rtB . otwdcoetlk [ 0 ] ,
& rtB . otwdcoetlk [ 1 ] ) ; rtB . otwdcoetlk [ 2 ] = rtP . Constant_Value [
0 ] ; rtB . otwdcoetlk [ 3 ] = rtP . Constant_Value [ 1 ] ; memcpy ( & rtB .
pqf1n3c5zd [ 0 ] , & rtP . u1_Value_kogsxs4z2y [ 0 ] , sizeof ( real_T ) <<
4U ) ; rtB . pqf1n3c5zd [ 4 ] = jajzcpktoa ; rtB . pqf1n3c5zd [ 1 ] = rtP .
Gain1_Gain * jajzcpktoa ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC
( rtDW . k3sfgznul3 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) &&
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtP . Constant1_Value_n30gxh2450 ) {
if ( ! rtDW . k2ymqellzk ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart (
rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW .
k2ymqellzk = true ; } } else if ( rtDW . k2ymqellzk ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . fiyra3eut5 [ 0 ] =
rtP . sinthrcosthr_Y0_o3efkyf0oi ; rtB . fiyra3eut5 [ 1 ] = rtP .
sinthrcosthr_Y0_o3efkyf0oi ; rtB . fiyra3eut5 [ 2 ] = rtP .
sinthrcosthr_Y0_o3efkyf0oi ; rtB . fiyra3eut5 [ 3 ] = rtP .
sinthrcosthr_Y0_o3efkyf0oi ; rtDW . k2ymqellzk = false ; } } if ( rtDW .
k2ymqellzk ) { muDoubleScalarSinCos ( fil2tnzl4q , & rtB . fiyra3eut5 [ 0 ] ,
& rtB . fiyra3eut5 [ 1 ] ) ; rtB . fiyra3eut5 [ 2 ] = rtP .
Constant_Value_m5od03unxi [ 0 ] ; rtB . fiyra3eut5 [ 3 ] = rtP .
Constant_Value_m5od03unxi [ 1 ] ; memcpy ( & rtB . gb4m1upgms [ 0 ] , & rtP .
u4_Value [ 0 ] , sizeof ( real_T ) << 4U ) ; rtB . gb4m1upgms [ 14 ] = rtP .
Gain3_Gain * jajzcpktoa ; rtB . gb4m1upgms [ 11 ] = jajzcpktoa ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . czlc3ljrvw ) ; } } if
( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) { if (
rtP . Constant3_Value_kyknctkiab ) { if ( ! rtDW . h3ttfsops4 ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . h3ttfsops4 =
true ; } } else if ( rtDW . h3ttfsops4 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . h3ttfsops4 =
false ; } } if ( rtDW . h3ttfsops4 ) { dgdmzzjogn = rtP . we_Value -
jajzcpktoa ; jqo2opizyd_idx_0 = rtP . web_psb_Gain * ssGetT ( rtS ) ;
muDoubleScalarSinCos ( jqo2opizyd_idx_0 , & rtB . hvinyhszko , & rtB .
iw1cd0lav2 ) ; muDoubleScalarSinCos ( jqo2opizyd_idx_0 - fil2tnzl4q , & rtB .
f3fd2pxxgz , & rtB . closv3m451 ) ; memcpy ( & rtB . pia0she3o4 [ 0 ] , & rtP
. u3_Value [ 0 ] , sizeof ( real_T ) << 4U ) ; rtB . pia0she3o4 [ 14 ] =
dgdmzzjogn ; rtB . pia0she3o4 [ 11 ] = rtP . Gain2_Gain * dgdmzzjogn ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . hfxle4xmpy ) ; } }
switch ( ( int32_T ) rtP . Constant2_Value_l1jbfmoris ) { case 1 :
jqo2opizyd_idx_0 = rtB . otwdcoetlk [ 0 ] ; dgdmzzjogn = rtB . otwdcoetlk [ 1
] ; tmp = rtB . otwdcoetlk [ 2 ] ; tmp_p = rtB . otwdcoetlk [ 3 ] ; break ;
case 2 : jqo2opizyd_idx_0 = rtB . fiyra3eut5 [ 0 ] ; dgdmzzjogn = rtB .
fiyra3eut5 [ 1 ] ; tmp = rtB . fiyra3eut5 [ 2 ] ; tmp_p = rtB . fiyra3eut5 [
3 ] ; break ; default : jqo2opizyd_idx_0 = rtB . f3fd2pxxgz ; dgdmzzjogn =
rtB . closv3m451 ; tmp = rtB . hvinyhszko ; tmp_p = rtB . iw1cd0lav2 ; break
; } if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) {
if ( rtP . Constant_Value_kly1hwzxtv ) { if ( ! rtDW . dyer3jszh3 ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . dyer3jszh3 =
true ; } } else if ( rtDW . dyer3jszh3 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . pbhbu5syo3 = rtP .
irairb_Y0 ; rtB . iby2pb1cme = rtP . irairb_Y0 ; rtB . cqwuo1xw0b = rtP .
isaisb_Y0 ; rtB . lgiwwylx0p = rtP . isaisb_Y0 ; rtDW . dyer3jszh3 = false ;
} } if ( rtDW . dyer3jszh3 ) { rtB . pbhbu5syo3 = fhlb2qstqs [ 2 ] ; rtB .
iby2pb1cme = - ( 1.7320508075688772 * fhlb2qstqs [ 3 ] + fhlb2qstqs [ 2 ] ) /
2.0 ; rtB . cqwuo1xw0b = fhlb2qstqs [ 0 ] * dgdmzzjogn + jqo2opizyd_idx_0 *
fhlb2qstqs [ 1 ] ; rtB . lgiwwylx0p = ( ( 1.7320508075688772 *
jqo2opizyd_idx_0 - dgdmzzjogn ) * fhlb2qstqs [ 0 ] + ( - 1.7320508075688772 *
dgdmzzjogn - jqo2opizyd_idx_0 ) * fhlb2qstqs [ 1 ] ) / 2.0 ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . otcudvwncc ) ; } } if
( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) { if (
rtP . Constant1_Value_odujgzr1je ) { if ( ! rtDW . hgcaqe1nht ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . hgcaqe1nht =
true ; } } else if ( rtDW . hgcaqe1nht ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . b1hqruu3lc = rtP .
irairb_Y0_ivyhy1p3ly ; rtB . jrl11asq0k = rtP . irairb_Y0_ivyhy1p3ly ; rtB .
lu3zfkpimu = rtP . isaisb_Y0_gpqqvmdlbh ; rtB . psnaawa4gb = rtP .
isaisb_Y0_gpqqvmdlbh ; rtDW . hgcaqe1nht = false ; } } if ( rtDW . hgcaqe1nht
) { rtB . b1hqruu3lc = dgdmzzjogn * fhlb2qstqs [ 2 ] - jqo2opizyd_idx_0 *
fhlb2qstqs [ 3 ] ; rtB . jrl11asq0k = ( ( - dgdmzzjogn - 1.7320508075688772 *
jqo2opizyd_idx_0 ) * fhlb2qstqs [ 2 ] + ( jqo2opizyd_idx_0 -
1.7320508075688772 * dgdmzzjogn ) * fhlb2qstqs [ 3 ] ) / 2.0 ; rtB .
lu3zfkpimu = fhlb2qstqs [ 0 ] ; rtB . psnaawa4gb = - ( 1.7320508075688772 *
fhlb2qstqs [ 1 ] + fhlb2qstqs [ 0 ] ) / 2.0 ; if ( ssIsModeUpdateTimeStep (
rtS ) ) { srUpdateBC ( rtDW . ezrryhvozp ) ; } } if ( ssIsSampleHit ( rtS , 1
, 0 ) && ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtP .
Constant2_Value_aig4mgmkah ) { if ( ! rtDW . h0wbstq2sb ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . h0wbstq2sb =
true ; } } else if ( rtDW . h0wbstq2sb ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . aiph1d1ozm = rtP .
irairb_Y0_p0eabwehg2 ; rtB . fxgts2qscc = rtP . irairb_Y0_p0eabwehg2 ; rtB .
mx24leduor = rtP . isaisb_Y0_bpi2zml5at ; rtB . kovx3slok1 = rtP .
isaisb_Y0_bpi2zml5at ; rtDW . h0wbstq2sb = false ; } } if ( rtDW . h0wbstq2sb
) { rtB . aiph1d1ozm = dgdmzzjogn * fhlb2qstqs [ 2 ] + jqo2opizyd_idx_0 *
fhlb2qstqs [ 3 ] ; rtB . fxgts2qscc = ( ( 1.7320508075688772 *
jqo2opizyd_idx_0 - dgdmzzjogn ) * fhlb2qstqs [ 2 ] + ( - 1.7320508075688772 *
dgdmzzjogn - jqo2opizyd_idx_0 ) * fhlb2qstqs [ 3 ] ) / 2.0 ; rtB . mx24leduor
= fhlb2qstqs [ 0 ] * tmp_p + fhlb2qstqs [ 1 ] * tmp ; rtB . kovx3slok1 = ( (
1.7320508075688772 * tmp - tmp_p ) * fhlb2qstqs [ 0 ] + ( -
1.7320508075688772 * tmp_p - tmp ) * fhlb2qstqs [ 1 ] ) / 2.0 ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . cymarl3f1g ) ; } }
switch ( ( int32_T ) rtP . Constant3_Value_g55vewersr ) { case 1 :
nezq2aumsv_idx_0 = rtB . pbhbu5syo3 ; nezq2aumsv_idx_1 = rtB . iby2pb1cme ;
break ; case 2 : nezq2aumsv_idx_0 = rtB . b1hqruu3lc ; nezq2aumsv_idx_1 = rtB
. jrl11asq0k ; break ; default : nezq2aumsv_idx_0 = rtB . aiph1d1ozm ;
nezq2aumsv_idx_1 = rtB . fxgts2qscc ; break ; } switch ( ( int32_T ) rtP .
Constant4_Value_euqv3crn5c ) { case 1 : dl332u4kll_idx_0 = rtB . cqwuo1xw0b ;
dl332u4kll_idx_1 = rtB . lgiwwylx0p ; break ; case 2 : dl332u4kll_idx_0 = rtB
. lu3zfkpimu ; dl332u4kll_idx_1 = rtB . psnaawa4gb ; break ; default :
dl332u4kll_idx_0 = rtB . mx24leduor ; dl332u4kll_idx_1 = rtB . kovx3slok1 ;
break ; } rtB . eypf5fvuhy [ 0 ] = rtP . ib_Gain * dl332u4kll_idx_0 * rtP .
GainVr_Vs1_Gain [ 0 ] ; rtB . eypf5fvuhy [ 1 ] = rtP . ib_Gain *
dl332u4kll_idx_1 * rtP . GainVr_Vs1_Gain [ 1 ] ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } cx35bjw00t_idx_0 =
rtP . u_Vb_Gain * rtP . Constant6_Value [ 0 ] ; cx35bjw00t_idx_2 = rtP .
GainVr_Vs_Gain [ 0 ] * rtB . o4mv0apu4p [ 0 ] * rtP . u_Vb_Gain ;
cx35bjw00t_idx_1 = rtP . u_Vb_Gain * rtP . Constant6_Value [ 1 ] ;
cx35bjw00t_idx_3 = rtP . GainVr_Vs_Gain [ 1 ] * rtB . o4mv0apu4p [ 1 ] * rtP
. u_Vb_Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep (
rtS ) ) { if ( rtP . Constant_Value_gtcefg4zzv ) { if ( ! rtDW . oxl5j3231b )
{ if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . oxl5j3231b =
true ; } } else if ( rtDW . oxl5j3231b ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . p2yqvbxfbg = rtP .
vqrvdr_Y0 ; rtB . ellcd02d0a = rtP . vqrvdr_Y0 ; rtB . gnhazeo2uj = rtP .
vqsvds_Y0 ; rtB . eplxs5lwue = rtP . vqsvds_Y0 ; rtDW . oxl5j3231b = false ;
} } if ( rtDW . oxl5j3231b ) { rtB . ellcd02d0a = - 0.57735026918962573 *
cx35bjw00t_idx_1 ; rtB . eplxs5lwue = ( ( jqo2opizyd_idx_0 -
1.7320508075688772 * dgdmzzjogn ) * cx35bjw00t_idx_3 + 2.0 * jqo2opizyd_idx_0
* cx35bjw00t_idx_2 ) * 0.33333333333333331 ; rtB . p2yqvbxfbg = ( 2.0 *
cx35bjw00t_idx_0 + cx35bjw00t_idx_1 ) * 0.33333333333333331 ; rtB .
gnhazeo2uj = ( ( 1.7320508075688772 * jqo2opizyd_idx_0 + dgdmzzjogn ) *
cx35bjw00t_idx_3 + 2.0 * dgdmzzjogn * cx35bjw00t_idx_2 ) *
0.33333333333333331 ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC (
rtDW . icsha3sasz ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) &&
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtP . Constant1_Value_faydk34tyo ) {
if ( ! rtDW . mnzaoheyk3 ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart (
rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW .
mnzaoheyk3 = true ; } } else if ( rtDW . mnzaoheyk3 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . bh3kicabjx = rtP .
vqrvdr_Y0_pi4orirh4m ; rtB . dreas41q31 = rtP . vqrvdr_Y0_pi4orirh4m ; rtB .
gd120fhzkj = rtP . vqsvds_Y0_lyow20grr3 ; rtB . jdn3shvlxc = rtP .
vqsvds_Y0_lyow20grr3 ; rtDW . mnzaoheyk3 = false ; } } if ( rtDW . mnzaoheyk3
) { rtB . dreas41q31 = ( ( - jqo2opizyd_idx_0 - 1.7320508075688772 *
dgdmzzjogn ) * cx35bjw00t_idx_1 + - 2.0 * jqo2opizyd_idx_0 * cx35bjw00t_idx_0
) * 0.33333333333333331 ; rtB . jdn3shvlxc = - 0.57735026918962573 *
cx35bjw00t_idx_3 ; rtB . bh3kicabjx = ( ( dgdmzzjogn - 1.7320508075688772 *
jqo2opizyd_idx_0 ) * cx35bjw00t_idx_1 + 2.0 * dgdmzzjogn * cx35bjw00t_idx_0 )
* 0.33333333333333331 ; rtB . gd120fhzkj = ( 2.0 * cx35bjw00t_idx_2 +
cx35bjw00t_idx_3 ) * 0.33333333333333331 ; if ( ssIsModeUpdateTimeStep ( rtS
) ) { srUpdateBC ( rtDW . pjxukapuyo ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0
) && ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtP . Constant2_Value_k5k5bfeqo3
) { if ( ! rtDW . pmmn32whzd ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} rtDW . pmmn32whzd = true ; } } else if ( rtDW . pmmn32whzd ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . g4hfa4uke0 = rtP .
vqrvdr_Y0_jimj400mu5 ; rtB . euxnpqq3bj = rtP . vqrvdr_Y0_jimj400mu5 ; rtB .
mqv5agdv5x = rtP . vqsvds_Y0_pwfnlr1s2b ; rtB . pfwp1k1o3k = rtP .
vqsvds_Y0_pwfnlr1s2b ; rtDW . pmmn32whzd = false ; } } if ( rtDW . pmmn32whzd
) { rtB . euxnpqq3bj = ( ( jqo2opizyd_idx_0 - 1.7320508075688772 * dgdmzzjogn
) * cx35bjw00t_idx_1 + 2.0 * jqo2opizyd_idx_0 * cx35bjw00t_idx_0 ) / 3.0 ;
rtB . pfwp1k1o3k = ( ( tmp - 1.7320508075688772 * tmp_p ) * cx35bjw00t_idx_3
+ 2.0 * tmp * cx35bjw00t_idx_2 ) / 3.0 ; rtB . g4hfa4uke0 = ( (
1.7320508075688772 * jqo2opizyd_idx_0 + dgdmzzjogn ) * cx35bjw00t_idx_1 + 2.0
* dgdmzzjogn * cx35bjw00t_idx_0 ) / 3.0 ; rtB . mqv5agdv5x = ( (
1.7320508075688772 * tmp + tmp_p ) * cx35bjw00t_idx_3 + 2.0 * tmp_p *
cx35bjw00t_idx_2 ) / 3.0 ; if ( ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC
( rtDW . ht1xjimgz4 ) ; } } switch ( ( int32_T ) rtP .
Constant3_Value_arz4qri3yc ) { case 1 : jqo2opizyd_idx_0 = rtB . p2yqvbxfbg ;
dgdmzzjogn = rtB . ellcd02d0a ; break ; case 2 : jqo2opizyd_idx_0 = rtB .
bh3kicabjx ; dgdmzzjogn = rtB . dreas41q31 ; break ; default :
jqo2opizyd_idx_0 = rtB . g4hfa4uke0 ; dgdmzzjogn = rtB . euxnpqq3bj ; break ;
} switch ( ( int32_T ) rtP . Constant4_Value_imbo4fbnsv ) { case 1 : tmp =
rtB . gnhazeo2uj ; tmp_p = rtB . eplxs5lwue ; break ; case 2 : tmp = rtB .
gd120fhzkj ; tmp_p = rtB . jdn3shvlxc ; break ; default : tmp = rtB .
mqv5agdv5x ; tmp_p = rtB . pfwp1k1o3k ; break ; } rtB . et02ll3jko [ 2 ] = (
( 0.0 - nezq2aumsv_idx_0 ) - nezq2aumsv_idx_1 ) * rtP . unitconversion_Gain [
2 ] ; rtB . et02ll3jko [ 11 ] = ( ( 0.0 - dl332u4kll_idx_0 ) -
dl332u4kll_idx_1 ) * rtP . unitconversion_Gain [ 11 ] ; rtB . et02ll3jko [ 0
] = rtP . unitconversion_Gain [ 0 ] * nezq2aumsv_idx_0 ; rtB . et02ll3jko [ 3
] = fhlb2qstqs [ 2 ] * rtP . unitconversion_Gain [ 3 ] ; rtB . et02ll3jko [ 5
] = rtP . unitconversion_Gain [ 5 ] * bkadzvdrv5_idx_2 ; rtB . et02ll3jko [ 7
] = rtP . unitconversion_Gain [ 7 ] * jqo2opizyd_idx_0 ; rtB . et02ll3jko [ 9
] = rtP . unitconversion_Gain [ 9 ] * dl332u4kll_idx_0 ; rtB . et02ll3jko [
12 ] = fhlb2qstqs [ 0 ] * rtP . unitconversion_Gain [ 12 ] ; rtB . et02ll3jko
[ 14 ] = rtP . unitconversion_Gain [ 14 ] * bkadzvdrv5_idx_0 ; rtB .
et02ll3jko [ 16 ] = rtP . unitconversion_Gain [ 16 ] * tmp ; rtB . et02ll3jko
[ 1 ] = rtP . unitconversion_Gain [ 1 ] * nezq2aumsv_idx_1 ; rtB . et02ll3jko
[ 4 ] = fhlb2qstqs [ 3 ] * rtP . unitconversion_Gain [ 4 ] ; rtB . et02ll3jko
[ 6 ] = rtP . unitconversion_Gain [ 6 ] * bkadzvdrv5_idx_3 ; rtB . et02ll3jko
[ 8 ] = rtP . unitconversion_Gain [ 8 ] * dgdmzzjogn ; rtB . et02ll3jko [ 10
] = rtP . unitconversion_Gain [ 10 ] * dl332u4kll_idx_1 ; rtB . et02ll3jko [
13 ] = fhlb2qstqs [ 1 ] * rtP . unitconversion_Gain [ 13 ] ; rtB . et02ll3jko
[ 15 ] = rtP . unitconversion_Gain [ 15 ] * bkadzvdrv5_idx_1 ; rtB .
et02ll3jko [ 17 ] = rtP . unitconversion_Gain [ 17 ] * tmp_p ; if ( rtP .
Constant5_Value >= rtP . Switch2_Threshold ) { nezq2aumsv_idx_0 = rtB .
n0dnv4pnlf ; } else { nezq2aumsv_idx_0 = rtP . Lm_nosat_Value ; } rtB .
et02ll3jko [ 18 ] = rtP . unitconversion_Gain [ 18 ] * nezq2aumsv_idx_0 ; rtY
. npec32cc2u [ 0 ] = rtB . et02ll3jko [ 9 ] ; rtY . npec32cc2u [ 1 ] = rtB .
et02ll3jko [ 10 ] ; rtY . npec32cc2u [ 2 ] = rtB . et02ll3jko [ 11 ] ;
nezq2aumsv_idx_1 = rtP . u1_Gain [ 0 ] * fhlb2qstqs [ 0 ] * bkadzvdrv5_idx_1
+ rtP . u1_Gain [ 1 ] * fhlb2qstqs [ 1 ] * bkadzvdrv5_idx_0 ; rtB .
f2b5yhh4sl [ 0 ] = rtP . Gain_Gain [ 0 ] * jajzcpktoa ; rtB . f2b5yhh4sl [ 1
] = rtP . Gain_Gain [ 1 ] * nezq2aumsv_idx_1 ; rtB . f2b5yhh4sl [ 2 ] = rtP .
up_Gain * fil2tnzl4q * rtP . Gain_Gain [ 2 ] ; rtY . g3gy4f2qnt = rtB .
f2b5yhh4sl [ 0 ] ; rtY . iirxjsi1ck = rtB . f2b5yhh4sl [ 1 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . p0snjr0rm4 = ( ssGetTaskTime ( rtS ,
1 ) >= rtP . Step_Time ) ; if ( rtDW . p0snjr0rm4 == 1 ) { e1mfc3nbgg = rtP .
Step_YFinal ; } else { e1mfc3nbgg = rtP . Step_Y0 ; } rtY . ff3fiqzzpo =
e1mfc3nbgg ; rtDW . mnlqovtpug = ( ssGetTaskTime ( rtS , 1 ) >= rtP .
SpeedReference1_Time ) ; if ( rtDW . mnlqovtpug == 1 ) { rtB . lma3pjjclw =
rtP . SpeedReference1_YFinal ; } else { rtB . lma3pjjclw = rtP .
SpeedReference1_Y0 ; } rtY . eim4mc5rzx = rtB . lma3pjjclw ; }
nezq2aumsv_idx_0 = muDoubleScalarFloor ( ( rtX . ow5vjxae2l + rtP .
Constant6_Value_knfpzjs1ar [ 0 ] ) * 65536.0 ) ; if ( muDoubleScalarIsNaN (
nezq2aumsv_idx_0 ) || muDoubleScalarIsInf ( nezq2aumsv_idx_0 ) ) {
nezq2aumsv_idx_0 = 0.0 ; } else { nezq2aumsv_idx_0 = muDoubleScalarRem (
nezq2aumsv_idx_0 , 65536.0 ) ; } if ( nezq2aumsv_idx_0 < 0.0 ) { ol2nnbdqnc_p
= ( uint16_T ) - ( int16_T ) ( uint16_T ) - nezq2aumsv_idx_0 ; } else {
ol2nnbdqnc_p = ( uint16_T ) nezq2aumsv_idx_0 ; } jgiay0altu_p = (
ol2nnbdqnc_p <= rtP . Point50_Value ) ; jgiay0altu_idx_0 = jgiay0altu_p ; if
( ! jgiay0altu_p ) { ol2nnbdqnc_p -= rtP . Point50_Value ; } if (
ol2nnbdqnc_p > rtP . Point25_Value ) { ol2nnbdqnc_p = ( uint16_T ) ( rtP .
Point50_Value - ol2nnbdqnc_p ) ; } ol2nnbdqnc_idx_0 = ol2nnbdqnc_p ;
nezq2aumsv_idx_0 = muDoubleScalarFloor ( ( rtX . ow5vjxae2l + rtP .
Constant6_Value_knfpzjs1ar [ 1 ] ) * 65536.0 ) ; if ( muDoubleScalarIsNaN (
nezq2aumsv_idx_0 ) || muDoubleScalarIsInf ( nezq2aumsv_idx_0 ) ) {
nezq2aumsv_idx_0 = 0.0 ; } else { nezq2aumsv_idx_0 = muDoubleScalarRem (
nezq2aumsv_idx_0 , 65536.0 ) ; } if ( nezq2aumsv_idx_0 < 0.0 ) { ol2nnbdqnc_p
= ( uint16_T ) - ( int16_T ) ( uint16_T ) - nezq2aumsv_idx_0 ; } else {
ol2nnbdqnc_p = ( uint16_T ) nezq2aumsv_idx_0 ; } jgiay0altu_p = (
ol2nnbdqnc_p <= rtP . Point50_Value ) ; jgiay0altu_idx_1 = jgiay0altu_p ; if
( ! jgiay0altu_p ) { ol2nnbdqnc_p -= rtP . Point50_Value ; } if (
ol2nnbdqnc_p > rtP . Point25_Value ) { ol2nnbdqnc_p = ( uint16_T ) ( rtP .
Point50_Value - ol2nnbdqnc_p ) ; } ol2nnbdqnc_idx_1 = ol2nnbdqnc_p ;
nezq2aumsv_idx_0 = muDoubleScalarFloor ( ( rtX . ow5vjxae2l + rtP .
Constant6_Value_knfpzjs1ar [ 2 ] ) * 65536.0 ) ; if ( muDoubleScalarIsNaN (
nezq2aumsv_idx_0 ) || muDoubleScalarIsInf ( nezq2aumsv_idx_0 ) ) {
nezq2aumsv_idx_0 = 0.0 ; } else { nezq2aumsv_idx_0 = muDoubleScalarRem (
nezq2aumsv_idx_0 , 65536.0 ) ; } if ( nezq2aumsv_idx_0 < 0.0 ) { ol2nnbdqnc_p
= ( uint16_T ) - ( int16_T ) ( uint16_T ) - nezq2aumsv_idx_0 ; } else {
ol2nnbdqnc_p = ( uint16_T ) nezq2aumsv_idx_0 ; } jgiay0altu_p = (
ol2nnbdqnc_p <= rtP . Point50_Value ) ; if ( ! jgiay0altu_p ) { ol2nnbdqnc_p
-= rtP . Point50_Value ; } if ( ol2nnbdqnc_p > rtP . Point25_Value ) {
ol2nnbdqnc_p = ( uint16_T ) ( rtP . Point50_Value - ol2nnbdqnc_p ) ; } bpIdx
= plook_u32u16u32n16_evenc_f ( ol2nnbdqnc_idx_0 , rtP . LookUpTable_bp01Data
[ 0 ] , ( uint16_T ) ( rtP . LookUpTable_bp01Data [ 1 ] - rtP .
LookUpTable_bp01Data [ 0 ] ) , 32U , & frac ) ; khm24hkcsa_idx_0 =
intrp1d_s16s32s32u32u32n16l_f ( bpIdx , frac , rtP . LookUpTable_tableData )
; bpIdx = plook_u32u16u32n16_evenc_f ( ol2nnbdqnc_idx_1 , rtP .
LookUpTable_bp01Data [ 0 ] , ( uint16_T ) ( rtP . LookUpTable_bp01Data [ 1 ]
- rtP . LookUpTable_bp01Data [ 0 ] ) , 32U , & frac ) ; khm24hkcsa_idx_1 =
intrp1d_s16s32s32u32u32n16l_f ( bpIdx , frac , rtP . LookUpTable_tableData )
; bpIdx = plook_u32u16u32n16_evenc_f ( ol2nnbdqnc_p , rtP .
LookUpTable_bp01Data [ 0 ] , ( uint16_T ) ( rtP . LookUpTable_bp01Data [ 1 ]
- rtP . LookUpTable_bp01Data [ 0 ] ) , 32U , & frac ) ; rtB . kyzuz0c2ou =
rtP . Gain1_Gain_jt2wimow1f * rtB . f2b5yhh4sl [ 0 ] ; rtB . mhhevg4vlf = rtB
. lma3pjjclw - rtB . kyzuz0c2ou ; rtB . p2q5eo3ncp = ( rtP . PIDController_D
* rtB . mhhevg4vlf - rtX . k1hk1sh0lu ) * rtP . PIDController_N ; rtB .
bb3bcb2evb = ( rtP . PIDController_P * rtB . mhhevg4vlf + rtX . ofid0lihsi )
+ rtB . p2q5eo3ncp ; fil2tnzl4q = rtP . Gain1_Gain_ejiryrm5j4 * rtB .
bb3bcb2evb ; if ( ! jgiay0altu_idx_0 ) { khm24hkcsa_idx_0 = ( int16_T ) -
khm24hkcsa_idx_0 ; } rtB . cnowixuruv [ 0 ] = ( real_T ) khm24hkcsa_idx_0 *
6.103515625E-5 * fil2tnzl4q ; if ( ! jgiay0altu_idx_1 ) { khm24hkcsa_idx_1 =
( int16_T ) - khm24hkcsa_idx_1 ; } rtB . cnowixuruv [ 1 ] = ( real_T )
khm24hkcsa_idx_1 * 6.103515625E-5 * fil2tnzl4q ; if ( jgiay0altu_p ) {
khm24hkcsa_idx_0 = intrp1d_s16s32s32u32u32n16l_f ( bpIdx , frac , rtP .
LookUpTable_tableData ) ; } else { khm24hkcsa_idx_0 = ( int16_T ) -
intrp1d_s16s32s32u32u32n16l_f ( bpIdx , frac , rtP . LookUpTable_tableData )
; } rtB . cnowixuruv [ 2 ] = ( real_T ) khm24hkcsa_idx_0 * 6.103515625E-5 *
fil2tnzl4q ; rtB . n0nxhg3cgb = look1_binlxpw ( muDoubleScalarRem ( ssGetT (
rtS ) , rtP . Constant_Value_mko5x2kkfl ) , rtP . LookUpTable1_bp01Data , rtP
. RepeatingSequence_rep_seq_y , 2U ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
if ( ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . g5bk25txa0 = ( rtB .
cnowixuruv [ 0 ] > rtB . n0nxhg3cgb ) ; rtDW . c2i2bx2pjh = ( rtB .
cnowixuruv [ 2 ] > rtB . n0nxhg3cgb ) ; } rtB . hl3zkut0tq = rtDW .
g5bk25txa0 ; rtB . krwau33jsm = ! rtDW . c2i2bx2pjh ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { rtDW . jq4w4rpq33 = ( rtB . cnowixuruv [ 1
] > rtB . n0nxhg3cgb ) ; } rtB . jwsiric30g = rtDW . jq4w4rpq33 ; rtB .
cl5eiuyk0x = ! rtDW . g5bk25txa0 ; rtB . dduwtifztf = rtDW . c2i2bx2pjh ; rtB
. oj010qekf1 = ! rtDW . jq4w4rpq33 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
{ if ( rtDW . ftpuxa04zl . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . ftpuxa04zl . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . f2b5yhh4sl [ 0 ] + 0 ) ; } } { if ( rtDW . hp52lf4igt .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . hp52lf4igt .
AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . f2b5yhh4sl [ 1 ] +
0 ) ; } } { if ( rtDW . lrinayj5c5 . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . lrinayj5c5 . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . et02ll3jko [ 9 ] + 0 ) ; } } { if ( rtDW . fve5j2hzkb .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . fve5j2hzkb .
AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . lma3pjjclw + 0 ) ;
} } { if ( rtDW . alxpzb4n5e . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . alxpzb4n5e . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & e1mfc3nbgg + 0 ) ; } } } switch ( ( int32_T ) rtP .
Constant4_Value_n0est4yi5w ) { case 1 : memcpy ( & o4f5cfmrf5 [ 0 ] , & rtB .
pqf1n3c5zd [ 0 ] , sizeof ( real_T ) << 4U ) ; break ; case 2 : memcpy ( &
o4f5cfmrf5 [ 0 ] , & rtB . gb4m1upgms [ 0 ] , sizeof ( real_T ) << 4U ) ;
break ; default : memcpy ( & o4f5cfmrf5 [ 0 ] , & rtB . pia0she3o4 [ 0 ] ,
sizeof ( real_T ) << 4U ) ; break ; } jgiay0altu_p = ( rtP . Constant3_Value
>= rtP . Switch1_Threshold ) ; for ( i = 0 ; i < 16 ; i ++ ) { if (
jgiay0altu_p ) { nezq2aumsv_idx_0 = rtB . nfx3ygt3dv [ i ] ; } else {
nezq2aumsv_idx_0 = rtP . Constant4_Value [ i ] ; } ocnqsuc5g5 [ i ] = ( 0.0 -
o4f5cfmrf5 [ i ] ) - nezq2aumsv_idx_0 ; } for ( i = 0 ; i <= 2 ; i += 2 ) {
tmp_g = _mm_loadu_pd ( & ocnqsuc5g5 [ i + 4 ] ) ; tmp_e = _mm_loadu_pd ( &
ocnqsuc5g5 [ i ] ) ; tmp_i = _mm_loadu_pd ( & ocnqsuc5g5 [ i + 8 ] ) ; tmp_m
= _mm_loadu_pd ( & ocnqsuc5g5 [ i + 12 ] ) ; _mm_storeu_pd ( & fhlb2qstqs [ i
] , _mm_add_pd ( _mm_add_pd ( _mm_add_pd ( _mm_mul_pd ( tmp_g , _mm_set1_pd (
bkadzvdrv5_idx_1 ) ) , _mm_mul_pd ( tmp_e , _mm_set1_pd ( bkadzvdrv5_idx_0 )
) ) , _mm_mul_pd ( tmp_i , _mm_set1_pd ( bkadzvdrv5_idx_2 ) ) ) , _mm_mul_pd
( tmp_m , _mm_set1_pd ( bkadzvdrv5_idx_3 ) ) ) ) ; } rtB . kgnko1zzwd [ 0 ] =
( tmp + fhlb2qstqs [ 0 ] ) * rtP . wbase_Gain ; rtB . kgnko1zzwd [ 2 ] = (
jqo2opizyd_idx_0 + fhlb2qstqs [ 2 ] ) * rtP . wbase_Gain ; rtB . kgnko1zzwd [
1 ] = ( tmp_p + fhlb2qstqs [ 1 ] ) * rtP . wbase_Gain ; rtB . kgnko1zzwd [ 3
] = ( dgdmzzjogn + fhlb2qstqs [ 3 ] ) * rtP . wbase_Gain ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . mmslrcwj5x = rtP . u_Tb2_Gain * e1mfc3nbgg ; } rtB
. gywezhjjbo = ( ( nezq2aumsv_idx_1 - rtB . mmslrcwj5x ) - rtP . F_Gain *
jajzcpktoa ) * rtP . u_2H_Gain ; rtB . ofe2tbnzp1 = rtP .
web_psb_Gain_kuk5g3cab0 * jajzcpktoa ; rtB . l4bi3vcc2y = rtP .
PIDController_I * rtB . mhhevg4vlf ; rtB . e0zg34sjrt = rtP .
donotdeletethisgain_Gain * rtB . o4mv0apu4p [ 2 ] ; UNUSED_PARAMETER ( tid )
; } void MdlOutputsTID2 ( int_T tid ) { if ( ssIsModeUpdateTimeStep ( rtS ) )
{ srUpdateBC ( rtDW . gkp3taud2d ) ; srUpdateBC ( rtDW . hfxle4xmpy ) ;
srUpdateBC ( rtDW . k3sfgznul3 ) ; srUpdateBC ( rtDW . czlc3ljrvw ) ; } rtB .
mvr5juzn0d = rtP . V_Amplitude ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate
( int_T tid ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnUpdate (
rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> e5c3t34yfe [ 0 ] = rtB
. kgnko1zzwd [ 0 ] ; _rtXdot -> e5c3t34yfe [ 1 ] = rtB . kgnko1zzwd [ 1 ] ;
_rtXdot -> e5c3t34yfe [ 2 ] = rtB . kgnko1zzwd [ 2 ] ; _rtXdot -> e5c3t34yfe
[ 3 ] = rtB . kgnko1zzwd [ 3 ] ; if ( rtDW . ndmq3nqsdc ) { _rtXdot ->
iaj1ubzk1n = rtB . g2cszcmclk ; } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
iaj1ubzk1n = 0.0 ; } _rtXdot -> jk5zeqvmsz = rtB . ofe2tbnzp1 ; _rtXdot ->
ejnpqfalas = rtB . gywezhjjbo ; _rtXdot -> ow5vjxae2l = rtB . bb3bcb2evb ;
_rtXdot -> ofid0lihsi = rtB . l4bi3vcc2y ; _rtXdot -> k1hk1sh0lu = rtB .
p2q5eo3ncp ; } void MdlProjection ( void ) { } void MdlZeroCrossings ( void )
{ ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ;
if ( rtDW . ndmq3nqsdc ) { _rtZCSV -> haj0e0xzld = rtB . hd4k5zuzfl ; } else
{ { ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> haj0e0xzld = 0.0 ; } }
{ SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; ssSetNonsampledZCs ( rts , &
( ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> bsk4q2qeqy [ 0 ] ) ) ;
sfcnZeroCrossings ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } _rtZCSV -> kfovdudjft = ssGetT ( rtS ) - rtP . Step_Time ; _rtZCSV
-> npdkclgzrq = ssGetT ( rtS ) - rtP . SpeedReference1_Time ; _rtZCSV ->
emf0qg3zsc = rtB . cnowixuruv [ 0 ] - rtB . n0nxhg3cgb ; _rtZCSV ->
dkdkdapcbe = rtB . cnowixuruv [ 2 ] - rtB . n0nxhg3cgb ; _rtZCSV ->
hk0gdqbton = rtB . cnowixuruv [ 1 ] - rtB . n0nxhg3cgb ; } void MdlTerminate
( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate (
rts ) ; } { if ( rtDW . ftpuxa04zl . AQHandles ) { sdiTerminateStreaming ( &
rtDW . ftpuxa04zl . AQHandles ) ; } } { if ( rtDW . hp52lf4igt . AQHandles )
{ sdiTerminateStreaming ( & rtDW . hp52lf4igt . AQHandles ) ; } } { if ( rtDW
. lrinayj5c5 . AQHandles ) { sdiTerminateStreaming ( & rtDW . lrinayj5c5 .
AQHandles ) ; } } { if ( rtDW . fve5j2hzkb . AQHandles ) {
sdiTerminateStreaming ( & rtDW . fve5j2hzkb . AQHandles ) ; } } { if ( rtDW .
alxpzb4n5e . AQHandles ) { sdiTerminateStreaming ( & rtDW . alxpzb4n5e .
AQHandles ) ; } } } static void mr_vvvf_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_vvvf_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_vvvf_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_vvvf_restoreDataFromMxArray ( void * destData , const mxArray * srcArray ,
mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_vvvf_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_vvvf_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_vvvf_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_vvvf_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_vvvf_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void
mr_vvvf_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T *
varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j )
) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T
* ) srcData , numBytes ) ; } static void
mr_vvvf_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_vvvf_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_vvvf_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_vvvf_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber
( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal )
) ; } static uint_T mr_vvvf_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_vvvf_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_vvvf_GetDWork ( ) { static const char_T * ssDWFieldNames [
3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_vvvf_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 31 ] = {
"rtDW.jnrkrxkzrl" , "rtDW.dkyzsipnzx" , "rtDW.mxsrormvrm" , "rtDW.o0yfnvsxpn"
, "rtDW.irfhlvdpe0" , "rtDW.p0snjr0rm4" , "rtDW.mnlqovtpug" ,
"rtDW.czlc3ljrvw" , "rtDW.k3sfgznul3" , "rtDW.hfxle4xmpy" , "rtDW.cymarl3f1g"
, "rtDW.ezrryhvozp" , "rtDW.otcudvwncc" , "rtDW.ht1xjimgz4" ,
"rtDW.pjxukapuyo" , "rtDW.icsha3sasz" , "rtDW.gkp3taud2d" , "rtDW.g5bk25txa0"
, "rtDW.c2i2bx2pjh" , "rtDW.jq4w4rpq33" , "rtDW.bdjs2rcjwz" ,
"rtDW.k2ymqellzk" , "rtDW.a2epbhif3c" , "rtDW.h3ttfsops4" , "rtDW.h0wbstq2sb"
, "rtDW.hgcaqe1nht" , "rtDW.dyer3jszh3" , "rtDW.pmmn32whzd" ,
"rtDW.mnzaoheyk3" , "rtDW.oxl5j3231b" , "rtDW.ndmq3nqsdc" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 31 , rtdwDataFieldNames ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW .
jnrkrxkzrl ) , sizeof ( rtDW . jnrkrxkzrl ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 1 , ( const void * ) & ( rtDW . dkyzsipnzx ) , sizeof ( rtDW .
dkyzsipnzx ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void
* ) & ( rtDW . mxsrormvrm ) , sizeof ( rtDW . mxsrormvrm ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW .
o0yfnvsxpn ) , sizeof ( rtDW . o0yfnvsxpn ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 4 , ( const void * ) & ( rtDW . irfhlvdpe0 ) , sizeof ( rtDW .
irfhlvdpe0 ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void
* ) & ( rtDW . p0snjr0rm4 ) , sizeof ( rtDW . p0snjr0rm4 ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW .
mnlqovtpug ) , sizeof ( rtDW . mnlqovtpug ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 7 , ( const void * ) & ( rtDW . czlc3ljrvw ) , sizeof ( rtDW .
czlc3ljrvw ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void
* ) & ( rtDW . k3sfgznul3 ) , sizeof ( rtDW . k3sfgznul3 ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & ( rtDW .
hfxle4xmpy ) , sizeof ( rtDW . hfxle4xmpy ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 10 , ( const void * ) & ( rtDW . cymarl3f1g ) , sizeof ( rtDW
. cymarl3f1g ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const
void * ) & ( rtDW . ezrryhvozp ) , sizeof ( rtDW . ezrryhvozp ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & ( rtDW .
otcudvwncc ) , sizeof ( rtDW . otcudvwncc ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 13 , ( const void * ) & ( rtDW . ht1xjimgz4 ) , sizeof ( rtDW
. ht1xjimgz4 ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const
void * ) & ( rtDW . pjxukapuyo ) , sizeof ( rtDW . pjxukapuyo ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & ( rtDW .
icsha3sasz ) , sizeof ( rtDW . icsha3sasz ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 16 , ( const void * ) & ( rtDW . gkp3taud2d ) , sizeof ( rtDW
. gkp3taud2d ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const
void * ) & ( rtDW . g5bk25txa0 ) , sizeof ( rtDW . g5bk25txa0 ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & ( rtDW .
c2i2bx2pjh ) , sizeof ( rtDW . c2i2bx2pjh ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 19 , ( const void * ) & ( rtDW . jq4w4rpq33 ) , sizeof ( rtDW
. jq4w4rpq33 ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const
void * ) & ( rtDW . bdjs2rcjwz ) , sizeof ( rtDW . bdjs2rcjwz ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & ( rtDW .
k2ymqellzk ) , sizeof ( rtDW . k2ymqellzk ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 22 , ( const void * ) & ( rtDW . a2epbhif3c ) , sizeof ( rtDW
. a2epbhif3c ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const
void * ) & ( rtDW . h3ttfsops4 ) , sizeof ( rtDW . h3ttfsops4 ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & ( rtDW .
h0wbstq2sb ) , sizeof ( rtDW . h0wbstq2sb ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 25 , ( const void * ) & ( rtDW . hgcaqe1nht ) , sizeof ( rtDW
. hgcaqe1nht ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const
void * ) & ( rtDW . dyer3jszh3 ) , sizeof ( rtDW . dyer3jszh3 ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & ( rtDW .
pmmn32whzd ) , sizeof ( rtDW . pmmn32whzd ) ) ; mr_vvvf_cacheDataAsMxArray (
rtdwData , 0 , 28 , ( const void * ) & ( rtDW . mnzaoheyk3 ) , sizeof ( rtDW
. mnzaoheyk3 ) ) ; mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const
void * ) & ( rtDW . oxl5j3231b ) , sizeof ( rtDW . oxl5j3231b ) ) ;
mr_vvvf_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & ( rtDW .
ndmq3nqsdc ) , sizeof ( rtDW . ndmq3nqsdc ) ) ; mxSetFieldByNumber ( ssDW , 0
, 1 , rtdwData ) ; } return ssDW ; } void mr_vvvf_SetDWork ( const mxArray *
ssDW ) { ( void ) ssDW ; mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtB
) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_vvvf_restoreDataFromMxArray ( ( void
* ) & ( rtDW . jnrkrxkzrl ) , rtdwData , 0 , 0 , sizeof ( rtDW . jnrkrxkzrl )
) ; mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . dkyzsipnzx ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . dkyzsipnzx ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . mxsrormvrm ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . mxsrormvrm ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . o0yfnvsxpn ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . o0yfnvsxpn ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . irfhlvdpe0 ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . irfhlvdpe0 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . p0snjr0rm4 ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . p0snjr0rm4 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . mnlqovtpug ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . mnlqovtpug ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . czlc3ljrvw ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . czlc3ljrvw ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . k3sfgznul3 ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . k3sfgznul3 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . hfxle4xmpy ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . hfxle4xmpy ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . cymarl3f1g ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . cymarl3f1g ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . ezrryhvozp ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . ezrryhvozp ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . otcudvwncc ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . otcudvwncc ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . ht1xjimgz4 ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . ht1xjimgz4 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . pjxukapuyo ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . pjxukapuyo ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . icsha3sasz ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . icsha3sasz ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . gkp3taud2d ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . gkp3taud2d ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . g5bk25txa0 ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . g5bk25txa0 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . c2i2bx2pjh ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . c2i2bx2pjh ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . jq4w4rpq33 ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . jq4w4rpq33 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . bdjs2rcjwz ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . bdjs2rcjwz ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . k2ymqellzk ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . k2ymqellzk ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . a2epbhif3c ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . a2epbhif3c ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . h3ttfsops4 ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . h3ttfsops4 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . h0wbstq2sb ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . h0wbstq2sb ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . hgcaqe1nht ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . hgcaqe1nht ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . dyer3jszh3 ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . dyer3jszh3 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . pmmn32whzd ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . pmmn32whzd ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . mnzaoheyk3 ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . mnzaoheyk3 ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . oxl5j3231b ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . oxl5j3231b ) ) ;
mr_vvvf_restoreDataFromMxArray ( ( void * ) & ( rtDW . ndmq3nqsdc ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . ndmq3nqsdc ) ) ; } } mxArray *
mr_vvvf_GetSimStateDisallowedBlocks ( ) { mxArray * data = mxCreateCellMatrix
( 8 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const char_T * blockType [
8 ] = { "S-Function" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "S-Function" , } ; static const char_T * blockPath [ 8 ] = {
"vvvf/powergui/EquivalentModel1/State-Space" , "vvvf/Scope" , "vvvf/Scope1" ,
"vvvf/Scope2" , "vvvf/Subsystem/Scope4" , "vvvf/Subsystem/Scope5" ,
"vvvf/Scope3" , "vvvf/powergui/EquivalentModel1/State-Space" , } ; static
const int reason [ 8 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , } ; for ( subs [ 0
] = 0 ; subs [ 0 ] < 8 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 10 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 7 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 242 ) ; ssSetNumBlockIO ( rtS , 64 ) ;
ssSetNumBlockParams ( rtS , 1341 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1547433344U ) ;
ssSetChecksumVal ( rtS , 1 , 230169129U ) ; ssSetChecksumVal ( rtS , 2 ,
1701565233U ) ; ssSetChecksumVal ( rtS , 3 , 1522444939U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( & rtY , 0 , sizeof (
ExtY ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtY ) , "YOut" ) ; } {
real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof
( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T *
) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo
) ; dtInfo . numDataTypes = 28 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [
0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable
= & rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } vvvf_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"vvvf" ) ; ssSetPath ( rtS , "vvvf" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 1.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 4 , 1
, 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 4 , 1
, 1 , 1 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ]
= { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
 "vvvf/Asynchronous Machine\nSI Units/Electrical model/Asynchronous Machine\nState-space model/phi/Integrator"
, "vvvf/Asynchronous Machine\nSI Units/Mechanical model/Rotor angle thetam" ,
"vvvf/Asynchronous Machine\nSI Units/Mechanical model/Rotor speed (wm)" ,
"vvvf/Subsystem/Integrator" ,
"vvvf/Subsystem/PID Controller/Integrator/Continuous/Integrator" ,
"vvvf/Subsystem/PID Controller/Filter/Cont. Filter/Filter" ,
 "vvvf/Asynchronous Machine\nSI Units/Electrical model/Asynchronous Machine\nState-space model/Saturation/Time Constant/Integrator"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] =
{ { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 7 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 7 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . e5c3t34yfe [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . jk5zeqvmsz ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ejnpqfalas ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . ow5vjxae2l ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . ofid0lihsi ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . k1hk1sh0lu ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . iaj1ubzk1n ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; { static void * rt_LoggedOutputSignalPtrs [ ] = { & rtY .
npec32cc2u [ 0 ] , & rtY . g3gy4f2qnt , & rtY . iirxjsi1ck , & rtY .
ff3fiqzzpo , & rtY . eim4mc5rzx } ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( ( LogSignalPtrsType ) rt_LoggedOutputSignalPtrs ) ) ; } { static
int_T rt_LoggedOutputWidths [ ] = { 3 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedOutputNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedOutputDimensions [ ] = { 3 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedOutputIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) } ; static int_T rt_LoggedCurrentSignalDimensionsSize [ ] =
{ 4 , 4 , 4 , 4 , 4 } ; static BuiltInDTypeId rt_LoggedOutputDataTypeIds [ ]
= { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static
int_T rt_LoggedOutputComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedOutputLabels_0 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_0 [ ] = { "vvvf/Out1" } ; static const char_T *
rt_LoggedOutputLabels_1 [ ] = { "<Rotor speed (wm)>" } ; static const char_T
* rt_LoggedOutputBlockNames_1 [ ] = { "vvvf/Out2" } ; static const char_T *
rt_LoggedOutputLabels_2 [ ] = { "<Electromagnetic torque Te (N*m)>" } ;
static const char_T * rt_LoggedOutputBlockNames_2 [ ] = { "vvvf/Out3" } ;
static const char_T * rt_LoggedOutputLabels_3 [ ] = { "" } ; static const
char_T * rt_LoggedOutputBlockNames_3 [ ] = { "vvvf/Out4" } ; static const
char_T * rt_LoggedOutputLabels_4 [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames_4 [ ] = { "vvvf/Out5" } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedOutputSignalInfo [ ] = { { 1 ,
rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) ,
rt_LoggingPreprocessingFcnPtrs , { rt_LoggedOutputLabels_0 } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames_0 } , { ( NULL ) } , ( NULL )
, rt_RTWLogDataTypeConvert , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 1 ,
rt_LoggedOutputNumDimensions + 1 , rt_LoggedOutputDimensions + 1 ,
rt_LoggedOutputIsVarDims + 1 , rt_LoggedCurrentSignalDimensions + 1 ,
rt_LoggedCurrentSignalDimensionsSize + 1 , rt_LoggedOutputDataTypeIds + 1 ,
rt_LoggedOutputComplexSignals + 1 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 1 , { rt_LoggedOutputLabels_1 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_1 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 1 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 2 ,
rt_LoggedOutputNumDimensions + 2 , rt_LoggedOutputDimensions + 2 ,
rt_LoggedOutputIsVarDims + 2 , rt_LoggedCurrentSignalDimensions + 2 ,
rt_LoggedCurrentSignalDimensionsSize + 2 , rt_LoggedOutputDataTypeIds + 2 ,
rt_LoggedOutputComplexSignals + 2 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 2 , { rt_LoggedOutputLabels_2 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_2 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 2 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 3 ,
rt_LoggedOutputNumDimensions + 3 , rt_LoggedOutputDimensions + 3 ,
rt_LoggedOutputIsVarDims + 3 , rt_LoggedCurrentSignalDimensions + 3 ,
rt_LoggedCurrentSignalDimensionsSize + 3 , rt_LoggedOutputDataTypeIds + 3 ,
rt_LoggedOutputComplexSignals + 3 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 3 , { rt_LoggedOutputLabels_3 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_3 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 3 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 4 ,
rt_LoggedOutputNumDimensions + 4 , rt_LoggedOutputDimensions + 4 ,
rt_LoggedOutputIsVarDims + 4 , rt_LoggedCurrentSignalDimensions + 4 ,
rt_LoggedCurrentSignalDimensionsSize + 4 , rt_LoggedOutputDataTypeIds + 4 ,
rt_LoggedOutputComplexSignals + 4 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 4 , { rt_LoggedOutputLabels_4 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_4 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 4 , ( NULL ) } } ; rtliSetLogYSignalInfo (
ssGetRTWLogInfo ( rtS ) , rt_LoggedOutputSignalInfo ) ;
rt_LoggedCurrentSignalDimensions [ 0 ] = & rt_LoggedOutputWidths [ 0 ] ;
rt_LoggedCurrentSignalDimensions [ 1 ] = & rt_LoggedOutputWidths [ 1 ] ;
rt_LoggedCurrentSignalDimensions [ 2 ] = & rt_LoggedOutputWidths [ 2 ] ;
rt_LoggedCurrentSignalDimensions [ 3 ] = & rt_LoggedOutputWidths [ 3 ] ;
rt_LoggedCurrentSignalDimensions [ 4 ] = & rt_LoggedOutputWidths [ 4 ] ; }
rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
 "tmp_raccel_yout1,tmp_raccel_yout2,tmp_raccel_yout3,tmp_raccel_yout4,tmp_raccel_yout5"
) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , &
statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 10 ] ;
static real_T absTol [ 10 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [
10 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static real_T
contStateJacPerturbBoundMinVec [ 10 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 10 ] ; static uint8_T zcAttributes [ 13 ] =
{ ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP )
, ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 8
] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . mmslrcwj5x ) , ( NULL )
} , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . oj010qekf1 ) , ( NULL ) }
, { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . dduwtifztf ) , ( NULL ) } ,
{ 1 * sizeof ( real_T ) , ( char * ) ( & rtB . cl5eiuyk0x ) , ( NULL ) } , {
1 * sizeof ( real_T ) , ( char * ) ( & rtB . jwsiric30g ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . krwau33jsm ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . hl3zkut0tq ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . lma3pjjclw ) , ( NULL ) } } ; { int
i ; for ( i = 0 ; i < 10 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0
; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol
( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0
) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 )
; ssSetMaxStepSize ( rtS , 5.0E-6 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
8 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode23" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 13 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 13 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1547433344U ) ; ssSetChecksumVal ( rtS , 1 ,
230169129U ) ; ssSetChecksumVal ( rtS , 2 , 1701565233U ) ; ssSetChecksumVal
( rtS , 3 , 1522444939U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 12 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . gkp3taud2d ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW . gkp3taud2d ;
systemRan [ 3 ] = ( sysRanDType * ) & rtDW . icsha3sasz ; systemRan [ 4 ] = (
sysRanDType * ) & rtDW . pjxukapuyo ; systemRan [ 5 ] = ( sysRanDType * ) &
rtDW . ht1xjimgz4 ; systemRan [ 6 ] = ( sysRanDType * ) & rtDW . otcudvwncc ;
systemRan [ 7 ] = ( sysRanDType * ) & rtDW . ezrryhvozp ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . cymarl3f1g ; systemRan [ 9 ] = ( sysRanDType * ) &
rtDW . hfxle4xmpy ; systemRan [ 10 ] = ( sysRanDType * ) & rtDW . k3sfgznul3
; systemRan [ 11 ] = ( sysRanDType * ) & rtDW . czlc3ljrvw ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_vvvf_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_vvvf_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_vvvf_SetDWork )
; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS )
) { return rtS ; } ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct
childSFunctions [ 1 ] ; static SimStruct * childSFunctionPtrs [ 1 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ;
static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 ,
sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 ,
sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2Sfcn ; struct
_ssBlkInfo2 * blkInfo2Sfcn = & _blkInfo2Sfcn ; ssSetBlkInfo2Ptr ( rts ,
blkInfo2Sfcn ) ; } { static struct _ssPortInfo2 _portInfo2 ; struct
_ssPortInfo2 * portInfo2 = & _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts ,
portInfo2 ) ; } ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static
struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2
) ; } { static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 (
rts , & methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 2 ) ; static struct _ssPortInputs inputPortInfo [
2 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; { static
real_T const * sfcnUPtrs [ 3 ] ; sfcnUPtrs [ 0 ] = & rtB . eypf5fvuhy [ 0 ] ;
sfcnUPtrs [ 1 ] = & rtB . eypf5fvuhy [ 1 ] ; sfcnUPtrs [ 2 ] = & rtB .
mvr5juzn0d ; ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 3 ) ; } { static real_T const *
sfcnUPtrs [ 6 ] ; sfcnUPtrs [ 0 ] = & rtB . hl3zkut0tq ; sfcnUPtrs [ 1 ] = &
rtB . krwau33jsm ; sfcnUPtrs [ 2 ] = & rtB . jwsiric30g ; sfcnUPtrs [ 3 ] = &
rtB . cl5eiuyk0x ; sfcnUPtrs [ 4 ] = & rtB . dduwtifztf ; sfcnUPtrs [ 5 ] = &
rtB . oj010qekf1 ; ssSetInputPortSignalPtrs ( rts , 1 , ( InputPtrsType ) &
sfcnUPtrs [ 0 ] ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 1 , 6 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 2 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 2 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 2 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; { static struct
_ssOutPortCoSimAttribute outputPortCoSimAttribute [ 2 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 3 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB .
o4mv0apu4p ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidthAsInt ( rts , 1 , 12 ) ; ssSetOutputPortSignal ( rts , 1
, ( ( real_T * ) rtB . ij320zmpr0 ) ) ; } } ssSetModelName ( rts ,
"State-Space" ) ; ssSetPath ( rts ,
"vvvf/powergui/EquivalentModel1/State-Space" ) ; if ( ssGetRTModel ( rtS ) ==
( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 10 ] ;
ssSetSFcnParamsCount ( rts , 10 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . StateSpace_P1_Size ) ;
ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . StateSpace_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . StateSpace_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . StateSpace_P4_Size ) ;
ssSetSFcnParam ( rts , 4 , ( mxArray * ) rtP . StateSpace_P5_Size ) ;
ssSetSFcnParam ( rts , 5 , ( mxArray * ) rtP . StateSpace_P6_Size ) ;
ssSetSFcnParam ( rts , 6 , ( mxArray * ) rtP . StateSpace_P7_Size ) ;
ssSetSFcnParam ( rts , 7 , ( mxArray * ) rtP . StateSpace_P8_Size ) ;
ssSetSFcnParam ( rts , 8 , ( mxArray * ) rtP . StateSpace_P9_Size ) ;
ssSetSFcnParam ( rts , 9 , ( mxArray * ) rtP . StateSpace_P10_Size ) ; }
ssSetRWork ( rts , ( real_T * ) & rtDW . dkyzsipnzx [ 0 ] ) ; ssSetIWork (
rts , ( int_T * ) & rtDW . o0yfnvsxpn [ 0 ] ) ; ssSetPWork ( rts , ( void * *
) & rtDW . lasptfrk2y [ 0 ] ) ; { static struct _ssDWorkRecord dWorkRecord [
4 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 4 ] ; ssSetSFcnDWork (
rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ;
ssSetNumDWorkAsInt ( rts , 4 ) ; ssSetDWorkWidthAsInt ( rts , 0 , 7 ) ;
ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts ,
0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW . irfhlvdpe0 [ 0 ] ) ;
ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ; ssSetDWorkDataType ( rts , 1 ,
SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork ( rts , 1
, & rtDW . dkyzsipnzx [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 2 , 23 ) ;
ssSetDWorkDataType ( rts , 2 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . o0yfnvsxpn [ 0 ] ) ;
ssSetDWorkWidthAsInt ( rts , 3 , 22 ) ; ssSetDWorkDataType ( rts , 3 ,
SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 3 , 0 ) ; ssSetDWork ( rts , 3
, & rtDW . lasptfrk2y [ 0 ] ) ; } ssSetModeVector ( rts , ( int_T * ) & rtDW
. irfhlvdpe0 [ 0 ] ) ; sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts )
; sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCsAsInt ( rts , 7 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetInputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected (
rts , 0 , 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 1 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ;
ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } executionInfo ->
simulationOptions_ . stateSaveName_ = rtliGetLogX ( ssGetRTWLogInfo ( rtS ) )
; executionInfo -> simulationOptions_ . finalStateName_ = rtliGetLogXFinal (
ssGetRTWLogInfo ( rtS ) ) ; executionInfo -> simulationOptions_ .
outputSaveName_ = rtliGetLogY ( ssGetRTWLogInfo ( rtS ) ) ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID2 ( tid ) ; }
