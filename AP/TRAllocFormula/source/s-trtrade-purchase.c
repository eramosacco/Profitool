#define LPROTOTYPE
#define PRIMELIB
#include "fortran.h"
#include "cmis_com.h"
#include "p_post_com_batch.h"
#include "billing_com.h"
#include "apar_hold_com.h"
#include "apar_tracking_com.h"
#include "sc_com1.h"
#include "sc_com2.h"
#include "shared_com.h"
#include "parm_k.h"
/*
----------------------------------------------------------------------C
     S/TRTRADE-PURCHASES

     PURCHASE INPUT PROCESSOR

     GMT - 04/24/82

*/
#define NFIELD      17

#include "libSQLclient.h"
#include "libbb.h"
#include "libutil.h"
#include "libpost.h"
#include "libfio.h"
#include "libscr.h"
double combjp();
double rndoff();
void tr6800(void)
{
static short T1;
static short D3;
static short D6;
static double T9;
static double T10;
static short D15;
static short D17;
static short D19;
static short D21;
static short D23;
static short K22 = 22;
static short K1 = 1;
static short K24 = 24;
static short K18 = 18;
static short K11 = 11;
static short K17 = 17;
static short K0 = 0;
static short K10 = 10;
static short K14 = 14;
static short K33 = 33;
static short K12 = 12;
static short K26 = 26;
static short K30 = 30;
static short K16 = 16;
static short K4 = 4;
static short K9 = 9;
static short K5 = 5;
static short K15 = 15;
static short K13 = 13;
static short K8 = 8;
static short K3 = 3;
static short K104 = 104;
static short K2 = 2;
static short K6 = 6;
static short K7 = 7;
static short K27 = 27;
static short K76 = 76;
static short K23 = 23;
static double R4 = 1.e0;
static short K9999 = 9999;
static short K20 = 20;
static double R7 = 0.30e0;
static double R8 = 0.1e0;
static short N1 = -1;
static short K40 = 40;
static short K21 = 21;
static double R11 = 0.e0;
static double R12 = .01e0;
static short K19 = 19;
static double R13 = 0.01e0;
static short K160 = 160;
static short K78 = 78;
static short K62 = 62;
static short K32 = 32;
static double pSldep;
static short bSeqfn[5];
static short duplxS;                         /* DUPLEX PRIMOS FUNCTION */
static short cpShlp[8];                      /* NAME USED FOR HELP REQUESTS IN SCFM */
static short filelS;

static double fldnam[13][NFIELD];
static double quanty[13];
static double amnts[13];
static double dracct[13];
static double drjacc[13];
static double cracct[13];
static double taxcod[13];
static double taxamt[13];
static double rjobs[13];
static double invli[13];
static double invdli[13];
static double poli[13];
static double discli[13];
static double clntli[13];
static double csh[13];
static double dsc[13];
static double adisc[13];
static double apict[13];
static double arict[13];
static double invoic;
static double accts[20];
static double vatamt[13];
static double data[10];
static double ppsout[1];
static double tmemo[2];
static double vatact[2][3][2][3];
static double code[1];
static double entity[10][6];

static short litem[13];
static short fordom;
static short accpay;
static short ifgs;
static short vivo;
static short vatype;
static short vatdsc[36][20];
static short despnt[2][3][2][3];
static short activ[5];
static short memo[8];
static short ifldna[16];
static short iactiv[5];
static short inobil[13];

static short dscact[5];
static short loctax[20];
static short iactxt[5];
static short jobtxt[5];
static short imem[8];
static short activs[13][5];
static short rmemo[13][8];
static short idchg[13][2];
static short keygi[20];
static short lactxt[5];
static short ljbtxt[5];
static short jrnkey[10];
static short keyact[11];
static short ivname[15];
static short lastyp[4];
static short itemp[2];
static short nresp[12];
static short irescd[13][8];
static short namres[8];
static short namqty[3];
static short inhld[38];
static short marray[14];
static short jcoid[2];
static short keycSm[60];
static short keysav[10];
static short keysv[22];
static short nexpn[13];
static short nclos[13];
static short icert[6];
static short keyalc[22];

static short invdat[5];
static short icaltx[13];
static short itax[5];
static short iact[5];
static short memotx[8];

static unsigned short nqtyrc;
static unsigned short invref;
static unsigned short dupdue;
static unsigned short image;
static unsigned short linitm;
static unsigned short rqmemo;

static short ndup;
static double typlst;
static short iflag;
static double olddsc;
static double craold;
static short idumb;
static short irc;
static short ipbya;
static double sdatdu;
static short idsmod;
static short idum;
static short invchk;
static short invdup;
static short i;
static short nview;
static double batch;
static double effbat;
static double effout;
static short nswvb;
static double effdat;
static double datout;
static short iswpps;
static double pps1;
static double pps2;
static double vatrt;
static short nfunc;
static double trtype;
static short ircb;
static double refno;
static short ircf;
static double vcno;
static short idsflg;
static double vbjob;
static short nbank;
static double apgl;
static double dscern;
static double vatcr;
static double vatdr;
static short iforgn;
static double client;
static short nonbil;
static short ircnon;
static double po;
static double rjobph;
static short ircSjp;
static double drSacc;
static short ircSac;
static short ircSat;
static short nm1;
static short nd1;
static short ny1;
static double datinv;
static short nm2;
static short nd2;
static short ny2;
static double datdue;
static double cramnt;
static double disc;
static short ifc;
static short ilc;
static double dscfac;
static double ddisc;
static double vatpct;
static short iexvat;
static double vattot;
static short ircvat;
static double divisr;
static double divsor;
static double stxtot;
static short irctax;
static double taxabl;
static double taxemt;
static double codtax;
static short iopt;
static double taxrat;
static double saltax;
static double usetax;
static short noe;
static double rmisc;
static double ttaxbl;
static double sbtotx;
static short ircsub;
static double sbrtio;
static short nswcls;
static short nswcxp;
static double crjacc;
static double alloc;
static short j;
static double ramnt;
static short mflag;
static short icnt;
static double perc;
static double rj;
static double rp;
static double ac;
static double stcode;
static double rjp;
static double amt;
static short nodup;
static short lstlin;
static short ircamt;
static short ircacc;
static short ircjob;
static short ircact;
static short ircmem;
static short ircinv;
static short ircrst;
static double tdist;
static double tadisc;
static double tvat;
static double tstax;
static short ilast;
static short nswdup;
static short lstvat;
static short lsttax;
static short ircbak;
static double dum;
static short ircSd;
static short lstdsc;
static double bjob;
static short k;
static double rjob;
static double phase;
static short irca;
static short ircv;
static double subjct;
static double exempt;
static short irc1;
static short irc2;
static short nerr;
static short m;
static double vatro;
static double dscadj;
static short ij;
static double staxro;
static double check;
static short month;
static short iday;
static short iyear;
static double chkdat;
static double cash;
static short ib;
static short ivcmod;
static short ircS;
static short ircSS;
static short ircx;
static double tsaltx;
static double crjtax;
static double crltax;
static double taxtyp;
static double taxent;
static double ratio;
static double actvat;
static double cract;
static double cractl;
static double pstamt;
static short iacpay;
static double dract;
static double dractl;
static short kk;
static short iclr;
static double tamnt;
static double clsamt;
static short ierrs;
static double chkjob;
static double chkphs;
static short idupls;
static short n;
static double epps;
static double x;
static double odate;
static double hldref;
static short len;
static short nread;
static int FIRST = 1;
static int ftnsiz[] = {1,1,221,1,1,5,1,1,4,1,1,5};
static namelist DATAVAR[] = {
"fldnam",fldnam,2,ftnsiz,"dscact",dscact,1,ftnsiz+3,"lastyp",lastyp,1,ftnsiz+6,"invdat",invdat,1,ftnsiz+9,
    "ndup",&ndup,1,NULL
};
static char *DATAVAL[] = {
"$DATAVAR",
"fldnam='AMOUNT01','DRACCT01','JOBPH01','ACTIV01','MEMO01','EXPN01','CLOS01','VAT01','INV01','DISC01','PO01','CLNT01',",
"'TAXCOD01','NONBIL01','TAXLOC01','TAXAMT01','TAXOUT01','AMOUNT02','DRACCT02','JOBPH02','ACTIV02','MEMO02','EXPN02',",
"'CLOS02','VAT02','INV02','DISC02','PO02','CLNT02','TAXCOD02','NONBIL02','TAXLOC02','TAXAMT02','TAXOUT02','AMOUNT03',",
"'DRACCT03','JOBPH03','ACTIV03','MEMO03','EXPN03','CLOS03','VAT03','INV03','DISC03','PO03','CLNT03','TAXCOD03',",
"'NONBIL03','TAXLOC03','TAXAMT03','TAXOUT03','AMOUNT04','DRACCT04','JOBPH04','ACTIV04','MEMO04','EXPN04','CLOS04',",
"'VAT04','INV04','DISC04','PO04','CLNT04','TAXCOD04','NONBIL04','TAXLOC04','TAXAMT04','TAXOUT04','AMOUNT05',",
"'DRACCT05','JOBPH05','ACTIV05','MEMO05','EXPN05','CLOS05','VAT05','INV05','DISC05','PO05','CLNT05','TAXCOD05',",
"'NONBIL05','TAXLOC05','TAXAMT05','TAXOUT05','AMOUNT06','DRACCT06','JOBPH06','ACTIV06','MEMO06','EXPN06','CLOS06',",
"'VAT06','INV06','DISC06','PO06','CLNT06','TAXCOD06','NONBIL06','TAXLOC06','TAXAMT06','TAXOUT06','AMOUNT07',",
"'DRACCT07','JOBPH07','ACTIV07','MEMO07','EXPN07','CLOS07','VAT07','INV07','DISC07','PO07','CLNT07','TAXCOD07',",
"'NONBIL07','TAXLOC07','TAXAMT07','TAXOUT07','AMOUNT08','DRACCT08','JOBPH08','ACTIV08','MEMO08','EXPN08','CLOS08',",
"'VAT08','INV08','DISC08','PO08','CLNT08','TAXCOD08','NONBIL08','TAXLOC08','TAXAMT08','TAXOUT08','AMOUNT09',",
"'DRACCT09','JOBPH09','ACTIV09','MEMO09','EXPN09','CLOS09','VAT09','INV09','DISC09','PO09','CLNT09','TAXCOD09',",
"'NONBIL09','TAXLOC09','TAXAMT09','TAXOUT09','AMOUNT10','DRACCT10','JOBPH10','ACTIV10','MEMO10','EXPN10','CLOS10',",
"'VAT10','INV10','DISC10','PO10','CLNT10','TAXCOD10','NONBIL10','TAXLOC10','TAXAMT10','TAXOUT10','AMOUNT11',",
"'DRACCT11','JOBPH11','ACTIV11','MEMO11','EXPN11','CLOS11','VAT11','INV11','DISC11','PO11','CLNT11','TAXCOD11',",
"'NONBIL11','TAXLOC11','TAXAMT11','TAXOUT11','AMOUNT12','DRACCT12','JOBPH12','ACTIV12','MEMO12','EXPN12','CLOS12',",
"'VAT12','INV12','DISC12','PO12','CLNT12','TAXCOD12','NONBIL12','TAXLOC12','TAXAMT12','TAXOUT12','AMOUNT13',",
"'DRACCT13','JOBPH13','ACTIV13','MEMO13','EXPN13','CLOS13','VAT13','INV13','DISC13','PO13','CLNT13','TAXCOD13',",
"'NONBIL13','TAXLOC13','TAXAMT13','TAXOUT13',dscact='DI','SC','OU','NT','',lastyp='  ','  ','  ','',invdat=",
"'DA','TE',' I','NV','',ndup='N',",
"$END"
};

static char* F3064[] = {
    "('HOLD ALL INVOICES: ',a8)"
};
static char* F3067[] = {
    "('HOLD ALL TRADE INVOICES: ',a8)"
};
static char* F3645[] = {
    "(b'Z#.##')"
};
static char* F3785[] = {
    "(f8.0)"
};
static char* F3825[] = {
    "(b'$$$,$$#.##')"
};
static char* F3831[] = {
    "(b'ZZ#.##','%     ')"
};
static char* F4010[] = {
    "(2a2,'TRAL',a8,4x,24x)"
};
static char* F45011[] = {
    "(f9.2)"
};
static char* F6610[] = {
    "(b'ZZZZZ#',b'Z#',5a2,4x)"
};
static char* F6804[] = {
    "(a1,' TAX ',a8,'  ')"
};
static char* F68214[] = {
    "(a1,' TAX ',a8,'  ')"
};
static char* F6826[] = {
    "('P V',a1,4x)"
};
static char* F6829[] = {
    "(f12.2,4x)"
};
static char* F6851[] = {
    "('CDV',a1,4x)"
};
static char* F7040[] = {
    "(2a2,'PO',b'ZZZZZZ',b'ZZZZZZ',b'ZZ',5a2,a8,82x)"
};
static char* F7320[] = {
    "('**Warning:  PPS expires on ',a8,44x)"
};
static char* F7375[] = {
    "(b'Z#.##')"
};

    if(FIRST) {
        FIRST=0;
        fiointu((char*)DATAVAL,0,2);
        fiornl(DATAVAR,5,NULL);
    }

    typlst = *(double*)fifstrgv("~~~~~~~~",8);

    /*
     ----- ADDED VARIABLES FOR W/O KGC-0020 ***DEI***

    */
    iflag = 0;                               /* TELL ME TWICE FLAG */
    olddsc = 0.e0;                           /* PREVIOUS DISCOUNT RATE */
    craold = 0.e0;                           /* PREVIOUS INVOICE AMOUNT */

    linitm = FALSE;
    invref = FALSE;
    gnliSc("READ","INVOICE FROM REFERENCE",&K22,&idumb,&K1,&irc);
    if(irc == 0) invref = TRUE;

    /*
     ---- Set IPBYA which indicates whether Payables
     ---- are to be recorded by activity (AP/AR$MASTER)

    */
    ibyaSc("P ",&ipbya);

    image = FALSE;
    if(xc_cSenvr != 1) goto S550;            /* NO CAPTURE IF NOT IN ONLINE */
    gnliSc("READ","TRTRADE PURCHASE CAPTURE",&K24,&idumb,&K1,&irc);
    if(irc == 0) image = TRUE;
    T1 = CPTURS;
    flagSc("U ","G ",&T1,&irc);
    if(irc == 1) image = FALSE;              /* CAPTURE WAS ALREADY ON */

S550:
    dupdue = FALSE;
    gnliSc("READ","DUPLICATE DUE DATE",&K18,&idumb,&K1,&irc);
    if(irc == 0) dupdue = TRUE;

    sdatdu = 0.e0;                           /* SAVE DATE DUE FOR LATER USE   1/6/89 SL */

    /*
    -------------------CHECK FOR % DISCOUNTS

    */
    idsmod = 0;                              /* DISCOUNT NOT IN % */

    gnliSc("READ","% DISCOUNTS",&K11,&idum,&K1,&irc);
    if(irc == 7) goto S1000;

    idsmod = 1;                              /* DISCOUNT IS A % */

S1000:

    /*
     --- OPEN COMMITMENT$MASTER

    */
    ioSf("OPEN","COMMITMENT$MASTER",&K17,"    ",&K0,&K0,&K0,&K0,&irc);

    if(irc != 0) ferrSc(&K10,&irc,"COULD NOT OPEN COMMITMENT$MASTER  SUBR: TR6800~",&K0);

    /*
     ---- Check configuration params to see if duplicate invoice checking
          is required.  If so, also check if user must confirm acceptance
          of duplicate invoice situations, or just a return will suffice.

    */
    invchk = 0;                              /* NOT NECESSARY TO CHECK */
    invdup = 0;                              /* NO CONFIRM DUP INV */

    gnliSc("READ","CHECK INVOICES",&K14,&idum,&K1,&irc);
    if(irc != 0) goto S1080;

    /*
     ---- Yes, check for duplicates.  Now determine if its at the
          invoice or job level.

    */
    fileSc("READ",&K33,"AP/AR$MASTER",&K12,&K1,&irc,0);
    if(irc != 0) ferrSc(&K10,&irc,"AP/AR$MASTER~",&K0);

    invchk = 1;                              /* CHECK AT INVOICE LEVEL */
    if(icompr("J ",&idum,&K1) == 0) invchk = 2;/* CHECK AT JOB/PHASE LEVEL */

    /*
     ---- Finally, see if user must enter confirmation (i.e. "OK")
          when Duplicate Invoice situation found.

    */
    gnliSc("READ","CONFIRM DUPLICATE INVOICES",&K26,&idum,&K1,&irc);
    if(irc == 0) invdup = 1;

S1080:

    /*
         Determine if Entry of a MEMO is required

    */
    rqmemo = FALSE;
    gnliSc("READ","TRTRADE PURCHASE MEMO REQUIRED",&K30,&idum,&K1,&irc);
    if(irc == 0) rqmemo = TRUE;

    /*
     ----  OPEN INPUT BATCH

    */
    for(i=1; i==1 || i<=10; i++)
    {
        jrnkey[i-1] = 0;
    }

    jrnkey[0] = 1;                           /* SET FLAG FOR PURCHASE JOURNAL */
    nview = 0;                               /* RESET VIEWING ONLY FLAG */
    iSopnS(jrnkey,&batch,&effbat,&effout,&irc);
    if(irc > 1) goto S9000;
    if(irc == 1) nview = 1;                  /* SET VIEWING ONLY FLAG */

    /*
     ----- Test for Verify Batch

    */
    nswvb = 0;
    if(icompr(&batch,"/ ",&K1) == 0) nswvb = 1;

    loadSs(xsc1_scSsel,&K16,&irc);           /* LOAD INPUT SCREEN */
    if(irc != 0) goto S9000;
    if(idsmod == 0) soutSs("P ",&K4,"Discount$",&K9,&irc);
    if(idsmod == 0) soutSs("P ",&K5,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K4,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K5,"Discount$",&K9,&irc);

    /*
     ----- SEE IF QUANTITIES AND RESOURCE CODES ARE ON THE SCREEN

    */
S1105:

    readSs(&K10,&irc);

    /*
         get override effective date

    */
    mdySc("G ","EFFECTIVE",&K9,&effdat,&datout,&irc);
    if(irc != 0) goto S1120;

    for(i=1,D3=(D3=(7-i+1))>0?D3:1; D3>0; D3--,i+=1)
    {
        clsdSc(&i,&effdat,"W ",&irc);
        if(irc == 0) goto S1110;
        blnkSs("MONTH EFFECTIVE",&K15,&irc);
        blnkSs("DAY EFFECTIVE",&K13,&irc);
        blnkSs("YEAR EFFECTIVE",&K14,&irc);
        goto S1105;
S1110:;
    }

    goto S1125;

S1120:

    effdat = effbat;

S1125:

    mvwrd("RESOURCE CODE 01",namres,&K8);
    mvwrd("QTY01 ",namqty,&K3);

    nqtyrc = TRUE;                           /*  ASSUME THEY ARE THERE */
    dataSs(namres,&K16,&idum,&K1,&irc);
    if(irc == 1) nqtyrc = FALSE;             /*  NO, THEY ARE NOT */

    /*
     ----- IF RESOURCE CODES AND QUANTITIES DON'T EXIST ON THE SCREEN,
           INITIALIZE THOSE VARIABLES SO THEY WON'T BE FULL OF JUNK

    */
    if(nqtyrc) goto S1700;
    fill(irescd,&K104,"  ");
    for(i=1; i==1 || i<=13; i++)
    {
        quanty[i-1] = 0.0e0;
    }

S1700:

    iswpps = 1;
    dataSs("PPS APPLICABLE",&K14,&idum,&K2,&irc);
    if(irc != 4) iswpps = 0;
    pps1 = -1.e0;
    pps2 = -1.e0;
    ppsout[0] = *(double*)fifstrgv("N       ",8);

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effbat,&vatrt,&irc);

    /*
     ----- INITIALIZE TIME & EXPENSE VARIABLES

    */
    initSb(&irc);

    xbilcom_bSbtch = batch;
    xbilcom_bSdate = effbat;

    /*
         OUTPUT BATCH NUMBER AND EFFECTIVE DATE

    */
    soutSs("P ",&K1,&batch,&K8,&irc);
    soutSs("P ",&K2,&effout,&K8,&irc);

    nfunc = *(short*)fifstrgv("A ",2);       /* SET DEFAULT FUNCTION */
    if(nview == 1) nfunc = *(short*)fifstrgv("L ",2);/* SET DEFAULT FUNCTION FOR A CLOSED BATCH */
    fill(&trtype,&K4,"  ");                  /* INITIALIZE TRANSACTION TYPE */
    ndup = *(short*)fifstrgv("N ",2);        /* SET DEFAULT DUPLICATION SWITCH */

