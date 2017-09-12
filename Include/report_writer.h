/*
-----------------------------------------------------------------------
     RDS 09/03/85

     This insert file contains the definition and description of all 'R
     WRITER' specific variables.

*/
#ifndef ICF_report_writer
#define ICF_report_writer
#define MAXITM      300                      /* Maximum number of items for a repor */
#define MAXST       300                      /* Maximum number of standard items */
#define MAXLEV      20                       /* Maximum number of levels */
#define MAXCND      200                      /* Maximum number of condition lines */
#define MAXBRK      100                      /* Maximum number of break values */
#define MAXCOL      500                      /* Maximum number of columns on output */
#define MXCOLS      1000
#define MAXROW      132                      /* Maximum number of row (lines) on ou */
#define MAXKEY      100                      /* Maximum size of key stored by DATA$ */

 short xrptwtr_marray[14];                   /* MIDAS array */
 short xrptwtr_ifile[12];                    /* Temporary MIDAS file name 'RW$DATA.LFDn */
 short xrptwtr_ichars[96];                   /* ASCII printable character set (right ch */

 short xrptwtr_irepnm[10];                   /* Report name */
 short xrptwtr_irwbb;                        /* First 2 chars of filename to be used by */
 double xrptwtr_dater;                       /* Report date */
 double xrptwtr_datep;                       /* Period date */
 double xrptwtr_dateb;                       /* Begin date */
 short xrptwtr_itemin[16];                   /* Temporary item name */
 short xrptwtr_icats[100];                   /* List of categories in B'##' format */

 short xrptwtr_iuselk;                       /* Use LKEY for BB field lookup - 'Y' or ' */
 short xrptwtr_keys[MAXLEV][MAXKEY];         /* Primary keys for RW$DATA */
 short xrptwtr_key[MAXKEY];                  /* Key for RW$DATA */
 short xrptwtr_keynxt[MAXKEY];               /* Next key for RW$DATA in 'GENSUP' */
 short xrptwtr_lkey[MAXKEY];                 /* Last KEY */
 double xrptwtr_data[MAXITM];                /* Data buffer for RW$DATA */
 double xrptwtr_datnxt[MAXITM];              /* Next data buffer from RW$DATA in 'GENSU */
 short xrptwtr_keywrd;                       /* Length of key to RW$DATA.lfd file in wo */
 short xrptwtr_keybyt;                       /* Length of key to RW$DATA.lfd file in by */
 double xrptwtr_datein;                      /* Effective date of record from input dat */

 short xrptwtr_item[MAXITM][16];             /* List of items used in current report */
 short xrptwtr_itmbit[MAXITM];               /* 16 on/off bit settings for each ITEM */
/*
                                1  on  - output ITMCHR when 0 or blank
                                2  on  - This is a date calculation
                                3  on  - This item's name starts with '
                                4  on  - Float ( ) around this numeric
                                         instead of '-'
                                5  on  - All items output with formats
                                         include ',' or '.' French it
                                6  on  - A 0 posted for a FIO field
*/
 short xrptwtr_itmchr[MAXITM];               /* Character to fill field with if value i */
 short xrptwtr_itmst[MAXITM];                /* Index into standard item list for repor */
 short xrptwtr_iexno[MAXITM];                /* Exception number that applies or 0 */
 short xrptwtr_nleitm;                       /* Last LEVEL item number (index into ITEM */
 short xrptwtr_idaitm;                       /* First DATA item number         " */
 short xrptwtr_icnitm;
 short xrptwtr_ndaitm;                       /* Last DATA item number          " */
 short xrptwtr_icaitm;                       /* First calculated item number   " */
 short xrptwtr_ncaitm;                       /* Last calculated item number    " */
 short xrptwtr_iloitm;                       /* First level output item number " */
 short xrptwtr_nloitm;                       /* Last level output item number  " */
 short xrptwtr_ideitm;                       /* First description item number  " */
 short xrptwtr_ndeitm;                       /* Last description item number   " */
 short xrptwtr_islitm;                       /* First, for selection only, item number */
 short xrptwtr_nslitm;                       /* Last, for selection only, item number */
 short xrptwtr_iclitm;
 short xrptwtr_nclitm;
 short xrptwtr_nda;                          /* Largest of NDAITM, NCAITM, NCNITM */
 short xrptwtr_nall;                         /* Last item number, no matter which kind */
 short xrptwtr_ntcalc;                       /* Number of columns to calculate totals f */
 short xrptwtr_nbb;                          /* Number of black boards to output */

 short xrptwtr_ilevnm[16];                   /* Name of level (or break name) currently */
 short xrptwtr_level[MAXLEV][10];            /* Holds level info for each LEVEL item */
 short xrptwtr_lvlbit[MAXLEV];               /* 16 on/off bit settings for each LEVEL i */
