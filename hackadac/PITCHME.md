


<!-- .slide: class="center" -->
###### <span style="color:#e49436">Differential Scanning Techniques for Detection of Security Vulnerabilities</span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> 
Michaël Timbert, Sumanta Chaudhuri, Xuan Thuy Ngo, Sylvain Guilley</br>
Telecom ParisTech, Secure-IC</br>
Paris, FRANCE </br>
</b></span>

<img src="assets/TelecomParisTech_logo_80.png" style="position:absolute; left:850px; top:-200px;" width="50"/>
<img src="hackadac/images/logo_sic_2016.png" style="position:absolute; left:910px; top:-200px;" height="50" width="150"/>
---
#### TPTSIC: Telecom ParisTech
- Grande Ecole in France 
- Formerly École Nationale Supérieure des Télécommunications. (ENST)
- Established in 1878
- A Specialisation School for Digital Technologies.
- Among the top 5 engineering schools in France.
---
#### TPTSIC: Secure-IC
<!---?image=https://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/Secure-IC_presentation_one_slide.svg&size=auto&title=Secure-IC -->
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/Secure-IC_presentation_one_slide.svg" width="700"/>
---
#### Context
- Semiconductor industry is highly globalised.
- Modern day SoCs incorporate hundreds of third party IPs.
- All these IPs are specified/design separately by different design teams.
- Security bugs arise from their interaction during integration.
- The goal is to find security bugs during design/integration phase.  
##### Hack@Dac
- 1st Phase: An open source SoC Pulpino.
- 2nd Phase: An open source SoC Pulpissimo.

Note:
Important point to stress is that our goal is to catch during integration 
phase, before the chip goes to foundry.
---
#### First Things First: The Attacker Model

- A clear idea of what are we protecting and from whom ?
- What would we like to have:
	- Divide the attacker space into several sets. not necessarily disjoint.
`$${A_0,A_1\ldots A_n} $$`

	- clearly specify each set with attributes/enumerated types.
	- e.g simple hardware adversary using JTAG port.
	- e.g simple hardware adversary using AXI port 1, with Master ID 4, 
	- e.g simple(unprivileged software adversary)

Note:
Importance of specifying things correctly. Second example shows teh specification 
of a master among various masters using the same AXI port.
---
#### First Things First: The Security Objective
- Specification of security objectives with assertions:
- For memory mapped SoCs we have
	- A set of memory zones `$${M_0,M_1\ldots M_n} $$`
	- A set of Attackers/Users `$${A_0,A_1\ldots A_n} $$ 
- Example Security Objectives:
	- `\(A_0,A_5\)` can't access `\({M_{10},M_{11}}\)`
	- if `\(A_0,A_5\)` access  `\(M_{10}\)` implies `\(\overline{\{A_0,A_5\}}\)`  can't access `\({M_{10},M_{11}}\)`

Note:
Important to specify security objectives which can be directly used in code not 
in text/word/excel format.

---?code=hackadac/src/assertions.sv&lang=verilog&title= Security Objectives SVA

Note: 

Property/sequence they are system verilog assertion (sva) keyword. 
|-> means implies. The first property shows that value read from jtag port 
should not be the same as value read from processor. The sequence describes the password
11000 in sva. The last property shows that password sequence implies data read from jtag 
port should be equal to memory data.
---
#### First Things First: Bug Classification
- Functional Bugs
	- e.g JTAG port is wide open
	- Protocol Bugs
    - Bugs arising from hardware and software specified separately

- RTL Bugs
	- Arising from poor coding techniques.
	- trying to meet other constraints (e.g timing, power)



---
#### Our Methods
- Differential Memory Scan.
	- A way to find functional Bugs.
	- It might also find RTL bugs but our main goal is to catch bugs which arise 
from interaction of different hardware/software blocks.
	- RTL is not the best place to find functional bugs.

- Differential Code Coverage.
	- A way to find RTL bugs.

- Linting.
	- Traditional RTL linters like SpyGlass.
---
#### Differential Memory Scan
- Point of Views (POV)
	- Secure Point of View
	- Hacker Point of View

-e.g
- In Hack@Dac we assume simple HW adversary
	- set of attackers `\(A_0\)`=Processor, `\(A_1\)`=JTAG, `\(A_2\)`=SPI, `\(A_3\)`=GPIO
	- Secure POV: Processor/Software `\(A_0\)`
	- Hacker POV: Access from hardware pins. `\({A_1,A_2,A_3}\)`
	
---
#### Differential Memory Scan
- More complicated Examples
- Trustzone
	- Secure POV: Software running in Secure World
	- Hacker POV: Software/hardware 
- Cache snoop control unit
	- Secure POV: Processor AXI port.
	- Hacker POV: Accelerator Coherency port from, NIC, DMA.

---?code=hackadac/src/diffscan.c&lang=asm&title=Differential Memory Scan : Pseudocode
@[1](A set of memory zones)
@[2](A set of Attackers)
@[3](A set of security objectives (Assertions))
@[4](Dividing into security objectives)
@[5-7](Scan & Check in parallel)

---
#### Pulpino Memory MAP
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/mmap.svg" width="300"/>
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/pulpino_block.svg" fill="#044B94" fill-opacity="0.4" width="500" style="position:absolute; left:400px; top:100px;"/>



---?code=hackadac/src/pulpino.c&lang=asm&title=Differential Memory Scan : Pulpino

--- 
#### Differential Memory Scan: Pulpino
- Found Boot address modification bug
	- The system boots from bootrom 0x8080, and runs.
	- The attacker resets the SoC. and puts it in sleep mode (fetch_enable).
	- The attacker changes the boot address  (e.g 0x4000)  through JTAG.
   		Boot address Register 0x1A107008, P. 27 datasheet.pdf
	- Attacker loads his program through SPI. (spi_load(use_qspi)) in testbench,
   at the same address 0x4000.
	- The attacker brings the SoC out of sleep mode, the SoC will now boot from
   0x4000 with attacker program.

---
#### Differential Code Coverage
- A way to detect RTL Bugs.
- Once a functional bug is detected we can enquire if it is in specification or due to a RTL bug.
- To find RTL trace:
	- first run some random tests and store code coverage.
	- execute the scan from concerned user/attacker model, and store code coverage results.
	- Diff the code coverage to find RTL trail.
	- This process can be further refined with each access. read/write/password etc.   


---
#### Differential Code Coverage
-	Applied differential code coverage to inspect JTAG port vulnerability.
-	Scan through all other ports (SPI,CPU)
-	Store code coverage.
-	several accesses through JTAG port.
-	Manually diff code coverage.

---
<p><span class="menu-title slide-title">coverage with no jtag access : adbg_tap_top.sv </span></p>
```verilog
225              // sequential part of the FSM
226       76     always @ (posedge tck_pad_i or negedge trstn_pad_i)
227              begin
228                 if(trstn_pad_i == 0)
229                     begin
230        5            TAP_state = `STATE_test_logic_reset;
231        5            pwd_check = 1'b1;
232                     end
233                 else
234       71            TAP_state = next_TAP_state;
235              end
236
237
238              // Determination of next state; purely combinatorial
239      138     always @ (TAP_state or tms_pad_i or logic_reset or pwd_check)
240              begin
241                 case(TAP_state)
242                     `STATE_test_logic_reset:
243                         begin
244        2                if(tms_pad_i) next_TAP_state = `STATE_test_logic_reset;
245       20                else next_TAP_state = `STATE_run_test_idle;
246                         end
247                     `STATE_run_test_idle:


```
---
<p><span class="menu-title slide-title">coverage with jtag access: adbg_tap_top.sv</span></p>
```verilog
225             // sequential part of the FSM
226   42060     always @ (posedge tck_pad_i or negedge trstn_pad_i)
227             begin
228                if(trstn_pad_i == 0)
229                    begin
230    3077            TAP_state = `STATE_test_logic_reset;
231    3077            pwd_check = 1'b1;
232                    end
233                else
234   38983            TAP_state = next_TAP_state;
235             end
236
237
238             // Determination of next state; purely combinatorial
239   93833     always @ (TAP_state or tms_pad_i or logic_reset or pwd_check)
240             begin
241                case(TAP_state)
242                    `STATE_test_logic_reset:
243                        begin
244    2050                if(tms_pad_i) next_TAP_state = `STATE_test_logic_reset;
245   13331                else next_TAP_state = `STATE_run_test_idle;
246                        end
247                    `STATE_run_test_idle:


