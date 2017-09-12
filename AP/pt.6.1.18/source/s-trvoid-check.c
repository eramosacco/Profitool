#define LPROTOTYPE
#define PRIMELIB
#include "libSQLclient.h"
#include "libbb.h"
#include "libutil.h"
#include "libpost.h"
#include "libfio.h"
#include "libscr.h"
#include "fortran.h"
#include "p_post_com_batch.h"
#include "sc_com1.h"
#include "sc_com2.h"
#include "black_board_insert.h"
#include "cmis_com.h"
#include "apar_com_new.h"
#include "io_units.h"
#include "parm_k.h"
double rndoff();
double combjp();
/*
----------------------------------------------------------------------C
     S/TRVOID-CHECK

     BATCH INPUT PROCESSOR FOR VOIDING CHECKS

     DBS - 07/14/98 - from a clone of S-TRTRADE-PAYMENTS

*/

void tr9800(void)
{
static double T2;
static double T3;
static double T4;
static short D6;
static short K4 = 4;
static short K32 = 32;
static short K12 = 12;
static short K1 = 1;
static short K10 = 10;
static short K0 = 0;
static short K17 = 17;
static short K16 = 16;
static short K5 = 5;
static short K35 = 35;
static short K36 = 36;
static short K29 = 29;
static short K8 = 8;
static short K2 = 2;
static short K3 = 3;
static short K11 = 11;
static short K13 = 13;
static short K6 = 6;
static short K9999 = 9999;
static short K30 = 30;
static short K7 = 7;
static short K9 = 9;
static short K80 = 80;
static short K64 = 64;
static short K14 = 14;
static short K15 = 15;
static double R1 = 0.e0;
static short N1 = -1;
static short K33 = 33;
static double pSldep;
static short duplxS;                         /* DUPLEX PRIMOS FUNCTION */
static short cpShlp[8];                      /* NAME USED FOR HELP REQUESTS IN SCFM */

static double amount[300];
static double ppsamt[300];
static double rjobph[300];
static double activ[300][2];
static double po[300];
static double rinv[300];
static double effinv[300];
static double datinv[300];
static double accts[20];
static double acctem[20];
static double apdata[5];
static double vatact[2][3][2][3];
static double code[1];

static short ivname[15];
static short jrnkey[10];
static short keyj[32];
static short keysav[32];
static short keyap[32];
static short lastyp[4];
static short marray[14];
static short icert[6];
static short iact[5];
static short memdsc[8];
static short mempps[8];
static short fordom;
static short accpay;
static short ifgs;
static short vivo;
static short vatdsc[36][20];
static short despnt[2][3][2][3];
static short itcode[300];
static short invcmp[300];
static short ijob[3];
static short iphase[1];
static short iobuff[6];
static short iactiv[5];
static short dscact[5];
static short check[4];
static short camnt[7];
static short cjob[3];
static short cph;
static short cinv[4];

static unsigned short backed;
static unsigned short more;
static short ipbya;
static short irc;
static short i;
static short nview;
static double batch;
static double effdat;
static double effout;
static short iswpps;
static double rdum;
static double atovc;
static double atoacc;
static double atotyp;
static double atopay;
static short nfunc;
static double trtype;
static short ircb;
static double refno;
static short ircf;
static double vendor;
static short nbank;
static short ircvat;
static double apglcd;
static double apgldc;
static double dscern;
static short ifor;
static double chckno;
static double dummy;
static double cash;
static double chkdat;
static short mflag;
static double tamnt;
static short ib;
static short icd;
static double vend;
static double amnt;
static double rj;
static double rp;
static double commit;
static double rjp;
static double discnt;
static double ppsdue;
static double trcode;
static double apgl;
static short irccom;
static short irc5;
static double rjob;
static double phase;
static short len;
static short idash;
static short ircSs;
static double ppsrat;
static double ppstmp;
static short ircx;
static double dscjob;
static double dscphs;
static short invoic;
static short icg;
static short jfunc;
static short nread;

static char* F1326[] = {
    "(f10.0)"
};
static char* F1336[] = {
    "(f10.0)"
};
static char* F3431[] = {
    "('Batch Effective Date cannot be earlier than ','Date of Check to be Voided')"
};
static char* F3455[] = {
    "(2a2,b'########')"
};
static char* F3467[] = {
    "(f9.2)"
};
static char* F3475[] = {
    "(b'-----,--#.##')"
};
static char* F3485[] = {
    "(b'-,--#.##')"
};
static char* F3565[] = {
    "(b'-,---,--#.##')"
};
static char* F3570[] = {
    "('CLIENT# ',b'######',2x)"
};
static char* F4120[] = {
    "(a2,a2,4x)"
};


    fill(lastyp,&K4,"!!");                   /*  Force call TTYP$C */

    ibyaSc("P ",&ipbya);

    /*
     --- OPEN AP/AR$MASTER FILE FOR INVOICE VALIDATION

    */
    fileSc("READ",&K32,"AP/AR$MASTER",&K12,&K1,&irc,0);
    if(irc != 0) ferrSc(&K10,&irc,"FILE: AP/AR$MASTER   PROGRAM: TRADE PAYMENTS~",&K0);

    /*
     --- OPEN COMMITMENT$MASTER

    */
    ioSf("OPEN","COMMITMENT$MASTER",&K17,"    ",&K0,&K0,&K0,&K0,&irc);

    if(irc != 0) ferrSc(&K10,&irc,"COULD NOT OPEN COMMITMENT$MASTER  SUBR: TR6700~",&K0);

    /*
     --- OPEN INPUT BATCH

    */
    for(i=1; i==1 || i<=10; i++)
    {
        jrnkey[i-1] = 0;
    }

    jrnkey[2] = 1;                           /* CASH DISBURSEMENTS JOURNAL */
    nview = 0;                               /* RESET VIEWING ONLY FLAG */
    iSopnS(jrnkey,&batch,&effdat,&effout,&irc);
    if(irc > 1) goto S9000;
    if(irc == 1) nview = 1;                  /* SET VIEWING ONLY FLAG */

    if(ipbya != *(short*)fifstrgv("Y ",2)) loadSs("TRVOID CHECK    ",&K16,&irc);
    if(ipbya == *(short*)fifstrgv("Y ",2)) loadSs("TRVOID CHECKA   ",&K16,&irc);

    if(irc != 0) goto S9000;

    /*
     --- GET PPS SWITCH

    */
    iswpps = 1;
    dataSs("PPS01 ",&K5,&rdum,&K0,&irc);
    if(irc == 1) iswpps = 0;
    if(iswpps == 0) goto S1370;


    /*
     --- GET AUSTRALIAN TAX OFFICE V/C #, ACCOUNT NUMBER, AND TR TYPE

    */
    gnliSc("READ","AUSTRALIAN TAX OFFICE VENDOR NUMBER",&K35,xc_cSmess,&K10,&irc);
    if(irc == 0) goto S1325;
    errSs("Must enter (GENL INFO) AUSTRALIAN TAX OFFICE VENDOR NUMBER~",&K0,&irc);
    goto S1360;

S1325:
    if(READ(INTERNAL,xc_cSmess,10,IOSTAT,NULL,1,FMT,F1326,1,REAL8,&atovc,0)) goto S1328;
    atovc = fifdint(atovc);
    if(atovc >= 1.e0 && atovc <= 999999.e0) goto S1330;

S1328:
    errSs("Invalid (GENL INFO) AUSTRALIAN TAX OFFICE VENDOR NUMBER~",&K0,&irc);
    goto S1360;

S1330:
    gnliSc("READ","AUSTRALIAN TAX OFFICE LEDGER ACCOUNT",&K36,xc_cSmess,&K10,&irc);
    if(irc == 0) goto S1335;
    errSs("Must enter (GENL INFO) AUSTRALIAN TAX OFFICE LEDGER ACCOUNT~",&K0,&irc);
    goto S1360;

S1335:
    if(READ(INTERNAL,xc_cSmess,10,IOSTAT,NULL,1,FMT,F1336,1,REAL8,&atoacc,0)) goto S1338;
    if(atoacc >= 100.e0 && atoacc <= 999999.99e0) goto S1340;

S1338:
    errSs("Invalid (GENL INFO) AUSTRALIAN TAX OFFICE LEDGER ACCOUNT~",&K0,&irc);
    goto S1360;

S1340:

    gnliSc("READ","AUSTRALIAN TAX OFFICE TR TYPE",&K29,&atotyp,&K8,&irc);
    if(irc == 0) goto S1350;
    errSs("Must enter (GENL INFO) AUSTRALIAN TAX OFFICE TR TYPE~",&K0,&irc);
    goto S1360;

S1350:
    tracSc(&atotyp,acctem,&irc);
    if(irc == 0) goto S1370;
    errSs("Invalid (GENL INFO) AUSTRALIAN TAX OFFICE TR TYPE~",&K0,&irc);
    goto S1360;

S1360:
    bangSs(&irc);
    goto S9000;

S1370:
    atopay = acctem[0];                      /*ATO PAYABLE*/

    /*
     --- OUTPUT BATCH NUMBER AND EFFECTIVE DATE

    */
    soutSs("P ",&K1,&batch,&K8,&irc);
    soutSs("P ",&K2,&effout,&K8,&irc);

    nfunc = *(short*)fifstrgv("A ",2);       /* SET DEFAULT FUNCTION */
    if(nview == 1) nfunc = *(short*)fifstrgv("L ",2);/* SET DEFAULT FUNCTION FOR A CLOSED BATCH */
    fill(&trtype,&K4,"  ");                  /* INITIALIZE TRANSACTION TYPE */

S1800:
    backed = FALSE;
    protSs(&K0,&K0,&K2,&K0,&irc);            /* UNPROTECT */
    initSs(&K2,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);      /* LOAD FUNCTION */
    doutSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    posSs("REFNO ",&K5,&irc);

    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2050;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2050;
    if(icompr(&trtype,"        ",&K8) == 0 && nview == 0) posSs("TRANSACTION TYPE",&K16,&irc);

    soutSs("B ",&K3,"RETURN after entering Reference#~",&K0,&irc);

S2000:

    rdpaSs("REFNO ",&K5,&K1,&irc);           /* READ SCREEN THRU REFERENCE# */
    soutSs("C ",&K3,&K0,&K0,&ircb);          /* CLEAR MESSAGE TO 'RETURN' */
    if(irc == 0) goto S2200;
    if(irc == 4) goto S2100;
    if(irc == 8) goto S1800;
    goto S9000;

S2050:

    /*
     --- AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    rdpaSs("REFNO ",&K5,&K11,&irc);
    goto S2200;

S2100:
    errSs("Screen cannot be SAVED until data has been entered~",&K0,&irc);
    goto S2000;

S2200:
    dataSs("FUNC",&K4,&nfunc,&K1,&ircf);
    if(nfunc == *(short*)fifstrgv("L ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2250;
    if(nview == 1) goto S2230;               /* VIEWING ONLY */

    if(nfunc == *(short*)fifstrgv("A ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("C ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("D ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2250;
    errSs("Enter 'A', 'C', 'L', 'N', 'S', or 'D'~",&K0,&irc);
    goto S2240;

S2230:

    /*
     --- VIEWING ONLY ALLOWED (LIST OR NEXT) ON A CLOSED BATCH

    */
    errSs("Batch is CLOSED.  Viewing only.  Enter 'L' or 'N'~",&K0,&irc);
    goto S2240;

S2240:
    if(ircf == 0) blnkSs("FUNC",&K4,&irc);
    if(ircf != 0) starSs("FUNC",&K4,&irc);
    goto S2000;

S2250:

    /*
     --- GET REFERENCE NUMBER

    */
    dataSs("REFNO ",&K5,&refno,&K8,&irc);
    if(irc == 0) goto S2320;
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2950;/* START A 'NEXT' SERIES */
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2950;/* START A 'NEXT SAVED' SERIES */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2950;/* START A 'RE-ENTER' SERIES */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2950;/* START A 'RE-ENTER' SERIES */
    iSgref(&batch,&K0,&refno,&irc);
    if(irc != 0) goto S2310;
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    goto S2320;
S2310:
    errSs("Enter Source Document Reference#~",&K0,&irc);
    starSs("REFNO ",&K5,&irc);
    goto S2000;

S2320:

    /*
     --- CHECK FOR 'NO LEADING BLANK' IN REFERENCE#

    */
    if(icompr(&refno,"  ",&K1) != 0) goto S2330;
    errSs("Reference# must be left justified~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2330:

    /*
     --- If 'NEXT'ing thru screens, or saved screens, go to NEXT function

    */
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2950;

    /*
     --- SEE IF THIS SOURCE DOCUMENT (REFERENCE#) HAS ALREADY BEEN ENTERED

    */
    iSvref(&batch,&refno,&K0,&irc);
    if(irc == 9) goto S9000;

    if(nfunc != *(short*)fifstrgv("A ",2)) goto S2350;

    /*
     --- IF AN ITEM IS TO BE ADDED, IT SHOULD NOT BE ON FILE ALREADY

    */
    if(irc == 0) goto S2380;                 /* IT IS NOT ON FILE */
    errSs("This Reference# is already on file~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2350:

    /*
     --- IF AN ITEM IS TO BE CHANGED, DELETED, OR LISTED, IT SHOULD ALREADY BE
            ON FILE

    */
    if(irc == 1 || irc == 2) goto S2370;     /* IT IS ON FILE */
    errSs("This Reference# is not on file in this Batch~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2370:

    /*
     --- DISPLAY PREVIOUSLY ENTERED SOURCE DOCUMENT

    */
    iSdisp(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    if(irc == 2) goto S2000;                 /* WRONG INPUT SCREEN FOR THIS DOCUMENT */
    /*
    /* DOCUMENT

     --- PUT CURRENT FUNCTION BACK ON SCREEN

    */
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

S2380:
    if(nfunc == *(short*)fifstrgv("A ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("C ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("D ",2)) goto S2900;

    /*
     --- 'LIST' - LET THEM LOOK AT IT, THEN GO AGAIN...

    */
    if(irc == 0) errSs("For viewing only.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    goto S1800;

S2900:

    /*
     --- 'DELETE' - CONFIRM THAT THIS ITEM IS TO BE DELETED

    */
    errSs("RETURN to DELETE this item.  Otherwise, enter ?~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    if(irc == 8) goto S1800;

    /*
     --- DELETE THE REFERENCED ITEM FROM THIS BATCH

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    goto S1800;

S2950:

    /*
     --- Get and Display the 'NEXT' screen image

    */
    iSnext(&batch,&refno,&irc);
    if(irc <= 1) goto S2955;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S9000;/* ENND OF A 'RE-ENTER' SERIES */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S9000;/* ENND OF A 'RE-ENTER' SERIES */
    initSs(&K1,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    errSs("There are no more entries in this Batch.~",&K0,&irc);
    goto S2000;

S2955:
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2960;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2960;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2960;
    if(irc != 1) goto S2950;                 /* NOT A SAVED SCREEN */
    goto S2960;

S2960:
    iSdisp(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    if(irc == 2) goto S2970;                 /* WRONG SCREEN UP TO DISPLAY THIS ITEM */
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

    /*
     --- IF A 'RE-ENTER' SERIES IS IN PROCESS, GO TO PROCESS THIS SCREEN

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3000;

    errSs("For VIEWING only.  RETURN for next screen~",&K0,&irc);
    goto S2000;

S2970:
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    goto S2000;

S3000:

    /*
     ----------------------------------------------------------------------

         'ADD' or 'CHANGE' - PROCESS INPUT SCREEN

    */
    protSs("FUNC",&K4,&K1,&K0,&irc);
    protSs("REFNO ",&K5,&K1,&K0,&irc);

    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

    protSs("DATA ENTRY BB",&K13,&K1,&K0,&irc);

    /*
    *    CALL ERR$S ( 'Enter Payment data.~',0,IRC )
    */
    errSs("Enter Vendor, Check No, and date~",&K0,&irc);
    posSs("VENDOR",&K6,&irc);

    dataSs("VENDOR",&K6,&vendor,&K0,&irc);

    /*
     --- AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3060;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3060;

S3050:
    if(!backed) goto S3055;

    /*
    ------Make sure any 'D' records from the previous attempt are removed

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 7) irc = 0;
    if(irc != 0) goto S8200;

S3055:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* SAVE THIS SCREEN IF RE-ENTERING */
    readSs(&K1,&irc);
    if(irc == 0) goto S3100;
    if(irc == 4) goto S8050;
    if(irc == 8) goto S1800;
    goto S9000;

S3060:
    readSs(&K11,&irc);
    if(irc == 4) goto S8000;

S3100:
    dataSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    if(irc != 4) goto S3130;                 /* EMPTY FIELD */
    errSs("Enter Transaction Type~",&K0,&irc);
    starSs("TRANSACTION TYPE",&K16,&irc);
    goto S3050;

S3130:
    if(icompr(&trtype,lastyp,&K8) == 0) goto S3150;
    ttypSc(&trtype,&nbank,&irc);
    if(irc == 0) goto S3140;
    errSs("Invalid Transaction Type~",&K0,&irc);
    blnkSs("TRANSACTION TYPE",&K16,&irc);
    goto S3050;

S3140:
    mvwrd(&trtype,lastyp,&K4);
    protSs("TRANSACTION TYPE",&K16,&K1,&K0,&irc);

S3150:

    /*
     --- GET ACCOUNT NUMBERS FROM GENL$INFO

    */
    vatSac(&trtype,vatact,vatdsc,despnt,&ircvat);
    tracSc(&trtype,accts,&irc);
    if(irc != 0) goto S3160;
    /*
         APGL   = ACCTS(1)
    */
    apglcd = accts[0];
    apgldc = accts[1];
    dscern = accts[6];
    if((apglcd != 0.e0 || apgldc != 0.e0) && dscern != 0.e0) goto S3170;

S3160:
    ferrSc(&K9999,&K10,"Use TR ACCOUNT to establish ledger accounts for A/P~",&K0);

S3170:

    /*
     --- GET VENDOR (PAYEE) NUMBER

    */
    dataSs("VENDOR",&K6,&vendor,&K0,&irc);
    if(irc == 0) goto S3220;
    errSs("Enter Vendor #~",&K0,&irc);
    starSs("VENDOR",&K6,&irc);
    goto S3050;

S3220:

    /*
     --- VALIDATE VENDOR NUMBER AGAINST VENDOR/CLIENT ROSTER

    */
    vinfSc(&vendor,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    if(irc == 0) goto S3240;
    errSs("Vendor not on Vendor/Client Roster~",&K0,&irc);
    blnkSs("VENDOR",&K6,&irc);
    goto S3050;

S3240:
    soutSs("P ",&K3,ivname,&K30,&irc);

    /*
     ----See if this vendor is domestic or foreign

    */
    vinfSc(&vendor,"    ","FOREIGN ",&K7,&ifor,&K2,&K0,&K0,&irc);
    fordom = 1;                              /* Domestic */
    if(ifor == *(short*)fifstrgv("X ",2)) fordom = 2;/* Foreign */

    /*
     --- GET CHECK NUMBER

    */
    dataSs("CHECKNO ",&K8,&chckno,&K8,&irc);
    if(irc == 0) goto S3320;
    errSs("Enter Check #~",&K0,&irc);
    starSs("CHECKNO ",&K7,&irc);
    goto S3050;

S3320:

    /*
     --- CHECK IF BANK CASH ACCOUNT HAS BEEN SET UP & CHECK# IS VALID

    */
    taccSc(&chckno,&dummy,&cash,&irc);
    if(irc == 0) goto S3350;
    blnkSs("CHECKNO ",&K7,&irc);
    goto S3050;

S3350:

    /*
         Get check date

    */
    mdySc("G ","CHECK ",&K5,&chkdat,&dummy,&irc);
    if(irc == 0) goto S3430;                 /* GOT A CHECK DATE */
    blnkSs("YEAR CHECK",&K10,&irc);
    blnkSs("DAY CHECK ",&K9,&irc);
    blnkSs("MONTH CHECK ",&K11,&irc);
    errSs("Invalid Check Date~",&K0,&irc);
    goto S3050;

S3430:

    /*
         Do not allow a check to be voided with a date earlier than the
            date the check was issued

    */
    if(chkdat <= effdat) goto S3435;

    blnkSs("YEAR CHECK",&K10,&irc);
    blnkSs("DAY CHECK ",&K9,&irc);
    blnkSs("MONTH CHECK ",&K11,&irc);
    WRITE(INTERNAL,xc_cSmess,80,FMT,F3431,1,0);
    errSs(xc_cSmess,&K80,&irc);
    goto S3050;

S3435:

    /*
    ------Find cash disbursements for this Vendor in JOURNALS

    */
    protSs("DATA ENTRY BB",&K13,&K2,&K0,&irc);
    protSs("VENDOR",&K6,&K1,&K0,&irc);

    ersSs("DATA ENTRY BB",&K13,&irc);

    fill(keyj,&K32,"  ");
    WRITE(INTERNAL,keyj,12,FMT,F3455,1,DO,2,INT2,xc_cScoid,REAL8,chkdat,0);

    mflag = FLSNXT+FLSUKY;

    mvwrd(keyj,keysav,&K32);

    /*
         Initialize total to be used to accumulated distribution of
            net amount of check

    */
    tamnt = 0.e0;
    ib = 0;
    xpScom1_nscdat = 0;
    backed = FALSE;

S3458:

    /*
         Initialize blackboard row counter

    */
    more = FALSE;
    xbb_jsetSb = 0;
    xbb_lsetSb = xbb_jsetSb;

S3460:
    if(more) goto S3550;                     /*  Deal with first 300, then come back */
    ioSf("NEXT","JOURNALS",&K8,"    ",keyj,&K64,&mflag,&K0,&irc);
    if(irc == 7) goto S3550;
    if(icompr(keyj,keysav,&K12) != 0) goto S3550;

    /*
         Is this a "Cash Disbursement" entry

    */
    dataSf("GET ","JOURNALS",&K8,"    ","SOURCE JOURNAL",&K14,&icd,&K2,&K0,&K0,&irc);
    if(irc != 0 || icompr(&icd,"CD",&K2) != 0) goto S3460;

    dataSf("GET ","JOURNALS",&K8,"    ","CHECK#/DEPOSIT#",&K15,check,&K8,&K0,&K0,&irc);
    if(icompr(check,&chckno,&K8) != 0) goto S3460;

    dataSf("GET ","JOURNALS",&K8,"    ","V/C NUMBER",&K10,&vend,&K0,&K0,&K0,&irc);
    if(iameq(&vend,&vendor) != 0) goto S3460;

    /*
         Check matches, get pertinent data

    */
    dataSf("GET ","JOURNALS",&K8,"    ","$AMOUNT ",&K7,&amnt,&K0,&K0,&K0,&irc);
    if(iameq(&amnt,&R1) == 0) goto S3460;

    /*
         Accumulate net amount of check to be voided

    */
    tamnt = tamnt+amnt;

    /*
         If memo indicates that this Cash Disbursements journal entry
            is a Discount, then this amount is a discount applied to
            last prior distribution for the current check

    */
    dataSf("GET ","JOURNALS",&K8,"    ","JOURNAL MEMO",&K12,memdsc,&K8,&K0,&K0,&irc);
    if(icompr(memdsc,"Discnt: ",&K8) == 0) goto S3480;

    xbb_jsetSb = xbb_jsetSb+1;
    if(xbb_jsetSb == 300) more = TRUE;

    xbb_lsetSb = xbb_jsetSb;

    dataSf("GET ","JOURNALS",&K8,"    ","TRANSACTION CODE",&K16,&itcode[xbb_lsetSb-1],&K2,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","JOB ",&K3,&rj,&K0,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","PHASE ",&K5,&rp,&K0,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","COMMITMENT ID",&K13,&commit,&K8,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","INVOICE#",&K8,cinv,&K8,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","INVOICE COMPONENT",&K17,&invcmp[xbb_lsetSb-1],&K2,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","DATE EFFECTIVE",&K14,&effinv[xbb_lsetSb-1],&K0,&K0,&K0,&irc);

    dataSf("GET ","JOURNALS",&K8,"    ","DATE INVOICE",&K12,&datinv[xbb_lsetSb-1],&K0,&K0,&K0,&irc);

    fill(iactiv,&K5,"  ");
    if(ipbya != *(short*)fifstrgv("Y ",2)) goto S3465;
    dataSf("GET ","JOURNALS",&K8,"    ","ACTIVITY",&K8,iactiv,&K10,&K0,&K0,&irc);
S3465:

    /*
         Output information to screen fields

    */
    rjp = combjp(&rj,&rp);
    WRITE(INTERNAL,iobuff,9,FMT,F3467,1,REAL8,rjp,0);
    doutSs("JOBPH ",&K5,iobuff,&K9,&irc);

    if(ipbya == *(short*)fifstrgv("Y ",2)) doutSs("ACTIV ",&K5,iactiv,&K10,&irc);

    doutSs("COMMIT",&K6,&commit,&K8,&irc);

    doutSs("INVOICE ",&K7,cinv,&K8,&irc);

    WRITE(INTERNAL,xc_cSmess,12,FMT,F3475,1,REAL8,amnt,0);
    doutSs("AMOUNT",&K6,xc_cSmess,&K12,&irc);

    goto S3460;

S3480:

    /*
         Output amount of discount to current distribution row on screen
            (Do not increment JSET$B)

    */
    discnt = -amnt;                          /* reverse sign for display */

    WRITE(INTERNAL,xc_cSmess,8,FMT,F3485,1,REAL8,discnt,0);
    doutSs("DISCOUNT",&K8,xc_cSmess,&K8,&irc);

    goto S3460;

S3550:

    if(tamnt != 0) goto S3560;
    errSs("Check not found~",&K0,&irc);
    goto S3050;

S3560:

    /*
         Put total net amount of check to be voided on screen

    */
    WRITE(INTERNAL,xc_cSmess,12,FMT,F3565,1,REAL8,tamnt,0);
    doutSs("NET ",&K3,xc_cSmess,&K12,&irc);

    /*
     --- ENCODE PPS MEMO

    */
    WRITE(INTERNAL,mempps,16,FMT,F3570,1,REAL8,vendor,0);

    ppsdue = 0.e0;
    mvbyt("N/APPLICABLE",icert,&K12);


    /*
     ----------------------------------------------------------------------

    */
    if(xbb_lsetSb == 0) goto S4995;          /*  May happen on subsequent pass(MORE) */
    for(i=1,D6=(D6=(xbb_lsetSb-i+1))>0?D6:1; D6>0; D6--,i+=1)
    {

        xbb_jsetSb = i;

        /*
         set transaction code, account

        */
        if(icompr(&itcode[i-1],"DC",&K2) == 0) goto S4100;
        trcode = *(double*)fifstrgv("CD",2); /* trade cash disbursement */
        apgl = apglcd;
        goto S4110;

S4100:
        trcode = *(double*)fifstrgv("DC",2); /* sub payment */
        apgl = apgldc;
S4110:

        WRITE(INTERNAL,code,8,FMT,F4120,1,REAL8,trcode,INT2,invcmp[i-1],0);

        dataSs("AMOUNT",&K6,&amount[i-1],&K0,&irc);
        if(irc == 4) goto S4990;
        amount[i-1] = -amount[i-1];

        /*
               GET DISCOUNT, IF ANY

        */
        dataSs("DISCOUNT",&K8,&discnt,&K0,&irc);
        discnt = -discnt;                    /* reverse sign from display */

        /*
         ---   GET JOB/PHASE NUMBER

        */
        dataSs("JOBPH ",&K5,&rjobph[i-1],&K0,&irc);
        if(irc == 0) goto S4320;
        errSs("Enter Job #~",&K0,&irc);
        starSs("JOBPH ",&K5,&irc);
        goto S3050;
S4320:
        if(rjobph[i-1] == fifdint(rjobph[i-1])) rjobph[i-1] = rjobph[i-1]+.01e0;


        /*
             GET INVOICE NUMBER, IF APPLICABLE FOR THIS LINE

        */
        dataSs("INVOICE ",&K7,&rinv[i-1],&K8,&irc);
        if(irc == 0) goto S4360;
        errSs("Enter Invoice#~",&K0,&irc);
        starSs("INVOICE ",&K7,&irc);
        goto S3050;

S4360:

        /*
             Get the COMMIT ID

        */
        dataSs("COMMIT",&K6,&commit,&K8,&irccom);

        /*
             Get activity

        */
        dataSs("ACTIV ",&K5,&activ[i-1][0],&K10,&irc5);
        if(irc5 == 0 && ipbya == *(short*)fifstrgv("Y ",2)) goto S4430;
        if(irc5 != 0 && ipbya != *(short*)fifstrgv("Y ",2)) goto S4430;
        errSs("Enter an activity~",&K0,&irc);
        blnkSs("ACTIV ",&K5,&irc);
        goto S3050;

S4430:
        rjob = fifdint(rjobph[i-1]);
        phase = fifdint(1.e2*(rjobph[i-1]-rjob)+.0001e0);
        len = 40;
        if(ipbya != *(short*)fifstrgv("Y ",2)) len = 30;
        idash = icompr(&activ[i-1][0],"-         ",&K10);
        if(idash == 0) len = 30;
        if(idash != 0) frmaSc(&rjob,&phase,&activ[i-1][0],&irc);
        if(idash != 0) doutSs("ACTIV ",&K5,&activ[i-1][0],&K10,&irc);

        /*
         ----------------------------------------------------------------------

         --- VALIDATE PPS AMOUNT

        */
        if(iswpps == 0) goto S4700;

        ppsamt[i-1] = 0.e0;
        dataSs("PPS ",&K3,&ppsamt[i-1],&K0,&ircSs);
        if(ircSs == 1) goto S4700;           /* FIELD NOT ON SCREEN */

        ppstax(&vendor,&effinv[i-1],&ppsrat,icert,&irc);
        if(iameq(&ppsrat,(T2= -1.e0,&T2)) == 0) mvbyt("N/APPLICABLE",icert,&K12);

        if(iameq(&ppsamt[i-1],&R1) == 0 && iameq(&ppsrat,(T3= -1.e0,&T3)) == 0) goto S4700;

        if(iameq(&ppsamt[i-1],&R1) != 0 && iameq(&ppsrat,(T4= -1.e0,&T4)) == 0) goto S4690;/* ERROR */

        ppstmp = amount[i-1]*(ppsrat*.01e0);
        ppstmp = rndoff(&ppstmp,&K0);

        if(iameq(&ppsamt[i-1],&ppstmp) == 0) goto S4700;

        /*
         --- PPS WARNING

        */
        errSs("WARNING *** PPS Amount is incorrect for the current PPS rate~",&K0,&irc);
        blnkSs("PPS ",&K3,&irc);
        bangSs(&irc);
        rstSs("PPS ",&K3,&irc);
        if(irc == 0) goto S4700;
        if(irc == 8) goto S3050;
        goto S1800;

S4690:

        /*
         --- PPS ERROR (PPS NOT APPLICABLE)

        */
        errSs("ERROR *** PPS Not Applicable for this Creditor~",&K0,&irc);
        blnkSs("PPS ",&K3,&irc);
        goto S3050;

S4700:

        /*
         ----------------------------------------------------------------------

        ------See if buffer is dangerously full

        */
        if(ib < MAXSCD-1000) goto S4704;

        /*
        ------If we have not yet BACKED up this reference this is the time to do it

        */
        if(backed) goto S4703;

        backed = TRUE;
        if(nfunc == *(short*)fifstrgv("A ",2)) goto S4703;

        iSback("BACK",&batch,&refno,&irc);
        if(irc != 0) goto S9000;

        iSdlet(&batch,&refno,&irc);

S4703:
        xpScom1_nscdat = xpScom1_nscdat+1;
        iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
        ib = 0;

S4704:

        xc_cSrow = i;

        ib = ib+1;
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("\\\\      ",8);/* Group Separator */
        xpScom1_pSscdt[ib] = 1.e0;           /* Version */
        xpScom1_pSscdt[ib+1] = i;            /* Group Number */
        xpScom1_pSscdt[ib+2] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+3] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+4] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+5] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+6] = 0.e0;         /* Reserved for future use */
        ib = ib+7;

        /*
         ---   PACK THIS LINE ITEM INTO SCREEN DATA BUFFER

        */
        ib = ib+1;

        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* TRADE PAYMENT (CASH DISBURSEMENT) */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION NUMBER */
        xpScom1_pSscdt[ib+2] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
        xpScom1_pSscdt[ib+4] = vendor;
        xpScom1_pSscdt[ib+5] = rjob;
        xpScom1_pSscdt[ib+6] = phase;
        mvwrd(&activ[i-1][0],&xpScom1_pSscdt[ib+7],&K5);
        xpScom1_pSscdt[ib+9] = commit;       /* COMMITMENT */
        xpScom1_pSscdt[ib+10] = rinv[i-1];   /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+11] = datinv[i-1]; /* INVOICE DATE */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF VOID */
        xpScom1_pSscdt[ib+13] = effinv[i-1]; /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+14] = amount[i-1]; /* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+15] = ppsamt[i-1]; /* PPS AMOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* DISCOUNT ALLOWED */
        xpScom1_pSscdt[ib+17] = apgl;        /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+18] = cash;        /* CREDIT ACCOUNT */
        xpScom1_pSscdt[ib+19] = apgl;        /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+20] = cash;        /* CREDIT ACCOUNT */
        fill(&xpScom1_pSscdt[ib+21],&K8,"  ");
        xpScom1_pSscdt[ib+23] = chckno;
        mvbyt(icert,&xpScom1_pSscdt[ib+24],&K12);/*  PPS CERTIFICATE */

        ib = ib+26;

        /*
             VOID DISCOUNT TAKEN, IF ANY

        */
        if(fabs(discnt) < .001e0) goto S4720;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        dscjob = xc_cSdacj;
        dscphs = xc_cSdacp;
        fill(dscact,&K5,"  ");

        /*
             for NZ use the actual job, phase and activity and not the default

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2)) goto S4710;
        dscjob = rjob;
        dscphs = phase;
        mvwrd(&activ[i-1][0],dscact,&K5);
S4710:

        jinfSc(&rjob,&phase,"JC  ","DISCOUNT ACTIVITY",&K17,iactiv,&K10,&K0,&K0,&irc);
        if(irc != 0) goto S4715;
        if(icompr(iactiv,"          ",&K10) == 0) goto S4715;

        /*
             FIX FORMAT OF DISCOUNT ACITIVITY

        */
        frmaSc(&rjob,&phase,iactiv,&irc);

        dscjob = rjob;
        dscphs = phase;
        mvbyt(iactiv,dscact,&K10);

S4715:
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("CD      ",8);/* CASH DISBURSEMENT */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vendor;
        xpScom1_pSscdt[ib+4] = dscjob;
        xpScom1_pSscdt[ib+5] = dscphs;
        mvwrd(dscact,&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = *(double*)fifstrgv("-       ",8);/* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = 0.e0;        /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE OF VOID */
        xpScom1_pSscdt[ib+12] = 0.e0;        /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = -discnt;     /* AMOUNT OF DISCOUNT VOIDED */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* PPS AMOUNT */
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT JOB ACCOUNT (DISCOUNTS EARNED) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = dscern;      /* DEBIT ACCOUNT (DISCOUNTS EARNED) */
        xpScom1_pSscdt[ib+18] = cash;        /* CREDIT ACCOUNT (CASH) */
        mvwrd("Discnt: ",&xpScom1_pSscdt[ib+19],&K4);/* PUT INVOICE ON WHICH DISCOUNT */
        mvwrd(&invoic,&xpScom1_pSscdt[ib+20],&K4);/* WAS EARNED IN MEMO */
        xpScom1_pSscdt[ib+21] = chckno;      /* CHECK NUMBER */

        ib = ib+22;

S4720:

        /*
        -----------------------------------------------------------------------

         --- See if PPS withholding (Australian Tax Office) is applicable

        */
        if(icompr(icert,"N/APPLICABLE",&K12) == 0) goto S4990;
        /*
         no...        /* no...

         --- GET PPS DUE DATE

        */
        ppsdue = effinv[i-1];
        nxtmo(&ppsdue,&irc);
        ppsdue = ppsdue+8.e0;

        /*
         --- Pack reduction of cash disbursement to vendor in amount of PPS withholding

        */
        ib = ib+1;
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("CD      ",8);/* TRADE PAYMENT (CASH DISBURSEMENT) */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION NUMBER */
        xpScom1_pSscdt[ib+2] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
        xpScom1_pSscdt[ib+4] = vendor;
        xpScom1_pSscdt[ib+5] = rjob;
        xpScom1_pSscdt[ib+6] = phase;
        mvwrd(&activ[i-1][0],&xpScom1_pSscdt[ib+7],&K5);
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("-       ",8);/* COMMITMENT */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("*PPS    ",8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+11] = datinv[i-1]; /* INVOICE DATE */
        xpScom1_pSscdt[ib+12] = chkdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+13] = effinv[i-1]; /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+14] = -ppsamt[i-1];/* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+15] = 0.e0;        /* PPS AMOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* DISCOUNT ALLOWED */
        xpScom1_pSscdt[ib+17] = apgl;        /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+18] = cash;        /* CREDIT ACCOUNT */
        xpScom1_pSscdt[ib+19] = apgl;        /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+20] = cash;        /* CREDIT ACCOUNT */
        fill(&xpScom1_pSscdt[ib+21],&K8,"  ");
        xpScom1_pSscdt[ib+23] = chckno;      /*  CHECK NUMBER */
        mvbyt("N/APPLICABLE",&xpScom1_pSscdt[ib+24],&K12);/* PPS certificate buffer */
        ib = ib+26;

        /*
             Pack invoice on account of the Australian Tax Office in
             the amount of PPS withholding from vendor

        */
        ib = ib+1;
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P       ",8);/* PURCHASE */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&atotyp,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = atovc;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activ[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = *(double*)fifstrgv("-       ",8);/* COMMITMENT */
        xpScom1_pSscdt[ib+9] = chckno;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = chkdat;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = ppsdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = ppsamt[i-1]; /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT */
        xpScom1_pSscdt[ib+15] = atoacc;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = atopay;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = atoacc;      /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = atopay;      /* CREDIT ACCOUNT */
        mvbyt(mempps,&xpScom1_pSscdt[ib+19],&K16);

        ib = ib+21;

        /*
         --- Pack Debit Memo (negative invoice) on account of vendor to
             record transfer of payment obligation to the Australian Tax Office

        */
        ib = ib+1;
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P       ",8);/* TRADE PURCHASE */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vendor;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activ[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = *(double*)fifstrgv("-       ",8);/* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("*PPS    ",8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = chkdat;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = ppsdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = -ppsamt[i-1];/* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT */
        xpScom1_pSscdt[ib+15] = atoacc;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = apgl;        /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = atoacc;      /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = apgl;        /* CREDIT ACCOUNT */
        mvbyt(mempps,&xpScom1_pSscdt[ib+19],&K16);

        ib = ib+21;

        goto S4990;

S4990:;
    }

S4995:
    if(more) goto S3458;                     /*  Go back for next gulp */


    /*
     ----------------------------------------------------------------------

     --- GET CONFIRMATION BEFORE POSTING ITEM

    */
    rstSs(&K0,&N1,&irc);                     /* UNBLINK ANY BLINKING FIELDS */
    elnsSb(&N1,&icg,&jfunc);

    if(nfunc == *(short*)fifstrgv("R ",2)) goto S7920;/* DON'T STOP ON 'RE-ENTER' */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S7920;/* DON'T STOP ON 'RE-ENTER' */

    errSs("Good entry.  RETURN to continue.  Otherwise, enter ^~",&K0,&irc);
    posSs("COM ",&K3,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7500;
    if(irc == 4) goto S8000;
    goto S8200;

S7500:

    /*
     ---  IF THIS IS A CHANGE, DELETE PRIOR VERSION OF THIS ITEM

    */
    if(nfunc != *(short*)fifstrgv("C ",2)) goto S7950;

S7920:
    if(xpScom1_nscdat > 0) goto S7950;

    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;

S7950:

    /*
     --- SAVE IMAGE OF INPUT SCREEN

    */
    iSsave(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    /*
     --- SAVE DATA FROM SCREEN

    */
    xpScom1_nscdat = xpScom1_nscdat+1;
    iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
    ib = 0;
    if(irc != 0) goto S9000;

    if(backed) iSback("DLET",&batch,&refno,&irc);

    goto S1800;

S8000:

    /*
     --- SAVE screen image of a BAD entry screen

    */
    nread = 1;                               /* set flag to read current screen image */
    goto S8100;

S8050:
    nread = 0;                               /* reset flag - don't read  screen image */
    goto S8100;

S8100:

    /*
     --- delete all previous references to this Batch#/Reference#

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 7) irc = 0;
    if(irc != 0) goto S9000;

    /*
     --- SAVE image of BAD screen in INPUT$BATCHES

    */
    iSbad(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    if(backed) iSback("DLET",&batch,&refno,&irc);

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8120;/* DON'T STOP ON RE-ENTER */
    errSs("Screen SAVED for later use.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);

S8120:
    if(irc == 0) goto S1800;
    goto S9000;

S8200:
    if(!backed) goto S1800;

    /*
    ------Restore backed Up copy of this reference

    */
    iSback("REST",&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    goto S1800;

S9000:
    if(backed) iSback("REST",&batch,&refno,&irc);
    fileSc("CLO ",&K32,&K0,&K0,&K0,&irc,0);
    fileSc("CLO ",&K33,&K0,&K0,&K0,&irc,0);

    return;

}
/*

-----------------------------------------------------------------------

     GMT November 22, 1989 10:26:56    JEN-0042

     Correct call to PPSTAX by moving it after read of AP record so the
     invoice date will be available to PPSTAX

-----------------------------------------------------------------------

     DLP January 19, 1990 10:50:40    NIC-0030

     Allow a Zero check amount without validating the invoice number,
     this will allow users to Void checks.

-----------------------------------------------------------------------

     DLP May 17, 1990 15:03:24    LEH-0044

     Modified program to get VAT from the input screen if it exists
     as a sperate amount from the Invoice amount for this check.
     If VAT is entered, pack VAT with an Invoice component of 'V'
     so it will be posted as VAT paid to a creditor to relieve VAT
     payable in AP/AR$MASTER, and post VAT paid in COMMITMENT$MASTER.

-----------------------------------------------------------------------

     DLP June 8, 1990 08:56:40    OLY-0011

     Added call to VCOM$C to display warning to user if the commitment
     is over billed.

-----------------------------------------------------------------------

     DLP June 19, 1990 11:01:00    PRO-0097

     Added a call to APAR$C with INVCMP = "**" to return the Invoice Balance
     in BAL$A(1).  Check to see if this payment amount exceeds the
     remaining balance, if so then warn the user.

-----------------------------------------------------------------------

     DLP June 27, 1990 14:04:44    PRO-0097

     Added a second call to APAR$C to find the total Invoice Balance
     when the line items are against different jobs.

-----------------------------------------------------------------------

     DLP September 12, 1990 15:10:28    BUG FIX

     Fixed the KEY to AP/AR$MASTER to be 64 bytes.

-----------------------------------------------------------------------

     DLP September 24, 1990 14:40:32    SCO-0038

     Added test to see if VATAMT(I) .EQ. 0D0 and to not pack
     vat amount as a data set if it is zero.

-----------------------------------------------------------------------

     DLP March 13, 1991 08:56:40    NIC-0074

     Commented out call to VALD$C to allow payments to Closed Jobs.

-----------------------------------------------------------------------

     DLP May 1, 1991 15:08:36    EDL-0069

     Added code to support extended VAT accounting.

           1)  Added call to VINF$C for "FOREIGN" vendor type
           2)  Added call to VAT$AC to get Vat Accounts
           3)  Added new sections to Packk accounting entries when
               paying VAT with Invoice Components of VF VG and VS

-----------------------------------------------------------------------

     GEL May 13, 1991 12:16:40    CAL-0023

     Added a check date field which overrides the batch effective date
     when entered.

-----------------------------------------------------------------------

     GEL May 20, 1991 12:01:40    FRU-0110

     Added check for a return code of 4 after READ$S which is executed
     by express reenter and the BATCH REENTER report.  This is code
     signifies an SCFM validation error and thus saves the screen image.

-----------------------------------------------------------------------

     DLP February 6, 1992 16:22:56    EDL-0099

     Added code to allow Payment of an Invoice by Invoice Component.

-----------------------------------------------------------------------

     DLP July 24, 1992 10:06:28    JEN

     Modified call to VCOM$C to include a new argument, IMODE.
     IMODE can equal 'B ' or 'P '
     B = test for billed amount exceeds commitment
     P = test for Paid amount exceeds commitment

-----------------------------------------------------------------------

     DLP May 11, 1993 19:14:12    LMA

     Added a call to DOUT$S to display the COMMIT ID on each line
     of distribution.

-----------------------------------------------------------------------

     DLP May 17, 1993 15:56:40    LMA-0009

     Added ability to enter the COMMIT ID on each line of distribution
     if the input field exists on the screen.  If the COMMIT ID is keyed in
     then the COMMIT ID is used to qualify the AP/AR$MASTER record which
     is searched for to validate the payment.
     Also added 16 display fields for displaying the COMMIT ID which
     was found on the AP/AR$MASTER record for this payment. The display fields
     [21,,,,] to [36,,,,]  are used for lines of distribution 1 to 16.
     If these fields are not on the screen then the program behaves
     as before.

-----------------------------------------------------------------------

     GEL February 16, 1994 13:04:36    DFZ-0001

     Eliminate FORTRAN Writes to the user terminal.

-----------------------------------------------------------------------

     DLP July 22, 1994 14:01:28    HBZ-0330

     Changed calls to FACT$C to calls to FRMA$C

-----------------------------------------------------------------------

     DLP October 18, 1995 09:35:48    MCI-0052

     Modified to allow a scrolling input screen of up to 300 lines.
     Also, look-up the payables for the Vendor, qualified by
     Job/Phase/Invoice Number/Commit ID
     Allow the user to PAY IN FULL with an X in the box.

-----------------------------------------------------------------------

     DLP November 6, 1995 08:24:36    PRO

     Modified to read the VENDOR, JOB, PHASE, INVOICE, COMMIT ID
     from the top of the screen before allowing input in the
     window.  Save the values of the fields at the top to see if
     the user changes the selection criteria.  If the selection criteria
     changes then clear the window and re-display the selected
     Invoices for payment distribution.

-----------------------------------------------------------------------

     DLP November 22, 1995 09:56:40    SMI-0056

     Added code to pack a Group Separator between each transaction

-----------------------------------------------------------------------

     DLP January 15, 1996 15:01:40    HBZ-0364

     Set C$ROW to the current row of distribution.

-----------------------------------------------------------------------

     GEL May 22, 1996 14:21:00    HBZ

     Modified to not ignore invoice amounts less than zero.

-----------------------------------------------------------------------

     GEL May 23, 1996 16:15:56    HBZ

     Correct problem where screen would output amount to be paid from the
     previous reference when the Pay in Full filed was filled in.

-----------------------------------------------------------------------

     RDS August 6, 1996 08:41:56    LML

     Fix a bug that caused "French" VAT processing to occur when operating
     with a "UK" country code.  This bug was a by-product of the enhancement
     that was made May 1, 1991.

-----------------------------------------------------------------------

     GEL May 02, 1997 12:42:40    ADM-1250

     Eliminate free formatted DECODEs.  Such a DECODE on a blank buffer
     could produce undesirable results.

-----------------------------------------------------------------------

     GEL May 20, 1997 11:05:41    KFA

     Modify to exclude invoices with zero amounts.

-----------------------------------------------------------------------

     RDS January 15, 1998 11:33:18    VEN-0001

     When calling up invoices, pay attention to AP/AR$MASTER records
     that have an invoice component "B" for backcharge as well as " ".
     Prior to now s-trinvoice.ftn was allowing entries to be posted
     to AP/AR$MASTER with a "B" for invoice component.

-----------------------------------------------------------------------

     SCB February 26, 1998 13:12:36    DEV

     Added capability to read either the new 58 byte key or old 52 byte key
     COMMITMENT$MASTER file. If applicable, changed the date format in the C$M
     key to handle an 8 char date field.

-----------------------------------------------------------------------

     RDS April 02, 1998 13:13:53    PRO

     Change code that identifys when to lookup information
     from AP/AR$MASTER vs leaving previously looked up info
     intack.  Prior to this change it was difficult to recover
     from validation problems without starting over.

-----------------------------------------------------------------------

     RDS April 03, 1998 08:29:43    PRO

     Multi "D" record references were not being handled correctly
     on a reenter.

-----------------------------------------------------------------------

     RDS April 23, 1998 15:11:07    OCJ/JRT

     When looking up invoices to pay, allow any invoice component to
     trigger a call to APAR$C and set KEYAP(32) to 'zz' so that we
     don't get the same item more than once.

-----------------------------------------------------------------------

     DBS July 27, 1998 17:22:57    PRO0012

     initial version (from tr trade payment)

-----------------------------------------------------------------------

     DBS January 12, 1999 08:39:21    pro0012

     added check for vendor match

-----------------------------------------------------------------------

     CJO February 19, 1999 15:59:38    PRO

     General source file cleanup; assumes this version is
     now Y2K compliant and has no need to consider 2 vs 4
     digit years.  The edits include :
       Delete/modify code assuming NEWLAB, NEWC$M and NEWL$D
       are all true.
       Delete LOGICAL Y2K and associated tests and date
       conversions.
       Delete comments having /VAX/PRIME/POSIX notes

-----------------------------------------------------------------------

     GEL May 19, 1999 15:40:43    BCK

     If the number of detail lines exceeds 300 (the capacity of a
     scrolling black board) set the line count to 300 and continue
     processing.  You can't look at more than the first 14 lines
     anyway so why bother complaining and stopping.

-----------------------------------------------------------------------

     GEL May 21, 1999 14:40:24    BCK

     Allow for voiding of a check that contains more than 300 lines
     of detail.  This involves processing the first 300 lines then
     going back and getting the next gulp of entries.

-----------------------------------------------------------------------

     SCB June 21, 1999 13:06:18    MA-0070

     Added capability to post zero GST values for MAI for tax reporting
     purposes.

-----------------------------------------------------------------------

     SCB June 22, 1999 09:16:30    MAI-0070

     Deleted extranous information to allow for compilation

-----------------------------------------------------------------------

     SCB March 02, 2000 09:53:31    BEC-0017

     Added AZ to the GST zero value calculation.

-----------------------------------------------------------------------

     SCB March 02, 2000 10:03:36    BEC-0017

     Misspelled nation code AU in previous comment.  Actually added Australia
     to the zero calculation GST by adding the AU nation code to every
     comparison that tests for the NZ nation code.

-----------------------------------------------------------------------

     RDS June 21, 2000 09:56:12    TIC-0146

     Changes to support the addition of "ACCOUNT" (debit job account)
     to the COMMITMENT$MASTER file.

-----------------------------------------------------------------------

     CJO September 14, 2000 12:30:50    PRO

     Revise output of amount to be formatted for consistent display
     and alignment of decimal points

-----------------------------------------------------------------------

     RDS April 17, 2003 15:50:05    ROS/TCT/GMT

     Correct a bug in this program that caused only the first row of
     detail input to be packed up in the "D" record when processed
     by the "R" funtion.  Also remove some dead code.

-----------------------------------------------------------------------

     DBS September 15, 2003 09:36:40    ROS

     Increased format to output NET to screen.

-----------------------------------------------------------------------

     DBS May 07, 2004 10:30:27    VIC

     Modified check for matching VENDOR to not complain and stop when
     non-matching VENDOR is encountered in JOURNALS. The offending journal
     record will not be processed.

-----------------------------------------------------------------------

     GEL October 12, 2005 11:36:38    PT6-0006

     Recode all calls to POUT$S so that "row" and "column" position
     references are eliminated.

-----------------------------------------------------------------------

     RDS March 20, 2008 10:23:30    GMT/BEC

     Correct the problem reported by Becton whereby GST is not properly
     voided via "TR VOID CHECK".

-----------------------------------------------------------------------

     GEL August 29, 2012 16:18:08    KIR

     Correct situation where the wrong Cost Center would sometimes
     be used for posting discounts.

     Correct the activity used for posting discounts, was previously
     posting garbage.

-----------------------------------------------------------------------

     GEL June 20, 2013 11:56:43    ACC-0000

     Correct comparison of vendor number so as to only select
     vendors associated with the check.  References ticket:78

*/
