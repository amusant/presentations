


<!-- .slide: class="center" -->
###### <span style="color:#e49436">A Security Vulnerability Analysis of SoCFPGA Architectures</span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> 
Sumanta Chaudhuri</br>
Telecom ParisTech</br>
Paris, FRANCE </br>
</b></span>

<img src="assets/TelecomParisTech_logo_80.png" style="position:absolute; left:900px; top:-200px;" width="50"/>
---
#### Context, Scope & Attacker Models

- SoC Security |
	- Secure Boot |
	- Digital Rights Management |
	- Attacks Against OS |
- FPGA Security |
	- Bitstream Security |
	- Tampering |
	- Power/EM Side Channels |
- Scope |
	- Attacks on OS mounted from the FPGA  |
- Attacker Model |
	- Scenario A : High Performance Computing |
	- Scenario B : Embedded |
---
#### Attacker Model
- HPC |
	- The attacker is an ordinary user of a SoCFPGA cluster |
	- She executes her code under the guise of compute intensive tasks. |
	- e.g AMAZON AWS |
	- Concerned FPGAs: Zynq UltraScale+, Arria W, Stratix X |

- Embedded |
	- The attacker is a third-party Supplier  of FPGA libraries (App Store) |
	- The User himself trying to break DRMs. |
	- concerned FPGAs: Cyclone V, Zynq 7000 |
---
<!--#### Existing Attacks in the SoC Domain-->


#### SoCFPGA: Architecture Overview
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg" height="400"/>
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/ultrascale.svg" height="400"/> 
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
I) Arch. 1,2  Cyclone and Zynq like.
</b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
II) Arch 3,4  Stratix X, Ultrascale like.
</b></span>

<!--only inline/background images  work in pdf export -->
<!--+++?image=https://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg&size=auto 60% -->
<!--<span style="color:gray; font-size:0.7em">SoCFPGA Architectures II<b></b></span> -->
<!--@title[Les fabricants] -->
<!--#### SoCFPGA: Architecture Overview II-->
<!--<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg" width="400"/>  -->

---
#### Existing Counter-Measures in the SoCFPGA : TrustZone
- TrustZone
	- Framework encompassing both Hardware and Software
- SoftWare
	- Secure & Non-Secure World Abstractions
	- Monitor Mode which handles the transition from one worlds to another
	- Secure TEEs (Trusted Execution Environments) run in the Secure World
		- e.g SierraTEE, Toppers
	- Rich OS Android, Linux, RTOS
- Hardware
	-	Each master can be Secure/Non-Secure/Per Transaction
	-	Firewalls (Programmable at Runtime)
	-	Cache Security Bit (33rd bit)

---

#### Existing Security Measures: SoCFPGA

- Memory Protection Unit
	- can define memory zones with granularity.
		- e.g 1MB in Cyclone V, 64MB in Zynq
	- control access based on Address Range, Master Id, Master Port

- Secure Cache Access
	- Security State of the masters using ACP must be the same as that of the processor

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
	- Reserving memory away from Linux Kernel
	- Reconfiguring Firewalls to block cache access
	- GCC like checks to detect buffer overflows. in OpenCL
	- Block traffic during context switch.
	
---
#### Cache Timing Attacks
- Attacks
	- CTA to break ASLR
	- CTA to guess program behaviour.
		- to guess cryptographic keys
- Countermeasures
	- SoCFPGAs with ACP and without SMMU are vulnerable.
	- A MMU can be programmed into FPGA.
	- Blocking Cache access during cryptographic routines.
---
#### Latency
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/lathist.svg" width="400"/> 
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/zynqcyclone.svg" height="400"/>
---
#### Rowhammer
- Attacks
	- Repeatedly reading a DRAM row within the refresh interval can cause bit-flips in the adjacent rows.
	- Particularly easy from FPGA. High speed/low latency memory access.
	- A maximum no. of memory accesses within the refresh interval.
	- FPGAs have direct links to DDR. (no intermediate cache)
