
CC := gcc #-g
CFLAGS += -fPIC -Wall -D__WSOCKS_THREAD \
		  #-D__WSOCKS_DNS -DDEBUG

WSOCKS_LIB_PATH := $(WSOCKS_PREFIX)/lib/wsocks
WSOCKS_COND_PATH := $(WSOCKS_LIB_PATH)/cond
WSOCKS_ACT_PATH := $(WSOCKS_LIB_PATH)/act
WSOCKS_CFG_PATH := $(WSOCKS_PREFIX)/etc
WSOCKS_BIN_PATH := $(WSOCKS_PREFIX)/bin

all: config libwsocks.so service.so address.so any.so BYPASS.so \
	HTTP.so SOCKS4.so SOCKS5.so wsocks

.PHONY: strip clean uninstall

config:
	printf "#ifndef _CONFIG_H_ \n\
		#define _CONFIG_H_ \n\
		#define WSOCKS_PREFIX \"$(WSOCKS_PREFIX)\" \n\
		#endif\n" > config.h

wsocks: main.c
	$(CC) -o $@ $^

libwsocks.so: misc.o list.o base64.o url.o \
			acl.o acl_cond.o acl_act.o acl_rule.o wsocks.o
	$(LD) -o $@ -shared -$(LD)l -lpthread --version-script symver.script $^

address.so: misc.o address.o
	$(LD) -o $@ -shared $^

service.so: service.o
	$(LD) -o $@ -shared $^

any.so: any.o
	$(LD) -o $@ -shared $^

HTTP.so: misc.o url.o base64.o HTTP.o
	$(LD) -o $@ -shared $^

BYPASS.so: BYPASS.o
	$(LD) -o $@ -shared $^

SOCKS4.so: misc.o url.o SOCKS4.o
	$(LD) -o $@ -shared $^

SOCKS5.so: misc.o url.o SOCKS5.o
	$(LD) -o $@ -shared $^

install: all
	install -d $(WSOCKS_LIB_PATH)
	install -d $(WSOCKS_COND_PATH)
	install -d $(WSOCKS_ACT_PATH)
	install -d $(WSOCKS_BIN_PATH)
	install libwsocks.so $(WSOCKS_LIB_PATH)/
	install any.so address.so service.so $(WSOCKS_COND_PATH)/
	install BYPASS.so HTTP.so SOCKS4.so SOCKS5.so $(WSOCKS_ACT_PATH)/
	install wsocks $(WSOCKS_BIN_PATH)/

uninstall:
	rm -rf $(WSOCKS_LIB_PATH)
	rm -rf $(WSOCKS_BIN_PATH)/wsocks

clean:
	rm -f *.o *.so wsocks

strip:
	strip -s *.so
