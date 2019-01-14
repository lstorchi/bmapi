#!gmake
##################################################
#
# Makefile for bmapi
#
# $Id$
#bmapi
###################################################

include ./config.mk

OBJS = \
	bmapi.o

all: $(OBJS)

clean:
	rm -f $(OBJS)

bmapi.o: bmapi.h
