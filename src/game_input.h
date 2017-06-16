class GameInput{
private:
    int forward;
    int backward;
    int up;
    int down;
    int lp;
    int rp;
    int lk;
    int rk;
    Keyboard kb;
public:
    GameInput(bool reversed);
    int charToKeymap(char c);
    void sendInput(std::string inputString);
    void setReversed(bool reversed);
};