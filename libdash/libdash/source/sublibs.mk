LIBDIR=../libs
OBJECTS=$(SOURCES:.cpp=.o)
DIRNAME=$(shell basename $(shell pwd))
LIBRARY=$(LIBDIR)/lib$(DIRNAME).a

all: $(SOURCES) $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	mkdir -p $(LIBDIR) 
	rm -f $@
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

distclean: clean
	rm -f $(LIBRARY)
	if test -d $(LIBDIR); then \
		rmdir --ignore-fail-on-non-empty $(LIBDIR) ; \
	fi
