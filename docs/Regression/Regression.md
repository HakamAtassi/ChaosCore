---
layout: default
title: Regression
nav_order: 2
has_children: true
---

# Regression

ChaosCore does its best to provide a reliable and robust verification environment. This is first to provide others with confidence in the functionality of the core, and second, to provide a platform for the contribution of tests without the overhead of learning a custom test framework. 

To this end, ChaosCore provides 3 discrete UVM test environments: one for the I$, one for the D$, and one for the Core. The I$ and D$ test environments provide a hand-written testlist encapuslated as YAML files. This approach was inspired by the verification infrastructure of OpenTitan. The Core, however, uses the riscv-dv instruction generator to fuzz the processor. 

Feel free to browse these regressions by accessing the table of contents below. 