


class PropsObject{
    public:

    protected:
        void coreStep();
        double _x;
        double _y;
        double _speed;
        double _direction;
};

class Bob: public PropsObject{
    public:
        Bob();
        void step();
        void draw();
    private:
        double _maxSpd;
};


Bob::Bob(){
    _maxSpd = 10;
    _speed = 3;
    _direction = 90;
    _x = 100;
    _y = 100;
}

void Bob::step(){
    if (_speed < _maxSpd)
        _speed++;

}

void Bob::draw(){

}