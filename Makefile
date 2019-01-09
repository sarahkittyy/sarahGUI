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
LINKFLAGS = -o $(OUTDIR)/$(EXECUTABLE) -lstdc++ -lsfml-window -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system 

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

docs:
	doxygen

all: $(OBJECTS)
	$(CC) $(LINKFLAGS) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CCFLAGS) $^ -o $@