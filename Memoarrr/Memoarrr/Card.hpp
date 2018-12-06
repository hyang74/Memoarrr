//
//  Card.hpp
//  Memoarrr
//
//  Created by Huairuo Yang on 2018-11-12.
//  Copyright © 2018 Huairuo Yang(7895717). All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include "Utils.hpp"
using namespace std;

class Card{
    friend class CardDeck;
    FaceAnimal cardAnimal;
    FaceBackground cardColor;
    Letter let;
    Number num;
    bool faceUp = false;
    int nRows = 3;
    
    Card(FaceAnimal animal, FaceBackground background): cardAnimal(animal), cardColor(background){};
    
public:
    void setLetter(Letter l){let=l;}
    void setNumber(Number n){num=n;}
    int getPosition() const{return ((int)let)*5 + (int)num;}
    
    int getAnimal() const {return (int)cardAnimal;}
    std::string getAnimalStr();
    int getColor() const {return (int)cardColor;}
    std::string getColorStr();
    
    bool isFaceUp(){return faceUp;}
    void turnFace(bool trueForUp){faceUp = trueForUp;}
    
    Card(const Card&) = delete;
    Card& operator= ( const Card & ) = delete;
    int getNRows() {return nRows;}
    std::string operator()(int i) {
            if(!faceUp){
                return " zzz";
            }
            else{
                if(i==1){
                    return (" "+getColorStr()+getAnimalStr()+getColorStr());
                }
                else{
                    return (" "+(getColorStr()+getColorStr()+getColorStr()));
                }
            }
    }
};

#endif /* Card_hpp */
