---
title: ChaosCore
layout: home
nav_order: 1
---


# ChaosCore

<div style="display: flex; align-items: flex-start;">
  <div style="flex: 1; padding-right: 20px;">
    <p>ChoasCore is a security oriented RV32GC core implemented in Chisel. It is aggresively parameterizable, out-of-order, superscalar, and synthezable. Currently, ChaosCore can be paramterized to generate verilog targeting either FPGAs or ASICs.</p>

    <p>Beyond being able to simply the core's fetch width, execution engine, and branch predictors, ChaosCore places an emphasis on demonstrating what impacts security oriented features may have on the performance.</p>

    <h3>What is done:</h3>
    <ul>
      <li>Dhrystone runs succesfully.</li>
      <li>Riscv-tests passed.</li>
      <li>Prediction accuracy of >90% (Workload?)</li>
      <li>Exceptions, interrupts, & privilage.</li>
    </ul>

    <h3>What is to be done:</h3>
    <ul>
      <li>Float & Double extensions</li>
      <li>Compressed instructions</li>
      <li>Virtual Memory</li>
    </ul>

  </div>

  <div style="max-width: 40%;">
    <img src="drawio/Core.drawio.svg" style="max-width: 100%;"/>
  </div>
</div>
