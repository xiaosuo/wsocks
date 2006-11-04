
#ifndef _BASE64_H_
#define _BASE64_H_

/*
 * @brief encode a string with base64 method.
 * @return the result, the value should be freed
 * 		   after using it.
 */
const char* base64_encode(const char *str, int length, int *retlen);
const char* base64_decode(const char *str, int length, int *retlen);

#endif /* _BASE64_H_ */
