#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

class Card {
protected:
    int grad;
    std::string culoare;

public:
    Card(int grad, const std::string& culoare)
        : grad(grad), culoare(culoare) {}

    int GetGrad() const {
        return grad;
    }

    const std::string& GetCuloare() const {
        return culoare;
    }

    void Deschide() {
        std::cout << "Cartea de joc este deschisa.\n";
    }

    void Intoarce() {
        std::cout << "Cartea de joc este intoarsa.\n";
    }
};

class PackOfCards {
protected:
    std::vector<Card> carti;

public:
    PackOfCards() {}

    void AdaugaCarte(const Card& carte) {
        carti.push_back(carte);
    }

    virtual void ScoateCarti() = 0;

    void AfiseazaCarti() {
        for (const Card& carte : carti) {
            std::cout << "Grad: " << carte.GetGrad() << ", Culoare: " << carte.GetCuloare() << "\n";
        }
    }
};

class PackOfCardsSorted : public PackOfCards {
public:
    void ScoateCarti() override {
        std::cout << "Scoate cartile in ordine:\n";
        for (const Card& carte : carti) {
            std::cout << "Grad: " << carte.GetGrad() << ", Culoare: " << carte.GetCuloare() << "\n";
        }
    }
};

class PackOfCardsRandom : public PackOfCards {
public:
    void ScoateCarti() override {
        std::cout << "Scoate cartile aleator:\n";
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(carti), std::end(carti), rng);
        for (const Card& carte : carti) {
            std::cout << "Grad: " << carte.GetGrad() << ", Culoare: " << carte.GetCuloare() << "\n";
        }
    }
};

int main() {
    Card carte1(10, "Inima");
    Card carte2(5, "Romb");
    Card carte3(8, "Trefla");

    PackOfCardsSorted butucOrdine;
    butucOrdine.AdaugaCarte(carte1);
    butucOrdine.AdaugaCarte(carte2);
    butucOrdine.AdaugaCarte(carte3);

    std::cout << "Butuc de carti in ordine:\n";
    butucOrdine.ScoateCarti();

    std::cout << "\n";

    PackOfCardsRandom butucAleator;
    butucAleator.AdaugaCarte(carte1);
    butucAleator.AdaugaCarte(carte2);
    butucAleator.AdaugaCarte(carte3);

    std::cout << "Butuc de carti aleator:\n";
    butucAleator.ScoateCarti();

    return 0;
}
