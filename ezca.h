/* Immediate Functions ... do not affect error message */

int ezcaEndGroup();
int ezcaGetErrorString(char *, char **);
int ezcaNewMonitorValue(char *, char); /* returns TRUE or FALSE */
void ezcaPerror(char *);

/* Non-Groupable Work Functions */

void ezcaAutoErrorMessageOff();
void ezcaAutoErrorMessageOn();
int ezcaClearMonitor(char *, char);
void ezcaDebugOff();
void ezcaDebugOn();
int ezcaDelay(float);
void ezcaFreeErrorString(char *);
int ezcaGetRetryCount();
float ezcaGetTimeout();
int ezcaPvToChid(char *, chid **);
int ezcaSetMonitor(char *, char);
int ezcaSetRetryCount(int);
int ezcaSetTimeout(float);
int ezcaStartGroup();
void ezcaTraceOff();
void ezcaTraceOn();

/* Groupable Work Functions */

int ezcaGet(char *, char, int, void *);
int ezcaGetControlLimits(char *, double *, double *);
int ezcaGetGraphicLimits(char *, double *, double *);
int ezcaGetNelem(char *, int *);
int ezcaGetPrecision(char *, short *);
int ezcaGetStatus(char *, TS_STAMP *, short *, short *);
int ezcaGetUnits(char *, char *);
int ezcaGetWithStatus(char *, char, int, void *, TS_STAMP *, short *, short *);
int ezcaPut(char *, char, int, void *);

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
#define EZCA_INVALIDPVNAME     1
#define EZCA_INVALIDARG        2
#define EZCA_FAILEDMALLOC      3
#define EZCA_CAFAILURE         4
#define EZCA_UDFREQ            5
#define EZCA_NOTCONNECTED      6
#define EZCA_NOTIMELYRESPONSE  7
#define EZCA_INGROUP           8
#define EZCA_NOTINGROUP        9
