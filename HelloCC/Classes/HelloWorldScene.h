#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
private:
	cocos2d::TextFieldTTF *tf;
	cocos2d::Label *btn;
	cocos2d::Size visibleSize;

protected:
	float _angle;
	cocos2d::Vec2 _direction;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
	void buildUI();
	void addListeners();
};

#endif // __HELLOWORLD_SCENE_H__
