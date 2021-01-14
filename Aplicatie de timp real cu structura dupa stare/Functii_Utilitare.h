int CVICALLBACK setare_esantionare (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
							// CITIRE PERIOADA DE ESANTIONARE
							GetCtrlVal(panelHandle,PANEL_NUMERIC_2,&Te);
							// ATRIBUIRE PERIOADA DE ESANTIONARE TIMER-ULUI
							SetCtrlAttribute(panelHandle,PANEL_TIMER,ATTR_INTERVAL,Te);

			break;
	}
	return 0;
}

int CVICALLBACK Refresh_graph (int panel, int control, int event,
							   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			//stergere grafic 
				
					DeleteGraphPlot (panelHandle, PANEL_GRAPH, -1, VAL_IMMEDIATE_DRAW );
					
					
					
			//Reinitializare timp de afisare
					tk_1=0;
					tk=0;

			break;
	}
	return 0;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			QuitUserInterface (0);

			break;
	}
	return 0;
}