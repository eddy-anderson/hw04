

EDITOR = /usr/bin/gedit
INDENT = /usr/bin/indent

CC        = clang
LDFLAGS   = -o
Libs      = -lm
CFLAGS    = -Weverything $(LDFLAGS)
SOURCES   = indented_circle.c
EXECUTABLE= indented_circle
OBJECTS=$(SOURCES:.c=.o)

.SUFFIXES:
.SUFFIXES:  .c .o .h

.PHONY: edit clean veryclean

target    = inscribed_circle

all: $(target)

$(target): $(target).c
	$(CC) $(target).c $(CFLAGS) $(target) $(Libs)\
	
    

edit : $(target).c
	$(EDITOR) $<
	$(INDENT) $<

clean : 
	rm -f *.o
	rm -f *.*~

veryclean : clean
	rm  -f $(target)
