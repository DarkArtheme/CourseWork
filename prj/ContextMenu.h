#pragma once
#ifndef SFML_SANDBOX_CONTEXTMENU_H
#define SFML_SANDBOX_CONTEXTMENU_H
#include "Button.h"
#include <memory>


class ContextMenu {
public:
    ContextMenu() = delete;
    ContextMenu(const ContextMenu&) = default;
    ContextMenu& operator=(const ContextMenu&) = default;
    ~ContextMenu() = default;
    ContextMenu(const sf::FloatRect& parameters, const sf::Font& font, const unsigned int size
    , const std::string& header, const std::vector<std::shared_ptr<Button>>& buttons_
    , sf::Color menu_clr, sf::Color border_clr, sf::Color text_clr);
    bool isVisible() const { return is_visible; }
    void setVisible(const bool value) { is_visible = value; }
    size_t getTowerIndex() const { return index_of_tower; }
    void setTowerIndex(const size_t value) { index_of_tower = value; }
    void draw(sf::RenderTarget& window) const;
private:
    sf::Color menu_color;
    sf::Color border_color;
    static const unsigned int thickness = 10;
    bool is_visible;
    size_t index_of_tower;
    sf::Vector2f pos;
    float width_, height_;
    sf::RectangleShape menu;
    sf::Text name;
    std::vector<std::shared_ptr<Button>> buttons;
};



#endif //SFML_SANDBOX_CONTEXTMENU_H
