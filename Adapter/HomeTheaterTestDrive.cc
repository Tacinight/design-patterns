/* The facade pattern provides a unified interface to a
 * set of interfaces in a subsustem. Facade  defines a 
 * higher level interface that makes the subsystem eaier
 * to use.
 */
#include <iostream>
#include <string>
using namespace std;

class TheaterLight {
public:
    void on() { cout << "Theater ceiling lights on" << endl; }
    void off();
    void dim(const int num) {
        cout << "Theater Ceiling lights dimming to" << to_string(num) << endl;
    }
};

class PopcornPopper {
public:
    void on() { cout << "Popcorn Popper on" << endl; }
    void off() { cout << "Popcorn Popper off" << endl; }
    void pop() { cout << "Popcorn Popper popping popcorn" << endl; }
};

class Screen {
public:
    void up(){ cout << "Theater screen going up" << endl; }
    void down() { cout << "Theater screen going down" << endl; }
};

class Tuner;
class CdPlayer;
class DvdPlayer;

class Amplifier {
public:
    void on() { cout << "Amplifier on" << endl; }
    void off() { cout << "Amplifier off" << endl; }
    void setCD();

    void setDVD(DvdPlayer* dvd) { 
        cout << "Amplifier setting DVD Player" << endl; 
    }

    void setStereoSound();
    void setSurroundSound() { cout << "Amplifier surround sound on" << endl; }
    void setTuner();
    void setVolume(const int num) {
        cout << "Amplifier setting volumn to" << to_string(5) << endl;
    }
private:
    Tuner* tuner;
    CdPlayer* cdPlayer;
    DvdPlayer* dvdPlayer;
};

class Tuner {
public:
    void on();
    void off();
    void setAM();
    void setFM();
    void setFrequency();
private:
    Amplifier* amplifier;
};

class CdPlayer {
public:
    void on();
    void off();
    void eject();
    void pause();
    void play();
    void stop();
private:
    Amplifier* amplifier;
};

class DvdPlayer {
public:
    void on() { cout << "DVD Player on" << endl; }
    void off() { cout << "DVD Player off" << endl; }
    void ejcet() { cout << "DVD Player eject" << endl; }
    void pause();
    void play(string movie) { cout << "DVD Player playing " << movie << endl; }
    void setStereoSound();
    void setTwoChannelAudio();
    void stop() { cout << "DVD Player stopped" << endl; }
private:
    Amplifier* amplifier;
};

class Projecter {
public:
    void on() { cout << "Projector on" << endl; }
    void off() { cout << "Projector off" << endl; }
    void tvMode();
    void wideScreenMode() { cout << "Projector in widescreen mode" << endl; }
private:
    DvdPlayer* dvdPlayer;
};

class HomeTheaterFacade {
public:
    HomeTheaterFacade(Amplifier* a, Tuner* t, DvdPlayer* d, CdPlayer* c,
        Projecter* p, Screen* s, TheaterLight* l,  PopcornPopper* po) {
        this->amp = a;
        this->tuner = t;
        this->dvd = d;
        this->cd = c;
        this->proj = p;
        this->lights = l;
        this->screen = s;
        this->popper = po;
    }

    void watchMovie(string movie) {
        cout << "Get ready to watch a movie..." << endl;
        popper->on();
        popper->pop();
        lights->dim(10);
        screen->down();
        proj->on();
        proj->wideScreenMode();
        amp->on();
        amp->setDVD(dvd);
        amp->setSurroundSound();
        dvd->on();
        dvd->play(movie);
    }

    void endMovie() {
        cout << "\nShutting movie theater down..." << endl;
        popper->off();
        lights->on();
        screen->up();
        proj->off();
        amp->off();
        dvd->stop();
        dvd->ejcet();
        dvd->off();
    }

    void listenToCd();
    void endCd();
    void listenToRadio();
    void endRadio();
private:
    Amplifier* amp;
    Tuner* tuner;
    DvdPlayer* dvd;
    CdPlayer* cd;
    Projecter* proj;
    TheaterLight* lights;
    Screen* screen;
    PopcornPopper* popper;
};

int main() {
    Amplifier amp;
    Tuner tuner;
    DvdPlayer dvd;
    CdPlayer cd;
    Projecter proj;
    TheaterLight lights;
    Screen screen;
    PopcornPopper popper;

    HomeTheaterFacade homeTheater(&amp, &tuner, &dvd, &cd, &proj,
                                  &screen, &lights, &popper);

    homeTheater.watchMovie("Raiders of the Lost Ark");
    homeTheater.endMovie();
}