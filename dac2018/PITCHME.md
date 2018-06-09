


<!-- .slide: class="center" -->
###### <span style="color:#e49436">A Security Vulnerability Analysis of SoCFPGA Architectures</span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> Sumanta Chaudhuri </b></span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> Telecom ParisTech </b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.4em; font-weight:bold"> Paris, FRANCE  </b></span> 
---
#### Context: Traditional Security Woes

- SoC Security |
	- Secure Boot |
	- Digital Rights Management |
	- Attacks Against OS |
- FPGA Security |
	- Bitstream Security |
	- Tampering |
	- Power/EM Side Channels |
---
#### Scope & Attacker Model 
- Scope |
	- Attacks on OS mounted from the FPGA  |
- Attacker Model |
	- Sceanrio A : High Performance Computing |
	- Scenario B : Embedded |
---
### Attacker Model
- HPC |
	- The attacker is an ordinary user of a SoCFPGA cluster |
	- She executes her code under the guise of compute intensive tasks. |
	- e.g AMAZON AWS |
	- Concerned FPGAs: Zynq UltraScale+, Arria W, Stratix X |

-Embedded |
	- The attacker is a third-party Supplier  of FPGA librarires (App Store) |
	- The User himself trying to break DRMs. |
	- concerned FPGAs: Cyclone V, Zynq 7000 |



<img src="https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_2vl_mux.svg" width="200"/> <img src="https://perso.telecom-paristech.fr/chaudhur/tmp/4VL_FF.svg" width="300"/>
+++


---
