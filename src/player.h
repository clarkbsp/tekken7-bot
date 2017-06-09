class Player{
public:
    Player();
    //DWORD baseAddr;
    DWORD64 xAddr;
    DWORD64 yAddr;
    DWORD64 zAddr;
    DWORD64 macroStateAddr;
    DWORD64 macroState;
    float x;
    float y;
    float z;
    //char stateString[32];
};

bool initPlayerAddresses(Player& p1, Player& p2);