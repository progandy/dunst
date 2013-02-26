#pragma once

#include "option_parser.h"

const char *icons_translate(char *name);

void icons_free(void);

void icons_from_inisection(const section_t *section);
