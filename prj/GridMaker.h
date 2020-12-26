#ifndef GRIDMAKER_H
#define GRIDMAKER_H

#include <vector>
#include <SFML/Graphics.hpp>

template<class T>
sf::IntRect makeRect(const T& obj);

enum Orientation {
	HORIZONTAL,
	VERTICAL,
};

struct SquarePosition{
	int hor;
	int ver;
	SquarePosition(int h = 0, int v = 0) : hor(h), ver(v) {}
};

struct Pixel {
	int height_pos;
	int width_pos;
	Pixel(int h = 0, int w = 0) : height_pos(h), width_pos(w) {}
};



class GridMaker{
public:
    GridMaker() = delete;
    GridMaker(const GridMaker&) = delete;
    GridMaker& operator=(const GridMaker&) = delete;

    explicit GridMaker(const sf::RenderTarget& window, const int sc);
    void updateGrid(const sf::RenderTarget& window);
	int getScale() const { return scale; }
	void drawGrid(sf::RenderWindow& window) const;
    SquarePosition getPosition(const Pixel& pix) const;
    void setState(const SquarePosition& position, const int state);
    int getState(const SquarePosition& position) const;
private:
    int scale;
    int window_width;
    int window_height;
    std::vector<sf::RectangleShape> makeRectangles(Orientation orientation);
	std::vector<sf::RectangleShape> hor_rectangles;
	std::vector<sf::RectangleShape> ver_rectangles;
	template<typename T>
	void drawObjects(sf::RenderWindow& window, const std::vector<T>& objects) const;
	std::vector<std::vector<int>> squares;

};

#endif