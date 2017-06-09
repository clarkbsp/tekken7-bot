class Player{
public:
    Player();
    //DWORD baseAddr;
    unsigned long long xAddr;
    unsigned long long yAddr;
    unsigned long long zAddr;
    unsigned long long macroStateAddr;
    int macroState;
    float x;
    float y;
    float z;
    //char stateString[32];
};

bool initPlayerAddresses(Player& p1, Player& p2);