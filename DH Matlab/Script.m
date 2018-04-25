syms q1 q2 q3;
syms d1 d2 d3;
syms a1 a2 a3;
syms w1 w2 w3;

pii = sym(pi);

%{
d2 = 0;
d3 = 0;
a1 = 0;
w1 = pii/2;
w2 = 0;
w3 = 0;
%}

A01 = DH(q1,d1,a1,w1);
A12 = DH(q2,d2,a2,w2);
A23 = DH(q3,d3,a3,w3);

T = A01*A12*A23;