#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "cocos2d-A.h"
#include "SceneStyle.h"

class MainMenu: public SceneStyle
{
public:
    MainMenu();
    static cocos2d::CCScene* scene();
    static MainMenu* create();

private:
    cocos2d::CCSprite* _logo;

    void onButtonClick();
    bool init();
    void onBackClick(){};
};

#endif // MAINSCENE_H
