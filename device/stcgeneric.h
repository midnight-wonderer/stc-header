// header for Small Device C Compiler
// header repository: https://github.com/MidnightWonderer/stc-header
// original source taken July 7 2015 from official website:
// http://www.stcmcu.com/datasheet/stc/STC-AD-PDF/STC_NEW_8051.H
//--------------------------------------------------------------------------------
// C51 Core SFRs
//                                             7     6     5     4     3     2     1     0     Reset Value
__sfr __at (0xE0) ACC; //Accumulator                                                           0000,0000
__sfr __at (0xF0) B;   //B Register                                                            0000,0000
__sfr __at (0xD0) PSW; //Program Status Word   CY    AC    F0    RS1   RS0   OV    F1    P     0000,0000
//-----------------------------------
__sbit __at (0xD7) CY;
__sbit __at (0xD6) AC;
__sbit __at (0xD5) F0;
__sbit __at (0xD4) RS1;
__sbit __at (0xD3) RS0;
__sbit __at (0xD2) OV;
__sbit __at (0xD1) F1;
__sbit __at (0xD0) P;
//-----------------------------------
__sfr __at (0x81) SP;  //Stack Pointer                                                         0000,0111
__sfr __at (0x82) DPL; //Data Pointer Low Byte                                                 0000,0000
__sfr __at (0x83) DPH; //Data Pointer High Byte                                                0000,0000
//--------------------------------------------------------------------------------
// Systems Management Special Function Register
//                                                7         6         5         4         3         2         1         0         Reset Value
__sfr __at (0x87) PCON; //Power Control           SMOD      SMOD0     LVDF      POF       GF1       GF0       PD        IDL       0001,0000
// -
__sfr __at (0x8E) AUXR; //Auxiliary Register      T0x12     T1x12     UART_M0x6 BRTR      S2SMOD    BRTx12    EXTRAM    S1BRS     0000,0000
//-----------------------------------
__sfr __at (0xA2) AUXR1; //Auxiliary Register 1   -         PCA_P4    SPI_P4    S2_P4     GF2       ADRJ      -         DPS       0000,0000
/*
PCA_P4:
    0, default PCA in the P1 port
    1, PCA/PWM switching from port P1 to P4 port:
                   ECI switch from P1.2 to P4.1 port
           PCA0 / PWM0 switch from P1.3 to P4.2 port
           PCA1 / PWM1 switch from P1.4 to P4.3 port
SPI_P4:
    0, default SPI port in P1
    1, SPI port switching from P1 to P4 port:
            SPICLK switch from P1.7 to P4.3 port
              MISO switch from P1.6 to P4.2 port
              MOSI switch from P1.5 to P4.1 port
                SS switch from P1.4 to P4.0 port
S2_P4:
    0, the default port UART2 in P1
    1, UART2 port switching from P1 to P4 port:
                TxD2 switch from P1.3 to P4.3 port
                RxD2 switch from P1.2 to P4.2 port
GF2: General Flag

ADRJ:
    0, 10-bit A/D conversion result register 8 on ADC_RES lower two on ADC_RESL register
    1, 10-bit A/D conversion result in the highest two ADC_RES register low 2 Low 8 on ADC_RESL register

DPS: 0, the default data pointer DPTR0
     1, using another data pointer DPTR1
*/
//-----------------------------------
__sfr __at (0x8F) WAKE_CLKO; //Additional SFR WAK1_CLKO
/*
      7          6          5          4          3          2          1          0          Reset Value
      PCAWAKEUP  RXD_PIN_IE T1_PIN_IE  T0_PIN_IE  LVD_WAKE   -          T1CLKO     T0CLKO     0000,0000B

b7 - PCAWAKEUP: PCA interrupt can wake powerdown.
b6 - RXD_PIN_IE: When P3.0 (RXD) falling RI set to wake up powerdown (must open the corresponding interrupt).
b5 - T1_PIN_IE: when T1 T1 pin falling interrupt flag is set to wake up powerdown (must open the corresponding interrupt).
b4 - T0_PIN_IE: when T0 T0 pin falling interrupt flag is set to wake up powerdown (must open the corresponding interrupt).
b3 - LVD_WAKE: when CMPIN low pin LVD interrupt flag is set to wake up powerdown (must open the corresponding interrupt).
b2 -
b1 - T1CLKO: Allows T1CKO (P3.5) pin output T1 overflow pulse, Fck1 = 1/2 T1 overflow rate
b0 - T0CLKO: Allows T0CKO (P3.4) pin output pulse T0 overflow, Fck0 = 1/2 T1 overflow rate
*/
//-----------------------------------             7     6     5     4     3     2     1     0     Reset Value
__sfr __at (0x97) CLK_DIV; //Clock Divder         -     -     -     -     -     CLKS2 CLKS1 CLKS0 xxxx,x000
//-----------------------------------
__sfr __at (0xA1) BUS_SPEED; //Stretch register   -     -     ALES1 ALES0 -     RWS2  RWS1  RWS0  xx10,x011
/*
ALES1 and ALES0:
00 : The P0 address setup time and hold time to ALE negative edge is one clock cycle
01 : The P0 address setup time and hold time to ALE negative edge is two clock cycles.
10 : The P0 address setup time and hold time to ALE negative edge is three clock cycles. (default)
11 : The P0 address setup time and hold time to ALE negative edge is four clock cycles.

RWS2,RWS1,RWS0:
  000 : The MOVX read/write pulse is 1 clock cycle.
  001 : The MOVX read/write pulse is 2 clock cycles.
  010 : The MOVX read/write pulse is 3 clock cycles.
  011 : The MOVX read/write pulse is 4 clock cycles. (default)
  100 : The MOVX read/write pulse is 5 clock cycles.
  101 : The MOVX read/write pulse is 6 clock cycles.
  110 : The MOVX read/write pulse is 7 clock cycles.
  111 : The MOVX read/write pulse is 8 clock cycles.
*/
//--------------------------------------------------------------------------------
// interrupt Special Function Registers
// Some interrupt control, interrupt flag spread other special function registers, these bits are defined in the bit address
// Some of median-bit addressability, see a new generation of 1T 8051 Series MCU Chinese guide
//                                                    7     6     5     4     3     2     1     0     Reset Value
__sfr __at (0xA8) IE;  //Interrupt Control Register   EA    ELVD  EADC  ES    ET1   EX1   ET0   EX0   0x00,0000
//-----------------------
__sbit __at (0xAF) EA;
__sbit __at (0xAE) ELVD; // low-voltage monitoring interrupt enable bit
__sbit __at (0xAD) EADC; // ADC interrupt enable bit
__sbit __at (0xAC) ES;
__sbit __at (0xAB) ET1;
__sbit __at (0xAA) EX1;
__sbit __at (0xA9) ET0;
__sbit __at (0xA8) EX0;
//-----------------------
__sfr __at (0xAF) IE2;  // Auxiliary Interrupt        -     -     -     -     -     -     ESPI  ES2   0000,0000
//-----------------------
__sfr __at (0xB8) IP;   // interrupt priority low     PPCA  PLVD  PADC  PS    PT1   PX1   PT0   PX0   0000,0000
//--------
__sbit __at (0xBF) PPCA; // PCA module interrupt priority
__sbit __at (0xBE) PLVD; // low-voltage monitoring interrupt priority
__sbit __at (0xBD) PADC; // ADC interrupt priority
__sbit __at (0xBC) PS;
__sbit __at (0xBB) PT1;
__sbit __at (0xBA) PX1;
__sbit __at (0xB9) PT0;
__sbit __at (0xB8) PX0;
//-----------------------
__sfr __at (0xB7) IPH; // Interrupt Priority High     PPCAH PLVDH PADCH PSH   PT1H  PX1H  PT0H  PX0H  0000,0000
__sfr __at (0xB5) IP2; //                             -     -     -     -     -     -     PSPI  PS2   xxxx,xx00
__sfr __at (0xB6) IPH2; //                            -     -     -     -     -     -     PSPIH PS2H  xxxx,xx00
//-----------------------
// I/O port Special Function Registers
//                                        7        6        5        4        3        2        1        0        Reset Value
__sfr __at (0x80) P0; // 8bit Port0       P0.7     P0.6     P0.5     P0.4     P0.3     P0.2     P0.1     P0.0     1111,1111
__sfr __at (0x94) P0M0; //                                                                                        0000,0000
__sfr __at (0x93) P0M1; //                                                                                        0000,0000
__sfr __at (0x90) P1; // 8bit Port1       P1.7     P1.6     P1.5     P1.4     P1.3     P1.2     P1.1     P1.0     1111,1111
__sfr __at (0x92) P1M0; //                                                                                        0000,0000
__sfr __at (0x91) P1M1; //                                                                                        0000,0000
__sfr __at (0x9D) P1ASF; // P1 analog special function
__sfr __at (0xA0) P2; // 8bit Port2       P2.7     P2.6     P2.5     P2.4     P2.3     P2.2     P2.1     P2.0     1111,1111
__sfr __at (0x96) P2M0; //                                                                                        0000,0000
__sfr __at (0x95) P2M1; //                                                                                        0000,0000
__sfr __at (0xB0) P3; // 8bit Port3       P3.7     P3.6     P3.5     P3.4     P3.3     P3.2     P3.1     P3.0     1111,1111
__sfr __at (0xB2) P3M0; //                                                                                        0000,0000
__sfr __at (0xB1) P3M1; //                                                                                        0000,0000
__sfr __at (0xC0) P4; // 8bit Port4       P4.7     P4.6     P4.5     P4.4     P4.3     P4.2     P4.1     P4.0     1111,1111
__sfr __at (0xB4) P4M0; //                                                                                        0000,0000
__sfr __at (0xB3) P4M1; //                                                                                        0000,0000
// -
__sfr __at (0xBB) P4SW; // Port-4 switch  -        LVD_P4.6 ALE_P4.5 NA_P4.4  -        -        -        -        x000,xxxx
__sfr __at (0xC8) P5; // 8bit Port5       -        -        -        -        P5.3     P5.2     P5.1     P5.0     xxxx,1111
__sfr __at (0xCA) P5M0; //                                                                                        0000,0000
__sfr __at (0xC9) P5M1; //                                                                                        0000,0000
//--------------------------------------------------------------------------------
// timer special function registers
//                                        7     6     5     4     3     2     1     0     Reset Value
__sfr __at (0x88) TCON; //T0/T1 Control   TF1   TR1   TF0   TR0   IE1   IT1   IE0   IT0   0000,0000
//-----------------------------------
__sbit __at (0x8F) TF1;
__sbit __at (0x8E) TR1;
__sbit __at (0x8D) TF0;
__sbit __at (0x8C) TR0;
__sbit __at (0x8B) IE1;
__sbit __at (0x8A) IT1;
__sbit __at (0x89) IE0;
__sbit __at (0x88) IT0;
//-----------------------------------
__sfr __at (0x89) TMOD; //T0/T1 Modes     GATE1 C/T1  M1_1  M1_0  GATE0 C/T0  M0_1  M0_0  0000,0000
__sfr __at (0x8A) TL0; //T0 Low Byte                                                      0000,0000
__sfr __at (0x8C) TH0; //T0 High Byte                                                     0000,0000
__sfr __at (0x8B) TL1; //T1 Low Byte                                                      0000,0000
__sfr __at (0x8D) TH1; //T1 High Byte                                                     0000,0000
//--------------------------------------------------------------------------------
// Serial Port Special Function Registers
//                                            7        6        5        4        3        2        1        0        Reset Value
__sfr __at (0x98) SCON; //Serial Control      SM0/FE   SM1      SM2      REN      TB8      RB8      TI       RI       0000,0000
//-----------------------------------
__sbit __at (0x9F) SM0;  // SM0/FE
__sbit __at (0x9E) SM1;
__sbit __at (0x9D) SM2;
__sbit __at (0x9C) REN;
__sbit __at (0x9B) TB8;
__sbit __at (0x9A) RB8;
__sbit __at (0x99) TI;
__sbit __at (0x98) RI;
//-----------------------------------
__sfr __at (0x99) SBUF; //Serial Data Buffer                                                                          xxxx,xxxx
__sfr __at (0xB9) SADEN; //Slave Address Mask                                                                         0000,0000
__sfr __at (0xA9) SADDR; //Slave Address                                                                              0000,0000
//-----------------------------------
__sfr __at (0x9A) S2CON; //S2 Control         S2SM0    S2SM1    S2SM2    S2REN    S2TB8    S2RB8    S2TI     S2RI     0000,0000
__sfr __at (0x9B) S2BUF; //S2 Serial Buffer                                                                           xxxx,xxxx
__sfr __at (0x9C) BRT; //S2 Baud-Rate Timer                                                                           0000,0000
//--------------------------------------------------------------------------------
// watchdog timer special function register
__sfr __at (0xC1) WDT_CONTR; //Watch-Dog-Timer Control register
//                                            WDT_FLAG -        EN_WDT   CLR_WDT  IDLE_WDT PS2      PS1      PS0      xx00,0000
//-----------------------

