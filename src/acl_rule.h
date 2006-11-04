
#ifndef _ACL_RULE_H_
#define _ACL_RULE_H_

#include "list.h"

typedef struct acl_rule
{
	struct list cond;
	struct list act;
} acl_rule_t;

#define ACL_RULE_PTR(x) ((acl_rule_t*)(x))

acl_rule_t* acl_rule_new(void);
void acl_rule_free(acl_rule_t *ar);

#endif /* _ACL_RULE_H */
