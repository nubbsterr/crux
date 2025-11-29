# makefiles are amazing
CC = gcc
SRC = crux.c

TARGET = crux
CFLAGS = -Wall -O2

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	@echo "Cleaning up..."
	rm -f $(TARGET)

install: $(TARGET)
	@echo "Creating $(BINDIR) directory..."
	mkdir -p $(BINDIR)
	@echo "Installing $(TARGET) to $(BINDIR)..."
	install -m 755 $(TARGET) $(BINDIR)

uninstall:
	@echo "Uninstalling $(TARGET) from $(BINDIR)..."
	rm -f $(BINDIR)/$(TARGET)

.PHONY: all clean install uninstall