//--------------------------------------------------------------------------------
// PCA/PWM special function register
//                                                        7     6     5     4     3     2     1     0     Reset Value
__sfr __at (0xD8) CCON;   //PCA Control Register          CF    CR    -     -     -     -     CCF1  CCF0  00xx,xx00
//-----------------------
__sbit __at (0xDF) CF; // PCA counter overflow flag set by hardware or software, must be cleared by software.
__sbit __at (0xDE) CR; // 1: Allow PCA counter and must be cleared by software.
//-
//-
__sbit __at (0xD9) CCF1; // PCA module interrupt flag is set by hardware and must be cleared by software.
__sbit __at (0xD8) CCF0; // PCA Module 0 interrupt flag, set by hardware and must be cleared by software.
//-----------------------
__sfr __at (0xD9) CMOD; //PCA Mode register               CIDL  -     -     -     CPS2  CPS1  CPS0  ECF   0xxx,x000
/*
CIDL: PCA counter is at idle state continues to count, 0: continues to count 1: Stop counting.

CPS2: PCA counter pulse source selection bit 2.
CPS1: PCA counter pulse source select bits.
CPS0: PCA counter pulse source 0.
   CPS2   CPS1   CPS0
    000 system clock frequency fosc / 12.
    001 system clock frequency fosc / 2.
    0 1 0 Timer0 overflow.
    011 external clock by the ECI / P3.4 pin input, maximum fosc / 2.
    100 system clock, Fosc / 1
    101 system clock frequency / 4, Fosc / 4
    110 system clock frequency / 6, Fosc / 6
    111 system clock frequency / 8, Fosc / 8

ECF: PCA counter overflow interrupt enable bit, 1-- allow CF (CCON.7) generates an interrupt.
*/
//-----------------------
__sfr __at (0xE9) CL; //PCA Counter Low                                                                   0000,0000
__sfr __at (0xF9) CH; //PCA Counter High                                                                  0000,0000
//-----------------------
__sfr __at (0xDA) CCAPM0; //PCA module 0 PWM register     -     ECOM0 CAPP0 CAPN0 MAT0  TOG0  PWM0  ECCF0 x000,0000
__sfr __at (0xDB) CCAPM1; //PCA module 1 PWM register     -     ECOM1 CAPP1 CAPN1 MAT1  TOG1  PWM1  ECCF1 x000,0000

