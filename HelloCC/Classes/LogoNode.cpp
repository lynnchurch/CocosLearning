#include "LogoNode.h"


LogoNode::LogoNode() :_logo(nullptr), _cocosLogo(nullptr)
{

}


LogoNode::~LogoNode()
{
}

bool LogoNode::init()
{
	if (!Node::init())
	{
		return false;
	}
	_logo = Sprite::create("logo.png");
	_cocosLogo = Sprite::create("cocos_logo.png");
	addChild(_logo);
	addChild(_cocosLogo);
	_cocosLogo->setVisible(false);
	schedule([this](float f){
		_logo->setVisible(!_logo->isVisible());
		_cocosLogo->setVisible(!_cocosLogo->isVisible());
	}, 1, "Test");
	
	return true;
}
