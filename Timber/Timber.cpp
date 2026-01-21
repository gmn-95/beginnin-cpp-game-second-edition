#include  <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    //Create a video mode object
    VideoMode vm(1920, 1080);

    //Create and open a window for the game
    RenderWindow window(vm, "Timber", Style::Fullscreen);

    //Create a texture to hold a graphic on the GPU
    Texture textureBackground;
    textureBackground.loadFromFile("../graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    //make a tree sprite
    Texture textureTree;
    textureTree.loadFromFile("../graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    //prepare the bee
    Texture textureBee;
    textureBee.loadFromFile("../graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    // is the bee currently movin?
    bool beeActive = false;
    //how fast can the bee fly
    float beeSpeed = 0.0f;

    // make 3 cloud sprites from 1 texture
    Texture textureCloud;
    textureCloud.loadFromFile("../graphics/cloud.png");

    // 3 new sprites with de same texture
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    // position the clouds on the left of the screen at different heights
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    // Are the clouds currently on screen?
    bool cloudActive1 = false;
    bool cloudActive2 = false;
    bool cloudActive3 = false;

    // how fast is each cloud?
    float cloudSpeed1 = 0.0f;
    float cloudSpeed2 = 0.0f;
    float cloudSpeed3 = 0.0f;

    while (window.isOpen())
    {
        /*
        ****************************************
        Handle the players input
        ****************************************
        */
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        /*
        ****************************************
        Update the scene
        ****************************************
        */


        /*
        ****************************************
        Draw the scene
        ****************************************
        */

        //clear everything from the last frame
        window.clear();

        window.draw(spriteBackground);

        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.draw(spriteTree);

        window.draw(spriteBee);

        //draw our gahem scene here
        window.display();
    }

    return 0;
}
