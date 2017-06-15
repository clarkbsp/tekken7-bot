class Game{
public:
    Game();
    Player p1;
    Player p2;
    int damageDoneDiff;
    float playerDistance;
    int quantizedPlayerDistance;

    std::string gameStateString;
    bool initPlayerAddresses();

    int getDamageDoneDiff() const;
    std::string getGameStateString() const;
    float getPlayerDistance() const;
    int getQuantizedPlayerDistance() const;

    void update();
    void updatePlayers();
    void updateGameStateString();
    void updatePlayerDistance();
    void updateQuantizedPlayerDistance();
    friend std::ostream& operator<<(std::ostream& os, const Game& g);
};
