#pragma once
#ifndef SFML_SANDBOX_BASETOWER_H
#define SFML_SANDBOX_BASETOWER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "BaseEnemy.h"
//#include <deque>
#include <cmath>
#include <memory>

enum State{
    NOT_BUILT,
    TARGETED_NOT_BUILD,
    READY,
    RELOADING,
};

class TowerTextureLoader{
public:
    static void LoadTextures(const std::string &path1, const std::string &path2);
    inline static sf::Texture place_for_tower;
    inline static sf::Texture targeted_place_for_tower;
    inline static sf::Texture base_texture;
    inline static sf::Texture tower_texture_1;
    inline static sf::Texture empty_tower_texture_1;
    inline static sf::Texture tower_texture_2;
    inline static sf::Texture rocket;
    inline static sf::Texture smoke;
    inline static sf::Texture explosion;
};

class TowerSoundLoader{
public:
    static void LoadSounds(const std::string &folder_path);
    inline static sf::SoundBuffer shot1;
    inline static sf::SoundBuffer shot2;
    inline static sf::SoundBuffer explosion;
};


class BaseTower {
public:
    BaseTower() = default;
    BaseTower(const BaseTower&) = default;
    BaseTower& operator=(const BaseTower&) = default;
    ~BaseTower() = default;
    sf::Vector2i getPos() const { return pos; }
    int getSide() const { return side; }
    int getCost() const { return cost; }
    sf::Clock* getClockptr() const { return clock_ptr; }
    sf::CircleShape getCircleRange() const { return circle; }
    State getState() const { return state; }
    void draw(sf::RenderTarget& window);
    void summon();
    void shoot();
    void reload();
    void flyRocket();
    void rotate();
    void setQuery(std::vector<std::vector<std::shared_ptr<BaseEnemy>>::iterator> query_);
    bool checkHit(std::vector<std::shared_ptr<BaseEnemy>>::iterator& it);
    void isTimeToShoot();
    //float getRotate() const { return sprite_tower.getRotation(); }
protected:
    static constexpr double PI = 3.1415926535;
    static constexpr unsigned int frames_for_explosion = 6;
    sf::Vector2i pos;                          // координаты относительно верхнего левого угла
    int side{64};                               // размер стороны квадрата башни
    sf::Sprite sprite_base;                    // спрайт для основания башни
    sf::Sprite sprite_tower;                   // спрайт для верхней части башни
    sf::Sprite sprite_rocket;
    sf::Sprite smoke;
    sf::Sprite sprite_explosion;
    State state{State::NOT_BUILT};
    sf::Clock* clock_ptr{nullptr};
    sf::Clock cooldown_clock;
    sf::Sound sound_shot;
    sf::Sound sound_explosion;
    int cost{0};
    float cooldown{0};
    float fire_range{0};
    sf::CircleShape circle;
    float rotation_speed{0};
    float rocket_speed{0};
    float angle{0};
    int damage{0};
    double scale_x, scale_y;
    bool explosion_is_visible{false};
    unsigned int cur_frame{0};
    std::vector<std::vector<std::shared_ptr<BaseEnemy>>::iterator> query;
    double dtor(const double deg) { return deg * PI / 180.0; }
    double rtod(const double rad) { return rad * 180.0 / PI; }
    bool isInRange(const sf::Vector2f& pt) const;

    bool isEqualExact(const double lhs, const double rhs) { return std::abs(rhs - lhs) < 1e-1; }
    bool isEqualApprox(const double lhs, const double rhs) { return std::abs(rhs - lhs) < 1.3; }
};

class LightTower : public BaseTower{
public:
    LightTower() = delete;
    ~LightTower() = default;
    LightTower(const LightTower&) = default;
    LightTower& operator=(const LightTower&) = default;
    explicit LightTower(const sf::Vector2i & position, const int side_
    , sf::Clock* clock_, const double scale_x_, const double scale_y_);
private:
};

class HeavyTower : public BaseTower{
public:
    HeavyTower() = delete;
    ~HeavyTower() = default;
    HeavyTower(const HeavyTower&) = default;
    HeavyTower& operator=(const HeavyTower&) = default;
    explicit HeavyTower(const sf::Vector2i & position, const int side_
    , sf::Clock* clock_, const double scale_x_, const double scale_y_);
};



#endif //SFML_SANDBOX_BASETOWER_H
