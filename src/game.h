class Game{
public:
    Game();
    Player p1;
    Player p2;
    float playerDistance;

    bool initPlayerAddresses();
    float getPlayerDistance();
    void update();
    void updatePlayerDistance();
    friend std::ostream& operator<<(std::ostream& os, const Game& g);
};
