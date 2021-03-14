#include "ContactListener.hpp"
#include "SpriteWithBody.hpp"
#include "Ostrich.hpp"
#include "PlayerOstrich.hpp"
#include <SDL2/SDL.h>

ContactListener::ContactListener()
{
}

void ContactListener::BeginContact(b2Contact *contact)
{

    auto *spriteA = (SpriteWithBody *)contact->GetFixtureA()->GetBody()->GetUserData();
    auto *spriteB = (SpriteWithBody *)contact->GetFixtureB()->GetBody()->GetUserData();
    std::string spriteAType = spriteA->getType();
    std::string spriteBType = spriteB->getType();

    if (spriteAType == "player" && spriteBType == "enemy")
    {
        auto *playerOst = (PlayerOstrich *)spriteA;
        auto *ost = (Ostrich *)spriteB;
        // enemy below
        SDL_Log("player, enemy");
        if (playerOst->getPosition().getX() > ost->getPosition().getX())
        {
            playerOst->takeHit(true);
            ost->takeHit(false);
        }
        else
        {
            playerOst->takeHit(false);
            ost->takeHit(true);
        }
    }
    else if (spriteAType == "enemy" && spriteBType == "player")
    {
        SDL_Log("enemy, player");

        PlayerOstrich *playerOst = (PlayerOstrich *)spriteB;
        Ostrich *ost = (Ostrich *)spriteA;
        // enemy below
        if (playerOst->getPosition().getX() > ost->getPosition().getX())
        {
            playerOst->takeHit(true);
            ost->takeHit(false);
        }
        else
        {
            playerOst->takeHit(false);
            ost->takeHit(true);
        }
    }
}