/*
                                1  on  - Blank is a valid value for thi
                                2  on  - Process records even when all
                                         items are zero
                                3  on  - Suppress output at this level.
                                         to totals only.
                                4  on  - Reverse sort on this level.
                                5  on  - Do not output if all reported
                                         items are zero
                                6  on  - Squeeze out blank lines of out
*/
 short xrptwtr_keypos[MAXLEV][MAXLEV];       /* Maintains position of item in each key */
 short xrptwtr_istore[MAXITM];               /* Index into DATA for data items */
 short xrptwtr_nogl;                         /* Number of entries in GLACCT (see GJ$D$W */
 short xrptwtr_icum;                         /* 'Y' or 'N' --- is noncumulative data pr */
 short xrptwtr_noncum[MAXITM];               /* 1 - noncumulative, 0 - default */
 short xrptwtr_itotlv[MAXITM];               /* Total level at which an item exists */
 short xrptwtr_iatlvl[MAXITM];               /* Level at which an item exists */
 short xrptwtr_idsize[MAXLEV];               /* Size of data in words for Ith key */
 short xrptwtr_isect[MAXITM];                /* Section that this item is in */
 short xrptwtr_itmrow[MAXITM];               /* Output starting row for output item */
 short xrptwtr_itmcol[MAXITM];               /* Output starting column for output item */
 short xrptwtr_nrow;                         /* Number of rows to output for this recor */
 short xrptwtr_ialtfm[MAXITM][11];           /* Alternate format (If blank,overwritten */
 short xrptwtr_icalc1[MAXITM];               /* Index into ITEM of calculation item 1 */
 short xrptwtr_icalc2[MAXITM];               /* Index into ITEM of calculation item 2 */
 short xrptwtr_ioper[MAXITM];                /* Operator (item1 IOPER item2) */
 double xrptwtr_Const[MAXITM];               /* Constant (in leau of item1 or item2) */
 short xrptwtr_ibb[20];                      /* Index to each BB item to be output */
 short xrptwtr_ibbfmt[20][4];                /* From col, To col, From row, To row */
 short xrptwtr_iaddlv[MAXITM];               /* Additive_thru LEVEL for DATA items */

 short xrptwtr_nexitm;                       /* Number of exception items */
 short xrptwtr_minex[300][8];                /* Minimum value of exception */
 short xrptwtr_maxex[300][8];                /* Maximum value of exception */
 double xrptwtr_dminex[300];                 /* Minimum value (stored as REAL*8) */
 double xrptwtr_dmaxex[300];                 /* Maximum value (stored as REAL*8) */
 short xrptwtr_iexnxt[300];                  /* Next exception for same item or 0 */
 short xrptwtr_iextyp[300];                  /* Exception type, I for include or O for */
 short xrptwtr_iexao[300];                   /* Exception method, A for 'and' or O for */
 short xrptwtr_iiand;                        /* Include all 'ands' 0, Y, or N */
 short xrptwtr_ioand;                        /* Omit all 'ands'    0, Y, or N */
 short xrptwtr_iior;                         /* Include 'ors'      0, Y, or N */

 short xrptwtr_irvsrt;                       /* Any reverse sort fields (Y or N) */
 short xrptwtr_itlout;                       /* Item(s) to consider at total time */

 short xrptwtr_nstitm;                       /* Number of standard items */
 short xrptwtr_isthrd;                       /* First hard coded standard item (from RE */
 short xrptwtr_istitm[MAXST][16];            /* List of standard items (REPORT.WRITER.I */
 short xrptwtr_isttyp[MAXST];                /* Type of item ('LE','DA','DE') */
 short xrptwtr_istlen[MAXST];                /* Length of standard item */
 short xrptwtr_istfmt[MAXST][10];            /* Default FORMAT for the standard item */

 short xrptwtr_nalitm;                       /* Number of Alias names in use */
 short xrptwtr_ialnam[20][16];               /* The Alais names that are in use */
 short xrptwtr_ialitm[20];                   /* The Standard item number of the Alias f */
 short xrptwtr_ialfil[20];                   /* The FD file (IFILES) that have alias(s) */

 short xrptwtr_ifdfil[MAXST];                /* Number of FD file from which this item */

 short xrptwtr_ikyuse[MAXLEV];               /* Used to update KEYUSE between records */
 short xrptwtr_keyuse[MAXLEV];               /* Shows which key(s) to post for a record */
 short xrptwtr_ktmplt[MAXLEV][MAXKEY];       /* Key templates (hierarchy numbers only) */

 short xrptwtr_iskrec;                       /* Current record has been excluded if = ' */

 short xrptwtr_icndlf;                       /* Conditional line feed (Y or N) */

 short xrptwtr_idcnt;                        /* Number of dump sets (index for IDSUB) */
 short xrptwtr_idsub[34][6];                 /* Indicates where and what to DUMP$W */
