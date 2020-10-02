# Library Base
include ../makefile.in
OUTPUT=bin/libbase.o
SOURCES=hash.cpp basicset.cpp datatype.cpp
TEMP=obj
OBJECTS=$(patsubst %.cpp,$(TEMP)/%.o,$(patsubst %.c,$(TEMP)/%.o,$(SOURCES)))
CFLAGS=-I$(INCLUDES)

build: $(OUTPUT)

rebuild: clean $(OUTPUT)

clean:
	$(RM) $(OUTPUT) $(OBJECTS)

$(OUTPUT): $(OBJECTS) | $(dir $(OUTPUT))
	$(LD) -i -o $@ $(OBJECTS)

$(TEMP)/%.o: src/%.c | $(TEMP)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TEMP)/%.o: src/%.cpp | $(TEMP)
	$(CPP) -c $(CFLAGS) -o $@ $<

$(TEMP) $(dir $(OUTPUT)):
	mkdir $@

.PHONY: build rebuild clean test