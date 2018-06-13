


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
	- `\(A_0,A_5\)` can't acces `\{M_{10},M_{11}\}`
	- if `\{A_0,A_5\}` access `M_{10}` `\overline{\{A_0,A_5\}}` 
---
#### First Things First: Bug Classification
- Functional Bugs

- RTL Bugs



---
#### Our Methods
- Differntial Memory Scan.
	- A way to find functional Bugs.
- Differential Code Coverage.
	- A way to find RTL bugs.
---
#### Differential Memory Scan
- Perspectives
	- Secure Perspective
	- Hacker Perspective

e.g
- In HackaDac we assume simple HW adversary
	- Secure Perspective: Processor/Software
	- Hacker Perspective: Access from hardware pins.
	
---
#### Differential Memory Scan
- More complicated Examples
- Trustzone
	- Secure Perspective: Software running in Secure World
	- Hacker Perspective: Software/hardware 
---
#### Existing Attacks in the SoC Domain

---

#### SoCFPGA: Architecture Overview
---
#### SoCFPGA: Architecture Overview I


---
#### Existing Counter-Measures in the SoCFPGA : TrustZone
---
#### TrustZone : Hardware
---

#### Existing Secuirty Measures: SoCFPGA
---
#### Existing Secuirty Measures: SMMU
---
#### Architectural Features
---
#### Attacks
--- 
#### Direct Memory Attacks
---
#### Cache Timing Attacks
---
#### Latency
---
#### Rowhammer
---
#### Security Vulnerabilities
---
#### Exepriments: DMA Code Injection
---?code=assets/src/dma0.asm&lang=asm&title=Disassembly of log10 function at python(2.7) numpy umath.so library
@[4](Replacing the jump to log10 function by jump to mod function)
---
#### Exepriments: Cache Timing Attacks to break ASLR
---
#### Exepriments: Cache Timing Attacks to break ASLR
---
#### Exepriments: Cache Timing Attacks to break ASLR
---
#### Exepriments: Cache Timing Attacks to break ASLR
---
#### Rowhammer
---
#### Rowhammer
---
#### Synthesis Results & Runtime