/*
                                should do.  One row per subroutine as f
                                 (1,J) - dump at start of routine (Y or
                                 (2,J) - dump at end of routine (Y or N
                                 (3,J) - how often (integer count 1-10,
                                 (4,J) - maximum number of dumps (1-100
                                 (5,J) - which display(s) to dump (bits
                                 (6,J) - count to compare to (3,J)

*/
 short xrptwtr_keyjd[23];                    /* Primary key for JOB$DATA */
 double xrptwtr_datajd[6];                   /* Data buffer for JOB$DATA */

 short xrptwtr_keyje[22];                    /* Primary key for JOB$ESTIMATE */
 short xrptwtr_keyld[14];                    /* Primary key for LEDGER$DATA */

 double xrptwtr_datard[503];                 /* Data buffer for record from input data */

 short xrptwtr_job;                          /* JOB  Index into ITEM or 0 if not in rep */
 short xrptwtr_iph;                          /* PHASE                   " */
 short xrptwtr_iact;                         /* ACTIVITY                " */
 short xrptwtr_ichno;                        /* CHANGE#                 " */
 short xrptwtr_icat;                         /* CATEGORY                " */
 short xrptwtr_icls;                         /* CLASS                   " */
 short xrptwtr_ivnd;                         /* VENDOR                  " */
 short xrptwtr_ipuo;                         /* PURCHASE ORDER          " */
 short xrptwtr_icho;                         /* CHANGE ORDER            " */
 short xrptwtr_lni;                          /* LINE ITEM               " */
 short xrptwtr_iconid;                       /* CONTRACT ID NUMBER      " */
 short xrptwtr_iaccnt;                       /* ACCOUNT NUMBER          " */
 short xrptwtr_idocu;                        /* DOCUMENT NUMBER (SEE COMMITMENT$MASTER. */
 short xrptwtr_iqteff;                       /* QUARTER EFFECTIVE (SEE PAYROLL$HISTORY. */
 short xrptwtr_iperdt;                       /* DATE PAYROLL PERIOD           " */
 short xrptwtr_icknum;                       /* CHECK NUMBER                  " */
 short xrptwtr_iprtyp;                       /* PAYROLL TYPE                  " */
 short xrptwtr_iemp;                         /* EMPLOYEE NUMBER               " */
 short xrptwtr_ibatch;                       /* BATCH                         " */
 short xrptwtr_iphset;                       /* PH SET                        " */
 short xrptwtr_iphkey;                       /* PH KEY                        " */
 short xrptwtr_iphpcd;                       /* PH PAY CODE */
 short xrptwtr_ifbdsc;

 short xrptwtr_icost;                        /* COST                    " */
 short xrptwtr_irev;                         /* REV                     " */
 short xrptwtr_irtnp;                        /* RTN-PAY                 " */
 short xrptwtr_ipay;                         /* PAYABLE                 " */
 short xrptwtr_irtnr;
 short xrptwtr_irec;                         /* RECEIVABLE              " */
 short xrptwtr_iqtyp;                        /* QTY-%                   " */
 short xrptwtr_iqtyu;                        /* QTY-UNIT                " */
 short xrptwtr_iqcp;                         /* QTYCAT-%                " */
 short xrptwtr_iqcu;                         /* QTYCAT-UNIT             " */

 short xrptwtr_icostp;                       /* P:COST                  " */
 short xrptwtr_irevp;                        /* P:REV                   " */
 short xrptwtr_irtnpp;                       /* P:RTN-PAY               " */
 short xrptwtr_ipayp;
 short xrptwtr_irtnrp;                       /* P:RTN-REC               " */
 short xrptwtr_irecp;                        /* P:RECEIVABLE            " */
 short xrptwtr_iqtypp;                       /* P:QTY-%                 " */
 short xrptwtr_iqtyup;                       /* P:QTY-UNIT              " */
 short xrptwtr_iqcpp;                        /* P:QTYCAT-%              " */
 short xrptwtr_iqcup;                        /* P:QTYCAT-UNIT              " */
 short xrptwtr_ihrsl;                        /* HOURS-L                 " */
 short xrptwtr_ihrslp;                       /* P:HOURS-L               " */
 short xrptwtr_ihrse;                        /* HOURS-E                 " */
 short xrptwtr_ihrsep;                       /* P:HOURS-E               " */
 short xrptwtr_iccst;                        /* COST-COM                " */
 short xrptwtr_iccstp;                       /* P:COST-COM              " */
 short xrptwtr_icrev;                        /* REV-COM                 " */
 short xrptwtr_icrevp;                       /* P:REV-COM               " */
 short xrptwtr_icst;                         /* COST ST                 " */
 short xrptwtr_icot;                         /* COST OT                 " */
 short xrptwtr_icdt;                         /* COST DT                 " */
 short xrptwtr_ihst;                         /* HOURS-L ST              " */
 short xrptwtr_ihot;                         /* HOURS-L OT              " */
 short xrptwtr_ihdt;                         /* HOURS-L DT              " */
 short xrptwtr_icstp;                        /* P:COST ST               " */
 short xrptwtr_icotp;                        /* P:COST OT               " */
 short xrptwtr_icdtp;                        /* P:COST DT               " */
 short xrptwtr_ihstp;                        /* P:HOURS-L ST            " */
 short xrptwtr_ihotp;                        /* P:HOURS-L OT            " */
 short xrptwtr_ihdtp;                        /* P:HOURS-L DT            " */

 short xrptwtr_ipqtp;                        /* PAY QTY-%               " */
 short xrptwtr_ipqtu;                        /* PAY QTY-UNIT            " */
 short xrptwtr_ipqtpp;                       /* P:PAY QTY-%             " */
 short xrptwtr_ipqtup;                       /* P:PAY QTY-UNIT          " */
 short xrptwtr_iestq[27][5];                 /* ESTQ-xx                 " */
 short xrptwtr_ieqc[27][5];                  /* ESTQCAT-xx              " */
 short xrptwtr_iestc[27][5];                 /* ESTC-xx                 " */
 short xrptwtr_iesth[27][5];                 /* ESTH-xx                 " */
 short xrptwtr_iestr[27][5];                 /* ESTR-xx                 " */

 short xrptwtr_iestqp[27][5];                /* P:ESTQ-xx               " */
 short xrptwtr_ieqcp[27][5];                 /* P:ESTQCAT-xx            " */
 short xrptwtr_iestcp[27][5];                /* P:ESTC-xx               " */
 short xrptwtr_iesthp[27][5];                /* P:ESTH-xx               " */
 short xrptwtr_iestrp[27][5];                /* P:ESTR-xx               " */
 short xrptwtr_memon;                        /* Standard item# of MEMO or 0 if not in u */

 short xrptwtr_ieffdt;                       /* DATE                    " */

 short xrptwtr_icom[5][3];                   /* Data items from COMMITMENT$MASTER file */
