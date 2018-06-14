


<!-- .slide: class="center" -->
###### <span style="color:#e49436">Differential Scanning Techniques for Detection of Security Vulnerabilities</span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> 
Sumanta Chaudhuri, Michaël Timbert, Xuan Thuy Ngo, Sylvain Guilley<br>
Telecom ParisTech, Secure-IC<br>
Paris, FRANCE <br>
</b></span>

<img src="assets/TelecomParisTech_logo_80.png" style="position:absolute; left:800px; top:-200px;"/>
---
#### Context
- Modern day SoCs incorporate hundreds of third party IPs.
- All these IPs are specified/design separately.
- Security bugs arise from their interaction.
- The goal is to find secuirty bugs during design/integration phase.
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
- Ponit of Views (POV)
	- Secure Ponit of View
	- Hacker Point of View

-e.g
- In HackaDac we assume simple HW adversary
	- set of attackes `\(A_0\)`=Processor, `\(A_1\)`=JTAG, `\(A_2\)`=SPI, `\(A_3\)`=GPIO
	- Secure POV: Processor/Software `\(A_0\)`
	- Hacker POV: Access from hardware pins. `\({A_1,A_2,A_3}\)`
	
---
#### Differential Memory Scan
- More complicated Examples
- Trustzone
	- Secure POV: Software running in Secure World
	- Hacker POV: Software/hardware 
---
#### Differential Memory Scan : Pseudocode

---?code=hackadac/src/diffscan.c&lang=asm&title=PseudoCode of Differential Memory Scan
@[1](A set of memory zones)
@[2](A set of Attackers)
@[3](A set of secuirity objectives (Assertions))
@[4](Dividing into security objectives)
@[5-7](Scan & Check in parallel)

---
#### Pulpino Memory MAP
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/mmap.svg" width="300"/>
---
#### Differential Memory Scan : Pulpino
---?code=hackadac/src/pulpino.c&lang=asm&title=PseudoCode of Differential Memory Scan
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
    <td>JTAG PAssword Scheme is Broken</td>
    <td>RTL</td>
    <td>Differential Code Coverage</td>
  </tr>
</table>
--- 
#### Bugs Not Found ?
---
#### Conclusion
---

