#include <vector>
#include <unordered_map>

class LearningAgent{
private:
    
    float discountRate;
    float learningRate;
    int timeStep;
    int stepSize;
    std::vector<std::string> actionsTaken;
    std::vector<double> rewards;
    std::vector<std::string> states;
    std::unordered_map<std::string, double> qVals;
public:
    Game game;
    LearningAgent(Game& game);
    std::string getGreedyAction(std::string state);
    std::string getRandomAction();
    std::string getEpsilonGreedyAction(std::string state);
    double getReturn(int timeToUpdate);
    double getReward();
    std::string getState();
    double getQ(std::string state, std::string action);
    void update();
    void updateQ(std::string state, std::string action, double totalReturn);
    double getMaxQ(std::string state);
    
    void takeAction(std::string action);

};