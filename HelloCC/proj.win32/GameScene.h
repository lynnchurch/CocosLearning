#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class GameScene :
	public Layer
{
public:
	GameScene();
	virtual ~GameScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	static Scene* createScene();
};
#endif // __GAME_SCENE_H__
