# **NanoTekSpice**

This the famous infamous project of tek2. It is written in C++ by [Miouzora](https://github.com/Miou-zora) and [BigT](https://github.com/BigT-Dev)

## What it is ?
**NanoTekSpice** is a logic simulator that builds a graph (the nodes of which will be simulated digital electronic
components, inputs or outputs) from a configuration file, and injects values into that graph to get results.

The main purpose of the project is to virtualize the component of a computer. Then compute of the virtualized hardware.

## How to use it ?

First of make sure to have g++ and make installed.

### Compilation
```
make
```

### Configuration file
```
• input : a component with a single pin directly linked to the command line. Its value is initialized to undefined.
• clock : a component that works like an input, except its value is inverted after each simulation.
• true : a component with a single pin that is always true.
• false : a component with a single pin that is always false.
• output : a component with a single pin used as the output of a circuit.
```

## Execute
```
./nanotekspice (configuration file)
```
### Configuration file
The configuration file looks like this :
```
∼/B-OOP-400> cat -e or_gate.nts
.chipsets:$
input a$
input b$
4071 or$
output s$
.links:$
a:1 or:1$
b:1 or:2$
or:3 s:1$
```
Feel free to create your own. Don't worry the program will tell you if something's wrong.

### Shell
Once launched you'll arrive in a small shell with those commands:
```
• input : a component with a single pin directly linked to the command line. Its value is initialized to undefined.
• clock : a component that works like an input, except its value is inverted after each simulation.
• true : a component with a single pin that is always true.
• false : a component with a single pin that is always false.
• output : a component with a single pin used as the output of a circuit.
```

## Wanna contribute ?
Before anything please read the `CONTRIBUTING.md` file. Then let's work together !!
