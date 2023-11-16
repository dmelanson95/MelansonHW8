"""

computeFunction.py

Function created by David Melanson for IoT Homework 8 Problem 4.1
Function that outputs x and x^2+2 for the numbers 0 to 9
Function takes no command line arguments
To invoke - python3 computeFunction.py
"""

[print(f"x = {x}\tf(x) = {x*x+2}") for x in range(10)]
