---
layout: default
title: Naming Convention(s) 
nav_order: 10
---




# Naming

Variable naming in large projects is very important. As such, this folder includes naming requirements of the involved modules

# Ports

All ports must be named as follows: ```<module_name>_<input/output>_snake_case_signal``` including clocks and resets. 

# Internal Signals

Internal signals are named ```snake_case_signal_name_<reg/wire>```, ie, the signal name must end with whether it is a wire or register.