S1800:
    protSs(&K0,&K0,&K2,&K0,&irc);            /* UNPROTECT ALL FIELDS */
    initSs(&K2,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);      /* LOAD FUNCTION */
    doutSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    doutSs("DUP ",&K3,&ndup,&K1,&irc);       /* LOAD AUTO DUP SWITCH */
    if(idsmod == 0) soutSs("P ",&K4,"Discount$",&K9,&irc);
    if(idsmod == 0) soutSs("P ",&K5,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K4,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K5,"Discount$",&K9,&irc);

    /*
         PUT DUE DATE BACK ON SCREEN...BUT NOT FIRST TIME THRU SL 1/6/89
    */
    if(dupdue && sdatdu != 0.e0) qmdySc(&K2,&K0,&K0,&K0,&sdatdu,&irc);

    posSs("REFNO ",&K5,&irc);

    if(icompr(&trtype,"        ",&K8) == 0 && nview == 0) posSs("TRANSACTION TYPE",&K16,&irc);
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2050;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2050;

    soutSs("B ",&K3,"RETURN after Reference#~",&K0,&irc);
    soutSs("C ",&K6,&K0,&K0,&irc);
    namdSs("C ","V/C$INFO",&K8,"    ",&irc);

S2000:
    iflag = 0;                               /* TELL ME TWICE FLAG FOR DISCOUNT RATE 0 = FIRST TIME */

    rdpaSs("REFNO ",&K5,&K1,&irc);           /* READ SCREEN THRU REFERENCE# */
    soutSs("C ",&K3,&K0,&K0,&ircb);          /* CLEAR VENDOR NAME */
    namdSs("C ","V/C$INFO",&K8,"    ",&ircb);
    if(irc == 0) goto S2200;
    if(irc == 4) goto S2100;
    if(irc == 8) goto S1800;
    goto S9000;

S2050:

    /*
         AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    soutSs("C ",&K6,&K0,&K0,&irc);
    soutSs("C ",&K3,&K0,&K0,&ircb);          /* CLEAR VENDOR NAME */
    namdSs("C ","V/C$INFO",&K8,"    ",&ircb);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    rdpaSs("REFNO ",&K5,&K11,&irc);
    goto S2200;

S2100:
    errSs("Screen cannot be SAVED until data has been entered~",&K0,&irc);
    goto S2000;

S2200:
    dataSs("FUNC",&K4,&nfunc,&K1,&ircf);

    /*
     ----- If Verify Batch test for invalid function

    */
    if(nswvb == 0) goto S2210;
    if(nfunc == *(short*)fifstrgv("R ",2) || nfunc == *(short*)fifstrgv("L ",2) || nfunc == *(short*)fifstrgv("N ",2) ||
      nfunc == *(short*)fifstrgv("S ",2)) goto S2210;
    errSs("Verify Batch - only 'R', 'L', 'N' and 'S' are valid~",&K0,&irc);
    posSs("FUNC",&K4,&irc);
    goto S2000;

S2210:
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
         VIEWING ONLY ALLOWED (LIST OR NEXT) ON A CLOSED BATCH

    */
    errSs("Batch is CLOSED.  Viewing only.  Enter 'L' or 'N'~",&K0,&irc);
    goto S2240;

S2240:
    if(ircf == 0) blnkSs("FUNC",&K4,&irc);
    if(ircf != 0) starSs("FUNC",&K4,&irc);
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

S2320:

    /*
     ----- Check for Invalid Reference Number

    */
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

S2350:

    /*
         IF AN ITEM IS TO BE CHANGED, DELETED, OR LISTED, IT SHOULD ALREADY  BE
            ON FILE

    */
    if(irc == 1 || irc == 2) goto S2370;     /* IT IS ON FILE */
    errSs("This Reference# is not on file in this Batch~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2370:

    /*
         DISPLAY PREVIOUSLY ENTERED SOURCE DOCUMENT

    */
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
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);
    if(irc == 0) errSs("For viewing only.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    goto S1800;

S2900:

    /*
         'DELETE' - CONFIRM THAT THIS ITEM IS TO BE DELETED

    */
    errSs("RETURN to DELETE this item.  Otherwise, enter ^~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    if(irc == 8) goto S1800;

    /*
         DELETE THE REFERENCED ITEM FROM THIS BATCH

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    goto S1800;

S2950:

    /*
         Get and Display the 'NEXT' screen image

    */
    iSnext(&batch,&refno,&irc);
    if(irc <= 1) goto S2955;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S9000;/* END OF A 'RE-ENTER' SERIES */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S9000;/* END OF A 'RE-ENTER' SERIES */
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

    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);

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

S3000:

    /*
     ----------------------------------------------------------------------

         'ADD' or 'CHANGE' - PROCESS INPUT SCREEN

    */
    protSs("FUNC",&K4,&K1,&K0,&irc);
    protSs("REFNO ",&K5,&K1,&K0,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    idsflg = idsmod;

    /*
         AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3060;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3060;

    errSs("Enter Purchase data.~",&K0,&irc);
    posSs("VCNO",&K4,&irc);
    idsflg = idsmod;

S3050:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* SAVE THIS SCREEN IF RE-ENTERING */
    readSs(&K1,&irc);
    if(irc == 0) goto S3100;
    if(irc == 4) goto S8050;
    if(irc == 8) goto S1800;
    goto S9000;

S3060:

    /*
     ----- Verify Batch Processing

    */
    if(nswvb == 0) goto S3080;               /* This is not a Verify Batch */

    /*
         Output vendor name

    */
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    if(irc != 0) goto S3061;

    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    if(irc != 0) goto S3061;

    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);

S3061:

    /*
     ----- Output the Verify Batch Message

    */
    posSs("PARK",&K4,&irc);
    errSs("Verify...  RETURN if correct, or '^' to revise~",&K0,&irc);
    bangSs(&irc);
    if(irc == 0) goto S3062;                 /* verified */
    if(irc == 8) goto S3075;                 /* to be revised */
    goto S9000;

S3062:

    /*
     ----- Verify ok - Delete entry

     ----- Get the information from the screen for releasing the 'Hold' on
             the invoice

    */
    readSs(&K11,&irc);
    if(irc != 0) goto S3074;

    dataSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    dataSs("INVOICE ",&K7,&invoic,&K8,&irc);

    if(icompr(&trtype,&typlst,&K8) == 0) goto S3070;
    typlst = trtype;

    /*
     ----- Look for Genl Info Switch for Holding all Invoices

    */
    fill(xhold_hScode,&K4,"  ");

    WRITE(INTERNAL,keygi,27,FMT,F3064,1,REAL8,trtype,0);
    gnliSc("READ",keygi,&K27,inhld,&K76,&irc);
    if(irc != 0) gnliSc("READ","HOLD ALL INVOICES",&K17,inhld,&K76,&irc);
    if(irc != 0) goto S3065;

    /*
     ----- Get the Hold Code from the data buffer if not blank

    */
    getrsn(inhld,xhold_hScode,xhold_hSresn,&irc);
    if(irc > 6) mvbyt("ALL     ",xhold_hScode,&K8);

S3065:
    WRITE(INTERNAL,keygi,33,FMT,F3067,1,REAL8,trtype,0);
    gnliSc("READ",keygi,&K33,inhld,&K76,&irc);
    if(irc != 0) gnliSc("READ","HOLD ALL TRADE INVOICES",&K23,inhld,&K76,&irc);
    if(irc != 0) goto S3070;

    /*
     ----- Get the Hold Code from the data buffer in not blank

    */
    getrsn(inhld,xhold_hScode,xhold_hSresn,&irc);
    if(irc > 6) mvbyt("TRADE   ",xhold_hScode,&K8);

S3070:
    xhold_hSfunc = *(short*)fifstrgv("R ",2);
    mvbyt(xc_cScoid,xhold_hScoid,&K4);
    mvbyt(&trtype,xhold_hStype,&K8);
    xhold_hSvcno = vcno;
    mvbyt(&invoic,xhold_hSinvc,&K8);

    for(i=1; i==1 || i<=13; i++)
    {
        dataSs(&fldnam[i-1][2],&K8,&vbjob,&K0,&irc);
        if(irc != 0) goto S3074;
        if(vbjob == fifdint(vbjob)) vbjob = combjp(&vbjob,&R4);
        spltjp(&vbjob,&xhold_hSjob,&xhold_hSphs,&irc);
        invhld(&irc);
    }

S3074:
    iSdlet(&batch,&refno,&irc);
    goto S1800;

S3075:
    errSs("Revise as necessary.  Then, RETURN to enter.~",&K0,&irc);

    /*
     ----- Read revised version of reference from screen

    */
    readSs(&K1,&irc);
    if(irc == 0) goto S3100;
    if(irc == 8) goto S1800;
    goto S9000;

S3080:

    /*
     ----- Read the information from the screen

    */
    readSs(&K11,&irc);
    if(irc == 4) goto S8000;
    goto S3100;

S3100:

    /*
         get override effective date

    */
    mdySc("G ","EFFECTIVE",&K9,&effdat,&datout,&irc);
    if(irc != 0) goto S3120;

    for(i=1,D6=(D6=(7-i+1))>0?D6:1; D6>0; D6--,i+=1)
    {
        clsdSc(&i,&effdat,"W ",&irc);
        if(irc == 0) goto S3110;
        blnkSs("MONTH EFFECTIVE",&K15,&irc);
        blnkSs("DAY EFFECTIVE",&K13,&irc);
        blnkSs("YEAR EFFECTIVE",&K14,&irc);
        goto S3050;
S3110:;
    }

    goto S3125;

S3120:

    effdat = effbat;

S3125:

    xbilcom_bSdate = effdat;

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effdat,&vatrt,&irc);

    /*
         GET TRANSACTION TYPE

    */
    dataSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    if(irc != 4) goto S3130;                 /* EMPTY FIELD */
    errSs("Enter Transaction Type~",&K0,&irc);
    starSs("TRANSACTION TYPE",&K16,&irc);
    goto S3050;

S3130:

    /*
     --- VALIDATE TRANSACTION TYPE

    */
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
     --- GET ACCOUNT NUMBERS

    */
    tracSc(&trtype,accts,&irc);
    if(irc != 0) goto S3175;

    apgl = accts[0];
    dscern = accts[6];
    vatcr = accts[8];
    vatdr = accts[9];

    if(apgl < 0.001e0) goto S3175;
    if(dscern < 0.001e0) goto S3175;
    if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && vatcr < 0.001e0) goto
      S3175;

    if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && vatdr < 0.001e0) goto
      S3175;

    goto S3210;

S3175:
    ferrSc(&K9999,&K10,"Use TR ACCOUNT to establish ledger accounts for A/P~",&K0);

S3210:

    /*
         Get any overide account numbers from this screen

    */
    ovracc("TRADE PAY ACCOUNT     ",&K22,&apgl,&irc);
    if(irc > 4) goto S3050;

    ovracc("DISCOUNT EARN ACCOUNT ",&K22,&dscern,&irc);
    if(irc > 4) goto S3050;

    ovracc("VAT OUTPUT ACCOUNT    ",&K22,&vatcr,&irc);
    if(irc > 4) goto S3050;

    ovracc("VAT INPUT ACCOUNT     ",&K22,&vatdr,&irc);
    if(irc > 4) goto S3050;

    /*
     --- GET VENDOR NUMBER

    */
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    if(irc == 0) goto S3220;
    errSs("Enter vendor number~",&K0,&irc);
    starSs("VCNO",&K4,&irc);
    goto S3050;

S3220:

    /*
     ---- CHECK FOR VENDOR IN V/C ROSTER

    */
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);

    if(irc == 0) goto S3230;
    if(irc == 7) goto S3225;
    errSc(&K20,&irc,"FILE: V/C$INFO   PROGRAM: TR PURCHASE~",&K0,&irc);
    bangSs(&irc);
    goto S9000;
S3225:
    errSs("Vendor not in Vendor/Client roster.~",&K0,&irc);
    blnkSs("VCNO",&K4,&irc);
    goto S3050;
S3230:
    vinfSc(&vcno,"    ","FOREIGN ",&K7,&iforgn,&K2,&K0,&K0,&irc);
    fordom = 1;                              /* Domestic Vendor */
    if(iforgn == *(short*)fifstrgv("X ",2)) fordom = 2;/* Foriegn Vendor */

    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);

    /*
     --- GET CLIENT NUMBER (optional, for automatic billing)

    */
    dataSs("CLIENT",&K6,&client,&K0,&irc);
    if(irc != 0) goto S3270;

    /*
     ---- CHECK FOR CLIENT IN V/C ROSTER

    */
    vinfSc(&client,"    ","NAME",&K4,ivname,&K1,&K0,&K0,&irc);
    if(irc == 0) goto S3270;
    if(irc == 7) goto S3265;
    errSc(&K20,&irc,"Looking for CLIENT in V/C$INFO~",&K0,&irc);
    bangSs(&irc);
    goto S9000;

S3265:
    errSs("Client not in Vendor/Client roster.~",&K0,&irc);
    blnkSs("CLIENT",&K6,&irc);
    goto S3050;

S3270:

    /*
    ------Get the NON-BILLABLE field from the top of the screen if it exist

    */
    dataSs("NON-BILLABLE",&K12,&nonbil,&K2,&ircnon);

    /*
     ----- Get the Invoice Number.  If it is blank and the Configuration
           Parameter 'INVOICE FROM REFERENCE' is in place then default
           Invoice to Reference.

    */
    dataSs("INVOICE ",&K7,&invoic,&K8,&irc);
    if(irc == 0) goto S3320;
    if(irc == 1) goto S3330;
    if(!invref) goto S3310;
    mvwrd(&refno,&invoic,&K4);
    doutSs("INVOICE ",&K7,&invoic,&K8,&irc);
    goto S3320;

S3310:
    errSs("Enter invoice number~",&K0,&irc);
    starSs("INVOICE ",&K7,&irc);
    goto S3050;
S3320:

    /*
         Get invoice information from 'Invoice Tracking File', if possible
         1st parameter is the commitment type (P, S or C)

    */
    linvSc("P ",&vcno,&invoic,&irc);
    if(irc == 7) goto S3050;                 /* not found, but required for this vendor */
S3330:

    /*
         Read Commitment ID

    */
    dataSs("PO",&K2,&po,&K8,&irc);
    if(irc == 0 || irc == 1) goto S3420;
    errSs("Enter Purchase Order Number~",&K0,&irc);
    starSs("PO",&K2,&irc);
    goto S3050;
S3420:

    /*
    ------Geta JOB/PHASE, ACCOUNT, and ACTIVITY from the top of the screen
          if the fields exist.

    */
    dataSs("JOBPH ",&K5,&rjobph,&K0,&ircSjp);

    dataSs("DRACCT",&K6,&drSacc,&K0,&ircSac);

    dataSs("ACTIV ",&K5,iactiv,&K10,&ircSat);

    /*
     --- GET INVOICE DATE -  INVOICE DATE = EFFECTIVE DATE IF NOT ENTERED

    */
    gmdySc(&K1,&nm1,&nd1,&ny1,&datinv,&irc);
    if(datinv > 0.e0 && irc == 0) goto S3500;
    if(datinv > 0.e0 && irc != 0) goto S3490;
    if(datinv == 0.e0) datinv = effdat;
    goto S3500;

S3490:
    errSs("Invalid Invoice Date~",&K0,&irc);

    blnkSs("YEAR1 ",&K5,&irc);
    blnkSs("DAY1",&K4,&irc);
    blnkSs("MONTH1",&K6,&irc);
    goto S3050;

