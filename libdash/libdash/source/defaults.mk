LIBNAME=libdash
CC=g++
AR=ar
LD=g++
ARFLAGS=-cr
CFLAGS=-fPIC -c -Wall #-DDEBUG
LDFLAGS=-shared -Wl,-soname,$(LIBNAME).so
