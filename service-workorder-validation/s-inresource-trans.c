#define LPROTOTYPE
#define PRIMELIB
#include "fortran.h"
#include "parm_k.h"
#include "sc_com1.h"
#include "sc_com2.h"
#include "sf_com2.h"
#include "iobuf_f.h"
#include "cmis_com.h"
#include "black_board_insert.h"
#include "big_memory.h"
#include "p_post_com_batch.h"
#include "billing_com.h"
#include "shared_com.h"
/*
-----------------------------------------------------------------------
     RDS 05/22/98

     This program drives the "IN RESOURCE TRANS" selection, which records
     Resource transfers Via "BATCH CLOSE".

*/


#include "libutil.h"
#include "libpost.h"
#include "libscr.h"
#include "libbb.h"
void in5250(void)
{
static short D2;
static short D6;
static short D8;
static short D10;
static short D12;
static short K10 = 10;
static short K0 = 0;
static short K8 = 8;
static short K16 = 16;
static short K20 = 20;
static short N1 = -1;
static short K2 = 2;
static short K1 = 1;
static short K5 = 5;
static short K4 = 4;
static short K15 = 15;
static short K13 = 13;
static short K14 = 14;
static short K12 = 12;
static short K80 = 80;
static short K17 = 17;
static short K9 = 9;
static short K30 = 30;
static short K11 = 11;
static short K6 = 6;
static short K7 = 7;
static double R3 = 0.e0;
static double R4 = 0.01e0;
static short K3 = 3;
static short K25 = 25;
static short K18 = 18;
static short K24 = 24;
static short duplxS;                         /* DUPLEX PRIMOS FUNCTION */
static short cpShlp[8];                      /* NAME USED FOR HELP REQUESTS IN SCFM */
static short cpSfid;                         /* CP$CTL FIELD INDEX */
static double pSldep;
static short bSeqfn[5];
static short filelS;

static double accinv[10];
static double entity[10][6];
static double rmrkup[5][3];

static short key[32];
static short keysav[32];
static short keyi[32];
static short keyr[32];
static short keyii[32];
static short id[4];
static short lfd[16];
static short idate[4];
static short ifldna[16];
static short itime[6];
static short marray[14];
static short locatn[8];
static short invtyp[4];
static short ires[8];
static short iract[5];
static short iactto[5];
static short iacttx[5];
static short jrnkey[10];
static short ivname[15];
static short loctax[20];
static short ioamnt[6];
static short jmemo[8];

static unsigned short backed;
static unsigned short lsmall;
static short nfunc;
static short nview;
static double batch;
static double effdat;
static double effout;
static short irc;
static short iqtyfl;
static short iactfl;
static double scSpff;
static short iprdfl;
static double rjobr;
static short ircf;
static double refno;
static double phsr;
static short jbtyfr;
static double vcno;
static short ircx;
static double dateff;
static double rjobto;
static double phsto;
static short jbtyto;
static double rinv;
static double tovcno;
static short i;
static short npass;
static short jset;
static double qtytrn;
static double uprice;
static short ircupr;
static short ircra;
static double rjacct;
static short ircdja;
static short ircda;
static short irca;
static double djacct;
static double dtjacc;
static double rlacct;
static double dlacct;
static double dtlacc;
static double expric;
static double totamt;
static double fact;
static double amnt;
static double djmacc;
static double dlmacc;
static short itaxit;
static double taxcod;
static double taxrat;
static double staxrt;
static double utaxrt;
static short noe;
static double usetax;
static short idum;
static short ib;
static double qty;
static double qtyjc;
static short ipostq;
static double altfac;
static short imark;
static short imq;
static short intrcd;
static short nbil;
static short ibnom;
static short nom;
static double taxabl;
static short ltxpos;
static double sument;
static double crjtax;
static double crltax;
static double taxtyp;
static double taxent;
static double roff;
static char* F1220[] = {
    "(b'########',4x)"
};


    nfunc = *(short*)fifstrgv("A ",2);

    fill(jrnkey,&K10,&K0);

    jrnkey[0] = 1;

    nview = 0;
    iSopnS(jrnkey,&batch,&effdat,&effout,&irc);
    if(irc > 1) goto S9000;
    if(irc == 1) nview = 1;

    mvbyt(&batch,xc_cSbtch,&K8);

    loadSs(xsc1_scSsel,&K16,&irc);
    if(irc != 0) goto S9000;

    lsmall = FALSE;
    if(icompr(xsc1_scSsel,"INSMALL CHARGES ",&K16) == 0) lsmall = TRUE;

    /*
         Check for required fields

    */
    iqtyfl = ifldno("QUANTITY TRANSFER   ",&K20);
    iactfl = ifldno("ACTIVITY            ",&K20);

    if(iqtyfl < 1) goto S8800;
    if(xsc2_scSbff[iqtyfl-1] < 1) goto S8800;
    if(itest(&scSpff,&iqtyfl) == 1) goto S8800;

    if(xbb_nsetSb > 300) xbb_nsetSb = 300;   /* 300 is the program limit */

    /*
         Set the Partial Read Field to the last Visable screen field before
         the B field

    */
    iprdfl = xbb_fsbfSb-2;

    WRITE(INTERNAL,itime,12,FMT,F1220,1,REAL8,effdat,0);

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    */
S1400:
    backed = FALSE;

    rstSs(&K0,&N1,&irc);

    protSs(&K0,&K0,&K2,&K0,&irc);

    initSs(&K1,&irc);

    doutSs("BATCH ",&K5,xc_cSbtch,&K8,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);

    doutSs("MONTH EFFECTIVE",&K15,&itime[2],&K2,&irc);
    doutSs("DAY EFFECTIVE",&K13,&itime[3],&K2,&irc);
    doutSs("YEAR EFFECTIVE",&K14,&itime[1],&K2,&irc);

    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2950;

    posSs("REFNO ",&K5,&irc);

    dataSs("RESOURCE JOB",&K12,&rjobr,&K0,&irc);
    if(irc == 4) posSs("RESOURCE JOB",&K12,&irc);
S2000:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;

    rdpaSs("REFNO ",&K5,&K2,&irc);
    if(irc == 8) goto S1400;
    if(irc == 4) goto S8000;
    if(irc != 0) goto S9000;

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
    errSs("Enter \"A\", \"C\", \"L\", \"N\", \"S\", \"R\", \"X\" or \"D\"~",&K0,&irc);
    goto S2240;

    /*
         VIEWING ONLY ALLOWED (LIST OR NEXT) ON A CLOSED BATCH

    */
S2230:
    errSs("Batch is CLOSED.  Viewing only.  Enter \"L\" or \"N\"~",&K0,&irc);
    goto S2240;

S2240:

    starSs("FUNC",&K4,&irc);
    goto S2000;

S2250:

    /*
         GET REFERENCE NUMBER

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

    /*
     ----- Check for Invalid Reference Number

    */
S2320:
    if(icompr(&refno,"/ ",&K1) != 0) goto S2330;
    errSs("Invalid Reference Number~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2330:

    /*
         If 'NEXT'ing thru screens, or saved screens, go to NEXT function

    */
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2950;

    /*
         SEE IF THIS SOURCE DOCUMENT (REFERENCE#) HAS ALREADY BEEN ENTERED

    */
    iSvref(&batch,&refno,&K0,&irc);
    if(irc == 9) goto S9000;

    if(nfunc != *(short*)fifstrgv("A ",2)) goto S2350;

    /*
         IF AN ITEM IS TO BE ADDED, IT SHOULD NOT BE ON FILE ALREADY

    */
    if(irc == 0) goto S2380;                 /* IT IS NOT ON FILE */
    errSs("This Reference# is already on file~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

    /*
         IF AN ITEM IS TO BE CHANGED, DELETED, OR LISTED, IT SHOULD ALREADY  BE
            ON FILE

    */
S2350:
    if(irc == 1 || irc == 2) goto S2370;     /* IT IS ON FILE */
    errSs("This Reference# is not on file in this Batch~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

    /*
         DISPLAY PREVIOUSLY ENTERED SOURCE DOCUMENT

    */
S2370:
    iSdisp(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    if(irc == 2) goto S2000;                 /* WRONG INPUT SCREEN FOR THIS DOCUMENT */
    /*
    /* DOCUMENT

         PUT CURRENT FUNCTION BACK ON SCREEN

    */
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

S2380:
    if(nfunc == *(short*)fifstrgv("A ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("C ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("D ",2)) goto S2900;

    /*
         'LIST' - LET THEM LOOK AT IT, THEN GO AGAIN...

    */
    bangSs(&irc);
    if(irc == 9) goto S9000;
    goto S1400;

    /*
         'DELETE' - CONFIRM THAT THIS ITEM IS TO BE DELETED

    */
S2900:
    errSs("RETURN to DELETE this item.  Otherwise, enter ^~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    if(irc == 8) goto S1400;

    /*
         DELETE THE REFERENCED ITEM FROM THIS BATCH

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    goto S1400;

    /*
         Get and Display the 'NEXT' screen image

    */
S2950:
    iSnext(&batch,&refno,&irc);
    if(irc <= 1) goto S2955;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S9000;/* END OF A 'RE-ENTER' SERIES */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S9000;/* END OF A 'RE-ENTER' SERIES */
    errSs("There are no more entries in this Batch.~",&K0,&irc);
    goto S1400;

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
         IF A 'RE-ENTER' SERIES IS IN PROCESS, GO TO PROCESS THIS SCREEN

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3000;

    errSs("For VIEWING only.  RETURN for next screen~",&K0,&irc);
    goto S2000;

S2970:
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    goto S2000;

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

         'ADD' or 'CHANGE' - PROCESS INPUT SCREEN

    */
S3000:
    *xc_cSrefn = refno;

    dataSs("RESOURCE JOB",&K12,&rjobr,&K0,&irc);

    dataSs("RESOURCE PHASE",&K14,&phsr,&K0,&irc);
    if(irc != 0) phsr = 1.e0;

    jinfSc(&rjobr,&phsr,"JC  ","JOB TYPE",&K8,&jbtyfr,&K2,&K0,&K0,&irc);
    if(jbtyfr == *(short*)fifstrgv("R ",2)) goto S3030;

    errSs("\"JOB TYPE\" of this Job must be \"R\"~",&K0,&irc);
    starSs("RESOURCE JOB",&K12,&irc);
    blnkSs("RESOURCE PHASE",&K14,&irc);
    goto S2000;

S3030:
    jinfSc(&rjobr,&phsr,"JC  ","COMPANY ID",&K10,xc_cSmess,&K4,&K0,&K0,&irc);

    if(icompr(xc_cSmess,xc_cScoid,&K4) == 0) goto S3032;

    blnkSs("RESOURCE JOB",&K12,&irc);
    errSs("This Job must belong to the Local Company~",&K0,&irc);
    goto S2000;

S3032:
    jinfSc(&rjobr,&phsr,"JC  ","NAME",&K4,xc_cSmess,&K80,&K0,&K0,&irc);
    doutSs("RESOURCE JOB NAME",&K17,xc_cSmess,&K80,&irc);

    if(nfunc != *(short*)fifstrgv("A ",2)) goto S3033;

    /*
         If there is a V/C NUMBER (or CUSTOMER NUMBER in ACCOs case),
         load it.

    */
    jinfSc(&rjobr,&phsr,"JC  ","V/C NUMBER",&K10,&vcno,&K0,&K0,&K0,&irc);
    if(irc != 0) jinfSc(&rjobr,&phsr,"JC  ","CUSTOMER NUMBER",&K15,&vcno,&K0,&K0,&K0,&irc);
    if(irc == 0) doutSs("V/C NUMBER",&K10,&vcno,&N1,&ircx);

S3033:

    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3038;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3038;

    errSs("Enter transfer information~",&K0,&irc);
    posSs("V/C NUMBER",&K10,&irc);

    protSs("FUNC",&K4,&K1,&K0,&irc);
    protSs("RESOURCE JOB",&K12,&K1,&K0,&irc);
    protSs("RESOURCE PHASE",&K14,&K1,&K0,&irc);
    protSs("REFNO ",&K5,&K1,&K0,&irc);

S3035:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;

    rdpaSs(&iprdfl,&K0,&K2,&irc);

    if(irc == 8) goto S8200;
    if(irc == 4) goto S8000;
    if(irc != 0) goto S9000;

S3038:

    /*
         "DATE EFFECITVE" will keep it's value until changed by the user

    */
    dataSs("MONTH EFFECTIVE",&K15,&itime[2],&K2,&irc);
    dataSs("DAY EFFECTIVE",&K13,&itime[3],&K2,&irc);
    dataSs("YEAR EFFECTIVE",&K14,&itime[1],&K2,&irc);

    mdySc("G ","EFFECTIVE",&K9,&dateff,idate,&irc);

    clsdSc(&K1,&dateff,"W ",&irc);
    if(irc == 0) goto S30385;

    blnkSs("MONTH EFFECTIVE",&K15,&irc);
    blnkSs("DAY EFFECTIVE",&K13,&irc);
    blnkSs("YEAR EFFECTIVE",&K14,&irc);

    goto S3035;

S30385:

    dataSs("V/C NUMBER",&K10,&vcno,&K0,&irc);
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    if(irc == 0) goto S3039;

    errSs("Invalid Vendor~",&K0,&irc);
    starSs("V/C NUMBER",&K10,&irc);

    goto S3035;

S3039:
    doutSs("VENDOR NAME",&K11,ivname,&K30,&irc);

    dataSs("TO JOB",&K6,&rjobto,&K0,&irc);

    dataSs("TO PHASE",&K8,&phsto,&K0,&irc);
    if(irc != 0) phsto = 1.e0;

    jinfSc(&rjobto,&phsto,"JC  ","JOB TYPE",&K8,&jbtyto,&K2,&K0,&K0,&irc);
    if(irc == 0) goto S3040;

    errSs("Cannot get the \"JOB TYPE\" for this Job~",&K0,&irc);
    blnkSs("TO JOB",&K6,&irc);
    blnkSs("TO PHASE",&K8,&irc);
    goto S3035;

S3040:
    if(jbtyto != *(short*)fifstrgv("R ",2)) goto S3045;

    blnkSs("TO JOB",&K6,&irc);
    blnkSs("TO PHASE",&K8,&irc);
    errSs("This Job must NOT be a Resource Job~",&K0,&irc);
    goto S3035;

S3045:
    jinfSc(&rjobto,&phsto,"JC  ","NAME",&K4,xc_cSmess,&K80,&K0,&K0,&irc);
    doutSs("TO JOB NAME",&K11,xc_cSmess,&K80,&irc);

    dataSs("INVOICE ",&K7,&rinv,&K8,&irc);

    /*
         Get some information needed for T&E Billing

    */
    dataSs("TO CLIENT",&K9,&tovcno,&K0,&irc);
    if(irc != 0) tovcno = 0.e0;

    if(tovcno == 0.e0) jinfSc(&rjobto,&phsto,"B   ","V/C NUMBER",&K10,&tovcno,&K0,&K0,&K0,&irc);

    /*
         Protect the key fields

    */
    for(i=1,D2=(D2=(iprdfl-i+1))>0?D2:1; D2>0; D2--,i+=1)
    {
        protSs(&i,&K0,&K1,&K0,&irc);
    }

    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

    npass = 0;
    if(nfunc == *(short*)fifstrgv("C ",2)) npass = 1;

    /*
         AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3080;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3080;

    errSs("Enter Resource transfer data.~",&K0,&irc);
    posSs("QUANTITY TRANSFER",&K17,&irc);

    if(!backed) goto S3065;

    /*
    ------Make sure any 'D' records from the previous attempt are removed

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 7) irc = 0;
    if(irc != 0) goto S8200;

S3065:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* SAVE THIS SCREEN IF RE-ENTERING */
    readSs(&K1,&irc);
    if(irc == 0) goto S3100;
    if(irc == 4) goto S8000;
    if(irc == 8) goto S8200;

    goto S9000;

    /*
     ----- Read the information from the screen

    */
S3080:

    npass = 2;

    readSs(&K11,&irc);
    if(irc == 4) goto S8000;

S3100:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

         Extend and Validate all the data

    */
    for(jset=1; jset==1 || jset<=xbb_nsetSb; jset++)
    {

        xbb_jsetSb = jset;                   /* Set the Sub B field set number */

        dataSs("QUANTITY TRANSFER",&K17,&qtytrn,&K0,&irc);
        if(iameq(&qtytrn,&R3) == 0) goto S4500;

        dataSs("RESOURCE",&K8,ires,&K16,&irc);

        /*
                Validate the Resource Code

        */
        vrscSc(xc_cScoid,ires,&irc);
        if(irc == 0) goto S3150;

        errSs("Invalid Resource Code~",&K0,&irc);
        blnkSs("RESOURCE",&K8,&irc);

        goto S3065;

S3150:

        dataSs("UNIT PRICE",&K10,&uprice,&K0,&ircupr);

        dataSs("RESOURCE ACTIVITY",&K17,iract,&K10,&ircra);

        if(ircra == 0) frmaSc(&rjobr,&phsr,iract,&irc);

        dataSs("ACCOUNT03",&K9,&rjacct,&K0,&ircdja);

        /*
                Validate Resource Job/Phase/Activity/Job Account

        */
        valdSc(&K1,&rjobr,&phsr,iract,&rjacct,&ircda);
        if(ircda == 0) goto S3650;

        starSs("RESOURCE ACTIVITY",&K17,&irc);
        if(ircda >= 3) starSs("ACCOUNT03",&K9,&irc);

        goto S3065;

S3650:

        dataSs("ACTIVITY",&K8,iactto,&K10,&irca);
        if(!lsmall || irca == 0) goto S3655;
        errSs("Invalid Activity~",&K0,&irc);
        blnkSs("ACTIVITY",&K8,&irc);
        goto S3065;

S3655:

        /*
                Use the From INVENTORY activity when there has been no Activity  supplied

        */
        if(irca != 0) mvbyt(iract,iactto,&K10);

        /*
                Fix the ACTIVITY number

        */
        xc_cSvjob = *(double*)fifstrgv("TO JOB  ",8);
        xc_cSvphs = *(double*)fifstrgv("TO PHASE",8);
        xc_cSvact = *(double*)fifstrgv("ACTIVITY",8);

        frmaSc(&rjobto,&phsto,iactto,&irc);
        if(irc > 1) goto S3035;             /* Custom formatting failed */

        if(irca == 0) doutSs("ACTIVITY",&K8,iactto,&K10,&irc);

        dataSs("TAX ACTIVITY",&K12,iacttx,&K10,&irca);

        /*
                Use the To INVENTORY activity when there has been no Activity supplied

        */
        if(irca != 0) mvbyt(iactto,iacttx,&K10);

        /*
                Fix the ACTIVITY number

        */
        frmaSc(&rjobto,&phsto,iacttx,&irc);

        if(irca == 0) doutSs("TAX ACTIVITY",&K12,iacttx,&K10,&irc);

        dataSs("ACCOUNT01",&K9,&djacct,&K0,&irc);

        dataSs("ACCOUNT02",&K9,&dtjacc,&K0,&irc);
        if(irc != 0) dtjacc = djacct;

        /*
                Validate the to Job/Phase/Activity/Job Account

        */
        valdSc(&K1,&rjobto,&phsto,iactto,&djacct,&ircda);
        if(ircda == 0) goto S3700;

        starSs("ACTIVITY",&K8,&irc);
        if(ircda >= 3) starSs("ACCOUNT01",&K9,&irc);

        goto S3065;

S3700:

        /*
                Validate the to Job/Phase/Activity/Job Account

        */
        valdSc(&K1,&rjobto,&phsto,iacttx,&dtjacc,&ircda);
        if(ircda == 0) goto S3710;

        starSs("TAX ACTIVITY",&K12,&irc);
        if(ircda >= 3) starSs("ACCOUNT02",&K9,&irc);

        goto S3065;

S3710:

        /*
                Get the Ledger Account numbers

        */
        vglaS2("Resource credit     ","I ","O ","C ",&rjobr,&phsr,iract,&rjacct,&rlacct,&irc);
        if(irc == 0) goto S3750;

        starSs("ACCOUNT03",&K9,&irc);

        goto S3065;

S3750:

        vglaS2("Purchase Debit      ","I ","E ","D ",&rjobto,&phsto,iactto,&djacct,&dlacct,&irc);
        if(irc == 0) goto S3760;

        starSs("ACCOUNT01",&K9,&irc);

        goto S3065;

S3760:

        vglaS2("Tax Debit           ","I ","E ","D ",&rjobto,&phsto,iacttx,&dtjacc,&dtlacc,&irc);
        if(irc == 0) goto S3770;

        starSs("ACCOUNT02",&K9,&irc);

        goto S3065;

S3770:

        expric = qtytrn*uprice;

        roffSc(&expric,&R4,&irc);

        frmtSc(&expric,&K2,&K1,&K1,&K0,&K1,ioamnt,&K11,&irc);

        doutSs("EXTENDED PRICE",&K14,ioamnt,&K11,&irc);

        totamt = expric;

        /*
                Handle zero to five Markups

        */
        for(i=1,D6=(D6=(5-i+1))>0?D6:1; D6>0; D6--,i+=1)
        {

            mvbyt("MARKUP FACTOR ",ifldna,&K14);
            mvnoSc(&i,ifldna,&K15,&irc);

            dataSs(ifldna,&K16,&fact,&K0,&irc);

            mvbyt(" AMOUNT ",&ifldna[3],&K7);

            if(irc == 0) goto S4150;

            dataSs(ifldna,&K16,&amnt,&K0,&irc);
            if(irc != 0) goto S4200;

            goto S4160;

S4150:

            amnt = expric*0.01e0*fact;

S4160:
            roffSc(&amnt,&R4,&irc);

            totamt = totamt+amnt;

            frmtSc(&amnt,&K2,&K1,&K1,&K0,&K1,ioamnt,&K11,&irc);

            doutSs(ifldna,&K16,ioamnt,&K11,&irc);

            mvbyt(" ACCOUNT ",&ifldna[3],&K9);
            mvnoSc(&i,ifldna,&K16,&irc);

            dataSs(ifldna,&K17,&djmacc,&K0,&irc);

            /*
                       Validate the Markup Job/Phase/Activity/Job Account

            */
            valdSc(&K1,&rjobr,&phsr,iract,&djmacc,&ircda);
            if(ircda == 0) goto S4170;

            starSs("RESOURCE ACTIVITY",&K17,&irc);
            if(ircda >= 3) starSs(ifldna,&K17,&irc);

            goto S3065;

S4170:
            vglaS2("Markup Credit       ","I ","I ","C ",&rjobr,&phsr,iract,&djmacc,&dlmacc,&irc);
            if(irc == 0) goto S4200;

            starSs(ifldna,&K17,&irc);

            goto S3065;

S4200:;
        }

        doutSs("TAX ",&K3,"  ",&K1,&irc);

        dataSs("TAXABLE ",&K7,&itaxit,&K2,&irc);
        if(itaxit == *(short*)fifstrgv("X ",2)) itaxit = *(short*)fifstrgv("Y ",2);
        if(itaxit == *(short*)fifstrgv("  ",2)) itaxit = *(short*)fifstrgv("Y ",2);
        if(itaxit != *(short*)fifstrgv("Y ",2)) goto S4350;

        dataSs("SALES TAX CODE",&K14,&taxcod,&K8,&irc);
        if(irc != 0) goto S4350;

        /*
                Get the total Use Tax rate for this Tax Code

        */
        staxSc(&K0,&taxcod,&dateff,&taxrat,&staxrt,&utaxrt,loctax,entity,&noe,&irc);

        if(irc == 0) goto S4310;             /* Good Tax Code */

        errSs("Invalid Tax Code~",&K0,&irc);
        blnkSs("SALES TAX CODE",&K14,&irc);

        goto S3035;

S4310:
        if(utaxrt == 0.e0) goto S4350;       /* No USE Tax rate */

        usetax = totamt*utaxrt*0.01e0;

        roffSc(&usetax,&R4,&irc);
        if(iameq(&usetax,&R3) == 0) goto S4350;

        frmtSc(&usetax,&K2,&K1,&K1,&K0,&K1,ioamnt,&K11,&irc);

        doutSs("TAX ",&K3,ioamnt,&K11,&irc);

        totamt = totamt+usetax;

S4350:

        frmtSc(&totamt,&K2,&K1,&K1,&K0,&K1,ioamnt,&K11,&irc);

        doutSs("TOTAL AMOUNT",&K12,ioamnt,&K11,&irc);

S4500:;
    }

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    ------Call ELNS$B to display fields which were DOUTed out after
          the user pressed return.

    */
    elnsSb(&N1,&idum,&ircx);

    if(npass >= 2) goto S4600;

    npass = npass+1;

S4550:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;

    errSs("Review or Modify values and RETURN to continue~",&K0,&irc);

    goto S3065;

S4600:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

         Now it is time to pack up all the info to be posted
          for this reference.

    */
    xbilcom_bSline = 0.e0;
    ib = 0;

    for(jset=1,D12=(D12=(xbb_lsetSb-jset+1))>0?D12:1; D12>0; D12--,jset+=1)
    {

        xbb_jsetSb = jset;

        dataSs("QUANTITY TRANSFER",&K17,&qty,&K0,&irc);
        if(iameq(&qty,&R3) == 0) goto S7000;

        qtyjc = 0.e0;                        /* QTY to post to JOB$DATA */

        dataSs("POST QUANTITY",&K13,&ipostq,&K2,&irc);
        if(irc != 0) ipostq = *(short*)fifstrgv("  ",2);

        doutSs("JOBCOST QUANTITY",&K16,"  ",&K1,&irc);

        if(ipostq != *(short*)fifstrgv("Y ",2) && ipostq != *(short*)fifstrgv("X ",2)) goto S4700;

        /*
                Establish the Quantity to be posted to JOB$DATA

        */
        qtyjc = qty;

        dataSs("ALTERNATE QUANTITY FACTOR",&K25,&altfac,&K0,&irc);

        if(irc == 0) qtyjc = qtyjc*altfac;

        /*
         look for markup quantity flags

        */
        for(imark=1,D8=(D8=(5-imark+1))>0?D8:1; D8>0; D8--,imark+=1)
        {
            mvbyt("MARKUP QUANTITY ",ifldna,&K16);
            mvnoSc(&imark,ifldna,&K17,&irc);
            dataSs(ifldna,&K18,&imq,&K1,&irc);
            if(irc != 0) goto S4650;
            if(icompr(&imq,"Y ",&K1) != 0 && icompr(&imq,"X ",&K1) != 0) goto S4650;

            fill(ifldna,&K16,"  ");
            mvbyt("MARKUP FACTOR ",ifldna,&K14);
            mvnoSc(&imark,ifldna,&K15,&irc);

            dataSs(ifldna,&K16,&fact,&K0,&irc);
            if(irc != 0) goto S4650;
            qtyjc = qtyjc+qtyjc*0.01e0*fact;
S4650:;
        }

        frmtSc(&qtyjc,&K2,&K1,&K1,&K0,&K1,ioamnt,&K11,&irc);

        doutSs("JOBCOST QUANTITY",&K16,ioamnt,&K11,&irc);

S4700:

        intrcd = *(short*)fifstrgv("TX",2);  /* Transfer */
        if(qty < 0.e0) intrcd = *(short*)fifstrgv("RT",2);/* Return */

        dataSs("RESOURCE",&K8,ires,&K16,&irc);

        dataSs("UNIT PRICE",&K10,&uprice,&K0,&ircupr);

        dataSs("RESOURCE ACTIVITY",&K17,iract,&K10,&ircra);

        if(ircra == 0) frmaSc(&rjobr,&phsr,iract,&irc);

        dataSs("ACCOUNT03",&K9,&rjacct,&K0,&ircdja);

        dataSs("ACTIVITY",&K8,iactto,&K10,&irca);

        /*
                Use the From INVENTORY activity when there has been no Activity  supplied

        */
        if(irca != 0) mvbyt(iract,iactto,&K10);

        /*
                Fix the ACTIVITY number

        */
        frmaSc(&rjobto,&phsto,iactto,&irc);

        if(irca == 0) doutSs("ACTIVITY",&K8,iactto,&K10,&irc);

        dataSs("TAX ACTIVITY",&K12,iacttx,&K10,&irca);

        /*
                Use the To INVENTORY activity when there has been no Activity supplied

        */
        if(irca != 0) mvbyt(iactto,iacttx,&K10);

        /*
                Fix the ACTIVITY number

        */
        frmaSc(&rjobto,&phsto,iacttx,&irc);

        if(irca == 0) doutSs("TAX ACTIVITY",&K12,iacttx,&K10,&irc);

        dataSs("JOURNAL MEMO",&K12,jmemo,&K16,&irc);

        dataSs("ACCOUNT01",&K9,&djacct,&K0,&irc);

        dataSs("ACCOUNT02",&K9,&dtjacc,&K0,&irc);
        if(irc != 0) dtjacc = djacct;

        /*
                Get the Ledger Account numbers

        */
        vglaS2("Resource credit     ","I ","O ","C ",&rjobr,&phsr,iract,&rjacct,&rlacct,&irc);
        if(irc == 0) goto S4750;

        starSs("ACCOUNT03",&K9,&irc);

        goto S3065;

S4750:

        vglaS2("Purchase Debit      ","I ","E ","D ",&rjobto,&phsto,iactto,&djacct,&dlacct,&irc);
        if(irc == 0) goto S4760;

        starSs("ACCOUNT01",&K9,&irc);

        goto S3065;

S4760:

        vglaS2("Tax Debit           ","I ","E ","D ",&rjobto,&phsto,iacttx,&dtjacc,&dtlacc,&irc);
        if(irc == 0) goto S4770;

        starSs("ACCOUNT02",&K9,&irc);

        goto S3065;

S4770:

        dataSs("EXTENDED PRICE",&K14,&expric,&K0,&irc);

        /*
                Get the Markup information

        */
        for(i=1,D10=(D10=(5-i+1))>0?D10:1; D10>0; D10--,i+=1)
        {

            rmrkup[i-1][0] = 0.e0;
            rmrkup[i-1][1] = 0.e0;
            rmrkup[i-1][2] = 0.e0;

            mvbyt("MARKUP AMOUNT ",ifldna,&K14);
            mvnoSc(&i,ifldna,&K15,&irc);

            dataSs(ifldna,&K16,&rmrkup[i-1][0],&K0,&irc);
            if(irc != 0) goto S4950;

            mvbyt(" ACCOUNT ",&ifldna[3],&K9);
            mvnoSc(&i,ifldna,&K16,&irc);
            dataSs(ifldna,&K17,&rmrkup[i-1][1],&K0,&irc);

            vglaS2("Markup Credit       ","I ","I ","C ",&rjobr,&phsr,iract,&rmrkup[i-1][1],&rmrkup[i-1][2],&irc);
            if(irc == 0) goto S4950;

            starSs(ifldna,&K17,&irc);

            goto S3065;

S4950:;
        }

        dataSs("TAXABLE ",&K7,&itaxit,&K2,&irc);
        if(itaxit == *(short*)fifstrgv("X ",2)) itaxit = *(short*)fifstrgv("Y ",2);
        if(itaxit == *(short*)fifstrgv("  ",2)) itaxit = *(short*)fifstrgv("Y ",2);
        if(itaxit == *(short*)fifstrgv("Y ",2)) goto S4955;

        taxcod = *(double*)fifstrgv("        ",8);
        utaxrt = 0.e0;
        dtjacc = 0.e0;
        dtlacc = 0.e0;

        goto S4960;

S4955:

        dataSs("SALES TAX CODE",&K14,&taxcod,&K8,&irc);
        if(irc != 0) goto S4960;

        /*
                Get the total Use Tax rate for this Tax Code

        */
        staxSc(&K0,&taxcod,&dateff,&taxrat,&staxrt,&utaxrt,loctax,entity,&noe,&irc);

        if(irc == 0) goto S4960;             /* Good Tax Code */

        errSs("Invalid Tax Code~",&K0,&irc);
        blnkSs("SALES TAX CODE",&K14,&irc);

        goto S3065;

S4960:

        dataSs("TAX ",&K3,&usetax,&K0,&irc);

        dataSs("TOTAL AMOUNT",&K12,&totamt,&K0,&irc);

        dataSs("NON-BILL",&K8,&nbil,&K2,&irc);

        /*
                See if buffer is dangerously full

        */
        if(ib < MAXSCD-1000) goto S5900;

        /*
                If we have not yet BACKED up this reference this is the time to  do it

        */
        if(backed) goto S5850;

        backed = TRUE;
        if(nfunc == *(short*)fifstrgv("A ",2)) goto S5850;

        iSback("BACK",&batch,&refno,&irc);
        if(irc != 0) goto S9000;

        iSdlet(&batch,&refno,&irc);

S5850:
        xpScom1_nscdat = xpScom1_nscdat+1;
        iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
        ib = 0;

S5900:

        xc_cSrow = jset;

        /*
                Pack up the Inventory Purchase "D" record set

        */
        ib = ib+1;

        packjm(&jset,xpScom1_pSscdt,&ib,&ircx);/* JOURNALS$MEMO */

        fillSa(&xpScom1_pSscdt[ib-1],35*8,"  ");

        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* Transactions */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("PI      ",8);/* Purchase from Inventory */
        xpScom1_pSscdt[ib+1] = 1.e0;         /* Version number */
        mvbyt(xc_cScoid,&xpScom1_pSscdt[ib+2],&K4);/* Company ID */
        xpScom1_pSscdt[ib+3] = *(double*)fifstrgv("        ",8);/* Transaction Type */
        xpScom1_pSscdt[ib+4] = vcno;         /* Vendor */
        xpScom1_pSscdt[ib+5] = rjobr;        /* Resource Job */
        xpScom1_pSscdt[ib+6] = phsr;         /* Resource Phase */
        mvbyt(iract,&xpScom1_pSscdt[ib+7],&K10);/* Resource Activity */
        xpScom1_pSscdt[ib+9] = rjobto;       /* To Job */
        xpScom1_pSscdt[ib+10] = phsto;       /* To Phase */
        mvbyt(iactto,&xpScom1_pSscdt[ib+11],&K10);/* To Activity */
        xpScom1_pSscdt[ib+13] = rinv;        /* Invoice (Ticket #) */
        xpScom1_pSscdt[ib+14] = dateff;      /* Date Effective */
        xpScom1_pSscdt[ib+15] = expric;      /* Extended Price */
        xpScom1_pSscdt[ib+16] = rjacct;      /* Resource Job Account */
        xpScom1_pSscdt[ib+17] = rlacct;      /* Resource Ledger Account */
        xpScom1_pSscdt[ib+18] = totamt;      /* Total Amount */
        xpScom1_pSscdt[ib+19] = djacct;      /* Purchase Debit Job Acc */
        xpScom1_pSscdt[ib+20] = dlacct;      /* Purchase Debit Ledger Acc */
        mvbyt(jmemo,&xpScom1_pSscdt[ib+21],&K16);/* Journal Memo */
        mvbyt(ires,&xpScom1_pSscdt[ib+23],&K16);/* Resource Code */
        xpScom1_pSscdt[ib+25] = qty;         /* Quantity */
        xpScom1_pSscdt[ib+26] = qtyjc;       /* Job Cost Quantity */
        xpScom1_pSscdt[ib+27] = uprice;      /* Unit Price */
        mvbyt(&intrcd,&xpScom1_pSscdt[ib+28],&K2);/* Inventory Transaction Code */
        mvbyt(&nbil,&xpScom1_pSscdt[ib+29],&K2);/* Non-Billable */
        xpScom1_pSscdt[ib+30] = taxcod;      /* Tax Code */
        xpScom1_pSscdt[ib+31] = utaxrt;      /* Use Tax Rate */
        xpScom1_pSscdt[ib+32] = usetax;      /* Use Tax Amount */
        xpScom1_pSscdt[ib+33] = dtjacc;      /* Debit Tax Job Account */
        xpScom1_pSscdt[ib+34] = dtlacc;      /* Debit Tax Ledger Account */
        ib = ib+36;

        ibnom = ib;
        nom = 0;
        taxabl = expric;

        for(i=0; i==0 || i<5; i++)
        {

            if(rmrkup[i][0] == 0.e0) goto S6100;

            taxabl = taxabl+rmrkup[i][0];

            /*
                       Store Markup amount, job account and ledger account

            */
            mvbyt(&rmrkup[i][0],&xpScom1_pSscdt[ib],&K24);

            nom = nom+1;

            ib = ib+3;

S6100:;
        }

        xpScom1_pSscdt[ibnom-1] = nom;       /* Number of Markups (0-5) */

        if(utaxrt == 0.e0) goto S6350;

        /*
                Packup USE tax set(s)

        */
        ltxpos = 0;
        sument = 0.e0;

        for(i=0; i==0 || i<noe; i++)
        {

            crjtax = entity[i][4];
            if(crjtax == 0.e0) goto S6300;   /* Not USE Tax */

            vglaS2("Tax Credit          ","I ","E ","C ",&rjobto,&phsto,iacttx,&crjtax,&crltax,&irc);
            if(irc != 0) goto S3065;

            taxtyp = *(double*)fifstrgv("USE     ",8);

            taxent = entity[i][3]*taxabl*0.01e0;

            roffSc(&taxent,&R4,&irc);

            sument = sument+taxent;

            ib = ib+1;

            ltxpos = ib+22;                  /* Entity Tax  */
            /*
            /*  $ position

            */
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("ST      ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd("        ",&xpScom1_pSscdt[ib+3],&K4);
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjobto;   /* JOB */
            xpScom1_pSscdt[ib+6] = phsto;    /* PHASE */
            mvwrd(iacttx,&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd("        ",&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&rinv,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = dateff;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = dateff;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = dateff;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = totamt;  /* INVOICE AMOUNT */
            mvwrd(&taxcod,&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[i][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[i][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = dtjacc;  /* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = crjtax;  /* CREDIT TAX  */
            /*
            /*  JOB ACCT
            */
            xpScom1_pSscdt[ib+24] = dtlacc;  /* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = crltax;  /* CREDIT TAX  */
            /*
            /*  LEDG ACT
            */
            mvwrd(jmemo,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = 0.e0;    /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = totamt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

S6300:;
        }

        if(ltxpos == 0) goto S6350;

        roff = usetax-sument;

        if(iameq(&roff,&R3) == 0) goto S6350;

        /*
                The last Use tax entity must force "total use tax" = "sum of entities"

        */
        xpScom1_pSscdt[ltxpos-1] = xpScom1_pSscdt[ltxpos-1]+roff;

S6350:

        /*
                Get the BILLING REFERENCE if there is one

        */
        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        if(jbtyto == *(short*)fifstrgv("I ",2)) goto S6800;/* No BILLING on "I" type job */
        /*
        /* job

                Initialize Time & Expense variables

        */
        initSb(&irc);

        mvbyt(&batch,&xbilcom_bSbtch,&K8);
        xbilcom_bSdate = dateff;

        /*
                Pack Time and Expense data

        */
        xbilcom_bSnbil = nbil;
        mvwrd(xc_cScoid,xbilcom_bScoid,&K2); /* CHARGED COMPANY ID */
        xbilcom_bSvcno = tovcno;             /* CLIENT NUMBER */

        xbilcom_bScjob = rjobto;             /* CHARGE JOB */
        xbilcom_bScphs = phsto;              /* CHARGE PHASE */
        xbilcom_bSjcda = djacct;             /* ACCOUNT CHARGED */
        mvwrd(iactto,xbilcom_bSactv,&K5);    /* ACTIVITY */
        mvwrd(ires,xbilcom_bSresc,&K8);      /* RESOURCE CODE */
        xbilcom_bSqty = qty;                 /* QUANTITY */
        xbilcom_bSamnt = totamt;             /* $ AMOUNT */
        mvbyt(xc_cSrefn,&xbilcom_bSref,&K8); /* REFERENCE NUMBER */
        xbilcom_bSline = jset;               /* LINE NUMBER */
        xpScom1_noscSp = ib;

        /*
                Setup "BILLING RATE OVERRIDE"

        */
        autote(&irc);

        ib = xpScom1_noscSp;

        if(irc == 7) irc = 0;
        if(irc == 0) goto S6800;             /* ERROR IN BILLING */

        goto S4550;

S6800:

S7000:;
    }

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

     --- GOOD ENTRY

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S7920;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S7920;

    errSs("Good entry. RETURN to continue. Otherwise, enter ^~",&K0,&irc);
    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7600;
    if(irc == 4) goto S8000;
    if(irc == 9) goto S9000;

    goto S8200;

    /*
         IF THIS IS A CHANGE, DELETE PRIOR VERSION OF THIS ITEM

    */
S7600:
    rstSs(&K0,&N1,&irc);                     /* UN-BLINK ALL FIELDS */

    if(nfunc != *(short*)fifstrgv("C ",2)) goto S7950;

S7920:
    if(xpScom1_nscdat > 0) goto S7950;

    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;

S7950:
    iSsave(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    /*
         SAVE DATA FROM SCREEN

    */
    xpScom1_nscdat = xpScom1_nscdat+1;
    iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
    ib = 0;
    if(irc != 0) goto S9000;

    if(backed) iSback("DLET",&batch,&refno,&irc);

    goto S1400;

    /*
         SAVE screen image of a BAD entry screen

    */
S8000:

    /*
         delete all previous references to this Batch#/Reference#

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 7) irc = 0;
    if(irc != 0) goto S9000;

    /*
         SAVE image of BAD screen in INPUT$BATCHES

    */
    iSbad(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    if(backed) iSback("DLET",&batch,&refno,&irc);

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8120;/* DON'T STOP ON RE-ENTER */
    errSs("Screen SAVED for later use.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);

S8120:
    if(irc == 0) goto S1400;
    goto S9000;

S8200:
    if(!backed) goto S1400;

    /*
    ------Restore Backed Up copy of this reference

    */
    iSback("REST",&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    goto S1400;

    /*
         Error Handling

    */
S8800:
    retuSs("There must be an unprotected Sub B field named \"QUANTITY TRANSFER\"~",&K0,"r!",&K2,&irc);
    goto S9000;

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    */
S9000:
    if(backed) iSback("REST",&batch,&refno,&irc);

    return;

}
/*
-----------------------------------------------------------------------

     RDS June 26, 1998 15:17:20    ACC-0118

     Code to support the new selection "TR RESOURCE TRANS".

-----------------------------------------------------------------------

     RDS June 29, 1998 09:00:55    ACC-0118

     The selection should be "IN RESOURCE TRANS" not "TR RESOURCE TRANS".

-----------------------------------------------------------------------

     RDS July 13, 1998 13:45:45    ACC-0118

     Provide for the posting of Quantities of completion to JOB$DATA.
     If the "IN RESOURCE TRANS" field "POST QUANTITY" contains "Y" or "X"
     then the Quantity will be posted.  If the field "ALTERNATE QUANTITY FACTOR"
     has a value, then the Quantity to be posted will be multiplied by it.

-----------------------------------------------------------------------

     RDS July 22, 1998 13:16:10    ACC-0118

     Change the screen field "RESOURCE ACCOUNT" to "ACCOUNT03".
     This supports validation on the "IN RESOURCE RATE" screen.

-----------------------------------------------------------------------

     DBS December 10, 1999 15:18:37    OCJ0000

     check for ACTIVITY if selection IN SMALL CHARGES

-----------------------------------------------------------------------

     DBS September 25, 2002 14:28:37    ACC0155

     Update the IB variable after the AUTOTE call so that
     the "D" record will reflect any COST$DATA set that
     may have been packed up.

*/
