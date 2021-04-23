
class unit {

    uint16_t speed = 0;
    uint16_t maxtime = 0;
    uint16_t turntime = 0;
    uint16_t health = 0;
    skill *skills = new skill(1);
    bool turn = false;

    public:
        
        unit () {
            
            //cout << "Created unit";
            skills
        }

        void setCounter (uint16_t counter) {
            maxtime = counter;
        }

        void setSpeed (uint16_t sp) {
            speed = sp;
        }

        void setHealth (uint16_t sp) {
            health = sp;
        }

        void doTurn () {
            //turn = true;
        }

        void endTurn () {
            //turn = false;
        }

        uint16_t getSpeed () {
            return speed;
        }

        uint16_t getPos () {
            return turntime;
        }

        bool checkTurn () {
            
            turntime += speed;

            turn = (turntime >= maxtime);

            if (turn)
                turntime -= maxtime;

            return turn;
        }
};