```
---
<p><span class="menu-title slide-title">Our Method Applied to Pulpino</span></p>
<!---?code=hackadac/src/adbg_tap_top.v&lang=verilog&title=Our Method Applied to Pulpino -->
```verilog
// sequential part of the FSM
always @ (posedge tck_pad_i or negedge trstn_pad_i)
begin
	if(trstn_pad_i == 0)
		begin
		TAP_state = `STATE_test_logic_reset;
		pwd_check = 1'b0;
		end
	else
		TAP_state = next_TAP_state;
end
```
- Password check is set to 1 during reset
---
<p><span class="menu-title slide-title">Our Method Applied to Pulpino</span></p>
<!---?code=hackadac/src/adbg_tap_top.v&lang=verilog&title=Our Method Applied to Pulpino-->
```verilog
    counter <= counter + 1'b1;
  end
end
always @ (*) begin
  if(counter == 5'b11111) begin
    pwd_check = (tmp_pwd[7:0] == idcode_reg[7:0]);
  end
    logic_reset = (idcode_reg[counter] != tmp_pwd[counter])? 1: 0;
end
```
- Only Last 8 bits of the password are checked
- the attacker  will be able to pass one jtag instruction/data,
- the attacker can reset every  time and write unlimited instructions
---
#### Bugs Found
<table>
  <tr>
    <th>Attack</th>
    <th>Type</th>
    <th>Method Used</th>
  </tr>
  <tr>
    <td>Boot address can be changed through SPI & sleep pin</td>
    <td>Functional</td>
    <td>Differential Scan</td>
  </tr>
  <tr class="fragment">
    <td>Boot address can be changed through JTAG & sleep pin</td>
    <td>Functional</td>
    <td>Differential Scan</td>
  </tr>
  <tr class="fragment">
    <td>GPIOs can be read through JTAG/SPI</td>
    <td>Functional</td>
    <td>Differential Scan</td>
  </tr>
  <tr class="fragment">
    <td>Debug Modes can be enabled through JTAG/SPI</td>
    <td>Functional</td>
    <td>Differential Scan</td>
  </tr>
  <tr class="fragment">
    <td>JTAG password scheme is Broken</td>
    <td>RTL</td>
    <td>Differential Code Coverage</td>
  </tr>
  <tr class="fragment">
    <td>JTAG password can be guessed through Exhaustive search.</td>
    <td>RTL</td>
    <td>Differential Code Coverage</td>
  </tr>
</table>


#### Drawbacks of our Methods:
- Depends on Simulation. (i.e not static such as linting)
- Needs a test already running from Secure Point of View.
- We could not get a secure mode test running in the finals. 
--- 
#### Conclusion
- SoC Designers integrate and create bugs.
- We differentiate and debug.
- Not very different from standard verification methodologies.
- Capable of detecting both functional and RTL bugs.
- Our methods are not static. 
---
<span style="font-family:Helvetica Neue; color blue;font-size:2.0em;font-weight:bold; position:absolute;left:250px; top:200px;">
Questions ?
</b></span>
