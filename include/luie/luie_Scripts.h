#pragma once

#include "luie_Types.h"

typedef struct Code LuieData;

typedef struct Script {
  uint32_t identifier;
  Code code;
  Arguments argSpec;
} Script;

typedef struct Scripts {
  Script *list;
  uint32_t size;
} Scripts;

LUIE_RC Luie_addScriptTo(
	const Scripts *scripts,
	const Script *script)