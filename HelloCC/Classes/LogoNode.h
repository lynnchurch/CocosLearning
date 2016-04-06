#pragma once
#ifndef __LOGO_NODE_H__
#define __LOGO_NODE_H__
#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class LogoNode:public Node
{
protected:
	Sprite* _logo;
	Sprite* _cocosLogo;

public:
	LogoNode();
	virtual ~LogoNode();
	virtual bool init();
	CREATE_FUNC(LogoNode);
};

#endif