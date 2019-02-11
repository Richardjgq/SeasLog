/*
  +----------------------------------------------------------------------+
  | SeasLog                                                              |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Chitao Gao  <neeke@php.net>                                  |
  +----------------------------------------------------------------------+
*/

#if PHP_VERSION_ID >= 70000

# define SEASLOG_MAKE_ZVAL(z) zval _stack_zval_##z; z = &(_stack_zval_##z)

# define SEASLOG_ZVAL_STRING(z, s) ZVAL_STRING(z, s)
# define SEASLOG_ZVAL_STRINGL(z, s, l) ZVAL_STRINGL(z, s, l)
# define SEASLOG_RETURN_STRINGL(k, l) RETURN_STRINGL(k, l)
# define SEASLOG_ADD_INDEX_STRINGL(z, i, s, l) add_index_stringl(&z, i, s, l)
# define SEASLOG_ADD_INDEX_LONG(z, i, l) add_index_long(&z, i, l)
# define SEASLOG_ADD_INDEX_ZVAL(z, i, zn) add_index_zval(&z, i, &zn)
# define SEASLOG_ADD_ASSOC_ZVAL_EX(z, s, l, zn) add_assoc_zval_ex(&z, s, l, &zn)
# define SEASLOG_ADD_ASSOC_ZVAL_EX_EX(z, sl, zn) add_assoc_zval_ex(&z, sl, &zn)
# define SEASLOG_ADD_ASSOC_STRING_EX(a, k, s) add_assoc_string_ex(&a, k, s)
# define SEASLOG_ADD_ASSOC_LONG_EX(a, k, l) add_assoc_long_ex(&a, k, l)
# define SEASLOG_ADD_ASSOC_DOUBLE_EX(a, k, d) add_assoc_double_ex(&a, k, d)
# define SEASLOG_ADD_NEXT_INDEX_STRING(a, s) add_next_index_string(a, s)
# define SEASLOG_ADD_NEXT_INDEX_STRINGL(a, s, l) add_next_index_stringl(a, s, l)
# define SEASLOG_ADD_NEXT_ZVAL(a, z) add_next_index_zval(&a, &z)
# define SEASLOG_ZEND_HASH_INDEX_ADD(ht, h, pData, nDataSize) zend_hash_index_add_ptr(ht, h, pData)
# define SEASLOG_ZEND_HASH_GET_CURRENT_KEY(ht, key, idx) zend_hash_get_current_key(ht, key, idx)
# define SEASLOG_ZEND_HASH_INDEX_UPDATE(ht, h, pData, nDataSize, pDest)  zend_hash_index_update_ptr(ht, h, pData)
# define SEASLOG_SMART_STR_C(str) ZSTR_VAL(str.s)
# define SEASLOG_SMART_STR_L(str) ZSTR_LEN(str.s)
# define SEASLOG_AUTO_GLOBAL(n) zend_is_auto_global_str(ZEND_STRL(n) TSRMLS_CC)
# define SEASLOG_ZVAL_PTR_DTOR(z) zval_ptr_dtor(z)

# define SEASLOG_EXPAND_FILE_PATH(dir, buf) expand_filepath_with_mode(dir, buf, NULL, 0, CWD_EXPAND)

# define STR_NAME_VAL(k) estrdup((k)->val)
# define STR_NAME_LEN(k) (k)->len

# define SEASLOG_STRS(s)  s, strlen(s)

# define SEASLOG_ARRAY_INIT(z) array_init(&z)

# define SEASLOG_ARRAY_DESTROY(arr) \
	do { \
		if (IS_ARRAY == Z_TYPE(arr)) { \
            zval_ptr_dtor(&(arr)); \
            ZVAL_NULL(&(arr)); \
		} \
	} while(0)

# define SEASLOG_JSON_ENCODE(buf, zval, options) php_json_encode(buf, &zval, options TSRMLS_CC)

#else

