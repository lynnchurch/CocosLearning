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

	//   // 正方形
	//auto rect = DrawNode::create();
	//rect->drawRect(Vec2(0, 0), Vec2(150, 150), Color4F(1, 0, 0, 1));
	//rect->setPosition(visibleSize / 2);
	//rect->setContentSize(Size(150, 150));
	//rect->setAnchorPoint(Vec2(0.5, 0.5));

	//// 点
	//auto dot = DrawNode::create();
	//dot->drawDot(Vec2(0, 0),10,Color4F(1,1,1,1));

	//schedule([rect, dot](float f){
	//	rect->setRotation(rect->getRotation() + 1);
	//	auto p = dot->convertToWorldSpace(Vec2(0, 0));
	//	CCLOG("%f,%f", p.x, p.y);
	//}, "Test");

	//rect->addChild(dot);
	//addChild(rect);


	//auto dot = DrawNode::create();
	//dot->drawDot(Vec2(0, 0), 10, Color4F(1, 1, 1, 1));
	//dot->setPosition(visibleSize / 2);
	//addChild(dot);

	//_angle = 0;
	//schedule([dot,visibleSize,this](float f) {
	//	dot->setPositionY(visibleSize.height/2+cos(_angle) * 100);
	//	dot->setPositionX(visibleSize.width / 2 + sin(_angle) * 60);
	//	_angle+=0.1;
	//}, "Test");

	_direction.set(random(-1, 1), random(-1, 1));
	_direction.normalize();

	auto dot = DrawNode::create();
	dot->drawDot(Vec2(10, 10), 10, Color4F(1, 1, 1, 1));
	dot->setContentSize(Size(20, 20));
	dot->setAnchorPoint(Vec2(0.5, 0.5));
	dot->setPosition(visibleSize / 2);
	addChild(dot);

	schedule([dot, visibleSize, this](float f) {
		auto p = dot->getPosition();
		if (p.x<10 || p.x>visibleSize.width - 10)
		{
			_direction.x *= -1;
		}
		else if (p.y<10 || p.y>visibleSize.height - 10)
		{
			_direction.y *= -1;
		}
		dot->setPosition(p + _direction);

	}, "Test");

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
