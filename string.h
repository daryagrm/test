#pragma once
#ifndef _STRING_H_
#define _STRING_H_

#include "function.h"
#include <iostream>

#define MAX_SIZE 1024

int _strlen(const char* s);
void _strcpy(char *s1, const char *s2, int n);
bool _strcmp(const char *s1, const char *s2);
char* read(const char *s);

#endif