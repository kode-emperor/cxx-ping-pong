// Libraries
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <format>
#include <iostream>
#include <sstream>
#include <thread>
#include <map>

using namespace std::chrono_literals;
using namespace std::string_literals;

constexpr int ARGV_PROJECT_ROOT =  1;
constexpr int WINDOW_SIZE_WIDTH = 1000;
constexpr int WINDOW_SIZE_HEIGHT = 500;
constexpr std::string_view WINDOW_TITLE_SV{"PingPongXX"};

namespace fs = std::filesystem;


int main(int argc, char **argv) {
  const auto projectRootDir = fs::path(argv[ARGV_PROJECT_ROOT]);
  const auto resFolder = fs::path(projectRootDir.string() + "/src/res");

  auto window =
      sf::RenderWindow{sf::VideoMode(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT),
                       WINDOW_TITLE_SV.data()};
  
  sf::Texture cactus1Texture;
  cactus1Texture.loadFromFile(projectRootDir.string() + "/src/res/cactus/cactus1_00.png");

  sf::Sprite cactus1Sprite;
  cactus1Sprite.setTexture(cactus1Texture);
  cactus1Sprite.setPosition(sf::Vector2f{30.f, 30.f});
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::White);
    window.draw(cactus1Sprite);
    window.display();
  }
  return 0;
}