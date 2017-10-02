#pragma once 

typedef struct Argument {
  union value {
    uint8_t charArg;
    uint32_t intArg;
    uint8_t *charArrayArg;
  } value;
} Argument;

typedef struct Arguments {
  uint32_t size;
  Argument *args;
} Arguments;