/*
                                COM C         (contract)
                                    S         (subcontract)
                                    P         (purchase order)
                                      AMOUNT
                                      CHANGE
                                      BILLED
                                      RETAIN
                                      PAID
*/
 short xrptwtr_icomp[5][3];                  /* Same as ICOM for period (P:) */

 short xrptwtr_lamt;                         /* LEDGER AMOUNT */
 short xrptwtr_lamtp;                        /* P:LEDGER AMOUNT */

 short xrptwtr_iphamt;                       /* PH AMOUNT */
 short xrptwtr_ippham;                       /* P:PH AMOUNT */
 short xrptwtr_iphq1;                        /* PH Q1 */
 short xrptwtr_iphq2;                        /* PH Q2 */
 short xrptwtr_iphq3;                        /* PH Q3 */
 short xrptwtr_iphq4;                        /* PH Q4 */
 short xrptwtr_iphq5;                        /* PH Q5 */
 short xrptwtr_iphq6;                        /* PH Q6 */
 short xrptwtr_iphq7;                        /* PH Q7 */
 short xrptwtr_iphq8;                        /* PH Q8 */

 short xrptwtr_ifdfld;                       /* Go against FIELD.FD. file in ISTNO ('Y' */

 short xrptwtr_keyfld[32];                   /* KEY to the FIELD.FD. file */
 short xrptwtr_idfld[99];                    /* Data buffer for the FIELD.FD. file */
 short xrptwtr_ifiles[50][16];               /* List of FIO files that report ITEM(s) a */
 short xrptwtr_ifilky[50];                   /* MIDAS index number to use in F$IO$W */
 short xrptwtr_nfiles;                       /* Number of filenames in IFILES */
 short xrptwtr_iflord[60];                   /* Order in which to process the data file */
 short xrptwtr_iaddfl[50][9];                /* Index to from 1 to 9 additional files */
 short xrptwtr_naddfl;                       /* Number past NFILES of additional only f */
 short xrptwtr_ifdfl;                        /* Number of .FD. file, set on last call t */
 short xrptwtr_iriplw;                       /* We will be plowing thru REPORT$INFO (Y */

 short xrptwtr_ilevel;                       /* Level of current RW$DATA record (from K */
 short xrptwtr_llevel;                       /* Level of last RW$DATA record (from LKEY */
 short xrptwtr_line[MAXROW][MAXCOL];         /* Output area for the current RW$DATA.lfd */
 short xrptwtr_ifc[MAXLEV][2];               /* Form contro by level 'L','T','P' */
 short xrptwtr_ifccnt[MAXLEV][2];            /* Number of lines or pages for form contr */
 short xrptwtr_itfc[MAXLEV][2];              /* Same as IFC for total lines */
 short xrptwtr_itfcnt[MAXLEV][2];            /* Same as IFCCNT for total lines */
 short xrptwtr_lastrw[MAXLEV];               /* Last row that has output for each level */
 short xrptwtr_ifstrw;                       /* First row of detail output on a page */
 short xrptwtr_ilstrw;                       /* Last row of detail output on a page */
 short xrptwtr_newlev[MAXLEV];               /* Value of level item has changed 'Y' or */
 short xrptwtr_iprtot[MAXITM][3];            /* 1 bit - Print the total  0 bit - Don't */
 double xrptwtr_total[MAXITM][MAXLEV];       /* Maintain totals by (level,data item) */
 short xrptwtr_ntotal[MAXLEV];               /* Number of lines in a total */
 short xrptwtr_itmcal[100];                  /* List of column items to calculate total */
 short xrptwtr_icallv[100];                  /* Calculate at this total level (for ITMC */
