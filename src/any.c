
#include <stdlib.h>
#include <stdio.h>

#include "acl_cond.h"

static void* any_parse(const char *str, int *eat, int *error)
{
	if(eat) *eat = 0;
	if(error) *error = 0;

	return NULL;
}

static int any_snprint(char *str, size_t size, void *priv)
{
	return snprintf(str, size, " ");
}

static int any_match(void *param, void *priv)
{
	return 0;
}

static void any_free(void *priv)
{
}

static acl_cond_module_t ac_any = {
	.name		= "any",
	.parse		= ACL_PARSE_PTR(&any_parse),
	.snprint	= ACL_SNPRINT_PTR(&any_snprint),
	.match		= ACL_MATCH_PTR(&any_match),
	.free		= ACL_FREE_PTR(&any_free),
};

ACL_COND_MODULE_DCLR(ac_any);