S3500:

    /*
     --- GET DUE DATE

    */
    gmdySc(&K2,&nm2,&nd2,&ny2,&datdue,&irc);

    sdatdu = datdue;                         /* SAVE DATE DUE FOR NEXT SCREEN SL 1/6/89 */

    if(datdue > 0.e0 && irc == 0) goto S3640;
    if(datdue > 0.e0 && irc != 0) goto S3530;

    dueSc(&vcno,&datinv,&datdue,&irc);
    if(irc == 0) goto S3640;
    if(irc == 1) goto S9100;

S3530:
    if(datdue == 0.e0) errSs("Enter Due Date~",&K0,&irc);
    if(datdue > 0.e0) errSs("Invalid Due Date~",&K0,&irc);
    blnkSs("YEAR2 ",&K5,&irc);
    blnkSs("DAY2",&K4,&irc);
    blnkSs("MONTH2",&K6,&irc);
    goto S3050;

S3640:

    /*
     ----- Check Due Date vs Open Thru Date for the Purchase Journal

    */
    ckdue(&datdue,&irc);
    if(irc != 0) goto S3050;

    /*
     --- GET PPS APPLICABLE FLAG

    */
    if(iswpps == 0) goto S3650;              /*  NO PPS FOR THIS SCREEN */
    ppstax(&vcno,&effdat,&pps1,icert,&irc);
    if(irc != 0) pps1 = -1.e0;

    pps2 = pps1;                             /* INIT INPUT RATE TO STORED RATE */

    if(nfunc == *(short*)fifstrgv("A ",2)) goto S3642;

    /*
     --- IF CHANGE SHOW RATE FROM V/C$INFO UNLESS IT HAS BEEN OVERRIDEN
          TO "N"OT APPLICABLE

    */
    dataSs("PPS APPLICABLE",&K14,&ppsout[0],&K4,&irc);
    if(irc != 0 || ppsout[0] == *(double*)fifstrgv("N       ",8)) pps2 = -1.e0;

S3642:

    /*
     --- OUTPUT PPS RATE (OR "N"OT APPLICABLE) TO SCREEN

    */
    if(pps2 < 0.e0) ppsout[0] = *(double*)fifstrgv("N       ",8);
    if(pps2 >= 0.e0) WRITE(INTERNAL,ppsout,5,FMT,F3645,1,REAL8,pps2,0);
    doutSs("PPS APPLICABLE",&K14,&ppsout[0],&K5,&irc);

S3650:

    /*
     --- GET INVOICE TOTAL

    */
    dataSs("TOTAL INVOICE",&K13,&cramnt,&K0,&irc);
    if(irc == 0) goto S3720;
    errSs("Enter invoice amount.~",&K0,&irc);
    blnkSs("TOTAL INVOICE",&K13,&irc);
    goto S3050;
S3720:

    /*
         IDSFLG = IDSMOD

    */
    dataSs("DISCOUNT",&K8,adisc,&K8,&irc);
    disc = 0.e0;
    if(irc == 0) goto S3820;
    vinfSc(&vcno,"    ","DISCOUNT",&K8,&disc,&K0,&K0,&K0,&irc);
    if(disc == 0.e0) goto S3820;
    doutSs("DISCOUNT",&K8,&disc,&K0,&irc);
    idsflg = 1;
S3820:
    lstrSa("$ ",1,adisc,8,&ifc,&ilc);
    if(ifc == 0) goto S3730;
    idsflg = 0;
    msubSa("  ",1,1,1,adisc,8,ifc,ifc);
    if(READ(INTERNAL,adisc,8,IOSTAT,NULL,1,FMT,F3785,1,REAL8,&disc,0)) goto S3790;
    goto S3800;

S3730:
    lstrSa("% ",1,adisc,8,&ifc,&ilc);
    if(ifc == 0) goto S3780;
    idsflg = 1;
    msubSa("  ",1,1,1,adisc,8,ifc,ilc);
    if(READ(INTERNAL,adisc,8,IOSTAT,NULL,1,FMT,F3785,1,REAL8,&disc,0)) goto S3790;
    goto S3800;

S3780:
    if(adisc[0] == *(double*)fifstrgv("        ",8)) goto S3800;
    if(READ(INTERNAL,adisc,8,IOSTAT,NULL,1,FMT,F3785,1,REAL8,&disc,0)) goto S3790;
    goto S3800;

S3790:
    errSs("Re-enter discount as numeric only.~",&K0,&irc);
    goto S3050;

S3800:
    if(idsflg == 0) soutSs("P ",&K4,"Discount$",&K9,&irc);
    if(idsflg == 0) soutSs("P ",&K5,"Discount%",&K9,&irc);
    if(idsflg == 1) soutSs("P ",&K4,"Discount%",&K9,&irc);
    if(idsflg == 1) soutSs("P ",&K5,"Discount$",&K9,&irc);

    /*
         DETERMINE PRO-RATA DISCOUNT ALLOCATION RATIO

    */
    dscfac = 0.e0;

    /*
         IF ( NFUNC .EQ. 'C ' ) IDSFLG = 0       DISC IS ALREADY $$$$
    */
    if(idsflg == 0) goto S3826;              /* IF DISCOUNT NOT %%%% */
    /*
                               IF DISCOUNT A %, CONVERT TO AN AMOUNT
    */
    dscfac = disc*0.01e0;
    disc = dscfac*cramnt;
    /*
         DDISC = DSCFAC * 100D0
    */
    WRITE(INTERNAL,xc_cSmess,12,FMT,F3825,1,REAL8,disc,0);
    /*
    3825  FORMAT ( B'ZZ#.##', '% Disc' )
    */
    soutSs("P ",&K6,xc_cSmess,&K10,&irc);
    goto S3841;

S3826:

    /*
     ---- Display $ discount from % discount

    */

    /*
     ----- CODE MODIFIED HERE PER WORK ORDER KGC-0020
           DISCOUNT RATE LIMIT RAISED TO 30% ***DEI***

    */
    if(cramnt != 0) dscfac = disc/cramnt;    /* RATIO FOR DISTRIBUTING DISCOUNT */
    ddisc = dscfac*100.e0;
    WRITE(INTERNAL,xc_cSmess,12,FMT,F3831,1,REAL8,ddisc,0);
    soutSs("P ",&K6,xc_cSmess,&K12,&irc);

