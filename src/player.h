class Player{
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

    unsigned long long getAttackStateAddr();
    void setAttackStateAddr(unsigned long long attackStateAddr);

    unsigned long long getBlockStateAddr();
    void setBlockStateAddr(unsigned long long blockStateAddr);

    float getX();

    float getY();

    float getZ();

    float getPos();

    int getMacroState();

    int getAnimState();

    int getAttackState();

    int getBlockState();
};