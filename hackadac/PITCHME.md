


<!-- .slide: class="center" -->
###### <span style="color:#e49436">Differential Scanning Techniques for Detection of Security Vulnerabilities</span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> Sumanta Chaudhuri, Michael Timbert, Xuan Thuy Ngo, Sylvain Guilley</b></span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> Telecom ParisTech, Secure IC</b></span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em; font-weight:bold"> Paris, FRANCE  </b></span> 
---
#### Context

---

#### First Things First: The Attacker Model
- A clear idea of what are protecting and from whom ?
- What would we like to have:
	- Divide the attacker spaces into several sets. not necessarlily disjoint.
`$${A_0,A_1\ldots A_n} $$`

	- clearly specify each set with SystemVerilog Assertions.
	-e.g simple hardware adversary: 
---
#### First Things First: The Security Objective
- Specification of Security objectives with assertions:
- For memory mapped SoCs we have
	- A set of memory zones `$${M_0,M_1\ldots M_n} $$`
	- A set of Attackers/Users `$${A_0,A_1\ldots A_n} $$ 
- Example Security Objectives:
	- `\(A_0,A_5\)` can't acces `\({M_{10},M_{11}}\)`
	- if `\(A_0,A_5\)` access  `\(M_{10}\)` implies `\(\overline{\{A_0,A_5\}}\)`  can't access `\({M_{10},M_{11}}\)`
---
#### First Things First: Bug Classification
- Functional Bugs
	- e.g JTAG port is wide open
	- Protocol Bugs
    - Bugs arising from hardware and software specified separately

- RTL Bugs
	- Arising from poor coding techniques.
	- trying to meet other constraints (e.g timing)



---
#### Our Methods
- Differntial Memory Scan.
	- A way to find functional Bugs.
	- It might also find functional bugs but our main goal is to catch bugs which arise 
from interaction of different hardware/software blocks.
	- RTL is not the best place to find functional bugs.

- Differential Code Coverage.
	- A way to find RTL bugs.
---
#### Differential Memory Scan
- Perspectives
	- Secure Perspective
	- Hacker Perspective

-e.g
- In HackaDac we assume simple HW adversary
	- set of attackes `\(A_0\)`=Processor, `\(A_1\)`=JTAG, `\(A_2\)`=SPI, `\(A_3\)`=GPIO
	- Secure Perspective: Processor/Software `\(A_0\)`
	- Hacker Perspective: Access from hardware pins. `\({A_1,A_2,A_3}\)`
	
---
#### Differential Memory Scan
- More complicated Examples
- Trustzone
	- Secure Perspective: Software running in Secure World
	- Hacker Perspective: Software/hardware 
---
#### Differential Memory Scan

---

#### Differential Memory Scan
---
#### Differential Code Coverage


---
#### Differential Code Coverage
---
#### Our Method Applied to Pulpino
---

#### Our Method Applied to Pulpino
---
#### Our Method Applied to Pulpino
---
#### Bugs Found
---
#### Bugs Found
--- 
#### Bugs Not Found ?
---
#### Conclusion
---

