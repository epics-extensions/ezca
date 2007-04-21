#*************************************************************************
# Copyright (c) 2002 The University of Chicago, as Operator of Argonne
# National Laboratory.
# Copyright (c) 2002 The Regents of the University of California, as
# Operator of Los Alamos National Laboratory.
# This file is distributed subject to a Software License Agreement found
# in the file LICENSE that is included with this distribution. 
#*************************************************************************
#
# $Id$
#
TOP = ../..
#If epics/extensions/configure directory exists, build with it.
#Otherwise use epics/extensions/config.
ifeq (0, $(words $(notdir $(wildcard $(TOP)/configure))))
include $(TOP)/config/CONFIG_EXTENSIONS
include $(TOP)/config/RULES_ARCHS
else
include $(TOP)/configure/CONFIG

# Use the following line if building ezca to be called from
# Visual Basic or other languages
#SHARED_LIBRARIES=YES
# Use the following line to build EzcaScan and ezcaIDL as
# standlone DLLs, i.e. without the need for ezca.dll in the path.
SHARED_LIBRARIES=NO
INC += ezca.h
LIBRARY_HOST = ezca
ezca_SRCS = ezca.c
ezca_LIBS += ca Com
ezca_SYS_LIBS_WIN32 = ws2_32 advapi32 user32

include $(TOP)/configure/RULES
endif
