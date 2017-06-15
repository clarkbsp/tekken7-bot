class Game{
public:
    Game();
    Player p1;
    Player p2;
    float playerDistance;

    std::string gameStateString;
    bool initPlayerAddresses();

    std::string getGameStateString() const;
    float getPlayerDistance() const;
    int getQuantizedPlayerDistance() const;

    void update();
    void updateGameStateString();
    void updatePlayerDistance();
    friend std::ostream& operator<<(std::ostream& os, const Game& g);
};