// ECOMn = 1: enable the comparison function.
// CAPPn = 1: Allow rising edge capture.
// CAPNn = 1: Allow falling edge capture.
// MATn = 1: When a match occurs, allow CCON the CCFn set.
// TOGn = 1: When a match occurs, CEXn will flip.
// PWMn = 1: The CEXn set PWM output.
// ECCFn = 1: Allow CCON the CCFn trigger an interrupt.

// ECOM Capps CAPNn text TOGn PWMn ECCFn
// 0 0 0 0 0 0 0 0x00 any feature is not enabled.
// X 1 0 0 0 0 x 0x21 16-bit ​​CEXn rising edge capture.
// X 0 1 0 0 0 x 0x11 16-bit ​​CEXn falling edge capture.
// X 1 1 0 0 0 x 0x31 16-bit ​​CEXn edge (upper and lower edge) trigger capture function.
// 1 0 0 1 0 0 x 0x49 16-bit software timer.
// 1 0 0 1 1 0 x 0x4d 16-bit high speed pulse output.
//  1      0      0     0     0     1     0   0x42   8位 PWM。

// ECOM Capps CAPNn text TOGn PWMn ECCFn
// 0 0 0 0 0 0 0 0x00 no such operation
// 1 0 0 0 0 1 0 0x42 ordinary eight PWM, without interruption
// 1 1 0 0 0 1 1 0x63 PWM output from low to high to generate an interrupt
// 1 0 1 0 0 1 1 0x53 PWM output from high to low can generate an interrupt
// 1 1 1 0 0 1 1 0x73 PWM output from low to high or from high to low can interrupt generation

