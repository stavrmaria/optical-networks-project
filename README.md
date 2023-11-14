# Optical Networks Project

## Project Description
In an optical network, eight computers use four different wavelengths (λ1 – λ4) to transmit packets to a server. Computers C1 and C2 transmit using wavelength λ1, computers C3 and C4 use λ2, and so on. The connection between the server and computers is established through combiners and a Wavelength Division Multiplexer (WDM multiplexer), as illustrated in the diagram.

<center>
<img src="opt-net.png" alt="network topology" width="400"/>
</center>

### Transmission occurs as follows:
- Time is divided into slots, each with a duration equal to the packet transmission time.
- Each computer has a queue with a capacity of 5 packets, and the probability of an arrival during a slot is denoted by ***p***.
- If a packet arrives and finds the queue full, it is lost.
- In each slot, every computer with a non-empty queue transmits its first (oldest) packet to the server with a probability of ***0.5***. 
- If two stations sharing the same wavelength transmit in the same slot, both packets are destroyed and remain in the station queues for retransmission.

### Objectives
1. For ***p = 0.1, 0.2, ..., 0.9, 1***:
    - Calculate the average packet delay (in slots) in the network.
    - Construct a graph with the horizontal axis representing the probability ***p*** and the vertical axis representing the average packet delay.
2. For ***p = 0.1, 0.2, ..., 0.9, 1***:
    - Calculate the throughput (average number of successful transmissions in a slot) in the network.
    - Construct a graph with the horizontal axis representing the probability ***p*** and the vertical axis representing the throughput.
3. For ***p = 0.1, 0.2, ..., 0.9, 1***:
    - Calculate the packet loss rate in the network.
    - Construct a graph with the horizontal axis representing the probability ***p*** and the vertical axis representing the packet loss rate

## Calculations & Graphs
- **Propability - Average Delay Graph**
$$ Average Delay = \frac{Total Delay}{Total Packets Sent} $$ 
<p align="center">
<img src="https://quicklatex.com/cache3/06/ql_c5b7539a7159e14a09920d6c671d4f06_l3.png" alt="propability - average delay graph" width="350"/>
</p>

- **Propability - Throughput Graph**
$$ Throughput = \frac{Total Packets Sent}{No. Slots} $$
<p align="center">
<img src="https://quicklatex.com/cache3/37/ql_0660c2e56cb54abec1407362b6f3b037_l3.png" alt="propability - throughput" width="350"/>
</p>

- **Propability - Packet Loss Rate Graph**
$$ Packet Loss Rate = \frac{Total Packets Lost}{Total Packets Created} $$
<p align="center">
<img src="https://quicklatex.com/cache3/be/ql_124e5f170949e8f9ff16400c3ef9cebe_l3.png" alt="propability - packet loss rate" width="350"/>
</p>

### Usage
1. Clone the GitHub repository:
```
git clone https://github.com/stavrmaria/optical-networks-project.git
```
2. Navigate to the project directory:
```
cd optical-networks-project
```
3. Open a terminal and run `make`:
```
make
```
This will execute the commands specified in the Makefile to build the project.
4. Execute the binary file:
```
./optnet
```