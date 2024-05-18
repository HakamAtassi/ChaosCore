# Use Ubuntu as the base image
FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive


RUN apt-get update -y && apt-get install -y \
    git \
    make \
    autoconf \
    g++ \
    flex \
    bison \
    perl \
    python3 \
    python3-pip \
    iverilog\
    help2man\
    apt-utils \
    ccache \
    numactl \
    vim


RUN git clone https://github.com/verilator/verilator \
    && unset VERILATOR_ROOT \
    && cd verilator \
    && git checkout v5.006 \
    && autoconf \
    && ./configure \
    && make -j $(nproc) \
    && make install \
    && verilator --version  # This will fail the build if Verilator is not correctly installed

# Install Python packages
RUN python3 -m pip install cocotb
RUN python3 -m pip install cocotb-test

# Install Scala

# Install chisel

# Install SBT


# Update bashrc
# TODO:

WORKDIR /work

# Default command on container start
CMD ["bash"]
