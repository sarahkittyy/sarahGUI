SRCDIR = src
OBJDIR = obj
OUTDIR = bin
INCDIR = include
HDRDIR = header
EXECUTABLE = gui

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

CC = g++
CCFLAGS = -c -Wall -Wno-unused-variable -I$(INCDIR)/ -I$(HDRDIR)/

LIBRARIES = -lstdc++ -lsfml-window -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
LIBRARIES-DEBUG = -lstdc++ -lsfml-window-d -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-network-d -lsfml-system-d
LINKFLAGS = -o $(OUTDIR)/$(EXECUTABLE)

clean:
	@rm $(OUTDIR)/$(EXECUTABLE) || true
	@rm $(OBJDIR)/* || true
	printf "Cleaned!\n"

zip:
	@zip -r GUI.zip .

run: all
	clear
	@printf "##Running##\n\n"
	@cd bin; ./gui
	@printf "\n"

run_debug: debug
	clear
	@printf "##Running Debug##\n\n"
	@cd bin; gdb gui
	@printf "\n"

docs:
	doxygen

all: $(OBJECTS)
	$(CC) $(LINKFLAGS) $(LIBRARIES) $(OBJECTS)

debug: $(OBJECTS)
	$(CC) $(LINKFLAGS) $(LIBRARIES-DEBUG) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CCFLAGS) $^ -o $@