
#ifndef _URL_H_
#define _URL_H_

typedef struct short_url
{
	char	*host;
	int		port;
	char	*user;
	char	*password;
} short_url_t;

short_url_t* short_url_new(void);
int short_url_parse(short_url_t *surl, const char *url_str, int *eat);
const char* short_url_to_string(short_url_t *surl);
short_url_t* short_url_new_from_string(const char *url_str, int *eat);
void short_url_free(short_url_t *url);

#endif /* _URL_H_ */
