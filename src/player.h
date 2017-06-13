class Player{
public:
    Player();
    unsigned long long xAddr;
    unsigned long long yAddr;
    unsigned long long zAddr;
    unsigned long long macroStateAddr;
    unsigned long long animStateAddr;
    unsigned long long attackStateAddr;
    unsigned long long blockStateAddr;
    int macroState;
    int animState;
    int attackState;
    int blockState;
    float x;
    float y;
    float z;
    void update();
    friend std::ostream& operator<<(std::ostream& os, const Player& p);
};