/*
                                Value of 0 means for all total levels
*/
 short xrptwtr_lvrcap;                       /* Level to output recap accumulators */
 short xrptwtr_lvrset;                       /* Level at which to clear recap accumulat */
 short xrptwtr_nbrk;                         /* Number of break items */
 short xrptwtr_ibrk[MAXBRK];                 /* ITEMNO of level item to check for break */
 short xrptwtr_ibrkv[MAXBRK][8];             /* Value to break on */
 short xrptwtr_ibrknm[MAXBRK][16];           /* Break description */
 short xrptwtr_ibrkno[MAXLEV];               /* Number of break that has occurred */
 short xrptwtr_nambrk[4];                    /* Name of break list to use */
 short xrptwtr_nsubf;                        /* Number of subdivided level items */
 short xrptwtr_istsub[30];                   /* Standard item number of a subdivided it */
 short xrptwtr_itmsub[30];                   /* First partial level item */
 short xrptwtr_ivcshr;                       /* Share V/C$INFO file...  'Y' or not 'N' */
 short xrptwtr_iriblk;                       /* Use blank COID against REPORT$INFO ('Y' */
 short xrptwtr_iprzro;                       /* Print zeroes ('Y' or 'N') */
 short xrptwtr_iddreq;                       /* DATA DEFINE required ('Y' or 'N') */
 short xrptwtr_icform;                       /* CONTINUOUS FORM ('Y' or 'N') */
 short xrptwtr_lpgbb[18];                    /* Name of last page BB */
 short xrptwtr_iovrly;                       /* Check for data overlay condition (Y or */
 short xrptwtr_lstwrd;                       /* Last word of COMMON block RPTWTR (used */

