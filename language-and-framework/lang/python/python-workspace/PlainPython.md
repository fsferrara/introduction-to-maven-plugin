# Working with Python

## Prerequisites

I am using python `3.6` ;-) so:
`sudo apt-get install python3` and `sudo apt-get install python3-pip`.


## VS Code

Install the `python` extension.
Then create a new workspace with [this guide](https://code.visualstudio.com/docs/python/python-tutorial#_prerequisites).


## Python Packages

*Packages* are how we obtain useful libraries, typically from [PyPI](https://pypi.org/).
For instance, to install `numpy`, do it with pip: `python3 -m pip install numpy`


## Plotting with matplolib

In the data science domain, it is common to plot data. Matplot is used in this case:
`python3 -m pip install matplotlib`

If using Linux, then you need to install `python3-tk` as well:
`sudo apt-get install python3-tk`
*tk* stands for _Tkinter_ and is Python's de-facto standard GUI (Graphical User Interface) package.


## Virtual Environment

To avoid installing python libraries and tools in the gobal environment, you can set-up a virtual environment.
You'l need venv for this: `sudo apt-get install python3-venv`.

Go to the project folder (not the workspace folder) and type: `python3 -m venv env`.
Hint. open that folder as VS Code project.

To enable the virtual env:
`source ./env/bin/activate`

Then install what you need:
`(env) $> python -m pip install matplotlib`
