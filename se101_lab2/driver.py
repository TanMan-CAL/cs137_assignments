#!/usr/bin/env python
################################################################################
#
# Test driver for "triangle" program
# Reads file "./testCaseInputs.txt where each line is of the form:
#       <testcase number> <inputs>? <expected output>
# 

DEBUG = False

import re                                         # Regular expressions
from subprocess import Popen, PIPE                # Spawn process; get results
import subprocess                                 # Do we need this?
import random                                     # Random numbers

inputs = open('testCaseInputs.txt').read()
inputs = [item.split(',') for item in inputs.split('\n')[:-1]]
for args in inputs:
    caseNo = args[0]
    expectedAnswer = args[len(args) - 1]
    command = ["./triangle"];
    i = 1
    while (i < len(args)-1):
        command.append(str(args[i]));
        i += 1

    if DEBUG:
        print(f"Testcase: {caseNo}")
        print(f"Command: {command}")
        print(f"Expected Answer: {expectedAnswer}")
        
    cproc = subprocess.Popen(command, stdin=PIPE, stdout=PIPE, stderr=PIPE)
    out, err = cproc.communicate()

    output = out.decode('utf-8') if isinstance(out, bytes) else str(out)
    errOut = err.decode('utf-8') if isinstance(out, bytes) else str(out)

    # Match against stdout and against stderr
    match = re.search(expectedAnswer,output)
    errMatch = re.search(expectedAnswer,errOut)
    
    if DEBUG:
        print(f"match: '{match}'\nerrMatch: '{errMatch}'")
        print(f"Output: {output}")
        print(f"ErrOut: {errOut}")
        
    if match:
        print(f"Testcase {caseNo} passed")
    elif errMatch:
        print(f"Testcase {caseNo} passed")        
    else:
        print(f"Testcase {caseNo} failed")
        print(f"Command: {command}")
        print(f"Output: '{output}'")
        print(f"ErrOut: '{errOut}'")
        print(f"Expected: '{expectedAnswer}'")

    if DEBUG:
        print("")
exit(0)
