%Proiectare solutie de control automat prin Metoda LQR
s= tf('s');
Hf  = (5*s+1)/((7*s+1)*(2*s+1));
Hf1 = c2d(Hf,0.1,'Tustin');
[NUM,DEN] = tfdata(Hf,'v');
[A,B,C,D] = tf2ss(NUM,DEN);
% Q=[ 1  0 ;
%     0  0.001];
%     
% R=[50];
% %FUNCTIA LQR
% [K,S,E] = lqr(A,B,Q,R)
% A0=A-B*K;
% B0=B;
% C0=C;
% D0=D;
% [n0,d0]= ss2tf(A0,B0,C0,D0);
% H0=tf(n0, d0);
% figure(1)
% step(Hf);
% hold on
% figure(2)
% step(H0);
% hold off
 

% % Proiectare solutie de control automat prin plasarea polilor

psi=0.7;        %pt. suprareglaj de 5%
t_rasp=5;     %timp de raspuns impus
wn=4/(t_rasp*psi);
rlocus(Hf)
sgrid(psi,wn)

% %%Valorile polilor complex conjugati vor fi
 P=[-0.502   -0.143];
%calcul K pt a plasa polii in locatiile dorite   
K_place = place(A,B,P)
