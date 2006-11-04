
#include <stdlib.h>
#include <assert.h>

#include "list.h"
#include "acl_rule.h"

acl_rule_t* acl_rule_new(void)
{
	acl_rule_t *ar;

	ar = malloc(sizeof(*ar));
	if(!ar)
		return NULL;
	list_init(&ar->cond, NULL);
	list_init(&ar->act, NULL);

	return ar;
}

void acl_rule_free(acl_rule_t *ar)
{
	assert(ar);

	list_free(&ar->cond);
	list_free(&ar->act);
	free(ar);
}