S3841:
    if(iameq(&dscfac,&R7) < 1) goto S3835;

    errSs("Discount Rate cannot be greater than 30%~",&K0,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    goto S3050;

S3835:

    /*
     ----- CODE ADDED HERE IN RESPONSE TO WORK ORDER KGC-0020
           TEST IF DISCOUNT IS LESS THAN 10 %, AND IF >= 10 %
           PROCESS AS A 'TELL ME TWICE' CONFIRM TO FINALIZE.

     ----- IF THE DISCOUNT IS < 10 % - DISREGARD AND PROCESS AS BEFORE.

    */
    if(iameq(&dscfac,&R8) < 1) goto S3845;

    /*
     ----- DISCOUNT IS >=10% AND <=30% - TEST TO SEE IF THIS IS
           THE CONFIRMING (SECOND) PASS THROUGH - IF SO - CHECK THE
           DATA (DISCOUNTS AND INVOICE AMOUNTS) FOR A MATCH.

     ----- TEST THE FUNCTION INDICATOR - IF R - DO NOT
           TEST FOR THE 10% SOLUTION...

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3845;
    if(iflag == 1) goto S3840;               /* SECOND PASS THROUGH */

    /*
     ----- FIRST TIME THROUGH - SET PROCESSING INFORMATION

    */
    iflag = 1;
    olddsc = dscfac;
    craold = cramnt;
    errSs("Discount is greater than 10% - RETURN to confirm~",&K0,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    goto S3050;                              /* RETURN TO READ$S TO RE-READ SCREEN INPUTS */

S3840:

    /*
     ----- SECOND TIME THROUGH FOR DISCOUNT >= 10%
           TEST 'SAMENESS' OF DISCOUNTS AND INVOICE AMOUNTS
           IF SAME - PROCESS AS BEFORE - OTHERWISE RESET THE
           'OLD' TEMPORARY VARIABLES AND RE-REQUEST CONFIRMATION.

    */
    if(iameq(&olddsc,&dscfac) == 0 && iameq(&craold,&cramnt) == 0) goto S3845;

    /*
     ----- RESET THE TEMPORRARY STORE VARIABLES AND REREAD SCREEN

    */
    iflag = 1;                               /* KEEP FLAG SET TO REQUEST CONFIRMATION OF DATA */
    olddsc = dscfac;
    craold = cramnt;
    errSs("Discount is greater than 10% - RETURN to confirm~",&K0,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    goto S3050;                              /* RETURN TO READ$S TO RE-READ SCREEN INPUTS */

S3845:

    /*
     --- GET TOTAL VAT AMOUNT AND PRO-RATA VAT RATIO

    */
    vatpct = 0.e0;
    iexvat = 0;
    vinfSc(&vcno,"    ","VAT EXEMPTED",&K12,&idum,&K1,&K0,&K0,&irc);
    if(irc == 0 && idum == *(short*)fifstrgv("Y ",2)) iexvat = 1;

    vatpct = vatrt/100.e0;
    dataSs("TOTAL VAT",&K9,&vattot,&K0,&irc);
    if(irc != 0) goto S3850;

    dataSs("VAT TYPE",&K8,&vatype,&K2,&ircvat);
    if(ircvat != 0) goto S3680;
    if(vatype == *(short*)fifstrgv("F ",2) || vatype == *(short*)fifstrgv("G ",2) || vatype == *(short*)fifstrgv("S ",2)
      ) goto S3680;
    blnkSs("VAT TYPE",&K8,&irc);
    errSs("Invalid Vat Type, Enter F or G or S ~",&K0,&irc);
    goto S3050;

S3680:
    if(ircvat == 0) vatSac(&trtype,vatact,vatdsc,despnt,&irc);
    accpay = 2;                              /* Payable */
    if(vatype == *(short*)fifstrgv("F ",2)) ifgs = 1;/* Fixed Assets */
    if(vatype == *(short*)fifstrgv("G ",2)) ifgs = 2;/* Goods */
    if(vatype == *(short*)fifstrgv("S ",2)) ifgs = 3;/* Services */
    if(vatype == *(short*)fifstrgv("S ",2)) accpay = 1;/* Accrued */

    divisr = cramnt-vattot;
    if(divisr != 0.e0) vatpct = vattot/divisr;/* DO NOT DIVIDE BY ZERO */

    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S3860;

    if(cramnt != 0.e0) vatpct = vattot/cramnt;
    goto S3860;

S3850:
    if(iexvat == 1) goto S3860;
    vattot = 0.e0;
    if(vatpct != -1.e0) vattot = cramnt-cramnt/(1.e0+vatpct);/* DO NOT DIVIDE BY ZERO */
    vattot = rndoff(&vattot,&K2);
    doutSs("TOTAL VAT",&K9,&vattot,&N1,&irc);

S3860:
    if(idsflg == 0) goto S3700;
    disc = (cramnt-vattot)*dscfac;
    /*
         CALL DOUT$S ( 'DISCOUNT', 8, DISC, -1, IRC )

    */
S3700:
    divsor = cramnt-vattot;
    if(idsflg == 0 && divsor != 0.0e0) dscfac = disc/divsor;

    /*
         IDSFLG = 0

     --- IF NATION CODE IS "NZ" or "AU" THEN RE-CALCULATE DISCOUNT FACTOR
         USING THE VALUE ADDED TAX AMOUNT

    */
    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S3870;

    dscfac = 0.e0;
    divisr = cramnt-disc-vattot;
    if(divisr != 0.e0) dscfac = disc/divisr; /* DO NOT DIVIDE BY ZERO */

S3870:
    dataSs("TOTAL SALES TAX",&K15,&stxtot,&K0,&irctax);
    for(i=1; i==1 || i<=13; i++)
    {
        icaltx[i-1] = -1;
    }
    taxabl = 0.e0;
    taxemt = 0.e0;

    dataSs("TAX CODE",&K8,&codtax,&K8,&irc);
    if(irc == 0) goto S3890;
    codtax = *(double*)fifstrgv("        ",8);
    goto S3900;

S3890:
    iopt = 2;
    staxSc(&iopt,&codtax,&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

    if(irc == 0) goto S3895;
    blnkSs("TAX CODE",&K8,&irc);
    errSs("Invalid Sales Tax Code~",&K0,&irc);
    goto S3050;

S3895:
    doutSs("SALES TAX LOCATION",&K18,loctax,&K40,&irc);
    doutSs("SALES TAX RATE",&K14,&taxrat,&N1,&irc);

S3900:
    dataSs("MISC",&K4,&rmisc,&K0,&irc);
    if(irc == 0) goto S3910;
    rmisc = 0;

S3910:
    ttaxbl = 0.0e0;
    for(i=1; i==1 || i<=13; i++)
    {
        dataSs(&fldnam[i-1][0],&K8,&amnts[i-1],&K0,&irc);
        dataSs(&fldnam[i-1][12],&K8,&taxcod[i-1],&K8,&irc);
        if(irc != 0) mvwrd(&codtax,&taxcod[i-1],&K4);
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S3925;
        ttaxbl = ttaxbl+amnts[i-1];
S3925:;
    }

    dataSs("AMOUNT SUBJECT TO TAX",&K21,&sbtotx,&K0,&ircsub);
    if(ircsub != 0) sbtotx = ttaxbl;
    if(sbtotx >= 0.0e0 && ttaxbl >= 0.0e0) goto S3930;
    if(sbtotx <= 0.0e0 && ttaxbl <= 0.0e0) goto S3930;
    errSs("Total Taxable and Amount Subject to Tax must have same sign~",&K0,&irc);
    starSs("AMOUNT SUBJECT TO TAX",&K21,&irc);
    goto S3050;

S3930:
    if(iameq((T9= fabs(sbtotx),&T9),(T10= fabs(ttaxbl),&T10)) <= 0) goto S3940;
    errSs("Amount Subject to Tax may be more than Total Taxable~",&K0,&irc);
    starSs("AMOUNT SUBJECT TO TAX",&K21,&irc);
    goto S3050;

S3940:
    sbrtio = 1.0e0;
    if(ttaxbl != 0.0e0) sbrtio = sbtotx/ttaxbl;

    /*
     --- GET CLOSE COMMITMENT FLAG

    */
    nswcls = 0;
    dataSs("FINAL COMMITMENT PAYMENT",&K24,&idum,&K2,&irc);
    if(irc == 0) nswcls = 1;

    /*
     --- CHECK FOR COMMIT AS EXPENDED FIELD

    */
    nswcxp = 0;
    dataSs("COMMIT AS EXPENDED",&K18,&idum,&K2,&irc);
    if(irc == 0) nswcxp = 1;

    /*
     --- CHECK TO INVALID COMBINATION OF ENTRIES

    */
    if(icompr(&po,"-       ",&K8) == 0 && nswcls+nswcxp > 0) goto S3950;
    if(nswcls+nswcxp > 1) goto S3975;
    goto S4000;

S3950:

    /*
     ---   PO = '-       '

    */
    blnkSs("FINAL COMMITMENT PAYMENT",&K24,&irc);
    blnkSs("COMMIT AS EXPENDED",&K18,&irc);
    errSs("Do not mark Final Payment or Commit as Expended;PO# indicates uncommited item~",&K0,&irc);
    goto S3050;

S3975:

    /*
     --- CAN NOT ENTER BOTH FINAL PAYMENT AND COMMIT AS EXPENDED

    */
    blnkSs("FINAL COMMITMENT PAYMENT",&K24,&irc);
    blnkSs("COMMIT AS EXPENDED",&K18,&irc);
    errSs("Do not mark both Final Payment and Commit as Expended ~",&K0,&irc);
    goto S3050;

S4000:
    crjacc = apgl;                           /* LOAD DEFAULT PAYABLES ACCOUNT */

    /*
    ------See if an ALLOCATION FORMULA has been entered for use
          in automaticaly distributing this invoice.

    */
    dataSs("ALLOCATION FORMULA",&K18,&alloc,&K8,&irc);

    if(irc != 0) goto S4070;

    /*
    -------See if data is already on the screen, if so do not output distribution

    */
    for(j=0; j==0 || j<13; j++)
    {

        dataSs(&fldnam[j][0],&K8,&ramnt,&K0,&irc);
        if(irc == 0) goto S4070;

    }

    mflag = FLSNXT+FLSUKY;
    ramnt = cramnt;
    icnt = 0;

    WRITE(INTERNAL,keyalc,44,FMT,F4010,1,DO,2,INT2,xc_cScoid,REAL8,alloc,0);

    mvwrd(keyalc,keysv,&K22);

S4020:

    ioSf("FIND","MISC$INFO",&K9,"TRAL",keyalc,&K0,&mflag,&K0,&irc);

    if(irc == 7) goto S4060;

    if(icompr(keyalc,keysv,&K16) != 0) goto S4060;

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","PERCENT ",&K7,&perc,&K0,&K0,&K0,&irc);

    if(iameq(&perc,&R11) == 0) goto S4020;

    icnt = icnt+1;

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","JOB ",&K3,&rj,&K0,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","PHASE ",&K5,&rp,&K0,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","ACTIVITY",&K8,iact,&K10,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","ACCOUNT ",&K7,&ac,&K0,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","SALES TAX CODE",&K14,&stcode,&K8,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","MEMO",&K4,imem,&K16,&K0,&K0,&irc);

    rjp = combjp(&rj,&rp);
    doutSs(&fldnam[icnt-1][2],&K7,&rjp,&N1,&irc);

    doutSs(&fldnam[icnt-1][3],&K7,iact,&K10,&irc);

    doutSs(&fldnam[icnt-1][1],&K8,&ac,&N1,&irc);

    doutSs(&fldnam[icnt-1][12],&K8,&stcode,&K8,&irc);

    doutSs(&fldnam[icnt-1][4],&K6,imem,&K16,&irc);

    amt = (cramnt-stxtot)*perc/100.e0;
    roffSc(&amt,&R12,&irc);
    doutSs(&fldnam[icnt-1][0],&K8,&amt,&N1,&irc);

    ramnt = ramnt-amt;

    goto S4020;

S4060:
    if(icnt > 0) goto S4065;
    errSs("Invalid Allocation Formula.~",&K0,&irc);
    blnkSs("ALLOCATION FORMULA",&K18,&irc);
    goto S3050;

S4065:
    if(iameq(&ramnt,&R11) == 0) goto S4070;

    dataSs(&fldnam[icnt-1][0],&K8,&amt,&K0,&irc);

    amt = amt+ramnt;
    doutSs(&fldnam[icnt-1][0],&K8,&amt,&N1,&irc);

S4070:

    /*
         GET DUP SWITCH (YES or NO)

    */
    dataSs("DUP ",&K3,&ndup,&K1,&irc);
    if(ndup == *(short*)fifstrgv("N ",2) || ndup == *(short*)fifstrgv("Y ",2)) goto S4090;
    errSs("Must be 'Y' or 'N'~",&K0,&irc);
    starSs("DUP ",&K3,&irc);
    goto S3050;
S4090:

    if(ndup != *(short*)fifstrgv("Y ",2)) goto S4210;

    nodup = 0;
    lstlin = 1;
    fill(lactxt,&K5,"  ");

    for(i=1; i==1 || i<=13; i++)
    {

        dataSs(&fldnam[i-1][0],&K8,&amnts[i-1],&K0,&ircamt);
        dataSs(&fldnam[i-1][1],&K8,iactxt,&K10,&ircacc);
        dataSs(&fldnam[i-1][2],&K8,jobtxt,&K10,&ircjob);
        dataSs(&fldnam[i-1][3],&K8,&activs[i-1][0],&K10,&ircact);
        dataSs(&fldnam[i-1][4],&K8,&rmemo[i-1][0],&K16,&ircmem);
        dataSs(&fldnam[i-1][8],&K5,&invli[i-1],&K8,&ircinv);

        if(iactxt[0] != *(short*)fifstrgv("  ",2)) mvbyt(iactxt,lactxt,&K10);
        if(jobtxt[0] != *(short*)fifstrgv("  ",2)) mvbyt(jobtxt,ljbtxt,&K10);
        if(i == 1) goto S4200;

        if(ircamt != 0) goto S4200;
        if(ircacc == 0) goto S4110;
        nodup = nodup+1;
        doutSs(&fldnam[i-1][1],&K8,lactxt,&K10,&irc);
        blnkSs(&fldnam[i-1][1],&K8,&irc);

S4110:
        if(ircjob == 0) goto S4120;
        nodup = nodup+1;
        doutSs(&fldnam[i-1][2],&K8,ljbtxt,&K10,&irc);
        blnkSs(&fldnam[i-1][2],&K8,&irc);

S4120:
        if(ircact == 0) goto S4130;
        nodup = nodup+1;
        mvbyt(&activs[lstlin-1][0],&activs[i-1][0],&K10);
        doutSs(&fldnam[i-1][3],&K8,&activs[i-1][0],&K10,&irc);
        blnkSs(&fldnam[i-1][3],&K8,&irc);

S4130:
        if(ircmem == 0) goto S4140;
        nodup = nodup+1;
        mvbyt(&rmemo[lstlin-1][0],&rmemo[i-1][0],&K16);
        doutSs(&fldnam[i-1][4],&K8,&rmemo[i-1][0],&K16,&irc);
        blnkSs(&fldnam[i-1][4],&K8,&irc);

S4140:
        if(ircinv != 4) goto S4145;
        nodup = nodup+1;
        invli[i-1] = invli[lstlin-1];
        doutSs(&fldnam[i-1][8],&K5,&invli[i-1],&K8,&irc);
        blnkSs(&fldnam[i-1][8],&K5,&irc);

S4145:
        lstlin = i;

S4200:;
    }

    if(icompr(&nfunc,"R ",&K1) == 0) goto S4210;
    if(icompr(&nfunc,"X ",&K1) == 0) goto S4210;

    if(nodup < 1) goto S4210;
    errSs("Verify Duplicated Data. RETURN if correct. Otherwise, '^'~",&K0,&irc);
    bangSs(&irc);
    rstSs(&K0,&N1,&ircrst);                  /*  RESET BLINKING FIELDS */
    if(irc == 0) goto S4210;
    if(irc == 4) goto S8000;
    if(irc == 8) goto S3050;
    goto S9000;

S4210:

    tdist = 0.e0;
    tadisc = 0.e0;
    tvat = 0.e0;
    tstax = 0.e0;
    stxtot = 0.e0;
    taxabl = 0.e0;
    taxemt = 0.e0;
    ilast = 0;
    nswdup = 0;
    lstvat = 0;                              /* row of last automaticaly calculated VAT amount */
    lsttax = 0;

    for(i=1,D15=(D15=(13-i+1))>0?D15:1; D15>0; D15--,i+=1)
    {

        litem[i-1] = 0;                      /* RESET FLAG FOR 'LINE ITEM' */
        ircbak = 1;                          /* Set at No Back Chaerge amount to start with */

        vatamt[i-1] = 0.e0;
        taxamt[i-1] = 0.e0;

        if(!nqtyrc) goto S4100;
        mvnoSc(&i,namres,&K15,&irc);         /*  FIELD NAME FOR RESOURCE CODE */
        mvnoSc(&i,namqty,&K4,&irc);          /*  FIELD NAME FOR QTY */

S4100:

        /*
             INITIALIZE KEY INTERCOMPANY PARAMETERS

        */
        mvbyt("    ",&idchg[i-1][0],&K4);
        apict[i-1] = 0.e0;
        arict[i-1] = 0.e0;

        /*
             GET AMOUNT

        */
        dataSs(&fldnam[i-1][0],&K8,&amnts[i-1],&K0,&irc);

        if(irc != 1) goto S4125;

        /*
        -----See if a field named BACKCHARGE13 is on the screen

        */
        if(i != 13) goto S4800;

        dataSs("BACKCHGAMT13",&K12,&amnts[i-1],&K0,&ircbak);
        if(ircbak == 1) goto S4800;
        if(ircbak == 0) amnts[i-1] = -amnts[i-1];/* Reverse Sign */

S4125:

        dataSs(&fldnam[i-1][7],&K8,&vatamt[i-1],&K0,&irc);
        if(amnts[i-1] == 0.e0 && vatamt[i-1] == 0) goto S4700;

        /*
         --- GET LINE ITEM INVOICE NUMBER IF IT IS ON THE SCREEN

        */
        dataSs(&fldnam[i-1][8],&K5,&invli[i-1],&K8,&irc);
        if(irc != 1) linitm = TRUE;
        if(irc == 1) invli[i-1] = invoic;
        if(irc == 1) goto S4150;
        linvSc("P ",&vcno,&invli[i-1],&irc);
        if(irc == 7) goto S3050;             /* Not found but required for vendor */
S4150:

        /*
         --- GET LINE ITEM INVOICE DATE IF  IT IS ON THE SCREEN

        */
        if(invli[i-1] != *(double*)fifstrgv("        ",8)) goto S4155;

        starSs(&fldnam[i-1][8],&K5,&irc);
        errSs("This field must be entered~",&K0,&irc);
        goto S3050;

S4155:

        mvnoSc(&i,invdat,&K9,&irc);
        mdySc("G ",invdat,&K10,&invdli[i-1],&dum,&irc);
        if(irc != 0) invdli[i-1] = datinv;   /* USE THE DEFAULT */

        /*
         --- GET LINE ITEM PO NUMBER IF IT IS ON THE SCREEN

        */
        dataSs(&fldnam[i-1][10],&K4,&poli[i-1],&K8,&irc);
        if(irc == 1) poli[i-1] = po;         /* USE THE DEFAULT */

        /*
        ------Get the NONBIL field from this line if the field is there

        */
        inobil[i-1] = nonbil;
        if(ircnon != 0) dataSs(&fldnam[i-1][13],&K8,&inobil[i-1],&K2,&irc);

        /*
         --- GET LINE ITEM CLIENT NUMBER (optional field, used for billing)

        */
        dataSs(&fldnam[i-1][11],&K6,&clntli[i-1],&K0,&irc);
        if(irc != 0) goto S4170;

        /*
         ---- CHECK FOR CLIENT IN V/C ROSTER

        */
        vinfSc(&clntli[i-1],"    ","NAME",&K4,ivname,&K1,&K0,&K0,&irc);
        if(irc == 0) goto S4180;
        if(irc == 7) goto S4165;
        errSc(&K20,&irc,"Looking for CLIENT (by line item) in V/C$INFO~",&K0,&irc);
        bangSs(&irc);
        goto S9000;

S4165:
        errSs("Client not in Vendor/Client roster.~",&K0,&irc);
        blnkSs(&fldnam[i-1][11],&K6,&irc);
        goto S3050;

S4170:
        clntli[i-1] = client;                /* use default CLIENT for this reference */

S4180:

        /*
         --- GET LINE ITEM DISCOUT IF IT IS ON THE SCREEN

        */
        discli[i-1] = 0.e0;
        dataSs(&fldnam[i-1][9],&K6,&discli[i-1],&K0,&ircSd);

        litem[i-1] = 1;                      /* SET FLAG FOR 'LINE ITEM */

        tdist = tdist+amnts[i-1];

        /*
             DETERMINE PORTIN OF DISCOUNT TO BE ALLOCATED TO THIS LINE ITEM

        */
        adisc[i-1] = 1.e-2*fifdint(amnts[i-1]*dscfac*1.e2+.5001e0);
        if(linitm && ircSd == 0) adisc[i-1] = discli[i-1];
        tadisc = tadisc+adisc[i-1];          /* TALLY DISCOUNT ALLOCATED */
        if(ircSd == 4) doutSs(&fldnam[i-1][9],&K6,&adisc[i-1],&N1,&irc);
        lstdsc = i;                          /* SAVE LOCATION FOR LAST DISCOUNT */

        /*
         --- GET PRO-RATA VAT AMOUNT

        */
        dataSs(&fldnam[i-1][7],&K8,&vatamt[i-1],&K0,&irc);
        if(irc == 0) goto S4215;

        vatamt[i-1] = amnts[i-1]*vatpct;
        if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && vattot != 0.e0 &&
          cramnt != vattot) vatamt[i-1] = (amnts[i-1]+adisc[i-1])/(cramnt-vattot)*vattot;
        vatamt[i-1] = rndoff(&vatamt[i-1],&K2);
        doutSs(&fldnam[i-1][7],&K8,&vatamt[i-1],&N1,&irc);
        lstvat = i;                          /* save row of last automatically calculated VAT amount */
S4215:
        tvat = tvat+vatamt[i-1];

        /*
             GET ACCOUNT NUMBER

        */
        dataSs(&fldnam[i-1][1],&K8,&drjacc[i-1],&K0,&ircacc);
        if(ircacc == 0) goto S4220;
        if(ircSac != 0) goto S4216;
        drjacc[i-1] = drSacc;
        goto S4220;
S4216:
        if(ircbak == 0) goto S4220;
        if(nswdup == 1 && ndup == *(short*)fifstrgv("Y ",2)) goto S4220;
        errSs("Enter Account#~",&K0,&irc);
        starSs(&fldnam[i-1][1],&K8,&irc);
        goto S3050;
S4220:

        /*
             GET JOB & PHASE

        */
        dataSs(&fldnam[i-1][2],&K8,&rjobs[i-1],&K0,&irc);
        if(irc == 0) goto S4320;
        if(ircSjp != 0) goto S4225;
        rjobs[i-1] = rjobph;
        goto S4320;
S4225:
        if(ircbak == 0) goto S4230;
        if(nswdup == 1 && ndup == *(short*)fifstrgv("Y ",2)) goto S4350;
        errSs("Enter job/phase number.~",&K0,&irc);
        starSs(&fldnam[i-1][2],&K8,&irc);
        goto S3050;

        /*
        ------Look for a single Job/Phase to use for Back Charges

        */
S4230:
        bjob = 0.e0;
        for(k=0; k==0 || k<13; k++)
        {
            if(litem[k] == 0) goto S4240;
            if(rjobs[k] == 0.e0) goto S4240;
            if(bjob == 0.e0) bjob = rjobs[k];
            if(bjob != 0.e0 && bjob == rjobs[k]) goto S4240;
            errSs("Must enter Job/Phs for Back Charge~",&K0,&irc);
            goto S3050;
S4240:;
        }
        if(bjob != 0) goto S4250;
        errSs("Must enter Job/Phs for Back Charge~",&K0,&irc);
        goto S3050;

S4250:
        rjobs[i-1] = bjob;
        goto S4320;

S4320:
        if(rjobs[i-1] == fifdint(rjobs[i-1])) rjobs[i-1] = combjp(&rjobs[i-1],&R4);
        spltjp(&rjobs[i-1],&rjob,&phase,&irc);
S4350:

        /*
             GET ACTIVITY NUMBER

        */
        dataSs(&fldnam[i-1][3],&K8,&activs[i-1][0],&K10,&ircact);
        if(ircact == 0) goto S4445;
        if(ircSat != 0) goto S4445;
        mvwrd(iactiv,&activs[i-1][0],&K5);
        ircact = 0;
S4445:

        xc_cSvjob = fldnam[i-1][2];
        xc_cSvphs = *(double*)fifstrgv("        ",8);
        xc_cSvact = fldnam[i-1][3];

        frmaSc(&rjob,&phase,&activs[i-1][0],&irca);
        if(irca   >  1) goto S3050;
        if(ircact == 0) goto S4450;
        if(ircbak == 0) goto S4450;
        if(nswdup == 1 && ndup == *(short*)fifstrgv("Y ",2)) goto S4450;
        errSs("Enter activity number.~",&K0,&irc);
        starSs(&fldnam[i-1][3],&K8,&irc);
        goto S3050;
S4450:
        if(ircact == 0) doutSs(&fldnam[i-1][3],&K8,&activs[i-1][0],&K10,&irc);
        if(ircSat == 0) doutSs("ACTIV ",&K5,&activs[i-1][0],&K10,&irc);

        /*
        -------Get Account and Activity for Back Charges

        */
        if(ircbak != 0) goto S4485;          /* Not a Back Charge on this line */
        if(ircact == 0) goto S4455;          /* Already have an activity */
        vctlSc("F ",&vcno,&rjob,&phase,"          ",&po,"BACK CHARGE ACTIVITY",&K20,&activs[i-1][0],&K10,&irc);
        frmaSc(&rjob,&phase,&activs[i-1][0],&irca);
        if(irc == 0) goto S4455;
        errSs("Invalid Activity for Back Charge~",&K0,&irc);
        goto S3050;

S4455:
        if(ircacc == 0) goto S4485;
        vctlSc("F ",&vcno,&rjob,&phase,&activs[i-1][0],&po,"BACK CHARGE ACCOUNT",&K19,&drjacc[i-1],&K0,&irc);
        if(irc == 0) goto S4485;
        errSs("Invalid Account for Back Charge~",&K0,&irc);
        goto S3050;

S4485:

        /*
             VALIDATE JOB/PHASE/ACTIVITY#

        */
        valdSc(&K1,&rjob,&phase,&activs[i-1][0],&drjacc[i-1],&ircv);
        if(ircv == 0) goto S4470;
        blnkSs(&fldnam[i-1][2],&K8,&irc);
        if(ircv >= 2 && ircv != 5) blnkSs(&fldnam[i-1][3],&K8,&irc);
        if(ircv >= 3) blnkSs(&fldnam[i-1][1],&K8,&irc);
        goto S3050;

S4470:

        /*
             VALIDATE DEBIT ACCOUNT

        */
        vglaS2("Debit               ","I ","E ","D ",&rjob,&phase,&activs[i-1][0],&drjacc[i-1],&dracct[i-1],&irc);
        if(irc == 0) goto S4480;
        blnkSs(&fldnam[i-1][1],&K8,&irc);
        goto S3050;
S4480:

        /*
             VALIDATE CREDIT ACCOUNT

        */
        vglaS2("Credit              ","A ","E ","C ",&rjob,&phase,&activs[i-1][0],&crjacc,&cracct[i-1],&irc);
        if(irc == 0) goto S4490;
        blnkSs("CRACCT",&K6,&irc);
        goto S3050;
S4490:

        /*
             SET UP ACCOUNT FOR DISCOUNT EARNED FOR EACH LINE ITEM THAT HAS A DISCOUNT,
                IF NATION CODE IS 'NZ' or 'AU' USE DISTRIBUTION JOB AND PHASE
                IF NOT 'NZ' or 'AU' USE DEFAULT ADMINISTRATIVE JOB AND PHASE

        */
        if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) vglaSc("A ",&rjob,&phase,&
          dscern,&dsc[i-1],&irc);

        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) vglaSc("A ",&xc_cSdacj,&
          xc_cSdacp,&dscern,&dsc[i-1],&irc);

        if(irc == 0) goto S4495;

        bangSs(&irc);

        errSs("Invalid Ledger Account for 'Discounts Earned' in TR ACCOUNT~",&K0,&irc);
        blnkSs("DISCOUNT",&K8,&irc);
        goto S3050;

S4495:

        /*
             GET MEMO

        */
        dataSs(&fldnam[i-1][4],&K8,&rmemo[i-1][0],&K16,&irc);
        if(irc == 0) goto S4498;
        if(!rqmemo) goto S4498;

        starSs(&fldnam[i-1][4],&K8,&irc);
        errSs("A memo is required~",&K0,&irc);
        goto S3050;

S4498:

        /*
        ------Get TAXCODnn if it is on the screen

        */
        dataSs(&fldnam[i-1][12],&K8,&taxcod[i-1],&K8,&irc);
        if(irc != 0) mvwrd(&codtax,&taxcod[i-1],&K4);
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S4510;

        iopt = 2;
        staxSc(&iopt,&taxcod[i-1],&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

        if(irc == 0) goto S4500;
        blnkSs(&fldnam[i-1][12],&K8,&irc);
        errSs("Invalid Sales Tax Code~",&K0,&irc);
        goto S3050;

S4500:
        doutSs(&fldnam[i-1][16],&K8,"          ",&K10,&irc);
        doutSs(&fldnam[i-1][14],&K8,loctax,&K40,&irc);

        if(icaltx[i-1] == 0) goto S4501;
        dataSs(&fldnam[i-1][15],&K8,&taxamt[i-1],&K0,&irc);
        icaltx[i-1] = 1;
        if(irc == 0) icaltx[i-1] = 0;
        if(icaltx[i-1] == 0) goto S4502;
S4501:
        taxamt[i-1] = amnts[i-1]*saltax*sbrtio*.01e0;
        lsttax = i;
        roffSc(&taxamt[i-1],&R13,&irc);
        WRITE(INTERNAL,itax,9,FMT,F45011,1,REAL8,taxamt[i-1],0);
        doutSs(&fldnam[i-1][16],&K8,itax,&K9,&irc);
S4502:
        if(irctax == 0) goto S4503;
        if(icaltx[i-1] == 1) goto S4503;
        errSs("Must enter the Total Sales Tax control Amount~",&K0,&irc);
        starSs("TOTAL SALES TAX",&K15,&irc);
        goto S3050;
S4503:
        tstax = tstax+taxamt[i-1];
        if(irctax != 0) stxtot = tstax;

        subjct = amnts[i-1]*sbrtio;
        exempt = amnts[i-1]-subjct;
        taxabl = taxabl+subjct;
        taxemt = taxemt+exempt;

S4510:

        /*
         ----- GET RESOURCE CODE AND QUANITY IF THEY ARE ON THE SCREEN

        */
        if(!nqtyrc) goto S4530;
        dataSs(namqty,&K5,&quanty[i-1],&K0,&irc1);
        dataSs(namres,&K16,&irescd[i-1][0],&K16,&irc2);
        irc = irc1+irc2;
        if(irc == 0) goto S4525;
        if(irc == 8) goto S4530;
        starSs(namqty,&K5,&irc);
        starSs(namres,&K16,&irc);
        errSs("Enter both a quantity and a resource code~",&K0,&irc);
        goto S3050;

S4525:

        /*
         ----- VALIDATE THE RESOURCE CODE

        */
        vrscSc(xc_cScoid,&irescd[i-1][0],&irc);
        if(irc == 0) goto S4530;
        blnkSs(namres,&K16,&irc);
        errSs("Invalid Resource Code~",&K0,&irc);
        goto S3050;

S4530:

        /*
             CHECK COMPANY ID ASSOCIATED WITH JOB/PHASE TO SEE IF AN INTERCOMPANY
                TRANSACTION IS INDICATED

        */
        jinfSc(&rjob,&phase,"JC  ","COMPANY ID",&K10,&idchg[i-1][0],&K4,&K0,&K0,&irc);
        if(irc != 0) ferrSc(&K0,&irc,"COMPANY ID FOR JOB/PHASE~",&K0);

        if(icompr(&idchg[i-1][0],xc_cScoid,&K4) == 0) goto S4550;/* NO ICT INDICATED */
        /*
        /* INDICATED

         ----- Check Journal Close Dates for ICT

        */
        ckjrn2(&idchg[i-1][0],&K1,&effdat,&refno,&irc);
        if(irc == 0) goto S4545;
        starSs(&fldnam[i-1][2],&K8,&irc);
        goto S3050;

S4545:

        /*
             GET AUTHORIZATION FOR INTERCOMPANY CHARGE AND ASSOCIATED PARAMETERS

        */
        aictSc(&idchg[i-1][0],&drjacc[i-1],&apict[i-1],&arict[i-1],&irc);
        if(irc == 0) goto S4550;             /* ICT IS OK */

        /*
             BLINK ACCOUNT# & JOB# AND OUTPUT ERROR MESSAGE

        */
        blnkSs(&fldnam[i-1][1],&K8,&irc);
        blnkSs(&fldnam[i-1][2],&K8,&irc);
        errSs("Indicated Intercompany charge is NOT authorized~",&K0,&irc);
        goto S3050;

S4550:

        /*
         --- GET CLOSE COMMITMENT FLAG

        */
        nclos[i-1] = 0;
        dataSs(&fldnam[i-1][6],&K8,&idum,&K2,&irc);
        if(irc == 0) nclos[i-1] = 1;

        /*
         --- CHECK FOR COMMIT AS EXPENDED FIELD

        */
        nexpn[i-1] = 0;
        dataSs(&fldnam[i-1][5],&K8,&idum,&K2,&irc);
        if(irc == 0) nexpn[i-1] = 1;

        /*
         --- CHECK TO INVALID COMBINATION OF ENTRIES

        */
        if(icompr(&po,"-       ",&K8) == 0 && nclos[i-1]+nexpn[i-1] > 0) goto S4570;
        if(nclos[i-1]+nexpn[i-1] > 1) goto S4580;
        goto S4600;

S4570:

        /*
         ---   PO = '-       '

        */
        blnkSs(&fldnam[i-1][6],&K8,&irc);
        blnkSs(&fldnam[i-1][5],&K8,&irc);
        errSs("Do not mark Final Payment or Commit as Expended;PO# indicates uncommited item~",&K0,&irc);
        goto S3050;

S4580:

        /*
         --- CAN NOT ENTER BOTH FINAL PAYMENT AND COMMIT AS EXPENDED

        */
        blnkSs(&fldnam[i-1][6],&K8,&irc);
        blnkSs(&fldnam[i-1][5],&K8,&irc);
        errSs("Do not mark both Final Payment and Commit as Expended ~",&K0,&irc);
        goto S3050;

S4600:
        ilast = i;
        litem[i-1] = 1;                      /* SET FLAG TO INDICATE 'LINE ITEM' */
        nswdup = 1;                          /* NOW WE CAN DUPLICATE ON SUCCEEDING LINES */

        goto S4800;

S4700:

        /*
             VERIFY THAT A LINE WITH NO AMOUNT ALSO HAS NO OTHER ENTRIES

        */
        amnts[i-1] = 0.;                     /* RESET AMOUNT WHEN LINE IS UNUSED */

        nerr = 0;
        for(m=0; m==0 || m<NFIELD; m++)
        {
            dataSs(&fldnam[i-1][m],&K8,&idumb,&K1,&irc);
            if(irc == 4 || irc == 1) goto S4720;
            blnkSs(&fldnam[i-1][m],&K8,&irc);
            nerr = 1;
S4720:;
        }

        if(!nqtyrc) goto S4770;
        dataSs(namqty,&K5,&idumb,&K1,&irc);
        if(irc == 4 || irc == 1) goto S4760;
        blnkSs(namqty,&K5,&irc);
        nerr = 1;

S4760:
        dataSs(namres,&K16,&idumb,&K1,&irc);
        if(irc == 4 || irc == 1) goto S4770;
        blnkSs(namres,&K16,&irc);
        nerr = 1;

S4770:
        if(nerr == 0) goto S4780;
        errSs("If no amount is entered, then leave remainder of line blank~",&K0,&irc);
        goto S3050;
S4780:

S4800:;
    }

    /*
         TRAP SCREEN THAT HAS NO LINE ITEMS

    */
    if(nswdup != 0) goto S4810;
    errSs("Enter distribution of Invoice~",&K0,&irc);
    posSs(&fldnam[0][0],&K8,&irc);
    goto S3050;
S4810:

    /*
         CHECK DISTRIBUTION OF TOTAL INVOICE AMOUNT

    */
    if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && fabs(cramnt-tdist-disc-
      vattot) < .005e0) goto S4860;

    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2) && fabs(cramnt-tdist-vattot-
      stxtot) < .005e0) goto S4860;

    errSs("Distribution of amounts does not match invoice total~",&K0,&irc);

    for(i=1; i==1 || i<=13; i++)
    {
        blnkSs(&fldnam[i-1][0],&K8,&irc);
    }
    blnkSs("TOTAL VAT",&K9,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    blnkSs("TOTAL INVOICE",&K13,&irc);
    goto S3050;

S4860:

    /*
         If VAT has been calculated automatically, force balancing of penny
            round-off into last automatically calculated VAT amount.

    */
    if(lstvat == 0) goto S4870;              /* no automatic calculation */

    vatro = vattot-tvat;                     /* determine amount of round-off */
    if(fabs(vatro) < .005e0) goto S4870;     /* no significant round-off */
    if(fabs(vatro) > .08e0) goto S4870;      /* too big to be round-off */
    vatamt[lstvat-1] = vatamt[lstvat-1]+vatro;/* revise last calculated  */
    /*
    /*  VAT
    */
    doutSs(&fldnam[lstvat-1][7],&K8,&vatamt[lstvat-1],&N1,&irc);
    tvat = tvat+vatro;                       /* revise total of distributed VAT */

S4870:

    /*
         CHECK DISTRIBUTION OF TOTAL VAT TAX

    */
    if(fabs(vattot-tvat) < .005e0) goto S4875;

    if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) errSs(
      "Distribution of GST does not match GST total~",&K0,&irc);

    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) errSs(
      "Distribution of VAT does not match VAT total~",&K0,&irc);

    for(i=1; i==1 || i<=13; i++)
    {
        blnkSs(&fldnam[i-1][7],&K8,&irc);
    }
    blnkSs("TOTAL VAT",&K9,&irc);
    goto S3050;
