#include  <SFML/Graphics.hpp>

using namespace sf;

constexpr std::string BASE_GRAPHICS_PATH = "../graphics/";
constexpr std::string TITLE_WINDOW = "Timber";
constexpr int WIDTH_WINDOW = 1920;
constexpr int HEIGHT_WINDOW = 1080;

namespace Timber
{
    void loadTextureFromFile(const std::string& fileName, Texture& texture)
    {
        texture.loadFromFile(BASE_GRAPHICS_PATH + fileName);
    }
}


int main()
{
    //Create a video mode object
    VideoMode vm(WIDTH_WINDOW, HEIGHT_WINDOW);

    //Create and open a window for the game
    RenderWindow window(vm, TITLE_WINDOW, Style::Fullscreen);

    //Create a texture to hold a graphic on the GPU
    Texture textureBackground;
    Timber::loadTextureFromFile("background.png", textureBackground);
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    //make a tree sprite
    Texture textureTree;
    Timber::loadTextureFromFile("tree.png", textureTree);
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    //prepare the bee
    Texture textureBee;
    Timber::loadTextureFromFile("bee.png", textureBee);
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    // is the bee currently movin?
    bool beeActive = false;
    //how fast can the bee fly
    float beeSpeed = 0.0f;

    // make 3 cloud sprites from 1 texture
    Texture textureCloud;
    Timber::loadTextureFromFile("cloud.png", textureCloud);

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

    //How fast is each cloud?
    float cloud1Speed = 0;
    float cloud2Speed = 0;
    float cloud3Speed = 0;

    //Variables to control time itself
    Clock clock;

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

        //Measure time
        Time dt = clock.restart();

        //setup the bee
        if (!beeActive)
        {
            // how fast is the bee
            srand((int) time(0));
            beeSpeed = (rand() % 200) + 200;

            // how high is the bee
            srand((int) time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        }
        else
        //Move the bee
        {
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

            // Has the bee reached the left-hand edge of the scree?
            if (spriteBee.getPosition().x < -100)
            {
                // set it up ready to be a whole new bee next frame
                beeActive = false;
            }
        }

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

