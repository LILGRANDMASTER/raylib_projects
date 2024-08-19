BINARY   := main.exe 
SOURCE   := ./src
INCLUDE  := ./include/
BUILDDIR := ./build

HEADERS := /mingw64/include
LIBPATH := /mingw64/lib

CC       ?= gcc
OPT      := O0
DEPFLAGS := -MD

CFLAGS := $(foreach D, $(HEADERS), -I$(D))
CFLAGS += $(foreach D, $(INCLUDE), -I$(D))
CFLAGS += -Wall -Wextra -O0 -g

CFILES   := $(foreach D, $(SOURCE), $(wildcard $(D)/*.c))
OBJECTS  := $(patsubst %.c, $(BUILDDIR)/%.o, $(notdir $(CFILES)))
DEPFILES := $(patsubst %.c, %.d, $(CFILES))

LIBS := $(foreach D, $(LIBPATH), -L$(D))
LIBS += -lraylib


all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $^ -o $@ $(LIBS)

$(BUILDDIR)/%.o: $(SOURCE)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ 
