#ifndef COMPILER_H
#define COMPILER_H

#include "git-compat-util.h"
#include "strbuf.h"

#ifdef __GLIBC__
#include <gnu/libc-version.h>
<<<<<<< HEAD

static inline void get_compiler_info(struct strbuf *info)
{
	strbuf_addf(info, "glibc: %s", gnu_get_libc_version());
}

#else

static inline void get_compiler_info(struct strbuf *info)
{
	strbuf_addstr(info, "get_compiler_info() not implemented");
}

#endif

=======
#endif

static inline void get_compiler_info(struct strbuf *info)
{
	int len = info->len;
#ifdef __GNUC__
	strbuf_addf(info, "gnuc: %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

#ifdef _MSC_VER
	strbuf_addf(info, "MSVC version: %02d.%02d.%05d\n",
		    _MSC_VER / 100, _MSC_VER % 100, _MSC_FULL_VER % 100000);
#endif

	if (len == info->len)
		strbuf_addstr(info, _("no compiler information available\n"));
}

static inline void get_libc_info(struct strbuf *info)
{
	int len = info->len;

#ifdef __GLIBC__
	strbuf_addf(info, "glibc: %s\n", gnu_get_libc_version());
#endif

	if (len == info->len)
		strbuf_addstr(info, _("no libc information available\n"));
}

>>>>>>> upstream/pu
#endif /* COMPILER_H */
