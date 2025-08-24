    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 4;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 114;
            section.data(114)  = dumData; %prealloc

                    ;% rtP.V_Amplitude
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.PIDController_D
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.PIDController_I
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.PIDController_InitialConditionForFilter
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.PIDController_InitialConditionForIntegrator
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.PIDController_N
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.PIDController_P
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.RepeatingSequence_rep_seq_y
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Linv_Y0
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 10;

                    ;% rtP.RLinv_Y0
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 11;

                    ;% rtP.Lm_Y0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 12;

                    ;% rtP.Integrator_IC
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 13;

                    ;% rtP.uDLookupTable_tableData
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% rtP.uDLookupTable_bp01Data
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 16;

                    ;% rtP.uTT1e6s_Gain
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 18;

                    ;% rtP.Constant1_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 19;

                    ;% rtP.u2_Value
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 20;

                    ;% rtP.u1_Value
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 22;

                    ;% rtP.u5_Value
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 38;

                    ;% rtP.u1_Value_ko0zivs4jv
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 54;

                    ;% rtP.u1_Value_d5egqcm1pc
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 56;

                    ;% rtP.vqrvdr_Y0
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 72;

                    ;% rtP.vqsvds_Y0
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 73;

                    ;% rtP.vqrvdr_Y0_pi4orirh4m
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 74;

                    ;% rtP.vqsvds_Y0_lyow20grr3
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 75;

                    ;% rtP.vqrvdr_Y0_jimj400mu5
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 76;

                    ;% rtP.vqsvds_Y0_pwfnlr1s2b
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 77;

                    ;% rtP.irairb_Y0
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 78;

                    ;% rtP.isaisb_Y0
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 79;

                    ;% rtP.irairb_Y0_ivyhy1p3ly
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 80;

                    ;% rtP.isaisb_Y0_gpqqvmdlbh
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 81;

                    ;% rtP.irairb_Y0_p0eabwehg2
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 82;

                    ;% rtP.isaisb_Y0_bpi2zml5at
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 83;

                    ;% rtP.sinbetacosbetasinthcosth_Y0
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 84;

                    ;% rtP.W_Y0
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 85;

                    ;% rtP.Gain2_Gain
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 86;

                    ;% rtP.web_psb_Gain
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 87;

                    ;% rtP.u3_Value
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 88;

                    ;% rtP.we_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 104;

                    ;% rtP.sinthrcosthr_Y0
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 105;

                    ;% rtP.W_Y0_e3wtsdenx4
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 106;

                    ;% rtP.Gain1_Gain
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 107;

                    ;% rtP.Constant_Value
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 108;

                    ;% rtP.u1_Value_kogsxs4z2y
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 110;

                    ;% rtP.sinthrcosthr_Y0_o3efkyf0oi
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 126;

                    ;% rtP.W_Y0_bl1gxt3wnj
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 127;

                    ;% rtP.Gain3_Gain
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 128;

                    ;% rtP.Constant_Value_m5od03unxi
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 129;

                    ;% rtP.u4_Value
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 131;

                    ;% rtP.Integrator_IC_ae2mgg5baa
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 147;

                    ;% rtP.Switch_Threshold
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 151;

                    ;% rtP.Rotoranglethetam_IC
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 152;

                    ;% rtP.Rotorspeedwm_IC
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 153;

                    ;% rtP.ib_Gain
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 154;

                    ;% rtP.GainVr_Vs1_Gain
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 155;

                    ;% rtP.StateSpace_P1_Size
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 157;

                    ;% rtP.StateSpace_P1
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 159;

                    ;% rtP.StateSpace_P2_Size
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 321;

                    ;% rtP.StateSpace_P2
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 323;

                    ;% rtP.StateSpace_P3_Size
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 327;

                    ;% rtP.StateSpace_P4_Size
                    section.data(61).logicalSrcIdx = 61;
                    section.data(61).dtTransOffset = 329;

                    ;% rtP.StateSpace_P4
                    section.data(62).logicalSrcIdx = 62;
                    section.data(62).dtTransOffset = 331;

                    ;% rtP.StateSpace_P5_Size
                    section.data(63).logicalSrcIdx = 63;
                    section.data(63).dtTransOffset = 1123;

                    ;% rtP.StateSpace_P5
                    section.data(64).logicalSrcIdx = 64;
                    section.data(64).dtTransOffset = 1125;

                    ;% rtP.StateSpace_P6_Size
                    section.data(65).logicalSrcIdx = 65;
                    section.data(65).dtTransOffset = 1137;

                    ;% rtP.StateSpace_P6
                    section.data(66).logicalSrcIdx = 66;
                    section.data(66).dtTransOffset = 1139;

                    ;% rtP.StateSpace_P7_Size
                    section.data(67).logicalSrcIdx = 67;
                    section.data(67).dtTransOffset = 1145;

                    ;% rtP.StateSpace_P7
                    section.data(68).logicalSrcIdx = 68;
                    section.data(68).dtTransOffset = 1147;

                    ;% rtP.StateSpace_P8_Size
                    section.data(69).logicalSrcIdx = 69;
                    section.data(69).dtTransOffset = 1153;

                    ;% rtP.StateSpace_P8
                    section.data(70).logicalSrcIdx = 70;
                    section.data(70).dtTransOffset = 1155;

                    ;% rtP.StateSpace_P9_Size
                    section.data(71).logicalSrcIdx = 71;
                    section.data(71).dtTransOffset = 1161;

                    ;% rtP.StateSpace_P9
                    section.data(72).logicalSrcIdx = 72;
                    section.data(72).dtTransOffset = 1163;

                    ;% rtP.StateSpace_P10_Size
                    section.data(73).logicalSrcIdx = 73;
                    section.data(73).dtTransOffset = 1164;

                    ;% rtP.StateSpace_P10
                    section.data(74).logicalSrcIdx = 74;
                    section.data(74).dtTransOffset = 1166;

                    ;% rtP.GainVr_Vs_Gain
                    section.data(75).logicalSrcIdx = 75;
                    section.data(75).dtTransOffset = 1167;

                    ;% rtP.u_Vb_Gain
                    section.data(76).logicalSrcIdx = 76;
                    section.data(76).dtTransOffset = 1169;

                    ;% rtP.Switch2_Threshold
                    section.data(77).logicalSrcIdx = 77;
                    section.data(77).dtTransOffset = 1170;

                    ;% rtP.unitconversion_Gain
                    section.data(78).logicalSrcIdx = 78;
                    section.data(78).dtTransOffset = 1171;

                    ;% rtP.u1_Gain
                    section.data(79).logicalSrcIdx = 79;
                    section.data(79).dtTransOffset = 1190;

                    ;% rtP.up_Gain
                    section.data(80).logicalSrcIdx = 80;
                    section.data(80).dtTransOffset = 1192;

                    ;% rtP.Gain_Gain
                    section.data(81).logicalSrcIdx = 81;
                    section.data(81).dtTransOffset = 1193;

                    ;% rtP.Step_Time
                    section.data(82).logicalSrcIdx = 82;
                    section.data(82).dtTransOffset = 1196;

                    ;% rtP.Step_Y0
                    section.data(83).logicalSrcIdx = 83;
                    section.data(83).dtTransOffset = 1197;

                    ;% rtP.Step_YFinal
                    section.data(84).logicalSrcIdx = 84;
                    section.data(84).dtTransOffset = 1198;

                    ;% rtP.SpeedReference1_Time
                    section.data(85).logicalSrcIdx = 85;
                    section.data(85).dtTransOffset = 1199;

                    ;% rtP.SpeedReference1_Y0
                    section.data(86).logicalSrcIdx = 86;
                    section.data(86).dtTransOffset = 1200;

                    ;% rtP.SpeedReference1_YFinal
                    section.data(87).logicalSrcIdx = 87;
                    section.data(87).dtTransOffset = 1201;

                    ;% rtP.Integrator_IC_i2vfa00yuw
                    section.data(88).logicalSrcIdx = 88;
                    section.data(88).dtTransOffset = 1202;

                    ;% rtP.Gain1_Gain_jt2wimow1f
                    section.data(89).logicalSrcIdx = 89;
                    section.data(89).dtTransOffset = 1203;

                    ;% rtP.Gain1_Gain_ejiryrm5j4
                    section.data(90).logicalSrcIdx = 90;
                    section.data(90).dtTransOffset = 1204;

                    ;% rtP.LookUpTable1_bp01Data
                    section.data(91).logicalSrcIdx = 91;
                    section.data(91).dtTransOffset = 1205;

                    ;% rtP.Switch1_Threshold
                    section.data(92).logicalSrcIdx = 92;
                    section.data(92).dtTransOffset = 1208;

                    ;% rtP.wbase_Gain
                    section.data(93).logicalSrcIdx = 93;
                    section.data(93).dtTransOffset = 1209;

                    ;% rtP.u_Tb2_Gain
                    section.data(94).logicalSrcIdx = 94;
                    section.data(94).dtTransOffset = 1210;

                    ;% rtP.F_Gain
                    section.data(95).logicalSrcIdx = 95;
                    section.data(95).dtTransOffset = 1211;

                    ;% rtP.u_2H_Gain
                    section.data(96).logicalSrcIdx = 96;
                    section.data(96).dtTransOffset = 1212;

                    ;% rtP.web_psb_Gain_kuk5g3cab0
                    section.data(97).logicalSrcIdx = 97;
                    section.data(97).dtTransOffset = 1213;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(98).logicalSrcIdx = 98;
                    section.data(98).dtTransOffset = 1214;

                    ;% rtP.Constant_Value_cphior1m01
                    section.data(99).logicalSrcIdx = 99;
                    section.data(99).dtTransOffset = 1215;

                    ;% rtP.Constant1_Value_mra2gbpsfd
                    section.data(100).logicalSrcIdx = 100;
                    section.data(100).dtTransOffset = 1216;

                    ;% rtP.Constant2_Value
                    section.data(101).logicalSrcIdx = 101;
                    section.data(101).dtTransOffset = 1217;

                    ;% rtP.Constant3_Value
                    section.data(102).logicalSrcIdx = 102;
                    section.data(102).dtTransOffset = 1233;

                    ;% rtP.Constant4_Value
                    section.data(103).logicalSrcIdx = 103;
                    section.data(103).dtTransOffset = 1234;

                    ;% rtP.Constant5_Value
                    section.data(104).logicalSrcIdx = 104;
                    section.data(104).dtTransOffset = 1250;

                    ;% rtP.Lm_nosat_Value
                    section.data(105).logicalSrcIdx = 105;
                    section.data(105).dtTransOffset = 1251;

                    ;% rtP.Constant3_Value_arz4qri3yc
                    section.data(106).logicalSrcIdx = 106;
                    section.data(106).dtTransOffset = 1252;

                    ;% rtP.Constant4_Value_imbo4fbnsv
                    section.data(107).logicalSrcIdx = 107;
                    section.data(107).dtTransOffset = 1253;

                    ;% rtP.Constant6_Value
                    section.data(108).logicalSrcIdx = 108;
                    section.data(108).dtTransOffset = 1254;

                    ;% rtP.Constant3_Value_g55vewersr
                    section.data(109).logicalSrcIdx = 109;
                    section.data(109).dtTransOffset = 1256;

                    ;% rtP.Constant4_Value_euqv3crn5c
                    section.data(110).logicalSrcIdx = 110;
                    section.data(110).dtTransOffset = 1257;

                    ;% rtP.Constant2_Value_l1jbfmoris
                    section.data(111).logicalSrcIdx = 111;
                    section.data(111).dtTransOffset = 1258;

                    ;% rtP.Constant4_Value_n0est4yi5w
                    section.data(112).logicalSrcIdx = 112;
                    section.data(112).dtTransOffset = 1259;

                    ;% rtP.Constant6_Value_knfpzjs1ar
                    section.data(113).logicalSrcIdx = 113;
                    section.data(113).dtTransOffset = 1260;

                    ;% rtP.Constant_Value_mko5x2kkfl
                    section.data(114).logicalSrcIdx = 114;
                    section.data(114).dtTransOffset = 1263;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.LookUpTable_tableData
                    section.data(1).logicalSrcIdx = 115;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.LookUpTable_bp01Data
                    section.data(1).logicalSrcIdx = 116;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Point25_Value
                    section.data(2).logicalSrcIdx = 117;
                    section.data(2).dtTransOffset = 33;

                    ;% rtP.Point50_Value
                    section.data(3).logicalSrcIdx = 118;
                    section.data(3).dtTransOffset = 34;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtP.Constant_Value_gtcefg4zzv
                    section.data(1).logicalSrcIdx = 119;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant1_Value_faydk34tyo
                    section.data(2).logicalSrcIdx = 120;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant2_Value_k5k5bfeqo3
                    section.data(3).logicalSrcIdx = 121;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Constant_Value_kly1hwzxtv
                    section.data(4).logicalSrcIdx = 122;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Constant1_Value_odujgzr1je
                    section.data(5).logicalSrcIdx = 123;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Constant2_Value_aig4mgmkah
                    section.data(6).logicalSrcIdx = 124;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Constant_Value_oc5ovlg3x4
                    section.data(7).logicalSrcIdx = 125;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Constant1_Value_n30gxh2450
                    section.data(8).logicalSrcIdx = 126;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Constant3_Value_kyknctkiab
                    section.data(9).logicalSrcIdx = 127;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 64;
            section.data(64)  = dumData; %prealloc

                    ;% rtB.eypf5fvuhy
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.o4mv0apu4p
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% rtB.ij320zmpr0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% rtB.et02ll3jko
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 17;

                    ;% rtB.f2b5yhh4sl
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 36;

                    ;% rtB.lma3pjjclw
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 39;

                    ;% rtB.kyzuz0c2ou
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 40;

                    ;% rtB.mhhevg4vlf
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 41;

                    ;% rtB.p2q5eo3ncp
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 42;

                    ;% rtB.bb3bcb2evb
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 43;

                    ;% rtB.cnowixuruv
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 44;

                    ;% rtB.n0nxhg3cgb
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 47;

                    ;% rtB.hl3zkut0tq
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 48;

                    ;% rtB.krwau33jsm
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 49;

                    ;% rtB.jwsiric30g
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 50;

                    ;% rtB.cl5eiuyk0x
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 51;

                    ;% rtB.dduwtifztf
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 52;

                    ;% rtB.oj010qekf1
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 53;

                    ;% rtB.kgnko1zzwd
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 54;

                    ;% rtB.mmslrcwj5x
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 58;

                    ;% rtB.gywezhjjbo
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 59;

                    ;% rtB.ofe2tbnzp1
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 60;

                    ;% rtB.l4bi3vcc2y
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 61;

                    ;% rtB.e0zg34sjrt
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 62;

                    ;% rtB.mvr5juzn0d
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 63;

                    ;% rtB.fiyra3eut5
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 64;

                    ;% rtB.gb4m1upgms
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 68;

                    ;% rtB.otwdcoetlk
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 84;

                    ;% rtB.pqf1n3c5zd
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 88;

                    ;% rtB.hvinyhszko
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 104;

                    ;% rtB.iw1cd0lav2
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 105;

                    ;% rtB.f3fd2pxxgz
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 106;

                    ;% rtB.closv3m451
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 107;

                    ;% rtB.pia0she3o4
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 108;

                    ;% rtB.aiph1d1ozm
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 124;

                    ;% rtB.fxgts2qscc
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 125;

                    ;% rtB.mx24leduor
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 126;

                    ;% rtB.kovx3slok1
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 127;

                    ;% rtB.b1hqruu3lc
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 128;

                    ;% rtB.jrl11asq0k
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 129;

                    ;% rtB.lu3zfkpimu
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 130;

                    ;% rtB.psnaawa4gb
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 131;

                    ;% rtB.pbhbu5syo3
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 132;

                    ;% rtB.iby2pb1cme
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 133;

                    ;% rtB.cqwuo1xw0b
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 134;

                    ;% rtB.lgiwwylx0p
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 135;

                    ;% rtB.euxnpqq3bj
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 136;

                    ;% rtB.pfwp1k1o3k
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 137;

                    ;% rtB.g4hfa4uke0
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 138;

                    ;% rtB.mqv5agdv5x
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 139;

                    ;% rtB.dreas41q31
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 140;

                    ;% rtB.jdn3shvlxc
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 141;

                    ;% rtB.bh3kicabjx
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 142;

                    ;% rtB.gd120fhzkj
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 143;

                    ;% rtB.ellcd02d0a
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 144;

                    ;% rtB.eplxs5lwue
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 145;

                    ;% rtB.p2yqvbxfbg
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 146;

                    ;% rtB.gnhazeo2uj
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 147;

                    ;% rtB.hd4k5zuzfl
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 148;

                    ;% rtB.n0dnv4pnlf
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 149;

                    ;% rtB.o4k3lywywo
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 150;

                    ;% rtB.nfx3ygt3dv
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 166;

                    ;% rtB.g2cszcmclk
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 182;

                    ;% rtB.hkxto43bbu
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 183;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.jnrkrxkzrl
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dkyzsipnzx
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 16;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtDW.lasptfrk2y
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ltw0otqabg.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 22;

                    ;% rtDW.luvdqb0tpz.LoggedData
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 23;

                    ;% rtDW.oztpmcot0n.LoggedData
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 24;

                    ;% rtDW.ftpuxa04zl.AQHandles
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 25;

                    ;% rtDW.hp52lf4igt.AQHandles
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 26;

                    ;% rtDW.lrinayj5c5.AQHandles
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 27;

                    ;% rtDW.fve5j2hzkb.AQHandles
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 28;

                    ;% rtDW.alxpzb4n5e.AQHandles
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 29;

                    ;% rtDW.dohjjx5mtd.LoggedData
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 30;

                    ;% rtDW.nzf1dvjri0.LoggedData
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 32;

                    ;% rtDW.jdhi4onrbt.LoggedData
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 33;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.mxsrormvrm
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.o0yfnvsxpn
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.irfhlvdpe0
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 23;

                    ;% rtDW.p0snjr0rm4
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 30;

                    ;% rtDW.mnlqovtpug
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 31;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% rtDW.czlc3ljrvw
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.k3sfgznul3
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.hfxle4xmpy
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.cymarl3f1g
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.ezrryhvozp
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.otcudvwncc
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ht1xjimgz4
                    section.data(7).logicalSrcIdx = 25;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.pjxukapuyo
                    section.data(8).logicalSrcIdx = 26;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.icsha3sasz
                    section.data(9).logicalSrcIdx = 27;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.gkp3taud2d
                    section.data(10).logicalSrcIdx = 28;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 14;
            section.data(14)  = dumData; %prealloc

                    ;% rtDW.g5bk25txa0
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.c2i2bx2pjh
                    section.data(2).logicalSrcIdx = 30;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.jq4w4rpq33
                    section.data(3).logicalSrcIdx = 31;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.bdjs2rcjwz
                    section.data(4).logicalSrcIdx = 32;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.k2ymqellzk
                    section.data(5).logicalSrcIdx = 33;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.a2epbhif3c
                    section.data(6).logicalSrcIdx = 34;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.h3ttfsops4
                    section.data(7).logicalSrcIdx = 35;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.h0wbstq2sb
                    section.data(8).logicalSrcIdx = 36;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.hgcaqe1nht
                    section.data(9).logicalSrcIdx = 37;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.dyer3jszh3
                    section.data(10).logicalSrcIdx = 38;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.pmmn32whzd
                    section.data(11).logicalSrcIdx = 39;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.mnzaoheyk3
                    section.data(12).logicalSrcIdx = 40;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.oxl5j3231b
                    section.data(13).logicalSrcIdx = 41;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.ndmq3nqsdc
                    section.data(14).logicalSrcIdx = 42;
                    section.data(14).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1547433344;
    targMap.checksum1 = 230169129;
    targMap.checksum2 = 1701565233;
    targMap.checksum3 = 1522444939;

