#include "toolbox.h"
#include <userint.h>
#include "interfata_grafica.h"


 

#include "Declarare_variabile.h" 
#include "Generare_semnal.h"
#include "Functii_Utilitare.h"

 


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "interfata_grafica.uir", PANEL)) < 0)
		return -1;
	
	
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}


int CVICALLBACK Start_Aplicatie (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
				// SETARE PERIOADA DE ESANTIOANARE
				Te = 0.100;
				selectare_referinta = 0;
				
				
				// INITIALIZARE VARIABILE
				tk_1 = 0; 
			
			
				// VARIABILE ELEM DE EXECUTIE
				C00 = Te/(Te+0.4);
				C0 = 0.1/(Te+0.4);
				
				// VARIABILE F.D.T PROCES NEPERTURBAT
				C1 = Te/(Te+7);  
				C2 = 5/(Te+7);
				C3 = Te/(Te+2);
				
				// TERMENII MATRICILOR A,B,C,D
				a11 = - 0.6429;
				a12 = - 0.0714;
				a21 = 1;
				a22 = 0;
				
				b1 =1;
				b2 = 0;
				
				c1 = 0.3571;
				c2 = 0.0714;
				
				d= 0;
				
				// TE/*RMENII VECTORULUI K -  LQR
				//k1 =    0.0078    ;// 0.0016 ;  
				//k2 =     0.0001;//  0.0000; */
				
				// TERMENII VECTORULUI K - PLASAREA POLILOR
				k1 =   0.0021    ;  
				k2 =   0.0004;
			 	
				
				
				pi=Pi();
			
			
				// ATRIBUIRE PERIOADA DE ESANTIONARE TIMER-ULUI
				SetCtrlAttribute(panelHandle,PANEL_TIMER,ATTR_INTERVAL,Te);
				// PORNIM TIMER-UL
				SetCtrlAttribute(panelHandle,PANEL_TIMER,ATTR_ENABLED,1);
				
				// DEZACTIVAM BUTONUL DUPA CE ESTE APASAT
				SetCtrlAttribute(panelHandle,PANEL_OKBUTTON,ATTR_DIMMED,1);
			
			
			
			break;
	}
	return 0;
}


 


int CVICALLBACK esantionare (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			
								//------------------- SELECTARE INTRARE ------------------------
								
								 referinta=generare_semnal();
								  
								 
								//---------------------ELEMENTUL DE COMPARATIE ------------------
								
								yk_comanda = referinta - k1*x1k - k2 * x2k  ; 
								
								// ----------------------- ELEMENTUL DE EXECUTIE --------------------
								  
								yk_elem_ex = yk_elem_ex_1+ C00*(yk_comanda - yk_elem_ex_1) + C0*(yk_comanda - yk_comanda_1 );
								
								// ------------------------ FUNCTIA DE TRANSFER  PROCES -----------------------
								 x1k = x1k_1 + Te * a11 * x1k_1 + Te * a12 * x2k_1 + Te * b1 * yk_elem_ex_1;
								 x2k = x2k_1 + Te * a21 * x1k_1 + Te * a22 * x2k_1 + Te * b2 * yk_elem_ex_1;	
								// x3k = x3k_1 + Te * a31 * x1k_1 + Te * a32 * x2k_1 + Te * a33 * x3k_1 + Te * b3 * yk_elem_ex_1;
								 
								// --------IESIREA PROCESULUI --------------------
								yk_proces =  c1 * x1k + c2 * x2k  + d * yk_elem_ex ;
								
								// --------TRADUCTOR PROCES NEPERTURBAT ----------
								//yk_traductor = 1*yk;
								
								// -------- PLOTARE RASPUNSUL FUNCTIEI DE TRANSFER -----------
								PlotLine (panelHandle, PANEL_GRAPH, tk_1, referinta_1, tk, referinta, VAL_GREEN);
								PlotLine (panelHandle, PANEL_GRAPH, tk_1, yk_proces_1, tk, yk_proces, VAL_BLUE);
								
								
								
								//resetare timp
								tk_1=tk;
								tk_2=tk_1;
								tk=tk+Te;
								
												
								//---------------generare esantioane noi-----------------
								
								// REFERINTA
								referinta_2 = referinta_1;
								referinta_1=referinta;
								// EROARE
								eroare_2=eroare_1;
								eroare_1=eroare;
								// COMANDA
								yk_comanda_1 = yk_comanda;
								// ELEM DE EXECUTIE
								yk_elem_ex_1 = yk_elem_ex ; 
								
								// F.D.T PROCES NEPERTURBAT
								x1k_1 = x1k;
								x2k_1 = x2k;
								
								
								// PROCES
								yk_proces_1= yk_proces;
								
								// TRADUCTOR PROCES NEPERTURBAT
								yk_traductor_1 = yk_traductor;

			break;
	}
	return 0;
}

































 
 
 

 
