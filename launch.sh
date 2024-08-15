#sudo docker build -t chaoscore .
#clear
#sudo docker run -m 4g -it --hostname ChaosCore chaoscore

# Create a python venv
python3 -m venv venv

# Source the venv
source venv/bin/activate


# install python libs in venv

python3 -m pip install py/ChaosCore/.
python3 -m pip install py/cocotb_utils/.

# install libs
python3 -m pip install cocotb
python3 -m pip install cocotbext-axi
python3 -m pip install cocotb_test
python3 -m pip install numpy