/*
     RW1087 Variable definitions

*/
 short xrptwtr_iflono[100];                  /* Ordered list of floating items */
 short xrptwtr_iflops[100];                  /* FLOAT Position */
 short xrptwtr_nfloat;                       /* Number of float items */

 unsigned short xrptwtr_nswcat[69];          /* Categories in use (Used by GJ$D$W & GJ$ */
 short xrptwtr_ninit;                        /* Number of INITIAL_ITEMs in ITINIT and V */
 short xrptwtr_itinit[50][16];               /* Name of each INITIAL_ITEM */
 double xrptwtr_vlinit[50];                  /* Value of each INITIAL_ITEM */
 short xrptwtr_initty[50];                   /* Type of each INITIAL_ITEM, 'DA'ys or 'M */
 short xrptwtr_ncumst[MAXST];                /* Cumlative or not (0 or 1) */
 short xrptwtr_nflsep;                       /* Number of Float separator characters */
 short xrptwtr_iflsep[20];                   /* The Floating field separator string */
 short xrptwtr_itlcnt;                       /* Number of detail lines required before */
 short xrptwtr_itnocn[MAXCND];               /* Item number for which a condition is to */
 short xrptwtr_icdata[MAXCND][16];           /* Data to test condition on (only when as */
 short xrptwtr_mincn[MAXCND][16];            /* ASCII minimum value */
 short xrptwtr_maxcn[MAXCND][16];            /* ASCII maximum value */
 double xrptwtr_dmincn[MAXCND];              /* DOUBLE PRECISION minimum value */
 double xrptwtr_dmaxcn[MAXCND];              /* DOUBLE PRECISION maximum value */
 short xrptwtr_ncnitm;                       /* Number of condition sets */
 short xrptwtr_irwid[2];                     /* Company ID to use if local ID recs not */