- Countermeasures
	- For effective attacks need to break ASLR first.
	- Obfuscation of physical address (since linux kernel 4.0)
	- Error correction codes (SECDED is  not enough.)
	- Target Row Refresh
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

---
#### Experiments: DMA Code Injection

-  The host program creates memory pressure by allocating arrays,
 and using those arrays in memory.

- In a separate process, the numpy module from python is loaded
  which forces the load of the umath.so library.

- The FPGA accelerator kernel scans through the CMA area for
  the following string âe28fc600;e28cca44;e5bcfd68â which is the
  signature of the log10 function.



---?code=assets/src/dma0.asm&lang=asm&title=Disassembly of log10 function at python(2.7) numpy umath.so library
@[4](Replacing the jump to log10 function by jump to mod function)
---
#### Experiments: Cache Timing Attacks to break ASLR
- In the first phase, FPGA accelerator kernel scans the 
  memory space with a step of 4KBytes and offset equal to 
  the virtual address offset. 

- In the 2nd phase, the host program, accesses the target virtual
  address (e.g beginning of the GNU libc), and at the same time
  FPGA measures the latency, so the target address has a high
  probability to get low latency.

-  next we rank addresses w.r.t the latency data from both phases
 and we use the following equation to calculate final ranks.

`$$\tiny{rank = \frac{\left|rank_{latency}(phase 1)-rank_{latency}(phase 2)\right|}{rank_{latency}(phase 2)}}$$`
---
#### Experiments: Cache Timing Attacks to break ASLR
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/raw1.png" width="400"/> 
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/raw2.png" width="400"/> 
<!--<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/ptetable1.svg" width="300"/> -->
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
I) The raw cache access latency data.
</b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
II) The differential ranking metric
</b></span>
---
#### Rowhammer
<!--![diag](http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/rowhammer_issi_16x256.svg) {width=10%} -->
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/rowhammer_issi_16x256.svg" height="400"/> 
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/map.svg" height="400"/> 
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:20px; top:600px;">
a) Error rate with Refresh Interval
</b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:620px; top:600px;">
(b) The error map of a 256 MB zone. Each
square represents 64KB.

</b></span>
<!--![diag](http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/map.svg) {width=10%} -->
---
#### Synthesis Results & Runtime

<table>
  <tr>
    <th>Attack Type</th>
    <th>EXP. A</th>
    <th>EXP. B</th>
    <th>EXP. C</th>
    <th>Ref. Kernel</th>
  </tr>
  <tr>
    <td>LEs</td>
    <td>8145</td>
    <td>17767</td>
    <td>9724</td>
    <td>216146</td>
  </tr>
  <tr class="fragment">
    <td>FFs</td>
    <td>15434</td>
    <td>33202</td>
    <td>18058</td>
    <td>375931</td>
  </tr>
  <tr class="fragment">
    <td>RAMS</td>
    <td>275 Kb</td>
    <td>269 Kb </td>
    <td>283 Kb </td>
    <td>245 Kb </td>
  </tr>
  <tr class="fragment">
    <td>DSP</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>1064</td>
  </tr>
  <tr class="fragment">
    <td>Freq. (MHz)</td>
    <td>143.55</td>
    <td>131.84</td>
    <td>149.99</td>
    <td>143.55</td>
  </tr>
  <tr class="fragment">
    <td>Runtime</td>
    <td>~10 min</td>
    <td>10 s</td>
    <td>16 Hours</td>
    <td>NA</td>
</table>
--- 
#### Conclusion
- We discussed various possible attacks on current SoCFPGA Architectures.
	- DMA
	- Cache Timing
	- Rowhammer
- Most of them arise from hardware/software interaction.
- and attacks which were not known during design time.
- Need to apply a security solution on a case-by-case basis.

---
<span style="font-family:Helvetica Neue; color blue;font-size:2.0em;font-weight:bold; position:absolute;left:200px; top:200px;">
Questions ?
</b></span>
