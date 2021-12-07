// KMKYL000VM_CCT2.cpp: implementation of the CKMKYL000VM_CCT2 class.
//
//////////////////////////////////////////////////////////////////////

//version 2

#include "stdafx.h"
#include "pindefine.h"
#include "KMKYL000VM_CCT2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CKMKYL000VM_CCT2::CKMKYL000VM_CCT2()
{
        SET_NAME("KMKYL000VM_CCT2");
        SET_VER("1.0.0");
}

CKMKYL000VM_CCT2::~CKMKYL000VM_CCT2()
{
}

BOOL CKMKYL000VM_CCT2::OnRunTimeWarnning(int warnCode)
{
        return FALSE;
}

BOOL CKMKYL000VM_CCT2::ProgramInitRun()
{
        ManualRun();
        SystemInit();

        RESET_TESTER();
        SET_LOGMODE( FAIL_MODE );
        SET_MUX( A_MUX, MUX_16_16 );
        SET_EXP( 0x33, 0x0 );
        SET_SIG_MODE( SIG_REG );
        SET_SIG_SIZE( SIG_REG_128 );
        SET_MAX_CHIP( CHIPGRP, 2 );
        SEND_MPAT("patternd");
        return TRUE;
}

BOOL CKMKYL000VM_CCT2::ManualRun()
{
        TEST("PKGMAP", PKGMAP);
        TEST("OPEN_162F", OPEN_162F);
        TEST("LEAK_H", LEAK_H);
        TEST("LEAK_L", LEAK_L);
        TEST("STBY_VDD1_D", STBY_VDD1_D);
        TEST("STBY_VDD2_D", STBY_VDD2_D);
        TEST("STBY_VDDCA_D", STBY_VDDCA_D);
        TEST("STBY_VDDQ_D", STBY_VDDQ_D);
        TEST("STBY_VDD1", STBY_VDD1);
        TEST("STBY_VDD2", STBY_VDD2);
        TEST("STBY_VDDCA", STBY_VDDCA);
        TEST("STBY_VDDQ", STBY_VDDQ);
        TEST("STBY_VREFCA", STBY_VREFCA);
        TEST("STBY_VREFDQ", STBY_VREFDQ);
        TEST("VOH0L", VOH0L);
        TEST("VOH0U", VOH0U);
        TEST("VOH1L", VOH1L);
        TEST("VOH1U", VOH1U);
        TEST("VOL0L", VOL0L);
        TEST("VOL0U", VOL0U);
        TEST("VOL1L", VOL1L);
        TEST("VOL1U", VOL1U);
        TEST("GF", GF);

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::AutoRun()
{

        SET_BIN(6, 10);
        STBY_VREFCA();

        SET_BIN(6, 11);
        STBY_VREFDQ();

        //SET_BIN(3, 0);
        //VOH0U();
        
        SET_BIN(8, 22, BIN_MONITOR);
        VOH0L();
return TRUE;


        SET_BIN(8, 4);
        VOH1L();

        SET_BIN(8, 5);
        VOH1U();

        SET_BIN(8, 6);
        VOL0L();

        SET_BIN(8, 7);
        VOL0U();

        SET_BIN(8, 8);
        VOL1L();

        SET_BIN(8, 9);
        VOL1U();

        SET_BIN(8, 10);
        GF();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::DISPLAY(LPSTR strItem)
{
        return CDeviceProgram::DISPLAY( strItem );
}

BOOL CKMKYL000VM_CCT2::PKGMAP()
{
        TEST("PKGMAP", PKGMAP);
        WRITE("PKGMAP");
        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_EXP( 0xF, 0x0 );
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS5, 1.2 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS6, 1.5 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 );
                
        SET_POW( VIH1, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        //<MODE_USER>
WRITE("PKGMAP1");
        //<OPT mpg_sig>
                int                iCount, iDut, iBit, iChip, iReportBit = 80;
                int                iRepeat = 20, iTestBit = 4, iIndex = 0, iChipMax=2;
                int                iMeasBit1[4] = {0,1,2,3}, iMeasBit2[4] = {2,3,4,5};
                int                iHex[16], iHex0=0, iHex3=3;
//                int                iData2[MAX_DUT];
                                unsigned __int64 ui64Data1 = 0;
                                unsigned int data1 = 0, data2 = 0;
                BOOL        bResult[MAX_DUT][2][80];
                int                iReportPin[64] = { 
                                                        35,39,75,79,42,46,50,54,58,62,66,70, 2, 6,10,14,
                                                        18,22,26,30,34,38,74,78,41,45,49,53,57,61,65,69,
                                                         1, 5, 9,13,17,21,25,29,33,37,73,77,40,44,48,52,
                                                        56,60,64,68, 0, 4, 8,12,16,20,24,28,32,36,72,76};
                int                moviSig[32] = {
                                                        0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 
                                                        0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0};
                SET_SIG_MODE( SIG_REG );
                SET_EXP(0xf, 0x0);

  //                              SEND_MPAT("patternd");
  WRITE("PKGMAP2");
                START_MPAT("SIGN");
                unsigned int uiReadData= 0;
        for( iChip = 0; iChip < iChipMax; iChip++) {
                for( iCount = 0; iCount < iRepeat; iCount++ ) 
                { // Get IO Data
                WRITE("PKGMAP2.5");
                        WAIT_MPAT();
                        
                        if ( m_bStop ) {      break;}
                        for( iDut = 0; iDut < MAX_DUT; iDut++ ) {
                                if ( m_bTestDut[iDut] ) {
                                                
                                                ui64Data1 = READ_LATCH1(iDut);
                                        //iData1[iDut] = ReadDriver( iDut, CMP_FAIL_LATCH1_ADDR );
//                                        iData2[iDut] = ReadDriver( iDut, CMP_FAIL_LATCH2_ADDR );
                                        for( iBit = 0; iBit < iTestBit; iBit++ ) {
                                                iIndex = iCount*iTestBit + iBit;
//                                                if (iChip==0) {
                                                                                                                 
                                                                                                                bResult[iDut][iChip][iIndex] = ((ui64Data1 >> iMeasBit1[iBit]) & 0x01) ? 0 : 1;
                                                     // bResult[iDut][iChip][iIndex] = ((iData1[iDut] >> iMeasBit1[iBit]) & 0x01) ? 0 : 1;
//                                                }
//                                                if (iChip==1) {
//                                                        bResult[iDut][iChip][iIndex] = ((iData2[iDut] >> iMeasBit2[iBit]) & 0x01) ? 0 : 1;
//                                                }
                                        }
                                       // WriteDriver( iDut, CMP_FAIL_CONTROL_ADDR, 0x0000 );// V Clear
                                }
                        }
                             FAIL_CLEAR();
                             READ_EXT(ADDR_XMIN,&uiReadData);
                  
                        CONTINUE_MPAT();
                        WRITE("PKGMAP3");
                        
                }
                READ_EXT(SEQ_PC_GET,&uiReadData);READ_EXT(SEQ_PC_GET,&uiReadData); 
                if(iChip==0) {
                        SET_EXP(0xf, 0x0);
                        WAIT(1000);
                }
        }                
        for ( iDut=0; iDut<MAX_DUT; iDut++) { // Re-arrange to Signature Data
                if ( !m_bTestDut[iDut] ) continue;
                for( iChip = 0; iChip < iChipMax; iChip++) {
                        for ( iCount=0; iCount< iRepeat-4; iCount++ ) {
                                iHex[iCount] = 0x00;
                                for ( iBit=0; iBit<iTestBit; iBit++) {
                                        iIndex = iReportPin[(iCount * iTestBit)+iBit];
                                        iHex[iCount] |= bResult[iDut][iChip][iIndex] << (iTestBit-iBit-1);
                                }
								//m_SigBody[iDut].m_dChipSig[iChip*2+0][iCount] = static_cast<double>(moviSig[iCount]);
                                //m_SigBody[iDut].m_dChipSig[iChip*2+0][iCount+16] = static_cast<double>(moviSig[iCount+16]);
                                m_SigBody[iDut].m_dChipSig[iChip][iCount] = static_cast<double>(iHex0);
                                m_SigBody[iDut].m_dChipSig[iChip][iCount+16] = static_cast<double>(iHex[iCount]);
                                
                                //m_SigBody[iDut].m_dChipSig[iChip*2+3][iCount] = static_cast<double>(moviSig[iCount]);
                                //m_SigBody[iDut].m_dChipSig[iChip*2+3][iCount+16] = static_cast<double>(moviSig[iCount+16]);
                                //m_SigBody[iDut].m_dChipSig[iChip*2+4][iCount] = static_cast<double>(iHex0);
                                //m_SigBody[iDut].m_dChipSig[iChip*2+4][iCount+16] = static_cast<double>(iHex[iCount]);
                        }
                        if ( !m_bManual ) continue;
                        WRITE("[Dut = %d] %X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X",
                         iDut+1,
                         iHex[0], iHex[1], iHex[2], iHex[3], iHex[4],  iHex[5], iHex[6], iHex[7],
                         iHex[8], iHex[9], iHex[10], iHex[11], iHex[12], iHex[13], iHex[14], iHex[15]);
                }
        }
        //<END_OPT>
WRITE("PKGMAP4");
        SYS_INIT();
WRITE("PKGMAP5");
        return TRUE;
}

BOOL CKMKYL000VM_CCT2::OPEN_162F()
{
        TEST("OPEN_162F", OPEN_162F);

/*        SET_PPS_REG( PPS1, 1.95 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1, FALSE);
        SET_PPS_REG( PPS2, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1, FALSE);
        SET_PPS_REG( PPS5, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1, FALSE);
        SET_PPS_REG( PPS6, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1, FALSE);
        
*/

        SET_PPS_REG( PPS1, 0.0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
//        SET_PPS_REG( PPS2, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS5, 0.0 V, R_250UA, 250 UA, 0 UA, 250 UA, 2 );
        SET_PPS_REG( PPS6, 0.0 V, R_250UA, 250 UA, 0 UA, 250 UA, 3  );


                SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 );
      
        ISVM( -100 UA, R_200UA, PMU1, PINALL, sizeof(PINALL)/sizeof(int) );
//                ISVM( 100 UA, R_200UA, PMU1, PINA, sizeof(PINA)/sizeof(int) );

        LIMIT( -2.0 V, -0.15 V ); // -0
//                LIMIT( 0.15 V, 2.0 V );

        WAIT( 1000 );
        MEAS_PIN( PINALL, sizeof(PINALL)/sizeof(int) );
                
        SYS_INIT();
        return TRUE;
}

BOOL CKMKYL000VM_CCT2::LEAK_H()
{
        TEST("LEAK_H", LEAK_H);
        
        SET_PINS(PINALL, sizeof(PINALL)/sizeof(int), PMU, PMU1 );
//        SET_PINS(PINALL, sizeof(PINALL)/sizeof(int), PMU, PMU2 );

//        SET_PPS_REG( PPS1, 1.2 V, R_500UA, 500 UA );
//        SET_PPS_REG( PPS3, 1.2 V, R_500UA, 500 UA );
//        SET_PPS_REG( PPS4, 1.2 V, R_500UA, 500 UA );

        
        SET_PPS_REG( PPS1, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS5, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 2 );
        SET_PPS_REG( PPS6, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 3  );
        
        SET_PPS_REG( PPS2, 0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS7, 0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1  );
        SET_PPS_REG( PPS8, 0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1  );

        SET_PPS_ON( 1000, 1000, 1000, 1000, 1000, 1000, 0, 0, 0, 0, 0, 0  );

        VSIM( R_20UA );
//        VSIM( R_50MA );

      SET_PMU( PMU1, 0.5 V );
      SET_PMU( PMU2, 0.0 V );
//                SET_PMU( PMU1, 0.5 V );
                
        LIMIT( -5 UA, 5 UA );

        MEAS_PIN_SERIAL( PINALL, sizeof(PINALL)/sizeof(int), 1000 );
        
//       MEAS_PIN( PINALL, sizeof(PINALL)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::LEAK_L()
{
        TEST("LEAK_L", LEAK_L);

        SET_PINS(PINALL, sizeof(PINALL)/sizeof(int), PMU, PMU1 );
 //       SET_PINS(PINALL, sizeof(PINALL)/sizeof(int), PMU, PMU2 );

//        SET_PPS_REG( PPS1, 1.2 V, R_500UA, 500 UA );
//        SET_PPS_REG( PPS3, 1.2 V, R_500UA, 500 UA );
//        SET_PPS_REG( PPS4, 1.2 V, R_500UA, 500 UA );


        
        SET_PPS_REG( PPS1, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS5, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1  );
        SET_PPS_REG( PPS6, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1  );
/*        
        SET_PPS_REG( PPS2, 0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS7, 0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1  );
        SET_PPS_REG( PPS8, 0 V, R_250UA, 250 UA, 0 UA, 250 UA, 1  );
 */ 
           
        SET_PPS_ON( 1000, 1000, 1000, 1000, 1000, 1000 ,0, 0, 0, 0, 0, 0  );
        
 //       RON_INT_PROC(0XFFF); 

        VSIM( R_20UA);

        SET_PMU( PMU1, 0 V );
        SET_PMU( PMU2, 0.5 V );
 //                SET_PMU( PMU1, 1.2 V );

        LIMIT( -5 UA, 5 UA );
                
        MEAS_PIN_SERIAL( PINALL, sizeof(PINALL)/sizeof(int), 1000 );
//                MEAS_PIN( PINALL, sizeof(PINALL)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDD1_D()
{
        TEST("STBY_VDD1_D", STBY_VDD1_D);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

//        SET_PPS_REG( PPS1, 1.3 V, R_50MA, 50 MA );
//        SET_PPS_REG( PPS3, 1.3 V, R_50MA, 50 MA );
//        SET_PPS_REG( PPS4, 1.3 V, R_50MA, 50 MA );
//        SET_PPS_REG( PPS5, 0.65 V, R_50MA, 50 MA );
//        SET_PPS_REG( PPS6, 0.65 V, R_50MA, 50 MA );
//        SET_PPS_REG( PPS2, 1.95 V, R_50MA, 50 MA );
        
        SET_PPS_REG( PPS1, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_50MA, 50 MA, -5.0 MA, 5.0 MA, 1 );

        SET_PPS_ON( 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIH1, 0.0 V );
        SET_POW( VIH3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );
                
 //               SEND_MPAT("patternd");
        START_MPAT( "StandBy" );
        WAIT( 1000 );

//        LIMIT( -5.0 MA, 5.0 MA );

        MEAS_PPS( PS2, sizeof(PS2)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDD2_D()
{
        TEST("STBY_VDD2_D", STBY_VDD2_D);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.3 V, R_50MA, 50 MA, -10.0 MA, 10.0 MA, 1);
        SET_PPS_REG( PPS3, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS4, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS5, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS6, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

        //LIMIT( -10.0 MA, 10.0 MA );

//        MEAS_PPS( PPS1, POS_5TH, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS1, sizeof(PS1)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDDCA_D()
{
        TEST("STBY_VDDCA_D", STBY_VDDCA_D);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

 /*       
        SET_PPS_REG( PPS1, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS2, 1.95 V, R_5MA, 5 MA );
        SET_PPS_ON( 0, 0, 0, 0, 0, 0 );
*/

        SET_PPS_REG( PPS1, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_2500UA, 2500 UA, -1 MA, 1 MA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );

        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );
                
                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

       // LIMIT( -1.0 MA, 1.0 MA );

        //MEAS_PPS( PPS3, POS_5TH, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS5, sizeof(PS5)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );
        SYS_INIT();
  
        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDDQ_D()
{
        TEST("STBY_VDDQ_D", STBY_VDDQ_D);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );


        SET_PPS_REG( PPS1, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_2500UA, 2500 UA, -1 MA, 1 MA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );



 /*       
        SET_PPS_REG( PPS1, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS2, 1.95 V, R_5MA, 5 MA );
 */
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
 //       SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL2, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );
        
                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

//        LIMIT( -1.0 MA, 1.0 MA );

        //MEAS_PPS( PPS4, POS_6TH, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS6, sizeof(PS6)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDD1()
{
        TEST("STBY_VDD1", STBY_VDD1);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_2500UA, 2500 UA, -0.1 MA, 1.0 MA, 1 );
/*        
        SET_PPS_REG( PPS1, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS4, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS5, 0.65 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS6, 0.65 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.95 V, R_50MA, 50 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

//        LIMIT( -0.1 MA, 1.0 MA );

//        MEAS_PPS( PPS2, POS_STBY, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS2, sizeof(PS2)/sizeof(int), PRP_STBY, SIG_VSIM, NULL);
                
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDD2()
{
        TEST("STBY_VDD2", STBY_VDD2);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.3 V, R_2500UA, 2500 UA, -0.1 MA, 2.2 MA, 1, R_2500UA, 30000);
//        SET_PPS_REG( PPS1, 1.3 V, R_25MA, 25 MA, -0.1 MA, 2.2 MA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
/*        
        SET_PPS_REG( PPS1, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS4, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS5, 0.65 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS6, 0.65 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.95 V, R_50MA, 50 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );
        
 //       WAIT( 10000 );  // ADD 20120920

 //       LIMIT( -0.1 MA, 2.2 MA );

        //MEAS_PPS( PPS1, POS_OPR, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS1, sizeof(PS1)/sizeof(int),PRP_STBY, SIG_VSIM, NULL, 50);
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDDCA()
{
        TEST("STBY_VDDCA", STBY_VDDCA);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );
        

        SET_PPS_REG( PPS1, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_2500UA, 2500 UA, -0.2 MA, 0.2 MA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );



/*        
        SET_PPS_REG( PPS1, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS4, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS2, 1.95 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );
        
//        LIMIT( -0.2 MA, 0.2 MA );

//        MEAS_PPS( PPS3, POS_3RD, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS5, sizeof(PS5)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );
//                MEAS_PPS( PS5, sizeof(PS5)/sizeof(int), 0, SIG_VSIM, NULL );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VDDQ()
{
        TEST("STBY_VDDQ", STBY_VDDQ);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.3 V, R_250UA, 250 UA, -0.2 MA, 0.2 MA, 1 );
        SET_PPS_REG( PPS7, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.65 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS2, 1.95 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );

/*        
        SET_PPS_REG( PPS1, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.3 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS5, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.65 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS2, 1.95 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

//        LIMIT( -0.2 MA, 0.2 MA );

        //MEAS_PPS( PPS4, POS_4TH, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS6, sizeof(PS6)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VREFCA()
{
        TEST("STBY_VREFCA", STBY_VREFCA);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );


        SET_PPS_REG( PPS1, 1.8 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS5, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_250UA, 250 UA, -0.2 MA, 0.2 MA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
      
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS2, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS3, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS4, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS5, 0.6 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS6, 0.6 V, R_500UA, 500 UA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
 //       SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

//        LIMIT( -0.2 MA, 0.2 MA );

        //MEAS_PPS( PPS5, POS_STBY, SIG_VSIM, NULL, 50 );
                MEAS_PPS( PS7, sizeof(PS7)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::STBY_VREFDQ()
{
        TEST("STBY_VREFDQ", STBY_VREFDQ);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );


        SET_PPS_REG( PPS1, 1.8 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS5, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_250UA, 250 UA, 0 UA, 250 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_250UA, 250 UA, -0.2 MA, 0.2 MA, 1 );

/*        
        SET_PPS_REG( PPS1, 1.8 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS2, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS3, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS4, 1.2 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS5, 0.6 V, R_500UA, 500 UA );
        SET_PPS_REG( PPS6, 0.6 V, R_500UA, 500 UA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "StandBy" );
        WAIT( 1000 );

//        LIMIT( -0.2 MA, 0.2 MA );

        //MEAS_PPS( PPS6, POS_STBY, SIG_VSIM, NULL, 50 );
        MEAS_PPS( PS8, sizeof(PS8)/sizeof(int), PRP_STBY, SIG_VSIM, NULL, 50 );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOH0L()
{
        TEST("VOH0L", VOH0L);

        SET_DC( true );
        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
     
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );
        
        START_MPAT( "VOH0L" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        LIMIT( 0.9 V, 9.0 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        SET_DC( false );
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOH0U()
{
        TEST("VOH0U", VOH0U);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
  

        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

                
        START_MPAT( "VOH0U" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        LIMIT( 0.9 V, 9.0 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOH1L()
{
        TEST("VOH1L", VOH1L);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );
 //               SEND_MPAT("patternd");
        START_MPAT( "VOH1L" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        LIMIT( 0.9 V, 9.0 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOH1U()
{
        TEST("VOH1U", VOH1U);
SET_CHIP(1);
        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
  

        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

//                SEND_MPAT("patternd");
        START_MPAT( "VOH1U" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        LIMIT( 0.9 V, 9.0 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        SYS_INIT();
SET_CHIP(0);
        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOL0L()
{
        TEST("VOL0L", VOL0L);
SET_CHIP(2);
        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
  

        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

//                SEND_MPAT("patternd");
        START_MPAT( "VOL0L" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        LIMIT( -9 V, 0.3 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );
SET_CHIP(0);
        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOL0U()
{
        TEST("VOL0U", VOL0U);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
 

        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

//                SEND_MPAT("patternd");
        START_MPAT( "VOL0U" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        LIMIT( -9 V, 0.3 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOL1L()
{
        TEST("VOL1L", VOL1L);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );


        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

//                SEND_MPAT("patternd");
        START_MPAT( "VOL1L" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        LIMIT( -9 V, 0.3 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOL, sizeof(PIN_IOL)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::VOL1U()
{
        TEST("VOL1U", VOL1U);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA, 0 UA, 50 MA, 1 );

        SET_PPS_REG( PPS5, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS6, 1.2 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_2500UA, 2500 UA, 0 UA, 2500 UA, 1 );
 

        
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.2 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.2 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_5MA, 5 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_5MA, 5 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.2 V );
//        SET_POW( VIH2, 1.2 V );
        SET_POW( VIH3, 1.2 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        WAIT( 1000 );

//                SEND_MPAT("patternd");
        START_MPAT( "VOL1U" );
        ISVM( 200 UA, R_2MA, PMU1, PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        LIMIT( -9 V, 0.3 V );

        WAIT( 1000 );
        MEAS_PIN( PIN_IOU, sizeof(PIN_IOU)/sizeof(int) );

        SYS_INIT();

        return TRUE;
}

BOOL CKMKYL000VM_CCT2::GF()
{
        TEST("GF", GF);

        SET_PINS(PIN_162F, sizeof(PIN_162F)/sizeof(int), DRE, VIH );
        SET_DRE( ON );

        SET_EXP( 0xf, 0x0 );
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS2, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS5, 1.3 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS6, 1.5 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS7, 0.6 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
        SET_PPS_REG( PPS8, 0.6 V, R_50MA, 50 MA, 0 MA, 50 MA, 1 );
/*        
        SET_PPS_REG( PPS1, 1.8 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS2, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS3, 1.3 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS4, 1.5 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS5, 0.6 V, R_50MA, 50 MA );
        SET_PPS_REG( PPS6, 0.6 V, R_50MA, 50 MA );
*/
        SET_PPS_ON( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  );

        SET_POW( VIH1, 1.3 V );
//        SET_POW( VIH2, 1.3 V );
        SET_POW( VIH3, 1.3 V );
        SET_POW( VIL1, 0.0 V );
        SET_POW( VIL3, 0.0 V );
        SET_POW( VTH , 0.6 V );
        
 //       SEND_MPAT("patternd");
        MEAS_MPAT( "GF" );

        SYS_INIT();

        return TRUE;
}

