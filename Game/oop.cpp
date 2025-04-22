#include <iostream>
#include <random>
#include <cctype>
using namespace std;

class GameObject {
protected:
    char label;

public:
    GameObject(char l) : label(l) {}

    virtual ~GameObject() {}

    char getLabel() const {
        return label;
    }
};

class Target : public GameObject {
private:
    bool isReal;

public:
    static int totalPercobaan; 
    Target(char l) : GameObject(l), isReal(false) {}

    ~Target() {}

    void setAsReal() {
        isReal = true;
    }

    bool isHit() const {
        return isReal;
    }

    static void tampilkanPercobaan() {
        cout << "\nJumlah percobaan: " << totalPercobaan << endl;
    }
};

int Target::totalPercobaan = 0;

int main() {

    Target* t1 = new Target('A');
    Target* t2 = new Target('B');
    Target* t3 = new Target('C');
    Target* targets[] = { t1, t2, t3 };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 2);
    int realIndex = distrib(gen);
    targets[realIndex]->setAsReal();

    cout << "=============================\n";
    cout << "       GAME TEMBAK TARGET    \n";
    cout << "=============================\n";
    cout << "Tiga target tersedia: [A] [B] [C]\n";
    cout << "Tebak target yang benar dan tembak!\n\n";


    cout << "Masukkan target (A, B, atau C): ";
    char guess;
    cin >> guess;
    guess = toupper(guess);

    Target::totalPercobaan++; 

    bool found = false;
    for (int i = 0; i < 3; ++i) {
        if (guess == targets[i]->getLabel()) {
            found = true;
            if (targets[i]->isHit()) {
                cout << "\nSelamat! Target " << guess << " berhasil ditembak!\n";
            } else {
                cout << "\nOops! Salah tembak.\n";
                cout << "Target yang benar adalah: " << targets[realIndex]->getLabel() << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "\nInput tidak valid. Gunakan hanya A, B, atau C.\n";
    }

    Target::tampilkanPercobaan();

    cout << "\n=============================\n";
    cout << "         GAME SELESAI        \n";
    cout << "=============================\n";

    delete t1;
    delete t2;
    delete t3;

    return 0;
}