# define SEASLOG_MAKE_ZVAL(z) MAKE_STD_ZVAL(z)
# define SEASLOG_ZVAL_STRING(z, s) ZVAL_STRING(z, s, 0)
# define SEASLOG_ZVAL_STRINGL(z, s, l) ZVAL_STRING(z, s, l, 1)
# define SEASLOG_RETURN_STRINGL(k, l) RETURN_STRINGL(k, l, 1)
# define SEASLOG_ADD_INDEX_STRINGL(z, i, s, l) add_index_stringl(z, i, s, l, 1)
# define SEASLOG_ADD_INDEX_LONG(z, i, l) add_index_long(z, i, l)
# define SEASLOG_ADD_INDEX_ZVAL(z, i, zn) add_index_zval(z, i, zn)
# define SEASLOG_ADD_ASSOC_ZVAL_EX(z, s, l, zn) add_assoc_zval_ex(z, s, l, zn)
# define SEASLOG_ADD_ASSOC_ZVAL_EX_EX(z, sl, zn) add_assoc_zval_ex(z, sl, zn)
# define SEASLOG_ADD_ASSOC_STRING_EX(a, k, s) add_assoc_string_ex(a, k, s, 1)
# define SEASLOG_ADD_ASSOC_LONG_EX(a, k, l) add_assoc_long_ex(a, k, l)
# define SEASLOG_ADD_ASSOC_DOUBLE_EX(a, k, d) add_assoc_double_ex(a, k, d)
# define SEASLOG_ADD_NEXT_INDEX_STRING(a, s) add_next_index_string(a, s, 1)
# define SEASLOG_ADD_NEXT_INDEX_STRINGL(a, s, l) add_next_index_stringl(a, s, l, 1)
# define SEASLOG_ADD_NEXT_ZVAL(a, z) add_next_index_zval(a, z)
# define SEASLOG_ZEND_HASH_INDEX_ADD(ht, h, pData, nDataSize) zend_hash_index_update(ht, h, pData, nDataSize, NULL)
# define SEASLOG_ZEND_HASH_GET_CURRENT_KEY(ht, key, idx) zend_hash_get_current_key(ht, key, idx, 0)
# define SEASLOG_ZEND_HASH_INDEX_UPDATE(ht, h, pData, nDataSize, pDest)  zend_hash_index_update(ht, h, pData, nDataSize, pDest)
# define SEASLOG_SMART_STR_C(str) str.c
# define SEASLOG_SMART_STR_L(str) str.len
# define SEASLOG_AUTO_GLOBAL(n) zend_is_auto_global(n, sizeof(n)-1 TSRMLS_CC)
# define SEASLOG_ZVAL_PTR_DTOR(z) zval_ptr_dtor(&z)

# if PHP_API_VERSION >= 20100412
# define SEASLOG_EXPAND_FILE_PATH(dir, buf) expand_filepath_with_mode(dir, buf, NULL, 0, CWD_EXPAND TSRMLS_CC)
# else
# define SEASLOG_EXPAND_FILE_PATH(dir, buf) expand_filepath_ex(dir, buf, NULL, 0 TSRMLS_CC)
# endif

# define STR_NAME_VAL(k) (char *)(estrdup(k))
# define STR_NAME_LEN(k) (k ## _length)

# define SEASLOG_STRS(s)  ZEND_STRS(s)

# define SEASLOG_ARRAY_INIT(z) MAKE_STD_ZVAL(z);array_init(z)

# define SEASLOG_ARRAY_DESTROY(arr) \
	do { \
		if (arr && IS_ARRAY == Z_TYPE_P(arr)) { \
            zval_ptr_dtor(&(arr)); \
		} \
	} while(0)

#if PHP_VERSION_ID < 50300
# define SEASLOG_JSON_ENCODE(buf, zval, options) php_json_encode(buf, zval TSRMLS_CC)
#else
# define SEASLOG_JSON_ENCODE(buf, zval, options) php_json_encode(buf, zval, options TSRMLS_CC)
#endif

#endif