S4875:

    /*
     ----------------------------------------------------------------------

         FORCE BALANCE OF DISCOUNT ALLOCATION (FRACTIONAL PENNY ROUND-OFF)

    */
    dscadj = disc-tadisc;
    if(!linitm) goto S4890;
    if(fabs(dscadj) < 0.20e0) goto S4890;
    blnkSs("DISCOUNT",&K8,&irc);
    for(ij=0; ij==0 || ij<13; ij++)
    {
        blnkSs(&fldnam[ij][9],&K6,&irc);
    }
    errSs("Discount distribution does not match total~",&K0,&irc);
    goto S3050;

S4890:
    adisc[lstdsc-1] = adisc[lstdsc-1]+dscadj;

    /*
    ------If Sales Tax was Calculated then check for Roundoff

    */
    staxro = 0.e0;
    if(lsttax == 0) goto S4895;

    staxro = stxtot-tstax;
    if(fabs(staxro) < .005e0) goto S4895;
    if(fabs(staxro) > .080e0) goto S4895;

    tstax = tstax+staxro;

S4895:
    if(fabs(stxtot-tstax) < .005e0) goto S4898;
    errSs("Distribution of Sales Tax does not match Sales Tax Total~",&K0,&irc);
    goto S3050;

S4898:

    /*
     ----------------------------------------------------------------------
         GET CHECK# AND DATE OF CHECK IF INVOICE HAS ALREADY BEEN PAID

    */
    dataSs("CHECK ",&K5,&check,&K8,&irc);
    if(irc == 4) goto S4990;
    gmdySc(&K3,&month,&iday,&iyear,&chkdat,&irc);
    if(irc == 0) goto S4940;
    errSs("Enter check date~",&K0,&irc);
    starSs("YEAR3 ",&K5,&irc);
    starSs("DAY3",&K4,&irc);
    starSs("MONTH3",&K6,&irc);
    goto S3050;

S4940:

    /*
         CHECK IF CASH DISBURSEMENT JOURNAL IS CLOSED THRU CHKDAT

    */
    clerr();

    clsdSc(&K3,&chkdat,"W ",&irc);
    if(irc == 0) goto S4945;
    blnkSs("MONTH3",&K6,&irc);
    blnkSs("DAY3",&K4,&irc);
    blnkSs("YEAR3 ",&K5,&irc);
    posSs("MONTH3",&K6,&irc);
    goto S3050;

S4945:

    /*
         VERIFY THAT THE BANK CASH ACCOUNT HAS BEEN SET UP

    */
    taccSc(&check,accts,&cash,&irc);
    if(irc == 0) goto S4950;
    blnkSs("CHECK ",&K5,&irc);
    errSs("Invalid Check#~",&K0,&irc);
    goto S3050;

S4950:
    doutSs("CHECK ",&K5,&check,&K8,&irc);

    /*
         Get the overide Cash Account if it is present

    */
    ovracc("CASH ACCOUNT",&K12,&cash,&irc);
    if(irc > 4) goto S3050;

    /*
         SET UP CASH ACCOUNT FOR EACH LINE ITEM

    */
    for(i=1; i==1 || i<=13; i++)
    {
        if(litem[i-1] == 0) goto S4960;

        spltjp(&rjobs[i-1],&rjob,&phase,&irc);

        vglaS2("Cash Ledger Account ","A ","O ","C ",&rjob,&phase,"          ",&cash,&csh[i-1],&irc);
        if(irc == 0) goto S4960;

        bangSs(&irc);

        errSs("Invalid Cash Ledger Account for indicated Bank Account~",&K0,&irc);
        blnkSs("CHECK ",&K5,&irc);
        goto S3050;

S4960:;
    }

S4990:

    /*
     ----------------------------------------------------------------------

         PACK INTO SCREEN DATA BUFFER

    */
    xpScom1_nscdat = 0;
    ib = 0;

    for(i=1,D17=(D17=(13-i+1))>0?D17:1; D17>0; D17--,i+=1)
    {

        if(litem[i-1] == 0) goto S6850;

        /*
             If we are close to no more space in P$SCDT then write the "D" rec

        */
        if(ib < MAXSCD-1500) goto S5750;

        if(nfunc == *(short*)fifstrgv("A ",2)) goto S5725;
        if(xpScom1_nscdat > 0) goto S5725;

        iSdlet(&batch,&refno,&irc);

S5725:
        xpScom1_nscdat = xpScom1_nscdat+1;
        iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);

        iSxinv(&batch,&refno,&vcno,&invoic,&irc);

        ib = 0;

S5750:

        xc_cSrow = i;

        ib = ib+1;
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("\\\\      ",8);/* Group Separator */
        xpScom1_pSscdt[ib] = 1.e0;           /* Version */
        xpScom1_pSscdt[ib+1] = i;            /* Group Number */
        xpScom1_pSscdt[ib+2] = 0.e0;         /* Reserved for future  */
        /*
        /*  use
        */
        xpScom1_pSscdt[ib+3] = 0.e0;         /* Reserved for future  */
        /*
        /*  use
        */
        xpScom1_pSscdt[ib+4] = 0.e0;         /* Reserved for future  */
        /*
        /*  use
        */
        xpScom1_pSscdt[ib+5] = 0.e0;         /* Reserved for future  */
        /*
        /*  use
        */
        xpScom1_pSscdt[ib+6] = 0.e0;         /* Reserved for future  */
        /*
        /*  use

        */
        ib = ib+7;

        /*
             Load table with active input field names for reference in other routines

        */
        fill(xc_cSnmaf,&K160,"  ");          /* blank fill names buffer */
        mvbyt(&fldnam[i-1][0],&xc_cSnmaf[0][0],&K8);/* amount */
        xc_cSnoaf = 1;                       /* number of active fields */

        invoic = invli[i-1];
        po = poli[i-1];
        datinv = invdli[i-1];

        spltjp(&rjobs[i-1],&rjob,&phase,&irc);

        /*
         --- Look for any expired insurance, if found hold payment

        */
        mvbyt(&activs[i-1][0],activ,&K10);
        holdSc(&vcno,&rjob,&phase,&effdat,&trtype,"B ",activ,&po,&invoic,&ib,&irc);

        /*
         --- CHECK IF "COMMIT AS EXPENDED" FIELD WAS FILLED IN

        */
        if(nswcxp == 1 || nexpn[i-1] == 1) goto S6700;

        /*
         --- CHECK COMMITMENTS FOR OVER-BILLING

         --- CHECK IF WE CAN "COMMIT AS EXPENDED"

        */
        mvbyt(&activs[i-1][0],activ,&K10);

        /*
         --- "V/C$INFO"

        */
        itemp[0] = *(short*)fifstrgv("  ",2);
        vinfSc(&vcno,"    ","COMMIT AS EXPENDED",&K18,&itemp[0],&K1,&K0,&K0,&irc);
        if(irc == 0 && itemp[0] == *(short*)fifstrgv("Y ",2)) goto S6700;

        /*
         --- CHECK VENDOR CONTROL

        */
        vctlSc("F ",&vcno,&rjob,&phase,&activs[i-1][0],&po,"COMMIT AS EXPENDED",&K18,&itemp[0],&K1,&irc);
        if(irc == 0 && itemp[0] == *(short*)fifstrgv("Y ",2)) goto S6700;

        /*
           --- GET COMMIT AS EXPENED FOR JOB/PHASE/ACTIVITY "ACTIVITY$INFO"

        */
        WRITE(INTERNAL,keyact,22,FMT,F6610,1,REAL8,rjob,REAL8,phase,DO,5,INT2,activ,0);

        ioSf("FIND","ACTIVITY$INFO",&K13,"    ",keyact,&K0,&K0,&K0,&irc);
        if(irc != 0) goto S6620;

        dataSf("GET ","ACTIVITY$INFO",&K13,"    ","COMMIT AS EXPENDED",&K18,&itemp[0],&K1,&K0,&K0,&irc);
        if(irc != 0 || itemp[0] != *(short*)fifstrgv("Y ",2)) goto S6620;

        goto S6700;                          /* COMMIT AS EXPENDED */

S6620:

        /*
         --- COMMITMENT VALIDATION ERROR

        */
        ivcmod = *(short*)fifstrgv("B ",2);  /* check for Over "B"illed condition */
        if(check != *(double*)fifstrgv("        ",8)) ivcmod = *(short*)fifstrgv("BW",2);/* Warning Only */
        vcomSc(&ivcmod,&idchg[i-1][0],"PO",&vcno,&rjob,&phase,&activs[i-1][0],&po,&amnts[i-1],&ircS);
        if(ircS == 0) goto S6800;

        for(j=0; j==0 || j<5; j++)
        {
            blnkSs(&fldnam[i-1][j],&K8,&irc);
        }

        if(ircS == 7) goto S6650;            /* COMMIT DOES NOT EXISTS REQUIRED */
        if(ircS == 2) goto S3050;            /* COMMIT REQUIRED */

        blnkSs("PO",&K2,&irc);
        posSs("PARK",&K4,&irc);
        bangSs(&irc);
        clrSs(&K24,&K24,&K1,&K78,&ircSS);
        rstSs(&K0,&N1,&ircSS);               /* UN-BLINK ALL FIELDS */
        if(irc == 0) goto S6800;
        if(irc != 8) goto S9000;
        posSs("VCNO",&K4,&irc);
        goto S3050;

