class skill {

    string name;
    uint16_t damage;

    public:
        
        unit (string skillname, uint16_t skilldamage) {
            
            //cout << "Created skill";
            name = skillname;
            damage = skilldamage;
        }

        void getName () {
            return name;
        }

        void getDamage () {
            return damage;
        }
};