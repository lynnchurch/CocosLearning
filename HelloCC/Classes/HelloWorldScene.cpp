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

	auto zombie = NodeGrid::create();
	zombie->addChild(Sprite::create("zombie.png"));
	zombie->setPosition(visibleSize / 2);
	addChild(zombie);
	//zombie->runAction(Shaky3D::create(30, Size(2, 2), 2, false)); // Õð¶¯
	//zombie->runAction(ShakyTiles3D::create(30, Size(50, 50), 2, false)); // ÍßÆ¬ËéÁÑÕð¶¯
	//zombie->runAction(ShuffleTiles::create(5, Size(100, 100), 5)); // ±¬Õ¨

	// Õð¶¯ºó±¬Õ¨
	/*auto shaky = Shaky3D::create(0.5, Size(1, 1), 2,false);
	auto shuffleTiles = ShuffleTiles::create(2, Size(100, 100), 25);
	zombie->runAction(Sequence::create(shaky, shuffleTiles, NULL));*/
	//zombie->runAction(TurnOffTiles::create(1, Size(150, 150))); // ËéÆ¬ÏûÊ§
	auto waves1 = Waves3D::create(5, Size(20, 20), 5, 20); // ²¨ÀËÐ§¹û
	auto waves2 = Waves3D::create(1, Size(2, 2), 10, 0);
	zombie->runAction(Sequence::create(waves1,waves2,NULL));

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
