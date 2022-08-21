CC = gcc
CFLAGS = -Wall -s -DNDEBUG
DEBUGFLAGS = -Wall -g
HEADERS = bank_utils.h colors.h ascii_art.h clear_buffer.h
BANKNAME = bank
APPNAME = coincasino

all: $(BANKNAME) $(APPNAME)
debug: $(BANKNAME).debug $(APPNAME).debug

$(APPNAME): $(APPNAME).c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(BANKNAME): $(BANKNAME).c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(APPNAME).debug: $(APPNAME).c $(HEADERS)
	$(CC) $(DEBUGFLAGS) $< -o $@

$(BANKNAME).debug: $(BANKNAME).c $(HEADERS)
	$(CC) $(DEBUGFLAGS) $< -o $@

clean:
	rm -f $(APPNAME) $(BANKNAME) a.out $(APPNAME).debug $(BANKNAME).debug

run: $(APPNAME)
	@./$(APPNAME)
	@rm $(APPNAME)
