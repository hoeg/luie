#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdlib.h>
#include <stdio.h>

typedef struct Code {
  uint32_t size;
  uint8_t *data;
} Code;

typedef struct Argument {
  union {
    uint8_t
    uint32_t
  } value;
} Argument;

typedef struct Arguments {
  uint32_t size;
  Argument *args;
} Arguments;

typedef struct RunnableScript {
  uint32_t identifier;
  Code code;
  Arguments argSpec;
} RunnableScript;

typedef struct RunnableScripts {
  RunnableScript *scripts;
  uint32_t size;
} RunnableScripts;

void bail(lua_State *L, char *msg){
  fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
    msg, lua_tostring(L, -1));
  exit(1);
}

int main(int argc, const char* argv[])
{
  lua_State *L;

  L = luaL_newstate();
  luaL_openlibs(L);
 
  if (luaL_loadfile(L, "hello.lua"))
    bail(L, "luaL_loadfile() failed");

  printf("In C, calling Lua\n");
  if (lua_pcall(L, 0, 0, 0))
    bail(L, "lua_pcall() failed");   

  lua_getglobal(L, "doStuff");

  if (lua_pcall(L, 0, 0, 0))
    bail(L, "lua_pcall() failed");

  printf("Back in C again\n");

  lua_close(L);

  return 0;
}