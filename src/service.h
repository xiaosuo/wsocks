
#ifndef _SERVICE_H_
#define _SERVICE_H_

enum {
	SERV_PORT,
	SERV_RANGE
};

#define SERV_STRLEN	12

typedef struct _service
{
	unsigned char type;
	union {
		struct {
			u_int16_t port;
		} serv;
		struct {
			u_int16_t begin;
			u_int16_t end;
		} range;
	} data;
} service;
service* parse_service(const char *str, int *eat, int *error);
int snprint_service(char *str, size_t size, service *serv);
int match_service(struct sockaddr *sa, service *serv);

#endif /* _CHAIN_H_ */