S6650:

        /*
           --- PURCHASE$ORDER# NOT FOUND

        */
        blnkSs("PO",&K2,&irc);
        goto S3050;

S6700:

        /*
           --- UNBLINK FIELDS SET BLINKING BY COMMITMENT VALIDATION, IF ANY

        */
        rstSs(&K0,&N1,&irc);

        if(icompr(&po,"-       ",&K8) == 0) goto S6800;

        /*
           --- PACK DATA FOR PURCHASE$ORDER COMMIT AS EXPENDED

        */
        if(amnts[i-1] == 0.e0) goto S6800;
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("PO      ",8);/* PURCHASE$ORDER */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(&idchg[i-1][0],&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);/*  TRANSACTION TYPE */
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);/* DOCUMENT REFERENCE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* PURCHASE$ORDER DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* CASH FLOW DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* CREDIT ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = 0.e0;        /* CREDIT ACCOUNT */
        mvwrd("CHANGE ORDER    ",&xpScom1_pSscdt[ib+19],&K8);

        ib = ib+21;

        /*
         ----- PACK TIME AND EXPENSE DATA

        */
        mvwrd(&idchg[i-1][0],xbilcom_bScoid,&K2);/* CHARGED COMPANY ID */
        xbilcom_bSvcno = clntli[i-1];        /* CLIENT NUMBER */
        xbilcom_bSvndr = vcno;               /* VENDOR NUMBER */
        mvwrd(&invoic,xbilcom_bSvinv,&K4);   /* VENDOR INVOICE */
        xbilcom_bSvind = datinv;             /* VENDOR INVOICE DATE */
        mvwrd(&rmemo[i-1][0],xbilcom_bSvmem,&K8);/* VENDOR INVOICE MEMO */
        xbilcom_bSdrja = drjacc[i-1];        /* VENDOR DR JOB ACCOUNT */
        xbilcom_bSdrgl = dracct[i-1];        /* VENDOR DR GL ACCOUNT */
        xbilcom_bScrja = 0.0e0;              /* VENDOR CR JOB ACCOUNT */
        xbilcom_bScrgl = 0.0e0;              /* VENDOR CR GL ACCOUNT */

        xbilcom_bScjob = rjob;               /*  CHARGE JOB */
        xbilcom_bScphs = phase;              /*  CHARGE PHASE */
        xbilcom_bSjcda = drjacc[i-1];        /*  ACCOUNT CHARGED */
        mvwrd(&activs[i-1][0],xbilcom_bSactv,&K5);/*  ACTIVITY */
        mvwrd(&irescd[i-1][0],xbilcom_bSresc,&K8);/*  RESOURCE CODE */
        xbilcom_bSqty = quanty[i-1];         /*  QUANTITY */
        xbilcom_bSamnt = amnts[i-1];         /*  $ AMOUNT */
        xbilcom_bSref = refno;               /*  REFERENCE NUMBER */
        xbilcom_bSpo = po;                   /*  COMMITMENT ID */
        xbilcom_bScom = 1.0e0;               /*  COMMITMENT FLAG */
        mvwrd(&inobil[i-1],&xbilcom_bSnbil,&K1);/*  NON-BILLABLE */

        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        xpScom1_noscSp = ib;

        T1 = NBWRNS;                         /* request billing rate */
        flagSc("U ","S ",&T1,&irc);
        autote(&irc);
        if(irc == 7) irc = 0;
        if(irc != 0) goto S3050;             /*  ERROR IN T&E BILLING */

        ib = xpScom1_noscSp;

