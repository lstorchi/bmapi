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

all: $(LIBNAME) teststate

$(LIBNAME) : $(OBJS) 
	ar -rcs $(LIBNAME) $(OBJS)

teststate: teststate.o
	gcc -o $@ $< -L./ -lbmapiipt -lm

clean:
	rm -f $(OBJS) $(LIBNAME) teststate.o teststate

util.o: ./ptinternal.h 
