#ifndef PHP_PCSC_H
#define PHP_PCSC_H

extern zend_module_entry pcsc_module_entry;
#define phpext_pcsc_ptr &pcsc_module_entry

#define PHP_PCSC_VERSION "0.3"

#ifdef PHP_WIN32
#define PHP_PCSC_API __declspec(dllexport)
#else
#define PHP_PCSC_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(pcsc);
PHP_MSHUTDOWN_FUNCTION(pcsc);
PHP_MINFO_FUNCTION(pcsc);

PHP_FUNCTION(scard_establish_context);
PHP_FUNCTION(scard_is_valid_context);
PHP_FUNCTION(scard_release_context);
PHP_FUNCTION(scard_list_readers);
PHP_FUNCTION(scard_connect);
//PHP_FUNCTION(scard_reconnect);
PHP_FUNCTION(scard_disconnect);
PHP_FUNCTION(scard_status);
PHP_FUNCTION(scard_transmit);
//PHP_FUNCTION(scard_cancel);

#define PHP_PCSC_CTX_RES_NAME "PC/SC Context"
#define PHP_PCSC_CONN_RES_NAME "PC/SC Connection"

static char* php_pcsc_error_to_string(LONG dwRC);

#endif	/* PHP_PCSC_H */
