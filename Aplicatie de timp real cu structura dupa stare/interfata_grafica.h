/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_GRAPH                      2       /* control type: graph, callback function: (none) */
#define  PANEL_NUMERIC_2                  3       /* control type: numeric, callback function: setare_esantionare */
#define  PANEL_NUMERIC_5                  4       /* control type: numeric, callback function: modificare_panta */
#define  PANEL_NUMERIC_4                  5       /* control type: numeric, callback function: (none) */
#define  PANEL_NUMERIC_3                  6       /* control type: numeric, callback function: Comutare_Sinusoida */
#define  PANEL_NUMERIC                    7       /* control type: numeric, callback function: (none) */
#define  PANEL_RING                       8       /* control type: ring, callback function: selectie_semnal */
#define  PANEL_OKBUTTON                   9       /* control type: command, callback function: Start_Aplicatie */
#define  PANEL_QUITBUTTON                 10      /* control type: command, callback function: QuitCallback */
#define  PANEL_OKBUTTON_2                 11      /* control type: command, callback function: Refresh_graph */
#define  PANEL_TIMER                      12      /* control type: timer, callback function: esantionare */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Comutare_Sinusoida(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK esantionare(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK modificare_panta(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Refresh_graph(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK selectie_semnal(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK setare_esantionare(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start_Aplicatie(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif