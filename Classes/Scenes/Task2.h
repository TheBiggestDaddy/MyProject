#ifndef TASK2SCENE_H
#define TASK2SCENE_H
#include "cocos2d-A.h"
#include "SceneStyle.h"

class Task2: public SceneStyle
{
public:
    Task2();
    static cocos2d::CCScene* scene();
    static Task2* create();

private:
    cocos2d::CCSprite* _logo;

    void onButtonClick();
    bool init();
    void onBackClick(){};
};

#endif // TASK2NSCENE_H
