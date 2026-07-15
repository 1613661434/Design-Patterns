CXX       = g++
CXXFLAGS  = -std=c++17 -Wall -Wextra
TARGET    = adapter
SRC       = src/main.cpp
INC       = -Iinclude
OUTDIR    = output
OUTPUT    = $(OUTDIR)/$(TARGET)

.PHONY: all run clean

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	@cmd /c "@echo off && if not exist \"$(OUTDIR)\" mkdir \"$(OUTDIR)\""
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

run: $(OUTPUT)
	$(OUTPUT)

clean:
	@cmd /c "@echo off && if exist \"$(OUTDIR)\" rmdir /s /q \"$(OUTDIR)\""
