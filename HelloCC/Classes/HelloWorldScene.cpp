#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = LabelTTF::create();
	label->setString("Please touch the screen.");
	label->setFontSize(24);
	label->setPosition(visibleSize / 2);
	addChild(label);

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = [](std::vector<Touch *> ts, Event *e)
	{
		CCLOG("Touches began , count is %ld", ts.size());
	};
	listener->onTouchesMoved = [](std::vector<Touch *> ts, Event *e)
	{
		CCLOG("Touches moved , count is %ld", ts.size());
	};
	listener->onTouchesEnded = [](std::vector<Touch *> ts, Event *)
	{
		CCLOG("Touches ended , count is %ld", ts.size());
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyReleased = [](EventKeyboard::KeyCode code, Event *e)
	{
		CCLOG("Keycode: %d", code);
		if (EventKeyboard::KeyCode::KEY_ESCAPE== code)
		{
			Director::getInstance()->end();
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
