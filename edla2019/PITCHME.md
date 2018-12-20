


<!-- .slide: class="center" -->
###### <span style="color:#e49436">A Streaming Deep Learning Accelerator with Selective Binarization</span>

<span style="font-family:Helvetica Neue; color blue;font-size:0.4em;font-weight:bold"> 
Xuecan Yang, Sumanta Chaudhuri, Laurence Likforman, Lirida Naviner</br>
Telecom ParisTech</br>
Paris, FRANCE </br>
</b></span>

<img src="assets/TelecomParisTech_logo_80.png" style="position:absolute; left:900px; top:-200px;" width="100"/>
---
#### Convolutional Neural Networks
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/cnn.svg" height="550"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Tiny Yolo Network.
</b></span>

---
#### Binarized CNNs & XNOR-net

- Binarization
	- Both Feature Maps and Coefficients can be Binarized with little loss in Precision
	- Works for smaller neural nets Lenet, Alexnet
- We prpose A Mixed prcision Neural network where we can mix layers with
	- Both Features and Weights are Floating Point(16 bit)
	- Features are in Floating point, Weights are binary.
	- Both Features and weights are Binary.
---
#### A Streaming Accelerator
- Streaming Accelerator
	- The input feature maps are streamed from main memmory to the accelerator.
	- The output feature maps are streamed back to the main memory.
	- Accelerator handles one layer at a time.

<!--#### Existing Attacks in the SoC Domain-->

---
#### Tiny Yolo: Object Detection
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/table1.svg" height="400"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Tiny Yolo Network.
</b></span>

---

#### Tiny Yolo: Intersection Over Union (IOU)
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/n11.png" height="400"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Tiny Yolo Network.
</b></span>

---
#### Tiny Yolo: Experiments
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/table2.svg" height="400"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Candidate Architectures.
</b></span>

---
#### Tiny Yolo: Training Results
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/IOU.svg" height="400"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Results of Training with different archietctures.
</b></span>

---
#### Accelerator: Architecture Overview
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/arch1.svg" height="400"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Overall Hardware Architecture.
</b></span>

---
#### Accelerator: Image To Matrix
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/im2col.svg" height="400"/>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Image to Matrix Transformation.
</b></span>

---

#### Accelerator: Architecture Overview
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/arch2.svg" height="400"/> 
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:40px; top:550px;">
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:500px; top:550px;">
Detailed architecture of the convolutional lanes.
</b></span>
---
#### Results:2x Improvement in Speed for 10% loss in IOU.
<!--![diag](http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/rowhammer_issi_16x256.svg) {width=10%} -->
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/result_arch_base.svg" height="225"/> 
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/result_arch8.svg" height="225"/> 
<img src="http://perso.telecom-paristech.fr/~chaudhur/images/edla/result_arch12.svg" height="225"/> 
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:20px; top:400px;">
a) Base Architecture
</b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:400px; top:400px;">
(b) Architecture 8
</b></span>
<span style="font-family:Helvetica Neue; color blue;font-size:0.5em;font-weight:bold; position:absolute;left:700px; top:400px;">
(c) Architecture 12
</b></span>

<!--![diag](http://perso.telecom-paristech.fr/~chaudhur/images/hsa_security/map.svg) {width=10%} -->
---
#### 
- Experiments are done in Pynq-Z1 board. from Xilinx.
	- 
	- The output feature maps are streamed back to the main memory.
	- Accelerator handles one layer at a time.
- Previous Work:
	- Traffic Sign Recognition Network 
	- Done on Cyclone V FPGA
	- OpenCL High level Synthesized program
	- First Prize in Intel Innovate Contest 2017.
	- [video] (https://www.youtube.com/watch?v=ePiQd8jrHkI)
<!--#### Existing Attacks in the SoC Domain-->
