


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

---
#### Attacker Model
- Embedded |
	- The attacker is a third-party Supplier  of FPGA librarires (App Store) |
	- The User himself trying to break DRMs. |
	- concerned FPGAs: Cyclone V, Zynq 7000 |
---
#### Existing Attacks in the SoC Domain

---
<!---
#### SoCFPGA: Architecture Overview
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.png" width="600"/>
-->
---
#### SoCFPGA: Architecture Overview I
![diag](http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg) {:height="36px" width="36px"}

<!--only inline/background images  work in pdf export -->
---?image=https://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg&size=auto 60%
<span style="color:gray; font-size:0.7em">SoCFPGA Architectures II<b></b></span>

@title[Les fabricants]
---
#### SoCFPGA: Architecture Overview III
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg" width="600"/> 

---
#### Existing Counter-Measures in the SoCFPGA : TrustZone
- TrustZone
	- Framework encompassing both Hardware and Software
- SoftWare
	- Secure & Non-Secure World Abstractions
	- Monitor Mode which handles the transition from one worls to another
	- Secure TEEs (Trusted Execution Environments) run in the Secure World
		- e.g SierraTEE, Toppers
	- Rich OS Android, Linux, RTOS
---
#### TrustZone : Hardware
-	Each master can be Secure/Non-Secure/Per Transaction
-	Firewalls (Programmable at Runtime)
-	Cache Security Bit (33rd bit)

---

#### Existing Secuirty Measures: SoCFPGA

- Memory Protection Unit
	- can define memory wones with granularity.
		- e.g 1MB in Cyclone V, 64MB in Zynq
	- control access based on Address Range, Master Id, Master Port

- Secure Cache Access
	- Secuirty State of the masters using ACP must be the same as that of the processor
	- 

#### Existing Secuirty Measures: SMMU
- System MMU/IOMMU 
	- MMU is the main memory protection mechanism in OS/SoC.
	- SMMU/IOMMU provides the same functionality for accelerators.
	- Ease of programmability.
	- Fine Grain Security for memory access (4KB)
---
#### Architectural Features
@title[Piecemeal Tables]

<table>
  <tr>
    <th>Features</th>
    <th>Arch1</th>
    <th>Arch2</th>
    <th>Arch3</th>
    <th>Arch4</th>
  </tr>
  <tr>
    <td>FireWalls</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  </tr>
  <tr class="fragment">
    <td>MPU at DDR Controller</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
  </tr>
  <tr class="fragment">
    <td>33rd 'NS' bit for Cache</td>
    <td>@fa[times]</td>
    <td>@fa[check]</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
  </tr>
  <tr class="fragment">
    <td>System MMU</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  </tr>
  <tr class="fragment">
    <td>ACP Present</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[times]</td>
  </tr>
  <tr class="fragment">
    <td>CCI</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  </tr>
</table>


---
#### Attacks
- Direct Memory Attacks
- Cache Timing Attacks
- Rowhammer

--- 
#### Direct Memory Attacks
- Attacks
	- DMA through Contiguous Memory
	- DMA through Cache
	- DMA Buffer Overflow
	- DMA through SMMU update window
- Countermeasures
	

---
#### Security Vulnerabilities
@title[Piecemeal Tables]

<table>
  <tr>
    <th>Attack Type</th>
    <th>Arch1</th>
    <th>Arch2</th>
    <th>Arch3</th>
    <th>Arch4</th>
  </tr>
  <tr>
    <td>DMA through CM</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
  </tr>
  <tr class="fragment">
    <td>DMA through Cache</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
  </tr>
  <tr class="fragment">
    <td>DMA Buffer Overflow</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  </tr>
  <tr class="fragment">
    <td>DMA SMMU Update</td>
    <td>n.a</td>
    <td>n.a</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  </tr>
  <tr class="fragment">
    <td>CTA (ASLR)</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[times]</td>
    <td>@fa[times]</td>
  </tr>
  <tr class="fragment">
    <td>CTA (Program Behaviour)</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  <tr class="fragment">
    <td>Rowhammer Bit Flip</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
    <td>@fa[check]</td>
  </tr>
</table>
+++


---
