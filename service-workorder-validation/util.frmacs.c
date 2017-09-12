#define LPROTOTYPE
#define PRIMELIB
#include "fortran.h"
#include "cmis_com.h"
#include "sc_com1.h"
#include "sc_com2.h"
#include "libutil.h"
#include "libscr.h"
#include "libfio.h"
/*
-----------------------------------------------------------------------
     util.frmacs.ftn

     Custom "format activity" procedure

        This routine comes into play initially in two online programs:

        s-prtime
        s-inresource-trans

        The cmis_com variables C$VJOB, C$VPHS and C$VACT are set, FRMA$C is
        called which in turn calls this routine.  util.frma-c calls us at
        it's start with a MODE = "B" (for before) and then at the end with
        MODE = "A" (for after).  We are to validate the activity, under
        certain circumstances when MODE = "B".  In any case we will reset
        C$VJOB, C$VPHS and C$VACT upon exit.

-----------------------------------------------------------------------

*/


void frmacs(short *mode,double *rjob,double *phs,short *iact,short *ierr)
{
static short K4 = 4;
static short K9 = 9;
static short K10 = 10;
static short K18 = 18;
static short K0 = 0;
static short K3 = 3;
static short K8 = 8;
static short K6 = 6;
static short K20 = 20;
static short K40 = 40;
static short K2 = 2;
static short duplxS;                         /* DUPLEX PRIMOS FUNCTION */
static short cpShlp[8];                      /* NAME USED FOR HELP REQUESTS IN SCFM */
static short iactiv[5];
static short key[60];
static short ierbuf[20];
static short jbwenn[3];

static short iblank[5];
static double result;
static short irc;
static short ifc;
static short ilc;
static short len;
static double wennjb;
static int FIRST = 1;
static int ftnsiz[] = {1,1,5};
static namelist DATAVAR[] = {
"iblank",iblank,1,ftnsiz
};
static char *DATAVAL[] = {
"$DATAVAR",
"iblank=5*'',",
"$END"
};

static char* F1620[] = {
    "(2a2,4x,5a2,102x)"
};

    if(FIRST) {
        FIRST=0;
        fiointu((char*)DATAVAL,0,2);
        fiornl(DATAVAR,1,NULL);
    }

    *ierr = 0;

    if(*mode != *(short*)fifstrgv("B ",2)) goto S9000;

    if(xc_cSvjob == *(double*)fifstrgv("        ",8)) goto S9900;/* No setup so bail */

    /*
         The custom validation only happens for ACCO & SUNB

    */
    if(icompr(xc_cScoid,"ACCO",&K4) != 0 && icompr(xc_cScoid,"SUNB",&K4) != 0) goto S9900;

    /*
         Qualify that we are in a place where Wennsoft workorder (service order)
         validation should occur

    */
    if(xsc1_scSsel[0] == *(short*)fifstrgv("PR",2)) goto S1100;
    if(xsc1_scSsel[0] == *(short*)fifstrgv("TR",2)) goto S1100;
    if(icompr(xsc1_scSsel,"ININV CHG",&K9) == 0) goto S1100;

    goto S9000;

S1100:
    dnumSc(iact,&K10,&result,&irc);
    if(irc != 0) goto S9000;

    /*
         Exceptions

    */
    if(icompr(xsc1_scSsel,"PRSV",&K4) == 0) goto S9000;

    /*
         Validate only ceratin activity ranges

    */
    mvbyt(iact,iactiv,&K10);
    jstrSa(1,iactiv,10);                     /*  Right */
    lstrSa(". ",1,iactiv,10,&ifc,&ilc);
    if(ifc == 0) goto S1125;
    len = 10-ifc+1;
    msubSa(iblank,10,1,len,iactiv,10,ifc,10);
    jstrSa(1,iactiv,10);                     /*  Right */

S1125:

    if(icompr(xc_cScoid,"SUNB",&K4) == 0) goto S1200;

    if(icompr(iactiv,"    100000",&K10) < 0) goto S9000;

    if(icompr(iactiv,"    599999",&K10) > 0 && icompr(iactiv,"   1000000",&K10) < 0) goto S9000;

    goto S1400;

S1200:

    if(icompr(iactiv,"     30000",&K10) < 0) goto S9000;

S1400:

    /*
         Validate only certain jobs

    */
    if(*rjob >= 51 && *rjob <= 59) goto S1500;
    if(*rjob >= 71 && *rjob <= 99) goto S1500;
    if(*rjob == 111) goto S1500;
    if(*rjob >= 150 && *rjob <= 159) goto S1500;
    if(*rjob >= 171 && *rjob <= 199) goto S1500;

    goto S9000;

S1500:

    ioSf("OPEN","WORK$ORDER$SERVICE",&K18,"    ",&K0,&K0,&K0,&K0,ierr);
    if(*ierr == 0) goto S1600;

    retuSs("Cannot open WORK$ORDER$SERVICE to do Wennsoft validation ~",&K0,"r!^ ",&K3,&irc);

    goto S9000;

S1600:
    jstrSa(2,iactiv,10);                     /*  Left */

    WRITE(INTERNAL,key,120,FMT,F1620,1,DO,2,INT2,xc_cScoid,DO,5,INT2,iactiv,0);

    ioSf("FIND","WORK$ORDER$SERVICE",&K18,"    ",key,&K0,&K0,&K0,ierr);
    if(*ierr == 0) goto S2000;

    errSs("Invalid workorder, either enter correct workorder# or use Job#  100~",&K0,&irc);

    blnkSs(&xc_cSvact,&K8,&irc);

    goto S3000;

S2000:

    dataSf("GET ","WORK$ORDER$SERVICE",&K18,"    ","JOB/DEPT",&K8,jbwenn,&K6,&K0,&K0,&irc);

    dnumSc(jbwenn,&K6,&wennjb,&irc);
    if(wennjb == *rjob) goto S9000;

    fill(ierbuf,&K20,"  ");
    mvbyt("Use Job # ",ierbuf,&K10);
    mvbyt(jbwenn,&ierbuf[5],&K6);

    errSs(ierbuf,&K40,&irc);

    doutSs(&xc_cSvjob,&K8,jbwenn,&K6,&irc);
    posSs(&xc_cSvjob,&K8,&irc);

    *ierr = 7;

S3000:

    if(icompr(&xc_cSvjob,"TO JOB",&K6) != 0) goto S9000;

    protSs("TO JOB",&K6,&K2,&K0,&irc);
    protSs("TO PHASE",&K8,&K2,&K0,&irc);

    goto S9000;

S9000:

    xc_cSvjob = *(double*)fifstrgv("        ",8);
    xc_cSvphs = *(double*)fifstrgv("        ",8);
    xc_cSvact = *(double*)fifstrgv("        ",8);

S9900:

    return;
}
/*
-----------------------------------------------------------------------

     GEL May 22, 2012 12:53:14    ACC-0228

     Strip of .00 before applying the test for ranges of activities.

-----------------------------------------------------------------------

     GEL June 18, 2012 17:44:55    ACC-0228

     Skip Wennsoft workorder validation if the activity is non numeric.

-----------------------------------------------------------------------

     GEL June 20, 2012 17:16:47    ACC-0228

     The decimal is not always in the 8th char position of the
     activity, sometimes it's in the 10th.  Modify to strip off
     the decimal and everything to the right no matter where it is.

-----------------------------------------------------------------------

     GEL May 21, 2013 11:57:32    ACC

     Turn on custom activity validation for any selection that
     begins with "ININV CHG".  References ticket:69

*/
