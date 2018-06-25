property secure_jtag;
	@(negedge clk) $sampled(jtag_data)!=$sampled(mem_data)
endproperty

sequence jtag_passwd; //11000101
	$rose(jtag.tdi) ##2 $fell(jtag.tdi) ##3 $rose(jtag.tdi) ##1 $fell(jtag.tdi) ##1 $rose(jtag.tdi)
endsequence

property secure_func_jtag;
	@(negedge clk) 
	jtag_passwd |=> $sampled(jtag_data)==$sampled(mem_data)
endproperty