S6800:

        /*
             IS THIS AN INTERCOMPANY TRANSACTION

        */
        if(apict[i-1] != 0.e0) goto S6820;   /* INTERCOMPANY TRANSACTION */
        if(amnts[i-1] == 0.e0) goto S6810;

        code[0] = *(double*)fifstrgv("P       ",8);
        if(ircbak == 0 && i == 13) code[0] = *(double*)fifstrgv("P B     ",8);
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
        ------Pack Sales Tax

        */
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S6810;

        iopt = 0;

        staxSc(&iopt,&taxcod[i-1],&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

        if(irc != 0) goto S6810;
        if(noe == 0) goto S6810;

        tsaltx = taxamt[i-1];

        for(j=1; j==1 || j<=noe; j++)
        {

            crjtax = entity[j-1][4];
            crltax = 0.e0;
            if(crjtax != 0.e0) vglaSc("A ",&rjob,&phase,&crjtax,&crltax,&irc);

            mvwrd("SALES   ",&taxtyp,&K4);   /* Sales Tax */
            if(crjtax != 0.e0) mvwrd("USE     ",&taxtyp,&K4);/* Use Tax */

            if(crltax == 0.e0) crjtax = crjacc;
            if(crltax == 0.e0) crltax = cracct[i-1];

            if(icaltx[i-1] == 0 && icompr(&taxtyp,"SALES ",&K5) == 0) goto S6801;

            /*
            ---------Tax was calculated by the sales tax rate

            */
            taxent = entity[j-1][3]*amnts[i-1]*sbrtio*.01e0;
            goto S6802;

            /*
            ---------Pro-Rate the Sales Tax by entity from tax input by user

            */
S6801:
            ratio = 0.e0;
            if(saltax != 0.e0) ratio = entity[j-1][3]/saltax;
            if(iameq(&ratio,&R11) == 0) ratio = 1.e0;
            taxent = taxamt[i-1]*ratio;

S6802:
            roffSc(&taxent,&R13,&irc);

            /*
                    Only reduce the TSALTX variable when we have a Sales Tax entity

            */
            if(icompr(&taxtyp,"USE ",&K3) == 0) goto S6803;
            tsaltx = tsaltx-taxent;
S6803:

            /*
                    Add any roundoff difference to the last entity

            */
            if(j == noe) taxent = taxent+tsaltx;
            if(i == lsttax && j == noe) taxent = taxent+staxro;

            WRITE(INTERNAL,memotx,16,FMT,F6804,1,REAL8,taxtyp,REAL8,taxcod[i-1],0);

            ib = ib+1;
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("ST      ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjob;     /* JOB */
            xpScom1_pSscdt[ib+6] = phase;    /* PHASE */
            mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd(&po,&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&invoic,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = datinv;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = effdat;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = datdue;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = amnts[i-1];/* INVOICE AMOUNT */
            mvwrd(&taxcod[i-1],&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[j-1][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[j-1][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = drjacc[i-1];/* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = crjtax;  /* CREDIT TAX JOB ACCT */
            xpScom1_pSscdt[ib+24] = dracct[i-1];/* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = crltax;  /* CREDIT TAX LEDG ACT */
            mvwrd(memotx,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = taxemt;  /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = cramnt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

            /*
             ----- PACK TIME AND EXPENSE DATA

            */
            mvwrd(&idchg[i-1][0],xbilcom_bScoid,&K2);/* CHARGED COMPANY ID */
            xbilcom_bSvcno = clntli[i-1];    /* CLIENT NUMBER */
            xbilcom_bSvndr = vcno;           /* VENDOR NUMBER */
            mvwrd(&invoic,xbilcom_bSvinv,&K4);/* VENDOR INVOICE */
            xbilcom_bSvind = datinv;         /* VENDOR INVOICE DATE */
            mvwrd(&rmemo[i-1][0],xbilcom_bSvmem,&K8);/* VENDOR INVOICE MEMO */
            xbilcom_bSdrja = drjacc[i-1];    /* VENDOR DR JOB ACCOUNT */
            xbilcom_bSdrgl = dracct[i-1];    /* VENDOR DR GL ACCOUNT */
            xbilcom_bScrja = crjtax;         /* VENDOR CR JOB ACCOUNT */
            xbilcom_bScrgl = crltax;         /* VENDOR CR GL ACCOUNT */

            xbilcom_bScjob = rjob;           /*  CHARGE JOB */
            xbilcom_bScphs = phase;          /*  CHARGE PHASE */
            xbilcom_bSjcda = drjacc[i-1];    /*  ACCOUNT CHARGED */
            mvwrd(&activs[i-1][0],xbilcom_bSactv,&K5);/*  ACTIVITY */
            mvwrd(&irescd[i-1][0],xbilcom_bSresc,&K8);/*  RESOURCE CODE */
            xbilcom_bSqty = 0.e0;            /*  QUANTITY */
            xbilcom_bSamnt = taxent;         /*  TAX $ AMOUNT */
            xbilcom_bSref = refno;           /*  REFERENCE NUMBER */
            xbilcom_bSpo = po;               /*  COMMITMENT ID */
            xbilcom_bScom = 0.0e0;           /*  COMMITMENT FLAG */
            mvwrd(&inobil[i-1],&xbilcom_bSnbil,&K1);/*  NON-BILLABLE */

            dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

            xpScom1_noscSp = ib;

            T1 = NBWRNS;                     /* request billing rate */
            flagSc("U ","S ",&T1,&irc);
            /*
                     /*  warning
            */
            autote(&irc);
            if(irc == 7) irc = 0;
            if(irc != 0) goto S3050;         /*  ERROR IN T&E BILLING */

            ib = xpScom1_noscSp;

        }

S6810:

        /*
         --- PACK DISCOUNT IF NATION = 'NZ' or 'AU'

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S6825;

        /*
             check to see whether we have a value to pack

        */
        if(iameq(&adisc[i-1],&R11) == 0) goto S6825;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P       ",8);/* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = adisc[i-1];  /* AMOUNT OF DISCOUNT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = dsc[i-1];    /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        goto S6825;

S6820:

        /*
             PACK THE ORIGINATING COMPANY SIDE OF AN INTERCOMPANY TRANSACTION

        */
        if(amnts[i-1] == 0.e0) goto S6821;
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO  */
        /*
        /*  entry

        */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT O ",8);/* PURCHASE - INTERCOMPANY - ORIGINATOR */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = arict[i-1];  /* DEBIT INTERCO A/R ACCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = arict[i-1];  /* DEBIT INTERCO A/R ACCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6821:

        /*
         --- PACK DISCOUNT IF NATION = 'NZ' or 'AU'

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S6824;

        /*
             check to see whether we have a value to pack

        */
        if(iameq(&adisc[i-1],&R11) == 0) goto S6824;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT O ",8);/* PURCHASE - INTERCOMPANY - ORIGINATOR */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = adisc[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT DISCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = dsc[i-1];    /* DEBIT DISCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6824:

        /*
             NOW, PACK CHARGED COMPANY'S SIDE OF INTERCOMPANY TRANSACTION

        */
        if(amnts[i-1] == 0.e0) goto S6825;
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT R ",8);/* PURCHASE - INTERCOMPANY - RECEIVER */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(&idchg[i-1][0],&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = apict[i-1];  /* CREDIT INTERCO A/P ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = apict[i-1];  /* CREDIT INTERCO A/P ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;

        ib = ib+22;

        /*
        ------Pack Sales Tax Inter-Company

        */
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S6825;

        iopt = 0;

        staxSc(&iopt,&taxcod[i-1],&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

        if(irc != 0) goto S6825;
        if(noe == 0) goto S6825;

        tsaltx = taxamt[i-1];

        for(j=1; j==1 || j<=noe; j++)
        {

            crjtax = entity[j-1][4];
            crltax = 0.e0;
            if(crjtax != 0.e0) vglaSc("A ",&rjob,&phase,&crjtax,&crltax,&irc);

            mvwrd("SALES   ",&taxtyp,&K4);   /* Sales Tax */
            if(crjtax != 0.e0) mvwrd("USE     ",&taxtyp,&K4);/* Use Tax */

            if(crltax == 0.e0) crjtax = crjacc;
            if(crltax == 0.e0) crltax = cracct[i-1];

            if(icaltx[i-1] == 0 && icompr(&taxtyp,"SALES ",&K5) == 0) goto S68211;

            /*
            ---------Tax was calculated by the sales tax rate

            */
            taxent = entity[j-1][3]*amnts[i-1]*sbrtio*.01e0;
            goto S68212;

            /*
            ---------Pro-Rate the Sales Tax by entity from tax input by user

            */
S68211:
            ratio = 0.e0;
            if(saltax != 0.e0) ratio = entity[j-1][3]/saltax;
            if(iameq(&ratio,&R11) == 0) ratio = 1.e0;
            taxent = taxamt[i-1]*ratio;

S68212:
            roffSc(&taxent,&R13,&irc);

            if(icompr(&taxtyp,"USE ",&K3) == 0) goto S68213;
            tsaltx = tsaltx-taxent;
S68213:
            if(j == noe) taxent = taxent+tsaltx;
            if(i == lsttax && j == noe) taxent = taxent+staxro;

            WRITE(INTERNAL,memotx,16,FMT,F68214,1,REAL8,taxtyp,REAL8,taxcod[i-1],0);

            ib = ib+1;
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("STICT O ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjob;     /* JOB */
            xpScom1_pSscdt[ib+6] = phase;    /* PHASE */
            mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd(&po,&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&invoic,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = datinv;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = effdat;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = datdue;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = amnts[i-1];/* INVOICE AMOUNT */
            mvwrd(&taxcod[i-1],&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[j-1][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[j-1][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = arict[i-1];/* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = crjtax;  /* CREDIT TAX JOB ACCT */
            xpScom1_pSscdt[ib+24] = arict[i-1];/* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = crltax;  /* CREDIT TAX LEDG ACT */
            mvwrd(memotx,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = taxemt;  /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = cramnt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

            ib = ib+1;
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("STICT R ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(&idchg[i-1][0],&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjob;     /* JOB */
            xpScom1_pSscdt[ib+6] = phase;    /* PHASE */
            mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd(&po,&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&invoic,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = datinv;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = effdat;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = datdue;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = amnts[i-1];/* INVOICE AMOUNT */
            mvwrd(&taxcod[i-1],&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[j-1][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[j-1][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = drjacc[i-1];/* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = apict[i-1];/* CREDIT TAX JOB ACCT */
            xpScom1_pSscdt[ib+24] = dracct[i-1];/* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = apict[i-1];/* CREDIT TAX LEDG ACT */
            mvwrd(memotx,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = taxemt;  /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = cramnt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

        }

S6825:

        /*
         --- PACK VAT TAX AMOUNT IF APPLICABLE

        */
        actvat = vatdr;
        cract = crjacc;
        cractl = cracct[i-1];

        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2) && vatamt[i-1] == 0.e0)
          goto S6930;

        code[0] = *(double*)fifstrgv("P V     ",8);
        if(ircvat != 0) goto S6828;
        WRITE(INTERNAL,code,8,FMT,F6826,1,INT2,vatype,0);

        vivo = 1;                            /* Vat In */
        actvat = vatact[vivo-1][ifgs-1][fordom-1][accpay-1];
        vglaSc("A ",&rjob,&phase,&actvat,&actvat,&irc);
        if(irc == 0) goto S6828;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][accpay-1]-1][0],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6828:

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = vatamt[i-1]; /* AMOUNT OF VAT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = actvat;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = cract;       /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = actvat;      /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cractl;      /* CREDIT ACCOUNT */
        WRITE(INTERNAL,tmemo,16,FMT,F6829,1,REAL8,amnts[i-1],0);
        mvbyt(tmemo,&xpScom1_pSscdt[ib+19],&K16);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
        ------If this is a Foreign Vendor pack a reversing Vs entry

        */
        if(fordom != 2) goto S6930;
        if(ircvat != 0) goto S6930;
        if(vatype == *(short*)fifstrgv("F ",2)) code[0] = *(double*)fifstrgv("P Vf    ",8);
        if(vatype == *(short*)fifstrgv("G ",2)) code[0] = *(double*)fifstrgv("P Vg    ",8);
        if(vatype == *(short*)fifstrgv("S ",2)) code[0] = *(double*)fifstrgv("P Vs    ",8);
        vivo = 2;                            /* Vat Out */
        actvat = vatact[vivo-1][ifgs-1][fordom-1][accpay-1];
        vglaSc("A ",&rjob,&phase,&actvat,&actvat,&irc);
        if(irc == 0) goto S6831;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][accpay-1]-1][0],&K40,&irc);
        goto S3050;

S6831:

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = -vatamt[i-1];/* AMOUNT OF VAT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = actvat;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = cract;       /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = actvat;      /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cractl;      /* CREDIT ACCOUNT */
        WRITE(INTERNAL,tmemo,16,FMT,F6829,1,REAL8,amnts[i-1],0);
        mvbyt(tmemo,&xpScom1_pSscdt[ib+19],&K16);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6930:

        /*
         ----- PACK TIME AND EXPENSE DATA

        */
        mvwrd(&idchg[i-1][0],xbilcom_bScoid,&K2);/* CHARGED COMPANY ID */
        xbilcom_bSvcno = clntli[i-1];        /* CLIENT NUMBER */
        xbilcom_bSvndr = vcno;               /* VENDOR NUMBER */
        mvwrd(&invoic,xbilcom_bSvinv,&K4);   /* VENDOR INVOICE */
        xbilcom_bSvind = datinv;             /* VENDOR INVOICE DATE */
        mvwrd(&rmemo[i-1][0],xbilcom_bSvmem,&K8);/* VENDOR INVOICE MEMO */
        xbilcom_bSdrja = drjacc[i-1];        /* VENDOR DR JOB ACCOUNT */
        xbilcom_bSdrgl = dracct[i-1];        /* VENDOR DR GL ACCOUNT */
        xbilcom_bScrja = 0.0e0;              /* VENDOR CR JOB ACCOUNT */
        xbilcom_bScrgl = 0.0e0;              /* VENDOR CR GL ACCOUNT */

        xbilcom_bScjob = rjob;               /*  CHARGE JOB */
        xbilcom_bScphs = phase;              /*  CHARGE PHASE */
        xbilcom_bSjcda = drjacc[i-1];        /*  ACCOUNT CHARGED */
        mvwrd(&activs[i-1][0],xbilcom_bSactv,&K5);/*  ACTIVITY */
        mvwrd(&irescd[i-1][0],xbilcom_bSresc,&K8);/*  RESOURCE CODE */
        xbilcom_bSqty = quanty[i-1];         /*  QUANTITY */
        xbilcom_bSamnt = amnts[i-1];         /*  $ AMOUNT */
        xbilcom_bSref = refno;               /*  REFERENCE NUMBER */
        xbilcom_bSpo = po;                   /*  COMMITMENT ID */
        xbilcom_bScom = 0.0e0;               /*  COMMITMENT FLAG */
        mvwrd(&inobil[i-1],&xbilcom_bSnbil,&K1);/*  NON-BILLABLE */

        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        xpScom1_noscSp = ib;

        T1 = NBWRNS;                         /* request billing rate */
        flagSc("U ","S ",&T1,&irc);
        autote(&irc);
        if(irc == 7) irc = 0;
        if(irc != 0) goto S3050;             /*  ERROR IN T&E BILLING */

        ib = xpScom1_noscSp;

S6850:;
    }

    /*
         IF THIS ITEM IS ALREADY PAID, PACK CASH DISBURSEMENT DATA

    */
    if(icompr(&check,"        ",&K8) == 0) goto S6960;

    for(i=1,D19=(D19=(13-i+1))>0?D19:1; D19>0; D19--,i+=1)
    {

        if(litem[i-1] == 0) goto S6950;

        xc_cSrow = i;

        invoic = invli[i-1];
        po = poli[i-1];
        datinv = invdli[i-1];
        spltjp(&rjobs[i-1],&rjob,&phase,&irc);
        code[0] = *(double*)fifstrgv("CD      ",8);
        if(i == 13 && ircbak == 0) code[0] = *(double*)fifstrgv("CDB     ",8);
        pstamt = amnts[i-1];
        if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) pstamt = pstamt+adisc[i-1];

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* CASH DISBURSEMENT */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLES BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = pstamt;      /* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT TAKEN */
        xpScom1_pSscdt[ib+15] = crjacc;      /* DEBIT JOB ACCOUNT (USE CREDIT ACCOUNT PAYABLE) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = cracct[i-1]; /* DEBIT ACCOUNT (USE CREDIT ACCOUNT PAYABLE */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
         ---- PACK DATA FOR VAT AMOUNT PAID ON THIS CHECK

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2) && fabs(vatamt[i-1]) <
          .001e0) goto S6860;
        code[0] = *(double*)fifstrgv("CDV     ",8);
        if(ircvat == 0) WRITE(INTERNAL,code,8,FMT,F6851,1,INT2,vatype,0);

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* CASH DISBURSEMENT  ( VAT ) */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLES BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = vatamt[i-1]; /* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT TAKEN */
        xpScom1_pSscdt[ib+15] = crjacc;      /* DEBIT JOB ACCOUNT (USE CREDIT ACCOUNT PAYABLE) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = cracct[i-1]; /* DEBIT ACCOUNT (USE CREDIT ACCOUNT PAYABLE */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
         -----If this is a Foreign Vendor and Vat type is Service, pack Vs type

        */
        if(fordom != 2) goto S6849;
        if(ircvat != 0) goto S6849;
        if(vatype == *(short*)fifstrgv("F ",2)) code[0] = *(double*)fifstrgv("CDVf    ",8);
        if(vatype == *(short*)fifstrgv("G ",2)) code[0] = *(double*)fifstrgv("CDVg    ",8);
        if(vatype == *(short*)fifstrgv("S ",2)) code[0] = *(double*)fifstrgv("CDVs    ",8);
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* CASH DISBURSEMENT  ( VAT ) */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLES BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = -vatamt[i-1];/* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT TAKEN */
        xpScom1_pSscdt[ib+15] = crjacc;      /* DEBIT JOB ACCOUNT (USE CREDIT ACCOUNT PAYABLE) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = cracct[i-1]; /* DEBIT ACCOUNT (USE CREDIT ACCOUNT PAYABLE */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6849:

        /*
         -----Pack entry to reverse accrued Vat and post to Payable Vat

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2) && fabs(vatamt[i-1]) <
          .001e0) goto S6860;
        if(vatype != *(short*)fifstrgv("S ",2)) goto S6860;
        vivo = 1;                            /* Vat In */
        iacpay = 2;                          /* Payable */
        dract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&dract,&dractl,&irc);
        if(irc == 0) goto S6852;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][1],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6852:
        vivo = 1;                            /* Vat In */
        iacpay = 1;                          /* Accrued */
        cract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&cract,&cractl,&irc);
        if(irc == 0) goto S6853;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][0],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6853:
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("D       ",8);/* Debit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = dract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = dractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("C       ",8);/* Credit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = cract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = cractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

        /*
         -----Pack entry to reverse accrued Vat Out and post to Payable Vat Out

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2) && fabs(vatamt[i-1]) <
          .001e0) goto S6860;

        if(fordom != 2) goto S6860;
        if(vatype != *(short*)fifstrgv("S ",2)) goto S6860;
        vivo = 2;                            /* Vat Out */
        iacpay = 1;                          /* Accrued */
        dract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&dract,&dractl,&irc);
        if(irc == 0) goto S6862;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][1],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6862:
        if(fordom == 2) vivo = 2;            /* Foreign is Vat Out */
        if(fordom == 2) iacpay = 2;          /* Foreign is Payable */
        cract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&cract,&cractl,&irc);
        if(irc == 0) goto S6863;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][0],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6863:
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("D       ",8);/* Debit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = dract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = dractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("C       ",8);/* Credit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = cract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = cractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

S6860:

        /*
             RECORD DISCOUNT TAKEN, IF ANY

        */
        if(fabs(adisc[i-1]) < .001e0) goto S6950;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("CD      ",8);/* CASH DISBURSEMENT */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = xc_cSdacj;
        xpScom1_pSscdt[ib+5] = xc_cSdacp;
        mvwrd(dscact,&xpScom1_pSscdt[ib+6],&K5);

        /*
             If NZ or AU use actual job, phase and activity and not defaults

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S6940;

        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);

S6940:
        xpScom1_pSscdt[ib+8] = *(double*)fifstrgv("-       ",8);/* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);
        xpScom1_pSscdt[ib+10] = 0.e0;
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = 0.e0;
        xpScom1_pSscdt[ib+13] = -adisc[i-1]; /* AMOUNT OF DISCOUNT EARNED (NOTE  */
        /*
        /*  CONTRA AMOUNT)
        */
        xpScom1_pSscdt[ib+14] = 0.e0;
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT JOB ACCOUNT (DISCOUNTS EARNED) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = dsc[i-1];    /* DEBIT ACCOUNT (DISCOUNTS EARNED) */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd("Discnt: ",&xpScom1_pSscdt[ib+19],&K4);/* PUT INVOICE ON WHICH  */
        /*
        /*  DISCOUNT
        */
        mvwrd(&invoic,&xpScom1_pSscdt[ib+20],&K4);/* WAS EARNED IN MEMO */
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6950:;
    }

    /*
    ----------------------------------------------------------------------C

    */
S6960:

    /*
     --- CLOSE COMMITMENTS

     ---  CLOSE THIS COMMITMENT FOR EACH JOB/PHASE/ACTIVITY

    */
    for(i=1,D21=(D21=(13-i+1))>0?D21:1; D21>0; D21--,i+=1)
    {

        if(nswcls == 0 && nclos[i-1] == 0) goto S7090;

        if(litem[i-1] == 0) goto S7090;      /* NOT USED */

        xc_cSrow = i;

        invoic = invli[i-1];
        po = poli[i-1];
        datinv = invdli[i-1];
        if(i == 1) goto S7030;

        /*
         --- SEE IF JOB/PHASE/ACTIVITY HAS ALREADY BEEN CLOSED

        */
        kk = i-1;
        for(k=0; k==0 || k<kk; k++)
        {
            if(litem[k] == 0) goto S7020;    /* NOT USED */
            if(rjobs[i-1] != rjobs[k] || icompr(&activs[i-1][0],&activs[k][0],&K10) != 0) goto S7020;
            if(nswcls == 0 && nclos[k] == 0) goto S7020;
            goto S7090;
S7020:;
        }

S7030:

        /*
         --- GET THE UNBILLED AMOUNT FOR THE JOB/PHASE/ACTIVITY/PO

        */
        spltjp(&rjobs[i-1],&rjob,&phase,&irc);
        jinfSc(&rjob,&phase,"JC  ","COMPANY ID",&K10,jcoid,&K4,&K0,&K0,&irc);

        mvbyt(&activs[i-1][0],activ,&K10);

        for(iclr=0; iclr==0 || iclr<10; iclr++)
        {                                    /* CLEAR ALL ELEMENTS... */
            data[iclr] = 0.e0;               /* ...OF EXPANDED C$M... */
        }

        /*
         --- ENCODE KEY TO THE COMMITMENT$MASTER

        */
        WRITE(INTERNAL,keycSm,120,FMT,F7040,1,DO,2,INT2,jcoid,REAL8,vcno,REAL8,rjob,REAL8,phase,DO,5,INT2,activ,REAL8,
          po,0);                             /* ...BUFFER */

        ioSf("FIND","COMMITMENT$MASTER",&K17,"    ",keycSm,&K0,&K0,&K0,&irc);
        if(irc == 7) goto S7090;

        gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$ORIGINAL",&K9,&data[0],&K0,&K0,&K0,&irc);
        gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$CHANGE  ",&K7,&data[1],&K0,&K0,&K0,&irc);
        gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$BILLED  ",&K7,&data[2],&K0,&K0,&K0,&irc);

        /*
         --- CHECK IF THERE IS A CURRENT BILLING FOR THIS COMMITMENT

        */
        tamnt = 0.e0;
        for(k=0; k==0 || k<13; k++)
        {
            if(litem[k] == 0) goto S7060;    /* NOT USED */
            if(rjobs[i-1] == rjobs[k] && icompr(&activs[i-1][0],&activs[k][0],&K10) == 0) tamnt = tamnt+amnts[k];
S7060:;
        }

        /*
         --- CALCULATE UNBILLED AMOUNT

        */
        clsamt = data[0]+data[1]-(data[2]+tamnt);

        if(clsamt == 0.e0) goto S7090;       /* COMMITMENT IS BILLED IN FULL */

        /*
         --- PACK DATA TO CLOSE A COMMITMENT

        */
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("PO      ",8);/* PURCHASE ORDER */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd("        ",&xpScom1_pSscdt[ib+2],&K4);/* DUMMY TRANSACTION TYPE */
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* PURCHASE ORDER DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* CASH FLOW DATE */
        xpScom1_pSscdt[ib+13] = -clsamt;     /* AMOUNT OF PURCHASE ORDER */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* CREDIT ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = 0.e0;        /* CREDIT ACCOUNT */
        mvwrd("CHANGE ORDER    ",&xpScom1_pSscdt[ib+19],&K8);

        ib = ib+21;

        /*
         ----- Pack T&E for Closed Commitment

        */
        mvwrd(&idchg[i-1][0],xbilcom_bScoid,&K2);/* CHARGED COMPANY ID */
        xbilcom_bSvcno = clntli[i-1];        /* CLIENT NUMBER */
        xbilcom_bSvndr = vcno;               /* VENDOR NUMBER */
        mvwrd(&invoic,xbilcom_bSvinv,&K4);   /* VENDOR INVOICE */
        xbilcom_bSvind = datinv;             /* VENDOR INVOICE DATE */
        mvwrd(&rmemo[i-1][0],xbilcom_bSvmem,&K8);/* VENDOR INVOICE MEMO */
        xbilcom_bSdrja = drjacc[i-1];        /* VENDOR DR JOB ACCOUNT */
        xbilcom_bSdrgl = dracct[i-1];        /* VENDOR DR GL ACCOUNT */
        xbilcom_bScrja = 0.0e0;              /* VENDOR CR JOB ACCOUNT */
        xbilcom_bScrgl = 0.0e0;              /* VENDOR CR GL ACCOUNT */

        xbilcom_bScjob = rjob;               /*  CHARGE JOB */
        xbilcom_bScphs = phase;              /*  CHARGE PHASE */
        xbilcom_bSjcda = drjacc[i-1];        /*  ACCOUNT CHARGED */
        mvwrd(&activs[i-1][0],xbilcom_bSactv,&K5);/*  ACTIVITY */
        mvwrd(&irescd[i-1][0],xbilcom_bSresc,&K8);/*  RESOURCE CODE */
        xbilcom_bSqty = quanty[i-1];         /*  QUANTITY */
        xbilcom_bSamnt = -clsamt;            /*  $ AMOUNT */
        xbilcom_bSref = refno;               /*  REFERENCE NUMBER */
        xbilcom_bSpo = po;                   /*  COMMITMENT ID */
        xbilcom_bScom = 1.0e0;               /*  COMMITMENT FLAG */

        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        xpScom1_noscSp = ib;

        autote(&irc);
        if(irc == 7) irc = 0;
        if(irc != 0) goto S3050;             /*  ERROR IN T&E BILLING */

        ib = xpScom1_noscSp;

S7090:;
    }

    /*
    ----------------------------------------------------------------------C

    */
    ierrs = 0;
    if(invchk == 0 && ierrs == 0) goto S7150;
    if(invchk == 0 && ierrs > 0) goto S7500;

    chkjob = 0.e0;
    chkphs = 0.e0;
    idupls = 0;

    if(invchk == 1) n = 1;                   /* CHECK AT INVOICE LEVEL */
    if(invchk == 2) n = 13;                  /* CHECK AT JOB/PHASE LEVEL */
    if(linitm) n = 13;                       /* INVOICE # ON LINE ITEM */

    for(i=1; i==1 || i<=n; i++)
    {                                        /* POSSIBLE LINE ITEM INVOICE# */
        if(litem[i-1] == 0) goto S7125;
        invoic = invli[i-1];
        if(invchk == 1) goto S7110;
        spltjp(&rjobs[i-1],&chkjob,&chkphs,&irc);
S7110:
        chkinv(&batch,&refno,&vcno,&invoic,&irc);
        if(irc != 0) idupls = 1;
        chkiSc(&K33,"P ",&vcno,"B ",&invoic,&chkjob,&chkphs,&irc);
        if(irc == 7) goto S7125;
        blnkSs("VCNO",&K4,&irc);
        blnkSs("INVOICE ",&K7,&irc);
        if(invchk == 2) blnkSs(&fldnam[i-1][2],&K7,&irc);
        idupls = 1;
S7125:;
    }

    if(ierrs == 0 && idupls == 0) goto S7150;
    if(ierrs > 0 && idupls == 0) goto S7500;
    if(nswvb == 1) goto S7150;

    /*
     ---- Duplicate invoice.  Warn user, and either make them
          input something to show they know, or just accept a
          return.

    */
    if(invdup > 0) goto S7130;
    errSs("Invoice already on file... Return to continue, or ^ to change~",&K0,&irc);

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* DON'T STOP IF ON 'RE-ENTER' */

    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7150;
    if(irc == 8) goto S7140;                 /* ROOFTOP */
    goto S9000;                              /* USER WANTS OUT */

S7130:

    /*
     ---- Make the user acknowledge the duplicate situation with
          an "OK"

    */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* DON'T STOP IF ON 'RE-ENTER' */

    if(xsc1_scSsmd != 21) goto S7132;

    /*
         Handle confirmation when in Web Edition

    */
    confrm("Invoice already on file~",&K0,&irc);
    if(irc == 0) goto S7150;

    goto S7140;

S7132:

    inatSb(&K24,&K1,"Invoice already on file...enter OK to continue, or ^ to change",&K62,nresp,&K24,&irc);

S7135:
    if(irc == 9) goto S9000;                 /* BANG */
    if(irc == 8) goto S7140;                 /* ROOFTOP */
    if(irc == 0 && icompr(nresp,"OK",&K2) == 0) goto S7150;/* OK */

    clrSs(&K24,&K24,&K1,&K78,&irc);
    inatSb(&K24,&K1,"Valid responses are 'OK', ^, or !",&K33,nresp,&K24,&irc);
    goto S7135;                              /* INVALID ANSWER...RE-ASK */

S7140:

    /*
     ---- Rooftop handler.  If rooftop is the response, unblink the
          blinking fields and position cursor for screen work.

    */
    clrSs(&K24,&K24,&K1,&K78,&irc);
    rstSs(&K0,&N1,&irc);                     /* UN-BLINK ALL FIELDS */
    posSs("INVOICE ",&K7,&irc);
    goto S3050;

S7150:

    /*
     ----------------------------------------------------------------------

         If the amount of this invoice is greater than the amount logged for
            this invoice, pack a HOLD.

    */
    n = 1;
    if(linitm) n = 13;

    for(i=1,D23=(D23=(n-i+1))>0?D23:1; D23>0; D23--,i+=1)
    {

        invoic = invli[i-1];
        linvSc("P ",&vcno,&invoic,&irc);     /* GET LOGGED AMOUNT */
        if(xtrkcom_amtlog == 0.e0) goto S7180;/* invoice not logged */
        if(!linitm) goto S7160;
        if(amnts[i-1] <= xtrkcom_amtlog) goto S7180;

S7160:
        if(cramnt <= xtrkcom_amtlog) goto S7180;/* not greater than logged amount */
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("H       ",8);/* HOLD INVOICE */
        ib = ib+1;
        xpScom1_pSscdt[ib] = 2.e0;           /* VERSION */
        mvbyt(xc_cScoid,&xpScom1_pSscdt[ib+1],&K4);/* COMPANY ID */
        mvbyt(&trtype,&xpScom1_pSscdt[ib+2],&K8);/* TRANSACTION TYPE */
        xpScom1_pSscdt[ib+3] = vcno;         /* V/C NUMBER */
        xpScom1_pSscdt[ib+4] = 0.e0;
        xpScom1_pSscdt[ib+5] = 0.e0;
        xpScom1_pSscdt[ib+6] = 0.e0;         /* HELD AMOUNT */
        mvbyt(&invoic,&xpScom1_pSscdt[ib+7],&K8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* EXPIRED DATE */
        xpScom1_pSscdt[ib+9] = effdat;       /* EFFECTIVE DATE */
        mvbyt("LOG ERR ",&xpScom1_pSscdt[ib+10],&K8);/* HOLD CODE */
        mvbyt("AMOUNT EXCEEDS LOG      ",&xpScom1_pSscdt[ib+11],&K24);/* HOLD  */
        /*
        /*  DESCP
        */
        mvwrd(&po,&xpScom1_pSscdt[ib+14],&K4);/* COMMIT ID */
        ib = ib+15;

S7180:;
    }


    /*
     ----------------------------------------------------------------------

         GET CONFIRMATION BEFORE POSTING ITEM

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S7920;/* DON'T STOP ON 'RE-ENTER' */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S7920;/* DON'T STOP ON 'RE-ENTER' */


    /*
     --- TEST TO SEE IF PPS CAN BE CHANGED

    */
    if(pps1 < 0.e0) goto S7500;

    vinfSc(&vcno,"    ","DATE PPS EXPIRY",&K15,&epps,&K0,&K0,&K0,&irc);

    x = 0.0e0;
    if(x == x) goto S7325;                   /* EXPIRY DATE NOT USED */

    if(datdue <= epps) goto S7325;

    outdat(&epps,&odate);
    WRITE(INTERNAL,xc_cSmess,78,FMT,F7320,1,REAL8,odate,0);
    errSs(xc_cSmess,&K78,&irc);
    bangSs(&irc);

S7325:
    errSs("Good entry.  RETURN to continue, \"*\" to change PPS, or \"^\"~",&K0,&irc);
    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7400;
    if(irc == 4) goto S8000;
    if(irc == 8) goto S1800;
    if(irc != 2) goto S9000;

    /*
     --- TOGGLE PPS

    */
    if(pps2 < 0.e0) goto S7350;              /* 'N     ' WAS DISPLAYED */
    pps2 = -1.e0;
    ppsout[0] = *(double*)fifstrgv("N       ",8);
    doutSs("PPS APPLICABLE",&K14,&ppsout[0],&K4,&irc);
    goto S7325;

S7350:
    pps2 = pps1;
    WRITE(INTERNAL,ppsout,5,FMT,F7375,1,REAL8,pps2,0);
    doutSs("PPS APPLICABLE",&K14,&ppsout[0],&K5,&irc);
    goto S7325;

S7400:
    if(pps1 == pps2) goto S7600;

    /*
     --- PACK PPS HOLD WHEN OVERRIDDEN

    */
    ib = ib+1;

    packjm(&i,xpScom1_pSscdt,&ib,&ircx);     /* Potentially Pack JOURNALS$MEMO entry */
    xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
    xpScom1_pSscdt[ib] = *(double*)fifstrgv("H       ",8);/* HOLD PURCHASE ORDER */
    ib = ib+1;
    xpScom1_pSscdt[ib] = 2.e0;               /* VERSION */
    mvbyt(xc_cScoid,&xpScom1_pSscdt[ib+1],&K4);/* COMPANY ID */
    mvbyt(&trtype,&xpScom1_pSscdt[ib+2],&K8);/* TRANSACTION TYPE */
    xpScom1_pSscdt[ib+3] = vcno;             /* V/C NUMBER */
    xpScom1_pSscdt[ib+4] = 0.e0;
    xpScom1_pSscdt[ib+5] = 0.e0;
    xpScom1_pSscdt[ib+6] = 0.e0;             /* HELD AMOUNT */
    mvbyt(&invoic,&xpScom1_pSscdt[ib+7],&K8);/* INVOICE NUMBER */
    xpScom1_pSscdt[ib+8] = 0.e0;             /* EXPIRED DATE */
    xpScom1_pSscdt[ib+9] = effdat;           /* EFFECTIVE DATE */
    mvbyt("*PPS    ",&xpScom1_pSscdt[ib+10],&K8);/* HOLD CODE */
    mvbyt("PPS WAS OVERRIDDEN  ",&xpScom1_pSscdt[ib+11],&K20);/* HOLD DESCP */
    mvwrd(&po,&xpScom1_pSscdt[ib+14],&K4);   /* COMMIT ID */
    ib = ib+15;
    goto S7600;

S7500:

    /*
     --- GOOD ENTRY

    */
    errSs("Good entry. RETURN to continue. Otherwise, enter ^~",&K0,&irc);
    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7600;
    if(irc == 4) goto S8000;
    if(irc == 8) goto S1800;
    goto S9000;

S7600:

    /*
         IF THIS IS A CHANGE, DELETE PRIOR VERSION OF THIS ITEM

    */
    rstSs(&K0,&N1,&irc);                     /* UN-BLINK ALL FIELDS */
    if(nfunc != *(short*)fifstrgv("C ",2)) goto S7950;
S7920:
    if(nswvb == 1) goto S7940;
    if(xpScom1_nscdat > 0) goto S7950;
    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    goto S7950;

S7940:

    /*
     ----- Change the Reference # for the revised version of Verify Batch

    */
    mvbyt(&refno,&hldref,&K8);
    jstrSa(1,&refno,8);
    mvbyt("/ ",&refno,&K1);
    rmvbSc(&refno,&K8,&K0,&len,&irc);

    /*
         DELETE REVISED VERSION OF REFERENCE, IF IT ALREADY EXISTS

    */
    iSdlet(&batch,&refno,&irc);

S7950:

    /*
         SAVE IMAGE OF INPUT SCREEN

    */
    if(image) prntSs(&K1,&irc);
    iSsave(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    /*
         SAVE DATA FROM SCREEN

    */
    iSdata(&batch,&refno,xpScom1_pSscdt,&ib,&irc);
    if(irc != 0) goto S9000;

    iSxinv(&batch,&refno,&vcno,&invoic,&irc);

    if(nswvb == 1) mvbyt(&hldref,&refno,&K8);

    goto S1800;

S8000:

    /*
         SAVE screen image of a BAD entry screen

    */
    nread = 1;                               /* set flag to read current screen image */
    goto S8100;

S8050:
    nread = 0;                               /* reset flag - don't read  screen image */
    goto S8100;

S8100:

    /*
         delete all previous references to this Batch#/Reference#

    */
    iSdlet(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    /*
         SAVE image of BAD screen in INPUT$BATCHES

    */
    iSbad(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8120;/* DON'T STOP ON RE-ENTER */
    errSs("Screen SAVED for later use.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);
S8120:
    if(irc == 0) goto S1800;
    goto S9000;

S9000:
    if(nswvb != 1) goto S9100;

    /*
     ----- Check to see if any more records in the Verify Batch

    */
    fill(xc_cSmess,&K4,"  ");
    iSnext(&batch,xc_cSmess,&irc);
    if(irc <= 1) goto S9100;

    /*
     ----- No more records, Delete the Verify Batch

    */
    iSdlet(&batch,&K0,&irc);

S9100:
    fileSc("CLO ",&K32,&K0,&K0,&K0,&irc,0);
    fileSc("CLO ",&K33,&K0,&K0,&K0,&irc,0);

    return;

}
#undef NFIELD
/*

-----------------------------------------------------------------------

     DLP January 25, 1993 20:06:36    PRO

     Restored call to READ$S to use a mode of 1 to cause SCFM validation.

-----------------------------------------------------------------------

     DLP March 9, 1993 08:26:12    JEN

     Display PPS rate with 2 decimal digits.  PPS EXPIRY date is now
     not used.

-----------------------------------------------------------------------

     GMT January 2, 1994 16:05:12    HBZ

     Enhance invoice entry program to allow direct entry of the client
     number that is to be billed by automatic T&E billing.  A client number
     can be entered on each line of distribution of an invoice.  A client
     number can also be entered for the entire invoice, unless overridden on
     a particular line of distribution.

-----------------------------------------------------------------------

     GMT January 2, 1994 22:59:44    PHI-0115

     Revise arguments to "Vendor Control" (VCTL$C) to include a
     parameter that stipulates whether to get the "F"irst vendor
     control record that fits, or to look thru all applicable
     vendor control records and use the record that has the "B"est
     fit.

     Also, add new arguments to HOLD$C to indicate whether the
     invoice being processed is charged to a purchase order or
     to a subcontract.  With this information, hold codes can be
     configured to be applied only to invoices charged to purchase
     orders or only to invoices charged to subcontracts.

-----------------------------------------------------------------------

     GEL January 4, 1994 16:04:28    HBZ-0299

     Corrections to satisfy DEC ALPHA compiler.

-----------------------------------------------------------------------

     RDS February 4, 1994 14:43:40    HBZ-0309

     Change the way JOURNALS$MEMO is posted to accomodate JOURNALS$MEMO
     posting from an IMPORT BATCH.  JOURNALS$MEMO data is now packed in
     the INPUT$BATCHES "D" record with a code of "JM".  When this set is
     encountered, it is DATA$Fed to JOURNALS$MEMO.  If the subsequent "D"
     record set results in call(s) to Post to "JOURNALS" (PST$J2) then a
     JOURNALS$MEMO record will be added with each JOURNALS record that is
     added.

-----------------------------------------------------------------------

     GEL February 16, 1994 13:23:00    DFZ-0001

     Eliminate FORTRAN Writes to the user terminal.

-----------------------------------------------------------------------

     DLP July 22, 1994 14:05:04    HBZ-0330

     Changed calls to FACT$C to calls to FRMA$C

-----------------------------------------------------------------------

     DLP September 7, 1994 13:38:20    HBZ

     Modified to save the reference when in "X" mode and a
     Duplicate Invoice was found for CONFIRM DUPLICATE INVOICE

-----------------------------------------------------------------------

     GMT March 19, 1995 09:03:52    SMI-0007

     Remove code that packs a "Q" (quantity) data set in input batches
     buffer.  Since the file RESOURCE$DATA has been obsoleted, POSTTR
     no longer recognizes a "Q" data set.

-----------------------------------------------------------------------

     GEL April 4, 1995 14:27:32    MAI

     Check number was not being properly validated allowing bogus numbers
     to be posted.

-----------------------------------------------------------------------

     GMT May 9, 1995 18:01:16    FRU-0183

     Add initialization of new BILLING$COM variable B$COID to support
     inter-company automatic t&e billing.

-----------------------------------------------------------------------

     GMT May 18, 1995 14:12:52    SMI-0009

     Add common variable for VENDOR INVOICE DATE.

-----------------------------------------------------------------------

     DLP October 26, 1995 15:53:48    MCI-0051

     Modified to use HOLD$C and to always build a version 2
     of the Hold buffer

-----------------------------------------------------------------------

     GEL November 8, 1995 14:17:00    SMI-0055

     Do not blink the activity if ACCOUNT LIST validation is what caused
     the failure.

-----------------------------------------------------------------------

     GMT November 9, 1995 09:05:24    SMITH

     When a transaction is charged to a 'T&E' type job (per JC JOB INFO,
     field JOB TYPE), but there are no billing rates that will produce
     a billing for the transaction, a warning will be issued to the
     user.  When possible, the input field on the entry screen that is
     initiating the transaction will blink.
     This warning can be suppressed company-wide and on all batch input
     screens by installing a configuration parameter as follows:

           key:  AUTO T&E BILLING RATE WARNING
           data: NO

-----------------------------------------------------------------------

     DLP November 20, 1995 18:27:16    SMI-0056

     Added code to pack a Group Separator between each transaction

-----------------------------------------------------------------------

     RDS January 12, 1996 10:20:00    SMI-0064

     Added support for Config Parameter "TRTRADE PURCHASE MEMO REQUIRED".

-----------------------------------------------------------------------

     DLP March 25, 1996 11:12:24    MOS-0032

     Added code to calculate and/or accept SALES TAX by line item
     and to pack the SALES TAX into "ST" sets for posting to
     SALES$TAX$DATA

-----------------------------------------------------------------------

     DLP March 26, 1996 14:04:32    MCI-0068

     Added code to get an ALLOCATION FORMULA from the screen and if it
     is defined to display the distribution on the screen.

-----------------------------------------------------------------------

     RDS March 28, 1996 16:34:00    SMI-0075

     Establish B$BREF with the value in the screen field "BILLING REFERENCE"
     so that Smith can have 1 BB$BILLING$MEMO BB per Input Batch Reference.

-----------------------------------------------------------------------

     RDS August 14, 1996 12:44:04    MCI-0068

     Change the 4010 FORMAT statement to put the *RTYP in the proper place
     in the key.

-----------------------------------------------------------------------

     GMT February 06, 1997 20:57:31    JHK

     Add a chunk of code to pack billing information that arises
     from sales and/or use tax.

-----------------------------------------------------------------------

     RDS March 27, 1997 08:58:15    PRO

     Correct handling of Distribution error checking when sales tax is
     involved.

-----------------------------------------------------------------------

     GEL May 02, 1997 12:44:20    ADM-1250

     Eliminate free formatted DECODEs.  Such a DECODE on a blank buffer
     could produce undesirable results.

-----------------------------------------------------------------------

     GMT December 09, 1997 00:19:50    BCKT

     Revise to associate "VATDR" with input field VAT INPUT ACCOUNT
                     and "VATCR" with input field VAT OUTPUT ACCOUNT.

-----------------------------------------------------------------------

     RDS January 17, 1998 10:11:14    OCJ

     Add code to auto-dup the Invoice number column and validate that
     each line of distributuion has an invoice number.  The invoice
     column is optional and is only on one standard trade purchase
     screen: "TR QUICK CHECK".

-----------------------------------------------------------------------

     SCB February 26, 1998 13:14:01    DEV

     Added capability to read either the new 58 byte key or old 52 byte  key
     COMMITMENT$MASTER file. If applicable, changed the date format in the C$M
     key to handle an 8 char date field.

-----------------------------------------------------------------------

     RDS August 06, 1998 17:00:18    PRO/JRT

     Remove 2 lines of code to fix the condition where the last entity
     on the last distribution line was posting the tax amount for that
     entity plus the total tax for the line.

-----------------------------------------------------------------------

     DBS August 25, 1998 16:52:43    MCI0000

     made vendor control HOLDs more specific,
     allowing releases to be more accurate

-----------------------------------------------------------------------

     CJO February 22, 1999 08:48:23    PRO

     General source file cleanup; assumes this version is
     now Y2K compliant and has no need to consider 2 vs 4
     digit years.  The edits include :
       Delete/modify code assuming NEWLAB, NEWC$M and NEWL$D
       are all true.
       Delete LOGICAL Y2K and associated tests and date
       conversions.
       Delete comments having /VAX/PRIME/POSIX notes

-----------------------------------------------------------------------

     SCB June 21, 1999 12:44:28    MAI-0070

     Added capability to post zero GST values for MAI for tax reporting
     purposes.

-----------------------------------------------------------------------

     SCB March 02, 2000 09:48:11    BEC-0017

     Added AZ to the GST zero value calculation.

-----------------------------------------------------------------------

     SCB March 02, 2000 11:55:41    BEC-0017

     Changed JOURNALS$MEMO output number format in TMEMO from a formatted
     number to an F12.2 format because the commas weren't being processed
     by Report Writer reports properly.

-----------------------------------------------------------------------

     RDS April 07, 2000 14:48:43    MOS

     Resolve the problem with sales tax vs use tax handling that MOS has
     struggled with in the past.  This program was posting the wrong tax
     amount on the last entity when the sales tax code included one or more
     USE tax entities.

-----------------------------------------------------------------------

     RDS June 21, 2000 09:56:02    TIC-0146

     Changes to support the addition of "ACCOUNT" (debit job account)
     to the COMMITMENT$MASTER file.

-----------------------------------------------------------------------

     DBS December 05, 2000 09:33:14    DES0083

     Added support for cross checking invoices in open batches

-----------------------------------------------------------------------

     RDS May 22, 2002 13:20:06    DEV-0004

     Implement the new "confirm" popup box for duplicate invoice/DIN
     confirmation.

-----------------------------------------------------------------------

     DBS October 04, 2002 16:26:55    TIC

     Converted some VGLA$C calls to VGLA$2.

-----------------------------------------------------------------------

     RDS December 19, 2002 15:01:44    PUG-0008

     Fix the position of PACKJM calls so that the JM set no longer
     destroys the first element of the next "D" record set.

-----------------------------------------------------------------------

     RDS September 26, 2003 13:56:54    HBZ

     Upgrade this program to properly deal with multiple INPUT$BATCHES
     "D" records.

-----------------------------------------------------------------------

     DBS July 07, 2004 10:25:38    TRU0120

     Added support for override batch effective date, use the following
     input screens fields to override.

     MONTH EFFECTIVE
     DAY EFFECTIVE
     YEAR EFFECTIVE

-----------------------------------------------------------------------

     GMT October 06, 2004 12:59:58    FRU 12706

     Add functionality to submit an additional commitment created
     by the "Commit As Expended" feature to T&E Billing.

-----------------------------------------------------------------------

     GEL October 25, 2005 12:11:20    PT6-0006

     Recode all calls to POUT$S so that "row" and "column" position
     references are eliminated.

-----------------------------------------------------------------------

     GEL May 10, 2007 10:13:41    ACC14687

     Added ability to hold invoices by Type with the Config Parameters

     HOLD ALL INVOICES: {type}
     HOLD ALL SUBCONTRACT INVOICES: {type}
     HOLD ALL TRADE INVOICES: {type}

     The program first looks for the Paramater for the specific Type.
     If it is not found it then looks for the corresponding Parameter
     with no Type.

-----------------------------------------------------------------------

     GEL July 05, 2007 18:55:42    TRU14710

     Enhance to validate effective dates verses journal close dates when
     doing an ICT.  This change will cause a hard error at data entry.

-----------------------------------------------------------------------

     GEL August 05, 2008 13:43:26    MOS-0112

     Corrected a bad field name and a potential infinite loop.

-----------------------------------------------------------------------

     GEL September 23, 2010 17:32:08    ZHI-0044

     When packing the Hold Reason in the INPUT$BATCHES data record
     for AMOUNT EXCEEDS LOG pack 24 chars rather than 20.  The
     uninitialized 4 chars were causing the data base server to barf.

-----------------------------------------------------------------------

     GEL September 27, 2010 12:23:59    ZHI-0044

     Undo previous change.  It is superseded by a change to
     post.posttr.ftn which unpacks 20 instead of 24 chars.

-----------------------------------------------------------------------

     GEL March 09, 2011 16:19:43    KIR-0032

     Look for a new field AMOUNT SUBJECT TO TAX.  There are times
     when only a portion of the invoice is subject to tax.  This is
     the mechanism to stipulate that override amount.  If the field
     doesn't exist (or exists and is blank) then tax will be computed
     on the entirety of the invoice.

     Enhance the memo for tax accruals written to the JOURNALS file.
     It will include "S TAX" for Sales Tax (or "U TAX" for Use tax)
     and the Tax Code.

*/
