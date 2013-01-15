include defaults.mk
CFLAGS+=-I/usr/include/libxml2
SOURCES=Helper.cpp libdash.cpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBDIR=../../bin
SUBLIBDIR=libs
SUBDIRS=adaptationlogic buffer http manager mpd statistics xml portable
SUBLIBS=$(SUBDIRS:%=$(SUBLIBDIR)/lib%.a)
SUBOBJS=$(SUBDIRS:%=%/*.o)
LIBRARY=$(LIBDIR)/$(LIBNAME).so
LIBRARY_S=$(LIBRARY:%.so=%.a)

default: $(SOURCES) $(LIBRARY)

static: $(SOURCES) $(LIBRARY_S)

all: $(SOURCES) $(LIBRARY_S) $(LIBRARY)

$(LIBRARY_S): $(OBJECTS) $(SUBLIBS)
	mkdir -p $(LIBDIR) 
	rm -f $(@)
	$(AR) $(ARFLAGS) $(LIBRARY_S) $(OBJECTS) $(SUBOBJS)

$(LIBRARY): $(SUBLIBS) $(OBJECTS)
	mkdir -p $(LIBDIR) 
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) -Wl,--whole-archive $(SUBLIBS) -Wl,--no-whole-archive

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

$(SUBLIBDIR)/lib%.a: %
	make -C $<

clean:
	rm -f $(OBJECTS)
	for dir in $(SUBDIRS); do \
		make -C $$dir $@ ;\
	done

distclean: clean
	for dir in $(SUBDIRS); do \
		make -C $$dir $@ ;\
	done
	rm -f $(LIBRARY_S)
	rm -f $(LIBRARY)
	if test -d $(LIBDIR); then \
		rmdir --ignore-fail-on-non-empty $(LIBDIR) ; \
	fi