//-----------------------
__sfr __at (0xEA) CCAP0L; // PCA Modules Capture / Compare 0 register low 8. 0000,0000
__sfr __at (0xFA) CCAP0H; // PCA Module 0 Capture / Compare register high eight. 0000,0000
__sfr __at (0xEB) CCAP1L; // PCA module capture / compare register 1 is low 8. 0000,0000
__sfr __at (0xFB) CCAP1H; // PCA Module 1 Capture / compare register high eight. 0000,0000
//-----------------------
__sfr __at (0xF2) PCA_PWM0; //PCA module 0 PWM register   -     -     -     -     -     -     EPC0H EPC0L xxxx,xx00
__sfr __at (0xF3) PCA_PWM1; //PCA module 1 PWM register   -     -     -     -     -     -     EPC1H EPC1L xxxx,xx00
//PCA_PWMn:    7      6      5      4      3      2      1      0
// - - - - - - EPCnH EPCnL
//B7-B2: Retention
// B1 (EPCnH): In PWM mode, the composition and CCAPnH 9 digits.
// B0 (EPCnL): In PWM mode, the composition and CCAPnL 9 digits.
//--------------------------------------------------------------------------------
// ADC Special Function Registers
//                                                                 7         6         5         4         3         2         1         0         Reset Value
__sfr __at (0xBC) ADC_CONTR; // A/D Switch control register        ADC_POWER SPEED1    SPEED0    ADC_FLAG  ADC_START CHS2      CHS1      CHS0      0000,0000
__sfr __at (0xBD) ADC_RES;   // A/D conversion result high 8-bit   ADCV.9    ADCV.8    ADCV.7    ADCV.6    ADCV.5    ADCV.4    ADCV.3    ADCV.2    0000,0000
__sfr __at (0xBE) ADC_RESL;  // A/D conversion result low 2-bit                                                                ADCV.1    ADCV.0    0000,0000
//--------------------------------------------------------------------------------
// SPI Special Function Registers
//                                                7    6    5    4    3    2    1    0    Reset Value
__sfr __at (0xCE) SPCTL; //SPI Control Register   SSIG SPEN DORD MSTR CPOL CPHA SPR1 SPR0 0000,0100
__sfr __at (0xCD) SPSTAT; //SPI Status Register   SPIF WCOL -    -    -    -    -    -    00xx,xxxx
__sfr __at (0xCF) SPDAT; //SPI Data Register                                              0000,0000
//--------------------------------------------------------------------------------
// IAP/ISP special function register
__sfr __at (0xC2) IAP_DATA;
__sfr __at (0xC3) IAP_ADDRH;
__sfr __at (0xC4) IAP_ADDRL;
//                                                    7     6     5     4     3     2     1     0     Reset Value
__sfr __at (0xC5) IAP_CMD; //IAP Mode Table           0     -     -     -     -     -     MS1   MS0   0xxx,xx00
__sfr __at (0xC6) IAP_TRIG;
__sfr __at (0xC7) IAP_CONTR; //IAP Control Register   IAPEN SWBS  SWRST CFAIL -     WT2   WT1   WT0   0000,x000
//--------------------------------------------------------------------------------
