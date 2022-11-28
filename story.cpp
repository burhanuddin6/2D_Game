#include "object.hpp"

class Story
{
    public:
    Player *player;
    Story()
    {
        player = new Player;
    }
    void createObject()
    {
    }
    void drawObjects()
    {
        player->draw();
    }
};