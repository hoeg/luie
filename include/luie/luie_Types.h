#pragma once

#include <stdint.h>

#define LUIE_RC uint32_t

typedef struct LuieData {
	uint32_t size;
	const uint8_t *content;
} LuieData;