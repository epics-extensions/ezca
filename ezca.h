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

epicsShareFunc int epicsShareAPI ezcaEndGroup();
epicsShareFunc int epicsShareAPI ezcaEndGroupWithReport(int **rcs, int *nrcs);
epicsShareFunc int epicsShareAPI ezcaGetErrorString(char *prefix, char **buff);
epicsShareFunc int epicsShareAPI ezcaNewMonitorValue(char *pvname, 
	char ezcatype); /* returns TRUE/FALSE */
epicsShareFunc void epicsShareAPI ezcaPerror(char *prefix);

/* Non-Groupable Work Functions */

epicsShareFunc void epicsShareAPI ezcaAutoErrorMessageOff();
epicsShareFunc void epicsShareAPI ezcaAutoErrorMessageOn();
epicsShareFunc int epicsShareAPI ezcaClearMonitor(char *pvname, char ezcatype);
epicsShareFunc void epicsShareAPI ezcaDebugOff();
epicsShareFunc void epicsShareAPI ezcaDebugOn();
epicsShareFunc int epicsShareAPI ezcaDelay(float sec);
epicsShareFunc void epicsShareAPI ezcaFree(void *buff);
epicsShareFunc int epicsShareAPI ezcaGetRetryCount();
epicsShareFunc float epicsShareAPI ezcaGetTimeout();
epicsShareFunc int epicsShareAPI ezcaPvToChid(char *pvname, chid **cid);
epicsShareFunc int epicsShareAPI ezcaSetMonitor(char *pvname, char ezcatype);
epicsShareFunc int epicsShareAPI ezcaSetRetryCount(int retry);
epicsShareFunc int epicsShareAPI ezcaSetTimeout(float sec);
epicsShareFunc int epicsShareAPI ezcaStartGroup();
epicsShareFunc void epicsShareAPI ezcaTraceOff();
epicsShareFunc void epicsShareAPI ezcaTraceOn();

/* Groupable Work Functions */

epicsShareFunc int epicsShareAPI ezcaGet(char *pvname, char ezcatype, 
	int nelem, void *data_buff);
epicsShareFunc int epicsShareAPI ezcaGetControlLimits(char *pvname, 
	double *low, double *high);
epicsShareFunc int epicsShareAPI ezcaGetGraphicLimits(char *pvname, 
	double *low, double *high);
epicsShareFunc int epicsShareAPI ezcaGetNelem(char *pvname, int *nelem);
epicsShareFunc int epicsShareAPI ezcaGetPrecision(char *pvname, 
	short *precision);
epicsShareFunc int epicsShareAPI ezcaGetStatus(char *pvname, 
	TS_STAMP *timestamp, short *status, short *severity);
epicsShareFunc int epicsShareAPI ezcaGetUnits(char *pvname, 
	char *units); /* units must be at least	EZCA_UNITS_SIZE large */
epicsShareFunc int epicsShareAPI ezcaGetWithStatus(char *pvname, 
	char ezcatype, int nelem, void *data_buff, TS_STAMP *timestamp, 
	short *status, short *severity);
epicsShareFunc int epicsShareAPI ezcaPut(char *pvname, char ezcatype, 
	int nelem, void *data_buff);
epicsShareFunc int epicsShareAPI ezcaPutOldCa(char *pvname, char ezcatype, 
	int nelem, void *data_buff);

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
