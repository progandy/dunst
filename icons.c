#include <string.h>
#include "icons.h"
#include "stdlib.h"
#include "option_parser.h"

typedef struct _icontrans_t {
	char *name;
	char *symbol;
} icontrans_t;

unsigned int icons_len;
icontrans_t *icons;

const char *icons_translate(char *name) {
	if (name == NULL || icons == NULL)
		return NULL;
		
	for (int i = 0; i < icons_len; ++i) {
		if (0 == strcmp(icons[i].name, name))
			return icons[i].symbol;
	}
	return NULL;
}

void icons_free(void) {
	if (icons != NULL) {
		for (int i = 0; i < icons_len; ++i) {
			free(icons[i].name);
			free(icons[i].symbol);
		}
		free(icons);
		icons = NULL;
	}
}

void icons_from_inisection(const section_t *section) {
	icons_free();
	if (section == NULL)
		return;
	
	icons_len = section->entry_count;
	icons = malloc(icons_len * sizeof(icontrans_t));

	for (int i = 0; i < icons_len; ++i) {
		icons[i].name = strdup(section->entries[i].key);
		icons[i].symbol = strdup(section->entries[i].value);
	}
}
