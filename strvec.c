#include "cache.h"
#include "strvec.h"
#include "strbuf.h"

const char *empty_strvec[] = { NULL };

void strvec_init(struct strvec *array)
{
<<<<<<< HEAD
	array->items = empty_strvec;
=======
	array->v = empty_strvec;
>>>>>>> upstream/seen
	array->nr = 0;
	array->alloc = 0;
}

static void strvec_push_nodup(struct strvec *array, const char *value)
{
<<<<<<< HEAD
	if (array->items == empty_strvec)
		array->items = NULL;

	ALLOC_GROW(array->items, array->nr + 2, array->alloc);
	array->items[array->nr++] = value;
	array->items[array->nr] = NULL;
=======
	if (array->v == empty_strvec)
		array->v = NULL;

	ALLOC_GROW(array->v, array->nr + 2, array->alloc);
	array->v[array->nr++] = value;
	array->v[array->nr] = NULL;
>>>>>>> upstream/seen
}

const char *strvec_push(struct strvec *array, const char *value)
{
	strvec_push_nodup(array, xstrdup(value));
<<<<<<< HEAD
	return array->items[array->nr - 1];
=======
	return array->v[array->nr - 1];
>>>>>>> upstream/seen
}

const char *strvec_pushf(struct strvec *array, const char *fmt, ...)
{
	va_list ap;
	struct strbuf v = STRBUF_INIT;

	va_start(ap, fmt);
	strbuf_vaddf(&v, fmt, ap);
	va_end(ap);

	strvec_push_nodup(array, strbuf_detach(&v, NULL));
<<<<<<< HEAD
	return array->items[array->nr - 1];
=======
	return array->v[array->nr - 1];
>>>>>>> upstream/seen
}

void strvec_pushl(struct strvec *array, ...)
{
	va_list ap;
	const char *arg;

	va_start(ap, array);
	while ((arg = va_arg(ap, const char *)))
		strvec_push(array, arg);
	va_end(ap);
}

void strvec_pushv(struct strvec *array, const char **items)
{
	for (; *items; items++)
		strvec_push(array, *items);
}

void strvec_pop(struct strvec *array)
{
	if (!array->nr)
		return;
<<<<<<< HEAD
	free((char *)array->items[array->nr - 1]);
	array->items[array->nr - 1] = NULL;
=======
	free((char *)array->v[array->nr - 1]);
	array->v[array->nr - 1] = NULL;
>>>>>>> upstream/seen
	array->nr--;
}

void strvec_split(struct strvec *array, const char *to_split)
{
	while (isspace(*to_split))
		to_split++;
	for (;;) {
		const char *p = to_split;

		if (!*p)
			break;

		while (*p && !isspace(*p))
			p++;
		strvec_push_nodup(array, xstrndup(to_split, p - to_split));

		while (isspace(*p))
			p++;
		to_split = p;
	}
}

void strvec_clear(struct strvec *array)
{
<<<<<<< HEAD
	if (array->items != empty_strvec) {
		int i;
		for (i = 0; i < array->nr; i++)
			free((char *)array->items[i]);
		free(array->items);
=======
	if (array->v != empty_strvec) {
		int i;
		for (i = 0; i < array->nr; i++)
			free((char *)array->v[i]);
		free(array->v);
>>>>>>> upstream/seen
	}
	strvec_init(array);
}

const char **strvec_detach(struct strvec *array)
{
<<<<<<< HEAD
	if (array->items == empty_strvec)
		return xcalloc(1, sizeof(const char *));
	else {
		const char **ret = array->items;
=======
	if (array->v == empty_strvec)
		return xcalloc(1, sizeof(const char *));
	else {
		const char **ret = array->v;
>>>>>>> upstream/seen
		strvec_init(array);
		return ret;
	}
}
