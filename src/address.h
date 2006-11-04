
#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include <sys/types.h>

enum {
	ADDR_HOST,
	ADDR_RANGE,
	ADDR_NETWORK
};

#define ADDR_STRLEN		32

/* NOTE: all the ip and port are in host order. */
typedef struct _address
{
	unsigned char type;
	union {
		struct {
			u_int32_t ip;
		} host;
		struct {
			u_int32_t begin;
			u_int32_t end;
		} range;
		struct {
			u_int32_t ip;
			u_int32_t mask;
		} network;
	} in;
} address;
address* parse_address(const char *str, int *eat, int *error);
int snprint_address(char *str, size_t size, address *addr);
int match_address(struct sockaddr *sa, address *addr);

#endif /* _ADDRESS_H_ */
