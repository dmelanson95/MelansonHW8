"""

cube.py

Function created by David Melanson for IoT Homework 8 Problem 4.
Function takes no command line arguments.
Function outputs even numbers in the range 0 to 19 and all odd numbers cubed in same range.
To invoke - python3 cube.py
"""

[print(x*x*x) if x%2 else print(x) for x in range(20)]
