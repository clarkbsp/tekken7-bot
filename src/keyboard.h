
//arrow keys are bugged
/*enum keymap{
    left = VK_LEFT,
    up = VK_UP,
    right = VK_RIGHT,
    down = VK_DOWN,
    start = VK_HOME,

    lp = VK_NUMPAD7,
    rp = VK_NUMPAD8,
    lk = VK_NUMPAD4,
    rk = VK_NUMPAD5
};*/
enum keymap{
    left = 'A',
    up = 'W',
    right = 'D',
    down = 'S',
    start = 'B',

    lp = 'U',
    rp = 'I',
    lk = 'J',
    rk = 'K'
};

class Keyboard{
private:
    INPUT kbInput;

public:
    Keyboard();
    void keyPress(int key);
    void keyDown(int key);
    void keyUp(int key);
};
