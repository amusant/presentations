



###### <span style="color:#e49436">Beyond Bits</span>:A Quaternary FPGA Architecture using Multi-`\(V_t\)` Multi-`\(V_{dd}\)` FDSOI Devices

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> Sumanta Chaudhuri </b></span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> Telecom ParisTech </b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.4em; font-weight:bold"> Paris, FRANCE  </b></span> 
+++
<img src="https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_2vl_mux.svg" width="200"/> <img src="https://perso.telecom-paristech.fr/chaudhur/tmp/4VL_FF.svg" width="300"/>
+++
##### Motivation: Bits, Trits or Quits ?
---
##### Motivation: Compute or Communicate ?
---
##### Motivation: Cost of Interconnect 
+++
##### State of the Art: Related Works
---
##### State of the Art: FDSOI
<div id="images">
	<a>
		<img src="https://perso.telecom-paristech.fr/chaudhur/tmp/backbias.svg" width="400">
		<div class="caption">Caption 1</div>
	</a>
	<a>
		<img src="https://perso.telecom-paristech.fr/chaudhur/tmp/fdsoi.svg" width="400"> 
		<div class="caption">Caption 2</div>
	</a>
</div>
+++
##### Overall Goal: A Quaternary FPGA
+++
##### Basic Blocks : Donwliteral Converters
<div style='float:left'>
<img src="https://perso.telecom-paristech.fr/chaudhur/tmp/dlcs.svg" width="400"/>
</div>
<div style='float:left'>
        <table border="1" width="1" style="margin-left:30%;float:top;"> 
  		<tr>
  		  <td>input</td>
  		  <td>DLC0</td> 
  		  <td>DLC1</td> 
  		  <td>DLC2</td> 
  		</tr>
  		<tr>
  		  <td>0</td>
  		  <td>3</td> 
  		  <td>3</td> 
  		  <td>3</td> 
  		</tr>
  		<tr>
  		  <td>1</td>
  		  <td>0</td> 
  		  <td>3</td> 
  		  <td>3</td> 
  		</tr>
  		<tr>
  		  <td>2</td>
  		  <td>0</td> 
  		  <td>0</td> 
  		  <td>3</td> 
  		</tr>
  		<tr>
  		  <td>3</td>
  		  <td>0</td> 
  		  <td>0</td> 
  		  <td>0</td> 
  		</tr>
        </table>
</div>
+++
##### Basic Blocks : Multiplexers
+++
##### Basic Blocks : Quaternary Lookup Tables
+++
##### Basic Blocks : Quaternay Flip-Flops
+++
##### Basic Blocks : B2Q
+++
##### Basic Blocks : Q2B

+++ 
##### FPGA Modelling Tool: VPR 
+++ 
##### VPR Parameters
+++
##### Experiments: Candidate Architectures
+++
##### Experiments: Results

+++
#####Images


![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4VL_FF.svg)

<span style="color:gray; font-size:0.7em">Quaternary Flip-Flops<b>CLK and Reset is combined</b></span>

![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_2vl_mux.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4VL_FF.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_lut.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_mux.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_routing1.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_routing_base1.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_routing_base.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/4vl_routing.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/clb.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/ff_wv_wr.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/flow.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/layout1.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/layout_schema.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/layout_sketch.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/layout.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/mvl.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/qfpga.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/Qlut4.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/qlut.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater3.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_base.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_hs.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_hs_vtannot.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_ll.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_ll_vtannot.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_vtannot.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/repeater_wv_wr.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/spicenetlist4.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/spicenetlist.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/xlat_2_4.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/xlat_4_2.svg)
---
![Image-Absolute](https://perso.telecom-paristech.fr/chaudhur/tmp/xtalk_wr.svg)
---
