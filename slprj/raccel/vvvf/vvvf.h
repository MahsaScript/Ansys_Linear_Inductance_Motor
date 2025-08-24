#ifndef vvvf_h_
#define vvvf_h_
#ifndef vvvf_COMMON_INCLUDES_
#define vvvf_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "vvvf_types.h"
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME vvvf
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (7)     
#define NBLOCKIO (64) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (10)   
#elif NCSTATES != 10
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T eypf5fvuhy [ 2 ] ; real_T o4mv0apu4p [ 3 ] ; real_T
ij320zmpr0 [ 12 ] ; real_T et02ll3jko [ 19 ] ; real_T f2b5yhh4sl [ 3 ] ;
real_T lma3pjjclw ; real_T kyzuz0c2ou ; real_T mhhevg4vlf ; real_T p2q5eo3ncp
; real_T bb3bcb2evb ; real_T cnowixuruv [ 3 ] ; real_T n0nxhg3cgb ; real_T
hl3zkut0tq ; real_T krwau33jsm ; real_T jwsiric30g ; real_T cl5eiuyk0x ;
real_T dduwtifztf ; real_T oj010qekf1 ; real_T kgnko1zzwd [ 4 ] ; real_T
mmslrcwj5x ; real_T gywezhjjbo ; real_T ofe2tbnzp1 ; real_T l4bi3vcc2y ;
real_T e0zg34sjrt ; real_T mvr5juzn0d ; real_T fiyra3eut5 [ 4 ] ; real_T
gb4m1upgms [ 16 ] ; real_T otwdcoetlk [ 4 ] ; real_T pqf1n3c5zd [ 16 ] ;
real_T hvinyhszko ; real_T iw1cd0lav2 ; real_T f3fd2pxxgz ; real_T closv3m451
; real_T pia0she3o4 [ 16 ] ; real_T aiph1d1ozm ; real_T fxgts2qscc ; real_T
mx24leduor ; real_T kovx3slok1 ; real_T b1hqruu3lc ; real_T jrl11asq0k ;
real_T lu3zfkpimu ; real_T psnaawa4gb ; real_T pbhbu5syo3 ; real_T iby2pb1cme
; real_T cqwuo1xw0b ; real_T lgiwwylx0p ; real_T euxnpqq3bj ; real_T
pfwp1k1o3k ; real_T g4hfa4uke0 ; real_T mqv5agdv5x ; real_T dreas41q31 ;
real_T jdn3shvlxc ; real_T bh3kicabjx ; real_T gd120fhzkj ; real_T ellcd02d0a
; real_T eplxs5lwue ; real_T p2yqvbxfbg ; real_T gnhazeo2uj ; real_T
hd4k5zuzfl ; real_T n0dnv4pnlf ; real_T o4k3lywywo [ 16 ] ; real_T nfx3ygt3dv
[ 16 ] ; real_T g2cszcmclk ; real_T hkxto43bbu ; } B ; typedef struct {
real_T jnrkrxkzrl [ 16 ] ; real_T dkyzsipnzx [ 2 ] ; void * lasptfrk2y [ 22 ]
; struct { void * LoggedData ; } ltw0otqabg ; struct { void * LoggedData ; }
luvdqb0tpz ; struct { void * LoggedData ; } oztpmcot0n ; struct { void *
AQHandles ; } ftpuxa04zl ; struct { void * AQHandles ; } hp52lf4igt ; struct
{ void * AQHandles ; } lrinayj5c5 ; struct { void * AQHandles ; } fve5j2hzkb
; struct { void * AQHandles ; } alxpzb4n5e ; struct { void * LoggedData [ 2 ]
; } dohjjx5mtd ; struct { void * LoggedData ; } nzf1dvjri0 ; struct { void *
LoggedData ; } jdhi4onrbt ; uint32_T mxsrormvrm ; int_T o0yfnvsxpn [ 23 ] ;
int_T irfhlvdpe0 [ 7 ] ; int_T p0snjr0rm4 ; int_T mnlqovtpug ; int8_T
czlc3ljrvw ; int8_T k3sfgznul3 ; int8_T hfxle4xmpy ; int8_T cymarl3f1g ;
int8_T ezrryhvozp ; int8_T otcudvwncc ; int8_T ht1xjimgz4 ; int8_T pjxukapuyo
; int8_T icsha3sasz ; int8_T gkp3taud2d ; boolean_T g5bk25txa0 ; boolean_T
c2i2bx2pjh ; boolean_T jq4w4rpq33 ; boolean_T bdjs2rcjwz ; boolean_T
k2ymqellzk ; boolean_T a2epbhif3c ; boolean_T h3ttfsops4 ; boolean_T
h0wbstq2sb ; boolean_T hgcaqe1nht ; boolean_T dyer3jszh3 ; boolean_T
pmmn32whzd ; boolean_T mnzaoheyk3 ; boolean_T oxl5j3231b ; boolean_T
ndmq3nqsdc ; } DW ; typedef struct { real_T e5c3t34yfe [ 4 ] ; real_T
jk5zeqvmsz ; real_T ejnpqfalas ; real_T ow5vjxae2l ; real_T ofid0lihsi ;
real_T k1hk1sh0lu ; real_T iaj1ubzk1n ; } X ; typedef struct { real_T
e5c3t34yfe [ 4 ] ; real_T jk5zeqvmsz ; real_T ejnpqfalas ; real_T ow5vjxae2l
; real_T ofid0lihsi ; real_T k1hk1sh0lu ; real_T iaj1ubzk1n ; } XDot ;
typedef struct { boolean_T e5c3t34yfe [ 4 ] ; boolean_T jk5zeqvmsz ;
boolean_T ejnpqfalas ; boolean_T ow5vjxae2l ; boolean_T ofid0lihsi ;
boolean_T k1hk1sh0lu ; boolean_T iaj1ubzk1n ; } XDis ; typedef struct {
real_T e5c3t34yfe [ 4 ] ; real_T jk5zeqvmsz ; real_T ejnpqfalas ; real_T
ow5vjxae2l ; real_T ofid0lihsi ; real_T k1hk1sh0lu ; real_T iaj1ubzk1n ; }
CStateAbsTol ; typedef struct { real_T e5c3t34yfe [ 4 ] ; real_T jk5zeqvmsz ;
real_T ejnpqfalas ; real_T ow5vjxae2l ; real_T ofid0lihsi ; real_T k1hk1sh0lu
; real_T iaj1ubzk1n ; } CXPtMin ; typedef struct { real_T e5c3t34yfe [ 4 ] ;
real_T jk5zeqvmsz ; real_T ejnpqfalas ; real_T ow5vjxae2l ; real_T ofid0lihsi
; real_T k1hk1sh0lu ; real_T iaj1ubzk1n ; } CXPtMax ; typedef struct { real_T
bsk4q2qeqy [ 7 ] ; real_T kfovdudjft ; real_T npdkclgzrq ; real_T emf0qg3zsc
; real_T dkdkdapcbe ; real_T hk0gdqbton ; real_T haj0e0xzld ; } ZCV ; typedef
struct { real_T npec32cc2u [ 3 ] ; real_T g3gy4f2qnt ; real_T iirxjsi1ck ;
real_T ff3fiqzzpo ; real_T eim4mc5rzx ; } ExtY ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T V_Amplitude
; real_T PIDController_D ; real_T PIDController_I ; real_T
PIDController_InitialConditionForFilter ; real_T
PIDController_InitialConditionForIntegrator ; real_T PIDController_N ; real_T
PIDController_P ; real_T RepeatingSequence_rep_seq_y [ 3 ] ; real_T Linv_Y0 ;
real_T RLinv_Y0 ; real_T Lm_Y0 ; real_T Integrator_IC ; real_T
uDLookupTable_tableData [ 2 ] ; real_T uDLookupTable_bp01Data [ 2 ] ; real_T
uTT1e6s_Gain ; real_T Constant1_Value ; real_T u2_Value [ 2 ] ; real_T
u1_Value [ 16 ] ; real_T u5_Value [ 16 ] ; real_T u1_Value_ko0zivs4jv [ 2 ] ;
real_T u1_Value_d5egqcm1pc [ 16 ] ; real_T vqrvdr_Y0 ; real_T vqsvds_Y0 ;
real_T vqrvdr_Y0_pi4orirh4m ; real_T vqsvds_Y0_lyow20grr3 ; real_T
vqrvdr_Y0_jimj400mu5 ; real_T vqsvds_Y0_pwfnlr1s2b ; real_T irairb_Y0 ;
real_T isaisb_Y0 ; real_T irairb_Y0_ivyhy1p3ly ; real_T isaisb_Y0_gpqqvmdlbh
; real_T irairb_Y0_p0eabwehg2 ; real_T isaisb_Y0_bpi2zml5at ; real_T
sinbetacosbetasinthcosth_Y0 ; real_T W_Y0 ; real_T Gain2_Gain ; real_T
web_psb_Gain ; real_T u3_Value [ 16 ] ; real_T we_Value ; real_T
sinthrcosthr_Y0 ; real_T W_Y0_e3wtsdenx4 ; real_T Gain1_Gain ; real_T
Constant_Value [ 2 ] ; real_T u1_Value_kogsxs4z2y [ 16 ] ; real_T
sinthrcosthr_Y0_o3efkyf0oi ; real_T W_Y0_bl1gxt3wnj ; real_T Gain3_Gain ;
real_T Constant_Value_m5od03unxi [ 2 ] ; real_T u4_Value [ 16 ] ; real_T
Integrator_IC_ae2mgg5baa [ 4 ] ; real_T Switch_Threshold ; real_T
Rotoranglethetam_IC ; real_T Rotorspeedwm_IC ; real_T ib_Gain ; real_T
GainVr_Vs1_Gain [ 2 ] ; real_T StateSpace_P1_Size [ 2 ] ; real_T
StateSpace_P1 [ 162 ] ; real_T StateSpace_P2_Size [ 2 ] ; real_T
StateSpace_P2 [ 4 ] ; real_T StateSpace_P3_Size [ 2 ] ; real_T
StateSpace_P4_Size [ 2 ] ; real_T StateSpace_P4 [ 792 ] ; real_T
StateSpace_P5_Size [ 2 ] ; real_T StateSpace_P5 [ 12 ] ; real_T
StateSpace_P6_Size [ 2 ] ; real_T StateSpace_P6 [ 6 ] ; real_T
StateSpace_P7_Size [ 2 ] ; real_T StateSpace_P7 [ 6 ] ; real_T
StateSpace_P8_Size [ 2 ] ; real_T StateSpace_P8 [ 6 ] ; real_T
StateSpace_P9_Size [ 2 ] ; real_T StateSpace_P9 ; real_T StateSpace_P10_Size
[ 2 ] ; real_T StateSpace_P10 ; real_T GainVr_Vs_Gain [ 2 ] ; real_T
u_Vb_Gain ; real_T Switch2_Threshold ; real_T unitconversion_Gain [ 19 ] ;
real_T u1_Gain [ 2 ] ; real_T up_Gain ; real_T Gain_Gain [ 3 ] ; real_T
Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T SpeedReference1_Time
; real_T SpeedReference1_Y0 ; real_T SpeedReference1_YFinal ; real_T
Integrator_IC_i2vfa00yuw ; real_T Gain1_Gain_jt2wimow1f ; real_T
Gain1_Gain_ejiryrm5j4 ; real_T LookUpTable1_bp01Data [ 3 ] ; real_T
Switch1_Threshold ; real_T wbase_Gain ; real_T u_Tb2_Gain ; real_T F_Gain ;
real_T u_2H_Gain ; real_T web_psb_Gain_kuk5g3cab0 ; real_T
donotdeletethisgain_Gain ; real_T Constant_Value_cphior1m01 ; real_T
Constant1_Value_mra2gbpsfd ; real_T Constant2_Value [ 16 ] ; real_T
Constant3_Value ; real_T Constant4_Value [ 16 ] ; real_T Constant5_Value ;
real_T Lm_nosat_Value ; real_T Constant3_Value_arz4qri3yc ; real_T
Constant4_Value_imbo4fbnsv ; real_T Constant6_Value [ 2 ] ; real_T
Constant3_Value_g55vewersr ; real_T Constant4_Value_euqv3crn5c ; real_T
Constant2_Value_l1jbfmoris ; real_T Constant4_Value_n0est4yi5w ; real_T
Constant6_Value_knfpzjs1ar [ 3 ] ; real_T Constant_Value_mko5x2kkfl ; int16_T
LookUpTable_tableData [ 33 ] ; uint16_T LookUpTable_bp01Data [ 33 ] ;
uint16_T Point25_Value ; uint16_T Point50_Value ; boolean_T
Constant_Value_gtcefg4zzv ; boolean_T Constant1_Value_faydk34tyo ; boolean_T
Constant2_Value_k5k5bfeqo3 ; boolean_T Constant_Value_kly1hwzxtv ; boolean_T
Constant1_Value_odujgzr1je ; boolean_T Constant2_Value_aig4mgmkah ; boolean_T
Constant_Value_oc5ovlg3x4 ; boolean_T Constant1_Value_n30gxh2450 ; boolean_T
Constant3_Value_kyknctkiab ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtY rtY ; extern P rtP ; extern mxArray * mr_vvvf_GetDWork ( ) ;
extern void mr_vvvf_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_vvvf_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * vvvf_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
