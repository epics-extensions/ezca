/*****************************************************************/
/*                                                               */
/* for backward compatability.  users who compile with -DOLDCA   */
/* will have all their ezcaPut() calls automatically turned into */
/* calls to ezcaPutOldCa() which uses ca_put() (no callback).    */
/*                                                               */
/* this was necessary because ca_array_put_callback() did not    */
/* appear in CA until EPICS 3.11.6.  using ezca to put values    */
/* onto IOCs booted with versions prior to 3.11.6 will not work  */
/* unless the user defines OLDCA on the compile line.            */
/*                                                               */
/* on the other hand, defining OLDCA turns ALL calls to ezcaPut  */
/* to ca_put() (no notification).                                */
/*                                                               */
/*****************************************************************/

#ifdef OLDCA
#define ezcaPut ezcaPutOldCa
#else
#define ezcaPut ezcaPut
#endif

/* Immediate Functions ... do not affect error message */

int ezcaEndGroup();
int ezcaEndGroupWithReport(int **rcs, int *nrcs);
int ezcaGetErrorString(char *prefix, char **buff);
int ezcaNewMonitorValue(char *pvname, char ezcatype); /* returns TRUE/FALSE */
void ezcaPerror(char *prefix);

/* Non-Groupable Work Functions */

void ezcaAutoErrorMessageOff();
void ezcaAutoErrorMessageOn();
int ezcaClearMonitor(char *pvname, char ezcatype);
void ezcaDebugOff();
void ezcaDebugOn();
int ezcaDelay(float sec);
void ezcaFree(void *buff);
int ezcaGetRetryCount();
float ezcaGetTimeout();
int ezcaPvToChid(char *pvname, chid **cid);
int ezcaSetMonitor(char *pvname, char ezcatype);
int ezcaSetRetryCount(int retry);
int ezcaSetTimeout(float sec);
int ezcaStartGroup();
void ezcaTraceOff();
void ezcaTraceOn();

/* Groupable Work Functions */

int ezcaGet(char *pvname, char ezcatype, int nelem, void *data_buff);
int ezcaGetControlLimits(char *pvname, double *low, double *high);
int ezcaGetGraphicLimits(char *pvname, double *low, double *high);
int ezcaGetNelem(char *pvname, int *nelem);
int ezcaGetPrecision(char *pvname, short *precision);
int ezcaGetStatus(char *pvname, TS_STAMP *timestamp, 
    short *status, short *severity);
int ezcaGetUnits(char *pvname, char *units); /* units must be at least */
					     /*  EZCA_UNITS_SIZE large */
int ezcaGetWithStatus(char *pvname, char ezcatype, int nelem, void *data_buff, 
	TS_STAMP *timestamp, short *status, short *severity);
int ezcaPut(char *pvname, char ezcatype, int nelem, void *data_buff);
int ezcaPutOldCa(char *pvname, char ezcatype, int nelem, void *data_buff);

/* must match size of char units[] in dbr_gr_xxxx */
/* and dbr_ctrl_xxxx structs in db_access.h       */
#define EZCA_UNITS_SIZE 8

/* Data Types */
#define ezcaByte   0
#define ezcaString 1
#define ezcaShort  2
#define ezcaLong   3
#define ezcaFloat  4
#define ezcaDouble 5
#define VALID_EZCA_DATA_TYPE(X) (((X) >= 0)&&((X)<=(ezcaDouble)))

/* Return Codes */
#define EZCA_OK                0
#define EZCA_INVALIDARG        1
#define EZCA_FAILEDMALLOC      2
#define EZCA_CAFAILURE         3
#define EZCA_UDFREQ            4
#define EZCA_NOTCONNECTED      5
#define EZCA_NOTIMELYRESPONSE  6
#define EZCA_INGROUP           7
#define EZCA_NOTINGROUP        8
