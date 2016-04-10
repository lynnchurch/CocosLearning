#include "HelloWorldScene.h"
#include "convString.h"
#include "StrCoding.h"

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

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	buildUI();
	addListeners();
	return true;
}

void HelloWorld::buildUI()
{
	tf = (TextFieldTTF *)TextFieldTTF::textFieldWithPlaceHolder(WStrToUTF8(L"请输入"), "", 24);
	tf->setPosition(visibleSize / 2);
	btn = Label::create();
	btn->setString(WStrToUTF8(L"提交"));
	btn->setSystemFontSize(24);
	btn->setPosition(Vec2(visibleSize.width / 2, tf->getPositionY() - tf->getContentSize().height / 2 - 35));
	addChild(tf);
	addChild(btn);
}

void HelloWorld::addListeners()
{
	auto director = Director::getInstance();
	auto handler = [this](Touch * t, Event * e){
		auto target = e->getCurrentTarget();
		CCLOG("target content size: %f %f",target->getContentSize().width,target->getContentSize().height);
		auto point = t->getLocation();
		if (target->getBoundingBox().containsPoint(point))
		{
			if (tf == target)
			{
				tf->attachWithIME();
			}
			else if (this->btn == target)
			{
				auto str = tf->getString();
				if (0 ==str.length())
				{
					MessageBox("输入内容不能为空", "提示");
					return false;
				}
				CCLOG(str.c_str());
				StrCoding strC;
			    string temp = "";
				strC.UTF_8ToGB2312(temp, (char *)str.c_str(), strlen(str.c_str()));
				MessageBox(temp.c_str(),"Notice");
				tf->detachWithIME();
			}
		}
		else
		{
			tf->detachWithIME();
		}
		return false;
	};

	auto l1 = EventListenerTouchOneByOne::create();
	l1->onTouchBegan = handler;
	director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(l1, tf);
	auto l2 = EventListenerTouchOneByOne::create();
	l2->onTouchBegan = handler;
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(l2, btn);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
