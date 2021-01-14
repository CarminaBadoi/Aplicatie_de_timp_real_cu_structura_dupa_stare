 // DECLARARE VARIABILE

static int panelHandle;
double referinta0,referinta=0,referinta_1,referinta_2; 
int selectare_referinta,comutare_sin;

double Te; // perioada de esantionare
double tk;        // esantionul luat la momentul prezent
double tk_1,tk_2;     // esantionul luat la momentul anterior
double tk_rampa;
double tk_sinusoida; 
double pi;   // variabila pi
double A;   // amplitudine
double T;  // perioada 
double b;   // pozitia pe ordonata

//---------------comanda ------------------
double yk_comanda_1,yk_comanda;

// -------------- VECTORUL K ------------------
double k1,k2,k3,a11,a12,a13,a21,a22,b1,b2,c1,c2,d;
double x1k,x2k,x1k_1,x2k_1;

//----------- elementul de executie ----------
double yk_elem_ex,yk_elem_ex_1 ; 
 

// -----------traductor proces---------------
double  yk_traductor,yk_traductor_1; 

// --------- eroarea -----------
double eroare,eroare_1,eroare_2;

// ----------proces --------------
double yk_proces,yk_proces_1;

// ------------- F.D.T PARTE FIXA ---------------------
 
double yk ;     // functia de transfer = (5s+1) / (7s+1) la momentul prezent
double yk_1;   // functia de transfer = (5s+1) / (7s+1) la momentul anterior 
double yk1_1; // functia de transfer =  1/ (2s+1) la momentul anterior 
double yk1;  // functia de transfer =  1/ (2s+1) la momentul prezent
double C00,C0,C1,C2,C3; // variabile pentru rescrierea functiilor 
