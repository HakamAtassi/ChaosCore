---
title: ChaosCore
layout: home
nav_order: 1
---


# ChaosCore (name subject to change)

## What ChaosCore? 



ChaosCore is a very Chaotic core. It works, passes our very robust verification suite (inspired by OpenTitan), but somehow leaves its users exposed. 


ChaosCore is a performance oriented aggresively parameterizable out-of-order superscalar Risc-v processor. ChaosCore comes in a few varients:

* Standard mode: the default ChaosCore configuration. Provides 2 ChaosCores for twice the fun. Shared L2 Cache.
* DVFS mode: a configuration option that scales power and frequency dependant on workload. Just dont let anyone find out. 
* Shared EU mode: a configuration offering a cheaper alternative to true multicore mode by sharing the cores EUs. 
* ???

Each of these varients offer a further configuration. Standard mode, for instance, offers a smoke mode that uses obfuscation techniques to hide memory activity. Standard mode also offers <clever mode for non speculative> mode, that masks processor speculation to limit specter attacks. 


* how will the user get their code to run??? Do they build it in advance and run it on the core? how does this work exactly?
















"if you ever get the chance to work on an out of order processor, take that chance" - Onur Multu