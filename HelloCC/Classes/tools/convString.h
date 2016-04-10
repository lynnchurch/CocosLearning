#include <stdio.h>
#include "cocos2d.h"

void WStrToUTF8(std::string& dest, const std::wstring& src);
std::string WStrToUTF8(const std::wstring& str);