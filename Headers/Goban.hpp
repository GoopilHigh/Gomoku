/*
** Goban.h for gomoku in /home/stephane/Gomoku_sfml_tile_map/Sources
**
** Made by Stéphane
** Login   <stephane@epitech.net>
**
** Started on  Thu Nov 10 17:05:45 2016 Stéphane
// Last update Fri Nov 11 19:59:31 2016 Stéphane
*/

#ifndef GOBAN_H
#define GOBAN_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Goban : public sf::Drawable, public sf::Transformable, public sf::Image
{
 public:
  Goban();
  ~Goban();
  bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

 private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  sf::VertexArray m_vertices;
  sf::Texture m_tileset;
};

#endif /* ! GOBAN_H */
