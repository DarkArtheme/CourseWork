#ifndef BASEENEMY_H
#define BASEENEMY_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "LevelMaker.h"
#include "GridMaker.h"
#include <cmath>

enum Direction {
	UP,
	LEFT,
	DOWN,
	RIGHT,
};

class EnemyTextureLoader{
public:
    static void LoadTextures(const std::string& path);
    static std::vector<sf::Texture> textures_common_enemy;
    static std::vector<sf::Texture> textures_heavy_enemy;
};

class BaseEnemy{
public:
	BaseEnemy() = default;
	BaseEnemy(const BaseEnemy&) = default;
	~BaseEnemy() = default;
	BaseEnemy& operator=(const BaseEnemy&) = default;
	//explicit BaseEnemy(const LevelMaker& lvl, sf::Clock& clk, const GridMaker& grd, const float side);
	float getSpeed() const { return speed; }
	void setSpeed(float value) { speed = value; }
	int getHealth() const { return health; }
	void setHealth(int value) { health = value; }
	int getPoints() const { return points_for_kill; }
	void move(sf::Clock& clock);
	bool shouldBeDeleted() const { return shoud_be_deleted; }
	sf::Vector2f getCenterPosition() const { return sprite.getPosition(); }
    sf::FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); }
    Direction getDirection() const { return dir; }
	void draw(sf::RenderTarget& window);

protected:
    //sf::Music sound_step;
    std::vector<sf::Texture>* textures;
	sf::Sprite sprite;
	int healthbar_width{0};
	int healthbar_height{0};
	sf::RectangleShape healthbar_border;
	sf::RectangleShape healthbar_green;
	sf::RectangleShape healthbar_red;
	Direction dir{Direction::DOWN};      // текущее направление
    double scale_x, scale_y;
	float speed{0.1};
	int health{0};
	int sprite_side;
	int points_for_kill{0};
    int max_health{0};
    int outline_thickness{0};
	std::size_t turn_num{0};             // номер текущего поворота
    std::vector<TmxObject> path;  // масссив со всеми поворотами
    bool shoud_be_deleted{false};        // должен ли экземпляр быть утилизирован в текущий момент времени
    template<class T>
    sf::Vector2f getCenter(const sf::Rect<T>& r); // получить координаты центра прямоугольника
    Direction setupDir(const std::string& str);  //вспомогательная функция для конструктора
    void changeTexture();                // меняет текстуру в соответствии с направлением
    template<class Vector>
    bool checkEqual(const Vector& lhs, const Vector& rhs); // грамотное сравнение векторов (дробных)
};


class LightEnemy : public BaseEnemy{
public:
    LightEnemy() = default;
    LightEnemy(const LightEnemy&) = default;
    LightEnemy& operator=(const LightEnemy&) = default;
    ~LightEnemy() = default;
    explicit LightEnemy(const LevelMaker& lvl, sf::Clock& clk, const GridMaker& grd, const int side, const double scale_x_, const double scale_y_);
private:
};

class HeavyEnemy : public BaseEnemy{
public:
    HeavyEnemy() = default;
    HeavyEnemy(const HeavyEnemy&) = default;
    HeavyEnemy& operator=(const HeavyEnemy&) = default;
    ~HeavyEnemy() = default;
    explicit HeavyEnemy(const LevelMaker& lvl, sf::Clock& clk, const GridMaker& grd, const int side, const double scale_x_, const double scale_y_);
private:

};



#endif

