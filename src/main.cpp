//
// Created by Pawan on 1/5/26.
//

#include "view/Window.h"
#include <iostream>
#include "model/Game.h"

using namespace std;

int main()
{
    cout << "Main cpp has been triggered;" << endl;

    Game game;
    game.run();
    return 0;
}