class Player{
    unsigned long long xAddr;
    unsigned long long yAddr;
    unsigned long long zAddr;
    unsigned long long macroStateAddr;
    unsigned long long animStateAddr;
    int macroState;
    int animState;
    float x;
    float y;
    float z;
public:
    Player();

    unsigned long long getXAddr();
    void setXAddr(unsigned long long addr);

    unsigned long long getYAddr();
    void setYAddr(unsigned long long addr);

    unsigned long long getZAddr();
    void setZAddr(unsigned long long addr);

    unsigned long long getMacroStateAddr();
    void setMacroStateAddr(unsigned long long macroStateAddr);

    unsigned long long getAnimStateAddr();
    void setAnimStateAddr(unsigned long long animStateAddr);

    float getX();

    float getY();

    float getZ();

    float getPos();

    int getMacroState();

    int getAnimState();
};