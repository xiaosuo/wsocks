
#ifndef _MISC_H_
#define _MISC_H_

#include <sys/types.h>

int valid_ip(const char *str);
u_int32_t num_to_netmask(int num);
int netmask_to_num(u_int32_t mask);
int block_save_flags(int fd);
int restore_flags(int fd, int flags);
ssize_t send_ni(int s, const void *buf, size_t len, int flags);
ssize_t recv_ni(int s, void *buf, size_t len, int flags);

#define skip_blank(ptr) \
	do{ \
		while(*ptr == ' ' || *ptr == '\t') \
			ptr ++; \
	}while(0)

#define skip_word(ptr) \
	do{ \
		while(*ptr != '\0' && *ptr != ' ' && *ptr !=  '\t') \
			ptr ++; \
	}while(0)

#endif /* _MISC_H */
