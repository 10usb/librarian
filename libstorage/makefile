# Library Storage
include ../makefile.in
OUTPUT=bin/libstorage.o
SOURCES=table.cpp index.cpp file.cpp structure.cpp
TEMP=obj
OBJECTS=$(patsubst %.cpp,$(TEMP)/%.o,$(patsubst %.c,$(TEMP)/%.o,$(SOURCES)))
CFLAGS=-I$(INCLUDES) -MMD -MP
DEPS=$(OBJECTS:.o=.d)

build: $(OUTPUT)

rebuild: clean $(OUTPUT)

clean:
	$(RM) $(OUTPUT) $(OBJECTS) $(DEPS)

$(OUTPUT): $(OBJECTS) | $(dir $(OUTPUT))
	$(LD) -i -o $@ $(OBJECTS)

$(TEMP)/%.o: src/%.c | $(TEMP)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TEMP)/%.o: src/%.cpp | $(TEMP)
	$(CPP) -c $(CFLAGS) -o $@ $<

$(TEMP) $(dir $(OUTPUT)):
	mkdir $@

-include $(DEPS)

.PHONY: build rebuild clean