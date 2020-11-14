#include "Window.hpp"

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <memory>

#include "AutomatonRenderer.hpp"
#include "UserInput.hpp"

using namespace UI;

Window::Window(
    std::unique_ptr<AutomatonRenderer> automaton_renderer,
    std::unique_ptr<UserInput> user_input)
    : window(
          sf::VideoMode(640, 690), "Multiplayer Wireworld",
          sf::Style::Close | sf::Style::Titlebar)
{
  this->automaton_renderer = std::move(automaton_renderer);
  this->user_input = std::move(user_input);
  automaton_canvas.create(640, 640);
  this->user_input->set_canvas_position(0, 50);
}

void Window::set_game(std::shared_ptr<Game> new_game) { this->game = new_game; }

void Window::update()
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    switch (event.type)
    {
      case sf::Event::Closed:
        game->quit();
        return;
      default:
        user_input->update(window, event);
    }
  }
  window.clear({80, 80, 80});

  automaton_renderer->render(automaton_canvas);
  user_input->preview_current_shape(automaton_canvas);
  automaton_canvas.display();

  sf::Sprite sprite(automaton_canvas.getTexture());
  sprite.setPosition({0, 50});
  window.draw(sprite);

  window.display();
}