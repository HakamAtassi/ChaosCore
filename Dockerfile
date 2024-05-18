# Use Ubuntu as the base image
FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

# Install basic dependencies
#RUN apt-get update -y && apt-get install -y \
    #git \
    #make \
    #autoconf \
    #g++ \
    #flex \
    #bison \
    #perl \
    #python3 \
    #python3-pip \
    #iverilog \
    #help2man \
    #apt-utils \
    #ccache \
    #numactl \
    #vim \
    #curl \
    #gnupg \
    #software-properties-common

# Install Verilator
#RUN git clone https://github.com/verilator/verilator \
    #&& unset VERILATOR_ROOT \
    #&& cd verilator \
    #&& git checkout v5.006 \
    #&& autoconf \
    #&& ./configure \
    #&& make -j $(nproc) \
    #&& make install \
    #&& verilator --version  # This will fail the build if Verilator is not correctly installed

# Install Python packages
#RUN python3 -m pip install cocotb cocotb-test

# Install Scala CLI
#RUN curl -sSLf https://scala-cli.virtuslab.org/get | sh

# Install SBT
#RUN echo "deb https://repo.scala-sbt.org/scalasbt/debian all main" | tee /etc/apt/sources.list.d/sbt.list  \
    #&& echo "deb https://repo.scala-sbt.org/scalasbt/debian /" | tee /etc/apt/sources.list.d/sbt_old.list  \
    #&& curl -sL "https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x2EE0EA64E40A89B84B2DF73499E82A75642AC823" | apt-key add   \
    #&& apt-get update  \
    #&& apt-get install sbt
# Install SBT


# Install Chisel3 (via SBT project dependency)

# Sample build.sbt file for a Chisel3 project
#RUN curl -O -L https://github.com/chipsalliance/chisel/releases/latest/download/chisel-example.scala

# Update bashrc (if needed)
# TODO: Add any custom bashrc updates

WORKDIR /work

# Default command on container start
CMD ["bash"]
