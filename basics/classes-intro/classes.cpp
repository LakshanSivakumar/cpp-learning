#include <iostream>


class Player{ //this is currently private
public: //now this makes the class public
    int x, y;
    int speed;
    void Move(int xa, int ya){
    x += xa * speed;
    y += ya * speed;
}
};




int main(){
    
    Player player;
    player.x = 100;
    player.y = 200;
    player.speed = 2;
    player.Move(1,1);
    std::cout << player.x << ", " << player.y << '\n';

}