/*
                                See SYS GENL INFO  'RW COID FOR dfd' pa
*/
 short xrptwtr_nclass;                       /* Used by BLDT$W, BLDO$W, and GFDDE */
 int xrptwtr_irwcnt;                         /* Number of records read from a source fi */
 int xrptwtr_nrwcnt;                         /* When IRWCNT is a multiple check for ! o */
 short xrptwtr_iphex;                        /* 'Y' means - 1 Include criteria exists f */
 short xrptwtr_iphmin;                       /* Minimum Phase value */
 short xrptwtr_iphmax;                       /* Maximum Phase value */
 short xrptwtr_iscrw;                        /* First row for detail output on Inquiry */
 short xrptwtr_icmdrw;                       /* Last BB row before commands (REFORMAT - */
 short xrptwtr_iovrde[MAXITM];               /* Standard item number to use for overrid */
 short xrptwtr_ifclct[50];                   /* (Y or N) when DATA_DEFINE has COLLECT Y */
 short xrptwtr_iallst[50];                   /* (Y or N) when DATA_DEFINE has ALL SETS */
 unsigned short xrptwtr_rwpush;              /* .TRUE. means Data pushing will occur */
 short xrptwtr_irqscn[8];                    /* Name of the request screen */
 short xrptwtr_nreps;                        /* Number of additional reports in a reque */
 double xrptwtr_datal[1000];                 /* Last data record from RW$DATA.LFDname */
 short xrptwtr_memde[4000];                  /* 'DE' items are put here by PUTI$W */
 short xrptwtr_nextde;                       /* Next avaiable location in MEMDE */
 short xrptwtr_imemde[MAXITM];               /* Index into MEMDE for each 'DE' item */
 short xrptwtr_idesiz[MAXLEV];               /* Size of the 'DE' record by level */
 unsigned short xrptwtr_stored;              /* Store 'DE'scriptive items (.TRUE. or .F */
 short xrptwtr_istord;                       /* "Y", "N", OR " " as specified in OPTION */
 short xrptwtr_mincit[MAXCND];               /* Item number suppling CONDITION min valu */
 short xrptwtr_maxcit[MAXCND];               /* Item number suppling CONDITION max valu */
 short xrptwtr_nxest[300];                   /* Array used by PUTI$W for combo EST item */
 short xrptwtr_nxesti;                       /* Pointer to current NXEST position */
 unsigned short xrptwtr_setest;              /* When .TRUE. ITEMNO will establish NXEST */

 short xrptwtr_iconvr;                       /* When = 'C ' we are doing a "RW REFORMAT */
 short xrptwtr_ipdshr;                       /* Share PERSONNEL$DATA file...  'Y' or no */

 unsigned short xrptwtr_abort;               /* When .FALSE. we will not Abort */

 short xrptwtr_ivh;                          /* VAC HOURS */
 short xrptwtr_ivhw;                         /* VAC HOURS WORKED */
 short xrptwtr_ivhe;                         /* VAC HOURS EARNED */
 short xrptwtr_ivr;                          /* VAC RATE */
 short xrptwtr_ivwn;                         /* VAC WEEK NUMBER */
 short xrptwtr_iveyn;                        /* VAC EMPLOYEE YEAR NUMBER */

 short xrptwtr_mwidrw;                       /* Width of the report output up to 1000 */

 unsigned short xrptwtr_nosort;              /* Avoid the sort/merge into temp file */

 short xrptwtr_iiishr;                       /* Share INSURANCE$INFO file...  'Y' or no */

 short xrptwtr_idatoe;                       /* DATE ORIGINAL ESTIMATE item pointer */

 short xrptwtr_ioutcn;                       /* Pointer to item "OUTPUT LINE COUNT" */
 int xrptwtr_outcnt;                         /* Count of output lines (permanently defi */

 short xrptwtr_iskipd;                       /* Indicates when it is safe to skip to ne */
 short xrptwtr_irwdum[194];                  /* Space to allow adding to COMMON on the */
 short xrptwtr_irwrev;                       /* Report Revision */

 short xrptwtr_icnist[MAXITM];               /* Index to first condition */
 short xrptwtr_icnlst[MAXITM];               /* Index to last condition */

 short xrptwtr_istch[MAXLEV];                /* 1st char of level data to store */
 short xrptwtr_lstch[MAXLEV];                /* last char of level data to store */
 short xrptwtr_nxtsub[MAXLEV];               /* Next sub-field level item to conside */
 short xrptwtr_nxtitm[MAXITM];               /* Next 'DA' item (occurs at multiple l */
 short xrptwtr_lconst[MAXITM][16];           /* Literal constant */
 short xrptwtr_liton[MAXITM];                /* 'Y' - print literal, 'N' don't print */
 short xrptwtr_icllen[MAXITM];               /* Length of string to compare (conditi */
 short xrptwtr_iclist[MAXITM];               /* Index to literal condition item one */
 short xrptwtr_icllst[MAXITM];               /* Index to literal condition item two */
 short xrptwtr_itcntl[800];                  /* For capturing TOTAL CONTROL in GDIT$ */
 short xrptwtr_memdel[4000];                 /* 'DE' items are captured here */
/*
                                1 - from REPORT$INFO
                                2 - from BB effective 12/23/88

*/
 short xrptwtr_idirs[50][3];

 short xlines_lines;
 short xlines_npage;
#endif /*ICF_report_writer */
