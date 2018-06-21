
M={RAM,ROM,IRAM,UART,GPIO,SPIM,Timer,Intr,I2C,FLL,CTRL,DBG}
A={PROC,JTAG,SPI,GPIO,PINS}
S0= <next slide>
for i in M
	scan(P0,i)
	store results
	scan(P1,i)
	store results
	compare ane verify assertions
