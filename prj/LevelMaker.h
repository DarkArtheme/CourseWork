#pragma once
#ifndef LEVELMAKER_H
#define LEVELMAKER_H
#include "TmxLevel.h"
//#include "GridMaker.h"
#include <iostream>
#include <algorithm>



class LevelMaker {
public:
    LevelMaker(const std::string& path, const std::string& filename, const int level_num
    , const std::string& extension, const double scalex, const double scaley);
    ~LevelMaker() = default;
    void drawLevel(sf::RenderTarget& target) { tmxl.Draw(target, scale_x, scale_y); }
    TmxObject getStart() const { return start_; }
    const std::vector<TmxObject>& returnPath() const { return path_; }
    const std::vector<TmxObject>& returnTowers() const { return towers_; }
    TmxObject getFinish() const { return finish_; }
private:
    const double scale_x;
    const double scale_y;
    TmxLevel tmxl;
    TmxObject start_;
    TmxObject finish_;
    std::vector<TmxObject> path_;
    std::vector<TmxObject> towers_;

};


#endif //LEVELMAKER_H
