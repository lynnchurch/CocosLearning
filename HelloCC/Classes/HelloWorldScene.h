#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;

class HelloWorld : public cocos2d::Layer,TableViewDataSource,TableViewDelegate
{
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

public:
	virtual cocos2d::Size cellSizeForTable(TableView *table)override;

	virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx)override;

	virtual ssize_t numberOfCellsInTableView(TableView *table)override;
public:
	virtual void tableCellTouched(TableView* table, TableViewCell* cell) override;

};

#endif // __HELLOWORLD_SCENE_H__
