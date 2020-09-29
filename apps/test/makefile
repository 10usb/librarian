# Test
include ../../makefile.in
OUTPUT=bin/db
SOURCES=main.cpp
DEPENDANCIES=libbase libstorage
TEMP=obj
OBJECTS=$(patsubst %.cpp,$(TEMP)/%.o,$(patsubst %.c,$(TEMP)/%.o,$(SOURCES)))
TARGET=$(OUTPUT)$(SUFFIX)
CFLAGS=-I$(INCLUDES)
LIBS=$(foreach x, $(DEPENDANCIES), $(ROOT)obj/$(x).o)

build: dependencies $(TARGET)

rebuild: clean-all dependencies $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS) $(LIBS)

clean-all: clean
	@$(foreach x,$(DEPENDANCIES),$(MAKE) --no-print-directory -C $(ROOT)$(x) clean OUTPUT=$(ROOT)obj/$(x).o;)

$(TARGET): $(OBJECTS) $(LIBS) | $(dir $(TARGET))
	$(CPP) -o $@ $(OBJECTS) $(LIBS)

$(TEMP)/%.o: src/%.cpp | $(TEMP)
	$(CPP) -c $(CFLAGS) -o $@ $<

$(TEMP)/%.o: src/%.c | $(TEMP)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TEMP) $(dir $(TARGET)):
	mkdir $@

$(LIBS):
	@$(MAKE) --no-print-directory -C $(@:$(ROOT)obj/%.o=$(ROOT)%) OUTPUT=$@

dependencies:
	@$(foreach x,$(DEPENDANCIES),$(MAKE) --no-print-directory -C $(ROOT)$(x) OUTPUT=$(ROOT)obj/$(x).o;)

.PHONY: build rebuild clean clean-all dependencies