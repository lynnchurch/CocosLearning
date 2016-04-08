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

	/*auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(visibleSize / 2);
	addChild(sprite);
	CCLOG("sprite size(1):%f %f", sprite->getContentSize().width, sprite->getContentSize().height);
	schedule([sprite](float f){
		CCLOG("sprite size:%f %f", sprite->getContentSize().width, sprite->getContentSize().height);

	}, "Test");
	//sprite->retain();*/

	/*Vector <Label *> vec;
	auto label1 = Label::create();
	label1->setString("Label 1");
	label1->setSystemFontSize(30);
	auto label2 = Label::create();
	label2->setString("Label 2");
	label2->setSystemFontSize(30);
	vec.pushBack(label1);
	vec.pushBack(label2);
	int i = 0;
	for (auto label : vec)
	{
		i++;
		if (1 == i)
		{
			label->setPosition(Vec2(visibleSize.width / 5, visibleSize.height / 2));
		}
		else if (2 == i)
		{
			label->setPosition(Vec2(visibleSize.width * 4 / 5, visibleSize.height / 2));
		}
		addChild(label);
	}*/

	/*Map<std::string, Label *> map;
	auto label1 = Label::create();
	label1->setString("Label 1");
	label1->setSystemFontSize(30);
	label1->setPosition(Vec2(visibleSize.width / 5, visibleSize.height / 2));
	auto label2 = Label::create();
	label2->setString("Label 2");
	label2->setSystemFontSize(30);
	label2->setPosition(Vec2(visibleSize.width * 4 / 5, visibleSize.height / 2));
	map.insert("label1", label1);
	map.insert("label2", label2);
	addChild(map.at("label1"));
	addChild(map.at("label2"));*/

	Value v1 = Value(123);
	Value v2 = Value("abc");
	Value v3 = Value(true);
	CCLOG("%s %s %s", v1.asString().c_str(), v2.asString().c_str(), v3.asString().c_str());

	Value v4 = Value::Null;
	v4 = v1;
	v4 = v2;
	v4 = v3;
	CCLOG("%s %s", v4.getType() == Value::Type::BOOLEAN ? "True" : "False", v4.asString().c_str());

	ValueVector vec;
	vec.push_back(Value("Hello"));
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	for (auto value : vec)
	{
		CCLOG("ValueVector %s", value.asString().c_str());
	}

	ValueMap map;
	map["a"] = v1;
	map["b"] = v2;
	map["c"] = v3;
	for (auto m : map)
	{
		CCLOG("%s:%s", m.first.c_str(), m.second.asString().c_str());
	}
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
