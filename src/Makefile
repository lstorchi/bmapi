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

LIBNAME = libbmapi.a

OBJS = \
	bmapi.o \
	bmapi_util.o

all: $(OBJS)
	ar -rcs $(LIBNAME) $(OBJS)

clean:
	rm -f $(OBJS) $(LIBNAME)

bmapi.o: ../include/bmapi.h ../include/bm_defined.h
bmapi_util.o: ../include/bmapi.h ../include/bm_defined.h
