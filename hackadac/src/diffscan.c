M={M0,M1,...} // Memory Zones
A={A0,A1,...} //Attacker Models
S={S0,S1,...} // Security Objectives
P={P0={A0},P1={A1,A2,A3}}
for i in M
	in parallel:
	scan(P,i); check_assertions(S);

Pulpino

M={}
A={A0,A1,...}
S0=
for i in M
	scan(P0,i)
	store results
	scan(P1,i)
	store results
	compare ane verify assertions
	
