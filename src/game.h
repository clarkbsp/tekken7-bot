class Game{
public:
    Game();
    Player p1;
    Player p2;
    bool initPlayerAddresses();
    void update();
    friend std::ostream& operator<<(std::ostream& os, const Game& g);
};
