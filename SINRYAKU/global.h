#pragma once
#include <string>

#define DEBUG
extern void InputUpdate();
extern int GetKey(int KeyCode);
extern int GetMouse();
extern void Load(std::string fn, std::string n);
extern int GetHandle(std::string);
extern std::string IntToString(int);
