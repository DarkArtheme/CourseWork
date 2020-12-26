#pragma once
#ifndef SFML_SANDBOX_BUTTON_H
#define SFML_SANDBOX_BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum Status{
    DEACTIVATED,
    TARGETED,
    CLICKED
};

class ButtonSoundLoader{
public:
    static void LoadSounds(const std::string &folder_path);
    inline static sf::SoundBuffer targeted;
    inline static sf::SoundBuffer clicked;
};

class Button{
public:
    Button() = default;
    Button(const Button&) = default;
    Button& operator=(const Button&) = default;
    ~Button() = default;
    virtual bool isVisible() const;
    virtual void setVisible(const bool value);
    virtual bool isPermanentlyClicked() const { return permanently_clicked; }
    virtual void setPermanentlyClicked(const bool value) { permanently_clicked = value; }
    virtual bool checkCursor(const sf::Vector2i& curs_pos) = 0;
    virtual bool isActivated(const sf::Vector2i& curs_pos) = 0;
    virtual void draw(sf::RenderTarget& window) = 0;
protected:
    sf::Vector2f pos;
    sf::Sound sound_targeted;
    sf::Sound sound_clicked;
    float width_{0}, height_{0};
    bool is_visible{true};
    bool permanently_clicked{false};
    Status status;
};


class ButtonSpr : public Button {
public:
    ButtonSpr() = delete;
    ButtonSpr(const ButtonSpr&) = default;
    ButtonSpr& operator=(const ButtonSpr&) = default;
    ~ButtonSpr() = default;
    explicit ButtonSpr(const sf::Texture& deactivated_texture
    , const sf::Texture& targeted_texture, const sf::Texture& clicked_texture
    , sf::Vector2f position, const float width, const float height);

    bool checkCursor(const sf::Vector2i& curs_pos) override;
    bool isActivated(const sf::Vector2i& curs_pos) override;
    void draw(sf::RenderTarget& window) override;
private:
    const sf::Texture& texture_deactivated;
    const sf::Texture& texture_targeted;
    const sf::Texture& texture_clicked;
    sf::Sprite sprite;
};


class ButtonRec : public Button {
public:
    ButtonRec() = delete;
    ButtonRec(const ButtonRec&) = default;
    ButtonRec& operator=(const ButtonRec&) = default;
    ~ButtonRec() = default;
    explicit ButtonRec(const sf::FloatRect& place, const sf::Color& color_deactivated
    , const sf::Color& color_targeted, const sf::Color& color_clicked
    , const sf::Color& color_text, const sf::Font& font
    , const unsigned int size, const std::string& str, float thickness_shadow);
    bool checkCursor(const sf::Vector2i& curs_pos) override;
    bool isActivated(const sf::Vector2i& curs_pos) override;
    void draw(sf::RenderTarget& window) override;
private:
    sf::FloatRect rect;                             // Содержит данные о размере и положении кнопки
    sf::RectangleShape rectshape;                   // Замена спрайтам
    sf::Text text;                                  // Текст на кнопке
    sf::Color deactivated_color;                    // Цвета для
    sf::Color targeted_color;                      // различных
    sf::Color clicked_color;                        // состояний кнопки
    sf::Color text_color;                           // Цвет текста
    float shadow_thickness{0};                      // Толщина тени контура
};


#endif //SFML_SANDBOX_BUTTON_H
