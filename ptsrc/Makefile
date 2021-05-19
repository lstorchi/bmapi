#!gmake
##################################################
#
# Makefile for bmapi
#
# $Id$
#bmapi
###################################################

include ../config.mk

CFLAGS=-I../include

LIBNAME = libbmapiipt.a

OBJS = \
	util.o 

all: $(OBJS)
	ar -rcs $(LIBNAME) $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)

util.o: ./ptinternal.h 
