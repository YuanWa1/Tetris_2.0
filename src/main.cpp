//
// Created by Pawan on 1/5/26.
//

#include "view/CreateWindow.h"
#include <iostream>
#include "view/Game.h"

using namespace std;

int main()
{
    cout << "Main cpp has been triggered;" << endl;

    Game game;
    game.run();
    return 0;
}