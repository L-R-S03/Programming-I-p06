#-----------------------------------------------------------------------------
# Author:     Lauren Smith
# Student ID: *20504565
# E-Mail:     lsmith147@uco.edu
# Course:     CMSC 1613 - Programming I
# CRN:        10053, Fall, 2021
# Project:    p06
# Due:        November 30 2021
# Account:    tt024
# ---------------------------------------------------------------------------
#p06.cpp    File p06.cpp  processes command line arguments and directs the

#List06.h   File List06.h contains the interface to class List

#List06.cpp File List06.cpp contains the implementation of class List
#p06make    File p06make contains instructions for creating executable file p06 with source files -06.cpp, list06.cpp and List06.h
#---------------------------------------------------------------------------------------------------------------------------------
#object files
#-------------------------------------------------------------------------
obj     =       p06.o List06.o
#-----------------------------------------------------
#Create the executable file p06
#-----------------------------------------------------
p06:            $(obj)
                g++ -o p06 $(obj) -lm
#------------------------------------------------------
#Create p06.o
#------------------------------------------------------
p06.o:          p06.cpp List06.h
                g++ -c -g p06.cpp
#------------------------------------------------------
#Create List06.o
#-----------------------------------------------------
List06.o:       List06.cpp List06.h
                g++ -c -g List06.cpp
