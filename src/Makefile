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

OBJS = \
	bmapi.o \
	bmapi_util.o

all: $(OBJS)

clean:
	rm -f $(OBJS)

bmapi.o: ../include/bmapi.h ../include/bm_defined.h
bmapi_util.o: ../include/bmapi.h ../include/bm_defined.h
