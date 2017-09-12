#define LPROTOTYPE
#define PRIMELIB
#include "fortran.h"
/*
--------------------------------------------------------------------
     RDS 10/24/03

     Produce a "SA FILE LOAD" report

*/

#include "libSQLclient.h"
#include "libscfm.h"
#include "libutil.h"
#include "libfio.h"
#include "libscr.h"
#include "cmis_com.h"
#include "iobuf_f.h"
#include "big_memory.h"
#include "lines_com.h"
#include "shared_com.h"
#include "parm_k.h"
void sa2100(void)
{
static short T1;
static short K24 = 24;
static short K80 = 80;
static short K240 = 240;
static short K28 = 28;
static short K0 = 0;
static short K30 = 30;
static short K120 = 120;
static short K14 = 14;
static short K72 = 72;
static short K13 = 13;
static short K15 = 15;
static short N1 = -1;
static short K6 = 6;
static short K40 = 40;
static short K32 = 32;
static short K18 = 18;
static short K22 = 22;
static short K10 = 10;
static short K9999 = 9999;
static short K60 = 60;
static short K1 = 1;
static double R2 = 0.e0;
static short K11 = 11;
static short K5 = 5;
static short K8 = 8;
static short K20 = 20;
static short K26 = 26;
static short K7 = 7;
static short filelS;

static short itfile[14];
static short itrtyp[2];
static short itfnam[16];
static short ipath[40];
static short itodir[40];
static short key[60];
static short keysav[60];

static short ititle[40];
static short itext[120];
static short iform[17];
static short ifdlen[200];
static short kord[200];
static short imfunc[20];

static int icnt;
static int irep;
static int iupd;
static int iskp;
static int iadd;
static int idel;
static short irc;
static short irep1;
static short iupd1;
static short iskp1;
static short iadd1;
static short idel1;
static short n1;
static short n2;
static short ifildx;
static short npath;
static short nxtlit;
static short nfld;
static short mflag;
static short irclit;
static short icol;
static short length;
static short n;
static short ifldty;
static short ich;
static short i;
static short l;
static short ist;
static short ichpky;
static short j;
static short l1;
static short l2;
static double code;
static short ii;
static double dp;
static short lenfor;
static short k;
static short islash;
static short n3;
static short ircx;
static int FIRST = 1;

#define ifld (xbigmem_memS)
#define istcol ((xbigmem_memS+3200))
#define lstcol ((xbigmem_memS+3400))
#define ilit ((xbigmem_memS+3600))
#define lenlit ((xbigmem_memS+3800))
#define lit ((xbigmem_memS+4000))
#define iformi ((xbigmem_memS+6000))
#define ln ((xbigmem_memS+8200))
static int ftnsiz[] = {1,1,40};
static namelist DATAVAR[] = {
"ititle",ititle,1,ftnsiz
};
static char *DATAVAL[] = {
"$DATAVAR",
"ititle='D ','A ','T ','A ','  ','F ','I ','L ','E ','  ','L ','O ','A ','D ','  ','  ','  ','  ','  ','  ','  ','',",
"18*'',",
"$END"
};

static char* F1120[] = {
    "(14a2,2a2/16a2/40a2/40a2/a2/a2/a2/a2/a2)"
};
static char* F1020[] = {
    "(80x,'TARGET FILE: ',14a2,39x,'       FROM: ',67x)"
};
static char* F1130[] = {
    "(4x,14a2,4x,2a2,16a2,48x)"
};
static char* F1240[] = {
    "(/'The following will be loaded into all ','records in the Target file:'/' ')"
};
static char* F1260[] = {
    "(i7,' records read',60x)"
};
static char* F1290[] = {
    "(40a2)"
};
static char* F1320[] = {
    "('Key: ',60a2//'File: ',14a2,'  Record type: ',2a2)"
};
static char* F2040[] = {
    "(/'Each record that is changed or added will have:'/' ')"
};
static char* F2120[] = {
    "(1000a2)"
};
static char* F2154[] = {
    "(//'UNABLE TO ASSIGN AN ALIAS VALUE FOR: ',//'FIELD: ',16a2,/'VALUE: ',40a2,//'FOR THE FOLLOWING INPUT RECORD:',/",
    "1000a2)"
};
static char* F2220[] = {
    "(//'MUST HAVE A VALUE FOR: ',16a2)"
};
static char* F2660[] = {
    "('Not found: ',60a2)"
};
static char* F2860[] = {
    "(//'UNABLE TO ASSIGN AN ALIAS VALUE FOR: ',//'FIELD: ',16a2,/'VALUE: ',40a2,//'FOR THE FOLLOWING INPUT RECORD:',/",
    "1000a2)"
};
static char* F8690[] = {
    "(/'FILE MOVED FROM: ',40a2/13x,'TO: ',40a2)"
};
static char* F8820[] = {
    "(/i8,' records read'/i8,' records updated'/i8,' records replaced'/i8,' records skipped'/i8,' records added'/i8,'",
    " records deleted')"
};

    if(FIRST) {
        FIRST=0;
        fiointu((char*)DATAVAL,0,2);
        fiornl(DATAVAR,1,NULL);
    }

    bstrSc(&irc);

    icnt = 0;
    irep = 0;
    iupd = 0;
    iskp = 0;
    iadd = 0;
    idel = 0;

    READ(10,FMT,F1120,1,DO,14,INT2,itfile,DO,2,INT2,itrtyp,DO,16,INT2,itfnam,DO,40,INT2,ipath,DO,40,INT2,itodir,INT2,&
      irep1,INT2,&iupd1,INT2,&iskp1,INT2,&iadd1,INT2,&idel1,0);

    outSc(&irc);

    WRITE(INTERNAL,itext,240,FMT,F1020,1,DO,14,INT2,itfile,0);

    n1 = nlenSa(itext,160);
    n2 = nlenSa(itrtyp,4);

    if(n2 > 0) msubSa(itrtyp,n2,1,n2,itext,160,n1+2,n1+n2+1);

    msubSa(ipath,80,1,67,itext,240,174,240);

    if(nlenSa(ipath,67) < 1) mvbyt(" Specified literals only",&itext[86],&K24);

    hdngSc(&K80,ititle,itext,&K240,&irc);

    ioSf("OPEN",itfile,&K28,itrtyp,&K0,&K0,&K0,&K0,&irc);
    if(irc != 0) ferrSc(&K30,&irc,"TRYING TO OPEN THE TARGET FILE~",&K0);

    ifildx = idxfil(itfile,&K28,itrtyp);

    npath = nlenSa(ipath,80);

    nxtlit = 1;
    nfld = 0;

    /*
         Read information entered on the "SA FILE LOAD INFO" screen
         pertaining to this report request.

    */
    WRITE(INTERNAL,key,120,FMT,F1130,1,DO,14,INT2,itfile,DO,2,INT2,itrtyp,DO,16,INT2,itfnam,0);

    mvbyt(key,keysav,&K120);

    mflag = FLSUKY+FLSNXT;

S1150:

    ioSf("FIND","FILE$LOAD$INFO",&K14,"    ",key,&K0,&mflag,&K0,&irc);
    if(icompr(key,keysav,&K72) != 0) irc = 7;
    if(irc != 0) goto S1200;

    dataSf("GET ","FILE$LOAD$INFO",&K14,"    ","LITERAL VALUE",&K13,&lit[nxtlit-1],&K80,&K0,&K0,&irclit);

    dataSf("GET ","FILE$LOAD$INFO",&K14,"    ","STARTING COLUMN",&K15,&icol,&N1,&K0,&K0,&irc);

    dataSf("GET ","FILE$LOAD$INFO",&K14,"    ","LENGTH",&K6,&length,&N1,&K0,&K0,&irc);

    n = iccnt(&lit[nxtlit-1],&K40);

    if(icol < 1 && n < 1) goto S1150;

    nfld = nfld+1;

    mvbyt(&key[36],(ifld+0+(nfld-1)*16),&K32);
    istcol[nfld-1] = icol;
    lstcol[nfld-1] = icol+length-1;

    dataSf("GET ","FILE$LOAD$INFO",&K14,"    ","FORMAT INSTRUCTION",&K18,(iformi+0+(nfld-1)*11),&K22,&K0,&K0,&irc);

    /*
         Get the field length as defined in the FD

    */
    ifdlen[nfld-1] = 0;

    gfldSf(itfile,&K28,itrtyp,(ifld+0+(nfld-1)*16),&K32,&kord[nfld-1],&ifdlen[nfld-1],&ifldty,xc_cSmess,&irc);
    if(irc != 0) errSp((ifld+0+(nfld-1)*16),&K32,&irc,&N1);
    if(irc != 0) ferrSc(&irc,&K30,"UNABLE TO FIND A FIELD WITH GFLD$F~",&K0);

    ilit[nfld-1] = 0;
    if(n < 1) goto S1150;

    ilit[nfld-1] = nxtlit;
    n1 = nlenSa(&lit[nxtlit-1],80);

    mchrSa(&ich,1,&lit[nxtlit-1],1);
    mchrSa(&ich,2,&lit[nxtlit-1],n1);

    if(ich != *(short*)fifstrgv("''",2) && ich != *(short*)fifstrgv("\"\"",2)) goto S1160;

    msubSa(&lit[nxtlit-1],n1,2,n1-1,xc_cSmess,80,1,n1-2);
    fillSa(&lit[nxtlit-1],n1,"  ");
    n1 = n1-2;
    mvbyt(xc_cSmess,&lit[nxtlit-1],&n1);
    n = n-1;

S1160:

    lenlit[nfld-1] = n1;

    nxtlit = nxtlit+n;

    goto S1150;

S1200:

    if(nfld < 1) ferrSc(&K10,&K9999,"No information found in FILE$LOAD$INFO.  See \"SA FILE LOAD INFO\"~",&K0);

    if(npath > 0) goto S2000;

    /*
         We are to load literals only

    */
    if(nxtlit == 1) ferrSc(&K10,&K9999,"No literals found to load.  See \"SA FILE LOAD INFO\"~",&K0);

    WRITE(OUTPUT,FMT,F1240,1,0);

    xlines_lines = xlines_lines+3;

    fill(key,&K60,"  ");

S1250:

    ioSf("FIND",itfile,&K28,itrtyp,key,&K0,&mflag,&K0,&irc);
    if(irc != 0) goto S8800;

    icnt = icnt+1;

    WRITE(INTERNAL,xc_cSmess,80,FMT,F1260,1,INT4,icnt,0);

    T1 = MEMOS;
    strsh(xc_cSmess,&K10,&T1);

    for(i=0; i==0 || i<nfld; i++)
    {

        if(ilit[i] < 1) goto S1300;

        /*
                "PUT" literal or memory function

        */
        fillSa(imfunc,40,"  ");
        mvbyt(&lit[ilit[i]-1],imfunc,&lenlit[i]);

        memfun(imfunc,xc_cSmess,&K80,&irc);
        if(irc != 0) mvbyt(&lit[ilit[i]-1],xc_cSmess,&lenlit[i]);

        l = nlenSa(xc_cSmess,80);

        dataSf("PUT ",itfile,&K28,itrtyp,(ifld+0+i*16),&K32,xc_cSmess,&l,&K0,&K0,&irc);

        if(icnt > 1) goto S1300;

        fill(xc_cSmess,&K40,"  ");
        mvbyt((ifld+0+i*16),xc_cSmess,&K32);
        n = lenlit[i];
        if(n > 48) n = 48;
        mvbyt(&lit[ilit[i]-1],&xc_cSmess[16],&n);

        WRITE(OUTPUT,FMT,F1290,1,DO,40,INT2,xc_cSmess,0);

        xlines_lines = xlines_lines+1;

        outxml("S ","LOAD FIELD",&K10,&xlines_lines,&K0,&K1,&R2,&irc);

S1300:;
    }

    ioSf("DEL ",itfile,&K28,itrtyp,key,&K0,&K0,&K0,&irc);
    if(irc == 0) goto S1400;

    WRITE(OUTPUT,FMT,F1320,1,DO,60,INT2,key,DO,14,INT2,itfile,DO,2,INT2,itrtyp,0);

    ferrSc(&K30,&irc,"TRYING TO DELETE A RECORD IN THE TARGET FILE~",&K0);

S1400:

    ioSf("ADD ",itfile,&K28,itrtyp,key,&K0,&K0,&K0,&irc);
    if(irc == 0) goto S1500;

    WRITE(OUTPUT,FMT,F1320,1,DO,60,INT2,key,DO,14,INT2,itfile,DO,2,INT2,itrtyp,0);

    ferrSc(&K30,&irc,"TRYING TO ADD A RECCORD TO THE TARGET FILE~",&K0);

S1500:

    iupd = iupd+1;

    goto S1250;

S2000:

    fileSc("READ",&K11,ipath,&npath,&K0,&irc,0);
    if(irc != 0) ferrSc(&K10,&irc,"Cannot open the input data file~",&K0);

    if(nxtlit == 1) goto S2100;

    WRITE(OUTPUT,FMT,F2040,1,0);

    xlines_lines = xlines_lines+3;

    for(i=0; i==0 || i<nfld; i++)
    {

        if(ilit[i] < 1) goto S2080;

        fill(xc_cSmess,&K40,"  ");
        mvbyt((ifld+0+i*16),xc_cSmess,&K32);
        n = lenlit[i];
        if(n > 48) n = 48;
        mvbyt(&lit[ilit[i]-1],&xc_cSmess[16],&n);

        WRITE(OUTPUT,FMT,F1290,1,DO,40,INT2,xc_cSmess,0);

        xlines_lines = xlines_lines+1;

        outxml("S ","LOAD FIELD",&K10,&xlines_lines,&K0,&K1,&R2,&irc);

S2080:;
    }

S2100:

    if(READ(11,IOSTAT,NULL,1,FMT,F2120,1,DO,1000,INT2,ln,0)) goto S8600;

    icnt = icnt+1;

    WRITE(INTERNAL,xc_cSmess,80,FMT,F1260,1,INT4,icnt,0);

    T1 = MEMOS;
    strsh(xc_cSmess,&K10,&T1);

    /*
         Create the primary key

    */
    fillSa(key,120,"  ");

    ist = 1;

    for(i=0; i==0 || i<NKEYS; i++)
    {

        ichpky = xfio_ikeyS[ifildx-1][i][16];
        if(ichpky == 0) goto S2350;
        if(ichpky == *(short*)fifstrgv("  ",2)) goto S2350;

        if(icompr(&xfio_ikeyS[ifildx-1][i][0],"*FILL ",&K5) == 0) goto S2290;

        if(icompr(&xfio_ikeyS[ifildx-1][i][0],"*COID ",&K5) != 0) goto S2130;

        msubSa(xc_cScoid,4,1,4,key,120,ist,ist+ichpky-1);

        goto S2140;

S2130:

        if(icompr(&xfio_ikeyS[ifildx-1][i][0],"*RTYP ",&K5) != 0) goto S2140;

        msubSa(itrtyp,ichpky,1,ichpky,key,120,ist,ist+ichpky-1);

        goto S2290;

S2140:

        for(j=0; j==0 || j<nfld; j++)
        {

            if(icompr(&xfio_ikeyS[ifildx-1][i][0],(ifld+0+j*16),&K32) != 0) goto S2200;

            if(xfio_ikeyS[ifildx-1][i][27] < 1) goto S2160;

            l = ichpky;
            if(ilit[j] < 1) goto S2150;

            /*
                       "PUT" literal or memory function

            */
            fillSa(imfunc,40,"  ");
            mvbyt(&lit[ilit[j]-1],imfunc,&lenlit[j]);

            memfun(imfunc,xc_cSmess,&K80,&irc);
            if(irc != 0) mvbyt(&lit[ilit[j]-1],xc_cSmess,&lenlit[j]);

            l = lenlit[j];
            if(l > ichpky) l = ichpky;       /* No longer than key field */

            msubSa(xc_cSmess,l,1,l,key,120,ist,ist+l-1);

            goto S2290;

S2150:

            l1 = lstcol[j]-istcol[j]+1;

            fill(xc_cSmess,&K40,"  ");
            msubSa(ln,10000,istcol[j],lstcol[j],xc_cSmess,80,1,l1);

            l2 = nlenSa(xc_cSmess,l1);

            if(l2 > l && l >= 8) goto S2152; /* Alias situation */
            if(l1 > l) l1 = l;               /* Not longer than field */
            l1 = l1-1;

            msubSa(ln,10000,istcol[j],istcol[j]+l1,key,120,ist,ist+l1);

            goto S2290;

S2152:

            /*
                       We must assign an alias if there is not already one
                       for this field value

            */
            aalias(xc_cSmess,&K80,&code,&irc);
            if(irc == 0) goto S2156;

            WRITE(OUTPUT,FMT,F2154,2,MORE);
            for(ii=0; ii==0 || ii<16; ii++)
            {
                WRITE(INT2,*(ifld+ii+j*16),MORE);
            }
            WRITE(DO,40,INT2,xc_cSmess,DO,1000,INT2,ln,0);

            setfer(&irc);
            stop();

S2156:

            errSp(&code,&K8,xc_cSmess,&K60);

            msubSa(&code,8,1,8,key,120,ist,ist+7);

            goto S2290;

S2160:

            fill(xc_cSmess,&K40,"  ");

            l = lstcol[j]-istcol[j]+1;
            msubSa(ln,10000,istcol[j],lstcol[j],xc_cSmess,80,1,l);

            dnumSc(xc_cSmess,&l,&dp,&irc);

            iform[0] = *(short*)fifstrgv("( ",2);
            mvbyt(&xfio_ikeyS[ifildx-1][i][17],&iform[1],&K20);
            iform[11] = *(short*)fifstrgv(") ",2);
            lenfor = 24;
            rmvblk(iform,&lenfor,&K0);

            WRITE(INTERNAL,xc_cSmess,ichpky,VFMT,iform,34,REAL8,dp,0);

            msubSa(xc_cSmess,80,1,ichpky,key,120,ist,ist+ichpky-1);

            goto S2290;

S2200:;
        }

        if(icompr(&xfio_ikeyS[ifildx-1][i][0],"*COID ",&K5) == 0) goto S2290;
        if(xfio_ikeyS[ifildx-1][i][28] == *(short*)fifstrgv("Y ",2)) goto S2290;

        WRITE(OUTPUT,FMT,F2220,1,MORE);
        for(k=0; k==0 || k<16; k++)
        {
            WRITE(INT2,xfio_ikeyS[ifildx-1][i][k],MORE);
        }
        WRITE(0);

        xlines_lines = xlines_lines+3;

        goto S9000;

S2290:

        ist = ist+ichpky;

    }

S2350:

    /*
         Now see if the record is on file

    */
    ioSf("FIND",itfile,&K28,itrtyp,key,&K0,&K0,&K0,&irc);
    if(irc != 0) goto S2600;

    if(iskp1 != *(short*)fifstrgv("X ",2)) goto S2510;

    iskp = iskp+1;

    goto S2100;

S2510:

    ioSf("DEL ",itfile,&K28,itrtyp,key,&K0,&K0,&K0,&irc);

    if(idel1 != *(short*)fifstrgv("X ",2)) goto S2515;

    if(irc == 0) idel = idel+1;

    goto S2100;

S2515:

    if(iupd1 != *(short*)fifstrgv("X ",2)) goto S2520;

    iupd = iupd+1;

    goto S2700;

S2520:

    if(irep1 != *(short*)fifstrgv("X ",2)) goto S2600;

    irep = irep+1;

    initSf(itfile,&K28,itrtyp,&irc);

    goto S2700;

S2600:

    if(iadd1 != *(short*)fifstrgv("X ",2)) goto S2650;

    iadd = iadd+1;

    goto S2700;

S2650:

    if(xlines_lines > 60) hdngSc(&K80,ititle,itext,&K240,&irc);

    WRITE(OUTPUT,FMT,F2660,1,DO,60,INT2,key,0);

    xlines_lines = xlines_lines+1;

    goto S2100;

S2700:

    /*
         Now put all the fields into the data record

    */
    for(i=0; i==0 || i<nfld; i++)
    {

        if(kord[i] == *(short*)fifstrgv("K ",2)) goto S3000;/* Skip key elements */

        fillSa(xc_cSmess,80,"  ");

        if(ilit[i] < 1) goto S2800;

        /*
             "PUT" literal or memory function

        */
        fillSa(imfunc,40,"  ");
        mvbyt(&lit[ilit[i]-1],imfunc,&lenlit[i]);

        memfun(imfunc,xc_cSmess,&K80,&irc);
        if(irc != 0) mvbyt(&lit[ilit[i]-1],xc_cSmess,&lenlit[i]);

        goto S2900;

S2800:

        if(istcol[i] < 1) goto S3000;

        l = ifdlen[i];                       /* Length of field as defined in FD */

        l1 = lstcol[i]-istcol[i]+1;

        msubSa(ln,10000,istcol[i],lstcol[i],xc_cSmess,80,1,l1);
        l1 = nlenSa(xc_cSmess,80);

        if(l < 8 || l >= l1) goto S2900;

        /*
             We must assign an alias if there is not already one
             for this field value

        */
        aalias(xc_cSmess,&l1,&code,&irc);
        if(irc == 0) goto S2870;

        WRITE(OUTPUT,FMT,F2860,2,MORE);
        for(ii=0; ii==0 || ii<16; ii++)
        {
            WRITE(INT2,*(ifld+ii+i*16),MORE);
        }
        WRITE(DO,40,INT2,xc_cSmess,DO,1000,INT2,ln,0);

        setfer(&irc);
        stop();

S2870:

        errSp(&code,&K8,xc_cSmess,&K60);

        fillSa(xc_cSmess,80,"  ");
        mvbyt(&code,xc_cSmess,&K8);

        goto S2900;

S2900:

        if(iupd1 == *(short*)fifstrgv("X ",2)) goto S2950;

        /*
             Except when doing update we want to avoid calling DATA$F when we
             have blank data so that numeric fields will remain in the state
             established by INIT$F.  Prior to this change for example a blank
             "RATE OF PAY" in PERSONNEL$DATA would become a 0 when we want it
             to remain blank.

        */
        if(nlenSa(xc_cSmess,80) < 1) goto S3000;

S2950:

        dataSf("PUT ",itfile,&K28,itrtyp,(ifld+0+i*16),&K32,xc_cSmess,&K80,&K0,&K0,&irc);

S3000:;
    }

    ioSf("ADD ",itfile,&K28,itrtyp,key,&K0,&K0,&K0,&irc);

    goto S2100;

S8600:

    if(nlenSa(itodir,80) < 1) goto S8800;

    mvbyt(ipath,xc_cSmess,&K80);

S8650:

    islash = ifindS("/ ",xc_cSmess,&K40);

    if(islash < 1) goto S8660;

    fillSa(xc_cSmess,islash,"  ");
    jstrSa(2,xc_cSmess,80);

    goto S8650;

S8660:

    n1 = nlenSa(itodir,80);
    n2 = nlenSa(xc_cSmess,80);
    n3 = n1+n2+2;

    if(n2 < 1) goto S8800;
    if(n1+n2 >= 80) goto S8800;

    mchrSa(itodir,n1+1,"/ ",1);
    msubSa(xc_cSmess,80,1,n2,itodir,80,n1+2,n3);

    cnamSc(ipath,&npath,itodir,&n3,&K0,&irc);
    if(irc == 0) goto S8680;

    errSc(&K10,&irc,"Trying to move the input file to the designated directory~",&K0,&ircx);

    goto S8800;

S8680:

    if(xlines_lines > 53) hdngSc(&K80,ititle,itext,&K240,&irc);

    WRITE(OUTPUT,FMT,F8690,1,DO,40,INT2,ipath,DO,40,INT2,itodir,0);

    xlines_lines = xlines_lines+3;

    outxml("S ","TO DIRECTORY FOR FROM FILE",&K26,&xlines_lines,&K0,&K1,&R2,&irc);

S8800:

    if(xlines_lines > 56) hdngSc(&K80,ititle,itext,&K240,&irc);

    WRITE(OUTPUT,FMT,F8820,2,INT4,icnt,INT4,iupd,INT4,irep,INT4,iskp,INT4,iadd,INT4,idel,0);

    T1 = xlines_lines+2;
    outxml("S ","LOAD STATISTICS",&K15,&T1,&K0,&K7,&R2,&irc);

S9000:

    stop();

    return;
#undef ifld
#undef istcol
#undef lstcol
#undef ilit
#undef lenlit
#undef lit
#undef iformi
#undef ln
}
/*
-----------------------------------------------------------------------

     RDS November 12, 2003 10:12:10    PRO

     Add "SA FILE LOAD INFO" and "SA FILE LOAD" to support loading of
     information into FD files (and tables).  These 2 selections
     provide an easier way to accomplish what "pt load-sq" does.

-----------------------------------------------------------------------

     RDS November 20, 2006 10:15:22    PRO/ACC

     Correct 3 problems not noticed in initial testing:

     1. The call to CNAM$C was missing the IATTCH argument.

     2. "A" type fields in the target file key were not being
        handled because the IKEY$(28,I,IFILDX) variable was
        not being tested properly.

     3. If "*COID" is supplied in the input file that value
        needs to be used instead of C$COID.

-----------------------------------------------------------------------

     RDS December 12, 2006 14:19:33    ACC-0185

     Changes to support alias values and memory functions (ie *TIMESTAMP, etc)
     when performing a "SA FILE LOAD" operation.

-----------------------------------------------------------------------

     RDS January 04, 2007 09:59:27    ACC

     Enhance "SA FILE LOAD" to support deletion of target file records.

-----------------------------------------------------------------------

     RDS January 04, 2008 17:15:45    PRO

     Add ",IRC" to the INIT$F call.  Prior to this change this
     report would crash when the "R"eplace option was requested.

-----------------------------------------------------------------------

     RDS January 27, 2009 12:55:42    PRO/DMN

     Except when doing update we want to avoid calling DATA$F when we
     have blank data so that numeric fields will remain in the state
     established by INIT$F.  Prior to this change for example a blank
     "RATE OF PAY" in PERSONNEL$DATA would become a 0 when we want it
     remain blank.

-----------------------------------------------------------------------

     RDS January 21, 2010 14:15:58    PRO

     Add OUTXML calls in order to produce a complete OUT___.xml file.

-----------------------------------------------------------------------

     RDS June 07, 2010 13:46:21    LVI-0082

     Change OUT###.xml to detail the output by "field" within "section".

-----------------------------------------------------------------------

     RDS November 10, 2010 13:27:41    PRO/SWE

     Minor changes to accomplish pushing blanks to any desired field
     including *COID.  You can do it by specifying a location in the
     input file that will always be blank or you can do it by
     quoting a literal.  For example '    ' or "    " as the literal
     for *COID would accomplish using blank for the company ID field.

     This will also allow plugging a literal that you want stored
     without it being left justified.  For example if I wanted to
     store blank blank BLUE in a field i could do it using the literal
     "  BLUE".

-----------------------------------------------------------------------

     RDS June 19, 2013 08:34:13    ACC-0000

     The "SA FILE LOAD" report can currently read records as long as 1000 characters.
     This enhancement changes that limit to 10,000 characters. ACCO has some rather
     huge spreadsheets which they trun into sequential files and then use to load
     various FD files. This should do them for a while.

     References ticket:72

*/
