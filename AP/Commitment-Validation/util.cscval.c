#define LPROTOTYPE
#define PRIMELIB
#include "libutil.h"
#include "libfio.h"
#include "libbb.h"
#include "libscr.h"
#include "fortran.h"
#include "parm_k.h"
#include "cmis_com.h"
#include "sc_com1.h"
/*
-----------------------------------------------------------------------
     GEL 04/29/13

     Where ITYPE - PO or SC
           RJOB  - Job number
           RPHS  - Phase number
           NACTIV- Activity number
           NCOMIT- Job number
           AMOUNT- Amount billed
           IERR  - Return code
                   0= Passed validation
                   1= Insufficient balance
                   2= Normally Commit required - Here, User entered ^
                   6= Commitment does not exist
                   9= Perform standard validation instead

*/

void cscval(short *itype,double *rjob,double *rphs,short *nactiv,short *ncomit,double *amount,short *ierr)
{
static short K13 = 13;
static short K25 = 25;
static short K8 = 8;
static short K0 = 0;
static short K2 = 2;
static short N1 = -1;
static short K10 = 10;
static short K4 = 4;
static short K64 = 64;
static short K17 = 17;
static short K1 = 1;
static short K30 = 30;
static short K38 = 38;
static short K9 = 9;
static short K7 = 7;
static short K5 = 5;
static short K40 = 40;
static short K36 = 36;
static short K24 = 24;
static short K39 = 39;
static short K80 = 80;
static short K78 = 78;
static short K20 = 20;

static short nswovr = 0;
static short duplxS;                         /* DUPLEX PRIMOS FUNCTION */
static short cpShlp[8];                      /* NAME USED FOR HELP REQUESTS IN SCFM */

static int i4func;

static short ncoid[2];
static short key[64];
static short keysav[64];
static short mess[40];
static short nresp[12];

static unsigned short found;
static unsigned short debug;
static double amtovr;
static short irc;
static short nflag;
static double orignl;
static double change;
static double billed;
static double ampaid;
static short mflag;
static short lensav;
static short icntyp;
static double cntrct;
static double orig;
static double chng;
static double bill;
static double paid;
static double unbill;
static double unpaid;
static double remain;
static short len;
static short ircSb;

static char* F1015[] = {
    "(f8.0)"
};
static char* F1125[] = {
    "(2a2,b'ZZZZZ#',b'Z#')"
};


    /*
    -----Check for Overbill Margin in GENERAL INFO

    */
    if(nswovr != 0) goto S1050;
    nswovr = 1;
    amtovr = .005e0;                         /* Default half penny */
    gnliSc("READ","ALLOWABLE OVERBILL AMOUNT",&K25,mess,&K8,&irc);
    if(irc != 0) goto S1050;
    if(READ(INTERNAL,mess,8,IOSTAT,NULL,1,FMT,F1015,1,REAL8,&amtovr,0)) goto S1025;
    if(amtovr <= 0.e0) amtovr = .005e0;
    goto S1050;

S1025:
    ferrSc(&K0,&K0,"Error decoding ALLOWABLE OVERBILL AMOUNT (CSCVAL)~",&K0);

S1050:
    debug = FALSE;
    if(xc_cSenvr != 1) debug = TRUE;
    *ierr = 9;                               /*  Perform standard validation */
    if(debug) errSp("ITYPE =~",&K0,itype,&K2);
    if(debug) errSp("NCOMIT=~",&K0,ncomit,&K8);
    if(debug) errSp("AMOUNT=~",&K0,amount,&K0);

    cvalSc(itype,rjob,rphs,&nflag,&irc);
    if(debug) errSp("NFLAG =~",&K0,&nflag,&N1);
    if(nflag != 1) goto S9000;               /*  Only if Warning */

    *ierr = 0;                               /*  Assume validation will be passed */
    if(icompr(ncomit,"-       ",&K8) == 0) goto S3000;

    jinfSc(rjob,rphs,"JC  ","COMPANY ID",&K10,ncoid,&K4,&K0,&K0,&irc);

    fill(key,&K64,"  ");
    WRITE(INTERNAL,key,12,FMT,F1125,1,DO,2,INT2,ncoid,REAL8,*rjob,REAL8,*rphs,0);

    found = FALSE;
    orignl = 0.0e0;
    change = 0.0e0;
    billed = 0.0e0;
    ampaid = 0.0e0;

    i4func = *(int*)fifstrgv("FIND",4);
    mflag = FLSNXT+FLSUKY;
    lensav = 22;                             /*  Thru Job/Phase summary */
    mvwrd(key,keysav,&K64);

S1200:
    ioSf(&i4func,"COMMITMENT$MASTER",&K17,"    ",key,&K0,&mflag,&K1,&irc);

    if(icompr(key,keysav,&lensav) != 0) irc = 7;
    if(irc == 7) goto S2500;
    if(irc != 0) ferrSc(&K30,&irc,"CSCVAL: Trying to find a commitment for validation~",&K0);

    i4func = *(int*)fifstrgv("NEXT",4);
    mflag = FLSUSE+FLSPLW+FLSUKY+FLSRET;

    gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","CONTRACT TYPE",&K13,&icntyp,&K2,&K0,&K0,&irc);
    if(icntyp != *itype) goto S1200;

    gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","CONTRACT",&K8,&cntrct,&K8,&K0,&K0,&irc);
    if(icompr(ncomit,&cntrct,&K8) != 0) goto S1200;

    found = TRUE;

    /*
         determine unbilled commitment under this Job/Phs/CommitID

    */
    gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$ORIGINAL",&K9,&orig,&K0,&K0,&K0,&irc);

    gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$CHANGE ",&K7,&chng,&K0,&K0,&K0,&irc);

    gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$BILLED ",&K7,&bill,&K0,&K0,&K0,&irc);

    gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$PAID ",&K5,&paid,&K0,&K0,&K0,&irc);

    orignl = orignl+orig;
    change = change+chng;
    billed = billed+bill;
    ampaid = ampaid+paid;

    goto S1200;

S2500:
    fill(mess,&K40,"  ");
    if(found) goto S2750;
    mvbyt("WARNING...Commitment is not on file.",mess,&K36);
    *ierr = 6;                               /*  Commitment does not exist */
    goto S3000;

S2750:
    unbill = orignl+change-billed+amtovr;
    unpaid = orignl+change-ampaid+amtovr;

    remain = unbill;                         /*  Batch entry */
    if(xc_cSenvr != 1) remain = unpaid;      /*  TR PROOF */
    if(debug) errSp("AMTOVR=~",&K0,&amtovr,&K0);
    if(debug) errSp("UNBILL=~",&K0,&unbill,&K0);
    if(debug) errSp("UNPAID=~",&K0,&unpaid,&K0);
    if(debug) errSp("REMAIN=~",&K0,&remain,&K0);
    if(iameq(&remain,amount) >= 0) goto S3000;
    mvbyt("WARNING Amt Billed exceeds Commitment.",mess,&K38);
    *ierr = 1;                               /*  Insufficient balance */
    goto S3000;

S3000:
    if(*ierr == 0) goto S9000;
    if(xc_cSenvr != 1) goto S9000;

    /*
         Handle confirmation when in Web Edition

    */
    if(xsc1_scSsmd != 21) goto S3015;

S3010:
    len = nlenSa(mess,80);
    confrm(mess,&len,&irc);
    if(irc == 0) goto S9000;

    goto S3010;

S3015:
    mvbyt("Enter \"OK\" to continue, or ^ to change.",&mess[20],&K39);
    rmvbSc(mess,&K80,&K1,&len,&irc);

    inatSb(&K24,&K1,mess,&len,nresp,&K24,&ircSb);

    clrSs(&K24,&K24,&K1,&K78,&irc);
    if(ircSb == 8) goto S3075;
    if(ircSb == 0 && icompr(nresp,"OK",&K2) == 0) goto S3050;/* OK */

    fill(mess,&K40,"  ");
    mvbyt("Invalid Response....",mess,&K20);
    goto S3015;                              /* INVALID ANSWER...RE-ASK */

S3050:
    goto S9000;

S3075:
    *ierr = 2;                               /*  To force calling program to branch back to top */
    goto S9000;

S9000:
    if(debug) errSp("IERR  =~",&K0,ierr,&N1);
    return;
}
/*
-----------------------------------------------------------------------

     GEL May 02, 2013 13:37:00    ACC-0267

     Custom routine to validate commitments down to the
     Job/Phase/Commitment ID.  References ticket: 44

-----------------------------------------------------------------------

     GEL May 17, 2013 12:18:16    ACC-0267

     Add checking for Config Param ALLOWABLE OVERBILL AMOUNT.

     Modify the warning messages to require the user to enter "OK"
     to confirm.  References ticket: 44

-----------------------------------------------------------------------

     GEL June 03, 2013 13:33:53    ACC-0267

     Modified the warning messages to require user to enter "OK"
     to continue or "^" to change.  If the user enters a "^"
     change the return status to 2 so the calling Batch Input
     program will branch back up.

*/
