
#include <stdlib.h>
#include <dlfcn.h>
#include <assert.h>
#include <string.h>

#include "misc.h"
#include "list.h"
#include "acl_act.h"

/* request the acl action module through the module name.
 * if the module isn't pressent in the acl, load it dynamic,
 * and add it to the acl for using it */
acl_act_module_t* request_acl_act_module(
		acl_t *acl,
		const char *ptr,
		int len)
{
	struct list *i;
	acl_act_module_t *aam;
	void *handle;
	acl_act_module_register_t *aam_reg;
	char name[32];
	char path[256];

	/* find it in the acl */
	list_for_each(i, &acl->act_mod){
		aam = ACL_ACT_MODULE_PTR(i->data);
		if(strlen(aam->name) != len)
			continue;
		if(strncmp(aam->name, ptr, len) == 0)
			return aam;
	}

	if(len >= sizeof(name))
		return NULL;
	snprintf(name, len + 1, ptr);
	 /* find it in the act_path */
	list_for_each(i, &acl->act_path){
		snprintf(path, sizeof(path), "%s/%s.so",
				(const char*)(i->data),
				name);
		handle = dlopen(path, RTLD_LAZY);
		if(handle)
			goto add;
	}

	return NULL;

add:
	aam = NULL;
	aam_reg = dlsym(handle, "acl_act_module_register");
	if(!aam_reg)
		goto done;
	aam = aam_reg();
	if(!aam)
		goto done;
	list_append(&acl->act_mod, aam, NULL);

done:
	if(!aam && dlclose(handle) != 0)
		abort();

	return aam;
}

acl_act_t* acl_act_new(void)
{
	acl_act_t *aa;

	aa = malloc(sizeof(*aa));
	if(!aa)
		return NULL;
	memset(aa, 0, sizeof(*aa));

	return aa;
}

void acl_act_free(acl_act_t *aa)
{
	assert(aa);

	if(aa->mod && aa->mod->free)
		aa->mod->free(aa->priv);

	free(aa);
}
