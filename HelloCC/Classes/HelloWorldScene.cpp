#include "HelloWorldScene.h"
#define  LABEL_TAG 1
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

	auto tv = TableView::create(this, Size(480, 320));
	tv->setAnchorPoint(Point(0.5, 0.5));
	tv->setPosition(Size(visibleSize.width / 2-30, 0));
	tv->setDelegate(this);
	addChild(tv);

	return true;
}


Size HelloWorld::cellSizeForTable(TableView *table)
{
	return Size(200, 30);
}

TableViewCell* HelloWorld::tableCellAtIndex(TableView *table, ssize_t idx)
{
	auto cell = table->dequeueCell();
	LabelTTF *label;
	if (NULL == cell)
	{
		cell = TableViewCell::create();
		label = LabelTTF::create();
		label->setFontSize(20);
		label->setAnchorPoint(Point(0, 0));
		label->setPosition(0, 0);
		label->setTag(LABEL_TAG);
		cell->addChild(label);
	}
	else
	{
		label = (LabelTTF*)cell->getChildByTag(LABEL_TAG);
	}
	label->setString(StringUtils::format("Label %d", (int)idx));
	CCLOG("Label %ld", idx);
	return cell;
}

ssize_t HelloWorld::numberOfCellsInTableView(TableView *table)
{
	return 100;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::tableCellTouched(TableView* table, TableViewCell* cell)
{
	auto label = (LabelTTF*)cell->getChildByTag(LABEL_TAG);
	CCLOG("%s is Clicked", label->getString().c_str());
}
