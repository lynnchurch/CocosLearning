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

	auto zombie = Sprite::create("zombie.png");
	zombie->setPosition(Vec2(visibleSize.width/6,visibleSize.height/2));
	zombie->setScale(1.1);
	addChild(zombie);
	//zombie->runAction(MoveTo::create(5,Vec2(visibleSize.width-50,visibleSize.height/2)));
	//auto action1 = MoveTo::create(5, Vec2(visibleSize.width - 50, visibleSize.height / 2));
	//auto action2 = MoveTo::create(3, Vec2(100, visibleSize.height / 2));
	auto move1 = MoveBy::create(5, Vec2(300, 0));
	//auto move2 = move1->reverse();
	auto scale = ScaleTo::create(2, 1.3);
	//zombie->runAction(Spawn::create(move1, scale, NULL));
	auto spawn = Spawn::create(move1, scale, NULL);
	zombie->runAction(Sequence::create(spawn, CallFunc::create([](){
		CCLOG("Animation completed.");
	}), NULL));
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
