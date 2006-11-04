
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "acl_act.h"

static void* BYPASS_parse(const char *str, int *eat, int *error)
{
	if(eat) *eat = 0;
	if(error) *error = 0;

	return NULL;
}

static int BYPASS_snprint(char *str, size_t size, void *priv)
{
	return snprintf(str, size, " ");
}

static int BYPASS_target(void *param, void *priv)
{
	return 0;
}

static void BYPASS_free(void *priv)
{
}

static acl_act_module_t ac_BYPASS = {
	.name		= "BYPASS",
	.parse		= ACL_PARSE_PTR(&BYPASS_parse),
	.snprint	= ACL_SNPRINT_PTR(&BYPASS_snprint),
	.target		= ACL_TARGET_PTR(&BYPASS_target),
	.free		= ACL_FREE_PTR(&BYPASS_free),
};

ACL_ACT_MODULE_DCLR(ac_BYPASS);
