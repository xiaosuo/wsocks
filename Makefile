
WSOCKS_PREFIX = /usr/local
export WSOCKS_PREFIX

.PHONY: clean all install

all:
	@make -C src

clean:
	@make -C src clean

install:
	@make -C src install

uninstall:
	@make -C src uninstall
